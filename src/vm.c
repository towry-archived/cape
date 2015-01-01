// vm.c 
// Copyright 2014 by Towry Wang

#include "vm.h"
#include "opcode.h"
#include "debug.h"
#include <stdio.h>
#include <string.h>

static int opcode;
static int reg1;
static int reg2;
static int reg3;
static void * imm;

void
vm_init(vm_t *vm)
{
  vm->pc = 0;
  vm->nins = 0;
  vm->running = 0;
  memset(vm->regs, 0, 4);
  vm->exitval = malloc(sizeof(Object));
  vm->exitval->ctype = CTNIL;
  vm->exitval->value.p = NULL;
  kv_init(vm->stack);
  // the most top scope
  vm->scope = scope_new_raw(vm);
  vm->current = vm->scope;
}

void
stack_push(vm_t *vm, Object *o)
{
  kv_push(Object *, vm->stack, o);
}

Object *
stack_pop(vm_t *vm)
{
  return kv_pop(vm->stack);
}

int 
stack_size(vm_t *vm)
{
  return kv_size(vm->stack);
}

instruction_t *
fetch_ins(vm_t *vm)
{
  return vm->ins[vm->pc++];
}

instruction_t *
ins_abc(int op, int arg1, int arg2, int arg3)
{
  instruction_t *ins = malloc(sizeof(instruction_t));
  if (ins == NULL) {
    log_err("malloc failed");
    exit(1);
  }

  ins->op = op;
  ins->arg1 = arg1;
  ins->arg2 = arg2;
  ins->arg3 = arg3;
  ins->p = NULL;

  return ins;
}

instruction_t *
ins_ab(int op, int arg1, int arg2)
{
  instruction_t *ins = malloc(sizeof(instruction_t));
  if (ins == NULL) {
    log_err("malloc failed");
    exit(1);
  }

  ins->op = op;
  ins->arg1 = arg1;
  ins->arg2 = arg2;
  ins->arg3 = 0;
  ins->p = (void*)arg2;

  return ins;
}

void
push_ins(vm_t *vm, instruction_t *ins)
{
  // sanity check not here
  if (vm->nins >= 1024) {
    log_err("1024");
  }

  vm->ins[vm->nins] = ins;
  vm->nins++;
}

static void
decode(instruction_t *instruction)
{
  opcode = instruction->op;
  reg1 = instruction->arg1;
  reg2 = instruction->arg2;
  reg3 = instruction->arg3;
  imm = instruction->p;
}

static char *
vm_concat(char *s1, char *s2)
{
  int len;

  len = strlen(s1) + strlen(s2);

  char *ret = malloc(len + 1);
  strcpy(ret, s1);
  strcat(ret, s2);

  return ret;
}

// ! we haven't check both value type

static void
vm_add(vm_t *vm)
{
  Object *o1, *o2;
  int i, m, size;

  o1 = (Object*)vm->regs[reg2];
  o2 = (Object*)vm->regs[reg3];

  if (o1->ctype == CTINT) {
    vm->exitval->ctype = CTINT;
    vm->exitval->value.i = o1->value.i + o2->value.i;
  } else if (o1->ctype == CTFLOAT) {
    vm->exitval->ctype = CTFLOAT;
    vm->exitval->value.f = o1->value.f + o2->value.f;
  } else if (o1->ctype == CTSTRING) {
    vm->exitval->ctype = CTSTRING;
    vm->exitval->value.p = vm_concat(o1->value.p, o2->value.p);
    // below maybe replaced.
    vm->exitval->len = strlen(o1->value.p) + strlen(o2->value.p);
  } else {
    log_err("unsupported operand type(s) for +");
    exit(1);
  }
}

static void
vm_sub(vm_t *vm)
{
  Object *o1, *o2;

  o1 = (Object*)vm->regs[reg2];
  o2 = (Object*)vm->regs[reg3];

  if (o1->ctype == CTINT) {
    vm->exitval->ctype = CTINT;
    vm->exitval->value.i = o1->value.i - o2->value.i;
  } else if (o1->ctype == CTFLOAT) {
    vm->exitval->ctype = CTFLOAT;
    vm->exitval->value.f = o1->value.f - o2->value.f;
  } else {
    log_err("unsupported operand type(s) for -");
    exit(1);
  }
}

static void
vm_mul(vm_t *vm)
{
  Object *o1, *o2;

  o1 = (Object*)vm->regs[reg2];
  o2 = (Object*)vm->regs[reg3];

  if (o1->ctype == CTINT) {
    vm->exitval->ctype = CTINT;
    vm->exitval->value.i = (o1->value.i) * (o2->value.i);
  } else if (o1->ctype == CTFLOAT) {
    vm->exitval->ctype = CTFLOAT;
    vm->exitval->value.f = (o1->value.f) * (o2->value.f);
  } else {
    log_err("unsupported operand type(s) for *");
    exit(1);
  }
}

static void
vm_div(vm_t *vm)
{
  Object *o1, *o2;

  o1 = (Object*)vm->regs[reg2];
  o2 = (Object*)vm->regs[reg3];

  if (o1->ctype == CTINT) {
    vm->exitval->ctype = CTINT;
    vm->exitval->value.i = o1->value.i / o2->value.i;
  } else if (o1->ctype == CTFLOAT) {
    vm->exitval->ctype = CTFLOAT;
    vm->exitval->value.f = o1->value.f / o2->value.f;
  } else {
    log_err("unsupported operand type(s) for /");
    exit(1);
  }
}

// For now, mod operation only allowed 
// between integers
static void
vm_mod(vm_t *vm)
{
  Object *o1, *o2;

  o1 = (Object*)vm->regs[reg2];
  o2 = (Object*)vm->regs[reg3];

  if (o1->ctype == CTINT) {
    vm->exitval->ctype = CTINT;
    vm->exitval->value.i = o1->value.i % o2->value.i;
  } else {
    log_err("unsupported operand type(s) for %%");
    exit(1);
  }
}

typedef void (*funcptr)(vm_t *, int);

static void
call_function(vm_t *vm, Object *fn)
{
  Object *functor;
  funcptr fpr;

  functor = scope_get(vm->scope, fn->value.p);
  if (functor == NULL) {
    log_err("Undefined function.");
    exit(1);
  }

  fpr = functor->value.p;

  // call the function
  fpr(vm, functor->len);
}

#define O1 (Object*)vm->regs[reg2]
#define O2 (Object*)vm->regs[reg3]

void
eval(vm_t *vm)
{
  Object *o1, *o2;

  switch(opcode) {
    case OP_HALT:
      vm->running = 0;
      break;
    case OP_LOADV:
      vm->regs[reg1] = (int)imm;
      break;
    case OP_LOADI:
      vm->regs[reg1] = (int)imm;
      break;
    case OP_MOVE:
      vm->regs[reg1] = (int)(vm->regs[reg2]);
      break;
    case OP_ADD:
      vm_add(vm);
      vm->regs[reg1] = (int)vm->exitval;
      break;
    case OP_SUB:
      vm_sub(vm);
      vm->regs[reg1] = (int)vm->exitval;
      break;
    case OP_MUL:
      vm_mul(vm);
      vm->regs[reg1] = (int)vm->exitval;
      break;
    case OP_DIV:
      vm_div(vm);
      vm->regs[reg1] = (int)vm->exitval;
      break;
    case OP_MOD:
      vm_mod(vm);
      vm->regs[reg1] = (int)vm->exitval;
      break;
    case OP_SETARG:
      o1 = stack_pop(vm);
      o2 = (Object*)(vm->regs[reg1]);

      scope_set((scope_t *)imm, (char*)(o1->value.p), o2);
      vm->regs[reg1] = 0;
      break;
    case OP_CALL:
      // method
      o1 = stack_pop(vm);
      call_function(vm, o1);
      break;
    case OP_PUSH:
      if (imm == 0) {
        imm = (void*)vm->regs[reg1];
      }

      stack_push(vm, (Object *)imm);
      break;
    case OP_GETARG:
      // o1 is identifier
      o1 = stack_pop(vm);
      o2 = scope_get((scope_t*)imm, o1->value.p);

      vm->regs[reg1] = (int)o2;
      break;
    default:
      break;
  }
}

Object *
vm_run(vm_t *vm)
{
  vm->running = 1;

  while (vm->running) {
    instruction_t *inst = fetch_ins(vm);
    decode(inst);
    eval(vm);
  }

  return vm->exitval;
}

scope_t *
scope_new(vm_t *vm)
{
  scope_t *ret;

  ret = malloc(sizeof(scope_t));
  if (ret == NULL) {
    log_err("malloc failed\n");
    exit(1);
  }

  ret->env = kh_init(env);
  ret->parent = vm->current;
  vm->current = ret;

  return ret;
}

// do not change the current scope
// just return a new scope
scope_t *
scope_new_raw(vm_t *vm)
{
  scope_t *ret;

  ret = malloc(sizeof(scope_t));
  if (ret == NULL) {
    log_err("malloc failed\n");
    exit(1);
  }

  ret->env = kh_init(env);

  return ret;
}

void
scope_push(scope_t *s, const char *name, Object *v)
{
  khiter_t k;
  int ret;

  k = kh_put(env, s->env, name, &ret);
  kh_value(s->env, k) = v;
}

void
scope_del(scope_t *s, const char *name)
{
  khiter_t k;

  k = kh_get(env, s->env, name);
  if (k != kh_end(s->env)) {
    kh_del(env, s->env, k);
  }
}

Object *
scope_get(scope_t *s, const char *name)
{
  khiter_t k;

  k = kh_get(env, s->env, name);

  return k == kh_end(s->env) ? NULL : kh_value(s->env, k);
}

void
scope_set(scope_t *s, const char *name, Object *v)
{
  khiter_t k;

  k = kh_get(env, s->env, name);
  if (k == kh_end(s->env)) {
    return;
  }

  kh_value(s->env, k) = v;
}

int 
scope_lookup(scope_t *s, const char *name)
{
  khiter_t k;

  k = kh_get(env, s->env, name);
  if (k == kh_end(s->env)) {
    return 0;
  }

  return 1;
}

const char *opcode_names[] = {
  "OP_HALT", "OP_LOADV", "OP_ADD",
  "OP_SUB", "OP_AND", "OP_OR", "OP_XOR",
  "OP_NOT", "OP_LOAD",
  "OP_STOR", "OP_JMP", "OP_JZ", "OP_PUSH",
  "OP_DUP", "OP_MOVE", "OP_JNZ", "OP_PuSHIP",
  "OP_POPIP", "OP_NOP_END", "OP_CALL", "OP_SYSCALL",
  "OP_SETARG", "OP_GETARG",
};


const char *
opcode_name(int i) {
  return opcode_names[i];
}

void
print_instruct(vm_t *vm)
{
  int i;
  instruction_t *ins;

  for (i = 0; i < vm->nins; i++) {
    ins = vm->ins[i];
    printf("%s, ARG1: %d, POINTER: %p\n", opcode_name(ins->op), ins->arg1, ins->p);
  }
}

Object *
define_c_function(vm_t *vm, void (*functor)(vm_t *, int), int nargs)
{
  Object *o;
  o = malloc(sizeof (Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }

  o->ctype = CTFUNC;
  o->value.p = functor;
  o->len = nargs;

  return o;
}

Object *
link_namespace(vm_t *vm, const char *name)
{
  Object *o;
  scope_t *scope;

  scope = scope_new_raw(vm);
  // this scope's parent is always the top scope
  scope->parent = vm->scope;

  o->ctype = CTREF;
  o->value.p = (void*)scope;
  scope_push(vm->scope, name, o);

  return o;
}

void
link_function(vm_t *vm, Object *ref, const char *name, Object *functor)
{
  scope_push((scope_t*)ref->value.p, name, functor);
}


void
link_function_top(vm_t *vm, const char *name, Object *functor)
{
  scope_push(vm->scope, name, functor);
}

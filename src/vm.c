// vm.c 
// Copyright 2014 by Towry Wang

#include "vm.h"
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
  memset(vm->regs, 0, NUM_REGS);
  vm->r = 0;
  vm->pool = pool_new(0);
  if (vm->pool == NULL) {
    exit(1);
  }
  vm->exitval = pool_alloc(vm->pool, sizeof(Object));
  vm->exitval->ctype = CTNIL;
  vm->exitval->value.p = NULL;
  kv_init(vm->stack);
  // the most top scope
  vm->scope = scope_new_raw(vm);
  vm->current = vm->scope;
  vm->nc = 0;
}

void
vm_free(vm_t *vm)
{
  pool_free(vm->pool); 
}

void
stack_push(vm_t *vm, Object *o)
{
  kv_push(Object *, vm->stack, o);
}

Object *
stack_pop(vm_t *vm)
{
  Object *o;

  o = kv_pop(vm->stack);

  return o;
}

int 
stack_size(vm_t *vm)
{
  return kv_size(vm->stack);
}

jump_t *
jump_new(vm_t *vm)
{
  jump_t *jt;

  jt = pool_alloc(vm->pool, sizeof (jump_t));

  return jt;
}

instruction_t *
fetch_ins(vm_t *vm)
{
  return vm->ins[vm->pc++];
}

instruction_t *
ins_abc(vm_t * vm, int op, int arg1, int arg2, int arg3)
{
  instruction_t *ins = pool_alloc(vm->pool, sizeof(instruction_t));
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
ins_ab(vm_t *vm, int op, int arg1, int arg2)
{
  instruction_t *ins = pool_alloc(vm->pool, sizeof(instruction_t));
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

void
vm_halt(vm_t *vm)
{
  push_ins(vm, ABC(OP_HALT, 0, 0, 0));
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

static void
print_stack(vm_t *vm)
{
  int i;

  for (i = 0; i < kv_size(vm->stack); i++) {
    printf("%p ", kv_A(vm->stack, i));
  }
  printf("\n\n");
}

static char *
vm_concat(vm_t *vm, char *s1, char *s2)
{
  int len;

  len = strlen(s1) + strlen(s2);

  char *ret = pool_alloc(vm->pool, len + 1);
  strcpy(ret, s1);
  strcat(ret, s2);

  return ret;
}

// ! we haven't check both value type

static Object *
vm_add(vm_t *vm)
{
  Object *o1, *o2;
  int i, m, size;

  Object *ret = pool_alloc(vm->pool, sizeof(Object));
  if (ret == NULL) {
    exit(1);
  }

  o2 = stack_pop(vm);
  o1 = stack_pop(vm);

  if (o1->ctype == CTINT) {
    ret->ctype = vm->exitval->ctype = CTINT;
    ret->value.i = vm->exitval->value.i = o1->value.i + o2->value.i;
  } else if (o1->ctype == CTFLOAT) {
    ret->ctype = vm->exitval->ctype = CTFLOAT;
    ret->value.i = vm->exitval->value.f = o1->value.f + o2->value.f;
  } else if (o1->ctype == CTSTRING) {
    ret->ctype = vm->exitval->ctype = CTSTRING;
    ret->value.p = vm->exitval->value.p = vm_concat(vm, o1->value.p, o2->value.p);
    // below maybe replaced.
    ret->len = vm->exitval->len = strlen(o1->value.p) + strlen(o2->value.p);
  } else {
    log_err("unsupported operand type(s) for +");
    exit(1);
  }

  return ret;
}

static Object *
vm_sub(vm_t *vm)
{
  Object *o1, *o2;
  Object *ret = pool_alloc(vm->pool, sizeof(Object));
  if (ret == NULL) {
    exit(1);
  }

  o2 = stack_pop(vm);
  o1 = stack_pop(vm);

  if (o1->ctype == CTINT) {
    ret->ctype = vm->exitval->ctype = CTINT;
    ret->value.i = vm->exitval->value.i = o1->value.i - o2->value.i;
  } else if (o1->ctype == CTFLOAT) {
    ret->ctype = vm->exitval->ctype = CTFLOAT;
    ret->value.i = vm->exitval->value.f = o1->value.f - o2->value.f;
  } else {
    log_err("unsupported operand type(s) for -");
    exit(1);
  }

  return ret;
}

static Object *
vm_mul(vm_t *vm)
{
  Object *o1, *o2;
  Object *ret = pool_alloc(vm->pool, sizeof(Object));
  if (ret == NULL) {
    exit(1);
  }

  o2 = stack_pop(vm);
  o1 = stack_pop(vm);

  if (o1->ctype == CTINT) {
    ret->ctype = vm->exitval->ctype = CTINT;

    ret->value.i = vm->exitval->value.i = (o1->value.i) * (o2->value.i);
  } else if (o1->ctype == CTFLOAT) {
    ret->ctype = vm->exitval->ctype = CTFLOAT;
    ret->value.f = vm->exitval->value.f = (o1->value.f) * (o2->value.f);
  } else {
    log_err("unsupported operand type(s) for *");
    exit(1);
  }

  return ret;
}

static Object *
vm_div(vm_t *vm)
{
  Object *o1, *o2;
  Object *ret = pool_alloc(vm->pool, sizeof(Object));
  if (ret == NULL) {
    exit(1);
  }

  o2 = stack_pop(vm);
  o1 = stack_pop(vm);

  if (o1->ctype == CTINT) {
    vm->exitval->ctype = CTINT;
    ret->ctype = CTINT;

    ret->value.i = vm->exitval->value.i = o1->value.i / o2->value.i;
  } else if (o1->ctype == CTFLOAT) {
    vm->exitval->ctype = CTFLOAT;
    ret->ctype = CTFLOAT;

    ret->value.f = vm->exitval->value.f = o1->value.f / o2->value.f;
  } else {
    log_err("unsupported operand type(s) for /");
    exit(1);
  }

  return ret;
}

// For now, mod operation only allowed 
// between integers
static Object *
vm_mod(vm_t *vm)
{
  Object *o1, *o2;
  Object *ret = pool_alloc(vm->pool, sizeof(Object));
  if (ret == NULL) {
    exit(1);
  }

  o2 = stack_pop(vm);
  o1 = stack_pop(vm);

  if (o1->ctype == CTINT) {
    ret->ctype = vm->exitval->ctype = CTINT;
    ret->value.i = vm->exitval->value.i = o1->value.i % o2->value.i;
  } else {
    log_err("unsupported operand type(s) for %%");
    exit(1);
  }

  return ret;
}

typedef void (*funcptr)(vm_t *, int);

static void
call_c_function(vm_t *vm, Object *fn)
{
  funcptr fpr;

  fpr = fn->value.p;

  // call the function
  fpr(vm, fn->len);
}

static void
call_function(vm_t *vm, Object *fn)
{
  Object *o, *o2;
  jump_t *jt, *jt2;
  scope_t *scope;
  int argc;
  int i;

  scope = (scope_t*)fn->closure;
  if (scope == NULL) {
    log_err("error when calling function");
    exit(1);
  }

  argc = scope->argc;
  for (i = argc-1; i >= 0; i--) {
    // log_info("loop");
    o = stack_pop(vm);
    o2 = scope_kget(scope, i);
    if (o2 == NULL) {
      log_err("Unknow error");
      exit(1);
    }

    if (o->ctype != o2->ctype) {
      log_err("Argument type not matched. %d: %d", o->ctype, o2->ctype);
      exit(1);
    } else {
      scope_kset(scope, i, o);
    }
  }

  jt2 = (jump_t *)fn->value.p;

  vm->regs[jx] = vm->pc;
  vm->pc = jt2->pc;
}

void
eval(vm_t *vm)
{
  Object *o1, *o2;
  jump_t *jt;

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
      vm->regs[reg1] = (int)vm_add(vm);
      break;
    case OP_SUB:
      vm->regs[reg1] = (int)vm_sub(vm);
      break;
    case OP_MUL:
      vm->regs[reg1] = (int)vm_mul(vm);
      break;
    case OP_DIV:
      vm->regs[reg1] = (int)vm_div(vm);
      break;
    case OP_MOD:
      vm->regs[reg1] = (int)vm_mod(vm);
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

      o2 = get_var(vm, o1);
      if (o2 == NULL) {
        log_err("Undefined function.");
        exit(1);
      }

      if (o2->ctype == CTCFUNC) {
        call_c_function(vm, o2);
      } else if (o2->ctype == CTFUNC) {
        call_function(vm, o2);
      } else {
        log_err("func call");
        exit(1);
      }
      break;
    case OP_PUSH:
      if (imm == 0) {
        imm = (void*)vm->regs[reg1];
      }
      o1 = (void*)imm;
      
      stack_push(vm, (Object *)imm);
      break;
    case OP_GETARG:
      // o1 is identifier
      o1 = stack_pop(vm);
      o2 = scope_get((scope_t*)imm, o1->value.p);

      vm->regs[reg1] = (int)o2;
      break;
    case OP_JUMP:
      jt = (jump_t *)(imm);

      vm->regs[jx] = vm->pc;
      vm->pc = jt->pc;
      break;
    case OP_NOOP:
      // for debug use
      break;
    case OP_RET:
      if (vm->regs[jx] == 0) {
        break;
      }
      vm->pc = vm->regs[jx];
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

  ret = pool_alloc(vm->pool, sizeof(scope_t));
  if (ret == NULL) {
    log_err("malloc failed\n");
    exit(1);
  }

  ret->env = kh_init(env);
  ret->parent = vm->current;
  ret->argc = 0;
  vm->current = ret;

  return ret;
}

// do not change the current scope
// just return a new scope
scope_t *
scope_new_raw(vm_t *vm)
{
  scope_t *ret;

  ret = pool_alloc(vm->pool, sizeof(scope_t));
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

Object *
scope_kget(scope_t *s, int k)
{
  if (k >= kh_end(s->env)) {
    return NULL;
  }

  return kh_value(s->env, k);
}

void
scope_kset(scope_t *s, int k, Object *v)
{
  if (k >= kh_end(s->env)) {
    return;
  }

  kh_value(s->env, k) = v;
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
  "OP_NOOP", "OP_HALT", "OP_LOADV", "OP_LOADI", "OP_ADD",
  "OP_SUB", "OP_AND", "OP_MUL", "OP_DIV",
  "OP_MOD", "OP_NOT", "OP_PUSH", "OP_MOVE",
  "OP_CALL", "OP_SETARG", "OP_GETARG", "OP_JUMP",
  "OP_RET",
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
    printf("%d: %s, ARG1: %d, POINTER: %p\n", i, opcode_name(ins->op), ins->arg1, ins->p);
  }
}

Object *
define_c_function(vm_t *vm, void (*functor)(vm_t *, int), int nargs)
{
  Object *o;
  o = pool_alloc(vm->pool, sizeof (Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }

  o->ctype = CTCFUNC;
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
link_function_current(vm_t *vm, const char *name, Object * functor)
{
  scope_push(vm->current, name, functor);
}

void
link_function_top(vm_t *vm, const char *name, Object *functor)
{
  scope_push(vm->scope, name, functor);
}


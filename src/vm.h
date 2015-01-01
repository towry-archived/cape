// vm.h
// Copyright 2014 by Towry Wang

#ifndef _VM_H
#define _VM_H

#include "intern.h"
#include "opcode.h"
#include "khash.h"
#include "kvec.h"
#include "pool.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_REGS 256
#define r0 0
#define r1 1
#define r2 2
#define r3 3
#define dx 255

typedef struct instruction_ {
  int op;
  int arg1;
  int arg2;
  int arg3;
  void *p;
} instruction_t;

KHASH_MAP_INIT_STR(env, Object *)

// free env
typedef struct scope_ {
  khash_t(env) *env;
  struct scope_ *parent;
} scope_t;

typedef struct vm_ {
  unsigned regs[NUM_REGS];
  int r;
  int pc;
  instruction_t *ins[1024];
  int nins;
  int running;
  Object *exitval;
  scope_t *scope;
  scope_t *current;
  kvec_t(Object *) stack;
  int ns;   // limit the stack
  pool_t *pool;
} vm_t;

#define ABC(op, a, b, c) ins_abc((vm), (op), (a), (b), (c)) 
#define AB(op, a, b) ins_ab((vm), (op), (a), (int)(b))
#define LASTINS  (vm->ins[vm->nins-1])
void vm_init(vm_t *);
void vm_free(vm_t *);
void vm_halt(vm_t *);
Object *vm_run(vm_t *);
instruction_t *ins_abc(vm_t*, int, int, int, int);
instruction_t *ins_ab(vm_t*, int, int, int);
scope_t *scope_new(vm_t *);
scope_t *scope_new_raw(vm_t *);
void scope_push(scope_t *, const char *, Object *);
void scope_del(scope_t *, const char *);
void scope_set(scope_t *, const char *, Object *);
Object *scope_get(scope_t *, const char *);
int scope_lookup(scope_t *, const char *);
void print_instruct(vm_t *);
void stack_push(vm_t *, Object *);
Object *stack_pop(vm_t *);
int stack_size(vm_t *);

#endif

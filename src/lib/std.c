// std.c 
// Copyright 2014 by Towry Wang

#include "intern.h"
#include "vm.h"
#include <stdio.h>

void
std_print(vm_t *vm, int nargs)
{
  Object *o;

  o = stack_pop(vm);

  switch(o->ctype) {
    case CTINT:
      printf("%d", o->value.i);
      break;
    case CTFLOAT:
      printf("%f", o->value.f);
      break;
    case CTSTRING:
      printf("%s", o->value.p, o->len);
      break;
    default:
      printf("Unknow");
      break;
  }
}

void
std_println(vm_t *vm, int nargs)
{
  std_print(vm, nargs);
  printf("\n");
}

void
bind_lib_std()
{
  Object *
}
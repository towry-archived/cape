
#ifdef TEST_VM

#include "intern.h"
#include "vm.h"

int
main()
{
  vm_t vm;
  Object *o, *o2, *o3, *os, *os2;
  Object *exitval;

  o = malloc(sizeof(Object));
  o->ctype = CTFLOAT;
  o->value.f = 482.3;

  o2 = malloc(sizeof(Object));
  o2->ctype = CTFLOAT;
  o2->value.f = 12.1;

  o3 = malloc(sizeof(Object));
  o3->ctype = CTINT;
  o3->value.i = 300;

  os = malloc(sizeof(Object));
  os->ctype = CTSTRING;
  os->value.p = "Hello";

  os2 = malloc(sizeof(Object));
  os2->ctype = CTSTRING;
  os2->value.p = " World";

  vm_init(&vm);

  push_ins(&vm, AB(OP_LOADV, r0, o));
  push_ins(&vm, AB(OP_LOADV, r1, o2));
  push_ins(&vm, ABC(OP_SUB, r2, r0, r1));
  push_ins(&vm, ABC(OP_HALT, 0, 0, 0));

  exitval = vm_run(&vm);

  switch(exitval->ctype) {
    case CTINT:
      printf("%d\n", exitval->value.i);
      break;
    case CTFLOAT:
      printf("%f\n", exitval->value.f);
      break;
    case CTSTRING:
      printf("%s:%d\n", exitval->value.p, exitval->len);
      break;
    default:
      printf("Unknow\n");
      break;
  }

  return 0;
}

#endif

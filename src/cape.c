// Copyright 2014 by Towry Wang

#include "intern.h"
#include "debug.h"
#include "vm.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

extern void lex_init(char *); 
extern int yyparse();

#ifndef _CTREE_
Node *xtop;
#endif

int main(int argc, char *argv[])
{
  xtop = NULL;
  vm_t vm;
  Object *exitval;

  if (argc > 1) {
    lex_init(argv[1]);
    yyparse();
  } else {
    log_info("Nothing input");
    return 1;
  }

  vm_init(&vm);

  bind_lib_std(&vm);

  // tree_traverse(xtop, 0);
  parse_node(&vm, xtop);
  
  push_ins(&vm, ABC(OP_HALT, 0, 0, 0));

  // print_instruct(&vm);

  exitval = vm_run(&vm);

  // switch(exitval->ctype) {
  //   case CTINT:
  //     printf("%d\n", exitval->value.i);
  //     break;
  //   case CTFLOAT:
  //     printf("%f\n", exitval->value.f);
  //     break;
  //   case CTSTRING:
  //     printf("%s:%d\n", exitval->value.p, exitval->len);
  //     break;
  //   default:
  //     printf("Unknow\n");
  //     break;
  // }

  return 0;
}

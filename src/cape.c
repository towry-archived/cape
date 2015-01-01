// cape.c
// Copyright 2014 by Towry Wang

#include "intern.h"
#include "debug.h"
#include "vm.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

extern void lex_init(char *); 
extern int yyparse();

#ifndef _CTTREE_
Node *xtop;
#endif

static int usage() {
  printf("usage: cape [options] [file]\n"
         "options:\n"
         "  -e   eval code\n"
         "  -d   show debug info (multiple times for more)\n"
         "  -v   print version\n"
         "  -h   print this\n");
  return 1;
}

int main(int argc, char *argv[])
{
  xtop = NULL;
  vm_t vm;
  Object *exitval;

  if (argc > 1) {
    lex_init(argv[1]);
    yyparse();
  } else {
    usage();
    return 1;
  }

  vm_init(&vm);

  bind_lib_std(&vm);

  // tree_traverse(xtop, 0);
  // exit(0);

  parse_node(&vm, xtop);
  
  vm_halt(&vm);

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

  vm_free(&vm);
  node_free(xtop);

  return 0;
}

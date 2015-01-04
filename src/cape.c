// cape.c
// Copyright 2014 by Towry Wang

#include "intern.h"
#include "debug.h"
#include "vm.h"
#include "node.h"

#ifdef __unix__
# include <unistd.h>
#else
# include "getopt.h"
#endif

#include <stdio.h>
#include <stdlib.h>

extern void lex_init(char *); 
extern int yyparse();

#ifndef _CTTREE_
Node *xtop;
#endif

static int 
usage(int e) {
  printf("usage: cape [options] [file]\n"
         "options:\n"
         "  -t   print ast tree\n"
         "  -i   print instruction\n"
         "  -v   print version\n"
         "  -h   print this\n");
  exit(e);
}

static void
version(int i) {
  printf("Cape version " VERSION "\n");
  if (i) {
    exit(0);
  }
}

int main(int argc, char *argv[])
{
  xtop = NULL;
  vm_t vm;
  int opt;
  char *source = NULL;
  int print_tree = 0;
  int print_ins = 0;
  Object *exitval;

  while ((opt = getopt(argc, argv, "t:i:vh")) != -1) {
    switch (opt) {
      case 't':
        print_tree = 1;
        source = optarg;
        break;
      case 'i':
        print_ins = 1;
        source = optarg;
        break;
      case 'v':
        version(1);
        break;
      case 'h':
        usage(0);
        break;
      default:
        usage(0);
        break;
    }
  }  

  argc -= optind;
  argv += optind;

  if (argc > 0) {
    source = argv[argc-1];
  }

  if (source == NULL) {
    usage(0);
  }

  lex_init(source);
  yyparse();

  vm_init(&vm);

  bind_lib_std(&vm);

  // print ast tree
  if (print_tree) {
    tree_traverse(xtop, 0);
    exit(0);
  }

  parse_node(&vm, xtop);
  
  vm_halt(&vm);

  // print instructions
  if (print_ins) {
    print_instruct(&vm);
    exit(0);
  }

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

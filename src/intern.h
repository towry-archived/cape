// intern.h
// Copyright 2014 by Towry Wang

#ifndef _INTERN_H
#define _INTERN_H

/* keep it simple */

#define nil 0

typedef union {
  short reg;
  short b;
  int i;
  float f;
  void *p;
} Value;

typedef enum {
  CTabcdefg = 0,

  CTNIL,
  CTBOOL,
  CTSTRING,
  CTIDENT,
  CTFLOAT,
  CTINT,
  CTFUNC, 
  CTCFUNC,
  CTREF,
} ValueType;

typedef struct Object_ {
  short ctype;
  Value value;
  int len;
} Object;
#define ov(x, y)  (x->value.y)

typedef enum {
  NT_abcdefg,

  CONST_INT,
  CONST_FLOAT,
  CONST_STRING,
  CONST_IDENT,
  CONST_BOOL,
  NT_IMPORT,
  NT_FUNC,
  NT_STMT,
  NT_STMT_LIST,
  NT_LIST,
  NT_EXPR,
  NT_CALL,
  NT_ARGS,
  NT_PARAM,
  NT_GET,
  NT_ASSIGN,    // =
  NT_VASSIGN,   // :=
  NT_OR,
  NT_AND,
  NT_LE,
  NT_GE,
  NT_NE,
  NT_EQ,
  NT_GT,
  NT_LT,
  NT_ADD,
  NT_SUB,
  NT_MUL,
  NT_DIV,
  NT_MOD,
  NT_SHAND, /* shift and */
  NT_SHOR,
  NT_UNEG,  /* - factor */
  NT_UNOT,  /* ! factor */
  NT_DECL,
  NT_TYPE,
  NT_NOT,
  NT_VAR,
  NT_PROGRAM,
} NodeType;

typedef struct Node_ {
  struct Node_ *left;
  struct Node_ *right;
  NodeType type;
  Object *o;
} Node;

typedef union YYSTYPE {
  struct Node_ *node;
} YYSTYPE;

extern Node *xtop;

Node *make_node(NodeType, Node*, Node *, Object*);
Node *list2(Node *, Node *);
Node *const_int_node(int);
Node *const_bool_node(int);
Node *const_float_node(float);
Node *const_string_node(char *);
Node *const_ident_node(char *);
Object *null_value();
Object *int_value(int);
Object *float_value(float);
Object *bool_value(int);
Object *string_value(const char*);
int tree_traverse(Node *, int);

#endif

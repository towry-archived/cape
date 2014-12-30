// Copyright 2014 by Towry Wang

#include "intern.h"
#include "debug.h"
#include "vm.h"
#include <stdlib.h>
#include <string.h>

Object o = { .ctype = CTNIL };

Object *
null_value()
{
  return &o;
}

Object *
int_value(int i)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTINT;
  o->value.i = i;
  return o;
}

Object *
float_value(float f)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTFLOAT;
  o->value.f = f;
  return o;
}

Object *
string_value(const char *s)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTSTRING;
  o->value.p = strdup(s);
  return o;
}

Object *
bool_value(int i)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTBOOL;
  o->value.b = i;
  return o;
}

Node *
make_node(NodeType t, Node* left, 
                Node *right, Object *v)
{
  Node *node;

  if ((node = malloc(sizeof(*node)))) {
    node->type = t;
    node->left = left;
    node->right = right;
    node->o = v;
    return node;
  }

  log_err("failed to make node");
  return NULL;
}

Node *
const_int_node(int v)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTINT;
  o->value.i = v;

  return make_node(CONST_INT, NULL, NULL, o);
}

Node *
const_float_node(float v)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTFLOAT;
  o->value.f = v;

  return make_node(CONST_FLOAT, NULL, NULL, o);
}

Node *
const_string_node(char *s)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }

  o->ctype = CTSTRING;
  o->value.p = s;

  return make_node(CONST_STRING, NULL, NULL, o);
}

Node *
const_ident_node(char *s)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTSTRING;
  o->value.p = strdup(s);

  return make_node(CONST_IDENT, NULL, NULL, o);
}

Node*
const_bool_node(int i)
{
  Object *o;

  o = malloc(sizeof(Object));
  if (o == NULL) {
    log_err("malloc");
    exit(1);
  }
  
  o->ctype = CTBOOL;
  o->value.b = i;

  return make_node(CONST_BOOL, NULL, NULL, o);
}

Node *
list2(Node *a, Node *b)
{
  return make_node(NT_LIST, a, b, null_value());
}

#define ttl(x, y)  if (x->left != NULL) tree_traverse(x->left, y)
#define ttr(x, y)  if (x->right != NULL) tree_traverse(x->right, y)

static void
prefix(int offset)
{
  while (offset--) {
    putc(' ', stdout);
  }
}

static void
print_const_node(Node *tree, int offset)
{
  switch(tree->o->ctype) {
    case CTNIL:
      printf("CTNIL\n");
      prefix(offset);
      printf("No value");
      break;
    case CTBOOL:
      printf("CTBOOL\n");
      prefix(offset);
      printf("value: %d\n", ov(tree->o, b));
      break;
    case CTINT:
      printf("CTINT\n");
      prefix(offset);
      printf("value: %d\n", ov(tree->o, i));
      break;
    case CTFLOAT:
      printf("CTFLOAT\n");
      prefix(offset);
      printf("value: %d\n", ov(tree->o, f));
      break;
    case CTSTRING:
      printf("CTSTRING\n");
      prefix(offset);
      printf("value: %s\n", ov(tree->o, p));
      break;
    default:
      printf("Unknow\n");
      break;
  }
}

int
tree_traverse(Node *tree, int offset)
{
  if (tree != NULL) {
    prefix(offset);
  } else {
    return 0;
  }

  switch(tree->type) {
    case NT_PROGRAM:
      ttl(tree, offset);
      ttr(tree, offset);
      break;
    case NT_STMT_LIST:
      printf("NT_STMT_LIST\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_STMT:
      printf("NT_STMT\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_LIST:
      ttl(tree, offset);
      ttr(tree, offset);
      break;
    case NT_CALL:
      printf("NT_CALL\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_ARGS:
      printf("NT_ARGS\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case CONST_INT:
    case CONST_BOOL:
    case CONST_FLOAT:
    case CONST_IDENT:
    case CONST_STRING:
      print_const_node(tree, offset);
      break;
    case NT_ASSIGN:
      printf("NT_ASSIGN\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_VASSIGN:
      printf("NT_VASSIGN\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_ADD:
      printf("NT_ADD\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_SUB:
      printf("NT_SUB\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_MUL:
      printf("NT_MUL\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_DIV:
      printf("NT_DIV\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_MOD:
      printf("NT_MOD\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_FUNC:
      printf("NT_FUNC\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_PARAM:
      printf("NT_PARAM\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_DECL:
      printf("NT_DECL\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_VAR:
      printf("NT_VAR\n");
      ttl(tree, offset+1);
      ttr(tree, offset+1);
      break;
    case NT_TYPE:
      switch(tree->o->ctype)
      {
        case CTSTRING:
          prefix(offset);
          printf("string\n");
          break;
        default:
          prefix(offset);
          printf("INT|TFLOAT|TBOOL|TNIL\n");
      }
      break;
    default:
      log_info("Unknow type %d", tree->type);
      break;
  }
}


static scope_t * 
var_in_scope(scope_t *s, Object *a)
{
  scope_t *scope;
  scope = s;
  while (scope != NULL) {
    if (scope_lookup(scope, a->value.p)) {
      return scope;
    }

    scope = scope->parent;
  }

  return NULL;
}

static int
var_in_current_scope(scope_t *s, Object *a)
{
  if (scope_lookup(s, a->value.p)) {
    return 1;
  }

  return 0;
}

static void
assign(vm_t *vm, Object *arg1, Object *arg2)
{
  if (!var_in_scope(vm->current, arg1)) {
    log_err("Variable not declared.");
    exit(1);
  }

  scope_push(vm->current, arg1->value.p, arg2);
}

static void
vassign(vm_t *vm, Object *arg1, Object *arg2)
{
  if (var_in_current_scope(vm->current, arg1)) {
    log_err("Variable already declared.");
    exit(1);
  }

  scope_push(vm->current, arg1->value.p, arg2);
}

Object *
get_var(vm_t *vm, Object *id)
{
  scope_t *scope;

  if ((scope = var_in_scope(vm->current, id)) == NULL) {
    log_err("Variable not declared.");
    exit(1);
  }

  // get variable value from that scope
  return scope_get(scope, id->value.p);
}

static void
prepare_arg(vm_t *vm, Node *node)
{
  Node *left;
  Object *o;
  
  if (node == NULL) {
    return;
  }

  left = node->left;
  if (left == NULL) {
    return;
  }

  if (left->type == CONST_IDENT) {
    push_ins(vm, AB(OP_PUSH, r0, left->o));
    push_ins(vm, AB(OP_GETARG, r2, vm->current));
    push_ins(vm, AB(OP_PUSH, r2, 0));
  } else {
    push_ins(vm, AB(OP_PUSH, r0, left->o));
  }
}

#define pnl(x)   if (x->left != NULL) parse_node(vm, x->left)
#define pnr(x)   if (x->right != NULL) parse_node(vm, x->right)
#define rpnl(x)   x->left != NULL ? parse_node(vm, x->left) : NULL
#define rpnr(x)   x->right != NULL ? parse_node(vm, x->right) : NULL

Object *
parse_node(vm_t *vm, Node *node)
{
  Object *oo;

  if (node == NULL) {
    return NULL;
  }

  switch(node->type) {
    case NT_PROGRAM:
      scope_new(vm);
      pnl(node);
      pnr(node);
      break;
    case NT_STMT_LIST:
      pnl(node);
      pnr(node);
      break;
    case NT_STMT:
      pnl(node);
      pnr(node);
      break;
    case NT_LIST:
      pnl(node);
      pnr(node);
      break;
    case NT_CALL:
      // type checking not done yet
      // push args first
      pnr(node);
      // push method
      push_ins(vm, AB(OP_PUSH, 0, rpnl(node)));
      push_ins(vm, AB(OP_CALL, 0, 0));
      break;
    case NT_ARGS:
      // push the args into stack
      prepare_arg(vm, node);
      break;
    case CONST_IDENT:
    case CONST_STRING:
    case CONST_FLOAT:
    case CONST_BOOL:
    case CONST_INT: 
      return node->o;
      break;
    case NT_ASSIGN:
      assign(vm, rpnl(node), NULL);
      break;
    case NT_VASSIGN:
      oo = rpnr(node);

      instruction_t *ins = LASTINS;
      if (ins != NULL) {
        switch (ins->op) {
          case OP_ADD:
          case OP_SUB:
            oo = rpnl(node);
            vassign(vm, oo, NULL);
            push_ins(vm, AB(OP_PUSH, 0, oo));
            push_ins(vm, AB(OP_SETARG, r2, vm->current));
            break;
          default:
            vassign(vm, rpnl(node), oo);
            break;
        }
      } else {
        vassign(vm, rpnl(node), oo);
      }
      break;
    case NT_ADD:
      push_ins(vm, AB(OP_LOADV, r0, get_var(vm, rpnl(node))));
      push_ins(vm, AB(OP_LOADV, r1, get_var(vm, rpnr(node))));
      push_ins(vm, ABC(OP_ADD, r2, r0, r1));
      break;
    case NT_SUB:
      push_ins(vm, AB(OP_LOADV, r0, get_var(vm, rpnl(node))));
      push_ins(vm, AB(OP_LOADV, r1, get_var(vm, rpnr(node))));
      push_ins(vm, ABC(OP_SUB, r2, r0, r1));
      break;
    case NT_MUL:
      break;
    case NT_DIV:
      break;
    case NT_MOD:
      break;
    case NT_FUNC:
      break;
    case NT_PARAM:
      break;
    case NT_DECL:
      break;
    case NT_VAR:
      break;
    case NT_TYPE:
      break;
    default:
      log_info("default");
      break;
  }
}

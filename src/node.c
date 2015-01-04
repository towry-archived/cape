// node.c
// Copyright 2014 by Towry Wang

#include "intern.h"
#include "debug.h"
#include "vm.h"
#include "node.h"
#include <stdlib.h>
#include <string.h>

void
node_free(Node *top)
{
  if (top == NULL) {
    return;
  }

  if (top->o != NULL) {
    free(top->o);
  }

  if (top->left != NULL) {
    node_free(top->left);
  }

  if (top->right != NULL) {
    node_free(top->right);
  }
}

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
  
  o->ctype = CTIDENT;
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
    case CTIDENT:
      printf("CTIDENT\n");
      prefix(offset);
      printf("value: %s\n", ov(tree->o, p));
      break;
    default:
      printf("Unknow: %d\n", tree->o->ctype);
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

  // if it's literal
  if (id->ctype != CTIDENT) {
    return id;
  }

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

static void
assign_multiple_var(vm_t *vm, Node *n, Object *t)
{
  Node *a;

  if (n == NULL) return;

  a = n;
  while (a != NULL) {
    if (a->type == NT_LIST) {
      assign_multiple_var(vm, a->left, t);
      assign_multiple_var(vm, a->right, t);
    }

    if (a->type = NT_VAR) {
      a = a->left; // ident
      vm->current->argc++;

      scope_push(vm->current, a->o->value.p, t);
    }

    break;
  }
}

static void
make_decl(vm_t *vm, Node *n)
{
  Object *t;
  Node *a;

  t = rpnr(n);
  if (t == NULL) {
    log_err("Need type");
    exit(1);
  }

  a = n->left;
  assign_multiple_var(vm, a, t);
}

static void
prepare_param(vm_t *vm, Node *node)
{
  if (node == NULL) return;

  if (node->type == NT_DECL) {
    make_decl(vm, node);
    return;
  }

  prepare_param(vm, node->left);
  prepare_param(vm, node->right);
}

static Object *
define_function(vm_t *vm, Node *node)
{
  Object *o;
  jump_t *jt = jump_new(vm);
  Node *n;

  o = pool_alloc(vm->pool, sizeof (Object));
  if (o == NULL) {
    exit(1);
  }

  jt->pc = vm->nins;
  o->ctype = CTFUNC;
  o->value.p = (void *)jt;
  o->closure = NULL;

  // now n is a list
  // and in the left of list is the params
  // in the right of list is the body
  // there may have some errors.

  return o;
}

Object *
parse_node(vm_t *vm, Node *node)
{
  Object *oo, *oo2;

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
      push_ins(vm, AB(OP_PUSH, 0, node->o));
      push_ins(vm, AB(OP_GETARG, dx, vm->current));
      return node->o;
      break;
    case CONST_STRING:
    case CONST_FLOAT:
    case CONST_BOOL:
    case CONST_INT: 
      // primary
      push_ins(vm, AB(OP_LOADI, dx, node->o));
      return node->o;
      break;
    case NT_ASSIGN:
      oo = rpnl(node); // get variable name
      assign(vm, oo, NULL);

      pnr(node);
      push_ins(vm, AB(OP_PUSH, 0, oo));
      push_ins(vm, AB(OP_SETARG, dx, vm->current));
      break;
    case NT_VASSIGN:
      oo = rpnl(node); // get variable name
      vassign(vm, oo, NULL);
      pnr(node);
      push_ins(vm, AB(OP_PUSH, 0, oo));
      push_ins(vm, AB(OP_SETARG, dx, vm->current));
      break;
    case NT_ADD:
      pnl(node);
      // push the result to stack
      push_ins(vm, AB(OP_PUSH, dx, 0));

      pnr(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      // like a method call
      push_ins(vm, ABC(OP_ADD, r2, 0, 0));
      push_ins(vm, AB(OP_MOVE, dx, r2));
      break;
    case NT_SUB:
      pnl(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      pnr(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      push_ins(vm, ABC(OP_SUB, r2, 0, 0));
      push_ins(vm, AB(OP_MOVE, dx, r2));
      break;
    case NT_MUL:
      pnl(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      pnr(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      push_ins(vm, ABC(OP_MUL, r2, 0, 0));
      push_ins(vm, AB(OP_MOVE, dx, r2));
      break;
    case NT_DIV:
      pnl(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      pnr(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      push_ins(vm, ABC(OP_DIV, r2, 0, 0));
      push_ins(vm, AB(OP_MOVE, dx, r2));
      break;
    case NT_MOD:
      pnl(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      pnr(node);
      push_ins(vm, AB(OP_PUSH, dx, 0));

      push_ins(vm, ABC(OP_MOD, r2, 0, 0));
      push_ins(vm, AB(OP_MOVE, dx, r2));
      break;
    case NT_FUNC:
      // compile this function to instruction code
      oo = rpnl(node); // func name

      // set jump
      jump_t *jt = jump_new(vm);
      push_ins(vm, AB(OP_JUMP, 0, jt));

      oo2 = define_function(vm, node);
      link_function_current(vm, oo->value.p, oo2);

      oo2->closure = (void *)scope_new(vm);
      prepare_param(vm, node->right->left);      
      // compile func body
      pnr(node->right);
      push_ins(vm, AB(OP_RET, 0, 0));
      jt->pc = vm->nins;
      break;
    case NT_PARAM:
      pnl(node);
      pnr(node);
      break;
    case NT_DECL:
      break;
    case NT_VAR:
      break;
    case NT_TYPE:
      return node->o;
      break;
    default:
      log_info("default");
      break;
  }
}

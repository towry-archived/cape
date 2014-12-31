// opcode.h
// Copyright 2014 by Towry Wang

#ifndef _OPCODE_H
#define _OPCODE_H

// vm bytecode opcode

enum {
  OP_HALT,
  OP_LOADV,
  OP_LOADI,
  OP_ADD,
  OP_SUB,
  OP_AND,
  OP_MUL,
  OP_DIV,
  OP_MOD,
  OP_OR,
  OP_XOR,
  OP_NOT,
  OP_PUSH,
  OP_MOVE,    // OP A B, move B to A
  OP_CALL,
  OP_SETARG,    // this opcode need a register and a scope
  OP_GETARG,
};

#endif

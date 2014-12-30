// opcode.h
// Copyright 2014 by Towry Wang

#ifndef _OPCODE_H
#define _OPCODE_H

// vm bytecode opcode

enum {
  OP_HALT,
  OP_LOADV,
  OP_ADD,
  OP_SUB,
  OP_AND,
  OP_OR,
  OP_XOR,
  OP_NOT,
  OP_LOAD,
  OP_STOR,
  OP_JMP,
  OP_JZ,
  OP_PUSH,
  OP_DUP,
  OP_MOVE,
  OP_JNZ,
  OP_PUSHIP,
  OP_POPIP,
  OP_NOP_END,
  OP_CALL,
  OP_SYSCALL,
  OP_SETARG,    // this opcode need a register and a scope
  OP_GETARG,
};

#endif

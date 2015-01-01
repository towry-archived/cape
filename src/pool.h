/*

Copyright (C) 2011 Vincent van Ingen <vin@ingine.nl>

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use
of this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely.

Terms and conditions for copying, distribution and modification:

0. Just do whatever you want to do with it!

*/



#ifndef POOL_H
#define POOL_H

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define POOL_VERSION "0.1"
#define POOL_SET_SIZE 1
#define POOL_SET_SIZE_DEFAULT 4096
#define POOL_NO_ERROR 0
#define POOL_ERROR_MEMORY_ALLOC 1
#define POOL_ERROR_POOL_IS_NULL 2

typedef struct pool pool_t;

void *pool_alloc( pool_t *p, int size );
void pool_free( pool_t *p );
pool_t *pool_new( int size );
void pool_set( int var, int value );

#ifdef __cplusplus
}
#endif

#endif


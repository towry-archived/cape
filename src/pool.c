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



#include "pool.h"


/* Fixes a warning message */
#ifdef __LP64__
    #define PERROR long
#else
    #define PERROR int
#endif


static PERROR error( int errnum, const char *func );
static pool_t *getpool( pool_t *p, int size );

struct pool
{
    void *data;
    int size, max_size;
    pool_t *next;
};

static int pool_set_size = POOL_SET_SIZE_DEFAULT;

static char *errmsgs[] = {
    "No error.",
    "Memory allocation error.",
    "Pool is NULL."
};




/*
 * Prints an error message.
 */
 static PERROR error( int errnum, const char *func )
 {
    fprintf( stderr, "Error #%04i in function '%s': %s\n", errnum, func, errmsgs[errnum] );
    return 0;
 }



/*
 * Returns available pool for pool_alloc()
 * If not, create a new pool.
 */
static pool_t *getpool( pool_t *p, int size )
{
    if( !p ) {
        return (pool_t*)error( POOL_ERROR_POOL_IS_NULL, __FUNCTION__ );
    }

    // If we got some space left in this pool, return it!
    if( p->size + size <= p->max_size ) {
        return p;
    }

    // We got another pool, check it if it's availabe
    if( p->next ) {
        return getpool( p->next, size );
    }

    // Create a new pool and return it
    p->next = pool_new( size );

    if( !p->next ) {
        return 0; // pool_new() will return the errmsg
    }

    return p->next;
}



/*
 * Allocate memory from within the *pool
 */
void *pool_alloc( pool_t *p, int size )
{
    // Get a pool, or create one, with at least the
    // size of free space to allocate.
    p = getpool( p, size );

    if( !p ) {
        return (char*)error( POOL_ERROR_POOL_IS_NULL, __FUNCTION__ );
    }

    void *a = p->data + p->size;
    p->size += size;
    return a;
}


/*
 * Please children. Get out the pool now!
 */
void pool_free( pool_t *p )
{
    if( !p ) {
	error( POOL_ERROR_POOL_IS_NULL, __FUNCTION__ );
    }

    if( p->next ) {
        pool_free( p->next );
    }

    free( p );
}



/*
 * It creates a new swimming pool! Wheeeee!
 */
pool_t *pool_new( int size )
{
    int max_size = size + sizeof(pool_t);
    
    if( max_size < pool_set_size ) {
	max_size = pool_set_size;
    }

    void *tmp = calloc( 1, max_size );
    
    if( !tmp ) {
	return (pool_t*)error( POOL_ERROR_MEMORY_ALLOC, __FUNCTION__ );
    }

    // The pool_t structure is within the data
    pool_t *p = tmp;
    p->data = tmp;
    p->next = 0;
    p->size = sizeof(pool_t);	// The first space is used for this structure
    p->max_size = max_size;
    return p;
}



/*
 * Change global pool settings.
 */
void pool_set( int var, int value )
{
    switch( var )
    {
        case POOL_SET_SIZE:
        {
            pool_set_size = value;
            break;
        }
    }
}


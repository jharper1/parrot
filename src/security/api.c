/*
Copyright (C) 2012, Parrot Foundation.

=head1 NAME

src/security/api.c - Parrot Security API

=head1 DESCRIPTION

Functions related to managing the Parrot Security

=head2 Functions

=over 4
=cut

*/

#include "parrot/parrot.h"
#include "parrot/security.h"

#define PANIC_ZERO_ALLOCATION(func) panic_zero_byte_allocation(__LINE__, (func)) 
#define PANIC_OUT_OF_MEM(size) panic_failed_allocation(__LINE__, (size))

/* HEADERIZER BEGIN: static */
/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */

PARROT_FUNCTION_NOT_SUPPORTED
static void panic_failed_allocation(unsigned int line, unsigned long size);

PARROT_FUNCTION_NOT_SUPPORTED
static int SECURITY_CONTEXT(PARROT_INTERP, ARGIN(STRING* var))
       __attribute__nonnull__(1);

#define ASSERT_ARGS_SECURITY_CONTEXT __attribute__unused__ int _ASSERT_ARGS_CHECK = (\
       PARROT_ASSERT_ARG(interp) \
    , PARROT_ASSERT_ARG(var))

/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */
/* HEADERIZER END: static */

/* 

=item C<Parrot_sec_allocate_context(interp)

Allocating memory for Interp 

*/


PARROT_EXPORT
PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Parrot_sec_allocate_context(interp)
{
	/*   Allocates a zeroed memory block to the context */
    ASSERT_ARGS(Parrot_sec_allocate_context)
    int * context;

    context = calloc(1, sizeof(int));

    if (context==0)
        PANIC_ZERO_ALLOCATION("Parrot_sec_allocate_context");
#ifdef DETAIL_MEMORY_DEBUG
    fprintf(stderr, "Allocated %i at %p\n", size);
#endif
    return interp;
}

/*

=item C<Parrot_sec_initialize_context(interp, context)

Initializing memory for the Interp.

*/

PARROT_EXPORT
PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Parrot_sec_initialize_context(interp, context, flags, PMC *named_permissions)








/*

=item C<Parrot_sec_free_context(interp, context)

Freeing up memory for the Interp.

*/

Parrot_EXPORT
void 
Parrot_sec_free_context(interp, context)
{
    ASSERT_ARGS(Parrot_sec_free_context)
#ifdef DETAIL_MEMORY_DEBUG
    fprintf(stderr, "Freed %p\n", context);
#endif
    if (context)
        free(context);
}
	




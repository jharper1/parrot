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

/* HEADERIZER BEGIN: static */
/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */

PARROT_FUNCTION_NOT_SUPPORTED
static int Parrot_security(PARROT_INTERP, ARGIN(STRING* var))
       __attribute__nonnull__(1);

#define ASSERT_ARGS_Parrot_secure __attribute__unused__ int _ASSERT_ARGS_CHECK = (\
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
PARROT_Sec
PARROT_sec_allocate_context(interp)
{
    ASSERT_ARGS(Parrot_sec_allocate_context)
    int secure;
    Parrot_GC_Init_Args args;
    memset(&args, 0, sizeof (args));
    args.secure = &secure;
    return interp;
}


/* 

=item C<Parrot_sec_free_context(interp, context)

Freeing up memory for the Interp.

*/

Parrot_EXPORT
void 
Parrot_sec_free_context(interp, context)
{
    ASSERT_ARGS(Parrot_sec_free_context)
    
	

}



/*

*/










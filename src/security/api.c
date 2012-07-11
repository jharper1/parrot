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
       __attribute__nonnull__(2);

#define ASSERT_ARGS_SECURITY_CONTEXT __attribute__unused__ int _ASSERT_ARGS_CHECK = (\
       PARROT_ASSERT_ARG(interp) \
    , PARROT_ASSERT_ARG(var))

/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */
/* HEADERIZER END: static */

#define PERMISSION_SOCKET_IO 0x01
#define PERMISSION_LOAD_BYTECODE 0x02
#define PERMISSION_LOAD_DYNPMC 0x04
#define PERMISSION_LOAD_DYNOP 0x08
 
/* 

=item C<Parrot_sec_allocate_context(interp)

Allocating memory for Interp 

*/


PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Parrot_sec_allocate_context(interp)
{
/*   Allocates a zeroed memory block to the context */
    ASSERT_ARGS(Parrot_sec_allocate_context)
    return (SECURITY_CONTEXT*)mem_sys_allocate_zeroed(sizeof(SECURITY_CONTEXT));
}
/*

=item C<Parrot_sec_initialize_context(interp, context)

Initializing memory for the Interp.

*/

PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Parrot_sec_initialize_context(interp, context, flags, PMC *named_permissions)
{
    ASSERT_ARGS(Parrot_sec_initialize_context)
    Parrot_context_initialize(interp, named_permissions);
    
    int permission; 

  
}
 
return sec->permission_bits & permission;
}


/*

=item C<Parrot_sec_free_context(interp, context)

Freeing up memory for the Interp.

*/

void 
Parrot_sec_free_context(interp, context)
{
    ASSERT_ARGS(Parrot_sec_free_context)
    mem_sys_free(context);
}

/*
Pushes context using old_context as parent


*/	

PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Parrot_sec_push_new_context(interp, old_context)
{
    ASSERT_ARGS(Parrot_sec_push_new_context)
    Interp *Interp
    
    context = Parrot_sec_initialize_context(interp, context);

class old_context{
    private:
        int new_context;
    public:
        void values (int *context)
          {new_context = context}
    };

class sec_context: public old_context{
  public:
    int get_data ()
       { return (new_context);}

    }

return;

}

/*
Gets current context from interp
*/

PARROT_MALLOC
PARROT_CANNOT_RETURN_NULL
Parrot_sec_get_current_context(interp)
{
    ASSERT_ARGS(Parrot_sec_get_current_content)
    return Parrot_sec_push_new_context(interp, context)
}

/*

=back

=head1 SEE ALSO

L<src/security/security_private.h>

=cut

*/

/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4 cinoptions='\:2=2' :
 */

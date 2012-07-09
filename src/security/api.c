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
{
    ASSERT_ARGS(Parrot_sec_initialize_context)
    Parrot_context_initialize(interp, named_permissions);
    
    const int PERMISSION;

    enum named_permissions {
    PERMISSION_SOCKET_IO = 0x01, 
    PERMISSION_LOAD_BYTECODE = 0x02,
    PERMISSION_LOAD_DYNPMC = 0x04,
    PERMISSION_LOAD_DYNOP = 0x08
    };

    PERMISSION = PERMISSION_SOCKET_IO | PERMISSION_LOAD_BYTECODE | PERMISSION_LOAD_DYNPMC | PERMISSION_LOAD_DYNOP;

  
    }
 
return sec->permission_bits & permision;
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
#ifdef DETAIL_MEMORY_DEBUG
    fprintf(stderr, "Freed %p\n", context);
#endif
    if (context)
        free(context);
}

/*
Pushes context using old_context as parent


*/	
Parrot_EXPORT
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
Parrot_EXPORT
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

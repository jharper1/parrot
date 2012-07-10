/* security_private.h
 *  Copyright (C) 2012, Parrot Foundation.
 *  Overview:
 *     This is the API header for the security subsystem
 *  Data Structure and Algorithms:
 *  History:
 *  Notes:
 *  References:
 */

#ifndef PARROT_SECURITY_PRIVATE_H_GUARD
#define PARROT_SECURITY_PRIVATE_H_GUARD

#define SEC_FILE_IO 0x01
#define SEC_LOAD_BYTECODE 0x02
#define SEC_LOAD_DYNLIB 0x04
#define SEC_SOCKET_IO 0x08
#define PERMISSION_ALL 0xFFFFFFFF

typedef struct _security_context {
    struct _security_context * parent_context;
    UINTVAL permission_bits;
} SECURITY_CONTEXT;






/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */
/* HEADERIZER END: src/security/api.c */

#endif /* PARROT_SECURITY_PRIVATE_H_GUARD */

/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4 cinoptions='\:2=2' :
 */

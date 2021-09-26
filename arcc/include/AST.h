#ifndef ARCC_AST_H
#define ARCC_AST_H

#include "token.h"

#include <stdlib.h>

typedef enum NODE_TYPE
{
    //Head node//
    NODE_PROGRAM,
    //Statement and expression nodes//
    NODE_STATEMENT,
    NODE_EXPRESSION,
    //Definition nodes//
    NODE_VARDEF,
    NODE_FUNCDEF,
    //Parameter lists//
    NODE_PARAM_LIST,
    //Terminating nodes//
    NODE_TERMINATOR,
    NODE_INT_CONSTANT
} node_type_t;

typedef struct NODE_STRUCT
{
    node_type_t type;
    void* value; //Used for constant nodes
    struct NODE_STRUCT** children;
    size_t nchildren;
} node_t;

node_t* node_create_with_children(node_type_t type, node_t** children, size_t nchildren);

node_t* node_create(node_type_t type);

void node_destruct(node_t* node);

#endif
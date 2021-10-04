#ifndef ARCC_AST_H
#define ARCC_AST_H

#include "token.h"
#include "list.h"

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
    NODE_ID,
    NODE_INT_CONSTANT,
    NODE_RETURN_KEYWORD,
    NODE_INT_KEYWORD
} node_type_t;

typedef struct NODE_STRUCT
{
    node_type_t type;
    void* value; //Used for constant nodes
    list_t* children;
} node_t;

node_t* node_create_with_children(node_type_t type, void* value, list_t* children, size_t nchildren);

node_t* node_create(node_type_t type, void* value);

void node_destruct(node_t* node);

int node_is_terminator(node_t* node);

void print_ast_indented(node_t* node, int depth);

void print_ast(node_t* node);

#endif
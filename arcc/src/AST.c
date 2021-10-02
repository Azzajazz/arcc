#include "AST.h"
#include "utils.h"

#include <stdio.h>

node_t* node_create_with_children(node_type_t type, void* value, node_t** children, size_t nchildren)
{
    node_t* node = malloc(sizeof(*node));
    node->type = type;
    node->value = value;
    node->children = children;
    node->nchildren = nchildren;
    return node;
}

node_t* node_create(node_type_t type, void* value)
{
    return node_create_with_children(type, value, NULL, 0);
}

void node_destruct(node_t* node)
{
    if (node_is_terminator(node))
    {
        free(node);
    }
    else
    {
        size_t i;
        for (i = 0; i < node->nchildren; i++)
        {
            node_destruct(node->children[i]);
        }
        free(node);
    }
}

int node_is_terminator(node_t* node)
{
    return
        node->type == NODE_ID ||
        node->type == NODE_INT_CONSTANT ||
        node->type == NODE_RETURN_KEYWORD ||
        node->type == NODE_INT_KEYWORD;
}

void print_ast_indented(node_t* node, int depth)
{
    int i;
    for (i = 0; i < depth; i++)
        printf("\t");

    switch (node->type)
    {
        case NODE_PROGRAM:
            printf("<NODE_PROGRAM (%d)>\n", node->type);
            break;
        case NODE_STATEMENT:
            printf("<NODE_STATEMENT (%d)>\n", node->type);
            break;
        case NODE_EXPRESSION:
            printf("<NODE_EXPRESSION (%d)>\n", node->type);
            break;
        case NODE_VARDEF:
            printf("<NODE_VARDEF (%d)>\n", node->type);
            break;
        case NODE_FUNCDEF:
            printf("<NODE_FUNCDEF (%d)>\n", node->type);
            break;
        case NODE_PARAM_LIST:
            printf("<NODE_PARAM_LIST (%d)>\n", node->type);
            break;
        case NODE_ID:
            printf("<NODE_ID (%d), %s>\n", node->type, (char*) node->value);
            break;
        case NODE_INT_CONSTANT:
            printf("<NODE_INT_CONSTANT (%d), %d>\n", node->type, *(int*) node->value);
            break;
        case NODE_RETURN_KEYWORD:
            printf("<NODE_RETURN_KEYWORD (%d)>\n", node->type);
            break;
        case NODE_INT_KEYWORD:
            printf("<NODE_INT_KEYWORD (%d)>\n", node->type);
            break;
        default:
            handle_error("Unknown node type", __func__);
    }

    for (i = 0; i < node->nchildren; i++)
        print_ast_indented(node->children[i], depth + 1);
}

void print_ast(node_t* node)
{
    print_ast_indented(node, 0);
}
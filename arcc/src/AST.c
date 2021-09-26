#include "AST.h"

node_t* node_create_with_children(node_type_t type, node_t** children, size_t nchildren)
{
    node_t* node = malloc(sizeof(*node));
    node->type = type;
    node->children = children;
    node->nchildren = nchildren;
    return node;
}

node_t* node_create(node_type_t type)
{
    return node_create_with_children(type, NULL, 0);
}

void node_destruct(node_t* node)
{
    if (node->type == NODE_TERMINATOR)
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
#include "token.h"
#include <string.h>

token_t* token_create(token_type_t type, void* value)
{
    token_t* token = malloc(sizeof(struct TOKEN_STRUCT));
    token->type = type;
    token->value = value;
    return token;
}
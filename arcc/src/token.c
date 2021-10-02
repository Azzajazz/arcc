#include "token.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

token_t* token_create(token_type_t type, void* value)
{
    token_t* token = malloc(sizeof(*token));
    token->type = type;
    token->value = value;
    return token;
}

void token_destruct(token_t* token)
{
    free(token);
}

void print_token(token_t* token) {
    switch (token->type)
    {
        case TOKEN_KW_INT:
            printf("<TOKEN_KW_INT (%d)>\n", token->type);
            break;
        case TOKEN_KW_RETURN:
            printf("<TOKEN_KW_RETURN (%d)>\n", token->type);
            break;
        case TOKEN_ID:
            printf("<TOKEN_ID (%d), val=%s>\n", token->type, (char*)token->value);
            break;
        case TOKEN_LIT_INT:
            printf("<TOKEN_LIT_INT (%d), val=%d>\n", token->type, *(int*) token->value);
            break;
        case TOKEN_OPEN_PAREN:
            printf("<TOKEN_OPEN_PAREN (%d)>\n", token->type);
            break;
        case TOKEN_CLOSE_PAREN:
            printf("<TOKEN_CLOSE_PAREN (%d)>\n", token->type);
            break;
        case TOKEN_OPEN_BRACE:
            printf("<TOKEN_OPEN_BRACE (%d)>\n", token->type);
            break;
        case TOKEN_CLOSE_BRACE:
            printf("<TOKEN_CLOSE_BRACE (%d)>\n", token->type);
            break;
        case TOKEN_SEMICOLON:
            printf("<TOKEN_SEMICOLON (%d)>\n", token->type);
            break;
        case TOKEN_EOF:
            printf("<TOKEN_EOF (%d)>\n", token->type);
            break;
        case TOKEN_BAD:
            printf("<TOKEN_BAD (%d)>\n", token->type);
            break;
    }
}
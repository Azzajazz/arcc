#include "token.h"
#include "lexer.h"

#include <stdio.h>

int main()
{
    token_t* token;
    lexer_t* lexer = lexer_create("abcdefghijklmnopqrs");
    printf("Created lexer with src %s, pos %d, current %c, src_len %d\n", lexer->src, lexer->pos, lexer->current, lexer->src_len);
    do
    {
        token = lexer_next_token(lexer);
        if (token->type == TOKEN_ID)
            printf("Token value: %s ", (char*) token->value);
        printf("Token type: %d\n", token->type);
    } while (token->type != TOKEN_EOF && token->type != TOKEN_BAD);
    
}
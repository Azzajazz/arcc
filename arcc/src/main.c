#include "token.h"
#include "lexer.h"

#include <stdio.h>

int main()
{
    token_t* token;
    lexer_t* lexer = lexer_create("int main()\n{\n\treturn 4;\n}\n");
    do
    {
        token = lexer_next_token(lexer);
        print_token(token);
    } while (token->type != TOKEN_EOF && token->type != TOKEN_BAD);
    
}
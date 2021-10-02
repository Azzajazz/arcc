#include "token.h"
#include "parser.h"

#include <stdio.h>

int main()
{
    token_t* token;
    lexer_t* lexer = lexer_create("int main() {\n\treturn 4;\n}");
    parser_t* parser = parser_create(lexer);
    node_t* ast = parser_parse_program(parser);
    print_ast(ast);
}
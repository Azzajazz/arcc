#include "token.h"
#include "parser.h"
#include "utils.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Please specify a file.");
        return 1;
    }

    char* src = read_src_file(argv[1]);
    token_t* token;
    lexer_t* lexer = lexer_create(src);
    parser_t* parser = parser_create(lexer);
    node_t* ast = parser_parse_program(parser);
    print_ast(ast);
}
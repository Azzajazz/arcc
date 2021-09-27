#include "parser.h"

#include <stdlib.h>

parser_t* parser_create(lexer_t* lexer, node_t* ast)
{
    parser_t* parser = malloc(sizeof(*parser));
    parser->lexer = lexer;
    parser->ast = ast;
    return parser;
}

void parser_destruct(parser_t* parser)
{
    free(parser);
}
#ifndef ARCC_PARSER_H
#define ARCC_PARSER_H

#include "lexer.h"
#include "AST.h"

typedef struct PARSER_STRUCT
{
    lexer_t* lexer;
    node_t* ast;
} parser_t;

parser_t* parser_create_with_ast(lexer_t* lexer, node_t* ast);

parser_t* parser_create(lexer_t* lexer);

void parser_destruct(parser_t* parser);

node_t* parser_parse_statement(parser_t* parser);

node_t* parser_parse_expr(parser_t* parser);

#endif
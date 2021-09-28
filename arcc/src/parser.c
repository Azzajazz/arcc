#include "parser.h"
#include "lexer.h"
#include "token.h"
#include "utils.h"

#include <stdlib.h>

parser_t* parser_create_with_ast(lexer_t* lexer, node_t* ast)
{
    parser_t* parser = malloc(sizeof(*parser));
    parser->lexer = lexer;
    parser->ast = ast;
    return parser;
}

parser_t* parser_create(lexer_t* lexer)
{
    node_t* root = node_create(NODE_PROGRAM, NULL);
    return parser_create_with_ast(lexer, root);
}

void parser_destruct(parser_t* parser)
{
    free(parser);
}

node_t* parser_parse_statement(parser_t* parser)
{
    node_t** children = malloc(2 * sizeof(*children));
    token_t* token;
    token = lexer_next_token(parser->lexer);
    if (token->type != TOKEN_KW_RETURN)
    {
        free(children);
        handle_error("Expected return token.", __func__);
    }
    children[0] = node_create(NODE_RETURN_KEYWORD, NULL);
    children[1] = parser_parse_expr(parser);
    return node_create_with_children(NODE_STATEMENT, NULL, children, 2);
}

node_t* parser_parse_expr(parser_t* parser)
{
    node_t** children = malloc(sizeof(*children));
    token_t* token;
    token = lexer_next_token(parser->lexer);
    if (token->type != TOKEN_LIT_INT)
    {
        free(children);
        handle_error("Expected integer literal.", __func__);
    }
    children[0] = node_create(NODE_INT_CONSTANT, token->value);
    return node_create_with_children(NODE_EXPRESSION, NULL, children, 1);
}
#include "AST.h"
#include "parser.h"
#include "lexer.h"
#include "token.h"
#include "list.h"
#include "utils.h"

#include <stdlib.h>

// parser_t* parser_create_with_ast(lexer_t* lexer, node_t* ast)
// {
//     parser_t* parser = malloc(sizeof(*parser));
//     parser->lexer = lexer;
//     //parser->ast = ast;
//     return parser;
// }

parser_t* parser_create(lexer_t* lexer)
{
    //node_t* root = node_create(NODE_PROGRAM, NULL);
    //return parser_create_with_ast(lexer);

    parser_t* parser = malloc(sizeof(*parser));
    parser->lexer = lexer;
    return parser;
}

void parser_destruct(parser_t* parser)
{
    free(parser);
}

node_t* parser_parse_statement(parser_t* parser)
{
    list_t* children = list_create_with_size(2);
    token_t* token;

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_KW_RETURN, __func__);
    list_push_back(children, (void*) node_create(NODE_RETURN_KEYWORD, NULL));
    token_destruct(token);

    list_push_back(children, (void*) parser_parse_expr(parser));

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_SEMICOLON, __func__);
    token_destruct(token);

    return node_create_with_children(NODE_STATEMENT, NULL, children, 2);
}

node_t* parser_parse_expr(parser_t* parser)
{
    list_t* children = list_create_with_size(1);
    token_t* token;

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_LIT_INT, __func__);
    list_push_back(children, (void*) node_create(NODE_INT_CONSTANT, token->value));
    token_destruct(token);

    return node_create_with_children(NODE_EXPRESSION, NULL, children, 1);
}

node_t* parser_parse_funcdef(parser_t* parser)
{
    list_t* children = list_create_with_size(3);
    token_t* token;

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_KW_INT, __func__);
    list_push_back(children, (void*) node_create(NODE_INT_KEYWORD, NULL));
    token_destruct(token);

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_ID, __func__);
    list_push_back(children, (void*) node_create(NODE_ID, token->value));
    token_destruct(token);

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_OPEN_PAREN, __func__);
    token_destruct(token);

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_CLOSE_PAREN, __func__);
    token_destruct(token);

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_OPEN_BRACE, __func__);
    token_destruct(token);

    list_push_back(children, (void*) parser_parse_statement(parser));

    token = lexer_next_token(parser->lexer);
    parser_assert_token_type(token, TOKEN_CLOSE_BRACE, __func__);
    token_destruct(token);

    return node_create_with_children(NODE_FUNCDEF, NULL, children, 3);
}

node_t* parser_parse_program(parser_t* parser)
{
    list_t* children = malloc(sizeof(*children));
    list_push_back(children, (void*) parser_parse_funcdef(parser));
    return node_create_with_children(NODE_PROGRAM, NULL, children, 1);
}

void parser_assert_token_type(token_t* token, token_type_t type, const char* fn)
{
    if (token->type != type) {
        char msg[34];
        snprintf(msg, 34, "Expected token type %d, got type %d", type, token->type);
        handle_error(msg, fn);
    }
}
#include "lexer.h"
#include "macros.h"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int is_whitespace(char c)
{
    return c == '\n' || c == '\r' || c == ' ' || c == '\t';
}

int is_id_terminator(char c)
{
    return is_whitespace(c) || c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == '\0';
}

lexer_t* lexer_create_with_pos(const char* src, int pos)
{
    lexer_t* lexer = malloc(sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->pos = pos;
    lexer->current = src[pos];
    lexer->src_len = strlen(src);
    return lexer;
}

lexer_t* lexer_create(char* src)
{
    return lexer_create_with_pos(src, 0);
}

void lexer_advance_by(lexer_t* lexer, int offset) {
    lexer->pos = MIN(lexer->pos + offset, lexer->src_len);
    lexer->current = lexer->src[lexer->pos];
}

void lexer_advance(lexer_t* lexer)
{
    lexer_advance_by(lexer, 1);
}

char lexer_peek(lexer_t* lexer, int offset)
{
    int index = MIN(lexer->pos + offset, lexer->src_len);
    return lexer->src[index];
}

token_t* lexer_read_kw_or_id(lexer_t* lexer)
{
    char identifier[20]; //TODO: Make this support arbitrary length identifiers
    int i = 0;

    while (!is_id_terminator(lexer->current))
    { 
        identifier[i] = lexer->current;
        i += 1;
        lexer_advance(lexer);
        
        if (i >= 20)
            return token_create(TOKEN_BAD, NULL);
    }
    identifier[i] = '\0';

    if (strcmp(identifier, "int") == 0)
    {
        return token_create(TOKEN_KW_INT, NULL);
    }

    if (strcmp(identifier, "return") == 0)
    {
        return token_create(TOKEN_KW_RETURN, NULL);
    }

    char* value = malloc(strlen(identifier) + 1);
    strcpy(value, identifier);
    return token_create(TOKEN_ID, value);
}

token_t* lexer_next_token(lexer_t* lexer)
{
    if (lexer->pos >= lexer->src_len)
    {
        return token_create(TOKEN_EOF, NULL);
    }

    while (is_whitespace(lexer->current))
    {
        lexer_advance(lexer);
    }

    if (isalpha(lexer->current))
        return lexer_read_kw_or_id(lexer);

    switch (lexer->current)
    {
        case '(':
            lexer_advance(lexer);
            return token_create(TOKEN_OPEN_PAREN, NULL);
        
        case ')':
            lexer_advance(lexer);
            return token_create(TOKEN_CLOSE_PAREN, NULL);

        case '{':
            lexer_advance(lexer);
            return token_create(TOKEN_OPEN_BRACE, NULL);
        
        case '}':
            lexer_advance(lexer);
            return token_create(TOKEN_CLOSE_BRACE, NULL);

        case ';':
            lexer_advance(lexer);
            return token_create(TOKEN_SEMICOLON, NULL);
    }

    return token_create(TOKEN_BAD, NULL);
}
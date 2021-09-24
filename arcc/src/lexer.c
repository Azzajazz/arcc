#include "lexer.h"
#include "utils.h"

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
    size_t alloc_size = 20;
    char* identifier = malloc(alloc_size);
    int i = 0;

    while (!is_id_terminator(lexer->current))
    { 
        identifier[i] = lexer->current;
        i += 1;
        lexer_advance(lexer);

        if (i >= alloc_size)
        {
            alloc_size += 5;
            identifier = try_realloc(identifier, alloc_size);
        }
    }
    identifier[i] = '\0';

    if (strcmp(identifier, "int") == 0)
    {
        free(identifier);
        return token_create(TOKEN_KW_INT, NULL);
    }

    if (strcmp(identifier, "return") == 0)
    {
        free(identifier);
        return token_create(TOKEN_KW_RETURN, NULL);
    }

    char* value = malloc(strlen(identifier) + 1);
    strcpy(value, identifier);
    free(identifier);
    return token_create(TOKEN_ID, value);
}

token_t* lexer_read_num_lit(lexer_t* lexer)
{
    size_t alloc_size = 20;
    char* identifier = malloc(alloc_size);
    int i = 0;

    while (!is_id_terminator(lexer->current))
    {
        if (!isdigit(lexer->current))
            return token_create(TOKEN_BAD, NULL);

        identifier[i] = lexer->current;
        i += 1;
        lexer_advance(lexer);

        if (i >= alloc_size)
        {
            alloc_size += 5;
            identifier = try_realloc(identifier, alloc_size);
        }
    }
    identifier[i] = '\0';

    int* value = malloc(sizeof(*value));
    *value = atoi(identifier);
    free(identifier);
    return token_create(TOKEN_LIT_INT, value);
}

//TODO: Add support for integer literals
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
    
    if (isdigit(lexer->current))
        return lexer_read_num_lit(lexer);

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
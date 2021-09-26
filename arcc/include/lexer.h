#ifndef ARCC_LEXER_H
#define ARCC_LEXER_H

#include "token.h"

typedef struct LEXER_STRUCT
{
    const char* src;
    int pos;
    char current;
    int src_len;
} lexer_t;

int is_whitespace(char c);

lexer_t* lexer_create_with_pos(const char* src, int pos);

lexer_t* lexer_create(char* src);

void lexer_destruct(lexer_t* lexer);

void lexer_advance_by(lexer_t* lexer, int offset);

void lexer_advance(lexer_t* lexer);

char lexer_peek(lexer_t* lexer, int offset);

char* lexer_peek_range(lexer_t* lexer, int length);

token_t* lexer_read_kw_or_id(lexer_t* lexer);

token_t* lexer_read_num_lit(lexer_t* lexer);

token_t* lexer_next_token(lexer_t* lexer);

#endif
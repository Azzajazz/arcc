#ifndef ARCC_LEXER_H
#define ARCC_LEXER_H

typedef struct LEXER_STRUCT
{
    char* src;
    int pos;
    int src_len;
} lexer_t;

lexer_t* lexer_create_with_pos(char* src, int pos);

lexer_t* lexer_create(char* src);

void lexer_advance_by(lexer_t* lexer, int offset);

void lexer_advance(lexer_t* lexer);

char lexer_peek(lexer_t* lexer, int offset);

#endif
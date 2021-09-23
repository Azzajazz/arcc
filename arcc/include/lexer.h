#ifndef ARCC_LEXER_H
#define ARCC_LEXER_H

typedef struct LEXER_STRUCT
{
    char* src;
    int pos;
} lexer_t;

lexer_t* lexer_create(char* src, int pos);

#endif
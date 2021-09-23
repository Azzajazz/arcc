#include "lexer.h"

lexer_t* lexer_create(char* src, int pos)
{
    lexer_t* lexer = malloc(sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->pos = pos;
    return lexer;
}
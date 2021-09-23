#include "lexer.h"
#include "macros.h"

#include <string.h>
#include <stdlib.h>

lexer_t* lexer_create_with_pos(char* src, int pos)
{
    lexer_t* lexer = malloc(sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->pos = pos;
    lexer->src_len = strlen(src);
    return lexer;
}

lexer_t* lexer_create(char* src)
{
    return lexer_create_with_pos(src, 0);
}

void lexer_advance_by(lexer_t* lexer, int offset) {
    lexer->pos = MIN(lexer->pos + offset, lexer->src_len - 1);
}

void lexer_advance(lexer_t* lexer)
{
    lexer_advance_by(lexer, 1);
}

char lexer_peek(lexer_t* lexer, int offset)
{
    int index = MIN(lexer->pos + offset, lexer->src_len - 1);
    return lexer->src[index];
}

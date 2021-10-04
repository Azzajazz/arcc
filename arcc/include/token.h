#ifndef ARCC_TOKEN_H
#define ARCC_TOKEN_H

typedef enum TOKEN_TYPE
{
    //Keyword tokens//
    TOKEN_KW_INT,
    TOKEN_KW_RETURN,
    //Identifier token//
    TOKEN_ID,
    //Literal tokens//
    TOKEN_LIT_INT,
    //Symbol tokens//
    TOKEN_OPEN_PAREN,
    TOKEN_CLOSE_PAREN,
    TOKEN_OPEN_BRACE,
    TOKEN_CLOSE_BRACE,
    TOKEN_SEMICOLON,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_TILDE,
    TOKEN_EXCLAM,
    //EOF token//
    TOKEN_EOF
} token_type_t;

typedef struct TOKEN_STRUCT
{
    token_type_t type;
    void* value;
} token_t;

token_t* token_create(token_type_t type, void* value);

void token_destruct(token_t* token);

void print_token(token_t* token);

#endif
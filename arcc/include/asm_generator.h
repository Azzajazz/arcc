#ifndef ARCC_ASM_GENERATOR_H
#define ARCC_ASM_GENERATOR_H

#include "AST.h"

#include <stdio.h>

typedef struct GENERATOR_STRUCT
{
    FILE* fp;
    node_t* ast;
    node_t* current;
} generator_t;

generator_t* generator_create(const char* outfile, node_t* ast);

void generator_destruct(generator_t* generator);

void generator_emit_program(generator_t* generator);

void generator_emit_funcdef(generator_t* generator);

void generator_emit_statement(generator_t* generator);

void generator_emit_expr(generator_t* generator);

void generator_assert_node_type(node_t* node, node_type_t type, const char* fn);
#endif
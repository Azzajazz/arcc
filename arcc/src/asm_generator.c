#include "asm_generator.h"
#include "utils.h"

generator_t* generator_create(const char* outfile, node_t* ast)
{
    generator_t* generator = malloc(sizeof(*generator));
    FILE* fp = fopen(outfile, "w");
    if (!fp)
        handle_error("Unable to open file!", __func__);
    generator->fp = fp;
    generator->ast = ast;
    generator->current = ast;
    return generator;
}

void generator_destruct(generator_t* generator)
{
    fclose(generator->fp);
    free(generator);
}

void generator_emit_program(generator_t* generator)
{
    generator_assert_node_type(generator->current, NODE_PROGRAM, __func__);

    generator_assert_node_type(generator->current->children[0], NODE_FUNCDEF, __func__);
    generator->current = generator->current->children[0];
    generator_emit_funcdef(generator);
}

void generator_emit_funcdef(generator_t* generator)
{
    generator_assert_node_type(generator->current, NODE_FUNCDEF, __func__);

    generator_assert_node_type(generator->current->children[1], NODE_ID, __func__);
    fprintf(generator->fp, ".globl %s\n", (char*) generator->current->children[1]->value);
    fprintf(generator->fp, "%s:\n", (char*) generator->current->children[1]->value);
    generator->current = generator->current->children[2];
    generator_emit_statement(generator);
}

void generator_emit_statement(generator_t* generator)
{
    generator_assert_node_type(generator->current, NODE_STATEMENT, __func__);

    generator_assert_node_type(generator->current->children[0], NODE_RETURN_KEYWORD, __func__);
    generator->current = generator->current->children[1];
    generator_emit_expr(generator);

    fputs("  ret\n", generator->fp);
}

void generator_emit_expr(generator_t* generator)
{
    generator_assert_node_type(generator->current, NODE_EXPRESSION, __func__);
    
    generator_assert_node_type(generator->current->children[0], NODE_INT_CONSTANT, __func__);
    fprintf(generator->fp, "  movl $%d, %%eax\n", *(int*) generator->current->children[0]->value);
}

void generator_assert_node_type(node_t* node, node_type_t type, const char* fn)
{
    if (node->type != type)
    {
        char msg[33];
        snprintf(msg, 33, "Expected node type %d, got type %d", type, node->type);
        handle_error(msg, fn);
    }
}
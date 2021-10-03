#include "token.h"
#include "parser.h"
#include "asm_generator.h"
#include "utils.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    const char* usage =
        "%s\n [SRCFILE] [OPTIONS]\n"
        "-o OUTFILE: Writes compiled assembly to OUTFILE";
    
    char* outfile = "out.s";
    if (argc < 2)
    {
        printf(usage, argv[0]);
    }
    for (int i = 2; i < argc; i += 2)
    {
        if (argv[i][0] == '-') {
            switch (argv[i][1])
            {
                case 'o':
                    outfile = argv[i + 1];
            }
        }
    }        

    char* src = read_src_file(argv[1]);
    lexer_t* lexer = lexer_create(src);
    parser_t* parser = parser_create(lexer);
    node_t* ast = parser_parse_program(parser);
    generator_t* generator = generator_create(outfile, ast);
    generator_emit_program(generator);
    generator_destruct(generator);
    node_destruct(ast);
    parser_destruct(parser);
    lexer_destruct(lexer);
}
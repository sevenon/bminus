#ifdef LINE_DIRECTIVE
#line 2 "bminus.c"
#endif

#ifndef MERGE_CODE
#include "builtinfuncs_ansic.h"
#include "globals.h"
#include "stringlib.h" 
#include "errormessages.h"
#include "preprocessor.h" 
#include "token.h" 
// #include "target_cvirtualmachine.h" 
// #include "target_javascript.h" 
// #include "target_linuxassemblerx86.h" 
#include "target_linuxelfx86.h" 
#include "compiler.h" 
#include "syntax.h" 
#include <stdio.h>
#endif

main() {
    // setmode(fileno(stdout), 0x8000); // do not add cr after lf on windows

    preprocessor_init();
    token_init();
    compiler_init();
    target_init();

    syntax_program();

    exit(0);
}

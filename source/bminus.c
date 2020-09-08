#ifndef _MSC_VER
#line 2 "bminus.c"
#endif

#ifdef _MSC_VER
#include "builtinfuncs_ansic.h"
#include "globals.h"
#include "stringlib.h" 
#include "errormessages.h"
#include "preprocessor.h" 
#include "token.h" 
// #include "target_cvirtualmachine.h" 
#include "target_javascript.h" 
// #include "target_linuxassemblerx86.h" 
#include "compiler.h" 
#include "syntax.h" 
#endif


main() {
    preprocessor_init();
    token_init();
    compiler_init();
    target_init();

    syntax_program();

    exit(0);

}


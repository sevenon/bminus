#ifdef LINE_DIRECTIVE
#line 2 "syntax.h"
#endif

// BMINUS Syntax 
//
// program
//            global-declaration-list
//
// global-declaration
//            declaration
//            function-definition
//
// global-declaration-list
//            global-declaration global-declaration-list
//            global-declaration
//
// function-definition
//            identifier( function-argument-declaration-list ) function-compound-statement
//            identifier( ) function-compound-statement
//
// function-compound-statement
//            { local-declaration-list statement-list } 
//            { statement-list } 
//
// declaration
//            type-specifier identifier ;
//            type-specifier identifier [ integer-constant ] ;
//            type-specifier identifier [ identifier ] ;
//            enum { enumerator-list } ;
//
// local-declaration-list
//            declaration local-declaration-list
//            declaration
//
// enumerator
//            identifier = integer-constant
//            identifier
//
// enumerator-list
//            enumerator , enumerator-list
//            enumerator
//            
// function-argument-declaration-list
//            function-argument-declaration , function-argument-declaration-list
//            function-argument-declaration
//
// function-argument-declaration
//            type-specifier identifier
//            type-specifier identifier []
//
// type-specifier
//            int
//            char
//
// statement
//           if-statement
//           while-statement
//           compound-statement
//           assignment-statement ;
//           expression-statement ;
//           return-statement ;
//
// statement-list
//            statement statement-list
//            statement
//            
// if-statement
//            if ( expression ) statement else statement
//            if ( expression ) statement
//
// while-statement
//            while ( expression ) statement
//
// assignment-statement
//            identifier = expression
//            identifier [ expression ] = expression
//            
// expression-statement
//           expression
//
// return-statement
//            return expression
//            return
//
// compound-statement
//            { statement-list } 
//
// expression
//            logical-or-expression
//
// logical-or-expression
//            logical-and-expression logical-or-switch-sequence
//            logical-and-expression
//
// logical-or-switch-sequence
//            || logical-and-expression logical-or-switch-sequence
//            || logical-and-expression
//
// logical-and-expression
//            equality-expression logical-and-switch-sequence
//            equality-expression
//
// logical-and-switch-sequence
//            && equality-expression logical-and-switch-sequence
//            && equality-expression
//
// equality-expression
//            relational-expression equality-expression-sequence
//            relational-expression
//
// equality-expression-sequence
//            equality-operator-operator relational-expression equality-expression-sequence
//            equality-operator-operator relational-expression
//
// equality-operator
//            one-of == !=
//
// relational-expression
//            additive-expression relational-expression-sequence
//            additive-expression
//
// relational-expression-sequence
//            relational-operator additive-expression relational-expression-sequence
//            relational-operator additive-expression
//
// relational-operator
//           one-of < <= > >=
//
// additive-expression
//            multiplicative-expression additive-expression-sequence
//            multiplicative-expression
//
// additive-expression-sequence
//           additive-operator multiplicative-expression additive-expression-sequence
//           additive-operator multiplicative-expression
//
// additive-operator
//           one-of  + - 
//            
// multiplicative-expression
//            unary-expression multiplicative-expression-sequence
//            unary-expression
//
// multiplicative-expression-sequence
//            multiplicative-operator unary-expression multiplicative-expression-sequence
//            multiplicative-operator unary-expression
//
// multiplicative-operator
//           one-of  * / 
//
// unary-expression
//            unary-operator unary-expression
//            primary-expression
//            
// unary-operator
//            one of  ! + - 
//
// primary-expression
//            built-in-function
//            identifier ( function-call-argument-list )
//            identifier [ expression ]
//            identifier
//            integer-constant
//            character-constant
//            ( expression )
//
// function-call-argument-list
//            function-call-argument , function-call-argument-list
//            function-call-argument
//
// function-call-argument
//            string-literal
//            pointer-identifier
//            expression
//
// built-in-function
//           fgetc ( stdin )
//           fputc ( expression , stdout)
//           fputc ( expression , stderr)
//           exit  ( expression )
//           debug ( expression )


// ---------------------------------------------------------------------------
// built-in-function
//           fgetc ( stdin )
//           fputc ( expression , stdout)
//           fputc ( expression , stderr)
//           exit  ( expression )
//           debug ( expression )
//
syntax_built_in_function() {

    // ----- fgetc  ( stdin )
    //
    if (token_advance_if("fgetc")) {
        if (! (token_advance_if("(") && token_advance_if("stdin") && token_advance_if(")"))) {
            error_syntax("fgetc(stdin) expected");
        }

        compiler_built_in_function_fgetc();
        return True;
    }

    // ----- fputc ( expression , stdout)
    // ----- fputc ( expression , stderr)
    //
    if (token_advance_if("fputc")) {

        if (! token_advance_if("(")) {
            error_syntax("opening parenthesis expected after fputc");
        }

        if (! syntax_expression()) {
            error_syntax("expression expected after fputc opening parenthesis");
        }

        if (! token_advance_if(",")) {
            error_syntax("fputc takes two arguments");
        }

        if (token_advance_if("stdout")) {
            compiler_built_in_function_fputc_stdout();
        }
        else if (token_advance_if("stderr")) {
            compiler_built_in_function_fputc_stderr();
        }
        else {
            error_syntax("second argument of fputc must be stdout or stderr");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected");
        }   
            
        return True;
    }

    // ----- exit ( expression )
    //
    if (token_advance_if("exit")) {

        if (! token_advance_if("(")) {
            error_syntax("opening parenthesis expected after exit");
        }

        if (! syntax_expression()) {
            error_syntax("expression expected after exit opening parenthesis");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected");
        }

        compiler_built_in_function_exit();
        return True;
    }

    // ----- debug ( expression )
    //
    if (token_advance_if("debug")) {

        if (! token_advance_if("(")) {
            error_syntax("opening parenthesis expected after debug");
        }

        if (! syntax_expression()) {
            error_syntax("expression expected after debug opening parenthesis");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected");
        }

        compiler_built_in_function_debug();
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// function-call-argument
//            string-literal
//            pointer-identifier
//            expression
//
syntax_function_call_argument() {

    if (token_type_is(Token_t_string_literal)) {
        compiler_function_call_string_literal_argument(token_text); // >>>>>>>>>>
        token_advance();
        return True;
    }
    
    // need to check symbol table to determine if identifier needs to be passed as a pointer
    if (token_type_is(Token_t_identifier) && (! token_lookahead_text_is("["))) {
        if (compiler_function_call_pointer_argument(token_text)) { // >>>>>>>>>>
            token_advance();
            return True;
        }
    }

    if (syntax_expression()) {
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// function-call-argument-list
//            function-call-argument , function-call-argument-list
//            function-call-argument
//
syntax_function_call_argument_list(int argument_no, int function_argument_count[]) {
    int cookie[1];

    if (! syntax_function_call_argument()) {
        return False;
    }

    function_argument_count[0] = function_argument_count[0] + 1;

    compiler_function_call_argument_prepare(cookie); // >>>>>>>>>>

    if (token_advance_if(",")) {
        syntax_function_call_argument_list(argument_no + 1, function_argument_count);
    }

    compiler_function_call_argument_pass(argument_no + 1, function_argument_count[0], cookie); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// primary-expression
//            built-in-function
//            identifier ( function-call-argument-list )
//            identifier [ expression ]
//            identifier
//            integer-constant
//            character-constant
//            ( expression )
//
syntax_primary_expression() {
    char cookie[Str_size];
    char name[Str_size];
    int function_argument_count[1];

    // ------ built-in-function

    if (syntax_built_in_function()) {
        return True;
    }

    // ------ identifier ( function-call-argument-list )

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) {
        copy(name, token_text);
        token_advance();
        token_advance();

        compiler_function_call_prepare(name, cookie); // >>>>>>>>>>

        function_argument_count[0] = 0;
        syntax_function_call_argument_list(0, function_argument_count);

        compiler_function_call_execute(cookie, function_argument_count[0]); // >>>>>>>>>>
                
        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected after function call expression");
        }

        return True;
    }

    // ------ identifier [ expression ]

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("[")) {
        copy(name, token_text);
        token_advance();
        token_advance();

        if (! syntax_expression()) {
            error_syntax("expression expected after opening bracket");
        }

        if (! token_advance_if("]")) {
            error_syntax("closing bracket expected");
        }

        compiler_primary_expression_array_index(); // >>>>>>>>>>
        compiler_primary_expression_identifier(name); // >>>>>>>>>>
        return True;
    }

    // ------ identifier

    if (token_type_is(Token_t_identifier)) {
        compiler_primary_expression_identifier(token_text); // >>>>>>>>>>
        token_advance();
        return True;
    }

    // ------ integer-constant

    if (token_type_is(Token_t_integer_constant)) {
        compiler_primary_expression_integer_constant(token_text); // >>>>>>>>>>       
        token_advance();
        return True;
    }

    // ----- character-constant

    if (token_type_is(Token_t_character_constant)) {
        compiler_primary_expression_character_constant(token_text[0]); // >>>>>>>>>>        
        token_advance();
        return True;
    }

    // ------ ( expression )

    if (token_advance_if("(")) {
        if (! syntax_expression()) {
            error_syntax("expression expected after opening parenthesis");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected after expression");
        }

        return True;
    }

    return False;
}



// ---------------------------------------------------------------------------
// unary-operator
//            one of  ! + - 
//
syntax_unary_operator(char s[]) {
 
    return contains(" ! + - ", s);
}

// ---------------------------------------------------------------------------
// unary-expression
//            unary-operator unary-expression
//            primary-expression
//            
syntax_unary_expression() {
    char operator_text[Str_size];

    if (token_type_is(Token_t_symbol) && syntax_unary_operator(token_text)) {
        copy(operator_text, token_text);
        token_advance();

        if (! syntax_unary_expression()) {
            error_syntax("expression expected after unary operator");
        }
                  
        compiler_unary_expression(operator_text); // >>>>>>>>>>
        return True;
    }

    return syntax_primary_expression();
}

// ---------------------------------------------------------------------------
// multiplicative-operator
//           one-of  * / 
//
syntax_multiplicative_operator(char s[]) {
 
    return contains(" * / ", s);
}

// ---------------------------------------------------------------------------
// multiplicative-expression-sequence
//            multiplicative-operator unary-expression multiplicative-expression-sequence
//            multiplicative-operator unary-expression
//
syntax_multiplicative_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_multiplicative_operator(token_text))) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_multiplicative_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_unary_expression()) {
        error_syntax("expression expected after unary operator");
    }

    compiler_multiplicative_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_multiplicative_expression_sequence();

    return True;
}


// ---------------------------------------------------------------------------
// multiplicative-expression
//            unary-expression multiplicative-expression-sequence
//            unary-expression
//
syntax_multiplicative_expression() {

    if (! syntax_unary_expression()) {
        return False;
    }

    syntax_multiplicative_expression_sequence();
    
    return True;
}

// ---------------------------------------------------------------------------
// additive-operator
//           one-of  + - 
//            
syntax_additive_operator(char s[]) {

    return contains(" + - ", s);
}

// ---------------------------------------------------------------------------
// additive-expression-sequence
//           additive-operator multiplicative-expression additive-expression-sequence
//           additive-operator multiplicative-expression
//
syntax_additive_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_additive_operator(token_text)) ) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_additive_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_multiplicative_expression()) {
        error_syntax("expression expected right of additive operator");
    }

    compiler_additive_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_additive_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// additive-expression
//            multiplicative-expression additive-expression-sequence
//            multiplicative-expression
//
syntax_additive_expression() {

    if (! syntax_multiplicative_expression()) {
        return False;
    }

    syntax_additive_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// relational-operator
//           one-of < <= > >=
//
syntax_relational_operator(char s[]) {

    return contains(" < <= > >= ", s);
}

// ---------------------------------------------------------------------------
// relational-expression-sequence
//            relational-operator additive-expression relational-expression-sequence
//            relational-operator additive-expression
//
syntax_relational_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_relational_operator(token_text)) ) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_relational_or_equality_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_additive_expression()) {
        error_syntax("expression expected right of relational operator");
    }

    compiler_relational_or_equality_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_relational_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// relational-expression
//            additive-expression relational-expression-sequence
//            additive-expression
//
syntax_relational_expression() {
 
    if (! syntax_additive_expression()) {
        return False;
    }

    syntax_relational_expression_sequence();

    return True;
}


// ---------------------------------------------------------------------------
// equality-operator
//            one-of == !=
//
syntax_equality_operator(char s[]) {

    return contains(" == != ", s);
}

// ---------------------------------------------------------------------------
// equality-expression-sequence
//            equality-operator-operator relational-expression equality-expression-sequence
//            equality-operator-operator relational-expression
//
syntax_equality_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_equality_operator(token_text)) ) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_relational_or_equality_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_relational_expression()) {
        error_syntax("expression expected right of equality operator");
    }

    compiler_relational_or_equality_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_equality_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// equality-expression
//            relational-expression equality-expression-sequence
//            relational-expression
//
syntax_equality_expression() {

    if (! syntax_relational_expression() ) {
        return False;
    }

    syntax_equality_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// logical-and-switch-sequence
//            && equality-expression logical-and-switch-sequence
//            && equality-expression
//
//
syntax_logical_and_switch_sequence(char cookie[]) {

    if (! token_advance_if("&&")) {
        return False;
    }

    if (! syntax_equality_expression()) {
        error_syntax("expression expected right of logical and");
    }

    compiler_logical_and_switch_sequence(cookie); // >>>>>>>>>>

    syntax_logical_and_switch_sequence(cookie);

    return True;
}

// ---------------------------------------------------------------------------
// logical-and-expression
//            equality-expression logical-and-switch-sequence
//            equality-expression
//
syntax_logical_and_expression() {
    char cookie[Str_size];

    if (! syntax_equality_expression() ) {
        return False;
    }
    
    if (token_text_is("&&")) {
        compiler_logical_and_expression_begin(cookie); // >>>>>>>>>>

        syntax_logical_and_switch_sequence(cookie);

        compiler_logical_and_expression_end(cookie); // >>>>>>>>>>
    }

    return True;
}


// ---------------------------------------------------------------------------
// logical-or-switch-sequence
//            || logical-and-expression logical-or-switch-sequence
//            || logical-and-expression
//
syntax_logical_or_switch_sequence(char cookie[]) {

    if (! token_advance_if("||")) {
        return False;
    }

    if (! syntax_logical_and_expression()) {
        error_syntax("expression expected right of logical-or operator");
    }

    compiler_logical_or_switch_sequence(cookie); // >>>>>>>>>>

    syntax_logical_or_switch_sequence(cookie);

    return True;
}

// ---------------------------------------------------------------------------
// logical-or-expression
//            logical-and-expression logical-or-switch-sequence
//            logical-and-expression
//
syntax_logical_or_expression() {
    char cookie[Str_size];
 
    if (! syntax_logical_and_expression()) {
        return False;
    }
    
    if (token_text_is("||")) {
        compiler_logical_or_expression_begin(cookie); // >>>>>>>>>>

        syntax_logical_or_switch_sequence(cookie);

        compiler_logical_or_expression_end(cookie); // >>>>>>>>>>
    }

    return True;
}

// ---------------------------------------------------------------------------
// expression
//            logical-or-expression
//
syntax_expression() {

    return syntax_logical_or_expression();
}


// ---------------------------------------------------------------------------
// function-call-statement
//            built-in-function
//            identifier ( function-call-argument-list )
//
syntax_function_call_statement() {
    char cookie[Str_size];
    char function_name[Str_size];
    int function_argument_count[1];

    if (syntax_built_in_function()) {
        return True;
    }

    if (! (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) ) {
        return False;
    }

    copy(function_name, token_text);

    token_advance();
    token_advance();

    compiler_function_call_prepare(function_name, cookie); // >>>>>>>>>>

    syntax_function_call_argument_list(0, function_argument_count);

    compiler_function_call_execute(cookie, function_argument_count[0]); // >>>>>>>>>>
                
    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after function call");
    }

    return True;
}

// ---------------------------------------------------------------------------
// return-statement
//            return expression
//            return
//
syntax_return_statement() {
 
    if (! token_advance_if("return")) {
        return False;
    }

    syntax_expression();

    compiler_return_statement(); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// expression-statement
//           expression
//
syntax_expression_statement() {

    return syntax_expression();
}

// ---------------------------------------------------------------------------
// assignment-statement
//            identifier = expression
//            identifier [ expression ] = expression
//            
syntax_assignment_statement() {
    int cookie[1];
    char variable_name[Str_size];

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("=")) {
        copy(variable_name, token_text);
        token_advance();
        token_advance();
   
        if (! syntax_expression()) {
            error_syntax("expression expected after equal sign");
        }

        compiler_assignment_statement(variable_name); // >>>>>>>>>>

        return True;
    }

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("[")) {
        copy(variable_name, token_text);
        token_advance();
        token_advance();

        if (! syntax_expression()) {
            error_syntax("expression expected within array index");
        }

        if (! token_advance_if("]")) {
            error_syntax("closing bracket expected after array index");
        }
            
        if (! token_advance_if("=")) {
            error_syntax("equal sign expected after array index");
        }

        compiler_assignment_statement_array_begin(cookie); // >>>>>>>>>>
   
        if (! syntax_expression()) {
            error_syntax("expression expected after equal sign");
        }

        compiler_assignment_statement_array_end(cookie); // >>>>>>>>>>
        compiler_assignment_statement(variable_name); // >>>>>>>>>>

        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// while-statement
//            while ( expression ) statement
//
syntax_while_statement() {
    char cookie[Str_size];

    if (! token_advance_if("while") ) {
        return False;
    }

    if (! token_advance_if("(") ) {
        error_syntax("opening parenthesis expected after while keyword");
    }

    compiler_while_statement_begin(cookie); // >>>>>>>>>>

    if (! syntax_expression()) {
        error_syntax("expression expected in while statement");
    }

    compiler_while_statement_test(cookie); // >>>>>>>>>>

    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after while statement");
    }

    if (! syntax_statement() ) {
        error_syntax("statement expected after while");
    }

    compiler_while_statement_end(cookie); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// if-statement
//            if ( expression ) statement else statement
//            if ( expression ) statement
//
syntax_if_statement() {
    char cookie[Str_size];

    if (! token_advance_if("if") ) {
        return False;
    }

    if (! token_advance_if("(") ) {
        error_syntax("opening parenthesis expected after if keyword");
    }

    if (! syntax_expression()) {
        error_syntax("expression expected in if statement");
    }

    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after if statement");
    }

    compiler_if_statement_test_fn(cookie); // >>>>>>>>>>

    if (! syntax_statement() ) {
        error_syntax("statement expected after if");
    }

    if (! token_advance_if("else") ) {
         compiler_if_statement_no_else_fn(cookie); // >>>>>>>>>>
         return True;
    }

    compiler_if_statement_else_fn(cookie); // >>>>>>>>>>

    if (! syntax_statement() ) {
        error_syntax("statement expected after else");
    }

    compiler_if_statement_else_end_fn(cookie); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// enumerator
//            identifier = integer-constant
//            identifier
//
syntax_enumerator() {
    char constant_name[Str_size];

    if (! token_type_is(Token_t_identifier) ) {
        return False;
    }
    
    copy(constant_name, token_text);
    token_advance();

    if (token_text_is("=")) {
        token_advance();

        if (! token_type_is(Token_t_integer_constant) ) {
            error_syntax("integer constant expected after equal sign in enum declaration");
        }

        compiler_enumerator_assigned_value(constant_name, token_text); // >>>>>>>>>>
        token_advance();
        return True;
    }

    compiler_enumerator(constant_name); // >>>>>>>>>>
    return True;
}



// ---------------------------------------------------------------------------
// enumerator-list
//            enumerator , enumerator-list
//            enumerator
//            
syntax_enumerator_list() {
    if (! syntax_enumerator() ) {
        return False;
    }

    if (token_advance_if(",")) {

        if (! syntax_enumerator_list() ) {
            error_syntax("identifier expected after comma in enum declaration");
        }
    }

    compiler_enumerator_list_end(); // >>>>>>>>>>

    return True;
}


// ---------------------------------------------------------------------------
// type-specifier
//            int
//            char
//
syntax_type_specifier() {

    if (token_text_is("int") || token_text_is("char")) {
        token_advance();
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// declaration
//            type-specifier identifier ;
//            type-specifier identifier [ integer-constant ] ;
//            type-specifier identifier [ identifier ] ;
//            enum { enumerator-list } ;
//
syntax_declaration() {
    char variable_name[Str_size];
    char array_length[Str_size];

    if (syntax_type_specifier()) {
    
        if (! token_type_is(Token_t_identifier)) {
            error_syntax("identifier expected after type specifier in declaration");
        }

        copy(variable_name, token_text);
        token_advance();

        // simple type declaration -------------------------------------------
        if (! token_text_is("[")) {
            compiler_declaration_integer(variable_name); // >>>>>>>>>>

            if (! token_advance_if(";") ) {
                error_syntax("semicolon expected after declaration");
            }

            return True;
        }

        // array type declaration -------------------------------------------
        copy(array_length, token_lookahead_text);

        if (token_lookahead_type_is(Token_t_integer_constant)) {
            compiler_declaration_integer_array_constant_length_specifier(variable_name, array_length); // >>>>>>>>>>
        }
        else if (token_lookahead_type_is(Token_t_identifier)) {
            compiler_declaration_integer_array_identifier_length_specifier(variable_name, array_length); // >>>>>>>>>>
        }
        else {
            error_syntax("identifier or integer constant expected after opening bracket in array declaration");
        }

        token_advance();
        token_advance();

        if (! token_advance_if("]") ) {
            error_syntax("closing bracket expected in array declaration");
        }

        if (!token_advance_if(";")) {
            error_syntax("semicolon expected after array declaration");
        }

        return True;

    }

    // enum declaration ------------------------------------------------------
    if (token_advance_if("enum")) {

        if (! token_advance_if("{")) {
            error_syntax("opening brace expected after enum keyword");
        }

        if (! syntax_enumerator_list() ) {
            error_syntax("enumerator list expected");
        }

        if (! token_advance_if("}")) {
            error_syntax("closing brace expected after enumerator list");
        }

        if (! token_advance_if(";")) {
            error_syntax("semicolon expected after enumerator declaration"); // ????
        }

        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// local-declaration-list
//            declaration local-declaration-list
//            declaration
//
syntax_local_declaration_list() {
    if (! syntax_declaration() ) {
        return False;
    }

    syntax_local_declaration_list();

    return True;
}

// ---------------------------------------------------------------------------
// compound-statement
//            { statement-list } 
//
syntax_compound_statement() {

    if (! token_advance_if("{") ) {
        return False;
    }

    syntax_statement_list();

    if (! token_advance_if("}") ) {
        error_syntax("closing brace expected at end of compound statement");
    }

    return True;
}

// ---------------------------------------------------------------------------
// statement
//           if-statement
//           while-statement
//           compound-statement
//           assignment-statement ;
//           expression-statement ;
//           return-statement ;
//
syntax_statement() {

    compiler_output_source_as_comment(); // >>>>>>>>>>

    if (syntax_if_statement() || 
        syntax_while_statement() ||
        syntax_compound_statement() ) {

        return True;
    }

    if (syntax_assignment_statement() ||
        syntax_expression_statement() ||
        syntax_return_statement() ) {

        if (! token_advance_if(";") ) {
            error_syntax("semicolon expected after statement");
        }

        return True;
    }

    return False;
}


// ---------------------------------------------------------------------------
// statement-list
//            statement statement-list
//            statement
//            
syntax_statement_list() {

    if (! syntax_statement() ) {
        return False;
    }

    syntax_statement_list();
    return True;
}

// ---------------------------------------------------------------------------
// function-argument-declaration
//            type-specifier identifier
//            type-specifier identifier []
//
syntax_function_argument_declaration(int argument_no) {
    int argument_type;
    char argument_name[Str_size];

    if (! syntax_type_specifier() ) {
        return False;
    }

    if (! token_type_is(Token_t_identifier) ) {
        error_syntax("identifier expected after type specifier in function definition");
    }

    copy(argument_name, token_text);
    token_advance();

    if (token_advance_if("[")) {
        argument_type = Compiler_t_integer_pointer;

        if (! token_advance_if("]") ) {
            error_syntax("closing bracket expected after array argument declaration");
        }
    } else {
        argument_type = Compiler_t_integer;
    }

    compiler_function_argument_declaration_item(argument_name, argument_type, argument_no + 1); // >>>>>>>>>>
    return True;
}

// ---------------------------------------------------------------------------
// function-argument-declaration-list
//            function-argument-declaration , function-argument-declaration-list
//            function-argument-declaration
//
syntax_function_argument_declaration_list(int argument_no) {

    if (! syntax_function_argument_declaration(argument_no) ) {
        return False;
    }

    if (! token_advance_if(",") ) {
        return True;
    }

    if (! syntax_function_argument_declaration_list(argument_no + 1) ) {
        error_syntax("function argument expected");
    }

    return True;
}

// ---------------------------------------------------------------------------
// function-compound-statement
//            { local-declaration-list statement-list } 
//            { statement-list } 
//
syntax_function_compound_statement() {
    
    if (! token_advance_if("{") ) {
        return False;
    }

    syntax_local_declaration_list();

    compiler_function_compound_statement_locals_declared(); // >>>>>>>>>>

    syntax_statement_list();

    if (! token_advance_if("}") ) {
        error_syntax("closing brace expected at end of function");
    }

    return True;
}

// ---------------------------------------------------------------------------
// function-definition
//            identifier( function-argument-declaration-list ) function-compound-statement
//            identifier( ) function-compound-statement
//
syntax_function_definition() {
    char function_name[Str_size];

    if (! (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) ) {
        return False;
    }

    copy(function_name, token_text);
    token_advance();
    token_advance();

    compiler_output_source_as_comment(); // >>>>>>>>>>

    compiler_function_definition_begin(function_name); // >>>>>>>>>>

    syntax_function_argument_declaration_list(0);

    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after function definintion");
    }

    if (! syntax_function_compound_statement() ) {
        error_syntax("function body expected after function definintion");
    }

    compiler_function_definition_end(); // >>>>>>>>>>

    return True;
}


// ---------------------------------------------------------------------------
// global-declaration
//            declaration
//            function-definition
//
syntax_global_declaration() {

    if (syntax_declaration()) {
        return True;
    }

    if (syntax_function_definition()) {
        return True;
    }

    return False;
}
// ---------------------------------------------------------------------------
// global-declaration-list
//            global-declaration global-declaration-list
//            global-declaration
//
syntax_global_declaration_list() {

    if (! syntax_global_declaration()) {
        return False;
    }

    syntax_global_declaration_list();
    return True;
}

// ---------------------------------------------------------------------------
// program
//            global-declaration-list
//
syntax_program() {
    token_advance();

    compiler_program_begin(); // >>>>>>>>>>

    if (! syntax_global_declaration_list()) {
        error_syntax("function or variable declaration expected");
    }

    if (! token_type_is(Token_t_eof)) {
        error_syntax("end of file expected");
    }

    compiler_output_source_as_comment();
    compiler_program_end(); // >>>>>>>>>>

    return True;
}


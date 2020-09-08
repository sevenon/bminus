var stdin_str = "";
var stdout_str = "";
var stderr_str = "";
var stdin_pos = 0;
var exit_code = 0;

function compile() {
    stdout_str = "";
    stderr_str = "";
    stdin_pos = 0;
    exit_code = 0;

    try {
        init_memory();
        main();
    } catch(e) {
    }
}

function readCharCodeFromStdin() {
    if (stdin_pos < stdin_str.length)
        return (stdin_str.charAt(stdin_pos++)).charCodeAt(0);
    else
        return -1;
}
    
function printCharCodeToStdout(c) {
    stdout_str += String.fromCharCode(c);
}
    
function printCharCodeToStderr(c) {
    stderr_str += String.fromCharCode(c);
}
         
function abortProgram(n) {
    exit_code = n;
    throw false;
}
    
function printIntegerNumber (n) {
    stdout_str += Number(n).toFixed().toString() + "\n";
}
    

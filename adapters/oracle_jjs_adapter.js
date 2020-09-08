
function readCharCodeFromStdin()    { return java.lang.System.in.read(); }
function printCharCodeToStdout(c)   { return java.lang.System.out.print(String.fromCharCode(c)); }
function printCharCodeToStderr(c)   { return java.lang.System.err.print(String.fromCharCode(c)); }
function abortProgram(n)            { java.lang.System.exit(n); }
function printIntegerNumber (n)     { return java.lang.System.out.println(Number(n).toFixed()); }

function run_script() {
	init_memory();
	main();
}

run_script();


function readCharCodeFromStdin()    { return WScript.StdIn.Read(1).charCodeAt(0); }
function printCharCodeToStdout(c)   { WScript.StdOut.Write(String.fromCharCode(c)); }
function printCharCodeToStderr(c)   { WScript.StdErr.Write(String.fromCharCode(c)); }
function abortProgram(n)            { WScript.Quit(n); }
function printIntegerNumber(n)      { WScript.StdOut.WriteLine((Number(n).toFixed())); }

function run_script() {
	init_memory();
	main();
}

run_script();

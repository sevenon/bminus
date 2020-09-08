
var stdinFs = require('fs');
var stdinBuf = new Buffer(1);

function readCharCodeFromStdin()    { n = stdinFs.readSync(process.stdin.fd, stdinBuf, 0, 1) ; if (n) return stdinBuf.readUInt8(); return -1; }
function printCharCodeToStdout(c)   { return process.stdout.write(String.fromCharCode(c)); }
function printCharCodeToStderr(c)   { return process.stderr.write(String.fromCharCode(c)); }
function abortProgram(n)            { process.exit(n); }
function printIntegerNumber (n)     { return process.stdout.write(Number(n).toFixed() +"\n"); }

function run_script() {
	init_memory();
	main();
}

run_script();

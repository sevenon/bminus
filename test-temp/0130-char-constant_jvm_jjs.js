
var A;
var X;
var BP;
var RAM = [];

function loadi       (n) { A = n; }

function load        (n) { A = RAM[n]; }
function store       (n) { RAM[n] = A; }

function add         (n) { A += RAM[n]; }
function subtract    (n) { A -= RAM[n]; }
function multiply    (n) { A *= RAM[n]; }
function divide      (n) { A = (A / RAM[n]) | 0; }

function loadx       ()  { X = A; }
function movebp      (n) { BP += n; }

function less        ()  { return A > 0; }
function greater     ()  { return A < 0; }
function equals      ()  { return A == 0; }
function notequals   ()  { return A != 0; }
function always      ()  { return true; }

var global;

                                                            // main() {
function main
(){
                                             main_end: {
                                                            // 	char c;
                                                            // 
                                                            // 	c = 'a';
                        loadi             (97);
                        store             (0+BP);
                                                            // 	debug (c);
                        load              (0+BP);
                        printIntegerNumber (A);
                                                            // 
                                                            // 	c = '\n';
                        loadi             (10);
                        store             (0+BP);
                                                            // 	debug (c);
                        load              (0+BP);
                        printIntegerNumber (A);
                                                            // }
} // main_end:
return;	}


function init_memory() {
global = 1048576;

BP = 0;

RAM = [
];

for (i = 0; i < 1048576; i ++) {
RAM[i] = 0;
}
}

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

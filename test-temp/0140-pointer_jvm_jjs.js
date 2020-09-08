
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

                                                            // int arr[10];
                                                            // 
                                                            // f(int arr[]) {
function f
(){
                                             f_end: {
                                                            // 	debug(arr[5]);
                        loadi             (5);
                        loadx             ();
                        loadi             (X);
                        store             (1+BP);
                        load              (0+BP);
                        add               (1+BP);
                        loadx             ();
                        load              (X);
                        printIntegerNumber (A);
                                                            // 	arr[8] = 88;
                        loadi             (8);
                        store             (1+BP);
                        loadi             (88);
                        store             (2+BP);
                        load              (1+BP);
                        loadx             ();
                        load              (2+BP);
                        store             (1+BP);
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (X);
                                                            // }
                                                            // 
                                                            // fn(int arg[]) {
} // f_end:
return;	}
function fn
(){
                                             fn_end: {
                                                            // 	arg[1] = 20;
                        loadi             (1);
                        store             (1+BP);
                        loadi             (20);
                        store             (2+BP);
                        load              (1+BP);
                        loadx             ();
                        load              (2+BP);
                        store             (1+BP);
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (X);
                                                            // 	arg[5] = 99;
                        loadi             (5);
                        store             (1+BP);
                        loadi             (99);
                        store             (2+BP);
                        load              (1+BP);
                        loadx             ();
                        load              (2+BP);
                        store             (1+BP);
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (X);
                                                            // 	debug(arg[1]);
                        loadi             (1);
                        loadx             ();
                        loadi             (X);
                        store             (1+BP);
                        load              (0+BP);
                        add               (1+BP);
                        loadx             ();
                        load              (X);
                        printIntegerNumber (A);
                                                            // 	debug(arg[5]);
                        loadi             (5);
                        loadx             ();
                        loadi             (X);
                        store             (1+BP);
                        load              (0+BP);
                        add               (1+BP);
                        loadx             ();
                        load              (X);
                        printIntegerNumber (A);
                                                            // 	f(arg);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        f();              
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // main() {
} // fn_end:
return;	}
function main
(){
                                             main_end: {
                                                            // 
                                                            // 	arr[0] = 10;
                        loadi             (0);
                        store             (0+BP);
                        loadi             (10);
                        store             (1+BP);
                        load              (0+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (-10+global+X);
                                                            // 
                                                            // 	fn(arr);
                        loadi             (-10+global);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        fn();             
                        movebp            (-9);
                                                            // 
                                                            // 	debug(arr[0]);
                        loadi             (0);
                        loadx             ();
                        load              (-10+global+X);
                        printIntegerNumber (A);
                                                            // 	debug(arr[1]);
                        loadi             (1);
                        loadx             ();
                        load              (-10+global+X);
                        printIntegerNumber (A);
                                                            // 	debug(arr[8]);
                        loadi             (8);
                        loadx             ();
                        load              (-10+global+X);
                        printIntegerNumber (A);
                                                            // }
} // main_end:
return;	}


function init_memory() {
global = 1048586;

BP = 0;

RAM = [
];

for (i = 0; i < 1048586; i ++) {
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

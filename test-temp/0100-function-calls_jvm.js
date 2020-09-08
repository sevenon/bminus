
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

                                                            // int global1;
                                                            // 
                                                            // f1(int arg1, int arg2, int arg3) {
function f1
(){
                                             f1_end: {
                                                            // 	debug(arg1);
                        load              (0+BP);
                        printIntegerNumber (A);
                                                            // 	debug(arg2);
                        load              (1+BP);
                        printIntegerNumber (A);
                                                            // 	debug(arg3);
                        load              (2+BP);
                        printIntegerNumber (A);
                                                            // }
                                                            // 
                                                            // int global2;
} // f1_end:
return;	}
                                                            // 
                                                            // f2(int arg2, int arg3) {
function f2
(){
                                             f2_end: {
                                                            // 	return arg2 * arg3;
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        multiply          (2+BP);
                        if(always())      break f2_end;
                                                            // }
                                                            // 
                                                            // int global3;
} // f2_end:
return;	}
                                                            // 
                                                            // main() {
function main
(){
                                             main_end: {
                                                            // 	int local1;
                                                            // 
                                                            // 	f1(10, f2(10,50), 30);
                        loadi             (10);
                        store             (1+BP);
                        loadi             (10);
                        store             (2+BP);
                        loadi             (50);
                        store             (3+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        f2();             
                        movebp            (-11);
                        store             (2+BP);
                        loadi             (30);
                        store             (3+BP);
                        load              (3+BP);
                        store             (14+BP);
                        load              (2+BP);
                        store             (13+BP);
                        load              (1+BP);
                        store             (12+BP);
                        movebp            (12);
                        f1();             
                        movebp            (-12);
                                                            // 
                                                            // 	local1 = 10;
                        loadi             (10);
                        store             (0+BP);
                                                            // 	global1 = 1;
                        loadi             (1);
                        store             (-1+global);
                                                            // 	global2 = 2;
                        loadi             (2);
                        store             (-2+global);
                                                            // 	global3 = 3;
                        loadi             (3);
                        store             (-3+global);
                                                            // 
                                                            // 	debug(local1);
                        load              (0+BP);
                        printIntegerNumber (A);
                                                            // 	debug(global1);
                        load              (-1+global);
                        printIntegerNumber (A);
                                                            // 	debug(global2);
                        load              (-2+global);
                        printIntegerNumber (A);
                                                            // 	debug(global3);
                        load              (-3+global);
                        printIntegerNumber (A);
                                                            // }
} // main_end:
return;	}


function init_memory() {
global = 1048579;

BP = 0;

RAM = [
];

for (i = 0; i < 1048579; i ++) {
RAM[i] = 0;
}
}

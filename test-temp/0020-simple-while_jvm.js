
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
                                                            // 	int i;
                                                            // 	i = 20;
                        loadi             (20);
                        store             (0+BP);
                                                            // 
                                                            // 	while (i - 10 >= 0) {
                                             while_0_end: {
while_0_test: while(true) {
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (10);
                        store             (2+BP);
                        load              (1+BP);
                        subtract          (2+BP);
                        store             (1+BP);
                        loadi             (0);
                        subtract          (1+BP);
                                             compare_1_false: {
                                             compare_1_true: {
                        if(greater())     break compare_1_true;
                        if(equals())      break compare_1_true;
                        loadi             (0);
                        if(always())      break compare_1_false;
} // compare_1_true:
                        loadi             (1);
} // compare_1_false:
                        if(equals())      break while_0_end;
                                                            //     	debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                                                            // 		i = i-1;
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        store             (2+BP);
                        load              (1+BP);
                        subtract          (2+BP);
                        store             (0+BP);
                                                            // 	}
                                                            // 
                                                            // }
                        if(always())      continue while_0_test;
                                             break; } // while_0_test:
} // while_0_end:
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

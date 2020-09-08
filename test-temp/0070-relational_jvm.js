
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

                                                            // int g1;
                                                            // int g2;
                                                            // 
                                                            // main() {
function main
(){
                                             main_end: {
                                                            // 	int i;
                                                            // 	int j;
                                                            // 	int k;
                                                            // 
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (0+BP);
                                                            // 	j = 10;
                        loadi             (10);
                        store             (1+BP);
                                                            // 	k = -5;
                        loadi             (5);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        store             (2+BP);
                                                            // 
                                                            // 
                                                            // 	g1 = 2;
                        loadi             (2);
                        store             (-1+global);
                                                            // 
                                                            // 
                                                            // 	g1 = 1 == 10 == 10;
                        loadi             (1);
                        store             (3+BP);
                        loadi             (10);
                        subtract          (3+BP);
                                             compare_0_false: {
                                             compare_0_true: {
                        if(equals())      break compare_0_true;
                        loadi             (0);
                        if(always())      break compare_0_false;
} // compare_0_true:
                        loadi             (1);
} // compare_0_false:
                        store             (3+BP);
                        loadi             (10);
                        subtract          (3+BP);
                                             compare_1_false: {
                                             compare_1_true: {
                        if(equals())      break compare_1_true;
                        loadi             (0);
                        if(always())      break compare_1_false;
} // compare_1_true:
                        loadi             (1);
} // compare_1_false:
                        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printIntegerNumber (A);
                                                            // 
                                                            // 	g1 = 10 == 10 == 1;
                        loadi             (10);
                        store             (3+BP);
                        loadi             (10);
                        subtract          (3+BP);
                                             compare_2_false: {
                                             compare_2_true: {
                        if(equals())      break compare_2_true;
                        loadi             (0);
                        if(always())      break compare_2_false;
} // compare_2_true:
                        loadi             (1);
} // compare_2_false:
                        store             (3+BP);
                        loadi             (1);
                        subtract          (3+BP);
                                             compare_3_false: {
                                             compare_3_true: {
                        if(equals())      break compare_3_true;
                        loadi             (0);
                        if(always())      break compare_3_false;
} // compare_3_true:
                        loadi             (1);
} // compare_3_false:
                        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printIntegerNumber (A);
                                                            // 
                                                            // 	g1 = 1 > 5 != 0;
                        loadi             (1);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_4_false: {
                                             compare_4_true: {
                        if(greater())     break compare_4_true;
                        loadi             (0);
                        if(always())      break compare_4_false;
} // compare_4_true:
                        loadi             (1);
} // compare_4_false:
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                                             compare_5_false: {
                                             compare_5_true: {
                        if(notequals())   break compare_5_true;
                        loadi             (0);
                        if(always())      break compare_5_false;
} // compare_5_true:
                        loadi             (1);
} // compare_5_false:
                        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printIntegerNumber (A);
                                                            // 
                                                            // 	g1 = 1 > 5 == 0;
                        loadi             (1);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_6_false: {
                                             compare_6_true: {
                        if(greater())     break compare_6_true;
                        loadi             (0);
                        if(always())      break compare_6_false;
} // compare_6_true:
                        loadi             (1);
} // compare_6_false:
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                                             compare_7_false: {
                                             compare_7_true: {
                        if(equals())      break compare_7_true;
                        loadi             (0);
                        if(always())      break compare_7_false;
} // compare_7_true:
                        loadi             (1);
} // compare_7_false:
                        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printIntegerNumber (A);
                                                            // 
                                                            // 	debug(2 < 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_8_false: {
                                             compare_8_true: {
                        if(less())        break compare_8_true;
                        loadi             (0);
                        if(always())      break compare_8_false;
} // compare_8_true:
                        loadi             (1);
} // compare_8_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 <= 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_9_false: {
                                             compare_9_true: {
                        if(less())        break compare_9_true;
                        if(equals())      break compare_9_true;
                        loadi             (0);
                        if(always())      break compare_9_false;
} // compare_9_true:
                        loadi             (1);
} // compare_9_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 <= 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                                             compare_10_false: {
                                             compare_10_true: {
                        if(less())        break compare_10_true;
                        if(equals())      break compare_10_true;
                        loadi             (0);
                        if(always())      break compare_10_false;
} // compare_10_true:
                        loadi             (1);
} // compare_10_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 > 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_11_false: {
                                             compare_11_true: {
                        if(greater())     break compare_11_true;
                        loadi             (0);
                        if(always())      break compare_11_false;
} // compare_11_true:
                        loadi             (1);
} // compare_11_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 >= 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_12_false: {
                                             compare_12_true: {
                        if(greater())     break compare_12_true;
                        if(equals())      break compare_12_true;
                        loadi             (0);
                        if(always())      break compare_12_false;
} // compare_12_true:
                        loadi             (1);
} // compare_12_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 >= 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                                             compare_13_false: {
                                             compare_13_true: {
                        if(greater())     break compare_13_true;
                        if(equals())      break compare_13_true;
                        loadi             (0);
                        if(always())      break compare_13_false;
} // compare_13_true:
                        loadi             (1);
} // compare_13_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 == 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                                             compare_14_false: {
                                             compare_14_true: {
                        if(equals())      break compare_14_true;
                        loadi             (0);
                        if(always())      break compare_14_false;
} // compare_14_true:
                        loadi             (1);
} // compare_14_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 == 3);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (3);
                        subtract          (3+BP);
                                             compare_15_false: {
                                             compare_15_true: {
                        if(equals())      break compare_15_true;
                        loadi             (0);
                        if(always())      break compare_15_false;
} // compare_15_true:
                        loadi             (1);
} // compare_15_false:
                        printIntegerNumber (A);
                                                            // 	debug(3 == 2);
                        loadi             (3);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                                             compare_16_false: {
                                             compare_16_true: {
                        if(equals())      break compare_16_true;
                        loadi             (0);
                        if(always())      break compare_16_false;
} // compare_16_true:
                        loadi             (1);
} // compare_16_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 != 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                                             compare_17_false: {
                                             compare_17_true: {
                        if(notequals())   break compare_17_true;
                        loadi             (0);
                        if(always())      break compare_17_false;
} // compare_17_true:
                        loadi             (1);
} // compare_17_false:
                        printIntegerNumber (A);
                                                            // 	debug(2 != 3);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (3);
                        subtract          (3+BP);
                                             compare_18_false: {
                                             compare_18_true: {
                        if(notequals())   break compare_18_true;
                        loadi             (0);
                        if(always())      break compare_18_false;
} // compare_18_true:
                        loadi             (1);
} // compare_18_false:
                        printIntegerNumber (A);
                                                            // 	debug(3 != 2);
                        loadi             (3);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                                             compare_19_false: {
                                             compare_19_true: {
                        if(notequals())   break compare_19_true;
                        loadi             (0);
                        if(always())      break compare_19_false;
} // compare_19_true:
                        loadi             (1);
} // compare_19_false:
                        printIntegerNumber (A);
                                                            // 
                                                            // }
} // main_end:
return;	}


function init_memory() {
global = 1048578;

BP = 0;

RAM = [
];

for (i = 0; i < 1048578; i ++) {
RAM[i] = 0;
}
}

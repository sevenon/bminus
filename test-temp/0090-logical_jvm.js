
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
                                                            // 	g1 = 2;
                        loadi             (2);
                        store             (-1+global);
                                                            // 	g2 = -4;
                        loadi             (4);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        store             (-2+global);
                                                            // 
                                                            // 	i = 5;
                        loadi             (5);
                        store             (0+BP);
                                                            // 	j = 6;
                        loadi             (6);
                        store             (1+BP);
                                                            // 
                                                            // 	debug(i < 5 && j == 6);
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_0_false: {
                                             compare_0_true: {
                        if(less())        break compare_0_true;
                        loadi             (0);
                        if(always())      break compare_0_false;
} // compare_0_true:
                        loadi             (1);
} // compare_0_false:
                                             logical_and_1_true: {
                                             logical_and_1_false: {
                        if(equals())      break logical_and_1_false;
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (6);
                        subtract          (3+BP);
                                             compare_2_false: {
                                             compare_2_true: {
                        if(equals())      break compare_2_true;
                        loadi             (0);
                        if(always())      break compare_2_false;
} // compare_2_true:
                        loadi             (1);
} // compare_2_false:
                        if(equals())      break logical_and_1_false;
                        loadi             (1);
                        if(always())      break logical_and_1_true;
} // logical_and_1_false:
                        loadi             (0);
} // logical_and_1_true:
                        printIntegerNumber (A);
                                                            // 	if (i < 5 && j == 6)
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                                             compare_3_false: {
                                             compare_3_true: {
                        if(less())        break compare_3_true;
                        loadi             (0);
                        if(always())      break compare_3_false;
} // compare_3_true:
                        loadi             (1);
} // compare_3_false:
                                             logical_and_4_true: {
                                             logical_and_4_false: {
                        if(equals())      break logical_and_4_false;
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (6);
                        subtract          (3+BP);
                                             compare_5_false: {
                                             compare_5_true: {
                        if(equals())      break compare_5_true;
                        loadi             (0);
                        if(always())      break compare_5_false;
} // compare_5_true:
                        loadi             (1);
} // compare_5_false:
                        if(equals())      break logical_and_4_false;
                        loadi             (1);
                        if(always())      break logical_and_4_true;
} // logical_and_4_false:
                        loadi             (0);
} // logical_and_4_true:
                                             if_6_end: {
                                             if_6_next: {
                        if(equals())      break if_6_next;
                                                            // 		debug(1);
                        loadi             (1);
                        printIntegerNumber (A);
                        if(always())      break if_6_end;
} // if_6_next:
                                                            // 	else
                                                            // 		debug(2);
                        loadi             (2);
                        printIntegerNumber (A);
} // if_6_end:
                                                            // 
                                                            // 	debug(0 || 1 && 1 && 1);
                        loadi             (0);
                                             logical_or_7_false: {
                                             logical_or_7_true: {
                        if(notequals())   break logical_or_7_true;
                        loadi             (1);
                                             logical_and_8_true: {
                                             logical_and_8_false: {
                        if(equals())      break logical_and_8_false;
                        loadi             (1);
                        if(equals())      break logical_and_8_false;
                        loadi             (1);
                        if(equals())      break logical_and_8_false;
                        loadi             (1);
                        if(always())      break logical_and_8_true;
} // logical_and_8_false:
                        loadi             (0);
} // logical_and_8_true:
                        if(notequals())   break logical_or_7_true;
                        loadi             (0);
                        if(always())      break logical_or_7_false;
} // logical_or_7_true:
                        loadi             (1);
} // logical_or_7_false:
                        printIntegerNumber (A);
                                                            // 
                                                            // 	debug(1 || 0 && 1 && 1);
                        loadi             (1);
                                             logical_or_9_false: {
                                             logical_or_9_true: {
                        if(notequals())   break logical_or_9_true;
                        loadi             (0);
                                             logical_and_10_true: {
                                             logical_and_10_false: {
                        if(equals())      break logical_and_10_false;
                        loadi             (1);
                        if(equals())      break logical_and_10_false;
                        loadi             (1);
                        if(equals())      break logical_and_10_false;
                        loadi             (1);
                        if(always())      break logical_and_10_true;
} // logical_and_10_false:
                        loadi             (0);
} // logical_and_10_true:
                        if(notequals())   break logical_or_9_true;
                        loadi             (0);
                        if(always())      break logical_or_9_false;
} // logical_or_9_true:
                        loadi             (1);
} // logical_or_9_false:
                        printIntegerNumber (A);
                                                            // 
                                                            // 	if (1 || debug(10)) {}
                        loadi             (1);
                                             logical_or_11_false: {
                                             logical_or_11_true: {
                        if(notequals())   break logical_or_11_true;
                        loadi             (10);
                        printIntegerNumber (A);
                        if(notequals())   break logical_or_11_true;
                        loadi             (0);
                        if(always())      break logical_or_11_false;
} // logical_or_11_true:
                        loadi             (1);
} // logical_or_11_false:
                                             if_12_end: {
                                             if_12_next: {
                        if(equals())      break if_12_next;
                                                            // 	if (0 || debug(20)) {}
} // if_12_next:
} // if_12_end:
                        loadi             (0);
                                             logical_or_13_false: {
                                             logical_or_13_true: {
                        if(notequals())   break logical_or_13_true;
                        loadi             (20);
                        printIntegerNumber (A);
                        if(notequals())   break logical_or_13_true;
                        loadi             (0);
                        if(always())      break logical_or_13_false;
} // logical_or_13_true:
                        loadi             (1);
} // logical_or_13_false:
                                             if_14_end: {
                                             if_14_next: {
                        if(equals())      break if_14_next;
                                                            // 	if (1 && debug(30)) {}
} // if_14_next:
} // if_14_end:
                        loadi             (1);
                                             logical_and_15_true: {
                                             logical_and_15_false: {
                        if(equals())      break logical_and_15_false;
                        loadi             (30);
                        printIntegerNumber (A);
                        if(equals())      break logical_and_15_false;
                        loadi             (1);
                        if(always())      break logical_and_15_true;
} // logical_and_15_false:
                        loadi             (0);
} // logical_and_15_true:
                                             if_16_end: {
                                             if_16_next: {
                        if(equals())      break if_16_next;
                                                            // 	if (0 && debug(40)) {}
} // if_16_next:
} // if_16_end:
                        loadi             (0);
                                             logical_and_17_true: {
                                             logical_and_17_false: {
                        if(equals())      break logical_and_17_false;
                        loadi             (40);
                        printIntegerNumber (A);
                        if(equals())      break logical_and_17_false;
                        loadi             (1);
                        if(always())      break logical_and_17_true;
} // logical_and_17_false:
                        loadi             (0);
} // logical_and_17_true:
                                             if_18_end: {
                                             if_18_next: {
                        if(equals())      break if_18_next;
                                                            // }
} // if_18_next:
} // if_18_end:
                                                            // 
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

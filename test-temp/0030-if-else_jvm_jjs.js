
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
                                                            // 	int t;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (0+BP);
                                                            // 	t = 100;
                        loadi             (100);
                        store             (1+BP);
                                                            // 
                                                            // 	while (i != 10) {
                                             while_0_end: {
while_0_test: while(true) {
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (10);
                        subtract          (2+BP);
                                             compare_1_false: {
                                             compare_1_true: {
                        if(notequals())   break compare_1_true;
                        loadi             (0);
                        if(always())      break compare_1_false;
} // compare_1_true:
                        loadi             (1);
} // compare_1_false:
                        if(equals())      break while_0_end;
                                                            // 		if (i == 1)
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (1);
                        subtract          (2+BP);
                                             compare_2_false: {
                                             compare_2_true: {
                        if(equals())      break compare_2_true;
                        loadi             (0);
                        if(always())      break compare_2_false;
} // compare_2_true:
                        loadi             (1);
} // compare_2_false:
                                             if_3_end: {
                                             if_3_next: {
                        if(equals())      break if_3_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                        if(always())      break if_3_end;
} // if_3_next:
                                                            // 		else if (i == 2)
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (2);
                        subtract          (2+BP);
                                             compare_4_false: {
                                             compare_4_true: {
                        if(equals())      break compare_4_true;
                        loadi             (0);
                        if(always())      break compare_4_false;
} // compare_4_true:
                        loadi             (1);
} // compare_4_false:
                                             if_5_end: {
                                             if_5_next: {
                        if(equals())      break if_5_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                        if(always())      break if_5_end;
} // if_5_next:
                                                            // 		else if (i == 3)
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (3);
                        subtract          (2+BP);
                                             compare_6_false: {
                                             compare_6_true: {
                        if(equals())      break compare_6_true;
                        loadi             (0);
                        if(always())      break compare_6_false;
} // compare_6_true:
                        loadi             (1);
} // compare_6_false:
                                             if_7_end: {
                                             if_7_next: {
                        if(equals())      break if_7_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                        if(always())      break if_7_end;
} // if_7_next:
                                                            // 		else if (i == 4)
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (4);
                        subtract          (2+BP);
                                             compare_8_false: {
                                             compare_8_true: {
                        if(equals())      break compare_8_true;
                        loadi             (0);
                        if(always())      break compare_8_false;
} // compare_8_true:
                        loadi             (1);
} // compare_8_false:
                                             if_9_end: {
                                             if_9_next: {
                        if(equals())      break if_9_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                        if(always())      break if_9_end;
} // if_9_next:
                                                            // 		else if (i == 5)
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (5);
                        subtract          (2+BP);
                                             compare_10_false: {
                                             compare_10_true: {
                        if(equals())      break compare_10_true;
                        loadi             (0);
                        if(always())      break compare_10_false;
} // compare_10_true:
                        loadi             (1);
} // compare_10_false:
                                             if_11_end: {
                                             if_11_next: {
                        if(equals())      break if_11_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                        if(always())      break if_11_end;
} // if_11_next:
                                                            // 		else
                                                            // 			debug(t);
                        load              (1+BP);
                        printIntegerNumber (A);
} // if_11_end:
} // if_9_end:
} // if_7_end:
} // if_5_end:
} // if_3_end:
                                                            // 
                                                            // 		i = i + 1;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
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

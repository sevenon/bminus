
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

                                                            // 
                                                            // main() {
function main
(){
                                             main_end: {
                                                            // 	int i;
                                                            // 	int arr[10];
                                                            // 
                                                            // 	i = 9;
                        loadi             (9);
                        store             (0+BP);
                                                            // 	while (i >= 0) {
                                             while_0_end: {
while_0_test: while(true) {
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (0);
                        subtract          (11+BP);
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
                                                            // 		arr[i] = i + 100;
                        load              (0+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (12+BP);
                        loadi             (100);
                        add               (12+BP);
                        store             (12+BP);
                        load              (11+BP);
                        loadx             ();
                        load              (12+BP);
                        store             (1+BP+X);
                                                            // 		i = i - 1;
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (1);
                        store             (12+BP);
                        load              (11+BP);
                        subtract          (12+BP);
                        store             (0+BP);
                                                            // 	}
                                                            // 	i = 9;
                        if(always())      continue while_0_test;
                                             break; } // while_0_test:
} // while_0_end:
                        loadi             (9);
                        store             (0+BP);
                                                            // 	while (i >= 0) {
                                             while_2_end: {
while_2_test: while(true) {
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (0);
                        subtract          (11+BP);
                                             compare_3_false: {
                                             compare_3_true: {
                        if(greater())     break compare_3_true;
                        if(equals())      break compare_3_true;
                        loadi             (0);
                        if(always())      break compare_3_false;
} // compare_3_true:
                        loadi             (1);
} // compare_3_false:
                        if(equals())      break while_2_end;
                                                            // 		arr[i] = i + 100;
                        load              (0+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (12+BP);
                        loadi             (100);
                        add               (12+BP);
                        store             (12+BP);
                        load              (11+BP);
                        loadx             ();
                        load              (12+BP);
                        store             (1+BP+X);
                                                            // 		i = i - 1;
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (1);
                        store             (12+BP);
                        load              (11+BP);
                        subtract          (12+BP);
                        store             (0+BP);
                                                            // 	}
                                                            // 
                                                            // 	i = 0;
                        if(always())      continue while_2_test;
                                             break; } // while_2_test:
} // while_2_end:
                        loadi             (0);
                        store             (0+BP);
                                                            // 	while (i < 10) {
                                             while_4_end: {
while_4_test: while(true) {
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (10);
                        subtract          (11+BP);
                                             compare_5_false: {
                                             compare_5_true: {
                        if(less())        break compare_5_true;
                        loadi             (0);
                        if(always())      break compare_5_false;
} // compare_5_true:
                        loadi             (1);
} // compare_5_false:
                        if(equals())      break while_4_end;
                                                            // 		debug(arr[i]);
                        load              (0+BP);
                        loadx             ();
                        load              (1+BP+X);
                        printIntegerNumber (A);
                                                            // 		i = i + 1;
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (1);
                        add               (11+BP);
                        store             (0+BP);
                                                            // 	}	
                                                            // }
                        if(always())      continue while_4_test;
                                             break; } // while_4_test:
} // while_4_end:
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

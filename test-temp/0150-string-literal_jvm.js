
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

                                                            // fn(char s1[], char s2[]) {
function fn
(){
                                             fn_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(s1[i] != 0) {
                                             while_0_end: {
while_0_test: while(true) {
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                                             compare_1_false: {
                                             compare_1_true: {
                        if(notequals())   break compare_1_true;
                        loadi             (0);
                        if(always())      break compare_1_false;
} // compare_1_true:
                        loadi             (1);
} // compare_1_false:
                        if(equals())      break while_0_end;
                                                            // 		debug(s1[i]);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        printIntegerNumber (A);
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 	
                                                            // 	i = 0;
                        if(always())      continue while_0_test;
                                             break; } // while_0_test:
} // while_0_end:
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(s2[i] != 0) {
                                             while_2_end: {
while_2_test: while(true) {
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (1+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                                             compare_3_false: {
                                             compare_3_true: {
                        if(notequals())   break compare_3_true;
                        loadi             (0);
                        if(always())      break compare_3_false;
} // compare_3_true:
                        loadi             (1);
} // compare_3_false:
                        if(equals())      break while_2_end;
                                                            // 		debug(s2[i]);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (1+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        printIntegerNumber (A);
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // }
                        if(always())      continue while_2_test;
                                             break; } // while_2_test:
} // while_2_end:
                                                            // 
                                                            // main() {
} // fn_end:
return;	}
function main
(){
                                             main_end: {
                                                            // 
                                                            // 	fn("hello", "world");
                        loadi             (0);
                        store             (0+BP);
                        loadi             (6);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        fn();             
                        movebp            (-10);
                                                            // }
} // main_end:
return;	}


function init_memory() {
global = 1048588;

BP = 12;

RAM = [
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
"w".charCodeAt(0),
"o".charCodeAt(0),
"r".charCodeAt(0),
"l".charCodeAt(0),
"d".charCodeAt(0),
0
];

for (i = 12; i < 1048588; i ++) {
RAM[i] = 0;
}
}

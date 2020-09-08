
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

                                                            // // this is a comment
                                                            // 
                                                            // fn(char arr[]) {
function fn
(){
                                             fn_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	while(arr[i] != 0) {
                                             while_0_end: {
while_0_test: while(true) {
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        store             (2+BP);
                        loadi             (0);
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
                                                            // 		debug(arr[i]);
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        printIntegerNumber (A);
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                                                            // 	}
                                                            // }
                        if(always())      continue while_0_test;
                                             break; } // while_0_test:
} // while_0_end:
                                                            // 
                                                            // main() {// more comments
} // fn_end:
return;	}
function main
(){
                                             main_end: {
                                                            // 	int i;
                                                            // 	i = 5;
                        loadi             (5);
                        store             (0+BP);
                                                            // 	fn("hello // hello");
                        loadi             (0);
                        store             (1+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        fn();             
                        movebp            (-10);
                                                            // 	// comment
                                                            // 	debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                                                            // }
} // main_end:
return;	}


function init_memory() {
global = 1048591;

BP = 15;

RAM = [
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
" ".charCodeAt(0),
"/".charCodeAt(0),
"/".charCodeAt(0),
" ".charCodeAt(0),
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0
];

for (i = 15; i < 1048591; i ++) {
RAM[i] = 0;
}
}

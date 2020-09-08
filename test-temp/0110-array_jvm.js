
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

                                                            // enum { arrlen = 10 };
                                                            // 
                                                            // int j[10];
                                                            // int k[arrlen];
                                                            // 
                                                            // fn() {
function fn
(){
                                             fn_end: {
                                                            // 	return 2;
                        loadi             (2);
                        if(always())      break fn_end;
                                                            // }
                                                            // 
                                                            // main() {
} // fn_end:
return;	}
function main
(){
                                             main_end: {
                                                            // 	enum { five = 5 };
                                                            // 	int b;
                                                            // 	int i[five];
                                                            // 
                                                            // 	i[fn()] = 4;
                        movebp            (14);
                        fn();             
                        movebp            (-14);
                        store             (6+BP);
                        loadi             (4);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (1+BP+X);
                                                            // 
                                                            // 	j[i[2]] = 99;
                        loadi             (2);
                        loadx             ();
                        load              (1+BP+X);
                        store             (6+BP);
                        loadi             (99);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (-10+global+X);
                                                            // 
                                                            // 	b = 4;
                        loadi             (4);
                        store             (0+BP);
                                                            // 
                                                            // 	k[arrlen-1] = 0;
                        loadi             (10);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (6+BP);
                        subtract          (7+BP);
                        store             (6+BP);
                        loadi             (0);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (-20+global+X);
                                                            // 
                                                            // 	debug(j[b]);
                        load              (0+BP);
                        loadx             ();
                        load              (-10+global+X);
                        printIntegerNumber (A);
                                                            // }
} // main_end:
return;	}


function init_memory() {
global = 1048596;

BP = 0;

RAM = [
];

for (i = 0; i < 1048596; i ++) {
RAM[i] = 0;
}
}

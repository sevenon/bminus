
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
                                                            // 	i = 0;
                        loadi             (0);
                        store             (0+BP);
                                                            // 	i = i + 1;
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        add               (1+BP);
                        store             (0+BP);
                                                            // 
                                                            // 	debug(i);
                        load              (0+BP);
                        printIntegerNumber (A);
                                                            // }
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

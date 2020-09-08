
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

                                                            // int i;
                                                            // 
                                                            // main() {
function main
(){
                                             main_end: {
                                                            // 	i = 10;
                        loadi             (10);
                        store             (-1+global);
                                                            // 
                                                            // 	debug(i);
                        load              (-1+global);
                        printIntegerNumber (A);
                                                            // }
                                                            // 
} // main_end:
return;	}


function init_memory() {
global = 1048577;

BP = 0;

RAM = [
];

for (i = 0; i < 1048577; i ++) {
RAM[i] = 0;
}
}

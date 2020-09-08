
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
                                                            // 	k = 4 + 2 - 16 + 8 + (2 * 5 / 2);
                        loadi             (4);
                        store             (3+BP);
                        loadi             (2);
                        add               (3+BP);
                        store             (3+BP);
                        loadi             (16);
                        store             (4+BP);
                        load              (3+BP);
                        subtract          (4+BP);
                        store             (3+BP);
                        loadi             (8);
                        add               (3+BP);
                        store             (3+BP);
                        loadi             (2);
                        store             (4+BP);
                        loadi             (5);
                        multiply          (4+BP);
                        store             (4+BP);
                        loadi             (2);
                        store             (5+BP);
                        load              (4+BP);
                        divide            (5+BP);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	debug(k);
                        load              (2+BP);
                        printIntegerNumber (A);
                                                            // 
                                                            // 	k = (g1 + i * 5 / 2 - 10 + 4 / 2) * 2 - j * (g2 - 1);
                        load              (-1+global);
                        store             (3+BP);
                        load              (0+BP);
                        store             (4+BP);
                        loadi             (5);
                        multiply          (4+BP);
                        store             (4+BP);
                        loadi             (2);
                        store             (5+BP);
                        load              (4+BP);
                        divide            (5+BP);
                        add               (3+BP);
                        store             (3+BP);
                        loadi             (10);
                        store             (4+BP);
                        load              (3+BP);
                        subtract          (4+BP);
                        store             (3+BP);
                        loadi             (4);
                        store             (4+BP);
                        loadi             (2);
                        store             (5+BP);
                        load              (4+BP);
                        divide            (5+BP);
                        add               (3+BP);
                        store             (3+BP);
                        loadi             (2);
                        multiply          (3+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (-2+global);
                        store             (5+BP);
                        loadi             (1);
                        store             (6+BP);
                        load              (5+BP);
                        subtract          (6+BP);
                        multiply          (4+BP);
                        store             (4+BP);
                        load              (3+BP);
                        subtract          (4+BP);
                        store             (2+BP);
                                                            // 	debug(k);
                        load              (2+BP);
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

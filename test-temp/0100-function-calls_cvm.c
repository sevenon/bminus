#include <stdio.h>
#include <stdlib.h>

int A;
int X;
extern int BP;
extern int RAM[];

loadi       (int n) { A = n; }

load        (int n) { A = RAM[n]; }
store       (int n) { RAM[n] = A; }

add         (int n) { A += RAM[n]; }
subtract    (int n) { A -= RAM[n]; }
multiply    (int n) { A *= RAM[n]; }
divide      (int n) { A /= RAM[n]; }

loadx       ()      { X = A; }
movebp      (int n) { BP += n; }

less        ()      { return A > 0; }
greater     ()      { return A < 0; }
equals      ()      { return A == 0; }
notequals   ()      { return A != 0; }
always      ()      { return 1; }

extern int global;

                                                            // int global1;
                                                            // 
                                                            // f1(int arg1, int arg2, int arg3) {
f1
(){
                                                            // 	debug(arg1);
                        load              (0+BP);
                        printf            ("%d\n", A);
                                                            // 	debug(arg2);
                        load              (1+BP);
                        printf            ("%d\n", A);
                                                            // 	debug(arg3);
                        load              (2+BP);
                        printf            ("%d\n", A);
                                                            // }
                                                            // 
                                                            // int global2;
f1_end:
return;	}
                                                            // 
                                                            // f2(int arg2, int arg3) {
f2
(){
                                                            // 	return arg2 * arg3;
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        multiply          (2+BP);
                        if(always())      goto f2_end;
                                                            // }
                                                            // 
                                                            // int global3;
f2_end:
return;	}
                                                            // 
                                                            // main() {
main
(){
                                                            // 	int local1;
                                                            // 
                                                            // 	f1(10, f2(10,50), 30);
                        loadi             (10);
                        store             (1+BP);
                        loadi             (10);
                        store             (2+BP);
                        loadi             (50);
                        store             (3+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        f2();             
                        movebp            (-11);
                        store             (2+BP);
                        loadi             (30);
                        store             (3+BP);
                        load              (3+BP);
                        store             (14+BP);
                        load              (2+BP);
                        store             (13+BP);
                        load              (1+BP);
                        store             (12+BP);
                        movebp            (12);
                        f1();             
                        movebp            (-12);
                                                            // 
                                                            // 	local1 = 10;
                        loadi             (10);
                        store             (0+BP);
                                                            // 	global1 = 1;
                        loadi             (1);
                        store             (-1+global);
                                                            // 	global2 = 2;
                        loadi             (2);
                        store             (-2+global);
                                                            // 	global3 = 3;
                        loadi             (3);
                        store             (-3+global);
                                                            // 
                                                            // 	debug(local1);
                        load              (0+BP);
                        printf            ("%d\n", A);
                                                            // 	debug(global1);
                        load              (-1+global);
                        printf            ("%d\n", A);
                                                            // 	debug(global2);
                        load              (-2+global);
                        printf            ("%d\n", A);
                                                            // 	debug(global3);
                        load              (-3+global);
                        printf            ("%d\n", A);
                                                            // }
main_end:
return;	}


int global = 1048579;

int BP = 0;

int RAM[1048579] = {
};


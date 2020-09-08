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

                                                            // int g1;
                                                            // int g2;
                                                            // 
                                                            // main() {
main
(){
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
                        printf            ("%d\n", A);
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
                        printf            ("%d\n", A);
                                                            // 
                                                            // }
main_end:
return;	}


int global = 1048578;

int BP = 0;

int RAM[1048578] = {
};


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

                                                            // int glob;
                                                            // 
                                                            // main() {
main
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (0+BP);
                                                            // 	glob = -5;
                        loadi             (5);
                        store             (1+BP);
                        loadi             (0);
                        subtract          (1+BP);
                        store             (-1+global);
                                                            // 
                                                            // 	while (1) {
while_0_test:           loadi             (1);
                        if(equals())      goto while_0_end;
                                                            // 		debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                                                            // 		if (i < glob) {
                        load              (0+BP);
                        store             (1+BP);
                        load              (-1+global);
                        subtract          (1+BP);
                        if(less())        goto compare_1_true;
                        loadi             (0);
                        if(always())      goto compare_1_false;
compare_1_true:         loadi             (1);
compare_1_false:        if(equals())      goto if_2_next;
                                                            // 			return;
                        if(always())      goto main_end;
                                                            // 		}
                                                            // 		i = i - 1;
if_2_next:
if_2_end:               load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        store             (2+BP);
                        load              (1+BP);
                        subtract          (2+BP);
                        store             (0+BP);
                                                            // 	}
                                                            // }
                        if(always())      goto while_0_test;
while_0_end:
main_end:
return;	}


int global = 1048577;

int BP = 0;

int RAM[1048577] = {
};


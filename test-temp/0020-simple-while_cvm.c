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

                                                            // main() {
main
(){
                                                            // 	int i;
                                                            // 	i = 20;
                        loadi             (20);
                        store             (0+BP);
                                                            // 
                                                            // 	while (i - 10 >= 0) {
while_0_test:           load              (0+BP);
                        store             (1+BP);
                        loadi             (10);
                        store             (2+BP);
                        load              (1+BP);
                        subtract          (2+BP);
                        store             (1+BP);
                        loadi             (0);
                        subtract          (1+BP);
                        if(greater())     goto compare_1_true;
                        if(equals())      goto compare_1_true;
                        loadi             (0);
                        if(always())      goto compare_1_false;
compare_1_true:         loadi             (1);
compare_1_false:        if(equals())      goto while_0_end;
                                                            //     	debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                                                            // 		i = i-1;
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        store             (2+BP);
                        load              (1+BP);
                        subtract          (2+BP);
                        store             (0+BP);
                                                            // 	}
                                                            // 
                                                            // }
                        if(always())      goto while_0_test;
while_0_end:
main_end:
return;	}


int global = 1048576;

int BP = 0;

int RAM[1048576] = {
};


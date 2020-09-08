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

                                                            // 
                                                            // main() {
main
(){
                                                            // 	int i;
                                                            // 	int arr[10];
                                                            // 
                                                            // 	i = 9;
                        loadi             (9);
                        store             (0+BP);
                                                            // 	while (i >= 0) {
while_0_test:           load              (0+BP);
                        store             (11+BP);
                        loadi             (0);
                        subtract          (11+BP);
                        if(greater())     goto compare_1_true;
                        if(equals())      goto compare_1_true;
                        loadi             (0);
                        if(always())      goto compare_1_false;
compare_1_true:         loadi             (1);
compare_1_false:        if(equals())      goto while_0_end;
                                                            // 		arr[i] = i + 100;
                        load              (0+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (12+BP);
                        loadi             (100);
                        add               (12+BP);
                        store             (12+BP);
                        load              (11+BP);
                        loadx             ();
                        load              (12+BP);
                        store             (1+BP+X);
                                                            // 		i = i - 1;
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (1);
                        store             (12+BP);
                        load              (11+BP);
                        subtract          (12+BP);
                        store             (0+BP);
                                                            // 	}
                                                            // 	i = 9;
                        if(always())      goto while_0_test;
while_0_end:            loadi             (9);
                        store             (0+BP);
                                                            // 	while (i >= 0) {
while_2_test:           load              (0+BP);
                        store             (11+BP);
                        loadi             (0);
                        subtract          (11+BP);
                        if(greater())     goto compare_3_true;
                        if(equals())      goto compare_3_true;
                        loadi             (0);
                        if(always())      goto compare_3_false;
compare_3_true:         loadi             (1);
compare_3_false:        if(equals())      goto while_2_end;
                                                            // 		arr[i] = i + 100;
                        load              (0+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (12+BP);
                        loadi             (100);
                        add               (12+BP);
                        store             (12+BP);
                        load              (11+BP);
                        loadx             ();
                        load              (12+BP);
                        store             (1+BP+X);
                                                            // 		i = i - 1;
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (1);
                        store             (12+BP);
                        load              (11+BP);
                        subtract          (12+BP);
                        store             (0+BP);
                                                            // 	}
                                                            // 
                                                            // 	i = 0;
                        if(always())      goto while_2_test;
while_2_end:            loadi             (0);
                        store             (0+BP);
                                                            // 	while (i < 10) {
while_4_test:           load              (0+BP);
                        store             (11+BP);
                        loadi             (10);
                        subtract          (11+BP);
                        if(less())        goto compare_5_true;
                        loadi             (0);
                        if(always())      goto compare_5_false;
compare_5_true:         loadi             (1);
compare_5_false:        if(equals())      goto while_4_end;
                                                            // 		debug(arr[i]);
                        load              (0+BP);
                        loadx             ();
                        load              (1+BP+X);
                        printf            ("%d\n", A);
                                                            // 		i = i + 1;
                        load              (0+BP);
                        store             (11+BP);
                        loadi             (1);
                        add               (11+BP);
                        store             (0+BP);
                                                            // 	}	
                                                            // }
                        if(always())      goto while_4_test;
while_4_end:
main_end:
return;	}


int global = 1048576;

int BP = 0;

int RAM[1048576] = {
};


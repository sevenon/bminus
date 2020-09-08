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
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (0+BP);
                                                            // 	j = 10;
                        loadi             (10);
                        store             (1+BP);
                                                            // 	k = -5;
                        loadi             (5);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        store             (2+BP);
                                                            // 
                                                            // 
                                                            // 	g1 = 2;
                        loadi             (2);
                        store             (-1+global);
                                                            // 
                                                            // 
                                                            // 	g1 = 1 == 10 == 10;
                        loadi             (1);
                        store             (3+BP);
                        loadi             (10);
                        subtract          (3+BP);
                        if(equals())      goto compare_0_true;
                        loadi             (0);
                        if(always())      goto compare_0_false;
compare_0_true:         loadi             (1);
compare_0_false:        store             (3+BP);
                        loadi             (10);
                        subtract          (3+BP);
                        if(equals())      goto compare_1_true;
                        loadi             (0);
                        if(always())      goto compare_1_false;
compare_1_true:         loadi             (1);
compare_1_false:        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	g1 = 10 == 10 == 1;
                        loadi             (10);
                        store             (3+BP);
                        loadi             (10);
                        subtract          (3+BP);
                        if(equals())      goto compare_2_true;
                        loadi             (0);
                        if(always())      goto compare_2_false;
compare_2_true:         loadi             (1);
compare_2_false:        store             (3+BP);
                        loadi             (1);
                        subtract          (3+BP);
                        if(equals())      goto compare_3_true;
                        loadi             (0);
                        if(always())      goto compare_3_false;
compare_3_true:         loadi             (1);
compare_3_false:        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	g1 = 1 > 5 != 0;
                        loadi             (1);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(greater())     goto compare_4_true;
                        loadi             (0);
                        if(always())      goto compare_4_false;
compare_4_true:         loadi             (1);
compare_4_false:        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        if(notequals())   goto compare_5_true;
                        loadi             (0);
                        if(always())      goto compare_5_false;
compare_5_true:         loadi             (1);
compare_5_false:        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	g1 = 1 > 5 == 0;
                        loadi             (1);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(greater())     goto compare_6_true;
                        loadi             (0);
                        if(always())      goto compare_6_false;
compare_6_true:         loadi             (1);
compare_6_false:        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        if(equals())      goto compare_7_true;
                        loadi             (0);
                        if(always())      goto compare_7_false;
compare_7_true:         loadi             (1);
compare_7_false:        store             (-1+global);
                                                            // 	debug(g1);
                        load              (-1+global);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	debug(2 < 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(less())        goto compare_8_true;
                        loadi             (0);
                        if(always())      goto compare_8_false;
compare_8_true:         loadi             (1);
compare_8_false:        printf            ("%d\n", A);
                                                            // 	debug(2 <= 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(less())        goto compare_9_true;
                        if(equals())      goto compare_9_true;
                        loadi             (0);
                        if(always())      goto compare_9_false;
compare_9_true:         loadi             (1);
compare_9_false:        printf            ("%d\n", A);
                                                            // 	debug(2 <= 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                        if(less())        goto compare_10_true;
                        if(equals())      goto compare_10_true;
                        loadi             (0);
                        if(always())      goto compare_10_false;
compare_10_true:        loadi             (1);
compare_10_false:       printf            ("%d\n", A);
                                                            // 	debug(2 > 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(greater())     goto compare_11_true;
                        loadi             (0);
                        if(always())      goto compare_11_false;
compare_11_true:        loadi             (1);
compare_11_false:       printf            ("%d\n", A);
                                                            // 	debug(2 >= 5);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(greater())     goto compare_12_true;
                        if(equals())      goto compare_12_true;
                        loadi             (0);
                        if(always())      goto compare_12_false;
compare_12_true:        loadi             (1);
compare_12_false:       printf            ("%d\n", A);
                                                            // 	debug(2 >= 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                        if(greater())     goto compare_13_true;
                        if(equals())      goto compare_13_true;
                        loadi             (0);
                        if(always())      goto compare_13_false;
compare_13_true:        loadi             (1);
compare_13_false:       printf            ("%d\n", A);
                                                            // 	debug(2 == 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                        if(equals())      goto compare_14_true;
                        loadi             (0);
                        if(always())      goto compare_14_false;
compare_14_true:        loadi             (1);
compare_14_false:       printf            ("%d\n", A);
                                                            // 	debug(2 == 3);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (3);
                        subtract          (3+BP);
                        if(equals())      goto compare_15_true;
                        loadi             (0);
                        if(always())      goto compare_15_false;
compare_15_true:        loadi             (1);
compare_15_false:       printf            ("%d\n", A);
                                                            // 	debug(3 == 2);
                        loadi             (3);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                        if(equals())      goto compare_16_true;
                        loadi             (0);
                        if(always())      goto compare_16_false;
compare_16_true:        loadi             (1);
compare_16_false:       printf            ("%d\n", A);
                                                            // 	debug(2 != 2);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                        if(notequals())   goto compare_17_true;
                        loadi             (0);
                        if(always())      goto compare_17_false;
compare_17_true:        loadi             (1);
compare_17_false:       printf            ("%d\n", A);
                                                            // 	debug(2 != 3);
                        loadi             (2);
                        store             (3+BP);
                        loadi             (3);
                        subtract          (3+BP);
                        if(notequals())   goto compare_18_true;
                        loadi             (0);
                        if(always())      goto compare_18_false;
compare_18_true:        loadi             (1);
compare_18_false:       printf            ("%d\n", A);
                                                            // 	debug(3 != 2);
                        loadi             (3);
                        store             (3+BP);
                        loadi             (2);
                        subtract          (3+BP);
                        if(notequals())   goto compare_19_true;
                        loadi             (0);
                        if(always())      goto compare_19_false;
compare_19_true:        loadi             (1);
compare_19_false:       printf            ("%d\n", A);
                                                            // 
                                                            // }
main_end:
return;	}


int global = 1048578;

int BP = 0;

int RAM[1048578] = {
};


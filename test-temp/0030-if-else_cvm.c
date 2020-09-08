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
                                                            // 	int t;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (0+BP);
                                                            // 	t = 100;
                        loadi             (100);
                        store             (1+BP);
                                                            // 
                                                            // 	while (i != 10) {
while_0_test:           load              (0+BP);
                        store             (2+BP);
                        loadi             (10);
                        subtract          (2+BP);
                        if(notequals())   goto compare_1_true;
                        loadi             (0);
                        if(always())      goto compare_1_false;
compare_1_true:         loadi             (1);
compare_1_false:        if(equals())      goto while_0_end;
                                                            // 		if (i == 1)
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (1);
                        subtract          (2+BP);
                        if(equals())      goto compare_2_true;
                        loadi             (0);
                        if(always())      goto compare_2_false;
compare_2_true:         loadi             (1);
compare_2_false:        if(equals())      goto if_3_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                        if(always())      goto if_3_end;
                                                            // 		else if (i == 2)
if_3_next:              load              (0+BP);
                        store             (2+BP);
                        loadi             (2);
                        subtract          (2+BP);
                        if(equals())      goto compare_4_true;
                        loadi             (0);
                        if(always())      goto compare_4_false;
compare_4_true:         loadi             (1);
compare_4_false:        if(equals())      goto if_5_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                        if(always())      goto if_5_end;
                                                            // 		else if (i == 3)
if_5_next:              load              (0+BP);
                        store             (2+BP);
                        loadi             (3);
                        subtract          (2+BP);
                        if(equals())      goto compare_6_true;
                        loadi             (0);
                        if(always())      goto compare_6_false;
compare_6_true:         loadi             (1);
compare_6_false:        if(equals())      goto if_7_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                        if(always())      goto if_7_end;
                                                            // 		else if (i == 4)
if_7_next:              load              (0+BP);
                        store             (2+BP);
                        loadi             (4);
                        subtract          (2+BP);
                        if(equals())      goto compare_8_true;
                        loadi             (0);
                        if(always())      goto compare_8_false;
compare_8_true:         loadi             (1);
compare_8_false:        if(equals())      goto if_9_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                        if(always())      goto if_9_end;
                                                            // 		else if (i == 5)
if_9_next:              load              (0+BP);
                        store             (2+BP);
                        loadi             (5);
                        subtract          (2+BP);
                        if(equals())      goto compare_10_true;
                        loadi             (0);
                        if(always())      goto compare_10_false;
compare_10_true:        loadi             (1);
compare_10_false:       if(equals())      goto if_11_next;
                                                            // 			debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                        if(always())      goto if_11_end;
                                                            // 		else
                                                            // 			debug(t);
if_11_next:             load              (1+BP);
                        printf            ("%d\n", A);
if_11_end:
if_9_end:
if_7_end:
if_5_end:
                                                            // 
                                                            // 		i = i + 1;
if_3_end:               load              (0+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
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


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
                                                            // 	debug(i < 5 && j == 6);
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(less())        goto compare_0_true;
                        loadi             (0);
                        if(always())      goto compare_0_false;
compare_0_true:         loadi             (1);
compare_0_false:        if(equals())      goto logical_and_1_false;
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (6);
                        subtract          (3+BP);
                        if(equals())      goto compare_2_true;
                        loadi             (0);
                        if(always())      goto compare_2_false;
compare_2_true:         loadi             (1);
compare_2_false:        if(equals())      goto logical_and_1_false;
                        loadi             (1);
                        if(always())      goto logical_and_1_true;
logical_and_1_false:    loadi             (0);
logical_and_1_true:     printf            ("%d\n", A);
                                                            // 	if (i < 5 && j == 6)
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (5);
                        subtract          (3+BP);
                        if(less())        goto compare_3_true;
                        loadi             (0);
                        if(always())      goto compare_3_false;
compare_3_true:         loadi             (1);
compare_3_false:        if(equals())      goto logical_and_4_false;
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (6);
                        subtract          (3+BP);
                        if(equals())      goto compare_5_true;
                        loadi             (0);
                        if(always())      goto compare_5_false;
compare_5_true:         loadi             (1);
compare_5_false:        if(equals())      goto logical_and_4_false;
                        loadi             (1);
                        if(always())      goto logical_and_4_true;
logical_and_4_false:    loadi             (0);
logical_and_4_true:     if(equals())      goto if_6_next;
                                                            // 		debug(1);
                        loadi             (1);
                        printf            ("%d\n", A);
                        if(always())      goto if_6_end;
                                                            // 	else
                                                            // 		debug(2);
if_6_next:              loadi             (2);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	debug(0 || 1 && 1 && 1);
if_6_end:               loadi             (0);
                        if(notequals())   goto logical_or_7_true;
                        loadi             (1);
                        if(equals())      goto logical_and_8_false;
                        loadi             (1);
                        if(equals())      goto logical_and_8_false;
                        loadi             (1);
                        if(equals())      goto logical_and_8_false;
                        loadi             (1);
                        if(always())      goto logical_and_8_true;
logical_and_8_false:    loadi             (0);
logical_and_8_true:     if(notequals())   goto logical_or_7_true;
                        loadi             (0);
                        if(always())      goto logical_or_7_false;
logical_or_7_true:      loadi             (1);
logical_or_7_false:     printf            ("%d\n", A);
                                                            // 
                                                            // 	debug(1 || 0 && 1 && 1);
                        loadi             (1);
                        if(notequals())   goto logical_or_9_true;
                        loadi             (0);
                        if(equals())      goto logical_and_10_false;
                        loadi             (1);
                        if(equals())      goto logical_and_10_false;
                        loadi             (1);
                        if(equals())      goto logical_and_10_false;
                        loadi             (1);
                        if(always())      goto logical_and_10_true;
logical_and_10_false:   loadi             (0);
logical_and_10_true:    if(notequals())   goto logical_or_9_true;
                        loadi             (0);
                        if(always())      goto logical_or_9_false;
logical_or_9_true:      loadi             (1);
logical_or_9_false:     printf            ("%d\n", A);
                                                            // 
                                                            // 	if (1 || debug(10)) {}
                        loadi             (1);
                        if(notequals())   goto logical_or_11_true;
                        loadi             (10);
                        printf            ("%d\n", A);
                        if(notequals())   goto logical_or_11_true;
                        loadi             (0);
                        if(always())      goto logical_or_11_false;
logical_or_11_true:     loadi             (1);
logical_or_11_false:    if(equals())      goto if_12_next;
                                                            // 	if (0 || debug(20)) {}
if_12_next:
if_12_end:              loadi             (0);
                        if(notequals())   goto logical_or_13_true;
                        loadi             (20);
                        printf            ("%d\n", A);
                        if(notequals())   goto logical_or_13_true;
                        loadi             (0);
                        if(always())      goto logical_or_13_false;
logical_or_13_true:     loadi             (1);
logical_or_13_false:    if(equals())      goto if_14_next;
                                                            // 	if (1 && debug(30)) {}
if_14_next:
if_14_end:              loadi             (1);
                        if(equals())      goto logical_and_15_false;
                        loadi             (30);
                        printf            ("%d\n", A);
                        if(equals())      goto logical_and_15_false;
                        loadi             (1);
                        if(always())      goto logical_and_15_true;
logical_and_15_false:   loadi             (0);
logical_and_15_true:    if(equals())      goto if_16_next;
                                                            // 	if (0 && debug(40)) {}
if_16_next:
if_16_end:              loadi             (0);
                        if(equals())      goto logical_and_17_false;
                        loadi             (40);
                        printf            ("%d\n", A);
                        if(equals())      goto logical_and_17_false;
                        loadi             (1);
                        if(always())      goto logical_and_17_true;
logical_and_17_false:   loadi             (0);
logical_and_17_true:    if(equals())      goto if_18_next;
                                                            // }
if_18_next:
                                                            // 
if_18_end:
main_end:
return;	}


int global = 1048578;

int BP = 0;

int RAM[1048578] = {
};


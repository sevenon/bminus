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

                                                            // fn(char s1[], char s2[]) {
fn
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(s1[i] != 0) {
while_0_test:           load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        if(notequals())   goto compare_1_true;
                        loadi             (0);
                        if(always())      goto compare_1_false;
compare_1_true:         loadi             (1);
compare_1_false:        if(equals())      goto while_0_end;
                                                            // 		debug(s1[i]);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        printf            ("%d\n", A);
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 	
                                                            // 	i = 0;
                        if(always())      goto while_0_test;
while_0_end:            loadi             (0);
                        store             (2+BP);
                                                            // 	while(s2[i] != 0) {
while_2_test:           load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (1+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        if(notequals())   goto compare_3_true;
                        loadi             (0);
                        if(always())      goto compare_3_false;
compare_3_true:         loadi             (1);
compare_3_false:        if(equals())      goto while_2_end;
                                                            // 		debug(s2[i]);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (1+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        printf            ("%d\n", A);
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // }
                        if(always())      goto while_2_test;
                                                            // 
                                                            // main() {
while_2_end:
fn_end:
return;	}
main
(){
                                                            // 
                                                            // 	fn("hello", "world");
                        loadi             (0);
                        store             (0+BP);
                        loadi             (6);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        fn();             
                        movebp            (-10);
                                                            // }
main_end:
return;	}


int global = 1048588;

int BP = 12;

int RAM[1048588] = {
'h',
'e',
'l',
'l',
'o',
0,
'w',
'o',
'r',
'l',
'd',
0
};


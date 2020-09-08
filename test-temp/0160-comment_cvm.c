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

                                                            // // this is a comment
                                                            // 
                                                            // fn(char arr[]) {
fn
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	while(arr[i] != 0) {
while_0_test:           load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        store             (2+BP);
                        loadi             (0);
                        subtract          (2+BP);
                        if(notequals())   goto compare_1_true;
                        loadi             (0);
                        if(always())      goto compare_1_false;
compare_1_true:         loadi             (1);
compare_1_false:        if(equals())      goto while_0_end;
                                                            // 		debug(arr[i]);
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        printf            ("%d\n", A);
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                                                            // 	}
                                                            // }
                        if(always())      goto while_0_test;
                                                            // 
                                                            // main() {// more comments
while_0_end:
fn_end:
return;	}
main
(){
                                                            // 	int i;
                                                            // 	i = 5;
                        loadi             (5);
                        store             (0+BP);
                                                            // 	fn("hello // hello");
                        loadi             (0);
                        store             (1+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        fn();             
                        movebp            (-10);
                                                            // 	// comment
                                                            // 	debug(i);
                        load              (0+BP);
                        printf            ("%d\n", A);
                                                            // }
main_end:
return;	}


int global = 1048591;

int BP = 15;

int RAM[1048591] = {
'h',
'e',
'l',
'l',
'o',
' ',
'/',
'/',
' ',
'h',
'e',
'l',
'l',
'o',
0
};


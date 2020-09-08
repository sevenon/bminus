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

                                                            // enum { arrlen = 10 };
                                                            // 
                                                            // int j[10];
                                                            // int k[arrlen];
                                                            // 
                                                            // fn() {
fn
(){
                                                            // 	return 2;
                        loadi             (2);
                        if(always())      goto fn_end;
                                                            // }
                                                            // 
                                                            // main() {
fn_end:
return;	}
main
(){
                                                            // 	enum { five = 5 };
                                                            // 	int b;
                                                            // 	int i[five];
                                                            // 
                                                            // 	i[fn()] = 4;
                        movebp            (14);
                        fn();             
                        movebp            (-14);
                        store             (6+BP);
                        loadi             (4);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (1+BP+X);
                                                            // 
                                                            // 	j[i[2]] = 99;
                        loadi             (2);
                        loadx             ();
                        load              (1+BP+X);
                        store             (6+BP);
                        loadi             (99);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (-10+global+X);
                                                            // 
                                                            // 	b = 4;
                        loadi             (4);
                        store             (0+BP);
                                                            // 
                                                            // 	k[arrlen-1] = 0;
                        loadi             (10);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (6+BP);
                        subtract          (7+BP);
                        store             (6+BP);
                        loadi             (0);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (-20+global+X);
                                                            // 
                                                            // 	debug(j[b]);
                        load              (0+BP);
                        loadx             ();
                        load              (-10+global+X);
                        printf            ("%d\n", A);
                                                            // }
main_end:
return;	}


int global = 1048596;

int BP = 0;

int RAM[1048596] = {
};


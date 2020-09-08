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
                                                            // 	char c;
                                                            // 
                                                            // 	c = 'a';
                        loadi             (97);
                        store             (0+BP);
                                                            // 	debug (c);
                        load              (0+BP);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	c = '\n';
                        loadi             (10);
                        store             (0+BP);
                                                            // 	debug (c);
                        load              (0+BP);
                        printf            ("%d\n", A);
                                                            // }
main_end:
return;	}


int global = 1048576;

int BP = 0;

int RAM[1048576] = {
};


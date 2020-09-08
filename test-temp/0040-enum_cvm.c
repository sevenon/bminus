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

                                                            // enum {a, b, c, d=20, e, f=50};
                                                            // 
                                                            // 
                                                            // main() {
main
(){
                                                            // 	debug(a);
                        loadi             (0);
                        printf            ("%d\n", A);
                                                            // 	debug(b);
                        loadi             (1);
                        printf            ("%d\n", A);
                                                            // 	debug(c);
                        loadi             (2);
                        printf            ("%d\n", A);
                                                            // 	debug(d);
                        loadi             (20);
                        printf            ("%d\n", A);
                                                            // 	debug(e);
                        loadi             (21);
                        printf            ("%d\n", A);
                                                            // 	debug(f);
                        loadi             (50);
                        printf            ("%d\n", A);
                                                            // }
                                                            // 
main_end:
return;	}


int global = 1048576;

int BP = 0;

int RAM[1048576] = {
};


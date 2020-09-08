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

                                                            // int arr[10];
                                                            // 
                                                            // f(int arr[]) {
f
(){
                                                            // 	debug(arr[5]);
                        loadi             (5);
                        loadx             ();
                        loadi             (X);
                        store             (1+BP);
                        load              (0+BP);
                        add               (1+BP);
                        loadx             ();
                        load              (X);
                        printf            ("%d\n", A);
                                                            // 	arr[8] = 88;
                        loadi             (8);
                        store             (1+BP);
                        loadi             (88);
                        store             (2+BP);
                        load              (1+BP);
                        loadx             ();
                        load              (2+BP);
                        store             (1+BP);
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (X);
                                                            // }
                                                            // 
                                                            // fn(int arg[]) {
f_end:
return;	}
fn
(){
                                                            // 	arg[1] = 20;
                        loadi             (1);
                        store             (1+BP);
                        loadi             (20);
                        store             (2+BP);
                        load              (1+BP);
                        loadx             ();
                        load              (2+BP);
                        store             (1+BP);
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (X);
                                                            // 	arg[5] = 99;
                        loadi             (5);
                        store             (1+BP);
                        loadi             (99);
                        store             (2+BP);
                        load              (1+BP);
                        loadx             ();
                        load              (2+BP);
                        store             (1+BP);
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (X);
                                                            // 	debug(arg[1]);
                        loadi             (1);
                        loadx             ();
                        loadi             (X);
                        store             (1+BP);
                        load              (0+BP);
                        add               (1+BP);
                        loadx             ();
                        load              (X);
                        printf            ("%d\n", A);
                                                            // 	debug(arg[5]);
                        loadi             (5);
                        loadx             ();
                        loadi             (X);
                        store             (1+BP);
                        load              (0+BP);
                        add               (1+BP);
                        loadx             ();
                        load              (X);
                        printf            ("%d\n", A);
                                                            // 	f(arg);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        f();              
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // main() {
fn_end:
return;	}
main
(){
                                                            // 
                                                            // 	arr[0] = 10;
                        loadi             (0);
                        store             (0+BP);
                        loadi             (10);
                        store             (1+BP);
                        load              (0+BP);
                        loadx             ();
                        load              (1+BP);
                        store             (-10+global+X);
                                                            // 
                                                            // 	fn(arr);
                        loadi             (-10+global);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        fn();             
                        movebp            (-9);
                                                            // 
                                                            // 	debug(arr[0]);
                        loadi             (0);
                        loadx             ();
                        load              (-10+global+X);
                        printf            ("%d\n", A);
                                                            // 	debug(arr[1]);
                        loadi             (1);
                        loadx             ();
                        load              (-10+global+X);
                        printf            ("%d\n", A);
                                                            // 	debug(arr[8]);
                        loadi             (8);
                        loadx             ();
                        load              (-10+global+X);
                        printf            ("%d\n", A);
                                                            // }
main_end:
return;	}


int global = 1048586;

int BP = 0;

int RAM[1048586] = {
};


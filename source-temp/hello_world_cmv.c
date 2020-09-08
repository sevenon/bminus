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
                                                            // 
                                                            //     write("Hello world\n");
                        loadi             (0);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        write();          
                        movebp            (-9);
                                                            //     exit(0);
                        loadi             (0);
                        exit              (A);
                                                            // }
                                                            // 
                                                            // write(char str[]) {
main_end:
return;	}
write
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	while (str[i] != 0) {
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
                                                            // 		fputc(str[i], stdout);
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        fputc             (A, stdout);
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                                                            // 	}
                                                            // }
                        if(always())      goto while_0_test;
while_0_end:
write_end:
return;	}


int global = 1048589;

int BP = 13;

int RAM[1048589] = {
'H',
'e',
'l',
'l',
'o',
' ',
'w',
'o',
'r',
'l',
'd',
10,
0
};


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

                                                            // #ifndef VC_IDE
                                                            // #line 2 "globals.h"
                                                            // #endif
                                                            // 
                                                            // enum {
                                                            //     False = 0,
                                                            //     True = 1
                                                            // };
                                                            // 
                                                            // enum {
                                                            //     Str_size = 256,
                                                            //     Source_buffer_length = 1048576
                                                            // };
                                                            // 
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "stringlib.h"
                                                            // #endif
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // write(char str[]) {
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
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // writeln(char str[]) {
while_0_end:
write_end:
return;	}
writeln
(){
                                                            // 	write(str);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        write();          
                        movebp            (-9);
                                                            // 	fputc('\n', stdout);
                        loadi             (10);
                        fputc             (A, stdout);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // write_stderr(char str[]) {
writeln_end:
return;	}
write_stderr
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	while (str[i] != 0) {
while_2_test:           load              (1+BP);
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
                        if(notequals())   goto compare_3_true;
                        loadi             (0);
                        if(always())      goto compare_3_false;
compare_3_true:         loadi             (1);
compare_3_false:        if(equals())      goto while_2_end;
                                                            // 		fputc(str[i], stderr);
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        fputc             (A, stderr);
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                                                            // 	}
                                                            // }
                        if(always())      goto while_2_test;
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // writeln_stderr(char str[]) {
while_2_end:
write_stderr_end:
return;	}
writeln_stderr
(){
                                                            // 	write_stderr(str);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        write_stderr();   
                        movebp            (-9);
                                                            // 	fputc('\n', stderr);
                        loadi             (10);
                        fputc             (A, stderr);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // readln(char line[], int max_chars) {
writeln_stderr_end:
return;	}
readln
(){
                                                            //     int i;
                                                            //     int c;
                                                            // 
                                                            //     i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            //     c = 0;
                        loadi             (0);
                        store             (3+BP);
                                                            //     line[i] = 0;
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (0);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (4+BP);
                        loadi             (X);
                        store             (5+BP);
                        load              (0+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (X);
                                                            //     while (i < max_chars && c != '\n' && c != -1) {
while_4_test:           load              (2+BP);
                        store             (4+BP);
                        load              (1+BP);
                        subtract          (4+BP);
                        if(less())        goto compare_5_true;
                        loadi             (0);
                        if(always())      goto compare_5_false;
compare_5_true:         loadi             (1);
compare_5_false:        if(equals())      goto logical_and_6_false;
                        load              (3+BP);
                        store             (4+BP);
                        loadi             (10);
                        subtract          (4+BP);
                        if(notequals())   goto compare_7_true;
                        loadi             (0);
                        if(always())      goto compare_7_false;
compare_7_true:         loadi             (1);
compare_7_false:        if(equals())      goto logical_and_6_false;
                        load              (3+BP);
                        store             (4+BP);
                        loadi             (1);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        subtract          (4+BP);
                        if(notequals())   goto compare_8_true;
                        loadi             (0);
                        if(always())      goto compare_8_false;
compare_8_true:         loadi             (1);
compare_8_false:        if(equals())      goto logical_and_6_false;
                        loadi             (1);
                        if(always())      goto logical_and_6_true;
logical_and_6_false:    loadi             (0);
logical_and_6_true:     if(equals())      goto while_4_end;
                                                            //         c = fgetc(stdin);
                        A=fgetc           (stdin);
                        store             (3+BP);
                                                            //         if (c != -1 && c != '\r') {
                        load              (3+BP);
                        store             (4+BP);
                        loadi             (1);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        subtract          (4+BP);
                        if(notequals())   goto compare_9_true;
                        loadi             (0);
                        if(always())      goto compare_9_false;
compare_9_true:         loadi             (1);
compare_9_false:        if(equals())      goto logical_and_10_false;
                        load              (3+BP);
                        store             (4+BP);
                        loadi             (13);
                        subtract          (4+BP);
                        if(notequals())   goto compare_11_true;
                        loadi             (0);
                        if(always())      goto compare_11_false;
compare_11_true:        loadi             (1);
compare_11_false:       if(equals())      goto logical_and_10_false;
                        loadi             (1);
                        if(always())      goto logical_and_10_true;
logical_and_10_false:   loadi             (0);
logical_and_10_true:    if(equals())      goto if_12_next;
                                                            //             line[i] = c;
                        load              (2+BP);
                        store             (4+BP);
                        load              (3+BP);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (4+BP);
                        loadi             (X);
                        store             (5+BP);
                        load              (0+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (X);
                                                            //             line[i + 1] = 0;
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (4+BP);
                        loadi             (0);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (4+BP);
                        loadi             (X);
                        store             (5+BP);
                        load              (0+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (X);
                                                            //             i = i + 1;
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (2+BP);
                                                            //         }
                                                            //     }
if_12_next:
                                                            //     return i;
if_12_end:              if(always())      goto while_4_test;
while_4_end:            load              (2+BP);
                        if(always())      goto readln_end;
                                                            // }
                                                            // // ---------------------------------------------------------------------------
                                                            // starts_with(char str[], char with_str[]) {
readln_end:
return;	}
starts_with
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while (str[i] != 0 && str[i] == with_str[i]) {
while_13_test:          load              (2+BP);
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
                        if(notequals())   goto compare_14_true;
                        loadi             (0);
                        if(always())      goto compare_14_false;
compare_14_true:        loadi             (1);
compare_14_false:       if(equals())      goto logical_and_15_false;
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
                        subtract          (3+BP);
                        if(equals())      goto compare_16_true;
                        loadi             (0);
                        if(always())      goto compare_16_false;
compare_16_true:        loadi             (1);
compare_16_false:       if(equals())      goto logical_and_15_false;
                        loadi             (1);
                        if(always())      goto logical_and_15_true;
logical_and_15_false:   loadi             (0);
logical_and_15_true:    if(equals())      goto while_13_end;
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            //     }
                                                            // 
                                                            //     if (with_str[i] == 0) {
                        if(always())      goto while_13_test;
while_13_end:           load              (2+BP);
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
                        if(equals())      goto compare_17_true;
                        loadi             (0);
                        if(always())      goto compare_17_false;
compare_17_true:        loadi             (1);
compare_17_false:       if(equals())      goto if_18_next;
                                                            // 	    return True;
                        loadi             (1);
                        if(always())      goto starts_with_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_18_next:
if_18_end:              loadi             (0);
                        if(always())      goto starts_with_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // str_equals(char str1[], char str2[]) {
starts_with_end:
return;	}
str_equals
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while (str1[i] == str2[i]) {
while_19_test:          load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
                        subtract          (3+BP);
                        if(equals())      goto compare_20_true;
                        loadi             (0);
                        if(always())      goto compare_20_false;
compare_20_true:        loadi             (1);
compare_20_false:       if(equals())      goto while_19_end;
                                                            // 		if (str1[i] == 0 && str2[i] == 0) {
                        load              (2+BP);
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
                        if(equals())      goto compare_21_true;
                        loadi             (0);
                        if(always())      goto compare_21_false;
compare_21_true:        loadi             (1);
compare_21_false:       if(equals())      goto logical_and_22_false;
                        load              (2+BP);
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
                        if(equals())      goto compare_23_true;
                        loadi             (0);
                        if(always())      goto compare_23_false;
compare_23_true:        loadi             (1);
compare_23_false:       if(equals())      goto logical_and_22_false;
                        loadi             (1);
                        if(always())      goto logical_and_22_true;
logical_and_22_false:   loadi             (0);
logical_and_22_true:    if(equals())      goto if_24_next;
                                                            // 			return True;
                        loadi             (1);
                        if(always())      goto str_equals_end;
                                                            //         }
                                                            // 		if (str1[i] == 0 || str2[i] == 0) {
if_24_next:
if_24_end:              load              (2+BP);
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
                        if(equals())      goto compare_25_true;
                        loadi             (0);
                        if(always())      goto compare_25_false;
compare_25_true:        loadi             (1);
compare_25_false:       if(notequals())   goto logical_or_26_true;
                        load              (2+BP);
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
                        if(equals())      goto compare_27_true;
                        loadi             (0);
                        if(always())      goto compare_27_false;
compare_27_true:        loadi             (1);
compare_27_false:       if(notequals())   goto logical_or_26_true;
                        loadi             (0);
                        if(always())      goto logical_or_26_false;
logical_or_26_true:     loadi             (1);
logical_or_26_false:    if(equals())      goto if_28_next;
                                                            // 			return False;
                        loadi             (0);
                        if(always())      goto str_equals_end;
                                                            //         }
                                                            // 		i = i + 1;
if_28_next:
if_28_end:              load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      goto while_19_test;
while_19_end:           loadi             (0);
                        if(always())      goto str_equals_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // copy_pos(char dest[], char src[], int dest_pos, int src_pos) {
str_equals_end:
return;	}
copy_pos
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (4+BP);
                                                            // 	while (src[i + src_pos] != 0) {
while_29_test:          load              (4+BP);
                        store             (5+BP);
                        load              (3+BP);
                        add               (5+BP);
                        loadx             ();
                        loadi             (X);
                        store             (5+BP);
                        load              (1+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (X);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        if(notequals())   goto compare_30_true;
                        loadi             (0);
                        if(always())      goto compare_30_false;
compare_30_true:        loadi             (1);
compare_30_false:       if(equals())      goto while_29_end;
                                                            // 		dest[i + dest_pos] = src[i + src_pos];
                        load              (4+BP);
                        store             (5+BP);
                        load              (2+BP);
                        add               (5+BP);
                        store             (5+BP);
                        load              (4+BP);
                        store             (6+BP);
                        load              (3+BP);
                        add               (6+BP);
                        loadx             ();
                        loadi             (X);
                        store             (6+BP);
                        load              (1+BP);
                        add               (6+BP);
                        loadx             ();
                        load              (X);
                        store             (6+BP);
                        load              (5+BP);
                        loadx             ();
                        load              (6+BP);
                        store             (5+BP);
                        loadi             (X);
                        store             (6+BP);
                        load              (0+BP);
                        add               (6+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (X);
                                                            // 		i = i + 1;
                        load              (4+BP);
                        store             (5+BP);
                        loadi             (1);
                        add               (5+BP);
                        store             (4+BP);
                                                            // 	}
                                                            // 
                                                            // 	dest[i + dest_pos] = 0;
                        if(always())      goto while_29_test;
while_29_end:           load              (4+BP);
                        store             (5+BP);
                        load              (2+BP);
                        add               (5+BP);
                        store             (5+BP);
                        loadi             (0);
                        store             (6+BP);
                        load              (5+BP);
                        loadx             ();
                        load              (6+BP);
                        store             (5+BP);
                        loadi             (X);
                        store             (6+BP);
                        load              (0+BP);
                        add               (6+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (X);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // copy(char dest[], char src[]) {
copy_pos_end:
return;	}
copy
(){
                                                            // 
                                                            //     copy_pos(dest, src, 0, 0);
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (0);
                        store             (4+BP);
                        loadi             (0);
                        store             (5+BP);
                        load              (5+BP);
                        store             (15+BP);
                        load              (4+BP);
                        store             (14+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        copy_pos();       
                        movebp            (-12);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // copy_from(char dest[], char src[], int src_pos) {
copy_end:
return;	}
copy_from
(){
                                                            // 
                                                            //     copy_pos(dest, src, 0, src_pos);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        loadi             (0);
                        store             (5+BP);
                        load              (2+BP);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        copy_pos();       
                        movebp            (-12);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // copy_to(char dest[], char src[], int dest_pos) {
copy_from_end:
return;	}
copy_to
(){
                                                            // 
                                                            //     copy_pos(dest, src, dest_pos, 0);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (2+BP);
                        store             (5+BP);
                        loadi             (0);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        copy_pos();       
                        movebp            (-12);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // append(char dest[], char src[]) {
copy_to_end:
return;	}
append
(){
                                                            //     int dest_length;
                                                            // 
                                                            //     dest_length = length(dest);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        length();         
                        movebp            (-10);
                        store             (2+BP);
                                                            //     copy_to(dest, src, dest_length);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (2+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        copy_to();        
                        movebp            (-12);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // append_char(char dest[], int c) {
append_end:
return;	}
append_char
(){
                                                            //     char s[2];
                                                            // 
                                                            //     s[0] = c;
                        loadi             (0);
                        store             (4+BP);
                        load              (1+BP);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (2+BP+X);
                                                            //     s[1] = 0;
                        loadi             (1);
                        store             (4+BP);
                        loadi             (0);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (2+BP+X);
                                                            //     append(dest, s);
                        load              (0+BP);
                        store             (4+BP);
                        loadi             (2+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        movebp            (12);
                        append();         
                        movebp            (-12);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // fill_until_col(char str[], int col) {
append_char_end:
return;	}
fill_until_col
(){
                                                            // 	int i;
                                                            // 
                                                            //     i = length(str);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        length();         
                        movebp            (-10);
                        store             (2+BP);
                                                            // 	while (i < col) {
while_31_test:          load              (2+BP);
                        store             (3+BP);
                        load              (1+BP);
                        subtract          (3+BP);
                        if(less())        goto compare_32_true;
                        loadi             (0);
                        if(always())      goto compare_32_false;
compare_32_true:        loadi             (1);
compare_32_false:       if(equals())      goto while_31_end;
                                                            //         str[i] = ' ';
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (32);
                        store             (4+BP);
                        load              (3+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (3+BP);
                        loadi             (X);
                        store             (4+BP);
                        load              (0+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (3+BP);
                        store             (X);
                                                            //         i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            //     }
                                                            // 
                                                            //     str[i] = 0;
                        if(always())      goto while_31_test;
while_31_end:           load              (2+BP);
                        store             (3+BP);
                        loadi             (0);
                        store             (4+BP);
                        load              (3+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (3+BP);
                        loadi             (X);
                        store             (4+BP);
                        load              (0+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (3+BP);
                        store             (X);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // contains(char str[], char substr[]) {
fill_until_col_end:
return;	}
contains
(){
                                                            // 	int i;
                                                            // 	int j;
                                                            // 	int k;
                                                            // 
                                                            // 	if(substr[0] == 0) {
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (5+BP);
                        load              (1+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (X);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        if(equals())      goto compare_33_true;
                        loadi             (0);
                        if(always())      goto compare_33_false;
compare_33_true:        loadi             (1);
compare_33_false:       if(equals())      goto if_34_next;
                                                            // 		return True;
                        loadi             (1);
                        if(always())      goto contains_end;
                                                            //     }
                                                            // 
                                                            // 	i = 0;
if_34_next:
if_34_end:              loadi             (0);
                        store             (2+BP);
                                                            // 	while (str[i] != 0) {
while_35_test:          load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (5+BP);
                        load              (0+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (X);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        if(notequals())   goto compare_36_true;
                        loadi             (0);
                        if(always())      goto compare_36_false;
compare_36_true:        loadi             (1);
compare_36_false:       if(equals())      goto while_35_end;
                                                            // 		j = i;
                        load              (2+BP);
                        store             (3+BP);
                                                            // 		k = 0;
                        loadi             (0);
                        store             (4+BP);
                                                            // 		while (str[j] == substr[k]) {
while_37_test:          load              (3+BP);
                        loadx             ();
                        loadi             (X);
                        store             (5+BP);
                        load              (0+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (X);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        loadi             (X);
                        store             (6+BP);
                        load              (1+BP);
                        add               (6+BP);
                        loadx             ();
                        load              (X);
                        subtract          (5+BP);
                        if(equals())      goto compare_38_true;
                        loadi             (0);
                        if(always())      goto compare_38_false;
compare_38_true:        loadi             (1);
compare_38_false:       if(equals())      goto while_37_end;
                                                            // 			j = j + 1;
                        load              (3+BP);
                        store             (5+BP);
                        loadi             (1);
                        add               (5+BP);
                        store             (3+BP);
                                                            // 			k = k + 1;
                        load              (4+BP);
                        store             (5+BP);
                        loadi             (1);
                        add               (5+BP);
                        store             (4+BP);
                                                            // 			if (substr[k] == 0) {
                        load              (4+BP);
                        loadx             ();
                        loadi             (X);
                        store             (5+BP);
                        load              (1+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (X);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        if(equals())      goto compare_39_true;
                        loadi             (0);
                        if(always())      goto compare_39_false;
compare_39_true:        loadi             (1);
compare_39_false:       if(equals())      goto if_40_next;
                                                            // 				return True;
                        loadi             (1);
                        if(always())      goto contains_end;
                                                            //             }
                                                            // 		}
if_40_next:
                                                            // 		i = i + 1;
if_40_end:              if(always())      goto while_37_test;
while_37_end:           load              (2+BP);
                        store             (5+BP);
                        loadi             (1);
                        add               (5+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      goto while_35_test;
while_35_end:           loadi             (0);
                        if(always())      goto contains_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // contains_char(char str[], int c) {
contains_end:
return;	}
contains_char
(){
                                                            //     char s[2];
                                                            // 
                                                            //     s[0] = c;
                        loadi             (0);
                        store             (4+BP);
                        load              (1+BP);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (2+BP+X);
                                                            //     s[1] = 0;
                        loadi             (1);
                        store             (4+BP);
                        loadi             (0);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (2+BP+X);
                                                            //     return contains(str, s);
                        load              (0+BP);
                        store             (4+BP);
                        loadi             (2+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        movebp            (12);
                        contains();       
                        movebp            (-12);
                        if(always())      goto contains_char_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // length(char str[]) {
contains_char_end:
return;	}
length
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	while (str[i] != 0) {
while_41_test:          load              (1+BP);
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
                        if(notequals())   goto compare_42_true;
                        loadi             (0);
                        if(always())      goto compare_42_false;
compare_42_true:        loadi             (1);
compare_42_false:       if(equals())      goto while_41_end;
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                                                            //     }
                                                            // 
                                                            // 	return i;
                        if(always())      goto while_41_test;
while_41_end:           load              (1+BP);
                        if(always())      goto length_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // str_to_int(char str[]) {
length_end:
return;	}
str_to_int
(){
                                                            // 	int i;
                                                            // 	int n;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	n = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while (str[i] != 0) {
while_43_test:          load              (1+BP);
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
                        if(notequals())   goto compare_44_true;
                        loadi             (0);
                        if(always())      goto compare_44_false;
compare_44_true:        loadi             (1);
compare_44_false:       if(equals())      goto while_43_end;
                                                            // 		n = n * 10 + (str[i] - '0');
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (10);
                        multiply          (3+BP);
                        store             (3+BP);
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (0+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
                        store             (4+BP);
                        loadi             (48);
                        store             (5+BP);
                        load              (4+BP);
                        subtract          (5+BP);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (1+BP);
                                                            // 	}
                                                            // 
                                                            // 	return n;
                        if(always())      goto while_43_test;
while_43_end:           load              (2+BP);
                        if(always())      goto str_to_int_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // int_to_str(int n, char str[]) {
str_to_int_end:
return;	}
int_to_str
(){
                                                            //     int pos;
                                                            //     int endpos;
                                                            // 	int n_mod_10;
                                                            //     int absn;
                                                            //     char tmp_str[Str_size];
                                                            // 
                                                            //     absn = n;
                        load              (0+BP);
                        store             (5+BP);
                                                            //     if (absn < 0) {
                        load              (5+BP);
                        store             (262+BP);
                        loadi             (0);
                        subtract          (262+BP);
                        if(less())        goto compare_45_true;
                        loadi             (0);
                        if(always())      goto compare_45_false;
compare_45_true:        loadi             (1);
compare_45_false:       if(equals())      goto if_46_next;
                                                            //         absn = -absn;
                        load              (5+BP);
                        store             (262+BP);
                        loadi             (0);
                        subtract          (262+BP);
                        store             (5+BP);
                                                            //     }
                                                            // 
                                                            //     pos = Str_size - 1;
if_46_next:
if_46_end:              loadi             (256);
                        store             (262+BP);
                        loadi             (1);
                        store             (263+BP);
                        load              (262+BP);
                        subtract          (263+BP);
                        store             (2+BP);
                                                            //     tmp_str[pos] = 0;
                        load              (2+BP);
                        store             (262+BP);
                        loadi             (0);
                        store             (263+BP);
                        load              (262+BP);
                        loadx             ();
                        load              (263+BP);
                        store             (6+BP+X);
                                                            //     endpos = pos;
                        load              (2+BP);
                        store             (3+BP);
                                                            // 	while (pos == endpos || absn != 0) {
while_47_test:          load              (2+BP);
                        store             (262+BP);
                        load              (3+BP);
                        subtract          (262+BP);
                        if(equals())      goto compare_48_true;
                        loadi             (0);
                        if(always())      goto compare_48_false;
compare_48_true:        loadi             (1);
compare_48_false:       if(notequals())   goto logical_or_49_true;
                        load              (5+BP);
                        store             (262+BP);
                        loadi             (0);
                        subtract          (262+BP);
                        if(notequals())   goto compare_50_true;
                        loadi             (0);
                        if(always())      goto compare_50_false;
compare_50_true:        loadi             (1);
compare_50_false:       if(notequals())   goto logical_or_49_true;
                        loadi             (0);
                        if(always())      goto logical_or_49_false;
logical_or_49_true:     loadi             (1);
logical_or_49_false:    if(equals())      goto while_47_end;
                                                            // 		n_mod_10 = absn - (10 * ( absn / 10));
                        load              (5+BP);
                        store             (262+BP);
                        loadi             (10);
                        store             (263+BP);
                        load              (5+BP);
                        store             (264+BP);
                        loadi             (10);
                        store             (265+BP);
                        load              (264+BP);
                        divide            (265+BP);
                        multiply          (263+BP);
                        store             (263+BP);
                        load              (262+BP);
                        subtract          (263+BP);
                        store             (4+BP);
                                                            // 		pos = pos - 1;
                        load              (2+BP);
                        store             (262+BP);
                        loadi             (1);
                        store             (263+BP);
                        load              (262+BP);
                        subtract          (263+BP);
                        store             (2+BP);
                                                            // 		tmp_str[pos] = '0' + n_mod_10;
                        load              (2+BP);
                        store             (262+BP);
                        loadi             (48);
                        store             (263+BP);
                        load              (4+BP);
                        add               (263+BP);
                        store             (263+BP);
                        load              (262+BP);
                        loadx             ();
                        load              (263+BP);
                        store             (6+BP+X);
                                                            // 		absn = absn / 10;
                        load              (5+BP);
                        store             (262+BP);
                        loadi             (10);
                        store             (263+BP);
                        load              (262+BP);
                        divide            (263+BP);
                        store             (5+BP);
                                                            // 	}
                                                            // 
                                                            //     if (n < 0) {
                        if(always())      goto while_47_test;
while_47_end:           load              (0+BP);
                        store             (262+BP);
                        loadi             (0);
                        subtract          (262+BP);
                        if(less())        goto compare_51_true;
                        loadi             (0);
                        if(always())      goto compare_51_false;
compare_51_true:        loadi             (1);
compare_51_false:       if(equals())      goto if_52_next;
                                                            // 		pos = pos - 1;
                        load              (2+BP);
                        store             (262+BP);
                        loadi             (1);
                        store             (263+BP);
                        load              (262+BP);
                        subtract          (263+BP);
                        store             (2+BP);
                                                            //         tmp_str[pos] = '-';
                        load              (2+BP);
                        store             (262+BP);
                        loadi             (45);
                        store             (263+BP);
                        load              (262+BP);
                        loadx             ();
                        load              (263+BP);
                        store             (6+BP+X);
                                                            //     }
                                                            // 
                                                            //     copy_from(str, tmp_str, pos);
if_52_next:
if_52_end:              load              (1+BP);
                        store             (262+BP);
                        loadi             (6+BP);
                        store             (263+BP);
                        load              (2+BP);
                        store             (264+BP);
                        load              (264+BP);
                        store             (273+BP);
                        load              (263+BP);
                        store             (272+BP);
                        load              (262+BP);
                        store             (271+BP);
                        movebp            (271);
                        copy_from();      
                        movebp            (-271);
                                                            // }
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "errormessages.h"
                                                            // #endif
                                                            // 
                                                            // int error_line_no;
int_to_str_end:
return;	}
                                                            // int error_line_pos;
                                                            // 
                                                            // char error_file_name[Str_size];
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_set_line(int line_no, int line_pos) {
error_set_line
(){
                                                            //     error_line_no = line_no;
                        load              (0+BP);
                        store             (-1+global);
                                                            //     error_line_pos = line_pos;
                        load              (1+BP);
                        store             (-2+global);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_set_file_name(char file_name[]) {
error_set_line_end:
return;	}
error_set_file_name
(){
                                                            //     copy(error_file_name, file_name);
                        loadi             (-258+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_print(char err_type[], char msg[]) {
error_set_file_name_end:
return;	}
error_print
(){
                                                            //     char str[Str_size];
                                                            // 
                                                            //     write_stderr(err_type); writeln_stderr(msg);
                        load              (0+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        write_stderr();   
                        movebp            (-265);
                        load              (1+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln_stderr(); 
                        movebp            (-265);
                                                            // 
                                                            //     write_stderr("File: "); writeln_stderr(error_file_name);
                        loadi             (0);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        write_stderr();   
                        movebp            (-265);
                        loadi             (-258+global);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln_stderr(); 
                        movebp            (-265);
                                                            // 
                                                            //     int_to_str(error_line_no, str);
                        load              (-1+global);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                                                            //     write_stderr("Line no: "); writeln_stderr(str);
                        loadi             (7);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        write_stderr();   
                        movebp            (-265);
                        loadi             (2+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln_stderr(); 
                        movebp            (-265);
                                                            // 
                                                            //     int_to_str(error_line_pos, str);
                        load              (-2+global);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                                                            //     write_stderr("Line pos: "); writeln_stderr(str);
                        loadi             (17);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        write_stderr();   
                        movebp            (-265);
                        loadi             (2+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln_stderr(); 
                        movebp            (-265);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_compiler(char msg[]) {
error_print_end:
return;	}
error_compiler
(){
                                                            //     error_print("Compile error: ", msg);
                        loadi             (28);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_print();    
                        movebp            (-10);
                                                            //     exit(1);
                        loadi             (1);
                        exit              (A);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_syntax(char msg[]) {
error_compiler_end:
return;	}
error_syntax
(){
                                                            //     error_print("Syntax error: ", msg);
                        loadi             (44);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_print();    
                        movebp            (-10);
                                                            //     exit(1);
                        loadi             (1);
                        exit              (A);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_parse(char msg[]) {
error_syntax_end:
return;	}
error_parse
(){
                                                            //     error_print("Parse error: ", msg);
                        loadi             (59);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_print();    
                        movebp            (-10);
                                                            //     exit(1);
                        loadi             (1);
                        exit              (A);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_preprocessor(char msg[]) {
error_parse_end:
return;	}
error_preprocessor
(){
                                                            //     error_print("Error while reading source: ", msg);
                        loadi             (73);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_print();    
                        movebp            (-10);
                                                            //     exit(1);
                        loadi             (1);
                        exit              (A);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_target(char msg[]) {
error_preprocessor_end:
return;	}
error_target
(){
                                                            //     error_print("Code generation error: ", msg);
                        loadi             (102);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_print();    
                        movebp            (-10);
                                                            //     exit(1);
                        loadi             (1);
                        exit              (A);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // error_internal() {
error_target_end:
return;	}
error_internal
(){
                                                            //     error_print("Internal error", "");
                        loadi             (126);
                        store             (0+BP);
                        loadi             (141);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_print();    
                        movebp            (-10);
                                                            //     exit(1);
                        loadi             (1);
                        exit              (A);
                                                            // }
                                                            // 
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "preprocessor.h"
                                                            // #endif
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // char file_name[Str_size];
error_internal_end:
return;	}
                                                            // 
                                                            // int line_no;
                                                            // int line_pos;
                                                            // 
                                                            // char line[Str_size];
                                                            // int line_length;
                                                            // 
                                                            // char source_buffer[Source_buffer_length];
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_init() {
preprocessor_init
(){
                                                            //     line_no = 0;
                        loadi             (0);
                        store             (-515+global);
                                                            //     line_pos = 0;
                        loadi             (0);
                        store             (-516+global);
                                                            //     copy(source_buffer, "");
                        loadi             (-1049349+global);
                        store             (0+BP);
                        loadi             (142);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            //     copy(file_name, "N/A");
                        loadi             (-514+global);
                        store             (0+BP);
                        loadi             (143);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_get_line_no() {
preprocessor_init_end:
return;	}
preprocessor_get_line_no
(){
                                                            //     return line_no;
                        load              (-515+global);
                        if(always())      goto preprocessor_get_line_no_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_get_line_pos() {
preprocessor_get_line_no_end:
return;	}
preprocessor_get_line_pos
(){
                                                            //     return line_pos;
                        load              (-516+global);
                        if(always())      goto preprocessor_get_line_pos_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_get_source_chunk(char src[]) {
preprocessor_get_line_pos_end:
return;	}
preprocessor_get_source_chunk
(){
                                                            //     copy(src, source_buffer);
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (-1049349+global);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            //     copy(source_buffer, "");
                        loadi             (-1049349+global);
                        store             (1+BP);
                        loadi             (147);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_read_next_line() {
preprocessor_get_source_chunk_end:
return;	}
preprocessor_read_next_line
(){
                                                            //     int chars_read;
                                                            // 
                                                            //     chars_read = readln(line, Str_size - 1);
                        loadi             (-772+global);
                        store             (1+BP);
                        loadi             (256);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (2+BP);
                        subtract          (3+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        readln();         
                        movebp            (-11);
                        store             (0+BP);
                                                            //     if (chars_read == Str_size - 1) {
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (256);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (2+BP);
                        subtract          (3+BP);
                        subtract          (1+BP);
                        if(equals())      goto compare_53_true;
                        loadi             (0);
                        if(always())      goto compare_53_false;
compare_53_true:        loadi             (1);
compare_53_false:       if(equals())      goto if_54_next;
                                                            //         error_preprocessor("line too long");
                        loadi             (148);
                        store             (1+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_preprocessor(); 
                        movebp            (-10);
                                                            //     }
                                                            // 
                                                            //     if (str_equals(line, ""))
if_54_next:
if_54_end:              loadi             (-772+global);
                        store             (1+BP);
                        loadi             (162);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        str_equals();     
                        movebp            (-11);
                        if(equals())      goto if_55_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto preprocessor_read_next_line_end;
if_55_next:
                                                            // 
                                                            //     line_no = line_no + 1;
if_55_end:              load              (-515+global);
                        store             (1+BP);
                        loadi             (1);
                        add               (1+BP);
                        store             (-515+global);
                                                            //     line_pos = 0;
                        loadi             (0);
                        store             (-516+global);
                                                            //     line_length = length(line);
                        loadi             (-772+global);
                        store             (1+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        length();         
                        movebp            (-10);
                        store             (-773+global);
                                                            // 
                                                            //     append(source_buffer, line);
                        loadi             (-1049349+global);
                        store             (1+BP);
                        loadi             (-772+global);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        append();         
                        movebp            (-11);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto preprocessor_read_next_line_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_read_char() {
preprocessor_read_next_line_end:
return;	}
preprocessor_read_char
(){
                                                            //     int c;
                                                            // 
                                                            //     if (line_pos >= line_length)
                        load              (-516+global);
                        store             (1+BP);
                        load              (-773+global);
                        subtract          (1+BP);
                        if(greater())     goto compare_56_true;
                        if(equals())      goto compare_56_true;
                        loadi             (0);
                        if(always())      goto compare_56_false;
compare_56_true:        loadi             (1);
compare_56_false:       if(equals())      goto if_57_next;
                                                            //         return '\n';
                        loadi             (10);
                        if(always())      goto preprocessor_read_char_end;
if_57_next:
                                                            // 
                                                            //     c = line[line_pos];
if_57_end:              load              (-516+global);
                        loadx             ();
                        load              (-772+global+X);
                        store             (0+BP);
                                                            // 
                                                            //     line_pos = line_pos + 1;
                        load              (-516+global);
                        store             (1+BP);
                        loadi             (1);
                        add               (1+BP);
                        store             (-516+global);
                                                            //     return c;
                        load              (0+BP);
                        if(always())      goto preprocessor_read_char_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_lookahead1() {
preprocessor_read_char_end:
return;	}
preprocessor_lookahead1
(){
                                                            //     if (line_pos >= line_length)
                        load              (-516+global);
                        store             (0+BP);
                        load              (-773+global);
                        subtract          (0+BP);
                        if(greater())     goto compare_58_true;
                        if(equals())      goto compare_58_true;
                        loadi             (0);
                        if(always())      goto compare_58_false;
compare_58_true:        loadi             (1);
compare_58_false:       if(equals())      goto if_59_next;
                                                            //         return '\n';
                        loadi             (10);
                        if(always())      goto preprocessor_lookahead1_end;
if_59_next:
                                                            // 
                                                            //     return line[line_pos];
if_59_end:              load              (-516+global);
                        loadx             ();
                        load              (-772+global+X);
                        if(always())      goto preprocessor_lookahead1_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_lookahead2() {
preprocessor_lookahead1_end:
return;	}
preprocessor_lookahead2
(){
                                                            //     if (line_pos + 1 >= line_length)
                        load              (-516+global);
                        store             (0+BP);
                        loadi             (1);
                        add               (0+BP);
                        store             (0+BP);
                        load              (-773+global);
                        subtract          (0+BP);
                        if(greater())     goto compare_60_true;
                        if(equals())      goto compare_60_true;
                        loadi             (0);
                        if(always())      goto compare_60_false;
compare_60_true:        loadi             (1);
compare_60_false:       if(equals())      goto if_61_next;
                                                            //         return '\n';
                        loadi             (10);
                        if(always())      goto preprocessor_lookahead2_end;
if_61_next:
                                                            // 
                                                            //     return line[line_pos + 1];
if_61_end:              load              (-516+global);
                        store             (0+BP);
                        loadi             (1);
                        add               (0+BP);
                        loadx             ();
                        load              (-772+global+X);
                        if(always())      goto preprocessor_lookahead2_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_compiler_directive() {
preprocessor_lookahead2_end:
return;	}
preprocessor_compiler_directive
(){
                                                            //     int i;
                                                            // 
                                                            //     if (starts_with(line, "#line 2 ")) {
                        loadi             (-772+global);
                        store             (1+BP);
                        loadi             (163);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        starts_with();    
                        movebp            (-11);
                        if(equals())      goto if_62_next;
                                                            //         line_no = 2;
                        loadi             (2);
                        store             (-515+global);
                                                            // 
                                                            //         copy(file_name, "");
                        loadi             (-514+global);
                        store             (1+BP);
                        loadi             (172);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        copy();           
                        movebp            (-11);
                                                            //         i = length("#line 2 ");
                        loadi             (173);
                        store             (1+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        length();         
                        movebp            (-10);
                        store             (0+BP);
                                                            // 
                                                            //         while (line[i] != ' ' && line[i] != '\n' && line[i] != 0) {
while_63_test:          load              (0+BP);
                        loadx             ();
                        load              (-772+global+X);
                        store             (1+BP);
                        loadi             (32);
                        subtract          (1+BP);
                        if(notequals())   goto compare_64_true;
                        loadi             (0);
                        if(always())      goto compare_64_false;
compare_64_true:        loadi             (1);
compare_64_false:       if(equals())      goto logical_and_65_false;
                        load              (0+BP);
                        loadx             ();
                        load              (-772+global+X);
                        store             (1+BP);
                        loadi             (10);
                        subtract          (1+BP);
                        if(notequals())   goto compare_66_true;
                        loadi             (0);
                        if(always())      goto compare_66_false;
compare_66_true:        loadi             (1);
compare_66_false:       if(equals())      goto logical_and_65_false;
                        load              (0+BP);
                        loadx             ();
                        load              (-772+global+X);
                        store             (1+BP);
                        loadi             (0);
                        subtract          (1+BP);
                        if(notequals())   goto compare_67_true;
                        loadi             (0);
                        if(always())      goto compare_67_false;
compare_67_true:        loadi             (1);
compare_67_false:       if(equals())      goto logical_and_65_false;
                        loadi             (1);
                        if(always())      goto logical_and_65_true;
logical_and_65_false:   loadi             (0);
logical_and_65_true:    if(equals())      goto while_63_end;
                                                            //             append_char(file_name, line[i]);
                        loadi             (-514+global);
                        store             (1+BP);
                        load              (0+BP);
                        loadx             ();
                        load              (-772+global+X);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        append_char();    
                        movebp            (-11);
                                                            //             i = i + 1; 
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        add               (1+BP);
                        store             (0+BP);
                                                            //         }
                                                            // 		error_set_file_name(file_name);
                        if(always())      goto while_63_test;
while_63_end:           loadi             (-514+global);
                        store             (1+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_set_file_name(); 
                        movebp            (-10);
                                                            //         error_set_line(2, 0);
                        loadi             (2);
                        store             (1+BP);
                        loadi             (0);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        error_set_line(); 
                        movebp            (-11);
                                                            // 	}
                                                            // }
if_62_next:
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // preprocessor_skip() {
if_62_end:
preprocessor_compiler_directive_end:
return;	}
preprocessor_skip
(){
                                                            //     int c;
                                                            //     int c1;
                                                            // 
                                                            //     if (line_pos >= line_length) {
                        load              (-516+global);
                        store             (2+BP);
                        load              (-773+global);
                        subtract          (2+BP);
                        if(greater())     goto compare_68_true;
                        if(equals())      goto compare_68_true;
                        loadi             (0);
                        if(always())      goto compare_68_false;
compare_68_true:        loadi             (1);
compare_68_false:       if(equals())      goto if_69_next;
                                                            //         if (! preprocessor_read_next_line())
                        movebp            (10);
                        preprocessor_read_next_line(); 
                        movebp            (-10);
                        if(notequals())   goto logical_not_70_false;
                        loadi             (1);
                        if(always())      goto logical_not_70_true;
logical_not_70_false:   loadi             (0);
logical_not_70_true:    if(equals())      goto if_71_next;
                                                            //             return False;
                        loadi             (0);
                        if(always())      goto preprocessor_skip_end;
if_71_next:
                                                            // 
                                                            //         if (line_length == 0)
if_71_end:              load              (-773+global);
                        store             (2+BP);
                        loadi             (0);
                        subtract          (2+BP);
                        if(equals())      goto compare_72_true;
                        loadi             (0);
                        if(always())      goto compare_72_false;
compare_72_true:        loadi             (1);
compare_72_false:       if(equals())      goto if_73_next;
                                                            //             return preprocessor_skip();
                        movebp            (10);
                        preprocessor_skip(); 
                        movebp            (-10);
                        if(always())      goto preprocessor_skip_end;
if_73_next:
                                                            // 
                                                            //         if (starts_with(line, "#")) {
if_73_end:              loadi             (-772+global);
                        store             (2+BP);
                        loadi             (182);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        starts_with();    
                        movebp            (-12);
                        if(equals())      goto if_74_next;
                                                            //             preprocessor_compiler_directive();
                        movebp            (10);
                        preprocessor_compiler_directive(); 
                        movebp            (-10);
                                                            // 
                                                            //             line_pos = 0;
                        loadi             (0);
                        store             (-516+global);
                                                            //             line_length = 0;
                        loadi             (0);
                        store             (-773+global);
                                                            //             return preprocessor_skip();
                        movebp            (10);
                        preprocessor_skip(); 
                        movebp            (-10);
                        if(always())      goto preprocessor_skip_end;
                                                            //         }
                                                            //     }
if_74_next:
                                                            // 
                                                            //     c = line[line_pos];
if_74_end:
if_69_next:
if_69_end:              load              (-516+global);
                        loadx             ();
                        load              (-772+global+X);
                        store             (0+BP);
                                                            //     c1 = line[line_pos + 1];
                        load              (-516+global);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        loadx             ();
                        load              (-772+global+X);
                        store             (1+BP);
                                                            // 
                                                            //     if (c == ' ' || c == '\t' || c == '\n') {
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (32);
                        subtract          (2+BP);
                        if(equals())      goto compare_75_true;
                        loadi             (0);
                        if(always())      goto compare_75_false;
compare_75_true:        loadi             (1);
compare_75_false:       if(notequals())   goto logical_or_76_true;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (9);
                        subtract          (2+BP);
                        if(equals())      goto compare_77_true;
                        loadi             (0);
                        if(always())      goto compare_77_false;
compare_77_true:        loadi             (1);
compare_77_false:       if(notequals())   goto logical_or_76_true;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (10);
                        subtract          (2+BP);
                        if(equals())      goto compare_78_true;
                        loadi             (0);
                        if(always())      goto compare_78_false;
compare_78_true:        loadi             (1);
compare_78_false:       if(notequals())   goto logical_or_76_true;
                        loadi             (0);
                        if(always())      goto logical_or_76_false;
logical_or_76_true:     loadi             (1);
logical_or_76_false:    if(equals())      goto if_79_next;
                                                            //         line_pos = line_pos + 1;
                        load              (-516+global);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (-516+global);
                                                            //         return preprocessor_skip();
                        movebp            (10);
                        preprocessor_skip(); 
                        movebp            (-10);
                        if(always())      goto preprocessor_skip_end;
                                                            //     }
                                                            // 
                                                            //     if (c == '/' && c1 == '/') {
if_79_next:
if_79_end:              load              (0+BP);
                        store             (2+BP);
                        loadi             (47);
                        subtract          (2+BP);
                        if(equals())      goto compare_80_true;
                        loadi             (0);
                        if(always())      goto compare_80_false;
compare_80_true:        loadi             (1);
compare_80_false:       if(equals())      goto logical_and_81_false;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (47);
                        subtract          (2+BP);
                        if(equals())      goto compare_82_true;
                        loadi             (0);
                        if(always())      goto compare_82_false;
compare_82_true:        loadi             (1);
compare_82_false:       if(equals())      goto logical_and_81_false;
                        loadi             (1);
                        if(always())      goto logical_and_81_true;
logical_and_81_false:   loadi             (0);
logical_and_81_true:    if(equals())      goto if_83_next;
                                                            //         line_pos = 0;
                        loadi             (0);
                        store             (-516+global);
                                                            //         line_length = 0;
                        loadi             (0);
                        store             (-773+global);
                                                            //         return preprocessor_skip();
                        movebp            (10);
                        preprocessor_skip(); 
                        movebp            (-10);
                        if(always())      goto preprocessor_skip_end;
                                                            //     }
                                                            // 
                                                            //     return True;
if_83_next:
if_83_end:              loadi             (1);
                        if(always())      goto preprocessor_skip_end;
                                                            // }
                                                            // 
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "token.h"
                                                            // #endif
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // //
                                                            // // token
                                                            // //             integer-constant
                                                            // //             character-constant
                                                            // //             string-literal
                                                            // //             identifier-or-keyword
                                                            // //             symbol
                                                            // //
                                                            // // integer-constant
                                                            // //             digit-list
                                                            // //
                                                            // // character-constant
                                                            // //             ' char-escape-sequence '
                                                            // //             ' any-except ' '
                                                            // //            
                                                            // // digit-list
                                                            // //             digit digit-list
                                                            // //             digit
                                                            // //
                                                            // // digit
                                                            // //             one-of 0 1 2 3 4 5 6 7 8 9
                                                            // //            
                                                            // // string-literal
                                                            // //             " string-literal-char-sequence "
                                                            // //
                                                            // // string-literal-char-sequence
                                                            // //             string-literal-char string-literal-char-sequence
                                                            // //             string-literal-char
                                                            // //
                                                            // // string-literal-char
                                                            // //             char-escape-sequence
                                                            // //             any-char-except "
                                                            // //
                                                            // // char-escape-sequence
                                                            // //             one-of \n \r \t \\ \' \"
                                                            // //
                                                            // // identifier-or-keyword
                                                            // //             identifier-nondigit-char identifier-any-char-sequence
                                                            // //             identifier-nondigit-char
                                                            // //            
                                                            // // identifier-nondigit-char
                                                            // //             one-of _ a b c d e f g h i j k l m n o p q r s t u v w x y z
                                                            // //                      A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
                                                            // //            
                                                            // // identifier-any-char
                                                            // //             one-of _ a b c d e f g h i j k l m n o p q r s t u v w x y z
                                                            // //                      A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
                                                            // //                      0 1 2 3 4 5 6 7 8 9
                                                            // //           
                                                            // // identifier-any-char-sequence
                                                            // //             identifier-any-char identifier-any-char-sequence
                                                            // //             identifier-any-char
                                                            // // 
                                                            // // symbol
                                                            // //             one-of  < > + - / * = <= >= ( ) { } [ ] != == ; , 
                                                            // //
                                                            // // keyword
                                                            // //             one-of  const int char if else while enum debug
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // 
                                                            // int token_type;
preprocessor_skip_end:
return;	}
                                                            // int token_lookahead_type;
                                                            // 
                                                            // int token_line_no;
                                                            // int token_lookahead_line_no;
                                                            // 
                                                            // int token_line_pos;
                                                            // int token_lookahead_line_pos;
                                                            // 
                                                            // char token_text[Str_size];
                                                            // char token_lookahead_text[Str_size];
                                                            // 
                                                            // enum {
                                                            //     Token_t_invalid,
                                                            //     Token_t_character_constant,
                                                            //     Token_t_integer_constant,
                                                            //     Token_t_string_literal,
                                                            //     Token_t_identifier,
                                                            //     Token_t_symbol,
                                                            //     Token_t_keyword,
                                                            //     Token_t_eof
                                                            // };
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_init() {
token_init
(){
                                                            //     token_line_no = 0;
                        loadi             (0);
                        store             (-1049352+global);
                                                            //     token_line_pos = 0;
                        loadi             (0);
                        store             (-1049354+global);
                                                            //     token_lookahead_line_no = 0;
                        loadi             (0);
                        store             (-1049353+global);
                                                            //     token_lookahead_line_pos = 0;
                        loadi             (0);
                        store             (-1049355+global);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_char_escape_sequence() {
token_init_end:
return;	}
token_char_escape_sequence
(){
                                                            //     int c1;
                                                            //     int c2;
                                                            // 
                                                            //     c1 = preprocessor_lookahead1();
                        movebp            (10);
                        preprocessor_lookahead1(); 
                        movebp            (-10);
                        store             (0+BP);
                                                            //     c2 = preprocessor_lookahead2();
                        movebp            (10);
                        preprocessor_lookahead2(); 
                        movebp            (-10);
                        store             (1+BP);
                                                            // 
                                                            //     if (c1 != '\\' || c2 == '\n') {
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (92);
                        subtract          (2+BP);
                        if(notequals())   goto compare_84_true;
                        loadi             (0);
                        if(always())      goto compare_84_false;
compare_84_true:        loadi             (1);
compare_84_false:       if(notequals())   goto logical_or_85_true;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (10);
                        subtract          (2+BP);
                        if(equals())      goto compare_86_true;
                        loadi             (0);
                        if(always())      goto compare_86_false;
compare_86_true:        loadi             (1);
compare_86_false:       if(notequals())   goto logical_or_85_true;
                        loadi             (0);
                        if(always())      goto logical_or_85_false;
logical_or_85_true:     loadi             (1);
logical_or_85_false:    if(equals())      goto if_87_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_char_escape_sequence_end;
                                                            //     }
                                                            // 
                                                            //     preprocessor_read_char();
if_87_next:
if_87_end:              movebp            (10);
                        preprocessor_read_char(); 
                        movebp            (-10);
                                                            //     preprocessor_read_char();
                        movebp            (10);
                        preprocessor_read_char(); 
                        movebp            (-10);
                                                            // 
                                                            //     if        (c2 == 'n') {
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (110);
                        subtract          (2+BP);
                        if(equals())      goto compare_88_true;
                        loadi             (0);
                        if(always())      goto compare_88_false;
compare_88_true:        loadi             (1);
compare_88_false:       if(equals())      goto if_89_next;
                                                            //         c1 = 10;
                        loadi             (10);
                        store             (0+BP);
                                                            //     } else if (c2 == 'r') {
                        if(always())      goto if_89_end;
if_89_next:             load              (1+BP);
                        store             (2+BP);
                        loadi             (114);
                        subtract          (2+BP);
                        if(equals())      goto compare_90_true;
                        loadi             (0);
                        if(always())      goto compare_90_false;
compare_90_true:        loadi             (1);
compare_90_false:       if(equals())      goto if_91_next;
                                                            //         c1 = 13;
                        loadi             (13);
                        store             (0+BP);
                                                            //     } else if (c2 == 't') {
                        if(always())      goto if_91_end;
if_91_next:             load              (1+BP);
                        store             (2+BP);
                        loadi             (116);
                        subtract          (2+BP);
                        if(equals())      goto compare_92_true;
                        loadi             (0);
                        if(always())      goto compare_92_false;
compare_92_true:        loadi             (1);
compare_92_false:       if(equals())      goto if_93_next;
                                                            //         c1 = 9;
                        loadi             (9);
                        store             (0+BP);
                                                            //     } else if (c2 == '\\') {
                        if(always())      goto if_93_end;
if_93_next:             load              (1+BP);
                        store             (2+BP);
                        loadi             (92);
                        subtract          (2+BP);
                        if(equals())      goto compare_94_true;
                        loadi             (0);
                        if(always())      goto compare_94_false;
compare_94_true:        loadi             (1);
compare_94_false:       if(equals())      goto if_95_next;
                                                            //         c1 = 92;
                        loadi             (92);
                        store             (0+BP);
                                                            //     } else if (c2 == '\'') {
                        if(always())      goto if_95_end;
if_95_next:             load              (1+BP);
                        store             (2+BP);
                        loadi             (39);
                        subtract          (2+BP);
                        if(equals())      goto compare_96_true;
                        loadi             (0);
                        if(always())      goto compare_96_false;
compare_96_true:        loadi             (1);
compare_96_false:       if(equals())      goto if_97_next;
                                                            //         c1 = 39;
                        loadi             (39);
                        store             (0+BP);
                                                            //     } else if (c2 == '\"') {
                        if(always())      goto if_97_end;
if_97_next:             load              (1+BP);
                        store             (2+BP);
                        loadi             (34);
                        subtract          (2+BP);
                        if(equals())      goto compare_98_true;
                        loadi             (0);
                        if(always())      goto compare_98_false;
compare_98_true:        loadi             (1);
compare_98_false:       if(equals())      goto if_99_next;
                                                            //         c1 = 34;
                        loadi             (34);
                        store             (0+BP);
                                                            //     } else {
                        if(always())      goto if_99_end;
                                                            //         error_parse("invalid character escape sequence");
if_99_next:             loadi             (184);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        error_parse();    
                        movebp            (-11);
                                                            //     }
                                                            // 
                                                            //     append_char(token_lookahead_text, c1);
if_99_end:
if_97_end:
if_95_end:
if_93_end:
if_91_end:
if_89_end:              loadi             (-1049867+global);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        append_char();    
                        movebp            (-12);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_char_escape_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_string_literal_char() {
token_char_escape_sequence_end:
return;	}
token_string_literal_char
(){
                                                            //     int c1;
                                                            // 
                                                            //     if (token_char_escape_sequence()) {
                        movebp            (9);
                        token_char_escape_sequence(); 
                        movebp            (-9);
                        if(equals())      goto if_100_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_string_literal_char_end;
                                                            //     }
                                                            // 
                                                            //     c1 = preprocessor_lookahead1();
if_100_next:
if_100_end:             movebp            (9);
                        preprocessor_lookahead1(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     if (c1 != '"') {
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (34);
                        subtract          (1+BP);
                        if(notequals())   goto compare_101_true;
                        loadi             (0);
                        if(always())      goto compare_101_false;
compare_101_true:       loadi             (1);
compare_101_false:      if(equals())      goto if_102_next;
                                                            //         append_char(token_lookahead_text, c1);
                        loadi             (-1049867+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        append_char();    
                        movebp            (-11);
                                                            //         preprocessor_read_char();
                        movebp            (9);
                        preprocessor_read_char(); 
                        movebp            (-9);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_string_literal_char_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_102_next:
if_102_end:             loadi             (0);
                        if(always())      goto token_string_literal_char_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_string_literal_char_sequence() {
token_string_literal_char_end:
return;	}
token_string_literal_char_sequence
(){
                                                            // 
                                                            //     if (token_string_literal_char()) {
                        movebp            (8);
                        token_string_literal_char(); 
                        movebp            (-8);
                        if(equals())      goto if_103_next;
                                                            //         token_string_literal_char_sequence();
                        movebp            (8);
                        token_string_literal_char_sequence(); 
                        movebp            (-8);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_string_literal_char_sequence_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_103_next:
if_103_end:             loadi             (0);
                        if(always())      goto token_string_literal_char_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_string_literal() {
token_string_literal_char_sequence_end:
return;	}
token_string_literal
(){
                                                            // 
                                                            //     if (preprocessor_lookahead1() != '"') {
                        movebp            (8);
                        preprocessor_lookahead1(); 
                        movebp            (-8);
                        store             (0+BP);
                        loadi             (34);
                        subtract          (0+BP);
                        if(notequals())   goto compare_104_true;
                        loadi             (0);
                        if(always())      goto compare_104_false;
compare_104_true:       loadi             (1);
compare_104_false:      if(equals())      goto if_105_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_string_literal_end;
                                                            //     }
                                                            // 
                                                            //     preprocessor_read_char();
if_105_next:
if_105_end:             movebp            (8);
                        preprocessor_read_char(); 
                        movebp            (-8);
                                                            //     token_string_literal_char_sequence();
                        movebp            (8);
                        token_string_literal_char_sequence(); 
                        movebp            (-8);
                                                            // 
                                                            //     if (preprocessor_read_char() != '"') {
                        movebp            (8);
                        preprocessor_read_char(); 
                        movebp            (-8);
                        store             (0+BP);
                        loadi             (34);
                        subtract          (0+BP);
                        if(notequals())   goto compare_106_true;
                        loadi             (0);
                        if(always())      goto compare_106_false;
compare_106_true:       loadi             (1);
compare_106_false:      if(equals())      goto if_107_next;
                                                            //         error_parse("string literal not terminated");
                        loadi             (218);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_parse();    
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     token_lookahead_type = Token_t_string_literal;
if_107_next:
if_107_end:             loadi             (3);
                        store             (-1049351+global);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_string_literal_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_identifier_any_char() {
token_string_literal_end:
return;	}
token_identifier_any_char
(){
                                                            //     int c1;
                                                            // 
                                                            //     c1 = preprocessor_lookahead1();
                        movebp            (9);
                        preprocessor_lookahead1(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     if (! contains_char("_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", c1)) {
                        loadi             (248);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        contains_char();  
                        movebp            (-11);
                        if(notequals())   goto logical_not_108_false;
                        loadi             (1);
                        if(always())      goto logical_not_108_true;
logical_not_108_false:  loadi             (0);
logical_not_108_true:   if(equals())      goto if_109_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_identifier_any_char_end;
                                                            //     }
                                                            // 
                                                            //     append_char(token_lookahead_text, c1);
if_109_next:
if_109_end:             loadi             (-1049867+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        append_char();    
                        movebp            (-11);
                                                            //     preprocessor_read_char();
                        movebp            (9);
                        preprocessor_read_char(); 
                        movebp            (-9);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_identifier_any_char_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_identifier_any_char_sequence() {
token_identifier_any_char_end:
return;	}
token_identifier_any_char_sequence
(){
                                                            // 
                                                            //     if (! token_identifier_any_char()) {
                        movebp            (8);
                        token_identifier_any_char(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_110_false;
                        loadi             (1);
                        if(always())      goto logical_not_110_true;
logical_not_110_false:  loadi             (0);
logical_not_110_true:   if(equals())      goto if_111_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_identifier_any_char_sequence_end;
                                                            //     }
                                                            // 
                                                            //     token_identifier_any_char_sequence();
if_111_next:
if_111_end:             movebp            (8);
                        token_identifier_any_char_sequence(); 
                        movebp            (-8);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_identifier_any_char_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_identifier_non_digit_char() {
token_identifier_any_char_sequence_end:
return;	}
token_identifier_non_digit_char
(){
                                                            //     int c1;
                                                            // 
                                                            //     c1 = preprocessor_lookahead1();
                        movebp            (9);
                        preprocessor_lookahead1(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     if (! contains_char("_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", c1)) {
                        loadi             (312);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        contains_char();  
                        movebp            (-11);
                        if(notequals())   goto logical_not_112_false;
                        loadi             (1);
                        if(always())      goto logical_not_112_true;
logical_not_112_false:  loadi             (0);
logical_not_112_true:   if(equals())      goto if_113_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_identifier_non_digit_char_end;
                                                            //     }
                                                            // 
                                                            //     append_char(token_lookahead_text, c1);
if_113_next:
if_113_end:             loadi             (-1049867+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        append_char();    
                        movebp            (-11);
                                                            //     preprocessor_read_char();
                        movebp            (9);
                        preprocessor_read_char(); 
                        movebp            (-9);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_identifier_non_digit_char_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_identifier_or_keyword() {
token_identifier_non_digit_char_end:
return;	}
token_identifier_or_keyword
(){
                                                            //     char tmp_str[Str_size];
                                                            // 
                                                            //     if (! token_identifier_non_digit_char()) {
                        movebp            (264);
                        token_identifier_non_digit_char(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_114_false;
                        loadi             (1);
                        if(always())      goto logical_not_114_true;
logical_not_114_false:  loadi             (0);
logical_not_114_true:   if(equals())      goto if_115_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_identifier_or_keyword_end;
                                                            //     }
                                                            // 
                                                            //     token_identifier_any_char_sequence();
if_115_next:
if_115_end:             movebp            (264);
                        token_identifier_any_char_sequence(); 
                        movebp            (-264);
                                                            //     copy(tmp_str, " ");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (366);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //     append(tmp_str, token_lookahead_text);
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (-1049867+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            //     append(tmp_str, " ");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (368);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 
                                                            //     if (contains(" int char if else while enum return ", tmp_str)) {
                        loadi             (370);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        if(equals())      goto if_116_next;
                                                            //         token_lookahead_type = Token_t_keyword;
                        loadi             (6);
                        store             (-1049351+global);
                                                            //     } else {
                        if(always())      goto if_116_end;
                                                            //         token_lookahead_type = Token_t_identifier;
if_116_next:            loadi             (4);
                        store             (-1049351+global);
                                                            //     }
                                                            // 
                                                            //     return True;
if_116_end:             loadi             (1);
                        if(always())      goto token_identifier_or_keyword_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_character_constant() {
token_identifier_or_keyword_end:
return;	}
token_character_constant
(){
                                                            //     int c1;
                                                            // 
                                                            //     if (preprocessor_lookahead1() != '\'') {
                        movebp            (9);
                        preprocessor_lookahead1(); 
                        movebp            (-9);
                        store             (1+BP);
                        loadi             (39);
                        subtract          (1+BP);
                        if(notequals())   goto compare_117_true;
                        loadi             (0);
                        if(always())      goto compare_117_false;
compare_117_true:       loadi             (1);
compare_117_false:      if(equals())      goto if_118_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_character_constant_end;
                                                            //     }
                                                            // 
                                                            //     token_lookahead_type = Token_t_character_constant;
if_118_next:
if_118_end:             loadi             (1);
                        store             (-1049351+global);
                                                            //     preprocessor_read_char();
                        movebp            (9);
                        preprocessor_read_char(); 
                        movebp            (-9);
                                                            // 
                                                            //     if (! token_char_escape_sequence()) {
                        movebp            (9);
                        token_char_escape_sequence(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_119_false;
                        loadi             (1);
                        if(always())      goto logical_not_119_true;
logical_not_119_false:  loadi             (0);
logical_not_119_true:   if(equals())      goto if_120_next;
                                                            //         c1 = preprocessor_read_char();
                        movebp            (9);
                        preprocessor_read_char(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //         append_char(token_lookahead_text, c1);
                        loadi             (-1049867+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        append_char();    
                        movebp            (-11);
                                                            //     }
                                                            // 
                                                            //     c1 = preprocessor_read_char();
if_120_next:
if_120_end:             movebp            (9);
                        preprocessor_read_char(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     if (c1 != '\'') {
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (39);
                        subtract          (1+BP);
                        if(notequals())   goto compare_121_true;
                        loadi             (0);
                        if(always())      goto compare_121_false;
compare_121_true:       loadi             (1);
compare_121_false:      if(equals())      goto if_122_next;
                                                            //         error_parse("character constant not terminated");
                        loadi             (407);
                        store             (1+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_parse();    
                        movebp            (-10);
                                                            //     }
                                                            // 
                                                            //     return True;
if_122_next:
if_122_end:             loadi             (1);
                        if(always())      goto token_character_constant_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_digit() {
token_character_constant_end:
return;	}
token_digit
(){
                                                            //     int c1;
                                                            // 
                                                            //     c1 = preprocessor_lookahead1();
                        movebp            (9);
                        preprocessor_lookahead1(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            // 
                                                            //     if (! contains_char("0123456789", c1)) {
                        loadi             (441);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        contains_char();  
                        movebp            (-11);
                        if(notequals())   goto logical_not_123_false;
                        loadi             (1);
                        if(always())      goto logical_not_123_true;
logical_not_123_false:  loadi             (0);
logical_not_123_true:   if(equals())      goto if_124_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_digit_end;
                                                            //     }
                                                            // 
                                                            //     c1 = preprocessor_read_char();
if_124_next:
if_124_end:             movebp            (9);
                        preprocessor_read_char(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     append_char(token_lookahead_text, c1);
                        loadi             (-1049867+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        append_char();    
                        movebp            (-11);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_digit_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_digit_sequence() {
token_digit_end:
return;	}
token_digit_sequence
(){
                                                            //     if (! token_digit()) {
                        movebp            (8);
                        token_digit();    
                        movebp            (-8);
                        if(notequals())   goto logical_not_125_false;
                        loadi             (1);
                        if(always())      goto logical_not_125_true;
logical_not_125_false:  loadi             (0);
logical_not_125_true:   if(equals())      goto if_126_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_digit_sequence_end;
                                                            //     }
                                                            // 
                                                            //     token_digit_sequence();
if_126_next:
if_126_end:             movebp            (8);
                        token_digit_sequence(); 
                        movebp            (-8);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_digit_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_integer_constant() {
token_digit_sequence_end:
return;	}
token_integer_constant
(){
                                                            //     if (! token_digit_sequence()) {
                        movebp            (8);
                        token_digit_sequence(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_127_false;
                        loadi             (1);
                        if(always())      goto logical_not_127_true;
logical_not_127_false:  loadi             (0);
logical_not_127_true:   if(equals())      goto if_128_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto token_integer_constant_end;
                                                            //     }
                                                            // 
                                                            //     token_lookahead_type = Token_t_integer_constant;
if_128_next:
if_128_end:             loadi             (2);
                        store             (-1049351+global);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto token_integer_constant_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_symbol() {
token_integer_constant_end:
return;	}
token_symbol
(){
                                                            //     int c1;
                                                            //     int c2;
                                                            // 
                                                            //     c1 = preprocessor_lookahead1();
                        movebp            (10);
                        preprocessor_lookahead1(); 
                        movebp            (-10);
                        store             (0+BP);
                                                            //     c2 = preprocessor_lookahead2();
                        movebp            (10);
                        preprocessor_lookahead2(); 
                        movebp            (-10);
                        store             (1+BP);
                                                            // 
                                                            //     if (c1 == '<' && c2 == '=' ||
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (60);
                        subtract          (2+BP);
                        if(equals())      goto compare_129_true;
                        loadi             (0);
                        if(always())      goto compare_129_false;
compare_129_true:       loadi             (1);
compare_129_false:      if(equals())      goto logical_and_130_false;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (61);
                        subtract          (2+BP);
                        if(equals())      goto compare_131_true;
                        loadi             (0);
                        if(always())      goto compare_131_false;
compare_131_true:       loadi             (1);
compare_131_false:      if(equals())      goto logical_and_130_false;
                        loadi             (1);
                        if(always())      goto logical_and_130_true;
logical_and_130_false:  loadi             (0);
logical_and_130_true:   if(notequals())   goto logical_or_132_true;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (62);
                        subtract          (2+BP);
                        if(equals())      goto compare_133_true;
                        loadi             (0);
                        if(always())      goto compare_133_false;
compare_133_true:       loadi             (1);
compare_133_false:      if(equals())      goto logical_and_134_false;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (61);
                        subtract          (2+BP);
                        if(equals())      goto compare_135_true;
                        loadi             (0);
                        if(always())      goto compare_135_false;
compare_135_true:       loadi             (1);
compare_135_false:      if(equals())      goto logical_and_134_false;
                        loadi             (1);
                        if(always())      goto logical_and_134_true;
logical_and_134_false:  loadi             (0);
logical_and_134_true:   if(notequals())   goto logical_or_132_true;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (61);
                        subtract          (2+BP);
                        if(equals())      goto compare_136_true;
                        loadi             (0);
                        if(always())      goto compare_136_false;
compare_136_true:       loadi             (1);
compare_136_false:      if(equals())      goto logical_and_137_false;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (61);
                        subtract          (2+BP);
                        if(equals())      goto compare_138_true;
                        loadi             (0);
                        if(always())      goto compare_138_false;
compare_138_true:       loadi             (1);
compare_138_false:      if(equals())      goto logical_and_137_false;
                        loadi             (1);
                        if(always())      goto logical_and_137_true;
logical_and_137_false:  loadi             (0);
logical_and_137_true:   if(notequals())   goto logical_or_132_true;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (33);
                        subtract          (2+BP);
                        if(equals())      goto compare_139_true;
                        loadi             (0);
                        if(always())      goto compare_139_false;
compare_139_true:       loadi             (1);
compare_139_false:      if(equals())      goto logical_and_140_false;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (61);
                        subtract          (2+BP);
                        if(equals())      goto compare_141_true;
                        loadi             (0);
                        if(always())      goto compare_141_false;
compare_141_true:       loadi             (1);
compare_141_false:      if(equals())      goto logical_and_140_false;
                        loadi             (1);
                        if(always())      goto logical_and_140_true;
logical_and_140_false:  loadi             (0);
logical_and_140_true:   if(notequals())   goto logical_or_132_true;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (38);
                        subtract          (2+BP);
                        if(equals())      goto compare_142_true;
                        loadi             (0);
                        if(always())      goto compare_142_false;
compare_142_true:       loadi             (1);
compare_142_false:      if(equals())      goto logical_and_143_false;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (38);
                        subtract          (2+BP);
                        if(equals())      goto compare_144_true;
                        loadi             (0);
                        if(always())      goto compare_144_false;
compare_144_true:       loadi             (1);
compare_144_false:      if(equals())      goto logical_and_143_false;
                        loadi             (1);
                        if(always())      goto logical_and_143_true;
logical_and_143_false:  loadi             (0);
logical_and_143_true:   if(notequals())   goto logical_or_132_true;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (124);
                        subtract          (2+BP);
                        if(equals())      goto compare_145_true;
                        loadi             (0);
                        if(always())      goto compare_145_false;
compare_145_true:       loadi             (1);
compare_145_false:      if(equals())      goto logical_and_146_false;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (124);
                        subtract          (2+BP);
                        if(equals())      goto compare_147_true;
                        loadi             (0);
                        if(always())      goto compare_147_false;
compare_147_true:       loadi             (1);
compare_147_false:      if(equals())      goto logical_and_146_false;
                        loadi             (1);
                        if(always())      goto logical_and_146_true;
logical_and_146_false:  loadi             (0);
logical_and_146_true:   if(notequals())   goto logical_or_132_true;
                        loadi             (0);
                        if(always())      goto logical_or_132_false;
logical_or_132_true:    loadi             (1);
logical_or_132_false:   if(equals())      goto if_148_next;
                                                            //         c1 == '>' && c2 == '=' ||
                                                            //         c1 == '=' && c2 == '=' ||
                                                            //         c1 == '!' && c2 == '=' ||
                                                            //         c1 == '&' && c2 == '&' ||
                                                            //         c1 == '|' && c2 == '|') {
                                                            // 
                                                            //         copy(token_lookahead_text, "");
                        loadi             (-1049867+global);
                        store             (2+BP);
                        loadi             (452);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        copy();           
                        movebp            (-12);
                                                            //         append_char(token_lookahead_text, c1);
                        loadi             (-1049867+global);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        append_char();    
                        movebp            (-12);
                                                            //         append_char(token_lookahead_text, c2);
                        loadi             (-1049867+global);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        append_char();    
                        movebp            (-12);
                                                            // 
                                                            //         preprocessor_read_char();
                        movebp            (10);
                        preprocessor_read_char(); 
                        movebp            (-10);
                                                            //         preprocessor_read_char();
                        movebp            (10);
                        preprocessor_read_char(); 
                        movebp            (-10);
                                                            // 
                                                            //         token_lookahead_type = Token_t_symbol;
                        loadi             (5);
                        store             (-1049351+global);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_symbol_end;
                                                            //     }
                                                            // 
                                                            //     if (contains_char("<>=+-/*()[]{}!;,", c1)) {
if_148_next:
if_148_end:             loadi             (453);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        contains_char();  
                        movebp            (-12);
                        if(equals())      goto if_149_next;
                                                            //         copy(token_lookahead_text, "");
                        loadi             (-1049867+global);
                        store             (2+BP);
                        loadi             (470);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        copy();           
                        movebp            (-12);
                                                            //         append_char(token_lookahead_text, c1);
                        loadi             (-1049867+global);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        append_char();    
                        movebp            (-12);
                                                            // 
                                                            //         token_lookahead_type = Token_t_symbol;
                        loadi             (5);
                        store             (-1049351+global);
                                                            // 
                                                            //         preprocessor_read_char();
                        movebp            (10);
                        preprocessor_read_char(); 
                        movebp            (-10);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_symbol_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_149_next:
if_149_end:             loadi             (0);
                        if(always())      goto token_symbol_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_token() {
token_symbol_end:
return;	}
token_token
(){
                                                            // 
                                                            //     if (token_integer_constant()) {
                        movebp            (8);
                        token_integer_constant(); 
                        movebp            (-8);
                        if(equals())      goto if_150_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_token_end;
                                                            //     }
                                                            // 
                                                            //     if (token_character_constant()) {
if_150_next:
if_150_end:             movebp            (8);
                        token_character_constant(); 
                        movebp            (-8);
                        if(equals())      goto if_151_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_token_end;
                                                            //     }
                                                            // 
                                                            //     if (token_string_literal()) {
if_151_next:
if_151_end:             movebp            (8);
                        token_string_literal(); 
                        movebp            (-8);
                        if(equals())      goto if_152_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_token_end;
                                                            //     }
                                                            // 
                                                            //     if (token_identifier_or_keyword()) {
if_152_next:
if_152_end:             movebp            (8);
                        token_identifier_or_keyword(); 
                        movebp            (-8);
                        if(equals())      goto if_153_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_token_end;
                                                            //     }
                                                            // 
                                                            //     if (token_symbol()) {
if_153_next:
if_153_end:             movebp            (8);
                        token_symbol();   
                        movebp            (-8);
                        if(equals())      goto if_154_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_token_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_154_next:
if_154_end:             loadi             (0);
                        if(always())      goto token_token_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_get_next() {
token_token_end:
return;	}
token_get_next
(){
                                                            //     token_lookahead_type = Token_t_invalid;
                        loadi             (0);
                        store             (-1049351+global);
                                                            //     copy(token_lookahead_text, "");
                        loadi             (-1049867+global);
                        store             (0+BP);
                        loadi             (471);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            // 
                                                            //     if (! preprocessor_skip()) {
                        movebp            (8);
                        preprocessor_skip(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_155_false;
                        loadi             (1);
                        if(always())      goto logical_not_155_true;
logical_not_155_false:  loadi             (0);
logical_not_155_true:   if(equals())      goto if_156_next;
                                                            //         token_lookahead_type = Token_t_eof;
                        loadi             (7);
                        store             (-1049351+global);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_get_next_end;
                                                            //     }
                                                            // 
                                                            //     token_lookahead_line_no = preprocessor_get_line_no();
if_156_next:
if_156_end:             movebp            (8);
                        preprocessor_get_line_no(); 
                        movebp            (-8);
                        store             (-1049353+global);
                                                            //     token_lookahead_line_pos = preprocessor_get_line_pos();
                        movebp            (8);
                        preprocessor_get_line_pos(); 
                        movebp            (-8);
                        store             (-1049355+global);
                                                            // 
                                                            //     if (token_token()) {
                        movebp            (8);
                        token_token();    
                        movebp            (-8);
                        if(equals())      goto if_157_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_get_next_end;
                                                            //     }
                                                            // 
                                                            //     token_lookahead_type = Token_t_invalid;
if_157_next:
if_157_end:             loadi             (0);
                        store             (-1049351+global);
                                                            //     return False;
                        loadi             (0);
                        if(always())      goto token_get_next_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_text_is(char s[]) {
token_get_next_end:
return;	}
token_text_is
(){
                                                            //     if (token_type == Token_t_identifier || token_type == Token_t_symbol || token_type == Token_t_keyword) {
                        load              (-1049350+global);
                        store             (1+BP);
                        loadi             (4);
                        subtract          (1+BP);
                        if(equals())      goto compare_158_true;
                        loadi             (0);
                        if(always())      goto compare_158_false;
compare_158_true:       loadi             (1);
compare_158_false:      if(notequals())   goto logical_or_159_true;
                        load              (-1049350+global);
                        store             (1+BP);
                        loadi             (5);
                        subtract          (1+BP);
                        if(equals())      goto compare_160_true;
                        loadi             (0);
                        if(always())      goto compare_160_false;
compare_160_true:       loadi             (1);
compare_160_false:      if(notequals())   goto logical_or_159_true;
                        load              (-1049350+global);
                        store             (1+BP);
                        loadi             (6);
                        subtract          (1+BP);
                        if(equals())      goto compare_161_true;
                        loadi             (0);
                        if(always())      goto compare_161_false;
compare_161_true:       loadi             (1);
compare_161_false:      if(notequals())   goto logical_or_159_true;
                        loadi             (0);
                        if(always())      goto logical_or_159_false;
logical_or_159_true:    loadi             (1);
logical_or_159_false:   if(equals())      goto if_162_next;
                                                            //         if (str_equals(token_text, s)) {
                        loadi             (-1049611+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        str_equals();     
                        movebp            (-10);
                        if(equals())      goto if_163_next;
                                                            //             return True;
                        loadi             (1);
                        if(always())      goto token_text_is_end;
                                                            //         }
                                                            //     }
if_163_next:
                                                            // 
                                                            //     return False;
if_163_end:
if_162_next:
if_162_end:             loadi             (0);
                        if(always())      goto token_text_is_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_lookahead_text_is(char s[]) {
token_text_is_end:
return;	}
token_lookahead_text_is
(){
                                                            //     if (str_equals(token_lookahead_text, s)) {
                        loadi             (-1049867+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        str_equals();     
                        movebp            (-10);
                        if(equals())      goto if_164_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_lookahead_text_is_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_164_next:
if_164_end:             loadi             (0);
                        if(always())      goto token_lookahead_text_is_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_type_is(int t) {
token_lookahead_text_is_end:
return;	}
token_type_is
(){
                                                            //     if (token_type == t) {
                        load              (-1049350+global);
                        store             (1+BP);
                        load              (0+BP);
                        subtract          (1+BP);
                        if(equals())      goto compare_165_true;
                        loadi             (0);
                        if(always())      goto compare_165_false;
compare_165_true:       loadi             (1);
compare_165_false:      if(equals())      goto if_166_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_type_is_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_166_next:
if_166_end:             loadi             (0);
                        if(always())      goto token_type_is_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_lookahead_type_is(int t) {
token_type_is_end:
return;	}
token_lookahead_type_is
(){
                                                            //     if (token_lookahead_type == t) {
                        load              (-1049351+global);
                        store             (1+BP);
                        load              (0+BP);
                        subtract          (1+BP);
                        if(equals())      goto compare_167_true;
                        loadi             (0);
                        if(always())      goto compare_167_false;
compare_167_true:       loadi             (1);
compare_167_false:      if(equals())      goto if_168_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_lookahead_type_is_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_168_next:
if_168_end:             loadi             (0);
                        if(always())      goto token_lookahead_type_is_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_advance() {
token_lookahead_type_is_end:
return;	}
token_advance
(){
                                                            //     if (token_lookahead_line_no == 0) {
                        load              (-1049353+global);
                        store             (0+BP);
                        loadi             (0);
                        subtract          (0+BP);
                        if(equals())      goto compare_169_true;
                        loadi             (0);
                        if(always())      goto compare_169_false;
compare_169_true:       loadi             (1);
compare_169_false:      if(equals())      goto if_170_next;
                                                            //         token_get_next();
                        movebp            (8);
                        token_get_next(); 
                        movebp            (-8);
                                                            //     }
                                                            // 
                                                            //     copy(token_text,token_lookahead_text);
if_170_next:
if_170_end:             loadi             (-1049611+global);
                        store             (0+BP);
                        loadi             (-1049867+global);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            //     token_type = token_lookahead_type;
                        load              (-1049351+global);
                        store             (-1049350+global);
                                                            //     token_line_no = token_lookahead_line_no;
                        load              (-1049353+global);
                        store             (-1049352+global);
                                                            //     token_line_pos = token_lookahead_line_pos;
                        load              (-1049355+global);
                        store             (-1049354+global);
                                                            // 
                                                            //     error_set_line(token_line_no, token_line_pos);
                        load              (-1049352+global);
                        store             (0+BP);
                        load              (-1049354+global);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_set_line(); 
                        movebp            (-10);
                                                            // 
                                                            //     token_get_next();
                        movebp            (8);
                        token_get_next(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // token_advance_if(char s[]) {
token_advance_end:
return;	}
token_advance_if
(){
                                                            //     if (token_text_is(s)) {
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_text_is();  
                        movebp            (-9);
                        if(equals())      goto if_171_next;
                                                            //         token_advance();
                        movebp            (8);
                        token_advance();  
                        movebp            (-8);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto token_advance_if_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_171_next:
if_171_end:             loadi             (0);
                        if(always())      goto token_advance_if_end;
                                                            // }
                                                            // 
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "target_cvirtualmachine.h"
                                                            // #endif
                                                            // 
                                                            // // memory layout
                                                            // // the size local storage area (stack frames) is fixed
                                                            // // the size of the string table and global storage is allocated by the compiler
                                                            // // ---------------------------------------------------------------------------
                                                            // // | string table ------> | local storage -------> | <------- global storage |
                                                            // // ---------------------------------------------------------------------------
                                                            // enum {
token_advance_if_end:
return;	}
                                                            //     Target_local_storage_size = 1048576        // 1 * 1024 * 1024
                                                            // };
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // addressing modes
                                                            // enum {
                                                            //     Target_t_ix,
                                                            //     Target_t_local,
                                                            //     Target_t_local_ix,
                                                            //     Target_t_global,
                                                            //     Target_t_global_ix,
                                                            //     Target_t_indirect
                                                            // };
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // enum {
                                                            //     Target_string_table_size = 1048576        // 1 * 1024 * 1024
                                                            // };
                                                            // 
                                                            // int target_string_table_length;
                                                            // char target_string_table[Target_string_table_size];
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // char target_current_label[Str_size];
                                                            // 
                                                            // int target_label_sequence_no;
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_init() {
target_init
(){
                                                            // 
                                                            //     target_string_table_length = 0;
                        loadi             (0);
                        store             (-1049868+global);
                                                            //     copy(target_current_label, "");
                        loadi             (-2098700+global);
                        store             (0+BP);
                        loadi             (472);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            //     target_label_sequence_no = 0;
                        loadi             (0);
                        store             (-2098701+global);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // 
                                                            // target_program_begin() {
target_init_end:
return;	}
target_program_begin
(){
                                                            // 
                                                            //     writeln("#include <stdio.h>");
                        loadi             (473);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("#include <stdlib.h>");
                        loadi             (492);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (512);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("int A;");
                        loadi             (513);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("int X;");
                        loadi             (520);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("extern int BP;");
                        loadi             (527);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("extern int RAM[];");
                        loadi             (542);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (560);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("loadi       (int n) { A = n; }");
                        loadi             (561);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (592);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("load        (int n) { A = RAM[n]; }");
                        loadi             (593);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("store       (int n) { RAM[n] = A; }");
                        loadi             (629);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (665);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("add         (int n) { A += RAM[n]; }");
                        loadi             (666);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("subtract    (int n) { A -= RAM[n]; }");
                        loadi             (703);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("multiply    (int n) { A *= RAM[n]; }");
                        loadi             (740);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("divide      (int n) { A /= RAM[n]; }");
                        loadi             (777);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (814);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("loadx       ()      { X = A; }");
                        loadi             (815);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("movebp      (int n) { BP += n; }");
                        loadi             (846);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (879);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("less        ()      { return A > 0; }");
                        loadi             (880);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("greater     ()      { return A < 0; }");
                        loadi             (918);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("equals      ()      { return A == 0; }");
                        loadi             (956);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("notequals   ()      { return A != 0; }");
                        loadi             (995);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("always      ()      { return 1; }");
                        loadi             (1034);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (1068);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("extern int global;");
                        loadi             (1069);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("");
                        loadi             (1088);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // 
                                                            // target_program_end(int global_data_size) {
target_program_begin_end:
return;	}
target_program_end
(){
                                                            //     int i;
                                                            //     int ch;
                                                            //     char s[Str_size];
                                                            //     int memory_size;
                                                            // 
                                                            //     memory_size = target_string_table_length + Target_local_storage_size + global_data_size;
                        load              (-1049868+global);
                        store             (260+BP);
                        loadi             (1048576);
                        add               (260+BP);
                        store             (260+BP);
                        load              (0+BP);
                        add               (260+BP);
                        store             (259+BP);
                                                            // 
                                                            //     writeln("");
                        loadi             (1089);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            //     writeln("");
                        loadi             (1090);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            // 
                                                            //     write("int global = ");
                        loadi             (1091);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        write();          
                        movebp            (-268);
                                                            //     int_to_str(memory_size, s);
                        load              (259+BP);
                        store             (260+BP);
                        loadi             (3+BP);
                        store             (261+BP);
                        load              (261+BP);
                        store             (270+BP);
                        load              (260+BP);
                        store             (269+BP);
                        movebp            (269);
                        int_to_str();     
                        movebp            (-269);
                                                            //     write(s);
                        loadi             (3+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        write();          
                        movebp            (-268);
                                                            //     writeln(";");
                        loadi             (1105);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            //     writeln("");
                        loadi             (1107);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            // 
                                                            //     write("int BP = ");
                        loadi             (1108);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        write();          
                        movebp            (-268);
                                                            //     int_to_str(target_string_table_length, s);
                        load              (-1049868+global);
                        store             (260+BP);
                        loadi             (3+BP);
                        store             (261+BP);
                        load              (261+BP);
                        store             (270+BP);
                        load              (260+BP);
                        store             (269+BP);
                        movebp            (269);
                        int_to_str();     
                        movebp            (-269);
                                                            //     write(s);
                        loadi             (3+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        write();          
                        movebp            (-268);
                                                            //     writeln(";");
                        loadi             (1118);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            //     writeln("");
                        loadi             (1120);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            // 
                                                            //     write("int RAM[");
                        loadi             (1121);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        write();          
                        movebp            (-268);
                                                            //     int_to_str(memory_size, s);
                        load              (259+BP);
                        store             (260+BP);
                        loadi             (3+BP);
                        store             (261+BP);
                        load              (261+BP);
                        store             (270+BP);
                        load              (260+BP);
                        store             (269+BP);
                        movebp            (269);
                        int_to_str();     
                        movebp            (-269);
                                                            //     write(s);
                        loadi             (3+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        write();          
                        movebp            (-268);
                                                            //     writeln("] = {"); 
                        loadi             (1130);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            // 
                                                            //     i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            //     while (i < target_string_table_length) {
while_172_test:         load              (1+BP);
                        store             (260+BP);
                        load              (-1049868+global);
                        subtract          (260+BP);
                        if(less())        goto compare_173_true;
                        loadi             (0);
                        if(always())      goto compare_173_false;
compare_173_true:       loadi             (1);
compare_173_false:      if(equals())      goto while_172_end;
                                                            //         ch = target_string_table[i];
                        load              (1+BP);
                        loadx             ();
                        load              (-2098444+global+X);
                        store             (2+BP);
                                                            // 
                                                            //         if (ch == '\\' || ch == '\'' ) { 
                        load              (2+BP);
                        store             (260+BP);
                        loadi             (92);
                        subtract          (260+BP);
                        if(equals())      goto compare_174_true;
                        loadi             (0);
                        if(always())      goto compare_174_false;
compare_174_true:       loadi             (1);
compare_174_false:      if(notequals())   goto logical_or_175_true;
                        load              (2+BP);
                        store             (260+BP);
                        loadi             (39);
                        subtract          (260+BP);
                        if(equals())      goto compare_176_true;
                        loadi             (0);
                        if(always())      goto compare_176_false;
compare_176_true:       loadi             (1);
compare_176_false:      if(notequals())   goto logical_or_175_true;
                        loadi             (0);
                        if(always())      goto logical_or_175_false;
logical_or_175_true:    loadi             (1);
logical_or_175_false:   if(equals())      goto if_177_next;
                                                            //             copy(s, "'\\ '");
                        loadi             (3+BP);
                        store             (260+BP);
                        loadi             (1136);
                        store             (261+BP);
                        load              (261+BP);
                        store             (270+BP);
                        load              (260+BP);
                        store             (269+BP);
                        movebp            (269);
                        copy();           
                        movebp            (-269);
                                                            //             s[2] = ch;
                        loadi             (2);
                        store             (260+BP);
                        load              (2+BP);
                        store             (261+BP);
                        load              (260+BP);
                        loadx             ();
                        load              (261+BP);
                        store             (3+BP+X);
                                                            //         }
                                                            //         else if (ch >= ' ' && ch <= '~') {
                        if(always())      goto if_177_end;
if_177_next:            load              (2+BP);
                        store             (260+BP);
                        loadi             (32);
                        subtract          (260+BP);
                        if(greater())     goto compare_178_true;
                        if(equals())      goto compare_178_true;
                        loadi             (0);
                        if(always())      goto compare_178_false;
compare_178_true:       loadi             (1);
compare_178_false:      if(equals())      goto logical_and_179_false;
                        load              (2+BP);
                        store             (260+BP);
                        loadi             (126);
                        subtract          (260+BP);
                        if(less())        goto compare_180_true;
                        if(equals())      goto compare_180_true;
                        loadi             (0);
                        if(always())      goto compare_180_false;
compare_180_true:       loadi             (1);
compare_180_false:      if(equals())      goto logical_and_179_false;
                        loadi             (1);
                        if(always())      goto logical_and_179_true;
logical_and_179_false:  loadi             (0);
logical_and_179_true:   if(equals())      goto if_181_next;
                                                            //             copy(s, "' '");
                        loadi             (3+BP);
                        store             (260+BP);
                        loadi             (1141);
                        store             (261+BP);
                        load              (261+BP);
                        store             (270+BP);
                        load              (260+BP);
                        store             (269+BP);
                        movebp            (269);
                        copy();           
                        movebp            (-269);
                                                            //             s[1] = ch;
                        loadi             (1);
                        store             (260+BP);
                        load              (2+BP);
                        store             (261+BP);
                        load              (260+BP);
                        loadx             ();
                        load              (261+BP);
                        store             (3+BP+X);
                                                            //         }
                                                            //         else {
                        if(always())      goto if_181_end;
                                                            //             int_to_str(ch, s);
if_181_next:            load              (2+BP);
                        store             (260+BP);
                        loadi             (3+BP);
                        store             (261+BP);
                        load              (261+BP);
                        store             (270+BP);
                        load              (260+BP);
                        store             (269+BP);
                        movebp            (269);
                        int_to_str();     
                        movebp            (-269);
                                                            //         }
                                                            // 
                                                            //         i = i + 1;
if_181_end:
if_177_end:             load              (1+BP);
                        store             (260+BP);
                        loadi             (1);
                        add               (260+BP);
                        store             (1+BP);
                                                            //         if (i < target_string_table_length) {
                        load              (1+BP);
                        store             (260+BP);
                        load              (-1049868+global);
                        subtract          (260+BP);
                        if(less())        goto compare_182_true;
                        loadi             (0);
                        if(always())      goto compare_182_false;
compare_182_true:       loadi             (1);
compare_182_false:      if(equals())      goto if_183_next;
                                                            //             append(s, ",");
                        loadi             (3+BP);
                        store             (260+BP);
                        loadi             (1145);
                        store             (261+BP);
                        load              (261+BP);
                        store             (270+BP);
                        load              (260+BP);
                        store             (269+BP);
                        movebp            (269);
                        append();         
                        movebp            (-269);
                                                            //         }
                                                            // 
                                                            //         writeln(s);
if_183_next:
if_183_end:             loadi             (3+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            //     }
                                                            // 
                                                            //     writeln("};");
                        if(always())      goto while_172_test;
while_172_end:          loadi             (1147);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            //     writeln("");
                        loadi             (1150);
                        store             (260+BP);
                        load              (260+BP);
                        store             (268+BP);
                        movebp            (268);
                        writeln();        
                        movebp            (-268);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // 
                                                            // target_comment_print(char comment_block[]) {
target_program_end_end:
return;	}
target_comment_print
(){
                                                            //     int i;
                                                            //     char line[Str_size];
                                                            // 
                                                            //     i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            //     copy(line, "");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1151);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            // 
                                                            //     while (comment_block[i] != 0) {
while_184_test:         load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (258+BP);
                        load              (0+BP);
                        add               (258+BP);
                        loadx             ();
                        load              (X);
                        store             (258+BP);
                        loadi             (0);
                        subtract          (258+BP);
                        if(notequals())   goto compare_185_true;
                        loadi             (0);
                        if(always())      goto compare_185_false;
compare_185_true:       loadi             (1);
compare_185_false:      if(equals())      goto while_184_end;
                                                            // 
                                                            //         if (str_equals(line, "")) {
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1152);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        str_equals();     
                        movebp            (-267);
                        if(equals())      goto if_186_next;
                                                            //             fill_until_col(line, 60);
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (60);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        fill_until_col(); 
                        movebp            (-267);
                                                            //             append(line, "// ");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1153);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        append();         
                        movebp            (-267);
                                                            //         }
                                                            // 
                                                            //         if (comment_block[i] != '\n') {
if_186_next:
if_186_end:             load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (258+BP);
                        load              (0+BP);
                        add               (258+BP);
                        loadx             ();
                        load              (X);
                        store             (258+BP);
                        loadi             (10);
                        subtract          (258+BP);
                        if(notequals())   goto compare_187_true;
                        loadi             (0);
                        if(always())      goto compare_187_false;
compare_187_true:       loadi             (1);
compare_187_false:      if(equals())      goto if_188_next;
                                                            //             append_char(line, comment_block[i]);
                        loadi             (2+BP);
                        store             (258+BP);
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (259+BP);
                        load              (0+BP);
                        add               (259+BP);
                        loadx             ();
                        load              (X);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        append_char();    
                        movebp            (-267);
                                                            //         }
                                                            // 
                                                            //         if (comment_block[i] == '\n' || comment_block[i + 1] == 0) {
if_188_next:
if_188_end:             load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (258+BP);
                        load              (0+BP);
                        add               (258+BP);
                        loadx             ();
                        load              (X);
                        store             (258+BP);
                        loadi             (10);
                        subtract          (258+BP);
                        if(equals())      goto compare_189_true;
                        loadi             (0);
                        if(always())      goto compare_189_false;
compare_189_true:       loadi             (1);
compare_189_false:      if(notequals())   goto logical_or_190_true;
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (1);
                        add               (258+BP);
                        loadx             ();
                        loadi             (X);
                        store             (258+BP);
                        load              (0+BP);
                        add               (258+BP);
                        loadx             ();
                        load              (X);
                        store             (258+BP);
                        loadi             (0);
                        subtract          (258+BP);
                        if(equals())      goto compare_191_true;
                        loadi             (0);
                        if(always())      goto compare_191_false;
compare_191_true:       loadi             (1);
compare_191_false:      if(notequals())   goto logical_or_190_true;
                        loadi             (0);
                        if(always())      goto logical_or_190_false;
logical_or_190_true:    loadi             (1);
logical_or_190_false:   if(equals())      goto if_192_next;
                                                            //             writeln(line);
                        loadi             (2+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        writeln();        
                        movebp            (-266);
                                                            //             copy(line, "");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1157);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //         }
                                                            // 
                                                            //         i = i + 1;
if_192_next:
if_192_end:             load              (1+BP);
                        store             (258+BP);
                        loadi             (1);
                        add               (258+BP);
                        store             (1+BP);
                                                            //     }
                                                            // }
                        if(always())      goto while_184_test;
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // 
                                                            // target_instruction_print_line(char field1[], char field2[]) {
while_184_end:
target_comment_print_end:
return;	}
target_instruction_print_line
(){
                                                            //     char line[Str_size];
                                                            // 
                                                            //     copy(line, "");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1158);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            // 
                                                            //     if (! str_equals(target_current_label, "")) {
                        loadi             (-2098700+global);
                        store             (258+BP);
                        loadi             (1159);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        str_equals();     
                        movebp            (-266);
                        if(notequals())   goto logical_not_193_false;
                        loadi             (1);
                        if(always())      goto logical_not_193_true;
logical_not_193_false:  loadi             (0);
logical_not_193_true:   if(equals())      goto if_194_next;
                                                            //         copy(line, target_current_label);
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (-2098700+global);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //         append(line, ":");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1160);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 
                                                            //         copy(target_current_label, "");
                        loadi             (-2098700+global);
                        store             (258+BP);
                        loadi             (1162);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //     }
                                                            // 
                                                            //     append(line, " ");
if_194_next:
if_194_end:             loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1163);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            //     fill_until_col(line, 24);
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (24);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        fill_until_col(); 
                        movebp            (-266);
                                                            // 
                                                            //     append(line, field1);
                        loadi             (2+BP);
                        store             (258+BP);
                        load              (0+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            //     append(line, " ");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1165);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            //     fill_until_col(line, 42);
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (42);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        fill_until_col(); 
                        movebp            (-266);
                                                            //     append(line, field2);
                        loadi             (2+BP);
                        store             (258+BP);
                        load              (1+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 
                                                            //     writeln(line);
                        loadi             (2+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_instruction_branch(char condition[], char label[], char label_postfix[]) {
target_instruction_print_line_end:
return;	}
target_instruction_branch
(){
                                                            //     char instruction[Str_size];
                                                            //     char operand_field[Str_size];
                                                            // 
                                                            //     copy(instruction, "if(");
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1167);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        copy();           
                        movebp            (-522);
                                                            //     append(instruction, condition);
                        loadi             (3+BP);
                        store             (515+BP);
                        load              (0+BP);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //     append(instruction, "())");
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1171);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //         
                                                            //     copy(operand_field, "goto ");
                        loadi             (259+BP);
                        store             (515+BP);
                        loadi             (1175);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        copy();           
                        movebp            (-522);
                                                            //     append(operand_field, label);
                        loadi             (259+BP);
                        store             (515+BP);
                        load              (1+BP);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //     append(operand_field, label_postfix);
                        loadi             (259+BP);
                        store             (515+BP);
                        load              (2+BP);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //     append(operand_field, ";");
                        loadi             (259+BP);
                        store             (515+BP);
                        loadi             (1181);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            // 
                                                            //     target_instruction_print_line(instruction, operand_field);
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (259+BP);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        target_instruction_print_line(); 
                        movebp            (-522);
                                                            // }
                                                            // 
                                                            // target_instruction_memory_operand(char instruction[], int operand, int address_mode) {
target_instruction_branch_end:
return;	}
target_instruction_memory_operand
(){
                                                            //     char operand_str[Str_size];
                                                            //     char operand_field[Str_size];
                                                            // 
                                                            //     int_to_str(operand, operand_str);
                        load              (1+BP);
                        store             (515+BP);
                        loadi             (3+BP);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        int_to_str();     
                        movebp            (-522);
                                                            // 
                                                            //     if (address_mode == Target_t_global) {
                        load              (2+BP);
                        store             (515+BP);
                        loadi             (3);
                        subtract          (515+BP);
                        if(equals())      goto compare_195_true;
                        loadi             (0);
                        if(always())      goto compare_195_false;
compare_195_true:       loadi             (1);
compare_195_false:      if(equals())      goto if_196_next;
                                                            //         if (operand < 0) {
                        load              (1+BP);
                        store             (515+BP);
                        loadi             (0);
                        subtract          (515+BP);
                        if(less())        goto compare_197_true;
                        loadi             (0);
                        if(always())      goto compare_197_false;
compare_197_true:       loadi             (1);
compare_197_false:      if(equals())      goto if_198_next;
                                                            //             append(operand_str, "+global");
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1183);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //         }
                                                            //     } else if (address_mode == Target_t_global_ix) {
if_198_next:
if_198_end:             if(always())      goto if_196_end;
if_196_next:            load              (2+BP);
                        store             (515+BP);
                        loadi             (4);
                        subtract          (515+BP);
                        if(equals())      goto compare_199_true;
                        loadi             (0);
                        if(always())      goto compare_199_false;
compare_199_true:       loadi             (1);
compare_199_false:      if(equals())      goto if_200_next;
                                                            //         if (operand < 0) {
                        load              (1+BP);
                        store             (515+BP);
                        loadi             (0);
                        subtract          (515+BP);
                        if(less())        goto compare_201_true;
                        loadi             (0);
                        if(always())      goto compare_201_false;
compare_201_true:       loadi             (1);
compare_201_false:      if(equals())      goto if_202_next;
                                                            //             append(operand_str, "+global");
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1191);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //         }
                                                            //         append(operand_str, "+X");
if_202_next:
if_202_end:             loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1199);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            // 
                                                            //     } else if (address_mode == Target_t_local) {
                        if(always())      goto if_200_end;
if_200_next:            load              (2+BP);
                        store             (515+BP);
                        loadi             (1);
                        subtract          (515+BP);
                        if(equals())      goto compare_203_true;
                        loadi             (0);
                        if(always())      goto compare_203_false;
compare_203_true:       loadi             (1);
compare_203_false:      if(equals())      goto if_204_next;
                                                            //         append(operand_str, "+BP");
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1202);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            // 
                                                            //     } else if (address_mode == Target_t_local_ix) {
                        if(always())      goto if_204_end;
if_204_next:            load              (2+BP);
                        store             (515+BP);
                        loadi             (2);
                        subtract          (515+BP);
                        if(equals())      goto compare_205_true;
                        loadi             (0);
                        if(always())      goto compare_205_false;
compare_205_true:       loadi             (1);
compare_205_false:      if(equals())      goto if_206_next;
                                                            //         append(operand_str, "+BP+X");
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1206);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            // 
                                                            //     } else if (address_mode == Target_t_ix || address_mode == Target_t_indirect) {
                        if(always())      goto if_206_end;
if_206_next:            load              (2+BP);
                        store             (515+BP);
                        loadi             (0);
                        subtract          (515+BP);
                        if(equals())      goto compare_207_true;
                        loadi             (0);
                        if(always())      goto compare_207_false;
compare_207_true:       loadi             (1);
compare_207_false:      if(notequals())   goto logical_or_208_true;
                        load              (2+BP);
                        store             (515+BP);
                        loadi             (5);
                        subtract          (515+BP);
                        if(equals())      goto compare_209_true;
                        loadi             (0);
                        if(always())      goto compare_209_false;
compare_209_true:       loadi             (1);
compare_209_false:      if(notequals())   goto logical_or_208_true;
                        loadi             (0);
                        if(always())      goto logical_or_208_false;
logical_or_208_true:    loadi             (1);
logical_or_208_false:   if(equals())      goto if_210_next;
                                                            //         copy(operand_str, "X");
                        loadi             (3+BP);
                        store             (515+BP);
                        loadi             (1212);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        copy();           
                        movebp            (-522);
                                                            // 
                                                            //     } else {
                        if(always())      goto if_210_end;
                                                            //         error_internal();
if_210_next:            movebp            (520);
                        error_internal(); 
                        movebp            (-520);
                                                            //     }
                                                            // 
                                                            //     copy(operand_field, "(");
if_210_end:
if_206_end:
if_204_end:
if_200_end:
if_196_end:             loadi             (259+BP);
                        store             (515+BP);
                        loadi             (1214);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        copy();           
                        movebp            (-522);
                                                            //     append(operand_field, operand_str);
                        loadi             (259+BP);
                        store             (515+BP);
                        loadi             (3+BP);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //     append(operand_field, ");");
                        loadi             (259+BP);
                        store             (515+BP);
                        loadi             (1216);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            // 
                                                            //     target_instruction_print_line(instruction, operand_field);
                        load              (0+BP);
                        store             (515+BP);
                        loadi             (259+BP);
                        store             (516+BP);
                        load              (516+BP);
                        store             (523+BP);
                        load              (515+BP);
                        store             (522+BP);
                        movebp            (522);
                        target_instruction_print_line(); 
                        movebp            (-522);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_instruction_operand(char instruction[], int operand) {
target_instruction_memory_operand_end:
return;	}
target_instruction_operand
(){
                                                            //     char operand_str[Str_size];
                                                            //     char operand_field[Str_size];
                                                            // 
                                                            //     int_to_str(operand, operand_str);
                        load              (1+BP);
                        store             (514+BP);
                        loadi             (2+BP);
                        store             (515+BP);
                        load              (515+BP);
                        store             (523+BP);
                        load              (514+BP);
                        store             (522+BP);
                        movebp            (522);
                        int_to_str();     
                        movebp            (-522);
                                                            // 
                                                            //     copy(operand_field, "(");
                        loadi             (258+BP);
                        store             (514+BP);
                        loadi             (1219);
                        store             (515+BP);
                        load              (515+BP);
                        store             (523+BP);
                        load              (514+BP);
                        store             (522+BP);
                        movebp            (522);
                        copy();           
                        movebp            (-522);
                                                            //     append(operand_field, operand_str);
                        loadi             (258+BP);
                        store             (514+BP);
                        loadi             (2+BP);
                        store             (515+BP);
                        load              (515+BP);
                        store             (523+BP);
                        load              (514+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            //     append(operand_field, ");");
                        loadi             (258+BP);
                        store             (514+BP);
                        loadi             (1221);
                        store             (515+BP);
                        load              (515+BP);
                        store             (523+BP);
                        load              (514+BP);
                        store             (522+BP);
                        movebp            (522);
                        append();         
                        movebp            (-522);
                                                            // 
                                                            //     target_instruction_print_line(instruction, operand_field);
                        load              (0+BP);
                        store             (514+BP);
                        loadi             (258+BP);
                        store             (515+BP);
                        load              (515+BP);
                        store             (523+BP);
                        load              (514+BP);
                        store             (522+BP);
                        movebp            (522);
                        target_instruction_print_line(); 
                        movebp            (-522);
                                                            // }
                                                            // 
                                                            // target_instruction(char instruction[]) {
target_instruction_operand_end:
return;	}
target_instruction
(){
                                                            // 
                                                            //     target_instruction_print_line(instruction, "();");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1224);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_instruction_print_line(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_op_branch(char label[], char postfix[]) {
target_instruction_end:
return;	}
target_op_branch
(){
                                                            //     target_instruction_branch("always", label, postfix);
                        loadi             (1228);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_branch(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_branch_back(char label[], char postfix[]) {
target_op_branch_end:
return;	}
target_op_branch_back
(){
                                                            //     target_instruction_branch("always", label, postfix);
                        loadi             (1235);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_branch(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_branch_if_less(char label[], char postfix[]) {
target_op_branch_back_end:
return;	}
target_op_branch_if_less
(){
                                                            //     target_instruction_branch("less", label, postfix);
                        loadi             (1242);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_branch(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_branch_if_greater(char label[], char postfix[]) {
target_op_branch_if_less_end:
return;	}
target_op_branch_if_greater
(){
                                                            //     target_instruction_branch("greater", label, postfix);
                        loadi             (1247);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_branch(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_branch_if_equals(char label[], char postfix[]) {
target_op_branch_if_greater_end:
return;	}
target_op_branch_if_equals
(){
                                                            //     target_instruction_branch("equals", label, postfix);
                        loadi             (1255);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_branch(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_branch_if_not_equals(char label[], char postfix[]) {
target_op_branch_if_equals_end:
return;	}
target_op_branch_if_not_equals
(){
                                                            //     target_instruction_branch("notequals", label, postfix);
                        loadi             (1262);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_branch(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_branch_if_true(char label[], char postfix[]) {
target_op_branch_if_not_equals_end:
return;	}
target_op_branch_if_true
(){
                                                            //     target_op_branch_if_not_equals(label, postfix);
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_not_equals(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // target_op_branch_if_false(char label[], char postfix[]) {
target_op_branch_if_true_end:
return;	}
target_op_branch_if_false
(){
                                                            //     target_op_branch_if_equals(label, postfix);
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_equals(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // 
                                                            // target_op_loadx() {
target_op_branch_if_false_end:
return;	}
target_op_loadx
(){
                                                            //     target_instruction("loadx");
                        loadi             (1272);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_instruction(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // target_op_load_constant(int operand) {
target_op_loadx_end:
return;	}
target_op_load_constant
(){
                                                            //     target_instruction_operand("loadi", operand);
                        loadi             (1278);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_instruction_operand(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // target_op_load_address(int operand, int address_mode_type) {
target_op_load_constant_end:
return;	}
target_op_load_address
(){
                                                            //     target_instruction_memory_operand("loadi", operand, address_mode_type);
                        loadi             (1284);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_load(int operand, int address_mode_type) {
target_op_load_address_end:
return;	}
target_op_load
(){
                                                            //     target_instruction_memory_operand("load", operand, address_mode_type);
                        loadi             (1290);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_store(int operand, int address_mode_type) {
target_op_load_end:
return;	}
target_op_store
(){
                                                            //     target_instruction_memory_operand("store", operand, address_mode_type);
                        loadi             (1295);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_add(int operand, int address_mode_type) {
target_op_store_end:
return;	}
target_op_add
(){
                                                            //     target_instruction_memory_operand("add", operand, address_mode_type);
                        loadi             (1301);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_subtract(int operand, int address_mode_type) {
target_op_add_end:
return;	}
target_op_subtract
(){
                                                            //     target_instruction_memory_operand("subtract", operand, address_mode_type);
                        loadi             (1305);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_multiply (int operand, int address_mode_type) {
target_op_subtract_end:
return;	}
target_op_multiply
(){
                                                            //     target_instruction_memory_operand("multiply", operand, address_mode_type);
                        loadi             (1314);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_divide(int operand, int address_mode_type) {
target_op_multiply_end:
return;	}
target_op_divide
(){
                                                            //     target_instruction_memory_operand("divide", operand, address_mode_type);
                        loadi             (1323);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // target_op_test() {
target_op_divide_end:
return;	}
target_op_test
(){
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_op_subroutine_begin(char function_name[], int argument_count, int local_frame_size) {
target_op_test_end:
return;	}
target_op_subroutine_begin
(){
                                                            // 
                                                            //     writeln(function_name);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     writeln("(){");
                        loadi             (1330);
                        store             (3+BP);
                        load              (3+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // target_op_subroutine_end(char function_name[], int argument_count, int local_frame_size) {
target_op_subroutine_begin_end:
return;	}
target_op_subroutine_end
(){
                                                            // 
                                                            //     target_emit_label("", "");
                        loadi             (1334);
                        store             (3+BP);
                        loadi             (1335);
                        store             (4+BP);
                        load              (4+BP);
                        store             (11+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_emit_label(); 
                        movebp            (-10);
                                                            //     writeln("return;	}");
                        loadi             (1336);
                        store             (3+BP);
                        load              (3+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // target_op_call_subroutine(char function_name[], int argument_count, int local_frame_size) {
target_op_subroutine_end_end:
return;	}
target_op_call_subroutine
(){
                                                            //     char instruction_field[Str_size];
                                                            // 
                                                            //     target_instruction_operand("movebp", argument_count + local_frame_size);
                        loadi             (1346);
                        store             (259+BP);
                        load              (1+BP);
                        store             (260+BP);
                        load              (2+BP);
                        add               (260+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (267+BP);
                        load              (259+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_instruction_operand(); 
                        movebp            (-266);
                                                            // 
                                                            //     copy(instruction_field, function_name);
                        loadi             (3+BP);
                        store             (259+BP);
                        load              (0+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (267+BP);
                        load              (259+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //     append(instruction_field, "();");
                        loadi             (3+BP);
                        store             (259+BP);
                        loadi             (1353);
                        store             (260+BP);
                        load              (260+BP);
                        store             (267+BP);
                        load              (259+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            //     target_instruction_print_line(instruction_field, "");
                        loadi             (3+BP);
                        store             (259+BP);
                        loadi             (1357);
                        store             (260+BP);
                        load              (260+BP);
                        store             (267+BP);
                        load              (259+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_instruction_print_line(); 
                        movebp            (-266);
                                                            // 
                                                            //     target_instruction_operand("movebp", -(argument_count + local_frame_size));
                        loadi             (1358);
                        store             (259+BP);
                        load              (1+BP);
                        store             (260+BP);
                        load              (2+BP);
                        add               (260+BP);
                        store             (260+BP);
                        loadi             (0);
                        subtract          (260+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (267+BP);
                        load              (259+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_instruction_operand(); 
                        movebp            (-266);
                                                            // 
                                                            // }
                                                            // 
                                                            // target_op_pass_argument(int argument_no, int argument_count, int local_frame_size) {
target_op_call_subroutine_end:
return;	}
target_op_pass_argument
(){
                                                            // 
                                                            //     target_instruction_memory_operand("store", (argument_count + local_frame_size) + (argument_no - 1), Target_t_local);
                        loadi             (1365);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (2+BP);
                        add               (4+BP);
                        store             (4+BP);
                        load              (0+BP);
                        store             (5+BP);
                        loadi             (1);
                        store             (6+BP);
                        load              (5+BP);
                        subtract          (6+BP);
                        add               (4+BP);
                        store             (4+BP);
                        loadi             (1);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_instruction_memory_operand(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_emit_label(char label[], char label_postfix[]) {
target_op_pass_argument_end:
return;	}
target_emit_label
(){
                                                            // 
                                                            //     if (! str_equals(target_current_label, "")) {
                        loadi             (-2098700+global);
                        store             (2+BP);
                        loadi             (1371);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        str_equals();     
                        movebp            (-10);
                        if(notequals())   goto logical_not_211_false;
                        loadi             (1);
                        if(always())      goto logical_not_211_true;
logical_not_211_false:  loadi             (0);
logical_not_211_true:   if(equals())      goto if_212_next;
                                                            //         write(target_current_label);
                        loadi             (-2098700+global);
                        store             (2+BP);
                        load              (2+BP);
                        store             (9+BP);
                        movebp            (9);
                        write();          
                        movebp            (-9);
                                                            //         writeln(":");
                        loadi             (1372);
                        store             (2+BP);
                        load              (2+BP);
                        store             (9+BP);
                        movebp            (9);
                        writeln();        
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     copy(target_current_label, label);
if_212_next:
if_212_end:             loadi             (-2098700+global);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            //     append(target_current_label, label_postfix);
                        loadi             (-2098700+global);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        append();         
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_begin_branch_block(char label[], char label_postfix[]) {
target_emit_label_end:
return;	}
target_begin_branch_block
(){
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_end_branch_block(char label[], char label_postfix[]) {
target_begin_branch_block_end:
return;	}
target_end_branch_block
(){
                                                            //     target_emit_label(label, label_postfix);
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_emit_label(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_begin_back_branch_block(char label[], char label_postfix[]) {
target_end_branch_block_end:
return;	}
target_begin_back_branch_block
(){
                                                            //     target_emit_label(label, label_postfix);
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_emit_label(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_end_back_branch_block(char label[], char label_postfix[]) {
target_begin_back_branch_block_end:
return;	}
target_end_back_branch_block
(){
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_built_in_function_debug() {
target_end_back_branch_block_end:
return;	}
target_built_in_function_debug
(){
                                                            // 
                                                            //     target_instruction_print_line("printf", "(\"%d\\n\", A);");
                        loadi             (1374);
                        store             (0+BP);
                        loadi             (1381);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_instruction_print_line(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // target_built_in_function_exit() {
target_built_in_function_debug_end:
return;	}
target_built_in_function_exit
(){
                                                            // 
                                                            //     target_instruction_print_line("exit", "(A);");
                        loadi             (1394);
                        store             (0+BP);
                        loadi             (1399);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_instruction_print_line(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // target_built_in_function_fgetc() {
target_built_in_function_exit_end:
return;	}
target_built_in_function_fgetc
(){
                                                            // 
                                                            //     target_instruction_print_line("A=fgetc", "(stdin);");
                        loadi             (1404);
                        store             (0+BP);
                        loadi             (1412);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_instruction_print_line(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // target_built_in_function_fputc_stdout() {
target_built_in_function_fgetc_end:
return;	}
target_built_in_function_fputc_stdout
(){
                                                            // 
                                                            //     target_instruction_print_line("fputc", "(A, stdout);");
                        loadi             (1421);
                        store             (0+BP);
                        loadi             (1427);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_instruction_print_line(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // target_built_in_function_fputc_stderr() {
target_built_in_function_fputc_stdout_end:
return;	}
target_built_in_function_fputc_stderr
(){
                                                            // 
                                                            //     target_instruction_print_line("fputc", "(A, stderr);");
                        loadi             (1440);
                        store             (0+BP);
                        loadi             (1446);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_instruction_print_line(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_allocate_string(char string[], int string_length) {
target_built_in_function_fputc_stderr_end:
return;	}
target_allocate_string
(){
                                                            //     int i;
                                                            //     int address;
                                                            // 
                                                            //     if (target_string_table_length + string_length > Target_string_table_size) {
                        load              (-1049868+global);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        store             (4+BP);
                        loadi             (1048576);
                        subtract          (4+BP);
                        if(greater())     goto compare_213_true;
                        loadi             (0);
                        if(always())      goto compare_213_false;
compare_213_true:       loadi             (1);
compare_213_false:      if(equals())      goto if_214_next;
                                                            //         error_target("out of initialised (string) storage space");
                        loadi             (1459);
                        store             (4+BP);
                        load              (4+BP);
                        store             (11+BP);
                        movebp            (11);
                        error_target();   
                        movebp            (-11);
                                                            //     }
                                                            // 
                                                            //     i = 0;
if_214_next:
if_214_end:             loadi             (0);
                        store             (2+BP);
                                                            //     while(i <= string_length) {
while_215_test:         load              (2+BP);
                        store             (4+BP);
                        load              (1+BP);
                        subtract          (4+BP);
                        if(less())        goto compare_216_true;
                        if(equals())      goto compare_216_true;
                        loadi             (0);
                        if(always())      goto compare_216_false;
compare_216_true:       loadi             (1);
compare_216_false:      if(equals())      goto while_215_end;
                                                            //         target_string_table[target_string_table_length + i] = string[i];
                        load              (-1049868+global);
                        store             (4+BP);
                        load              (2+BP);
                        add               (4+BP);
                        store             (4+BP);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (5+BP);
                        load              (0+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (X);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (-2098444+global+X);
                                                            //         i = i + 1;
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (2+BP);
                                                            //     }
                                                            // 
                                                            //     address = target_string_table_length;
                        if(always())      goto while_215_test;
while_215_end:          load              (-1049868+global);
                        store             (3+BP);
                                                            //     target_string_table_length = target_string_table_length + string_length;
                        load              (-1049868+global);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        store             (-1049868+global);
                                                            // 
                                                            //     return address;
                        load              (3+BP);
                        if(always())      goto target_allocate_string_end;
                                                            // }
                                                            // 
                                                            // target_allocate_global_address(int offset, int var_size) {
target_allocate_string_end:
return;	}
target_allocate_global_address
(){
                                                            //     
                                                            //     return -offset - var_size;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (0);
                        subtract          (2+BP);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (2+BP);
                        subtract          (3+BP);
                        if(always())      goto target_allocate_global_address_end;
                                                            // }
                                                            // 
                                                            // target_allocate_local_address(int offset, int var_size, int function_argument_count) {
target_allocate_global_address_end:
return;	}
target_allocate_local_address
(){
                                                            // 
                                                            //     return function_argument_count + offset;
                        load              (2+BP);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        if(always())      goto target_allocate_local_address_end;
                                                            // }
                                                            // 
                                                            // target_allocate_function_argument_address(int argument_no, int var_size) {
target_allocate_local_address_end:
return;	}
target_allocate_function_argument_address
(){
                                                            // 
                                                            //     return argument_no - 1;
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (2+BP);
                        subtract          (3+BP);
                        if(always())      goto target_allocate_function_argument_address_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // target_get_label(char start_with[], char out_label[]) {
target_allocate_function_argument_address_end:
return;	}
target_get_label
(){
                                                            //     char sequence_no_str[Str_size];
                                                            // 
                                                            //     int_to_str(target_label_sequence_no, sequence_no_str);
                        load              (-2098701+global);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                                                            //     copy(out_label, start_with);
                        load              (1+BP);
                        store             (258+BP);
                        load              (0+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //     append(out_label, "_");
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (1501);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            //     append(out_label, sequence_no_str);
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 
                                                            //     target_label_sequence_no = target_label_sequence_no + 1;
                        load              (-2098701+global);
                        store             (258+BP);
                        loadi             (1);
                        add               (258+BP);
                        store             (-2098701+global);
                                                            // }
                                                            // 
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "compiler.h"
                                                            // #endif
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // enum {
target_get_label_end:
return;	}
                                                            //     Compiler_t_integer_pointer,
                                                            //     Compiler_t_integer,
                                                            //     Compiler_t_integer_array,
                                                            //     Compiler_t_integer_constant,
                                                            //     Compiler_t_function
                                                            // };
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // enum {
                                                            //     Compiler_t_global,
                                                            //     Compiler_t_local
                                                            // };
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // 
                                                            // enum {
                                                            //     Compiler_max_identifiers = 8192
                                                            // };
                                                            // 
                                                            // int compiler_col_value[Compiler_max_identifiers];
                                                            // int compiler_col_type[Compiler_max_identifiers];
                                                            // char compiler_col_name[2097152];   // Compiler_max_identifiers * Str_size
                                                            // char compiler_col_parent[2097152]; // Compiler_max_identifiers * Str_size
                                                            // 
                                                            // int compiler_identifier_table_size;
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // char compiler_function_name[Str_size];
                                                            // int compiler_function_argument_count;
                                                            // int compiler_function_local_data_size;
                                                            // int compiler_function_temp_data_size;
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // int compiler_global_data_size;
                                                            // 
                                                            // enum {
                                                            //     Compiler_max_temp_data_size = 8
                                                            // };
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // char compiler_source_chunk[Source_buffer_length];
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // int compiler_current_enum_value;
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // int compiler_label_sequence_no;
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_init() {
compiler_init
(){
                                                            // 
                                                            //     compiler_identifier_table_size = 0;
                        loadi             (0);
                        store             (-6309390+global);
                                                            //     compiler_global_data_size = 0;
                        loadi             (0);
                        store             (-6309650+global);
                                                            // 
                                                            //     compiler_current_enum_value = 0;
                        loadi             (0);
                        store             (-7358227+global);
                                                            //     compiler_label_sequence_no = 0;
                        loadi             (0);
                        store             (-7358228+global);
                                                            // 
                                                            //     copy(compiler_function_name, "");
                        loadi             (-6309646+global);
                        store             (0+BP);
                        loadi             (1503);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            //     compiler_function_argument_count = 0;
                        loadi             (0);
                        store             (-6309647+global);
                                                            //     compiler_function_local_data_size = 0;
                        loadi             (0);
                        store             (-6309648+global);
                                                            //     compiler_function_temp_data_size = 0;
                        loadi             (0);
                        store             (-6309649+global);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // compiler_get_current_scope() {
compiler_init_end:
return;	}
compiler_get_current_scope
(){
                                                            //     if (! str_equals(compiler_function_name, "")) {
                        loadi             (-6309646+global);
                        store             (0+BP);
                        loadi             (1504);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        str_equals();     
                        movebp            (-10);
                        if(notequals())   goto logical_not_217_false;
                        loadi             (1);
                        if(always())      goto logical_not_217_true;
logical_not_217_false:  loadi             (0);
logical_not_217_true:   if(equals())      goto if_218_next;
                                                            //         return Compiler_t_local;
                        loadi             (1);
                        if(always())      goto compiler_get_current_scope_end;
                                                            //     }
                                                            // 
                                                            //     return Compiler_t_global;
if_218_next:
if_218_end:             loadi             (0);
                        if(always())      goto compiler_get_current_scope_end;
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // compiler_find_identifier_with_parent(char name[], char parent[], int out_value[], int out_type[]) {
compiler_get_current_scope_end:
return;	}
compiler_find_identifier_with_parent
(){
                                                            //     int i;
                                                            //     char str[Str_size];
                                                            // 
                                                            //     i = 0;
                        loadi             (0);
                        store             (4+BP);
                                                            //     while (i < compiler_identifier_table_size) {
while_219_test:         load              (4+BP);
                        store             (261+BP);
                        load              (-6309390+global);
                        subtract          (261+BP);
                        if(less())        goto compare_220_true;
                        loadi             (0);
                        if(always())      goto compare_220_false;
compare_220_true:       loadi             (1);
compare_220_false:      if(equals())      goto while_219_end;
                                                            //         copy_from(str, compiler_col_name, i * Str_size);
                        loadi             (5+BP);
                        store             (261+BP);
                        loadi             (-4212237+global);
                        store             (262+BP);
                        load              (4+BP);
                        store             (263+BP);
                        loadi             (256);
                        multiply          (263+BP);
                        store             (263+BP);
                        load              (263+BP);
                        store             (270+BP);
                        load              (262+BP);
                        store             (269+BP);
                        load              (261+BP);
                        store             (268+BP);
                        movebp            (268);
                        copy_from();      
                        movebp            (-268);
                                                            //         if (str_equals(str, name)) {
                        loadi             (5+BP);
                        store             (261+BP);
                        load              (0+BP);
                        store             (262+BP);
                        load              (262+BP);
                        store             (268+BP);
                        load              (261+BP);
                        store             (267+BP);
                        movebp            (267);
                        str_equals();     
                        movebp            (-267);
                        if(equals())      goto if_221_next;
                                                            //             out_value[0] = compiler_col_value[i];
                        loadi             (0);
                        store             (261+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (-2106893+global+X);
                        store             (262+BP);
                        load              (261+BP);
                        loadx             ();
                        load              (262+BP);
                        store             (261+BP);
                        loadi             (X);
                        store             (262+BP);
                        load              (2+BP);
                        add               (262+BP);
                        loadx             ();
                        load              (261+BP);
                        store             (X);
                                                            //             out_type[0] = compiler_col_type[i];
                        loadi             (0);
                        store             (261+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (-2115085+global+X);
                        store             (262+BP);
                        load              (261+BP);
                        loadx             ();
                        load              (262+BP);
                        store             (261+BP);
                        loadi             (X);
                        store             (262+BP);
                        load              (3+BP);
                        add               (262+BP);
                        loadx             ();
                        load              (261+BP);
                        store             (X);
                                                            //             copy_from(str, compiler_col_parent, i * Str_size);
                        loadi             (5+BP);
                        store             (261+BP);
                        loadi             (-6309389+global);
                        store             (262+BP);
                        load              (4+BP);
                        store             (263+BP);
                        loadi             (256);
                        multiply          (263+BP);
                        store             (263+BP);
                        load              (263+BP);
                        store             (270+BP);
                        load              (262+BP);
                        store             (269+BP);
                        load              (261+BP);
                        store             (268+BP);
                        movebp            (268);
                        copy_from();      
                        movebp            (-268);
                                                            //             if (str_equals(str, parent)) {
                        loadi             (5+BP);
                        store             (261+BP);
                        load              (1+BP);
                        store             (262+BP);
                        load              (262+BP);
                        store             (268+BP);
                        load              (261+BP);
                        store             (267+BP);
                        movebp            (267);
                        str_equals();     
                        movebp            (-267);
                        if(equals())      goto if_222_next;
                                                            //                 return True;
                        loadi             (1);
                        if(always())      goto compiler_find_identifier_with_parent_end;
                                                            //             }
                                                            //         }
if_222_next:
                                                            //         i = i + 1;
if_222_end:
if_221_next:
if_221_end:             load              (4+BP);
                        store             (261+BP);
                        loadi             (1);
                        add               (261+BP);
                        store             (4+BP);
                                                            //     }
                                                            // 
                                                            //     return False;
                        if(always())      goto while_219_test;
while_219_end:          loadi             (0);
                        if(always())      goto compiler_find_identifier_with_parent_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_find_identifier(char name[], int out_value[], int out_type[], int out_scope[]) {
compiler_find_identifier_with_parent_end:
return;	}
compiler_find_identifier
(){
                                                            // 
                                                            //     if (compiler_get_current_scope() == Compiler_t_local) {
                        movebp            (8);
                        compiler_get_current_scope(); 
                        movebp            (-8);
                        store             (4+BP);
                        loadi             (1);
                        subtract          (4+BP);
                        if(equals())      goto compare_223_true;
                        loadi             (0);
                        if(always())      goto compare_223_false;
compare_223_true:       loadi             (1);
compare_223_false:      if(equals())      goto if_224_next;
                                                            //         if (compiler_find_identifier_with_parent(name, compiler_function_name, out_value, out_type)) {
                        load              (0+BP);
                        store             (4+BP);
                        loadi             (-6309646+global);
                        store             (5+BP);
                        load              (1+BP);
                        store             (6+BP);
                        load              (2+BP);
                        store             (7+BP);
                        load              (7+BP);
                        store             (15+BP);
                        load              (6+BP);
                        store             (14+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_find_identifier_with_parent(); 
                        movebp            (-12);
                        if(equals())      goto if_225_next;
                                                            //             out_scope[0] = Compiler_t_local;
                        loadi             (0);
                        store             (4+BP);
                        loadi             (1);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (4+BP);
                        loadi             (X);
                        store             (5+BP);
                        load              (3+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (X);
                                                            //             return True;
                        loadi             (1);
                        if(always())      goto compiler_find_identifier_end;
                                                            //         }
                                                            //     }
if_225_next:
                                                            // 
                                                            //     if (compiler_find_identifier_with_parent(name, "", out_value, out_type)) {
if_225_end:
if_224_next:
if_224_end:             load              (0+BP);
                        store             (4+BP);
                        loadi             (1505);
                        store             (5+BP);
                        load              (1+BP);
                        store             (6+BP);
                        load              (2+BP);
                        store             (7+BP);
                        load              (7+BP);
                        store             (15+BP);
                        load              (6+BP);
                        store             (14+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_find_identifier_with_parent(); 
                        movebp            (-12);
                        if(equals())      goto if_226_next;
                                                            //         out_scope[0] = Compiler_t_global;
                        loadi             (0);
                        store             (4+BP);
                        loadi             (0);
                        store             (5+BP);
                        load              (4+BP);
                        loadx             ();
                        load              (5+BP);
                        store             (4+BP);
                        loadi             (X);
                        store             (5+BP);
                        load              (3+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (X);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto compiler_find_identifier_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_226_next:
if_226_end:             loadi             (0);
                        if(always())      goto compiler_find_identifier_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_identifier_must_not_be_defined_in_current_scope(char name[]) {
compiler_find_identifier_end:
return;	}
compiler_identifier_must_not_be_defined_in_current_scope
(){
                                                            //     int value[1];
                                                            //     int type[1];
                                                            //     int scope[1];
                                                            // 
                                                            //     if (! compiler_find_identifier(name, value, type, scope)) {
                        load              (0+BP);
                        store             (4+BP);
                        loadi             (1+BP);
                        store             (5+BP);
                        loadi             (2+BP);
                        store             (6+BP);
                        loadi             (3+BP);
                        store             (7+BP);
                        load              (7+BP);
                        store             (18+BP);
                        load              (6+BP);
                        store             (17+BP);
                        load              (5+BP);
                        store             (16+BP);
                        load              (4+BP);
                        store             (15+BP);
                        movebp            (15);
                        compiler_find_identifier(); 
                        movebp            (-15);
                        if(notequals())   goto logical_not_227_false;
                        loadi             (1);
                        if(always())      goto logical_not_227_true;
logical_not_227_false:  loadi             (0);
logical_not_227_true:   if(equals())      goto if_228_next;
                                                            //         return;
                        if(always())      goto compiler_identifier_must_not_be_defined_in_current_scope_end;
                                                            //     }
                                                            // 
                                                            //     if (scope[0] == compiler_get_current_scope())  {
if_228_next:
if_228_end:             loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (4+BP);
                        movebp            (11);
                        compiler_get_current_scope(); 
                        movebp            (-11);
                        subtract          (4+BP);
                        if(equals())      goto compare_229_true;
                        loadi             (0);
                        if(always())      goto compare_229_false;
compare_229_true:       loadi             (1);
compare_229_false:      if(equals())      goto if_230_next;
                                                            //         error_compiler("name already defined");
                        loadi             (1506);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        movebp            (12);
                        error_compiler(); 
                        movebp            (-12);
                                                            //     }
                                                            // }
if_230_next:
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_add_identifier(char name[], int type, int value) {
if_230_end:
compiler_identifier_must_not_be_defined_in_current_scope_end:
return;	}
compiler_add_identifier
(){
                                                            // 
                                                            //     compiler_identifier_must_not_be_defined_in_current_scope(name);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_identifier_must_not_be_defined_in_current_scope(); 
                        movebp            (-9);
                                                            // 
                                                            //     if (compiler_identifier_table_size >= Compiler_max_identifiers) {
                        load              (-6309390+global);
                        store             (3+BP);
                        loadi             (8192);
                        subtract          (3+BP);
                        if(greater())     goto compare_231_true;
                        if(equals())      goto compare_231_true;
                        loadi             (0);
                        if(always())      goto compare_231_false;
compare_231_true:       loadi             (1);
compare_231_false:      if(equals())      goto if_232_next;
                                                            //         error_compiler("out of symbol table space");
                        loadi             (1527);
                        store             (3+BP);
                        load              (3+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_compiler(); 
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     copy_to(compiler_col_name, name, compiler_identifier_table_size * Str_size);
if_232_next:
if_232_end:             loadi             (-4212237+global);
                        store             (3+BP);
                        load              (0+BP);
                        store             (4+BP);
                        load              (-6309390+global);
                        store             (5+BP);
                        loadi             (256);
                        multiply          (5+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        copy_to();        
                        movebp            (-11);
                                                            //     copy_to(compiler_col_parent, compiler_function_name, compiler_identifier_table_size * Str_size);
                        loadi             (-6309389+global);
                        store             (3+BP);
                        loadi             (-6309646+global);
                        store             (4+BP);
                        load              (-6309390+global);
                        store             (5+BP);
                        loadi             (256);
                        multiply          (5+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        copy_to();        
                        movebp            (-11);
                                                            //     compiler_col_type[compiler_identifier_table_size] = type;
                        load              (-6309390+global);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (3+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (-2115085+global+X);
                                                            //     compiler_col_value[compiler_identifier_table_size] = value;
                        load              (-6309390+global);
                        store             (3+BP);
                        load              (2+BP);
                        store             (4+BP);
                        load              (3+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (-2106893+global+X);
                                                            // 
                                                            //     compiler_identifier_table_size = compiler_identifier_table_size + 1;
                        load              (-6309390+global);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (-6309390+global);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_must_find_identifier(char name[], int out_type[], int out_scope[]) {
compiler_add_identifier_end:
return;	}
compiler_must_find_identifier
(){
                                                            //     int value[1];
                                                            // 
                                                            //     if (! compiler_find_identifier(name, value, out_type, out_scope)) {
                        load              (0+BP);
                        store             (4+BP);
                        loadi             (3+BP);
                        store             (5+BP);
                        load              (1+BP);
                        store             (6+BP);
                        load              (2+BP);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        movebp            (13);
                        compiler_find_identifier(); 
                        movebp            (-13);
                        if(notequals())   goto logical_not_233_false;
                        loadi             (1);
                        if(always())      goto logical_not_233_true;
logical_not_233_false:  loadi             (0);
logical_not_233_true:   if(equals())      goto if_234_next;
                                                            //         error_compiler("name not defined");
                        loadi             (1553);
                        store             (4+BP);
                        load              (4+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_compiler(); 
                        movebp            (-10);
                                                            //     }
                                                            // 
                                                            //     return value[0];
if_234_next:
if_234_end:             loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        if(always())      goto compiler_must_find_identifier_end;
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_allocate_temp_local() {
compiler_must_find_identifier_end:
return;	}
compiler_allocate_temp_local
(){
                                                            //     int temp_local_address;
                                                            //     int offset;
                                                            //     
                                                            //     if (compiler_function_temp_data_size >= Compiler_max_temp_data_size) {
                        load              (-6309649+global);
                        store             (2+BP);
                        loadi             (8);
                        subtract          (2+BP);
                        if(greater())     goto compare_235_true;
                        if(equals())      goto compare_235_true;
                        loadi             (0);
                        if(always())      goto compare_235_false;
compare_235_true:       loadi             (1);
compare_235_false:      if(equals())      goto if_236_next;
                                                            //         error_compiler("too many local temporary variables");
                        loadi             (1570);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        error_compiler(); 
                        movebp            (-11);
                                                            //     }
                                                            // 
                                                            //     offset = compiler_function_local_data_size + compiler_function_temp_data_size;
if_236_next:
if_236_end:             load              (-6309648+global);
                        store             (2+BP);
                        load              (-6309649+global);
                        add               (2+BP);
                        store             (1+BP);
                                                            //     temp_local_address = target_allocate_local_address(offset, 1, compiler_function_argument_count);
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (-6309647+global);
                        store             (4+BP);
                        load              (4+BP);
                        store             (15+BP);
                        load              (3+BP);
                        store             (14+BP);
                        load              (2+BP);
                        store             (13+BP);
                        movebp            (13);
                        target_allocate_local_address(); 
                        movebp            (-13);
                        store             (0+BP);
                                                            // 
                                                            //     compiler_function_temp_data_size = compiler_function_temp_data_size + 1;
                        load              (-6309649+global);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (-6309649+global);
                                                            // 
                                                            //     return temp_local_address;
                        load              (0+BP);
                        if(always())      goto compiler_allocate_temp_local_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_free_temp_local(int temp_local_address) {
compiler_allocate_temp_local_end:
return;	}
compiler_free_temp_local
(){
                                                            //     int sanity_check_address;
                                                            //     int offset;
                                                            //     
                                                            //     compiler_function_temp_data_size = compiler_function_temp_data_size - 1;
                        load              (-6309649+global);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (3+BP);
                        subtract          (4+BP);
                        store             (-6309649+global);
                                                            // 
                                                            //     offset = compiler_function_local_data_size + compiler_function_temp_data_size;
                        load              (-6309648+global);
                        store             (3+BP);
                        load              (-6309649+global);
                        add               (3+BP);
                        store             (2+BP);
                                                            //     sanity_check_address = target_allocate_local_address(offset, 1, compiler_function_argument_count);
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (-6309647+global);
                        store             (5+BP);
                        load              (5+BP);
                        store             (15+BP);
                        load              (4+BP);
                        store             (14+BP);
                        load              (3+BP);
                        store             (13+BP);
                        movebp            (13);
                        target_allocate_local_address(); 
                        movebp            (-13);
                        store             (1+BP);
                                                            // 
                                                            //     if (temp_local_address != sanity_check_address) {
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        subtract          (3+BP);
                        if(notequals())   goto compare_237_true;
                        loadi             (0);
                        if(always())      goto compare_237_false;
compare_237_true:       loadi             (1);
compare_237_false:      if(equals())      goto if_238_next;
                                                            //         error_internal();
                        movebp            (10);
                        error_internal(); 
                        movebp            (-10);
                                                            //     }
                                                            // }
if_238_next:
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_get_label(char start_with[], char out_label[]) {
if_238_end:
compiler_free_temp_local_end:
return;	}
compiler_get_label
(){
                                                            //     char sequence_no_str[Str_size];
                                                            // 
                                                            //     int_to_str(compiler_label_sequence_no, sequence_no_str);
                        load              (-7358228+global);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                                                            //     copy(out_label, start_with);
                        load              (1+BP);
                        store             (258+BP);
                        load              (0+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //     append(out_label, "_");
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (1605);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            //     append(out_label, sequence_no_str);
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 
                                                            //     compiler_label_sequence_no = compiler_label_sequence_no + 1;
                        load              (-7358228+global);
                        store             (258+BP);
                        loadi             (1);
                        add               (258+BP);
                        store             (-7358228+global);
                                                            // }
                                                            // 
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_enumerator(char name[]) {
compiler_get_label_end:
return;	}
compiler_enumerator
(){
                                                            // 
                                                            //     compiler_identifier_must_not_be_defined_in_current_scope(name);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_identifier_must_not_be_defined_in_current_scope(); 
                        movebp            (-9);
                                                            // 
                                                            //     compiler_add_identifier(name, Compiler_t_integer_constant, compiler_current_enum_value);
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (3);
                        store             (2+BP);
                        load              (-7358227+global);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        compiler_add_identifier(); 
                        movebp            (-11);
                                                            //     compiler_current_enum_value = compiler_current_enum_value + 1;
                        load              (-7358227+global);
                        store             (1+BP);
                        loadi             (1);
                        add               (1+BP);
                        store             (-7358227+global);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_enumerator_assigned_value(char name[], char value[]) {
compiler_enumerator_end:
return;	}
compiler_enumerator_assigned_value
(){
                                                            // 
                                                            //     compiler_current_enum_value = str_to_int(value);
                        load              (1+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (9+BP);
                        movebp            (9);
                        str_to_int();     
                        movebp            (-9);
                        store             (-7358227+global);
                                                            //     compiler_enumerator(name);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_enumerator(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_enumerator_list_end() {
compiler_enumerator_assigned_value_end:
return;	}
compiler_enumerator_list_end
(){
                                                            // 
                                                            //     compiler_current_enum_value = 0;
                        loadi             (0);
                        store             (-7358227+global);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_declaration_integer(char variable_name[]) {
compiler_enumerator_list_end_end:
return;	}
compiler_declaration_integer
(){
                                                            //     int address;
                                                            // 
                                                            //     if (compiler_get_current_scope() == Compiler_t_local) {
                        movebp            (9);
                        compiler_get_current_scope(); 
                        movebp            (-9);
                        store             (2+BP);
                        loadi             (1);
                        subtract          (2+BP);
                        if(equals())      goto compare_239_true;
                        loadi             (0);
                        if(always())      goto compare_239_false;
compare_239_true:       loadi             (1);
compare_239_false:      if(equals())      goto if_240_next;
                                                            //         address = target_allocate_local_address(compiler_function_local_data_size, 1, compiler_function_argument_count);
                        load              (-6309648+global);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (-6309647+global);
                        store             (4+BP);
                        load              (4+BP);
                        store             (14+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        target_allocate_local_address(); 
                        movebp            (-12);
                        store             (1+BP);
                                                            //         compiler_function_local_data_size = compiler_function_local_data_size + 1;
                        load              (-6309648+global);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (-6309648+global);
                                                            //         compiler_add_identifier(variable_name, Compiler_t_integer, address);
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (14+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_add_identifier(); 
                        movebp            (-12);
                                                            //         return;
                        if(always())      goto compiler_declaration_integer_end;
                                                            //     }
                                                            // 
                                                            //     if (compiler_get_current_scope() == Compiler_t_global) {
if_240_next:
if_240_end:             movebp            (9);
                        compiler_get_current_scope(); 
                        movebp            (-9);
                        store             (2+BP);
                        loadi             (0);
                        subtract          (2+BP);
                        if(equals())      goto compare_241_true;
                        loadi             (0);
                        if(always())      goto compare_241_false;
compare_241_true:       loadi             (1);
compare_241_false:      if(equals())      goto if_242_next;
                                                            //         address = target_allocate_global_address(compiler_global_data_size, 1);
                        load              (-6309650+global);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_allocate_global_address(); 
                        movebp            (-11);
                        store             (1+BP);
                                                            //         compiler_global_data_size = compiler_global_data_size + 1;
                        load              (-6309650+global);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (-6309650+global);
                                                            //         compiler_add_identifier(variable_name, Compiler_t_integer, address);
                        load              (0+BP);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (14+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_add_identifier(); 
                        movebp            (-12);
                                                            //         return;
                        if(always())      goto compiler_declaration_integer_end;
                                                            //     }
                                                            // 
                                                            //     error_internal();
if_242_next:
if_242_end:             movebp            (9);
                        error_internal(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_declaration_integer_array(char array_name[], int array_length) {
compiler_declaration_integer_end:
return;	}
compiler_declaration_integer_array
(){
                                                            //     int address;
                                                            // 
                                                            //     if (array_length <= 0) {
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        if(less())        goto compare_243_true;
                        if(equals())      goto compare_243_true;
                        loadi             (0);
                        if(always())      goto compare_243_false;
compare_243_true:       loadi             (1);
compare_243_false:      if(equals())      goto if_244_next;
                                                            //         error_compiler("array length must be greater than zero");
                        loadi             (1607);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        error_compiler(); 
                        movebp            (-10);
                                                            //     }
                                                            // 
                                                            //     if (compiler_get_current_scope() == Compiler_t_local) {
if_244_next:
if_244_end:             movebp            (9);
                        compiler_get_current_scope(); 
                        movebp            (-9);
                        store             (3+BP);
                        loadi             (1);
                        subtract          (3+BP);
                        if(equals())      goto compare_245_true;
                        loadi             (0);
                        if(always())      goto compare_245_false;
compare_245_true:       loadi             (1);
compare_245_false:      if(equals())      goto if_246_next;
                                                            //         address = target_allocate_local_address(compiler_function_local_data_size, array_length, compiler_function_argument_count);
                        load              (-6309648+global);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (-6309647+global);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        target_allocate_local_address(); 
                        movebp            (-12);
                        store             (2+BP);
                                                            //         compiler_function_local_data_size = compiler_function_local_data_size + array_length;
                        load              (-6309648+global);
                        store             (3+BP);
                        load              (1+BP);
                        add               (3+BP);
                        store             (-6309648+global);
                                                            //         compiler_add_identifier(array_name, Compiler_t_integer_array, address);
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (2);
                        store             (4+BP);
                        load              (2+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_add_identifier(); 
                        movebp            (-12);
                                                            //         return;
                        if(always())      goto compiler_declaration_integer_array_end;
                                                            //     }
                                                            // 
                                                            //     if (compiler_get_current_scope() == Compiler_t_global) {
if_246_next:
if_246_end:             movebp            (9);
                        compiler_get_current_scope(); 
                        movebp            (-9);
                        store             (3+BP);
                        loadi             (0);
                        subtract          (3+BP);
                        if(equals())      goto compare_247_true;
                        loadi             (0);
                        if(always())      goto compare_247_false;
compare_247_true:       loadi             (1);
compare_247_false:      if(equals())      goto if_248_next;
                                                            //         address = target_allocate_global_address(compiler_global_data_size, array_length);
                        load              (-6309650+global);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_allocate_global_address(); 
                        movebp            (-11);
                        store             (2+BP);
                                                            //         compiler_global_data_size = compiler_global_data_size + array_length;
                        load              (-6309650+global);
                        store             (3+BP);
                        load              (1+BP);
                        add               (3+BP);
                        store             (-6309650+global);
                                                            //         compiler_add_identifier(array_name, Compiler_t_integer_array, address);
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (2);
                        store             (4+BP);
                        load              (2+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_add_identifier(); 
                        movebp            (-12);
                                                            //         return;
                        if(always())      goto compiler_declaration_integer_array_end;
                                                            //     }
                                                            // 
                                                            //     error_internal();
if_248_next:
if_248_end:             movebp            (9);
                        error_internal(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_declaration_integer_array_constant_length_specifier(char array_name[], char array_length_integer_constant[])  {
compiler_declaration_integer_array_end:
return;	}
compiler_declaration_integer_array_constant_length_specifier
(){
                                                            //     int length;
                                                            // 
                                                            //     length = str_to_int(array_length_integer_constant);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        str_to_int();     
                        movebp            (-10);
                        store             (2+BP);
                                                            //     compiler_declaration_integer_array(array_name, length);
                        load              (0+BP);
                        store             (3+BP);
                        load              (2+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        compiler_declaration_integer_array(); 
                        movebp            (-11);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_declaration_integer_array_identifier_length_specifier(char array_name[], char array_length_identifier[])  {
compiler_declaration_integer_array_constant_length_specifier_end:
return;	}
compiler_declaration_integer_array_identifier_length_specifier
(){
                                                            //     int array_length;
                                                            //     int type[1];
                                                            //     int scope[1];
                                                            // 
                                                            //     array_length = compiler_must_find_identifier(array_length_identifier, type, scope);
                        load              (1+BP);
                        store             (5+BP);
                        loadi             (3+BP);
                        store             (6+BP);
                        loadi             (4+BP);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        compiler_must_find_identifier(); 
                        movebp            (-14);
                        store             (2+BP);
                                                            // 
                                                            //     if (type[0] != Compiler_t_integer_constant) {
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (5+BP);
                        loadi             (3);
                        subtract          (5+BP);
                        if(notequals())   goto compare_249_true;
                        loadi             (0);
                        if(always())      goto compare_249_false;
compare_249_true:       loadi             (1);
compare_249_false:      if(equals())      goto if_250_next;
                                                            //         error_compiler("constant array length specifier expected");
                        loadi             (1646);
                        store             (5+BP);
                        load              (5+BP);
                        store             (12+BP);
                        movebp            (12);
                        error_compiler(); 
                        movebp            (-12);
                                                            //     }
                                                            // 
                                                            //     compiler_declaration_integer_array(array_name, array_length);
if_250_next:
if_250_end:             load              (0+BP);
                        store             (5+BP);
                        load              (2+BP);
                        store             (6+BP);
                        load              (6+BP);
                        store             (14+BP);
                        load              (5+BP);
                        store             (13+BP);
                        movebp            (13);
                        compiler_declaration_integer_array(); 
                        movebp            (-13);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_definition_begin(char function_name[]) {
compiler_declaration_integer_array_identifier_length_specifier_end:
return;	}
compiler_function_definition_begin
(){
                                                            // 
                                                            //     compiler_identifier_must_not_be_defined_in_current_scope(function_name);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_identifier_must_not_be_defined_in_current_scope(); 
                        movebp            (-9);
                                                            //     compiler_add_identifier(function_name, Compiler_t_function, 0);
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (4);
                        store             (2+BP);
                        loadi             (0);
                        store             (3+BP);
                        load              (3+BP);
                        store             (13+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        compiler_add_identifier(); 
                        movebp            (-11);
                                                            // 
                                                            //     copy(compiler_function_name, function_name);
                        loadi             (-6309646+global);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            //     compiler_function_local_data_size = 0;
                        loadi             (0);
                        store             (-6309648+global);
                                                            //     compiler_function_temp_data_size = 0;
                        loadi             (0);
                        store             (-6309649+global);
                                                            //     compiler_function_argument_count = 0;
                        loadi             (0);
                        store             (-6309647+global);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_argument_declaration_item(char argument_name[], int argument_type, int argument_no) {
compiler_function_definition_begin_end:
return;	}
compiler_function_argument_declaration_item
(){
                                                            //     int address;
                                                            // 
                                                            //     compiler_function_argument_count = compiler_function_argument_count + 1;
                        load              (-6309647+global);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (-6309647+global);
                                                            // 
                                                            //     address = target_allocate_function_argument_address(argument_no, 1);
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (1);
                        store             (5+BP);
                        load              (5+BP);
                        store             (12+BP);
                        load              (4+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_allocate_function_argument_address(); 
                        movebp            (-11);
                        store             (3+BP);
                                                            //     compiler_add_identifier(argument_name, argument_type, address);
                        load              (0+BP);
                        store             (4+BP);
                        load              (1+BP);
                        store             (5+BP);
                        load              (3+BP);
                        store             (6+BP);
                        load              (6+BP);
                        store             (14+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_add_identifier(); 
                        movebp            (-12);
                                                            // }
                                                            //     
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_compound_statement_locals_declared() {
compiler_function_argument_declaration_item_end:
return;	}
compiler_function_compound_statement_locals_declared
(){
                                                            // 
                                                            //     target_op_subroutine_begin(compiler_function_name,
                        loadi             (-6309646+global);
                        store             (0+BP);
                        load              (-6309647+global);
                        store             (1+BP);
                        load              (-6309648+global);
                        store             (2+BP);
                        loadi             (8);
                        add               (2+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (13+BP);
                        load              (1+BP);
                        store             (12+BP);
                        load              (0+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_subroutine_begin(); 
                        movebp            (-11);
                                                            //                                compiler_function_argument_count,
                                                            //                                compiler_function_local_data_size + Compiler_max_temp_data_size);
                                                            // 	
                                                            // 	target_begin_branch_block(compiler_function_name, "_end");
                        loadi             (-6309646+global);
                        store             (0+BP);
                        loadi             (1687);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_definition_end() {
compiler_function_compound_statement_locals_declared_end:
return;	}
compiler_function_definition_end
(){
                                                            // 
                                                            //     target_end_branch_block(compiler_function_name, "_end");
                        loadi             (-6309646+global);
                        store             (0+BP);
                        loadi             (1692);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            // 
                                                            //     target_op_subroutine_end(compiler_function_name,
                        loadi             (-6309646+global);
                        store             (0+BP);
                        load              (-6309647+global);
                        store             (1+BP);
                        load              (-6309648+global);
                        store             (2+BP);
                        loadi             (8);
                        add               (2+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (13+BP);
                        load              (1+BP);
                        store             (12+BP);
                        load              (0+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_subroutine_end(); 
                        movebp            (-11);
                                                            //                              compiler_function_argument_count,
                                                            //                              compiler_function_local_data_size + Compiler_max_temp_data_size);
                                                            // 
                                                            //     copy(compiler_function_name, "");
                        loadi             (-6309646+global);
                        store             (0+BP);
                        loadi             (1697);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            // 
                                                            //     if (compiler_function_temp_data_size != 0) {
                        load              (-6309649+global);
                        store             (0+BP);
                        loadi             (0);
                        subtract          (0+BP);
                        if(notequals())   goto compare_251_true;
                        loadi             (0);
                        if(always())      goto compare_251_false;
compare_251_true:       loadi             (1);
compare_251_false:      if(equals())      goto if_252_next;
                                                            //         error_internal();
                        movebp            (8);
                        error_internal(); 
                        movebp            (-8);
                                                            //     }
                                                            // }
if_252_next:
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_program_begin() {
if_252_end:
compiler_function_definition_end_end:
return;	}
compiler_program_begin
(){
                                                            // 
                                                            //     target_program_begin();
                        movebp            (8);
                        target_program_begin(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // compiler_program_end() {
compiler_program_begin_end:
return;	}
compiler_program_end
(){
                                                            // 
                                                            //     target_program_end(compiler_global_data_size);
                        load              (-6309650+global);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_program_end(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_output_source_as_comment() {
compiler_program_end_end:
return;	}
compiler_output_source_as_comment
(){
                                                            // 
                                                            //     preprocessor_get_source_chunk(compiler_source_chunk);
                        loadi             (-7358226+global);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        preprocessor_get_source_chunk(); 
                        movebp            (-9);
                                                            // 
                                                            //     target_comment_print(compiler_source_chunk);
                        loadi             (-7358226+global);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_comment_print(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // 
                                                            // compiler_built_in_function_fgetc() {
compiler_output_source_as_comment_end:
return;	}
compiler_built_in_function_fgetc
(){
                                                            // 
                                                            //     target_built_in_function_fgetc();
                        movebp            (8);
                        target_built_in_function_fgetc(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // compiler_built_in_function_fputc_stdout() {
compiler_built_in_function_fgetc_end:
return;	}
compiler_built_in_function_fputc_stdout
(){
                                                            // 
                                                            //     target_built_in_function_fputc_stdout();
                        movebp            (8);
                        target_built_in_function_fputc_stdout(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // compiler_built_in_function_fputc_stderr() {
compiler_built_in_function_fputc_stdout_end:
return;	}
compiler_built_in_function_fputc_stderr
(){
                                                            // 
                                                            //     target_built_in_function_fputc_stderr();
                        movebp            (8);
                        target_built_in_function_fputc_stderr(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // compiler_built_in_function_exit() {
compiler_built_in_function_fputc_stderr_end:
return;	}
compiler_built_in_function_exit
(){
                                                            // 
                                                            //     target_built_in_function_exit();
                        movebp            (8);
                        target_built_in_function_exit(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // compiler_built_in_function_debug() {
compiler_built_in_function_exit_end:
return;	}
compiler_built_in_function_debug
(){
                                                            // 
                                                            //     target_built_in_function_debug();
                        movebp            (8);
                        target_built_in_function_debug(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_call_prepare(char function_name[], char out_function_name_cookie[]) {
compiler_built_in_function_debug_end:
return;	}
compiler_function_call_prepare
(){
                                                            // 
                                                            //     copy(out_function_name_cookie, function_name);
                        load              (1+BP);
                        store             (2+BP);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        copy();           
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_call_string_literal_argument(char string_literal[]) {
compiler_function_call_prepare_end:
return;	}
compiler_function_call_string_literal_argument
(){
                                                            //     int string_length;
                                                            //     int address;
                                                            // 
                                                            //     string_length = length(string_literal);
                        load              (0+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        length();         
                        movebp            (-11);
                        store             (1+BP);
                                                            //     address = target_allocate_string(string_literal, string_length + 1);
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        target_allocate_string(); 
                        movebp            (-12);
                        store             (2+BP);
                                                            // 
                                                            //     target_op_load_address(address, Target_t_global);
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (3);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        target_op_load_address(); 
                        movebp            (-12);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_call_pointer_argument(char identifier[]) {
compiler_function_call_string_literal_argument_end:
return;	}
compiler_function_call_pointer_argument
(){
                                                            //     int value[1];
                                                            //     int type[1];
                                                            //     int scope[1];
                                                            // 
                                                            //     if (! compiler_find_identifier(identifier, value, type, scope)) {
                        load              (0+BP);
                        store             (4+BP);
                        loadi             (1+BP);
                        store             (5+BP);
                        loadi             (2+BP);
                        store             (6+BP);
                        loadi             (3+BP);
                        store             (7+BP);
                        load              (7+BP);
                        store             (18+BP);
                        load              (6+BP);
                        store             (17+BP);
                        load              (5+BP);
                        store             (16+BP);
                        load              (4+BP);
                        store             (15+BP);
                        movebp            (15);
                        compiler_find_identifier(); 
                        movebp            (-15);
                        if(notequals())   goto logical_not_253_false;
                        loadi             (1);
                        if(always())      goto logical_not_253_true;
logical_not_253_false:  loadi             (0);
logical_not_253_true:   if(equals())      goto if_254_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto compiler_function_call_pointer_argument_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_local) {
if_254_next:
if_254_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (4+BP);
                        loadi             (2);
                        subtract          (4+BP);
                        if(equals())      goto compare_255_true;
                        loadi             (0);
                        if(always())      goto compare_255_false;
compare_255_true:       loadi             (1);
compare_255_false:      if(equals())      goto logical_and_256_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (4+BP);
                        loadi             (1);
                        subtract          (4+BP);
                        if(equals())      goto compare_257_true;
                        loadi             (0);
                        if(always())      goto compare_257_false;
compare_257_true:       loadi             (1);
compare_257_false:      if(equals())      goto logical_and_256_false;
                        loadi             (1);
                        if(always())      goto logical_and_256_true;
logical_and_256_false:  loadi             (0);
logical_and_256_true:   if(equals())      goto if_258_next;
                                                            //         target_op_load_address(value[0], Target_t_local);
                        loadi             (0);
                        loadx             ();
                        load              (1+BP+X);
                        store             (4+BP);
                        loadi             (1);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        movebp            (13);
                        target_op_load_address(); 
                        movebp            (-13);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto compiler_function_call_pointer_argument_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_global) {
if_258_next:
if_258_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (4+BP);
                        loadi             (2);
                        subtract          (4+BP);
                        if(equals())      goto compare_259_true;
                        loadi             (0);
                        if(always())      goto compare_259_false;
compare_259_true:       loadi             (1);
compare_259_false:      if(equals())      goto logical_and_260_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (4+BP);
                        loadi             (0);
                        subtract          (4+BP);
                        if(equals())      goto compare_261_true;
                        loadi             (0);
                        if(always())      goto compare_261_false;
compare_261_true:       loadi             (1);
compare_261_false:      if(equals())      goto logical_and_260_false;
                        loadi             (1);
                        if(always())      goto logical_and_260_true;
logical_and_260_false:  loadi             (0);
logical_and_260_true:   if(equals())      goto if_262_next;
                                                            //         target_op_load_address(value[0], Target_t_global);
                        loadi             (0);
                        loadx             ();
                        load              (1+BP+X);
                        store             (4+BP);
                        loadi             (3);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        movebp            (13);
                        target_op_load_address(); 
                        movebp            (-13);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto compiler_function_call_pointer_argument_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_pointer && scope[0] == Compiler_t_local) {
if_262_next:
if_262_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (4+BP);
                        loadi             (0);
                        subtract          (4+BP);
                        if(equals())      goto compare_263_true;
                        loadi             (0);
                        if(always())      goto compare_263_false;
compare_263_true:       loadi             (1);
compare_263_false:      if(equals())      goto logical_and_264_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (4+BP);
                        loadi             (1);
                        subtract          (4+BP);
                        if(equals())      goto compare_265_true;
                        loadi             (0);
                        if(always())      goto compare_265_false;
compare_265_true:       loadi             (1);
compare_265_false:      if(equals())      goto logical_and_264_false;
                        loadi             (1);
                        if(always())      goto logical_and_264_true;
logical_and_264_false:  loadi             (0);
logical_and_264_true:   if(equals())      goto if_266_next;
                                                            //         target_op_load(value[0], Target_t_local);
                        loadi             (0);
                        loadx             ();
                        load              (1+BP+X);
                        store             (4+BP);
                        loadi             (1);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        movebp            (13);
                        target_op_load(); 
                        movebp            (-13);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto compiler_function_call_pointer_argument_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_266_next:
if_266_end:             loadi             (0);
                        if(always())      goto compiler_function_call_pointer_argument_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_call_argument_prepare(int out_argument_temp_local_cookie[]) {
compiler_function_call_pointer_argument_end:
return;	}
compiler_function_call_argument_prepare
(){
                                                            //     int temp_local;
                                                            // 
                                                            //     temp_local = compiler_allocate_temp_local();
                        movebp            (9);
                        compiler_allocate_temp_local(); 
                        movebp            (-9);
                        store             (1+BP);
                                                            //     target_op_store(temp_local, Target_t_local);
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_store(); 
                        movebp            (-11);
                                                            // 
                                                            //     out_argument_temp_local_cookie[0] = temp_local;
                        loadi             (0);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (2+BP);
                        loadx             ();
                        load              (3+BP);
                        store             (2+BP);
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (2+BP);
                        store             (X);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_call_argument_pass(int argument_number, int argument_count, int argument_temp_local_cookie[]) {
compiler_function_call_argument_prepare_end:
return;	}
compiler_function_call_argument_pass
(){
                                                            // 
                                                            //     target_op_load(argument_temp_local_cookie[0], Target_t_local);
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (2+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (11+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_load(); 
                        movebp            (-10);
                                                            //     
                                                            //     target_op_pass_argument(argument_number,
                        load              (0+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (-6309648+global);
                        store             (5+BP);
                        loadi             (8);
                        add               (5+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_pass_argument(); 
                        movebp            (-11);
                                                            //                             argument_count,
                                                            //                             compiler_function_local_data_size + Compiler_max_temp_data_size);
                                                            // 
                                                            //     compiler_free_temp_local(argument_temp_local_cookie[0]);
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (2+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        load              (3+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_free_temp_local(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_function_call_execute(char function_name_cookie[], int function_argument_count) {
compiler_function_call_argument_pass_end:
return;	}
compiler_function_call_execute
(){
                                                            // 
                                                            //     target_op_call_subroutine(function_name_cookie,
                        load              (0+BP);
                        store             (2+BP);
                        load              (1+BP);
                        store             (3+BP);
                        load              (-6309648+global);
                        store             (4+BP);
                        loadi             (8);
                        add               (4+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_call_subroutine(); 
                        movebp            (-11);
                                                            //                               function_argument_count,
                                                            //                               compiler_function_local_data_size + Compiler_max_temp_data_size);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_primary_expression_array_index() {
compiler_function_call_execute_end:
return;	}
compiler_primary_expression_array_index
(){
                                                            // 
                                                            //     target_op_loadx();
                        movebp            (8);
                        target_op_loadx(); 
                        movebp            (-8);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_primary_expression_identifier(char identifier[]) {
compiler_primary_expression_array_index_end:
return;	}
compiler_primary_expression_identifier
(){
                                                            //     int value;
                                                            //     int type[1];
                                                            //     int scope[1];
                                                            //     int temp_array_index;
                                                            // 
                                                            //     value = compiler_must_find_identifier(identifier, type, scope);
                        load              (0+BP);
                        store             (5+BP);
                        loadi             (2+BP);
                        store             (6+BP);
                        loadi             (3+BP);
                        store             (7+BP);
                        load              (7+BP);
                        store             (17+BP);
                        load              (6+BP);
                        store             (16+BP);
                        load              (5+BP);
                        store             (15+BP);
                        movebp            (15);
                        compiler_must_find_identifier(); 
                        movebp            (-15);
                        store             (1+BP);
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_constant) {
                        loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (5+BP);
                        loadi             (3);
                        subtract          (5+BP);
                        if(equals())      goto compare_267_true;
                        loadi             (0);
                        if(always())      goto compare_267_false;
compare_267_true:       loadi             (1);
compare_267_false:      if(equals())      goto if_268_next;
                                                            //         target_op_load_constant(value);
                        load              (1+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        movebp            (13);
                        target_op_load_constant(); 
                        movebp            (-13);
                                                            //         return;
                        if(always())      goto compiler_primary_expression_identifier_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_local) {
if_268_next:
if_268_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (5+BP);
                        loadi             (1);
                        subtract          (5+BP);
                        if(equals())      goto compare_269_true;
                        loadi             (0);
                        if(always())      goto compare_269_false;
compare_269_true:       loadi             (1);
compare_269_false:      if(equals())      goto logical_and_270_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (5+BP);
                        loadi             (1);
                        subtract          (5+BP);
                        if(equals())      goto compare_271_true;
                        loadi             (0);
                        if(always())      goto compare_271_false;
compare_271_true:       loadi             (1);
compare_271_false:      if(equals())      goto logical_and_270_false;
                        loadi             (1);
                        if(always())      goto logical_and_270_true;
logical_and_270_false:  loadi             (0);
logical_and_270_true:   if(equals())      goto if_272_next;
                                                            //         target_op_load(value, Target_t_local);
                        load              (1+BP);
                        store             (5+BP);
                        loadi             (1);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_load(); 
                        movebp            (-14);
                                                            //         return;
                        if(always())      goto compiler_primary_expression_identifier_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_global) {
if_272_next:
if_272_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (5+BP);
                        loadi             (1);
                        subtract          (5+BP);
                        if(equals())      goto compare_273_true;
                        loadi             (0);
                        if(always())      goto compare_273_false;
compare_273_true:       loadi             (1);
compare_273_false:      if(equals())      goto logical_and_274_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        if(equals())      goto compare_275_true;
                        loadi             (0);
                        if(always())      goto compare_275_false;
compare_275_true:       loadi             (1);
compare_275_false:      if(equals())      goto logical_and_274_false;
                        loadi             (1);
                        if(always())      goto logical_and_274_true;
logical_and_274_false:  loadi             (0);
logical_and_274_true:   if(equals())      goto if_276_next;
                                                            //         target_op_load(value, Target_t_global);
                        load              (1+BP);
                        store             (5+BP);
                        loadi             (3);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_load(); 
                        movebp            (-14);
                                                            //         return;
                        if(always())      goto compiler_primary_expression_identifier_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_local) {
if_276_next:
if_276_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (5+BP);
                        loadi             (2);
                        subtract          (5+BP);
                        if(equals())      goto compare_277_true;
                        loadi             (0);
                        if(always())      goto compare_277_false;
compare_277_true:       loadi             (1);
compare_277_false:      if(equals())      goto logical_and_278_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (5+BP);
                        loadi             (1);
                        subtract          (5+BP);
                        if(equals())      goto compare_279_true;
                        loadi             (0);
                        if(always())      goto compare_279_false;
compare_279_true:       loadi             (1);
compare_279_false:      if(equals())      goto logical_and_278_false;
                        loadi             (1);
                        if(always())      goto logical_and_278_true;
logical_and_278_false:  loadi             (0);
logical_and_278_true:   if(equals())      goto if_280_next;
                                                            //         target_op_load(value, Target_t_local_ix);
                        load              (1+BP);
                        store             (5+BP);
                        loadi             (2);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_load(); 
                        movebp            (-14);
                                                            //         return;
                        if(always())      goto compiler_primary_expression_identifier_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_global) {
if_280_next:
if_280_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (5+BP);
                        loadi             (2);
                        subtract          (5+BP);
                        if(equals())      goto compare_281_true;
                        loadi             (0);
                        if(always())      goto compare_281_false;
compare_281_true:       loadi             (1);
compare_281_false:      if(equals())      goto logical_and_282_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        if(equals())      goto compare_283_true;
                        loadi             (0);
                        if(always())      goto compare_283_false;
compare_283_true:       loadi             (1);
compare_283_false:      if(equals())      goto logical_and_282_false;
                        loadi             (1);
                        if(always())      goto logical_and_282_true;
logical_and_282_false:  loadi             (0);
logical_and_282_true:   if(equals())      goto if_284_next;
                                                            //         target_op_load(value, Target_t_global_ix);
                        load              (1+BP);
                        store             (5+BP);
                        loadi             (4);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_load(); 
                        movebp            (-14);
                                                            //         return;
                        if(always())      goto compiler_primary_expression_identifier_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_pointer && scope[0] == Compiler_t_local) {
if_284_next:
if_284_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (5+BP);
                        loadi             (0);
                        subtract          (5+BP);
                        if(equals())      goto compare_285_true;
                        loadi             (0);
                        if(always())      goto compare_285_false;
compare_285_true:       loadi             (1);
compare_285_false:      if(equals())      goto logical_and_286_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (5+BP);
                        loadi             (1);
                        subtract          (5+BP);
                        if(equals())      goto compare_287_true;
                        loadi             (0);
                        if(always())      goto compare_287_false;
compare_287_true:       loadi             (1);
compare_287_false:      if(equals())      goto logical_and_286_false;
                        loadi             (1);
                        if(always())      goto logical_and_286_true;
logical_and_286_false:  loadi             (0);
logical_and_286_true:   if(equals())      goto if_288_next;
                                                            //         temp_array_index = compiler_allocate_temp_local();
                        movebp            (12);
                        compiler_allocate_temp_local(); 
                        movebp            (-12);
                        store             (4+BP);
                                                            //         target_op_load_address(0, Target_t_ix);                 // temp_array_index = X
                        loadi             (0);
                        store             (5+BP);
                        loadi             (0);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_load_address(); 
                        movebp            (-14);
                                                            //         target_op_store(temp_array_index, Target_t_local);
                        load              (4+BP);
                        store             (5+BP);
                        loadi             (1);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_store(); 
                        movebp            (-14);
                                                            //         target_op_load(value, Target_t_local);                  // A = address held in local pointer variable
                        load              (1+BP);
                        store             (5+BP);
                        loadi             (1);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_load(); 
                        movebp            (-14);
                                                            //         target_op_add(temp_array_index, Target_t_local);        // X = A + temp_array_index
                        load              (4+BP);
                        store             (5+BP);
                        loadi             (1);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_add();  
                        movebp            (-14);
                                                            //         target_op_loadx();
                        movebp            (12);
                        target_op_loadx(); 
                        movebp            (-12);
                                                            //         target_op_load(0, Target_t_indirect);                         // load (X)
                        loadi             (0);
                        store             (5+BP);
                        loadi             (5);
                        store             (6+BP);
                        load              (6+BP);
                        store             (15+BP);
                        load              (5+BP);
                        store             (14+BP);
                        movebp            (14);
                        target_op_load(); 
                        movebp            (-14);
                                                            //         compiler_free_temp_local(temp_array_index);
                        load              (4+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        movebp            (13);
                        compiler_free_temp_local(); 
                        movebp            (-13);
                                                            //         return;
                        if(always())      goto compiler_primary_expression_identifier_end;
                                                            //     }
                                                            // 
                                                            //     error_compiler("identifier cannot be used in an expression");
if_288_next:
if_288_end:             loadi             (1698);
                        store             (5+BP);
                        load              (5+BP);
                        store             (13+BP);
                        movebp            (13);
                        error_compiler(); 
                        movebp            (-13);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_primary_expression_integer_constant(char integer_constant_str[]) {
compiler_primary_expression_identifier_end:
return;	}
compiler_primary_expression_integer_constant
(){
                                                            //     int integer_constant;
                                                            // 
                                                            //     integer_constant = str_to_int(integer_constant_str);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        str_to_int();     
                        movebp            (-10);
                        store             (1+BP);
                                                            //     target_op_load_constant(integer_constant);
                        load              (1+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_load_constant(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_primary_expression_character_constant(int character_code) {
compiler_primary_expression_integer_constant_end:
return;	}
compiler_primary_expression_character_constant
(){
                                                            // 
                                                            //     target_op_load_constant(character_code);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_op_load_constant(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_unary_expression(char operator_text[]) {
compiler_primary_expression_character_constant_end:
return;	}
compiler_unary_expression
(){
                                                            //     int temp_local;
                                                            //     char label[Str_size];
                                                            // 
                                                            //     if (str_equals(operator_text, "+")) {
                        load              (0+BP);
                        store             (258+BP);
                        loadi             (1741);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        str_equals();     
                        movebp            (-267);
                        if(equals())      goto if_289_next;
                                                            //         return;
                        if(always())      goto compiler_unary_expression_end;
                                                            //     }
                                                            // 
                                                            //     if (str_equals(operator_text, "-")) {
if_289_next:
if_289_end:             load              (0+BP);
                        store             (258+BP);
                        loadi             (1743);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        str_equals();     
                        movebp            (-267);
                        if(equals())      goto if_290_next;
                                                            //         temp_local = compiler_allocate_temp_local();
                        movebp            (265);
                        compiler_allocate_temp_local(); 
                        movebp            (-265);
                        store             (1+BP);
                                                            //         target_op_store(temp_local, Target_t_local);
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (1);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_op_store(); 
                        movebp            (-267);
                                                            //         target_op_load_constant(0);
                        loadi             (0);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_load_constant(); 
                        movebp            (-266);
                                                            //         target_op_subtract(temp_local, Target_t_local);
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (1);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_op_subtract(); 
                        movebp            (-267);
                                                            //         compiler_free_temp_local(temp_local);
                        load              (1+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        compiler_free_temp_local(); 
                        movebp            (-266);
                                                            //         return;
                        if(always())      goto compiler_unary_expression_end;
                                                            //     }
                                                            // 
                                                            //     if (str_equals(operator_text, "!")) {
if_290_next:
if_290_end:             load              (0+BP);
                        store             (258+BP);
                        loadi             (1745);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        str_equals();     
                        movebp            (-267);
                        if(equals())      goto if_291_next;
                                                            //         target_get_label("logical_not", label);
                        loadi             (1747);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_get_label(); 
                        movebp            (-267);
                                                            // 		target_begin_branch_block(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1759);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_begin_branch_block(); 
                        movebp            (-267);
                                                            // 		target_begin_branch_block(label, "_false");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1765);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_begin_branch_block(); 
                        movebp            (-267);
                                                            //         target_op_test();
                        movebp            (265);
                        target_op_test(); 
                        movebp            (-265);
                                                            //         target_op_branch_if_true(label, "_false");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1772);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_op_branch_if_true(); 
                        movebp            (-267);
                                                            //         target_op_load_constant(1);
                        loadi             (1);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_load_constant(); 
                        movebp            (-266);
                                                            //         target_op_branch(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1779);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_op_branch(); 
                        movebp            (-267);
                                                            //         target_end_branch_block(label, "_false");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1785);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_end_branch_block(); 
                        movebp            (-267);
                                                            //         target_op_load_constant(0);
                        loadi             (0);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_load_constant(); 
                        movebp            (-266);
                                                            //         target_end_branch_block(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1792);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        target_end_branch_block(); 
                        movebp            (-267);
                                                            //         return;
                        if(always())      goto compiler_unary_expression_end;
                                                            //     }
                                                            // 
                                                            //     error_internal();
if_291_next:
if_291_end:             movebp            (265);
                        error_internal(); 
                        movebp            (-265);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_multiplicative_expression_sequence_begin() {
compiler_unary_expression_end:
return;	}
compiler_multiplicative_expression_sequence_begin
(){
                                                            //     int temp_left_cookie;
                                                            // 
                                                            //     temp_left_cookie = compiler_allocate_temp_local();
                        movebp            (9);
                        compiler_allocate_temp_local(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     target_op_store(temp_left_cookie, Target_t_local);
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_store(); 
                        movebp            (-11);
                                                            // 
                                                            //     return temp_left_cookie;
                        load              (0+BP);
                        if(always())      goto compiler_multiplicative_expression_sequence_begin_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_multiplicative_expression_sequence_end(char operator_text[], int temp_left_cookie) {
compiler_multiplicative_expression_sequence_begin_end:
return;	}
compiler_multiplicative_expression_sequence_end
(){
                                                            //     int temp_right;
                                                            // 
                                                            //     if (str_equals(operator_text, "*")) {
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (1798);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        str_equals();     
                        movebp            (-11);
                        if(equals())      goto if_292_next;
                                                            //         target_op_multiply(temp_left_cookie, Target_t_local);
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_multiply(); 
                        movebp            (-11);
                                                            //         compiler_free_temp_local(temp_left_cookie);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            //         return;
                        if(always())      goto compiler_multiplicative_expression_sequence_end_end;
                                                            //     }
                                                            // 
                                                            //     if (str_equals(operator_text, "/")) {
if_292_next:
if_292_end:             load              (0+BP);
                        store             (3+BP);
                        loadi             (1800);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        str_equals();     
                        movebp            (-11);
                        if(equals())      goto if_293_next;
                                                            //         temp_right = compiler_allocate_temp_local();
                        movebp            (9);
                        compiler_allocate_temp_local(); 
                        movebp            (-9);
                        store             (2+BP);
                                                            //         target_op_store(temp_right, Target_t_local);
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_store(); 
                        movebp            (-11);
                                                            //         target_op_load(temp_left_cookie, Target_t_local);
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_load(); 
                        movebp            (-11);
                                                            //         target_op_divide(temp_right, Target_t_local);
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_divide(); 
                        movebp            (-11);
                                                            //         compiler_free_temp_local(temp_right);
                        load              (2+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            //         compiler_free_temp_local(temp_left_cookie);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            //         return;
                        if(always())      goto compiler_multiplicative_expression_sequence_end_end;
                                                            //     }
                                                            // 
                                                            //     error_internal();
if_293_next:
if_293_end:             movebp            (9);
                        error_internal(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_additive_expression_sequence_begin() {
compiler_multiplicative_expression_sequence_end_end:
return;	}
compiler_additive_expression_sequence_begin
(){
                                                            //     int temp_left_cookie;
                                                            // 
                                                            //     temp_left_cookie = compiler_allocate_temp_local();
                        movebp            (9);
                        compiler_allocate_temp_local(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     target_op_store(temp_left_cookie, Target_t_local);
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_store(); 
                        movebp            (-11);
                                                            // 
                                                            //     return temp_left_cookie;
                        load              (0+BP);
                        if(always())      goto compiler_additive_expression_sequence_begin_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_additive_expression_sequence_end(char operator_text[], int temp_left_cookie) {
compiler_additive_expression_sequence_begin_end:
return;	}
compiler_additive_expression_sequence_end
(){
                                                            //     int temp_right;
                                                            // 
                                                            //     if (str_equals(operator_text, "+")) {
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (1802);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        str_equals();     
                        movebp            (-11);
                        if(equals())      goto if_294_next;
                                                            //         target_op_add(temp_left_cookie, Target_t_local);
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_add();  
                        movebp            (-11);
                                                            //         compiler_free_temp_local(temp_left_cookie);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            //         return;
                        if(always())      goto compiler_additive_expression_sequence_end_end;
                                                            //     }
                                                            // 
                                                            //     if (str_equals(operator_text, "-")) {
if_294_next:
if_294_end:             load              (0+BP);
                        store             (3+BP);
                        loadi             (1804);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        str_equals();     
                        movebp            (-11);
                        if(equals())      goto if_295_next;
                                                            //         temp_right = compiler_allocate_temp_local();
                        movebp            (9);
                        compiler_allocate_temp_local(); 
                        movebp            (-9);
                        store             (2+BP);
                                                            //         target_op_store(temp_right, Target_t_local);
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_store(); 
                        movebp            (-11);
                                                            //         target_op_load(temp_left_cookie, Target_t_local);
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_load(); 
                        movebp            (-11);
                                                            //         target_op_subtract(temp_right, Target_t_local);
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_subtract(); 
                        movebp            (-11);
                                                            //         compiler_free_temp_local(temp_right);
                        load              (2+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            //         compiler_free_temp_local(temp_left_cookie);
                        load              (1+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            //         return;
                        if(always())      goto compiler_additive_expression_sequence_end_end;
                                                            //     }
                                                            // 
                                                            //     error_internal();
if_295_next:
if_295_end:             movebp            (9);
                        error_internal(); 
                        movebp            (-9);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_relational_or_equality_expression_sequence_begin() {
compiler_additive_expression_sequence_end_end:
return;	}
compiler_relational_or_equality_expression_sequence_begin
(){
                                                            //     int temp_left_cookie;
                                                            // 
                                                            //     temp_left_cookie = compiler_allocate_temp_local();
                        movebp            (9);
                        compiler_allocate_temp_local(); 
                        movebp            (-9);
                        store             (0+BP);
                                                            //     target_op_store(temp_left_cookie, Target_t_local);
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        store             (2+BP);
                        load              (2+BP);
                        store             (12+BP);
                        load              (1+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_store(); 
                        movebp            (-11);
                                                            // 
                                                            //     return temp_left_cookie;
                        load              (0+BP);
                        if(always())      goto compiler_relational_or_equality_expression_sequence_begin_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_relational_or_equality_expression_sequence_end(char operator_text[], int temp_left_cookie) {
compiler_relational_or_equality_expression_sequence_begin_end:
return;	}
compiler_relational_or_equality_expression_sequence_end
(){
                                                            //     char label[Str_size];
                                                            // 
                                                            //     target_get_label("compare", label);
                        loadi             (1806);
                        store             (258+BP);
                        loadi             (2+BP);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_get_label(); 
                        movebp            (-266);
                                                            // 
                                                            //     target_op_subtract(temp_left_cookie, Target_t_local);
                        load              (1+BP);
                        store             (258+BP);
                        loadi             (1);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_subtract(); 
                        movebp            (-266);
                                                            //     compiler_free_temp_local(temp_left_cookie);
                        load              (1+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_free_temp_local(); 
                        movebp            (-265);
                                                            // 
                                                            // 	target_begin_branch_block(label, "_false");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1814);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_begin_branch_block(); 
                        movebp            (-266);
                                                            // 	target_begin_branch_block(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1821);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_begin_branch_block(); 
                        movebp            (-266);
                                                            // 
                                                            //     if (str_equals(operator_text, "==")) {
                        load              (0+BP);
                        store             (258+BP);
                        loadi             (1827);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        str_equals();     
                        movebp            (-266);
                        if(equals())      goto if_296_next;
                                                            //         target_op_branch_if_equals(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1830);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_equals(); 
                        movebp            (-266);
                                                            //     }
                                                            //     else if (str_equals(operator_text, "!=")) {
                        if(always())      goto if_296_end;
if_296_next:            load              (0+BP);
                        store             (258+BP);
                        loadi             (1836);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        str_equals();     
                        movebp            (-266);
                        if(equals())      goto if_297_next;
                                                            //         target_op_branch_if_not_equals(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1839);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_not_equals(); 
                        movebp            (-266);
                                                            //     }
                                                            //     else if (str_equals(operator_text, "<")) {
                        if(always())      goto if_297_end;
if_297_next:            load              (0+BP);
                        store             (258+BP);
                        loadi             (1845);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        str_equals();     
                        movebp            (-266);
                        if(equals())      goto if_298_next;
                                                            //         target_op_branch_if_less(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1847);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_less(); 
                        movebp            (-266);
                                                            //     }
                                                            //     else if (str_equals(operator_text, "<=")) {
                        if(always())      goto if_298_end;
if_298_next:            load              (0+BP);
                        store             (258+BP);
                        loadi             (1853);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        str_equals();     
                        movebp            (-266);
                        if(equals())      goto if_299_next;
                                                            //         target_op_branch_if_less(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1856);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_less(); 
                        movebp            (-266);
                                                            //         target_op_branch_if_equals(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1862);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_equals(); 
                        movebp            (-266);
                                                            //     }
                                                            //     else if (str_equals(operator_text, ">")) {
                        if(always())      goto if_299_end;
if_299_next:            load              (0+BP);
                        store             (258+BP);
                        loadi             (1868);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        str_equals();     
                        movebp            (-266);
                        if(equals())      goto if_300_next;
                                                            //         target_op_branch_if_greater(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1870);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_greater(); 
                        movebp            (-266);
                                                            //     }
                                                            //     else if (str_equals(operator_text, ">=")) {
                        if(always())      goto if_300_end;
if_300_next:            load              (0+BP);
                        store             (258+BP);
                        loadi             (1876);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        str_equals();     
                        movebp            (-266);
                        if(equals())      goto if_301_next;
                                                            //         target_op_branch_if_greater(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1879);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_greater(); 
                        movebp            (-266);
                                                            //         target_op_branch_if_equals(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1885);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch_if_equals(); 
                        movebp            (-266);
                                                            //     }
                                                            //     else {
                        if(always())      goto if_301_end;
                                                            //         error_internal();
if_301_next:            movebp            (264);
                        error_internal(); 
                        movebp            (-264);
                                                            //     }
                                                            // 
                                                            //     target_op_load_constant(0);
if_301_end:
if_300_end:
if_299_end:
if_298_end:
if_297_end:
if_296_end:             loadi             (0);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        target_op_load_constant(); 
                        movebp            (-265);
                                                            //     target_op_branch(label, "_false");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1891);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_op_branch(); 
                        movebp            (-266);
                                                            //     target_end_branch_block(label, "_true");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1898);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_end_branch_block(); 
                        movebp            (-266);
                                                            //     target_op_load_constant(1);
                        loadi             (1);
                        store             (258+BP);
                        load              (258+BP);
                        store             (265+BP);
                        movebp            (265);
                        target_op_load_constant(); 
                        movebp            (-265);
                                                            //     target_end_branch_block(label, "_false");
                        loadi             (2+BP);
                        store             (258+BP);
                        loadi             (1904);
                        store             (259+BP);
                        load              (259+BP);
                        store             (267+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        target_end_branch_block(); 
                        movebp            (-266);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_logical_and_expression_begin(char out_label_and[]) {
compiler_relational_or_equality_expression_sequence_end_end:
return;	}
compiler_logical_and_expression_begin
(){
                                                            // 
                                                            //     target_get_label("logical_and", out_label_and);
                        loadi             (1911);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_get_label(); 
                        movebp            (-10);
                                                            // 	target_begin_branch_block(out_label_and, "_true");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1923);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            // 	target_begin_branch_block(out_label_and, "_false");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1929);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            // 
                                                            //     target_op_test();
                        movebp            (8);
                        target_op_test(); 
                        movebp            (-8);
                                                            //     target_op_branch_if_false(out_label_and, "_false");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1936);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_false(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_logical_and_switch_sequence(char label_and[]) {
compiler_logical_and_expression_begin_end:
return;	}
compiler_logical_and_switch_sequence
(){
                                                            // 
                                                            //     target_op_test();
                        movebp            (8);
                        target_op_test(); 
                        movebp            (-8);
                                                            //     target_op_branch_if_false(label_and, "_false");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1943);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_false(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_logical_and_expression_end(char label_and[]) {
compiler_logical_and_switch_sequence_end:
return;	}
compiler_logical_and_expression_end
(){
                                                            // 
                                                            //     target_op_load_constant(1);
                        loadi             (1);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_op_load_constant(); 
                        movebp            (-9);
                                                            //     target_op_branch(label_and, "_true");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1950);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch(); 
                        movebp            (-10);
                                                            //     target_end_branch_block(label_and, "_false");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1956);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            //     target_op_load_constant(0);
                        loadi             (0);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_op_load_constant(); 
                        movebp            (-9);
                                                            //     target_end_branch_block(label_and, "_true");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1963);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_logical_or_expression_begin(char out_label_or[]) {
compiler_logical_and_expression_end_end:
return;	}
compiler_logical_or_expression_begin
(){
                                                            // 
                                                            //     target_get_label("logical_or", out_label_or);
                        loadi             (1969);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_get_label(); 
                        movebp            (-10);
                                                            // 	target_begin_branch_block(out_label_or, "_false");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1980);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            // 	target_begin_branch_block(out_label_or, "_true");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1987);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            // 
                                                            // 
                                                            //     target_op_test();
                        movebp            (8);
                        target_op_test(); 
                        movebp            (-8);
                                                            //     target_op_branch_if_true(out_label_or, "_true");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1993);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_true(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_logical_or_switch_sequence(char label_or[]) {
compiler_logical_or_expression_begin_end:
return;	}
compiler_logical_or_switch_sequence
(){
                                                            // 
                                                            //     target_op_test();
                        movebp            (8);
                        target_op_test(); 
                        movebp            (-8);
                                                            //     target_op_branch_if_true(label_or, "_true");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (1999);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_true(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_logical_or_expression_end(char label_or[]) {
compiler_logical_or_switch_sequence_end:
return;	}
compiler_logical_or_expression_end
(){
                                                            // 
                                                            //     target_op_load_constant(0);
                        loadi             (0);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_op_load_constant(); 
                        movebp            (-9);
                                                            //     target_op_branch(label_or, "_false");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2005);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch(); 
                        movebp            (-10);
                                                            //     target_end_branch_block(label_or, "_true");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2012);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            //     target_op_load_constant(1);
                        loadi             (1);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        target_op_load_constant(); 
                        movebp            (-9);
                                                            //     target_end_branch_block(label_or, "_false");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2018);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_return_statement() {
compiler_logical_or_expression_end_end:
return;	}
compiler_return_statement
(){
                                                            // 
                                                            //     target_op_branch(compiler_function_name, "_end");
                        loadi             (-6309646+global);
                        store             (0+BP);
                        loadi             (2025);
                        store             (1+BP);
                        load              (1+BP);
                        store             (11+BP);
                        load              (0+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_assignment_statement(char variable_name[]) {
compiler_return_statement_end:
return;	}
compiler_assignment_statement
(){
                                                            //     int value;
                                                            //     int type[1];
                                                            //     int scope[1];
                                                            //     int temp_rvalue;
                                                            //     int temp_array_index;
                                                            // 
                                                            //     value = compiler_must_find_identifier(variable_name, type, scope);
                        load              (0+BP);
                        store             (6+BP);
                        loadi             (2+BP);
                        store             (7+BP);
                        loadi             (3+BP);
                        store             (8+BP);
                        load              (8+BP);
                        store             (18+BP);
                        load              (7+BP);
                        store             (17+BP);
                        load              (6+BP);
                        store             (16+BP);
                        movebp            (16);
                        compiler_must_find_identifier(); 
                        movebp            (-16);
                        store             (1+BP);
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_global) {
                        loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (6+BP);
                        loadi             (1);
                        subtract          (6+BP);
                        if(equals())      goto compare_302_true;
                        loadi             (0);
                        if(always())      goto compare_302_false;
compare_302_true:       loadi             (1);
compare_302_false:      if(equals())      goto logical_and_303_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (6+BP);
                        loadi             (0);
                        subtract          (6+BP);
                        if(equals())      goto compare_304_true;
                        loadi             (0);
                        if(always())      goto compare_304_false;
compare_304_true:       loadi             (1);
compare_304_false:      if(equals())      goto logical_and_303_false;
                        loadi             (1);
                        if(always())      goto logical_and_303_true;
logical_and_303_false:  loadi             (0);
logical_and_303_true:   if(equals())      goto if_305_next;
                                                            //         target_op_store(value, Target_t_global);
                        load              (1+BP);
                        store             (6+BP);
                        loadi             (3);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_store(); 
                        movebp            (-15);
                                                            //         return;
                        if(always())      goto compiler_assignment_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_local) {
if_305_next:
if_305_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (6+BP);
                        loadi             (1);
                        subtract          (6+BP);
                        if(equals())      goto compare_306_true;
                        loadi             (0);
                        if(always())      goto compare_306_false;
compare_306_true:       loadi             (1);
compare_306_false:      if(equals())      goto logical_and_307_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (6+BP);
                        loadi             (1);
                        subtract          (6+BP);
                        if(equals())      goto compare_308_true;
                        loadi             (0);
                        if(always())      goto compare_308_false;
compare_308_true:       loadi             (1);
compare_308_false:      if(equals())      goto logical_and_307_false;
                        loadi             (1);
                        if(always())      goto logical_and_307_true;
logical_and_307_false:  loadi             (0);
logical_and_307_true:   if(equals())      goto if_309_next;
                                                            //         target_op_store(value, Target_t_local);
                        load              (1+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_store(); 
                        movebp            (-15);
                                                            //         return;
                        if(always())      goto compiler_assignment_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_global) {
if_309_next:
if_309_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (6+BP);
                        loadi             (2);
                        subtract          (6+BP);
                        if(equals())      goto compare_310_true;
                        loadi             (0);
                        if(always())      goto compare_310_false;
compare_310_true:       loadi             (1);
compare_310_false:      if(equals())      goto logical_and_311_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (6+BP);
                        loadi             (0);
                        subtract          (6+BP);
                        if(equals())      goto compare_312_true;
                        loadi             (0);
                        if(always())      goto compare_312_false;
compare_312_true:       loadi             (1);
compare_312_false:      if(equals())      goto logical_and_311_false;
                        loadi             (1);
                        if(always())      goto logical_and_311_true;
logical_and_311_false:  loadi             (0);
logical_and_311_true:   if(equals())      goto if_313_next;
                                                            //         target_op_store(value, Target_t_global_ix);
                        load              (1+BP);
                        store             (6+BP);
                        loadi             (4);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_store(); 
                        movebp            (-15);
                                                            //         return;
                        if(always())      goto compiler_assignment_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_local) {
if_313_next:
if_313_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (6+BP);
                        loadi             (2);
                        subtract          (6+BP);
                        if(equals())      goto compare_314_true;
                        loadi             (0);
                        if(always())      goto compare_314_false;
compare_314_true:       loadi             (1);
compare_314_false:      if(equals())      goto logical_and_315_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (6+BP);
                        loadi             (1);
                        subtract          (6+BP);
                        if(equals())      goto compare_316_true;
                        loadi             (0);
                        if(always())      goto compare_316_false;
compare_316_true:       loadi             (1);
compare_316_false:      if(equals())      goto logical_and_315_false;
                        loadi             (1);
                        if(always())      goto logical_and_315_true;
logical_and_315_false:  loadi             (0);
logical_and_315_true:   if(equals())      goto if_317_next;
                                                            //         target_op_store(value, Target_t_local_ix);
                        load              (1+BP);
                        store             (6+BP);
                        loadi             (2);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_store(); 
                        movebp            (-15);
                                                            //         return;
                        if(always())      goto compiler_assignment_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (type[0] == Compiler_t_integer_pointer && scope[0] == Compiler_t_local) {
if_317_next:
if_317_end:             loadi             (0);
                        loadx             ();
                        load              (2+BP+X);
                        store             (6+BP);
                        loadi             (0);
                        subtract          (6+BP);
                        if(equals())      goto compare_318_true;
                        loadi             (0);
                        if(always())      goto compare_318_false;
compare_318_true:       loadi             (1);
compare_318_false:      if(equals())      goto logical_and_319_false;
                        loadi             (0);
                        loadx             ();
                        load              (3+BP+X);
                        store             (6+BP);
                        loadi             (1);
                        subtract          (6+BP);
                        if(equals())      goto compare_320_true;
                        loadi             (0);
                        if(always())      goto compare_320_false;
compare_320_true:       loadi             (1);
compare_320_false:      if(equals())      goto logical_and_319_false;
                        loadi             (1);
                        if(always())      goto logical_and_319_true;
logical_and_319_false:  loadi             (0);
logical_and_319_true:   if(equals())      goto if_321_next;
                                                            //         temp_rvalue = compiler_allocate_temp_local();
                        movebp            (13);
                        compiler_allocate_temp_local(); 
                        movebp            (-13);
                        store             (4+BP);
                                                            //         temp_array_index = compiler_allocate_temp_local();
                        movebp            (13);
                        compiler_allocate_temp_local(); 
                        movebp            (-13);
                        store             (5+BP);
                                                            //         target_op_store(temp_rvalue, Target_t_local);       // temp_rvalue = A
                        load              (4+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_store(); 
                        movebp            (-15);
                                                            //         target_op_load_address(0, Target_t_ix);             // temp_array_index = X
                        loadi             (0);
                        store             (6+BP);
                        loadi             (0);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_load_address(); 
                        movebp            (-15);
                                                            //         target_op_store(temp_array_index, Target_t_local);
                        load              (5+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_store(); 
                        movebp            (-15);
                                                            //         target_op_load(value, Target_t_local);              // A = address held in local pointer variable
                        load              (1+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_load(); 
                        movebp            (-15);
                                                            //         target_op_add(temp_array_index, Target_t_local);    // X = A + temp_array_index
                        load              (5+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_add();  
                        movebp            (-15);
                                                            //         target_op_loadx();                          
                        movebp            (13);
                        target_op_loadx(); 
                        movebp            (-13);
                                                            //         target_op_load(temp_rvalue, Target_t_local);        // (X) = temp_rvalue
                        load              (4+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_load(); 
                        movebp            (-15);
                                                            //         target_op_store(0, Target_t_indirect);
                        loadi             (0);
                        store             (6+BP);
                        loadi             (5);
                        store             (7+BP);
                        load              (7+BP);
                        store             (16+BP);
                        load              (6+BP);
                        store             (15+BP);
                        movebp            (15);
                        target_op_store(); 
                        movebp            (-15);
                                                            //         compiler_free_temp_local(temp_array_index);
                        load              (5+BP);
                        store             (6+BP);
                        load              (6+BP);
                        store             (14+BP);
                        movebp            (14);
                        compiler_free_temp_local(); 
                        movebp            (-14);
                                                            //         compiler_free_temp_local(temp_rvalue);
                        load              (4+BP);
                        store             (6+BP);
                        load              (6+BP);
                        store             (14+BP);
                        movebp            (14);
                        compiler_free_temp_local(); 
                        movebp            (-14);
                                                            //         return;
                        if(always())      goto compiler_assignment_statement_end;
                                                            //     }
                                                            // 
                                                            //     error_compiler("left hand side of assignment statement must be an integer identifier or array element");
if_321_next:
if_321_end:             loadi             (2030);
                        store             (6+BP);
                        load              (6+BP);
                        store             (14+BP);
                        movebp            (14);
                        error_compiler(); 
                        movebp            (-14);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_assignment_statement_array_begin(int out_temp_array_index_cookie[]) {
compiler_assignment_statement_end:
return;	}
compiler_assignment_statement_array_begin
(){
                                                            // 
                                                            //     out_temp_array_index_cookie[0] = compiler_allocate_temp_local();
                        loadi             (0);
                        store             (1+BP);
                        movebp            (8);
                        compiler_allocate_temp_local(); 
                        movebp            (-8);
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
                                                            //     target_op_store(out_temp_array_index_cookie[0], Target_t_local);
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (1+BP);
                        load              (0+BP);
                        add               (1+BP);
                        loadx             ();
                        load              (X);
                        store             (1+BP);
                        loadi             (1);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_store(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_assignment_statement_array_end(int temp_array_index_cookie[]) {
compiler_assignment_statement_array_begin_end:
return;	}
compiler_assignment_statement_array_end
(){
                                                            //     int temp_expression;
                                                            // 
                                                            //     temp_expression = compiler_allocate_temp_local();
                        movebp            (9);
                        compiler_allocate_temp_local(); 
                        movebp            (-9);
                        store             (1+BP);
                                                            // 
                                                            //     target_op_store(temp_expression, Target_t_local);
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_store(); 
                        movebp            (-11);
                                                            //     target_op_load(temp_array_index_cookie[0], Target_t_local);
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_load(); 
                        movebp            (-11);
                                                            //     target_op_loadx();
                        movebp            (9);
                        target_op_loadx(); 
                        movebp            (-9);
                                                            //     target_op_load(temp_expression, Target_t_local);
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        store             (3+BP);
                        load              (3+BP);
                        store             (12+BP);
                        load              (2+BP);
                        store             (11+BP);
                        movebp            (11);
                        target_op_load(); 
                        movebp            (-11);
                                                            // 
                                                            //     compiler_free_temp_local(temp_expression);
                        load              (1+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            //     compiler_free_temp_local(temp_array_index_cookie[0]);
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        store             (2+BP);
                        load              (2+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_free_temp_local(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_while_statement_begin(char out_label_while[]) {
compiler_assignment_statement_array_end_end:
return;	}
compiler_while_statement_begin
(){
                                                            // 
                                                            //     target_get_label("while", out_label_while);
                        loadi             (2116);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_get_label(); 
                        movebp            (-10);
                                                            // 	target_begin_branch_block(out_label_while, "_end");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2122);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            //     target_begin_back_branch_block(out_label_while, "_test");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2127);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_back_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_while_statement_end(char label_while[]) {
compiler_while_statement_begin_end:
return;	}
compiler_while_statement_end
(){
                                                            // 
                                                            //     target_op_branch_back(label_while, "_test");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2133);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_back(); 
                        movebp            (-10);
                                                            // 	target_end_back_branch_block(label_while, "_test");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2139);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_back_branch_block(); 
                        movebp            (-10);
                                                            //     target_end_branch_block(label_while, "_end");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2145);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_while_statement_test(char label_while[]) {
compiler_while_statement_end_end:
return;	}
compiler_while_statement_test
(){
                                                            // 
                                                            //     target_op_test();
                        movebp            (8);
                        target_op_test(); 
                        movebp            (-8);
                                                            //     target_op_branch_if_false(label_while, "_end");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2150);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_false(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ===========================================================================
                                                            // //
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_if_statement_test_fn(char out_label_if[]) {
compiler_while_statement_test_end:
return;	}
compiler_if_statement_test_fn
(){
                                                            // 
                                                            //     target_get_label("if", out_label_if);
                        loadi             (2155);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_get_label(); 
                        movebp            (-10);
                                                            // 
                                                            //     target_op_test();
                        movebp            (8);
                        target_op_test(); 
                        movebp            (-8);
                                                            // 	target_begin_branch_block(out_label_if, "_end");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2158);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            // 	target_begin_branch_block(out_label_if, "_next");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2163);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_begin_branch_block(); 
                        movebp            (-10);
                                                            //     target_op_branch_if_false(out_label_if, "_next");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2169);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch_if_false(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_if_statement_else_fn(char label_if[]) {
compiler_if_statement_test_fn_end:
return;	}
compiler_if_statement_else_fn
(){
                                                            // 
                                                            //     target_op_branch(label_if, "_end");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2175);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_op_branch(); 
                        movebp            (-10);
                                                            //     target_end_branch_block(label_if, "_next");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2180);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_if_statement_no_else_fn(char label_if[]) {
compiler_if_statement_else_fn_end:
return;	}
compiler_if_statement_no_else_fn
(){
                                                            // 
                                                            //     target_end_branch_block(label_if, "_next");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2186);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            //     target_end_branch_block(label_if, "_end");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2192);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // compiler_if_statement_else_end_fn(char label_if[]) {
compiler_if_statement_no_else_fn_end:
return;	}
compiler_if_statement_else_end_fn
(){
                                                            // 
                                                            //     target_end_branch_block(label_if, "_end");
                        load              (0+BP);
                        store             (1+BP);
                        loadi             (2197);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        target_end_branch_block(); 
                        movebp            (-10);
                                                            // }
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "syntax.h"
                                                            // #endif
                                                            // 
                                                            // // C-Subset Syntax 
                                                            // //
                                                            // // program
                                                            // //            global-declaration-list
                                                            // //
                                                            // // global-declaration
                                                            // //            declaration
                                                            // //            function-definition
                                                            // //
                                                            // // global-declaration-list
                                                            // //            global-declaration global-declaration-list
                                                            // //            global-declaration
                                                            // //
                                                            // // function-definition
                                                            // //            identifier( function-argument-declaration-list ) function-compound-statement
                                                            // //            identifier( ) function-compound-statement
                                                            // //
                                                            // // function-compound-statement
                                                            // //            { local-declaration-list statement-list } 
                                                            // //            { statement-list } 
                                                            // //
                                                            // // declaration
                                                            // //            type-specifier identifier ;
                                                            // //            type-specifier identifier [ integer-constant ] ;
                                                            // //            type-specifier identifier [ identifier ] ;
                                                            // //            enum { enumerator-list } ;
                                                            // //
                                                            // // local-declaration-list
                                                            // //            declaration local-declaration-list
                                                            // //            declaration
                                                            // //
                                                            // // enumerator
                                                            // //            identifier = integer-constant
                                                            // //            identifier
                                                            // //
                                                            // // enumerator-list
                                                            // //            enumerator , enumerator-list
                                                            // //            enumerator
                                                            // //            
                                                            // // function-argument-declaration-list
                                                            // //            function-argument-declaration , function-argument-declaration-list
                                                            // //            function-argument-declaration
                                                            // //
                                                            // // function-argument-declaration
                                                            // //            type-specifier identifier
                                                            // //            type-specifier identifier []
                                                            // //
                                                            // // type-specifier
                                                            // //            int
                                                            // //            char
                                                            // //
                                                            // // statement
                                                            // //           if-statement
                                                            // //           while-statement
                                                            // //           compound-statement
                                                            // //           assignment-statement ;
                                                            // //           expression-statement ;
                                                            // //           return-statement ;
                                                            // //
                                                            // // statement-list
                                                            // //            statement statement-list
                                                            // //            statement
                                                            // //            
                                                            // // if-statement
                                                            // //            if ( expression ) statement else statement
                                                            // //            if ( expression ) statement
                                                            // //
                                                            // // while-statement
                                                            // //            while ( expression ) statement
                                                            // //
                                                            // // assignment-statement
                                                            // //            identifier = expression
                                                            // //            identifier [ expression ] = expression
                                                            // //            
                                                            // // expression-statement
                                                            // //           expression
                                                            // //
                                                            // // return-statement
                                                            // //            return expression
                                                            // //            return
                                                            // //
                                                            // // compound-statement
                                                            // //            { statement-list } 
                                                            // //
                                                            // // expression
                                                            // //            logical-or-expression
                                                            // //
                                                            // // logical-or-expression
                                                            // //            logical-and-expression logical-or-switch-sequence
                                                            // //            logical-and-expression
                                                            // //
                                                            // // logical-or-switch-sequence
                                                            // //            || logical-and-expression logical-or-switch-sequence
                                                            // //            || logical-and-expression
                                                            // //
                                                            // // logical-and-expression
                                                            // //            equality-expression logical-and-switch-sequence
                                                            // //            equality-expression
                                                            // //
                                                            // // logical-and-switch-sequence
                                                            // //            && equality-expression logical-and-switch-sequence
                                                            // //            && equality-expression
                                                            // //
                                                            // // equality-expression
                                                            // //            relational-expression equality-expression-sequence
                                                            // //            relational-expression
                                                            // //
                                                            // // equality-expression-sequence
                                                            // //            equality-operator-operator relational-expression equality-expression-sequence
                                                            // //            equality-operator-operator relational-expression
                                                            // //
                                                            // // equality-operator
                                                            // //            one-of == !=
                                                            // //
                                                            // // relational-expression
                                                            // //            additive-expression relational-expression-sequence
                                                            // //            additive-expression
                                                            // //
                                                            // // relational-expression-sequence
                                                            // //            relational-operator additive-expression relational-expression-sequence
                                                            // //            relational-operator additive-expression
                                                            // //
                                                            // // relational-operator
                                                            // //           one-of < <= > >=
                                                            // //
                                                            // // additive-expression
                                                            // //            multiplicative-expression additive-expression-sequence
                                                            // //            multiplicative-expression
                                                            // //
                                                            // // additive-expression-sequence
                                                            // //           additive-operator multiplicative-expression additive-expression-sequence
                                                            // //           additive-operator multiplicative-expression
                                                            // //
                                                            // // additive-operator
                                                            // //           one-of  + - 
                                                            // //            
                                                            // // multiplicative-expression
                                                            // //            unary-expression multiplicative-expression-sequence
                                                            // //            unary-expression
                                                            // //
                                                            // // multiplicative-expression-sequence
                                                            // //            multiplicative-operator unary-expression multiplicative-expression-sequence
                                                            // //            multiplicative-operator unary-expression
                                                            // //
                                                            // // multiplicative-operator
                                                            // //           one-of  * / 
                                                            // //
                                                            // // unary-expression
                                                            // //            unary-operator unary-expression
                                                            // //            primary-expression
                                                            // //            
                                                            // // unary-operator
                                                            // //            one of  ! + - 
                                                            // //
                                                            // // primary-expression
                                                            // //            built-in-function
                                                            // //            identifier ( function-call-argument-list )
                                                            // //            identifier [ expression ]
                                                            // //            identifier
                                                            // //            integer-constant
                                                            // //            character-constant
                                                            // //            ( expression )
                                                            // //
                                                            // // function-call-argument-list
                                                            // //            function-call-argument , function-call-argument-list
                                                            // //            function-call-argument
                                                            // //
                                                            // // function-call-argument
                                                            // //            string-literal
                                                            // //            pointer-identifier
                                                            // //            expression
                                                            // //
                                                            // // built-in-function
                                                            // //           fgetc ( stdin )
                                                            // //           fputc ( expression , stdout)
                                                            // //           fputc ( expression , stderr)
                                                            // //           exit  ( expression )
                                                            // //           debug ( expression )
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // built-in-function
                                                            // //           fgetc ( stdin )
                                                            // //           fputc ( expression , stdout)
                                                            // //           fputc ( expression , stderr)
                                                            // //           exit  ( expression )
                                                            // //           debug ( expression )
                                                            // //
                                                            // syntax_built_in_function() {
compiler_if_statement_else_end_fn_end:
return;	}
syntax_built_in_function
(){
                                                            // 
                                                            //     // ----- fgetc  ( stdin )
                                                            //     //
                                                            //     if (token_advance_if("fgetc")) {
                        loadi             (2202);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto if_322_next;
                                                            //         if (! (token_advance_if("(") && token_advance_if("stdin") && token_advance_if(")"))) {
                        loadi             (2208);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto logical_and_323_false;
                        loadi             (2210);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto logical_and_323_false;
                        loadi             (2216);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto logical_and_323_false;
                        loadi             (1);
                        if(always())      goto logical_and_323_true;
logical_and_323_false:  loadi             (0);
logical_and_323_true:   if(notequals())   goto logical_not_324_false;
                        loadi             (1);
                        if(always())      goto logical_not_324_true;
logical_not_324_false:  loadi             (0);
logical_not_324_true:   if(equals())      goto if_325_next;
                                                            //             error_syntax("fgetc(stdin) expected");
                        loadi             (2218);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         compiler_built_in_function_fgetc();
if_325_next:
if_325_end:             movebp            (8);
                        compiler_built_in_function_fgetc(); 
                        movebp            (-8);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_built_in_function_end;
                                                            //     }
                                                            // 
                                                            //     // ----- fputc ( expression , stdout)
                                                            //     // ----- fputc ( expression , stderr)
                                                            //     //
                                                            //     if (token_advance_if("fputc")) {
if_322_next:
if_322_end:             loadi             (2240);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto if_326_next;
                                                            // 
                                                            //         if (! token_advance_if("(")) {
                        loadi             (2246);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_327_false;
                        loadi             (1);
                        if(always())      goto logical_not_327_true;
logical_not_327_false:  loadi             (0);
logical_not_327_true:   if(equals())      goto if_328_next;
                                                            //             error_syntax("opening parenthesis expected after fputc");
                        loadi             (2248);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (! syntax_expression()) {
if_328_next:
if_328_end:             movebp            (8);
                        syntax_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_329_false;
                        loadi             (1);
                        if(always())      goto logical_not_329_true;
logical_not_329_false:  loadi             (0);
logical_not_329_true:   if(equals())      goto if_330_next;
                                                            //             error_syntax("expression expected after fputc opening parenthesis");
                        loadi             (2289);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if(",")) {
if_330_next:
if_330_end:             loadi             (2341);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_331_false;
                        loadi             (1);
                        if(always())      goto logical_not_331_true;
logical_not_331_false:  loadi             (0);
logical_not_331_true:   if(equals())      goto if_332_next;
                                                            //             error_syntax("fputc takes two arguments");
                        loadi             (2343);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (token_advance_if("stdout")) {
if_332_next:
if_332_end:             loadi             (2369);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto if_333_next;
                                                            //             compiler_built_in_function_fputc_stdout();
                        movebp            (8);
                        compiler_built_in_function_fputc_stdout(); 
                        movebp            (-8);
                                                            //         }
                                                            //         else if (token_advance_if("stderr")) {
                        if(always())      goto if_333_end;
if_333_next:            loadi             (2376);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto if_334_next;
                                                            //             compiler_built_in_function_fputc_stderr();
                        movebp            (8);
                        compiler_built_in_function_fputc_stderr(); 
                        movebp            (-8);
                                                            //         }
                                                            //         else {
                        if(always())      goto if_334_end;
                                                            //             error_syntax("second argument of fputc must be stdout or stderr");
if_334_next:            loadi             (2383);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if(")")) {
if_334_end:
if_333_end:             loadi             (2433);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_335_false;
                        loadi             (1);
                        if(always())      goto logical_not_335_true;
logical_not_335_false:  loadi             (0);
logical_not_335_true:   if(equals())      goto if_336_next;
                                                            //             error_syntax("closing parenthesis expected");
                        loadi             (2435);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }   
                                                            //             
                                                            //         return True;
if_336_next:
if_336_end:             loadi             (1);
                        if(always())      goto syntax_built_in_function_end;
                                                            //     }
                                                            // 
                                                            //     // ----- exit ( expression )
                                                            //     //
                                                            //     if (token_advance_if("exit")) {
if_326_next:
if_326_end:             loadi             (2464);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto if_337_next;
                                                            // 
                                                            //         if (! token_advance_if("(")) {
                        loadi             (2469);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_338_false;
                        loadi             (1);
                        if(always())      goto logical_not_338_true;
logical_not_338_false:  loadi             (0);
logical_not_338_true:   if(equals())      goto if_339_next;
                                                            //             error_syntax("opening parenthesis expected after exit");
                        loadi             (2471);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (! syntax_expression()) {
if_339_next:
if_339_end:             movebp            (8);
                        syntax_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_340_false;
                        loadi             (1);
                        if(always())      goto logical_not_340_true;
logical_not_340_false:  loadi             (0);
logical_not_340_true:   if(equals())      goto if_341_next;
                                                            //             error_syntax("expression expected after exit opening parenthesis");
                        loadi             (2511);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if(")")) {
if_341_next:
if_341_end:             loadi             (2562);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_342_false;
                        loadi             (1);
                        if(always())      goto logical_not_342_true;
logical_not_342_false:  loadi             (0);
logical_not_342_true:   if(equals())      goto if_343_next;
                                                            //             error_syntax("closing parenthesis expected");
                        loadi             (2564);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         compiler_built_in_function_exit();
if_343_next:
if_343_end:             movebp            (8);
                        compiler_built_in_function_exit(); 
                        movebp            (-8);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_built_in_function_end;
                                                            //     }
                                                            // 
                                                            //     // ----- debug ( expression )
                                                            //     //
                                                            //     if (token_advance_if("debug")) {
if_337_next:
if_337_end:             loadi             (2593);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto if_344_next;
                                                            // 
                                                            //         if (! token_advance_if("(")) {
                        loadi             (2599);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_345_false;
                        loadi             (1);
                        if(always())      goto logical_not_345_true;
logical_not_345_false:  loadi             (0);
logical_not_345_true:   if(equals())      goto if_346_next;
                                                            //             error_syntax("opening parenthesis expected after debug");
                        loadi             (2601);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (! syntax_expression()) {
if_346_next:
if_346_end:             movebp            (8);
                        syntax_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_347_false;
                        loadi             (1);
                        if(always())      goto logical_not_347_true;
logical_not_347_false:  loadi             (0);
logical_not_347_true:   if(equals())      goto if_348_next;
                                                            //             error_syntax("expression expected after debug opening parenthesis");
                        loadi             (2642);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if(")")) {
if_348_next:
if_348_end:             loadi             (2694);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_349_false;
                        loadi             (1);
                        if(always())      goto logical_not_349_true;
logical_not_349_false:  loadi             (0);
logical_not_349_true:   if(equals())      goto if_350_next;
                                                            //             error_syntax("closing parenthesis expected");
                        loadi             (2696);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         compiler_built_in_function_debug();
if_350_next:
if_350_end:             movebp            (8);
                        compiler_built_in_function_debug(); 
                        movebp            (-8);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_built_in_function_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_344_next:
if_344_end:             loadi             (0);
                        if(always())      goto syntax_built_in_function_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // function-call-argument
                                                            // //            string-literal
                                                            // //            pointer-identifier
                                                            // //            expression
                                                            // //
                                                            // syntax_function_call_argument() {
syntax_built_in_function_end:
return;	}
syntax_function_call_argument
(){
                                                            // 
                                                            //     if (token_type_is(Token_t_string_literal)) {
                        loadi             (3);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_type_is();  
                        movebp            (-9);
                        if(equals())      goto if_351_next;
                                                            //         compiler_function_call_string_literal_argument(token_text); // >>>>>>>>>>
                        loadi             (-1049611+global);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_function_call_string_literal_argument(); 
                        movebp            (-9);
                                                            //         token_advance();
                        movebp            (8);
                        token_advance();  
                        movebp            (-8);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_function_call_argument_end;
                                                            //     }
                                                            //     
                                                            //     // need to check symbol table to determine if identifier needs to be passed as a pointer
                                                            //     if (token_type_is(Token_t_identifier) && (! token_lookahead_text_is("["))) {
if_351_next:
if_351_end:             loadi             (4);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_type_is();  
                        movebp            (-9);
                        if(equals())      goto logical_and_352_false;
                        loadi             (2725);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_lookahead_text_is(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_353_false;
                        loadi             (1);
                        if(always())      goto logical_not_353_true;
logical_not_353_false:  loadi             (0);
logical_not_353_true:   if(equals())      goto logical_and_352_false;
                        loadi             (1);
                        if(always())      goto logical_and_352_true;
logical_and_352_false:  loadi             (0);
logical_and_352_true:   if(equals())      goto if_354_next;
                                                            //         if (compiler_function_call_pointer_argument(token_text)) { // >>>>>>>>>>
                        loadi             (-1049611+global);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_function_call_pointer_argument(); 
                        movebp            (-9);
                        if(equals())      goto if_355_next;
                                                            //             token_advance();
                        movebp            (8);
                        token_advance();  
                        movebp            (-8);
                                                            //             return True;
                        loadi             (1);
                        if(always())      goto syntax_function_call_argument_end;
                                                            //         }
                                                            //     }
if_355_next:
                                                            // 
                                                            //     if (syntax_expression()) {
if_355_end:
if_354_next:
if_354_end:             movebp            (8);
                        syntax_expression(); 
                        movebp            (-8);
                        if(equals())      goto if_356_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_function_call_argument_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_356_next:
if_356_end:             loadi             (0);
                        if(always())      goto syntax_function_call_argument_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // function-call-argument-list
                                                            // //            function-call-argument , function-call-argument-list
                                                            // //            function-call-argument
                                                            // //
                                                            // syntax_function_call_argument_list(int argument_no, int function_argument_count[]) {
syntax_function_call_argument_end:
return;	}
syntax_function_call_argument_list
(){
                                                            //     int cookie[1];
                                                            // 
                                                            //     if (! syntax_function_call_argument()) {
                        movebp            (9);
                        syntax_function_call_argument(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_357_false;
                        loadi             (1);
                        if(always())      goto logical_not_357_true;
logical_not_357_false:  loadi             (0);
logical_not_357_true:   if(equals())      goto if_358_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_function_call_argument_list_end;
                                                            //     }
                                                            // 
                                                            //     function_argument_count[0] = function_argument_count[0] + 1;
if_358_next:
if_358_end:             loadi             (0);
                        store             (3+BP);
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (4+BP);
                        load              (3+BP);
                        loadx             ();
                        load              (4+BP);
                        store             (3+BP);
                        loadi             (X);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (3+BP);
                        store             (X);
                                                            // 
                                                            //     compiler_function_call_argument_prepare(cookie); // >>>>>>>>>>
                        loadi             (2+BP);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        compiler_function_call_argument_prepare(); 
                        movebp            (-10);
                                                            // 
                                                            //     if (token_advance_if(",")) {
                        loadi             (2727);
                        store             (3+BP);
                        load              (3+BP);
                        store             (10+BP);
                        movebp            (10);
                        token_advance_if(); 
                        movebp            (-10);
                        if(equals())      goto if_359_next;
                                                            //         syntax_function_call_argument_list(argument_no + 1, function_argument_count);
                        load              (0+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (3+BP);
                        load              (1+BP);
                        store             (4+BP);
                        load              (4+BP);
                        store             (12+BP);
                        load              (3+BP);
                        store             (11+BP);
                        movebp            (11);
                        syntax_function_call_argument_list(); 
                        movebp            (-11);
                                                            //     }
                                                            // 
                                                            //     compiler_function_call_argument_pass(argument_no + 1, function_argument_count[0], cookie); // >>>>>>>>>>
if_359_next:
if_359_end:             load              (0+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (3+BP);
                        loadi             (0);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
                        store             (4+BP);
                        loadi             (2+BP);
                        store             (5+BP);
                        load              (5+BP);
                        store             (14+BP);
                        load              (4+BP);
                        store             (13+BP);
                        load              (3+BP);
                        store             (12+BP);
                        movebp            (12);
                        compiler_function_call_argument_pass(); 
                        movebp            (-12);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_function_call_argument_list_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // primary-expression
                                                            // //            built-in-function
                                                            // //            identifier ( function-call-argument-list )
                                                            // //            identifier [ expression ]
                                                            // //            identifier
                                                            // //            integer-constant
                                                            // //            character-constant
                                                            // //            ( expression )
                                                            // //
                                                            // syntax_primary_expression() {
syntax_function_call_argument_list_end:
return;	}
syntax_primary_expression
(){
                                                            //     char cookie[Str_size];
                                                            //     char name[Str_size];
                                                            //     int function_argument_count[1];
                                                            // 
                                                            //     // ------ built-in-function
                                                            // 
                                                            //     if (syntax_built_in_function()) {
                        movebp            (521);
                        syntax_built_in_function(); 
                        movebp            (-521);
                        if(equals())      goto if_360_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_primary_expression_end;
                                                            //     }
                                                            // 
                                                            //     // ------ identifier ( function-call-argument-list )
                                                            // 
                                                            //     if (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) {
if_360_next:
if_360_end:             loadi             (4);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_type_is();  
                        movebp            (-522);
                        if(equals())      goto logical_and_361_false;
                        loadi             (2729);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_lookahead_text_is(); 
                        movebp            (-522);
                        if(equals())      goto logical_and_361_false;
                        loadi             (1);
                        if(always())      goto logical_and_361_true;
logical_and_361_false:  loadi             (0);
logical_and_361_true:   if(equals())      goto if_362_next;
                                                            //         copy(name, token_text);
                        loadi             (256+BP);
                        store             (513+BP);
                        loadi             (-1049611+global);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        copy();           
                        movebp            (-523);
                                                            //         token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            //         token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            // 
                                                            //         compiler_function_call_prepare(name, cookie); // >>>>>>>>>>
                        loadi             (256+BP);
                        store             (513+BP);
                        loadi             (0+BP);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        compiler_function_call_prepare(); 
                        movebp            (-523);
                                                            // 
                                                            //         function_argument_count[0] = 0;
                        loadi             (0);
                        store             (513+BP);
                        loadi             (0);
                        store             (514+BP);
                        load              (513+BP);
                        loadx             ();
                        load              (514+BP);
                        store             (512+BP+X);
                                                            //         syntax_function_call_argument_list(0, function_argument_count);
                        loadi             (0);
                        store             (513+BP);
                        loadi             (512+BP);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        syntax_function_call_argument_list(); 
                        movebp            (-523);
                                                            // 
                                                            //         compiler_function_call_execute(cookie, function_argument_count[0]); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (513+BP);
                        loadi             (0);
                        loadx             ();
                        load              (512+BP+X);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        compiler_function_call_execute(); 
                        movebp            (-523);
                                                            //                 
                                                            //         if (! token_advance_if(")")) {
                        loadi             (2731);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_advance_if(); 
                        movebp            (-522);
                        if(notequals())   goto logical_not_363_false;
                        loadi             (1);
                        if(always())      goto logical_not_363_true;
logical_not_363_false:  loadi             (0);
logical_not_363_true:   if(equals())      goto if_364_next;
                                                            //             error_syntax("closing parenthesis expected after function call expression");
                        loadi             (2733);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        error_syntax();   
                        movebp            (-522);
                                                            //         }
                                                            // 
                                                            //         return True;
if_364_next:
if_364_end:             loadi             (1);
                        if(always())      goto syntax_primary_expression_end;
                                                            //     }
                                                            // 
                                                            //     // ------ identifier [ expression ]
                                                            // 
                                                            //     if (token_type_is(Token_t_identifier) && token_lookahead_text_is("[")) {
if_362_next:
if_362_end:             loadi             (4);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_type_is();  
                        movebp            (-522);
                        if(equals())      goto logical_and_365_false;
                        loadi             (2793);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_lookahead_text_is(); 
                        movebp            (-522);
                        if(equals())      goto logical_and_365_false;
                        loadi             (1);
                        if(always())      goto logical_and_365_true;
logical_and_365_false:  loadi             (0);
logical_and_365_true:   if(equals())      goto if_366_next;
                                                            //         copy(name, token_text);
                        loadi             (256+BP);
                        store             (513+BP);
                        loadi             (-1049611+global);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        copy();           
                        movebp            (-523);
                                                            //         token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            //         token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            // 
                                                            //         if (! syntax_expression()) {
                        movebp            (521);
                        syntax_expression(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_367_false;
                        loadi             (1);
                        if(always())      goto logical_not_367_true;
logical_not_367_false:  loadi             (0);
logical_not_367_true:   if(equals())      goto if_368_next;
                                                            //             error_syntax("expression expected after opening bracket");
                        loadi             (2795);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        error_syntax();   
                        movebp            (-522);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if("]")) {
if_368_next:
if_368_end:             loadi             (2837);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_advance_if(); 
                        movebp            (-522);
                        if(notequals())   goto logical_not_369_false;
                        loadi             (1);
                        if(always())      goto logical_not_369_true;
logical_not_369_false:  loadi             (0);
logical_not_369_true:   if(equals())      goto if_370_next;
                                                            //             error_syntax("closing bracket expected");
                        loadi             (2839);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        error_syntax();   
                        movebp            (-522);
                                                            //         }
                                                            // 
                                                            //         compiler_primary_expression_array_index(); // >>>>>>>>>>
if_370_next:
if_370_end:             movebp            (521);
                        compiler_primary_expression_array_index(); 
                        movebp            (-521);
                                                            //         compiler_primary_expression_identifier(name); // >>>>>>>>>>
                        loadi             (256+BP);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        compiler_primary_expression_identifier(); 
                        movebp            (-522);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_primary_expression_end;
                                                            //     }
                                                            // 
                                                            //     // ------ identifier
                                                            // 
                                                            //     if (token_type_is(Token_t_identifier)) {
if_366_next:
if_366_end:             loadi             (4);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_type_is();  
                        movebp            (-522);
                        if(equals())      goto if_371_next;
                                                            //         compiler_primary_expression_identifier(token_text); // >>>>>>>>>>
                        loadi             (-1049611+global);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        compiler_primary_expression_identifier(); 
                        movebp            (-522);
                                                            //         token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_primary_expression_end;
                                                            //     }
                                                            // 
                                                            //     // ------ integer-constant
                                                            // 
                                                            //     if (token_type_is(Token_t_integer_constant)) {
if_371_next:
if_371_end:             loadi             (2);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_type_is();  
                        movebp            (-522);
                        if(equals())      goto if_372_next;
                                                            //         compiler_primary_expression_integer_constant(token_text); // >>>>>>>>>>       
                        loadi             (-1049611+global);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        compiler_primary_expression_integer_constant(); 
                        movebp            (-522);
                                                            //         token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_primary_expression_end;
                                                            //     }
                                                            // 
                                                            //     // ----- character-constant
                                                            // 
                                                            //     if (token_type_is(Token_t_character_constant)) {
if_372_next:
if_372_end:             loadi             (1);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_type_is();  
                        movebp            (-522);
                        if(equals())      goto if_373_next;
                                                            //         compiler_primary_expression_character_constant(token_text[0]); // >>>>>>>>>>        
                        loadi             (0);
                        loadx             ();
                        load              (-1049611+global+X);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        compiler_primary_expression_character_constant(); 
                        movebp            (-522);
                                                            //         token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_primary_expression_end;
                                                            //     }
                                                            // 
                                                            //     // ------ ( expression )
                                                            // 
                                                            //     if (token_advance_if("(")) {
if_373_next:
if_373_end:             loadi             (2864);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_advance_if(); 
                        movebp            (-522);
                        if(equals())      goto if_374_next;
                                                            //         if (! syntax_expression()) {
                        movebp            (521);
                        syntax_expression(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_375_false;
                        loadi             (1);
                        if(always())      goto logical_not_375_true;
logical_not_375_false:  loadi             (0);
logical_not_375_true:   if(equals())      goto if_376_next;
                                                            //             error_syntax("expression expected after opening parenthesis");
                        loadi             (2866);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        error_syntax();   
                        movebp            (-522);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if(")")) {
if_376_next:
if_376_end:             loadi             (2912);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_advance_if(); 
                        movebp            (-522);
                        if(notequals())   goto logical_not_377_false;
                        loadi             (1);
                        if(always())      goto logical_not_377_true;
logical_not_377_false:  loadi             (0);
logical_not_377_true:   if(equals())      goto if_378_next;
                                                            //             error_syntax("closing parenthesis expected after expression");
                        loadi             (2914);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        error_syntax();   
                        movebp            (-522);
                                                            //         }
                                                            // 
                                                            //         return True;
if_378_next:
if_378_end:             loadi             (1);
                        if(always())      goto syntax_primary_expression_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_374_next:
if_374_end:             loadi             (0);
                        if(always())      goto syntax_primary_expression_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // unary-operator
                                                            // //            one of  ! + - 
                                                            // //
                                                            // syntax_unary_operator(char s[]) {
syntax_primary_expression_end:
return;	}
syntax_unary_operator
(){
                                                            //  
                                                            //     return contains(" ! + - ", s);
                        loadi             (2960);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        contains();       
                        movebp            (-10);
                        if(always())      goto syntax_unary_operator_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // unary-expression
                                                            // //            unary-operator unary-expression
                                                            // //            primary-expression
                                                            // //            
                                                            // syntax_unary_expression() {
syntax_unary_operator_end:
return;	}
syntax_unary_expression
(){
                                                            //     char operator_text[Str_size];
                                                            // 
                                                            //     if (token_type_is(Token_t_symbol) && syntax_unary_operator(token_text)) {
                        loadi             (5);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_type_is();  
                        movebp            (-265);
                        if(equals())      goto logical_and_379_false;
                        loadi             (-1049611+global);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        syntax_unary_operator(); 
                        movebp            (-265);
                        if(equals())      goto logical_and_379_false;
                        loadi             (1);
                        if(always())      goto logical_and_379_true;
logical_and_379_false:  loadi             (0);
logical_and_379_true:   if(equals())      goto if_380_next;
                                                            //         copy(operator_text, token_text);
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //         token_advance();
                        movebp            (264);
                        token_advance();  
                        movebp            (-264);
                                                            // 
                                                            //         if (! syntax_unary_expression()) {
                        movebp            (264);
                        syntax_unary_expression(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_381_false;
                        loadi             (1);
                        if(always())      goto logical_not_381_true;
logical_not_381_false:  loadi             (0);
logical_not_381_true:   if(equals())      goto if_382_next;
                                                            //             error_syntax("expression expected after unary operator");
                        loadi             (2968);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //         }
                                                            //                   
                                                            //         compiler_unary_expression(operator_text); // >>>>>>>>>>
if_382_next:
if_382_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_unary_expression(); 
                        movebp            (-265);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_unary_expression_end;
                                                            //     }
                                                            // 
                                                            //     return syntax_primary_expression();
if_380_next:
if_380_end:             movebp            (264);
                        syntax_primary_expression(); 
                        movebp            (-264);
                        if(always())      goto syntax_unary_expression_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // multiplicative-operator
                                                            // //           one-of  * / 
                                                            // //
                                                            // syntax_multiplicative_operator(char s[]) {
syntax_unary_expression_end:
return;	}
syntax_multiplicative_operator
(){
                                                            //  
                                                            //     return contains(" * / ", s);
                        loadi             (3009);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        contains();       
                        movebp            (-10);
                        if(always())      goto syntax_multiplicative_operator_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // multiplicative-expression-sequence
                                                            // //            multiplicative-operator unary-expression multiplicative-expression-sequence
                                                            // //            multiplicative-operator unary-expression
                                                            // //
                                                            // syntax_multiplicative_expression_sequence() {
syntax_multiplicative_operator_end:
return;	}
syntax_multiplicative_expression_sequence
(){
                                                            //     int cookie;
                                                            //     char operator_text[Str_size];
                                                            // 
                                                            //     if (! (token_type_is(Token_t_symbol) && syntax_multiplicative_operator(token_text))) {
                        loadi             (5);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_type_is();  
                        movebp            (-266);
                        if(equals())      goto logical_and_383_false;
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        syntax_multiplicative_operator(); 
                        movebp            (-266);
                        if(equals())      goto logical_and_383_false;
                        loadi             (1);
                        if(always())      goto logical_and_383_true;
logical_and_383_false:  loadi             (0);
logical_and_383_true:   if(notequals())   goto logical_not_384_false;
                        loadi             (1);
                        if(always())      goto logical_not_384_true;
logical_not_384_false:  loadi             (0);
logical_not_384_true:   if(equals())      goto if_385_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_multiplicative_expression_sequence_end;
                                                            //     }
                                                            // 
                                                            //     copy(operator_text, token_text);
if_385_next:
if_385_end:             loadi             (1+BP);
                        store             (257+BP);
                        loadi             (-1049611+global);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //     token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            // 
                                                            //     cookie = compiler_multiplicative_expression_sequence_begin(); // >>>>>>>>>>
                        movebp            (265);
                        compiler_multiplicative_expression_sequence_begin(); 
                        movebp            (-265);
                        store             (0+BP);
                                                            // 
                                                            //     if (! syntax_unary_expression()) {
                        movebp            (265);
                        syntax_unary_expression(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_386_false;
                        loadi             (1);
                        if(always())      goto logical_not_386_true;
logical_not_386_false:  loadi             (0);
logical_not_386_true:   if(equals())      goto if_387_next;
                                                            //         error_syntax("expression expected after unary operator");
                        loadi             (3015);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //     }
                                                            // 
                                                            //     compiler_multiplicative_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>
if_387_next:
if_387_end:             loadi             (1+BP);
                        store             (257+BP);
                        load              (0+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        compiler_multiplicative_expression_sequence_end(); 
                        movebp            (-267);
                                                            // 
                                                            //     syntax_multiplicative_expression_sequence();
                        movebp            (265);
                        syntax_multiplicative_expression_sequence(); 
                        movebp            (-265);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_multiplicative_expression_sequence_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // multiplicative-expression
                                                            // //            unary-expression multiplicative-expression-sequence
                                                            // //            unary-expression
                                                            // //
                                                            // syntax_multiplicative_expression() {
syntax_multiplicative_expression_sequence_end:
return;	}
syntax_multiplicative_expression
(){
                                                            // 
                                                            //     if (! syntax_unary_expression()) {
                        movebp            (8);
                        syntax_unary_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_388_false;
                        loadi             (1);
                        if(always())      goto logical_not_388_true;
logical_not_388_false:  loadi             (0);
logical_not_388_true:   if(equals())      goto if_389_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_multiplicative_expression_end;
                                                            //     }
                                                            // 
                                                            //     syntax_multiplicative_expression_sequence();
if_389_next:
if_389_end:             movebp            (8);
                        syntax_multiplicative_expression_sequence(); 
                        movebp            (-8);
                                                            //     
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_multiplicative_expression_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // additive-operator
                                                            // //           one-of  + - 
                                                            // //            
                                                            // syntax_additive_operator(char s[]) {
syntax_multiplicative_expression_end:
return;	}
syntax_additive_operator
(){
                                                            // 
                                                            //     return contains(" + - ", s);
                        loadi             (3056);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        contains();       
                        movebp            (-10);
                        if(always())      goto syntax_additive_operator_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // additive-expression-sequence
                                                            // //           additive-operator multiplicative-expression additive-expression-sequence
                                                            // //           additive-operator multiplicative-expression
                                                            // //
                                                            // syntax_additive_expression_sequence() {
syntax_additive_operator_end:
return;	}
syntax_additive_expression_sequence
(){
                                                            //     int cookie;
                                                            //     char operator_text[Str_size];
                                                            // 
                                                            //     if (! (token_type_is(Token_t_symbol) && syntax_additive_operator(token_text)) ) {
                        loadi             (5);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_type_is();  
                        movebp            (-266);
                        if(equals())      goto logical_and_390_false;
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        syntax_additive_operator(); 
                        movebp            (-266);
                        if(equals())      goto logical_and_390_false;
                        loadi             (1);
                        if(always())      goto logical_and_390_true;
logical_and_390_false:  loadi             (0);
logical_and_390_true:   if(notequals())   goto logical_not_391_false;
                        loadi             (1);
                        if(always())      goto logical_not_391_true;
logical_not_391_false:  loadi             (0);
logical_not_391_true:   if(equals())      goto if_392_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_additive_expression_sequence_end;
                                                            //     }
                                                            // 
                                                            //     copy(operator_text, token_text);
if_392_next:
if_392_end:             loadi             (1+BP);
                        store             (257+BP);
                        loadi             (-1049611+global);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //     token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            // 
                                                            //     cookie = compiler_additive_expression_sequence_begin(); // >>>>>>>>>>
                        movebp            (265);
                        compiler_additive_expression_sequence_begin(); 
                        movebp            (-265);
                        store             (0+BP);
                                                            // 
                                                            //     if (! syntax_multiplicative_expression()) {
                        movebp            (265);
                        syntax_multiplicative_expression(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_393_false;
                        loadi             (1);
                        if(always())      goto logical_not_393_true;
logical_not_393_false:  loadi             (0);
logical_not_393_true:   if(equals())      goto if_394_next;
                                                            //         error_syntax("expression expected right of additive operator");
                        loadi             (3062);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //     }
                                                            // 
                                                            //     compiler_additive_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>
if_394_next:
if_394_end:             loadi             (1+BP);
                        store             (257+BP);
                        load              (0+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        compiler_additive_expression_sequence_end(); 
                        movebp            (-267);
                                                            // 
                                                            //     syntax_additive_expression_sequence();
                        movebp            (265);
                        syntax_additive_expression_sequence(); 
                        movebp            (-265);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_additive_expression_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // additive-expression
                                                            // //            multiplicative-expression additive-expression-sequence
                                                            // //            multiplicative-expression
                                                            // //
                                                            // syntax_additive_expression() {
syntax_additive_expression_sequence_end:
return;	}
syntax_additive_expression
(){
                                                            // 
                                                            //     if (! syntax_multiplicative_expression()) {
                        movebp            (8);
                        syntax_multiplicative_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_395_false;
                        loadi             (1);
                        if(always())      goto logical_not_395_true;
logical_not_395_false:  loadi             (0);
logical_not_395_true:   if(equals())      goto if_396_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_additive_expression_end;
                                                            //     }
                                                            // 
                                                            //     syntax_additive_expression_sequence();
if_396_next:
if_396_end:             movebp            (8);
                        syntax_additive_expression_sequence(); 
                        movebp            (-8);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_additive_expression_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // relational-operator
                                                            // //           one-of < <= > >=
                                                            // //
                                                            // syntax_relational_operator(char s[]) {
syntax_additive_expression_end:
return;	}
syntax_relational_operator
(){
                                                            // 
                                                            //     return contains(" < <= > >= ", s);
                        loadi             (3109);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        contains();       
                        movebp            (-10);
                        if(always())      goto syntax_relational_operator_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // relational-expression-sequence
                                                            // //            relational-operator additive-expression relational-expression-sequence
                                                            // //            relational-operator additive-expression
                                                            // //
                                                            // syntax_relational_expression_sequence() {
syntax_relational_operator_end:
return;	}
syntax_relational_expression_sequence
(){
                                                            //     int cookie;
                                                            //     char operator_text[Str_size];
                                                            // 
                                                            //     if (! (token_type_is(Token_t_symbol) && syntax_relational_operator(token_text)) ) {
                        loadi             (5);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_type_is();  
                        movebp            (-266);
                        if(equals())      goto logical_and_397_false;
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        syntax_relational_operator(); 
                        movebp            (-266);
                        if(equals())      goto logical_and_397_false;
                        loadi             (1);
                        if(always())      goto logical_and_397_true;
logical_and_397_false:  loadi             (0);
logical_and_397_true:   if(notequals())   goto logical_not_398_false;
                        loadi             (1);
                        if(always())      goto logical_not_398_true;
logical_not_398_false:  loadi             (0);
logical_not_398_true:   if(equals())      goto if_399_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_relational_expression_sequence_end;
                                                            //     }
                                                            // 
                                                            //     copy(operator_text, token_text);
if_399_next:
if_399_end:             loadi             (1+BP);
                        store             (257+BP);
                        loadi             (-1049611+global);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //     token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            // 
                                                            //     cookie = compiler_relational_or_equality_expression_sequence_begin(); // >>>>>>>>>>
                        movebp            (265);
                        compiler_relational_or_equality_expression_sequence_begin(); 
                        movebp            (-265);
                        store             (0+BP);
                                                            // 
                                                            //     if (! syntax_additive_expression()) {
                        movebp            (265);
                        syntax_additive_expression(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_400_false;
                        loadi             (1);
                        if(always())      goto logical_not_400_true;
logical_not_400_false:  loadi             (0);
logical_not_400_true:   if(equals())      goto if_401_next;
                                                            //         error_syntax("expression expected right of relational operator");
                        loadi             (3121);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //     }
                                                            // 
                                                            //     compiler_relational_or_equality_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>
if_401_next:
if_401_end:             loadi             (1+BP);
                        store             (257+BP);
                        load              (0+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        compiler_relational_or_equality_expression_sequence_end(); 
                        movebp            (-267);
                                                            // 
                                                            //     syntax_relational_expression_sequence();
                        movebp            (265);
                        syntax_relational_expression_sequence(); 
                        movebp            (-265);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_relational_expression_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // relational-expression
                                                            // //            additive-expression relational-expression-sequence
                                                            // //            additive-expression
                                                            // //
                                                            // syntax_relational_expression() {
syntax_relational_expression_sequence_end:
return;	}
syntax_relational_expression
(){
                                                            //  
                                                            //     if (! syntax_additive_expression()) {
                        movebp            (8);
                        syntax_additive_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_402_false;
                        loadi             (1);
                        if(always())      goto logical_not_402_true;
logical_not_402_false:  loadi             (0);
logical_not_402_true:   if(equals())      goto if_403_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_relational_expression_end;
                                                            //     }
                                                            // 
                                                            //     syntax_relational_expression_sequence();
if_403_next:
if_403_end:             movebp            (8);
                        syntax_relational_expression_sequence(); 
                        movebp            (-8);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_relational_expression_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // equality-operator
                                                            // //            one-of == !=
                                                            // //
                                                            // syntax_equality_operator(char s[]) {
syntax_relational_expression_end:
return;	}
syntax_equality_operator
(){
                                                            // 
                                                            //     return contains(" == != ", s);
                        loadi             (3170);
                        store             (1+BP);
                        load              (0+BP);
                        store             (2+BP);
                        load              (2+BP);
                        store             (11+BP);
                        load              (1+BP);
                        store             (10+BP);
                        movebp            (10);
                        contains();       
                        movebp            (-10);
                        if(always())      goto syntax_equality_operator_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // equality-expression-sequence
                                                            // //            equality-operator-operator relational-expression equality-expression-sequence
                                                            // //            equality-operator-operator relational-expression
                                                            // //
                                                            // syntax_equality_expression_sequence() {
syntax_equality_operator_end:
return;	}
syntax_equality_expression_sequence
(){
                                                            //     int cookie;
                                                            //     char operator_text[Str_size];
                                                            // 
                                                            //     if (! (token_type_is(Token_t_symbol) && syntax_equality_operator(token_text)) ) {
                        loadi             (5);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_type_is();  
                        movebp            (-266);
                        if(equals())      goto logical_and_404_false;
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        syntax_equality_operator(); 
                        movebp            (-266);
                        if(equals())      goto logical_and_404_false;
                        loadi             (1);
                        if(always())      goto logical_and_404_true;
logical_and_404_false:  loadi             (0);
logical_and_404_true:   if(notequals())   goto logical_not_405_false;
                        loadi             (1);
                        if(always())      goto logical_not_405_true;
logical_not_405_false:  loadi             (0);
logical_not_405_true:   if(equals())      goto if_406_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_equality_expression_sequence_end;
                                                            //     }
                                                            // 
                                                            //     copy(operator_text, token_text);
if_406_next:
if_406_end:             loadi             (1+BP);
                        store             (257+BP);
                        loadi             (-1049611+global);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //     token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            // 
                                                            //     cookie = compiler_relational_or_equality_expression_sequence_begin(); // >>>>>>>>>>
                        movebp            (265);
                        compiler_relational_or_equality_expression_sequence_begin(); 
                        movebp            (-265);
                        store             (0+BP);
                                                            // 
                                                            //     if (! syntax_relational_expression()) {
                        movebp            (265);
                        syntax_relational_expression(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_407_false;
                        loadi             (1);
                        if(always())      goto logical_not_407_true;
logical_not_407_false:  loadi             (0);
logical_not_407_true:   if(equals())      goto if_408_next;
                                                            //         error_syntax("expression expected right of equality operator");
                        loadi             (3178);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //     }
                                                            // 
                                                            //     compiler_relational_or_equality_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>
if_408_next:
if_408_end:             loadi             (1+BP);
                        store             (257+BP);
                        load              (0+BP);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        compiler_relational_or_equality_expression_sequence_end(); 
                        movebp            (-267);
                                                            // 
                                                            //     syntax_equality_expression_sequence();
                        movebp            (265);
                        syntax_equality_expression_sequence(); 
                        movebp            (-265);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_equality_expression_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // equality-expression
                                                            // //            relational-expression equality-expression-sequence
                                                            // //            relational-expression
                                                            // //
                                                            // syntax_equality_expression() {
syntax_equality_expression_sequence_end:
return;	}
syntax_equality_expression
(){
                                                            // 
                                                            //     if (! syntax_relational_expression() ) {
                        movebp            (8);
                        syntax_relational_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_409_false;
                        loadi             (1);
                        if(always())      goto logical_not_409_true;
logical_not_409_false:  loadi             (0);
logical_not_409_true:   if(equals())      goto if_410_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_equality_expression_end;
                                                            //     }
                                                            // 
                                                            //     syntax_equality_expression_sequence();
if_410_next:
if_410_end:             movebp            (8);
                        syntax_equality_expression_sequence(); 
                        movebp            (-8);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_equality_expression_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // logical-and-switch-sequence
                                                            // //            && equality-expression logical-and-switch-sequence
                                                            // //            && equality-expression
                                                            // //
                                                            // //
                                                            // syntax_logical_and_switch_sequence(char cookie[]) {
syntax_equality_expression_end:
return;	}
syntax_logical_and_switch_sequence
(){
                                                            // 
                                                            //     if (! token_advance_if("&&")) {
                        loadi             (3225);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_411_false;
                        loadi             (1);
                        if(always())      goto logical_not_411_true;
logical_not_411_false:  loadi             (0);
logical_not_411_true:   if(equals())      goto if_412_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_logical_and_switch_sequence_end;
                                                            //     }
                                                            // 
                                                            //     if (! syntax_equality_expression()) {
if_412_next:
if_412_end:             movebp            (8);
                        syntax_equality_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_413_false;
                        loadi             (1);
                        if(always())      goto logical_not_413_true;
logical_not_413_false:  loadi             (0);
logical_not_413_true:   if(equals())      goto if_414_next;
                                                            //         error_syntax("expression expected right of logical and");
                        loadi             (3228);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     compiler_logical_and_switch_sequence(cookie); // >>>>>>>>>>
if_414_next:
if_414_end:             load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_logical_and_switch_sequence(); 
                        movebp            (-9);
                                                            // 
                                                            //     syntax_logical_and_switch_sequence(cookie);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        syntax_logical_and_switch_sequence(); 
                        movebp            (-9);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_logical_and_switch_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // logical-and-expression
                                                            // //            equality-expression logical-and-switch-sequence
                                                            // //            equality-expression
                                                            // //
                                                            // syntax_logical_and_expression() {
syntax_logical_and_switch_sequence_end:
return;	}
syntax_logical_and_expression
(){
                                                            //     char cookie[Str_size];
                                                            // 
                                                            //     if (! syntax_equality_expression() ) {
                        movebp            (264);
                        syntax_equality_expression(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_415_false;
                        loadi             (1);
                        if(always())      goto logical_not_415_true;
logical_not_415_false:  loadi             (0);
logical_not_415_true:   if(equals())      goto if_416_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_logical_and_expression_end;
                                                            //     }
                                                            //     
                                                            //     if (token_text_is("&&")) {
if_416_next:
if_416_end:             loadi             (3269);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_text_is();  
                        movebp            (-265);
                        if(equals())      goto if_417_next;
                                                            //         compiler_logical_and_expression_begin(cookie); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_logical_and_expression_begin(); 
                        movebp            (-265);
                                                            // 
                                                            //         syntax_logical_and_switch_sequence(cookie);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        syntax_logical_and_switch_sequence(); 
                        movebp            (-265);
                                                            // 
                                                            //         compiler_logical_and_expression_end(cookie); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_logical_and_expression_end(); 
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     return True;
if_417_next:
if_417_end:             loadi             (1);
                        if(always())      goto syntax_logical_and_expression_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // logical-or-switch-sequence
                                                            // //            || logical-and-expression logical-or-switch-sequence
                                                            // //            || logical-and-expression
                                                            // //
                                                            // syntax_logical_or_switch_sequence(char cookie[]) {
syntax_logical_and_expression_end:
return;	}
syntax_logical_or_switch_sequence
(){
                                                            // 
                                                            //     if (! token_advance_if("||")) {
                        loadi             (3272);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_418_false;
                        loadi             (1);
                        if(always())      goto logical_not_418_true;
logical_not_418_false:  loadi             (0);
logical_not_418_true:   if(equals())      goto if_419_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_logical_or_switch_sequence_end;
                                                            //     }
                                                            // 
                                                            //     if (! syntax_logical_and_expression()) {
if_419_next:
if_419_end:             movebp            (8);
                        syntax_logical_and_expression(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_420_false;
                        loadi             (1);
                        if(always())      goto logical_not_420_true;
logical_not_420_false:  loadi             (0);
logical_not_420_true:   if(equals())      goto if_421_next;
                                                            //         error_syntax("expression expected right of logical-or operator");
                        loadi             (3275);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     compiler_logical_or_switch_sequence(cookie); // >>>>>>>>>>
if_421_next:
if_421_end:             load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        compiler_logical_or_switch_sequence(); 
                        movebp            (-9);
                                                            // 
                                                            //     syntax_logical_or_switch_sequence(cookie);
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        syntax_logical_or_switch_sequence(); 
                        movebp            (-9);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_logical_or_switch_sequence_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // logical-or-expression
                                                            // //            logical-and-expression logical-or-switch-sequence
                                                            // //            logical-and-expression
                                                            // //
                                                            // syntax_logical_or_expression() {
syntax_logical_or_switch_sequence_end:
return;	}
syntax_logical_or_expression
(){
                                                            //     char cookie[Str_size];
                                                            //  
                                                            //     if (! syntax_logical_and_expression()) {
                        movebp            (264);
                        syntax_logical_and_expression(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_422_false;
                        loadi             (1);
                        if(always())      goto logical_not_422_true;
logical_not_422_false:  loadi             (0);
logical_not_422_true:   if(equals())      goto if_423_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_logical_or_expression_end;
                                                            //     }
                                                            //     
                                                            //     if (token_text_is("||")) {
if_423_next:
if_423_end:             loadi             (3324);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_text_is();  
                        movebp            (-265);
                        if(equals())      goto if_424_next;
                                                            //         compiler_logical_or_expression_begin(cookie); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_logical_or_expression_begin(); 
                        movebp            (-265);
                                                            // 
                                                            //         syntax_logical_or_switch_sequence(cookie);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        syntax_logical_or_switch_sequence(); 
                        movebp            (-265);
                                                            // 
                                                            //         compiler_logical_or_expression_end(cookie); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_logical_or_expression_end(); 
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     return True;
if_424_next:
if_424_end:             loadi             (1);
                        if(always())      goto syntax_logical_or_expression_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // expression
                                                            // //            logical-or-expression
                                                            // //
                                                            // syntax_expression() {
syntax_logical_or_expression_end:
return;	}
syntax_expression
(){
                                                            // 
                                                            //     return syntax_logical_or_expression();
                        movebp            (8);
                        syntax_logical_or_expression(); 
                        movebp            (-8);
                        if(always())      goto syntax_expression_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // function-call-statement
                                                            // //            built-in-function
                                                            // //            identifier ( function-call-argument-list )
                                                            // //
                                                            // syntax_function_call_statement() {
syntax_expression_end:
return;	}
syntax_function_call_statement
(){
                                                            //     char cookie[Str_size];
                                                            //     char function_name[Str_size];
                                                            //     int function_argument_count[1];
                                                            // 
                                                            //     if (syntax_built_in_function()) {
                        movebp            (521);
                        syntax_built_in_function(); 
                        movebp            (-521);
                        if(equals())      goto if_425_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_function_call_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (! (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) ) {
if_425_next:
if_425_end:             loadi             (4);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_type_is();  
                        movebp            (-522);
                        if(equals())      goto logical_and_426_false;
                        loadi             (3327);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_lookahead_text_is(); 
                        movebp            (-522);
                        if(equals())      goto logical_and_426_false;
                        loadi             (1);
                        if(always())      goto logical_and_426_true;
logical_and_426_false:  loadi             (0);
logical_and_426_true:   if(notequals())   goto logical_not_427_false;
                        loadi             (1);
                        if(always())      goto logical_not_427_true;
logical_not_427_false:  loadi             (0);
logical_not_427_true:   if(equals())      goto if_428_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_function_call_statement_end;
                                                            //     }
                                                            // 
                                                            //     copy(function_name, token_text);
if_428_next:
if_428_end:             loadi             (256+BP);
                        store             (513+BP);
                        loadi             (-1049611+global);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        copy();           
                        movebp            (-523);
                                                            // 
                                                            //     token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            //     token_advance();
                        movebp            (521);
                        token_advance();  
                        movebp            (-521);
                                                            // 
                                                            //     compiler_function_call_prepare(function_name, cookie); // >>>>>>>>>>
                        loadi             (256+BP);
                        store             (513+BP);
                        loadi             (0+BP);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        compiler_function_call_prepare(); 
                        movebp            (-523);
                                                            // 
                                                            //     syntax_function_call_argument_list(0, function_argument_count);
                        loadi             (0);
                        store             (513+BP);
                        loadi             (512+BP);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        syntax_function_call_argument_list(); 
                        movebp            (-523);
                                                            // 
                                                            //     compiler_function_call_execute(cookie, function_argument_count[0]); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (513+BP);
                        loadi             (0);
                        loadx             ();
                        load              (512+BP+X);
                        store             (514+BP);
                        load              (514+BP);
                        store             (524+BP);
                        load              (513+BP);
                        store             (523+BP);
                        movebp            (523);
                        compiler_function_call_execute(); 
                        movebp            (-523);
                                                            //                 
                                                            //     if (! token_advance_if(")") ) {
                        loadi             (3329);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        token_advance_if(); 
                        movebp            (-522);
                        if(notequals())   goto logical_not_429_false;
                        loadi             (1);
                        if(always())      goto logical_not_429_true;
logical_not_429_false:  loadi             (0);
logical_not_429_true:   if(equals())      goto if_430_next;
                                                            //         error_syntax("closing parenthesis expected after function call");
                        loadi             (3331);
                        store             (513+BP);
                        load              (513+BP);
                        store             (522+BP);
                        movebp            (522);
                        error_syntax();   
                        movebp            (-522);
                                                            //     }
                                                            // 
                                                            //     return True;
if_430_next:
if_430_end:             loadi             (1);
                        if(always())      goto syntax_function_call_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // return-statement
                                                            // //            return expression
                                                            // //            return
                                                            // //
                                                            // syntax_return_statement() {
syntax_function_call_statement_end:
return;	}
syntax_return_statement
(){
                                                            //  
                                                            //     if (! token_advance_if("return")) {
                        loadi             (3380);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_431_false;
                        loadi             (1);
                        if(always())      goto logical_not_431_true;
logical_not_431_false:  loadi             (0);
logical_not_431_true:   if(equals())      goto if_432_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_return_statement_end;
                                                            //     }
                                                            // 
                                                            //     syntax_expression();
if_432_next:
if_432_end:             movebp            (8);
                        syntax_expression(); 
                        movebp            (-8);
                                                            // 
                                                            //     compiler_return_statement(); // >>>>>>>>>>
                        movebp            (8);
                        compiler_return_statement(); 
                        movebp            (-8);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_return_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // expression-statement
                                                            // //           expression
                                                            // //
                                                            // syntax_expression_statement() {
syntax_return_statement_end:
return;	}
syntax_expression_statement
(){
                                                            // 
                                                            //     return syntax_expression();
                        movebp            (8);
                        syntax_expression(); 
                        movebp            (-8);
                        if(always())      goto syntax_expression_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // assignment-statement
                                                            // //            identifier = expression
                                                            // //            identifier [ expression ] = expression
                                                            // //            
                                                            // syntax_assignment_statement() {
syntax_expression_statement_end:
return;	}
syntax_assignment_statement
(){
                                                            //     int cookie[1];
                                                            //     char variable_name[Str_size];
                                                            // 
                                                            //     if (token_type_is(Token_t_identifier) && token_lookahead_text_is("=")) {
                        loadi             (4);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_type_is();  
                        movebp            (-266);
                        if(equals())      goto logical_and_433_false;
                        loadi             (3387);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_lookahead_text_is(); 
                        movebp            (-266);
                        if(equals())      goto logical_and_433_false;
                        loadi             (1);
                        if(always())      goto logical_and_433_true;
logical_and_433_false:  loadi             (0);
logical_and_433_true:   if(equals())      goto if_434_next;
                                                            //         copy(variable_name, token_text);
                        loadi             (1+BP);
                        store             (257+BP);
                        loadi             (-1049611+global);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //         token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            //         token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            //    
                                                            //         if (! syntax_expression()) {
                        movebp            (265);
                        syntax_expression(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_435_false;
                        loadi             (1);
                        if(always())      goto logical_not_435_true;
logical_not_435_false:  loadi             (0);
logical_not_435_true:   if(equals())      goto if_436_next;
                                                            //             error_syntax("expression expected after equal sign");
                        loadi             (3389);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //         }
                                                            // 
                                                            //         compiler_assignment_statement(variable_name); // >>>>>>>>>>
if_436_next:
if_436_end:             loadi             (1+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        compiler_assignment_statement(); 
                        movebp            (-266);
                                                            // 
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_assignment_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (token_type_is(Token_t_identifier) && token_lookahead_text_is("[")) {
if_434_next:
if_434_end:             loadi             (4);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_type_is();  
                        movebp            (-266);
                        if(equals())      goto logical_and_437_false;
                        loadi             (3426);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_lookahead_text_is(); 
                        movebp            (-266);
                        if(equals())      goto logical_and_437_false;
                        loadi             (1);
                        if(always())      goto logical_and_437_true;
logical_and_437_false:  loadi             (0);
logical_and_437_true:   if(equals())      goto if_438_next;
                                                            //         copy(variable_name, token_text);
                        loadi             (1+BP);
                        store             (257+BP);
                        loadi             (-1049611+global);
                        store             (258+BP);
                        load              (258+BP);
                        store             (268+BP);
                        load              (257+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //         token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            //         token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            // 
                                                            //         if (! syntax_expression()) {
                        movebp            (265);
                        syntax_expression(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_439_false;
                        loadi             (1);
                        if(always())      goto logical_not_439_true;
logical_not_439_false:  loadi             (0);
logical_not_439_true:   if(equals())      goto if_440_next;
                                                            //             error_syntax("expression expected within array index");
                        loadi             (3428);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if("]")) {
if_440_next:
if_440_end:             loadi             (3467);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_advance_if(); 
                        movebp            (-266);
                        if(notequals())   goto logical_not_441_false;
                        loadi             (1);
                        if(always())      goto logical_not_441_true;
logical_not_441_false:  loadi             (0);
logical_not_441_true:   if(equals())      goto if_442_next;
                                                            //             error_syntax("closing bracket expected after array index");
                        loadi             (3469);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //         }
                                                            //             
                                                            //         if (! token_advance_if("=")) {
if_442_next:
if_442_end:             loadi             (3512);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_advance_if(); 
                        movebp            (-266);
                        if(notequals())   goto logical_not_443_false;
                        loadi             (1);
                        if(always())      goto logical_not_443_true;
logical_not_443_false:  loadi             (0);
logical_not_443_true:   if(equals())      goto if_444_next;
                                                            //             error_syntax("equal sign expected after array index");
                        loadi             (3514);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //         }
                                                            // 
                                                            //         compiler_assignment_statement_array_begin(cookie); // >>>>>>>>>>
if_444_next:
if_444_end:             loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        compiler_assignment_statement_array_begin(); 
                        movebp            (-266);
                                                            //    
                                                            //         if (! syntax_expression()) {
                        movebp            (265);
                        syntax_expression(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_445_false;
                        loadi             (1);
                        if(always())      goto logical_not_445_true;
logical_not_445_false:  loadi             (0);
logical_not_445_true:   if(equals())      goto if_446_next;
                                                            //             error_syntax("expression expected after equal sign");
                        loadi             (3552);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //         }
                                                            // 
                                                            //         compiler_assignment_statement_array_end(cookie); // >>>>>>>>>>
if_446_next:
if_446_end:             loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        compiler_assignment_statement_array_end(); 
                        movebp            (-266);
                                                            //         compiler_assignment_statement(variable_name); // >>>>>>>>>>
                        loadi             (1+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (266+BP);
                        movebp            (266);
                        compiler_assignment_statement(); 
                        movebp            (-266);
                                                            // 
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_assignment_statement_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_438_next:
if_438_end:             loadi             (0);
                        if(always())      goto syntax_assignment_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // while-statement
                                                            // //            while ( expression ) statement
                                                            // //
                                                            // syntax_while_statement() {
syntax_assignment_statement_end:
return;	}
syntax_while_statement
(){
                                                            //     char cookie[Str_size];
                                                            // 
                                                            //     if (! token_advance_if("while") ) {
                        loadi             (3589);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_447_false;
                        loadi             (1);
                        if(always())      goto logical_not_447_true;
logical_not_447_false:  loadi             (0);
logical_not_447_true:   if(equals())      goto if_448_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_while_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (! token_advance_if("(") ) {
if_448_next:
if_448_end:             loadi             (3595);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_449_false;
                        loadi             (1);
                        if(always())      goto logical_not_449_true;
logical_not_449_false:  loadi             (0);
logical_not_449_true:   if(equals())      goto if_450_next;
                                                            //         error_syntax("opening parenthesis expected after while keyword");
                        loadi             (3597);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     compiler_while_statement_begin(cookie); // >>>>>>>>>>
if_450_next:
if_450_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_while_statement_begin(); 
                        movebp            (-265);
                                                            // 
                                                            //     if (! syntax_expression()) {
                        movebp            (264);
                        syntax_expression(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_451_false;
                        loadi             (1);
                        if(always())      goto logical_not_451_true;
logical_not_451_false:  loadi             (0);
logical_not_451_true:   if(equals())      goto if_452_next;
                                                            //         error_syntax("expression expected in while statement");
                        loadi             (3646);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     compiler_while_statement_test(cookie); // >>>>>>>>>>
if_452_next:
if_452_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_while_statement_test(); 
                        movebp            (-265);
                                                            // 
                                                            //     if (! token_advance_if(")") ) {
                        loadi             (3685);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_453_false;
                        loadi             (1);
                        if(always())      goto logical_not_453_true;
logical_not_453_false:  loadi             (0);
logical_not_453_true:   if(equals())      goto if_454_next;
                                                            //         error_syntax("closing parenthesis expected after while statement");
                        loadi             (3687);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     if (! syntax_statement() ) {
if_454_next:
if_454_end:             movebp            (264);
                        syntax_statement(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_455_false;
                        loadi             (1);
                        if(always())      goto logical_not_455_true;
logical_not_455_false:  loadi             (0);
logical_not_455_true:   if(equals())      goto if_456_next;
                                                            //         error_syntax("statement expected after while");
                        loadi             (3738);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     compiler_while_statement_end(cookie); // >>>>>>>>>>
if_456_next:
if_456_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_while_statement_end(); 
                        movebp            (-265);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_while_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // if-statement
                                                            // //            if ( expression ) statement else statement
                                                            // //            if ( expression ) statement
                                                            // //
                                                            // syntax_if_statement() {
syntax_while_statement_end:
return;	}
syntax_if_statement
(){
                                                            //     char cookie[Str_size];
                                                            // 
                                                            //     if (! token_advance_if("if") ) {
                        loadi             (3769);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_457_false;
                        loadi             (1);
                        if(always())      goto logical_not_457_true;
logical_not_457_false:  loadi             (0);
logical_not_457_true:   if(equals())      goto if_458_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_if_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (! token_advance_if("(") ) {
if_458_next:
if_458_end:             loadi             (3772);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_459_false;
                        loadi             (1);
                        if(always())      goto logical_not_459_true;
logical_not_459_false:  loadi             (0);
logical_not_459_true:   if(equals())      goto if_460_next;
                                                            //         error_syntax("opening parenthesis expected after if keyword");
                        loadi             (3774);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     if (! syntax_expression()) {
if_460_next:
if_460_end:             movebp            (264);
                        syntax_expression(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_461_false;
                        loadi             (1);
                        if(always())      goto logical_not_461_true;
logical_not_461_false:  loadi             (0);
logical_not_461_true:   if(equals())      goto if_462_next;
                                                            //         error_syntax("expression expected in if statement");
                        loadi             (3820);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     if (! token_advance_if(")") ) {
if_462_next:
if_462_end:             loadi             (3856);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_463_false;
                        loadi             (1);
                        if(always())      goto logical_not_463_true;
logical_not_463_false:  loadi             (0);
logical_not_463_true:   if(equals())      goto if_464_next;
                                                            //         error_syntax("closing parenthesis expected after if statement");
                        loadi             (3858);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     compiler_if_statement_test_fn(cookie); // >>>>>>>>>>
if_464_next:
if_464_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_if_statement_test_fn(); 
                        movebp            (-265);
                                                            // 
                                                            //     if (! syntax_statement() ) {
                        movebp            (264);
                        syntax_statement(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_465_false;
                        loadi             (1);
                        if(always())      goto logical_not_465_true;
logical_not_465_false:  loadi             (0);
logical_not_465_true:   if(equals())      goto if_466_next;
                                                            //         error_syntax("statement expected after if");
                        loadi             (3906);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     if (! token_advance_if("else") ) {
if_466_next:
if_466_end:             loadi             (3934);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_467_false;
                        loadi             (1);
                        if(always())      goto logical_not_467_true;
logical_not_467_false:  loadi             (0);
logical_not_467_true:   if(equals())      goto if_468_next;
                                                            //          compiler_if_statement_no_else_fn(cookie); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_if_statement_no_else_fn(); 
                        movebp            (-265);
                                                            //          return True;
                        loadi             (1);
                        if(always())      goto syntax_if_statement_end;
                                                            //     }
                                                            // 
                                                            //     compiler_if_statement_else_fn(cookie); // >>>>>>>>>>
if_468_next:
if_468_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_if_statement_else_fn(); 
                        movebp            (-265);
                                                            // 
                                                            //     if (! syntax_statement() ) {
                        movebp            (264);
                        syntax_statement(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_469_false;
                        loadi             (1);
                        if(always())      goto logical_not_469_true;
logical_not_469_false:  loadi             (0);
logical_not_469_true:   if(equals())      goto if_470_next;
                                                            //         error_syntax("statement expected after else");
                        loadi             (3939);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     compiler_if_statement_else_end_fn(cookie); // >>>>>>>>>>
if_470_next:
if_470_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_if_statement_else_end_fn(); 
                        movebp            (-265);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_if_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // enumerator
                                                            // //            identifier = integer-constant
                                                            // //            identifier
                                                            // //
                                                            // syntax_enumerator() {
syntax_if_statement_end:
return;	}
syntax_enumerator
(){
                                                            //     char constant_name[Str_size];
                                                            // 
                                                            //     if (! token_type_is(Token_t_identifier) ) {
                        loadi             (4);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_type_is();  
                        movebp            (-265);
                        if(notequals())   goto logical_not_471_false;
                        loadi             (1);
                        if(always())      goto logical_not_471_true;
logical_not_471_false:  loadi             (0);
logical_not_471_true:   if(equals())      goto if_472_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_enumerator_end;
                                                            //     }
                                                            //     
                                                            //     copy(constant_name, token_text);
if_472_next:
if_472_end:             loadi             (0+BP);
                        store             (256+BP);
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //     token_advance();
                        movebp            (264);
                        token_advance();  
                        movebp            (-264);
                                                            // 
                                                            //     if (token_text_is("=")) {
                        loadi             (3969);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_text_is();  
                        movebp            (-265);
                        if(equals())      goto if_473_next;
                                                            //         token_advance();
                        movebp            (264);
                        token_advance();  
                        movebp            (-264);
                                                            // 
                                                            //         if (! token_type_is(Token_t_integer_constant) ) {
                        loadi             (2);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_type_is();  
                        movebp            (-265);
                        if(notequals())   goto logical_not_474_false;
                        loadi             (1);
                        if(always())      goto logical_not_474_true;
logical_not_474_false:  loadi             (0);
logical_not_474_true:   if(equals())      goto if_475_next;
                                                            //             error_syntax("integer constant expected after equal sign in enum declaration");
                        loadi             (3971);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //         }
                                                            // 
                                                            //         compiler_enumerator_assigned_value(constant_name, token_text); // >>>>>>>>>>
if_475_next:
if_475_end:             loadi             (0+BP);
                        store             (256+BP);
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        compiler_enumerator_assigned_value(); 
                        movebp            (-266);
                                                            //         token_advance();
                        movebp            (264);
                        token_advance();  
                        movebp            (-264);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_enumerator_end;
                                                            //     }
                                                            // 
                                                            //     compiler_enumerator(constant_name); // >>>>>>>>>>
if_473_next:
if_473_end:             loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_enumerator(); 
                        movebp            (-265);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_enumerator_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // enumerator-list
                                                            // //            enumerator , enumerator-list
                                                            // //            enumerator
                                                            // //            
                                                            // syntax_enumerator_list() {
syntax_enumerator_end:
return;	}
syntax_enumerator_list
(){
                                                            //     if (! syntax_enumerator() ) {
                        movebp            (8);
                        syntax_enumerator(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_476_false;
                        loadi             (1);
                        if(always())      goto logical_not_476_true;
logical_not_476_false:  loadi             (0);
logical_not_476_true:   if(equals())      goto if_477_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_enumerator_list_end;
                                                            //     }
                                                            // 
                                                            //     if (token_advance_if(",")) {
if_477_next:
if_477_end:             loadi             (4034);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(equals())      goto if_478_next;
                                                            // 
                                                            //         if (! syntax_enumerator_list() ) {
                        movebp            (8);
                        syntax_enumerator_list(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_479_false;
                        loadi             (1);
                        if(always())      goto logical_not_479_true;
logical_not_479_false:  loadi             (0);
logical_not_479_true:   if(equals())      goto if_480_next;
                                                            //             error_syntax("identifier expected after comma in enum declaration");
                        loadi             (4036);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            //     }
if_480_next:
                                                            // 
                                                            //     compiler_enumerator_list_end(); // >>>>>>>>>>
if_480_end:
if_478_next:
if_478_end:             movebp            (8);
                        compiler_enumerator_list_end(); 
                        movebp            (-8);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_enumerator_list_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // type-specifier
                                                            // //            int
                                                            // //            char
                                                            // //
                                                            // syntax_type_specifier() {
syntax_enumerator_list_end:
return;	}
syntax_type_specifier
(){
                                                            // 
                                                            //     if (token_text_is("int") || token_text_is("char")) {
                        loadi             (4088);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_text_is();  
                        movebp            (-9);
                        if(notequals())   goto logical_or_481_true;
                        loadi             (4092);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_text_is();  
                        movebp            (-9);
                        if(notequals())   goto logical_or_481_true;
                        loadi             (0);
                        if(always())      goto logical_or_481_false;
logical_or_481_true:    loadi             (1);
logical_or_481_false:   if(equals())      goto if_482_next;
                                                            //         token_advance();
                        movebp            (8);
                        token_advance();  
                        movebp            (-8);
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_type_specifier_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_482_next:
if_482_end:             loadi             (0);
                        if(always())      goto syntax_type_specifier_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // declaration
                                                            // //            type-specifier identifier ;
                                                            // //            type-specifier identifier [ integer-constant ] ;
                                                            // //            type-specifier identifier [ identifier ] ;
                                                            // //            enum { enumerator-list } ;
                                                            // //
                                                            // syntax_declaration() {
syntax_type_specifier_end:
return;	}
syntax_declaration
(){
                                                            //     char variable_name[Str_size];
                                                            //     char array_length[Str_size];
                                                            // 
                                                            //     if (syntax_type_specifier()) {
                        movebp            (520);
                        syntax_type_specifier(); 
                        movebp            (-520);
                        if(equals())      goto if_483_next;
                                                            //     
                                                            //         if (! token_type_is(Token_t_identifier)) {
                        loadi             (4);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_type_is();  
                        movebp            (-521);
                        if(notequals())   goto logical_not_484_false;
                        loadi             (1);
                        if(always())      goto logical_not_484_true;
logical_not_484_false:  loadi             (0);
logical_not_484_true:   if(equals())      goto if_485_next;
                                                            //             error_syntax("identifier expected after type specifier in declaration");
                        loadi             (4097);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         copy(variable_name, token_text);
if_485_next:
if_485_end:             loadi             (0+BP);
                        store             (512+BP);
                        loadi             (-1049611+global);
                        store             (513+BP);
                        load              (513+BP);
                        store             (523+BP);
                        load              (512+BP);
                        store             (522+BP);
                        movebp            (522);
                        copy();           
                        movebp            (-522);
                                                            //         token_advance();
                        movebp            (520);
                        token_advance();  
                        movebp            (-520);
                                                            // 
                                                            //         // simple type declaration -------------------------------------------
                                                            //         if (! token_text_is("[")) {
                        loadi             (4153);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_text_is();  
                        movebp            (-521);
                        if(notequals())   goto logical_not_486_false;
                        loadi             (1);
                        if(always())      goto logical_not_486_true;
logical_not_486_false:  loadi             (0);
logical_not_486_true:   if(equals())      goto if_487_next;
                                                            //             compiler_declaration_integer(variable_name); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        compiler_declaration_integer(); 
                        movebp            (-521);
                                                            // 
                                                            //             if (! token_advance_if(";") ) {
                        loadi             (4155);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_advance_if(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_488_false;
                        loadi             (1);
                        if(always())      goto logical_not_488_true;
logical_not_488_false:  loadi             (0);
logical_not_488_true:   if(equals())      goto if_489_next;
                                                            //                 error_syntax("semicolon expected after declaration");
                        loadi             (4157);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //             }
                                                            // 
                                                            //             return True;
if_489_next:
if_489_end:             loadi             (1);
                        if(always())      goto syntax_declaration_end;
                                                            //         }
                                                            // 
                                                            //         // array type declaration -------------------------------------------
                                                            //         copy(array_length, token_lookahead_text);
if_487_next:
if_487_end:             loadi             (256+BP);
                        store             (512+BP);
                        loadi             (-1049867+global);
                        store             (513+BP);
                        load              (513+BP);
                        store             (523+BP);
                        load              (512+BP);
                        store             (522+BP);
                        movebp            (522);
                        copy();           
                        movebp            (-522);
                                                            // 
                                                            //         if (token_lookahead_type_is(Token_t_integer_constant)) {
                        loadi             (2);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_lookahead_type_is(); 
                        movebp            (-521);
                        if(equals())      goto if_490_next;
                                                            //             compiler_declaration_integer_array_constant_length_specifier(variable_name, array_length); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (512+BP);
                        loadi             (256+BP);
                        store             (513+BP);
                        load              (513+BP);
                        store             (523+BP);
                        load              (512+BP);
                        store             (522+BP);
                        movebp            (522);
                        compiler_declaration_integer_array_constant_length_specifier(); 
                        movebp            (-522);
                                                            //         }
                                                            //         else if (token_lookahead_type_is(Token_t_identifier)) {
                        if(always())      goto if_490_end;
if_490_next:            loadi             (4);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_lookahead_type_is(); 
                        movebp            (-521);
                        if(equals())      goto if_491_next;
                                                            //             compiler_declaration_integer_array_identifier_length_specifier(variable_name, array_length); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (512+BP);
                        loadi             (256+BP);
                        store             (513+BP);
                        load              (513+BP);
                        store             (523+BP);
                        load              (512+BP);
                        store             (522+BP);
                        movebp            (522);
                        compiler_declaration_integer_array_identifier_length_specifier(); 
                        movebp            (-522);
                                                            //         }
                                                            //         else {
                        if(always())      goto if_491_end;
                                                            //             error_syntax("identifier or integer constant expected after opening bracket in array declaration");
if_491_next:            loadi             (4194);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         token_advance();
if_491_end:
if_490_end:             movebp            (520);
                        token_advance();  
                        movebp            (-520);
                                                            //         token_advance();
                        movebp            (520);
                        token_advance();  
                        movebp            (-520);
                                                            // 
                                                            //         if (! token_advance_if("]") ) {
                        loadi             (4277);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_advance_if(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_492_false;
                        loadi             (1);
                        if(always())      goto logical_not_492_true;
logical_not_492_false:  loadi             (0);
logical_not_492_true:   if(equals())      goto if_493_next;
                                                            //             error_syntax("closing bracket expected in array declaration");
                        loadi             (4279);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         if (!token_advance_if(";")) {
if_493_next:
if_493_end:             loadi             (4325);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_advance_if(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_494_false;
                        loadi             (1);
                        if(always())      goto logical_not_494_true;
logical_not_494_false:  loadi             (0);
logical_not_494_true:   if(equals())      goto if_495_next;
                                                            //             error_syntax("semicolon expected after array declaration");
                        loadi             (4327);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         return True;
if_495_next:
if_495_end:             loadi             (1);
                        if(always())      goto syntax_declaration_end;
                                                            // 
                                                            //     }
                                                            // 
                                                            //     // enum declaration ------------------------------------------------------
                                                            //     if (token_advance_if("enum")) {
if_483_next:
if_483_end:             loadi             (4370);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_advance_if(); 
                        movebp            (-521);
                        if(equals())      goto if_496_next;
                                                            // 
                                                            //         if (! token_advance_if("{")) {
                        loadi             (4375);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_advance_if(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_497_false;
                        loadi             (1);
                        if(always())      goto logical_not_497_true;
logical_not_497_false:  loadi             (0);
logical_not_497_true:   if(equals())      goto if_498_next;
                                                            //             error_syntax("opening brace expected after enum keyword");
                        loadi             (4377);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         if (! syntax_enumerator_list() ) {
if_498_next:
if_498_end:             movebp            (520);
                        syntax_enumerator_list(); 
                        movebp            (-520);
                        if(notequals())   goto logical_not_499_false;
                        loadi             (1);
                        if(always())      goto logical_not_499_true;
logical_not_499_false:  loadi             (0);
logical_not_499_true:   if(equals())      goto if_500_next;
                                                            //             error_syntax("enumerator list expected");
                        loadi             (4419);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if("}")) {
if_500_next:
if_500_end:             loadi             (4444);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_advance_if(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_501_false;
                        loadi             (1);
                        if(always())      goto logical_not_501_true;
logical_not_501_false:  loadi             (0);
logical_not_501_true:   if(equals())      goto if_502_next;
                                                            //             error_syntax("closing brace expected after enumerator list");
                        loadi             (4446);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         if (! token_advance_if(";")) {
if_502_next:
if_502_end:             loadi             (4491);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        token_advance_if(); 
                        movebp            (-521);
                        if(notequals())   goto logical_not_503_false;
                        loadi             (1);
                        if(always())      goto logical_not_503_true;
logical_not_503_false:  loadi             (0);
logical_not_503_true:   if(equals())      goto if_504_next;
                                                            //             error_syntax("semicolon expected after enumerator declaration"); // ????
                        loadi             (4493);
                        store             (512+BP);
                        load              (512+BP);
                        store             (521+BP);
                        movebp            (521);
                        error_syntax();   
                        movebp            (-521);
                                                            //         }
                                                            // 
                                                            //         return True;
if_504_next:
if_504_end:             loadi             (1);
                        if(always())      goto syntax_declaration_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_496_next:
if_496_end:             loadi             (0);
                        if(always())      goto syntax_declaration_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // local-declaration-list
                                                            // //            declaration local-declaration-list
                                                            // //            declaration
                                                            // //
                                                            // syntax_local_declaration_list() {
syntax_declaration_end:
return;	}
syntax_local_declaration_list
(){
                                                            //     if (! syntax_declaration() ) {
                        movebp            (8);
                        syntax_declaration(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_505_false;
                        loadi             (1);
                        if(always())      goto logical_not_505_true;
logical_not_505_false:  loadi             (0);
logical_not_505_true:   if(equals())      goto if_506_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_local_declaration_list_end;
                                                            //     }
                                                            // 
                                                            //     syntax_local_declaration_list();
if_506_next:
if_506_end:             movebp            (8);
                        syntax_local_declaration_list(); 
                        movebp            (-8);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_local_declaration_list_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // compound-statement
                                                            // //            { statement-list } 
                                                            // //
                                                            // syntax_compound_statement() {
syntax_local_declaration_list_end:
return;	}
syntax_compound_statement
(){
                                                            // 
                                                            //     if (! token_advance_if("{") ) {
                        loadi             (4541);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_507_false;
                        loadi             (1);
                        if(always())      goto logical_not_507_true;
logical_not_507_false:  loadi             (0);
logical_not_507_true:   if(equals())      goto if_508_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_compound_statement_end;
                                                            //     }
                                                            // 
                                                            //     syntax_statement_list();
if_508_next:
if_508_end:             movebp            (8);
                        syntax_statement_list(); 
                        movebp            (-8);
                                                            // 
                                                            //     if (! token_advance_if("}") ) {
                        loadi             (4543);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_509_false;
                        loadi             (1);
                        if(always())      goto logical_not_509_true;
logical_not_509_false:  loadi             (0);
logical_not_509_true:   if(equals())      goto if_510_next;
                                                            //         error_syntax("closing brace expected at end of compound statement");
                        loadi             (4545);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     return True;
if_510_next:
if_510_end:             loadi             (1);
                        if(always())      goto syntax_compound_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // statement
                                                            // //           if-statement
                                                            // //           while-statement
                                                            // //           compound-statement
                                                            // //           assignment-statement ;
                                                            // //           expression-statement ;
                                                            // //           return-statement ;
                                                            // //
                                                            // syntax_statement() {
syntax_compound_statement_end:
return;	}
syntax_statement
(){
                                                            // 
                                                            //     compiler_output_source_as_comment(); // >>>>>>>>>>
                        movebp            (8);
                        compiler_output_source_as_comment(); 
                        movebp            (-8);
                                                            // 
                                                            //     if (syntax_if_statement() || 
                        movebp            (8);
                        syntax_if_statement(); 
                        movebp            (-8);
                        if(notequals())   goto logical_or_511_true;
                        movebp            (8);
                        syntax_while_statement(); 
                        movebp            (-8);
                        if(notequals())   goto logical_or_511_true;
                        movebp            (8);
                        syntax_compound_statement(); 
                        movebp            (-8);
                        if(notequals())   goto logical_or_511_true;
                        loadi             (0);
                        if(always())      goto logical_or_511_false;
logical_or_511_true:    loadi             (1);
logical_or_511_false:   if(equals())      goto if_512_next;
                                                            //         syntax_while_statement() ||
                                                            //         syntax_compound_statement() ) {
                                                            // 
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_statement_end;
                                                            //     }
                                                            // 
                                                            //     if (syntax_assignment_statement() ||
if_512_next:
if_512_end:             movebp            (8);
                        syntax_assignment_statement(); 
                        movebp            (-8);
                        if(notequals())   goto logical_or_513_true;
                        movebp            (8);
                        syntax_expression_statement(); 
                        movebp            (-8);
                        if(notequals())   goto logical_or_513_true;
                        movebp            (8);
                        syntax_return_statement(); 
                        movebp            (-8);
                        if(notequals())   goto logical_or_513_true;
                        loadi             (0);
                        if(always())      goto logical_or_513_false;
logical_or_513_true:    loadi             (1);
logical_or_513_false:   if(equals())      goto if_514_next;
                                                            //         syntax_expression_statement() ||
                                                            //         syntax_return_statement() ) {
                                                            // 
                                                            //         if (! token_advance_if(";") ) {
                        loadi             (4597);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_515_false;
                        loadi             (1);
                        if(always())      goto logical_not_515_true;
logical_not_515_false:  loadi             (0);
logical_not_515_true:   if(equals())      goto if_516_next;
                                                            //             error_syntax("semicolon expected after statement");
                        loadi             (4599);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //         }
                                                            // 
                                                            //         return True;
if_516_next:
if_516_end:             loadi             (1);
                        if(always())      goto syntax_statement_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_514_next:
if_514_end:             loadi             (0);
                        if(always())      goto syntax_statement_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // statement-list
                                                            // //            statement statement-list
                                                            // //            statement
                                                            // //            
                                                            // syntax_statement_list() {
syntax_statement_end:
return;	}
syntax_statement_list
(){
                                                            // 
                                                            //     if (! syntax_statement() ) {
                        movebp            (8);
                        syntax_statement(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_517_false;
                        loadi             (1);
                        if(always())      goto logical_not_517_true;
logical_not_517_false:  loadi             (0);
logical_not_517_true:   if(equals())      goto if_518_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_statement_list_end;
                                                            //     }
                                                            // 
                                                            //     syntax_statement_list();
if_518_next:
if_518_end:             movebp            (8);
                        syntax_statement_list(); 
                        movebp            (-8);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_statement_list_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // function-argument-declaration
                                                            // //            type-specifier identifier
                                                            // //            type-specifier identifier []
                                                            // //
                                                            // syntax_function_argument_declaration(int argument_no) {
syntax_statement_list_end:
return;	}
syntax_function_argument_declaration
(){
                                                            //     int argument_type;
                                                            //     char argument_name[Str_size];
                                                            // 
                                                            //     if (! syntax_type_specifier() ) {
                        movebp            (265);
                        syntax_type_specifier(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_519_false;
                        loadi             (1);
                        if(always())      goto logical_not_519_true;
logical_not_519_false:  loadi             (0);
logical_not_519_true:   if(equals())      goto if_520_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_function_argument_declaration_end;
                                                            //     }
                                                            // 
                                                            //     if (! token_type_is(Token_t_identifier) ) {
if_520_next:
if_520_end:             loadi             (4);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_type_is();  
                        movebp            (-266);
                        if(notequals())   goto logical_not_521_false;
                        loadi             (1);
                        if(always())      goto logical_not_521_true;
logical_not_521_false:  loadi             (0);
logical_not_521_true:   if(equals())      goto if_522_next;
                                                            //         error_syntax("identifier expected after type specifier in function definition");
                        loadi             (4634);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //     }
                                                            // 
                                                            //     copy(argument_name, token_text);
if_522_next:
if_522_end:             loadi             (2+BP);
                        store             (258+BP);
                        loadi             (-1049611+global);
                        store             (259+BP);
                        load              (259+BP);
                        store             (268+BP);
                        load              (258+BP);
                        store             (267+BP);
                        movebp            (267);
                        copy();           
                        movebp            (-267);
                                                            //     token_advance();
                        movebp            (265);
                        token_advance();  
                        movebp            (-265);
                                                            // 
                                                            //     if (token_advance_if("[")) {
                        loadi             (4698);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_advance_if(); 
                        movebp            (-266);
                        if(equals())      goto if_523_next;
                                                            //         argument_type = Compiler_t_integer_pointer;
                        loadi             (0);
                        store             (1+BP);
                                                            // 
                                                            //         if (! token_advance_if("]") ) {
                        loadi             (4700);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        token_advance_if(); 
                        movebp            (-266);
                        if(notequals())   goto logical_not_524_false;
                        loadi             (1);
                        if(always())      goto logical_not_524_true;
logical_not_524_false:  loadi             (0);
logical_not_524_true:   if(equals())      goto if_525_next;
                                                            //             error_syntax("closing bracket expected after array argument declaration");
                        loadi             (4702);
                        store             (258+BP);
                        load              (258+BP);
                        store             (266+BP);
                        movebp            (266);
                        error_syntax();   
                        movebp            (-266);
                                                            //         }
                                                            //     } else {
if_525_next:
if_525_end:             if(always())      goto if_523_end;
                                                            //         argument_type = Compiler_t_integer;
if_523_next:            loadi             (1);
                        store             (1+BP);
                                                            //     }
                                                            // 
                                                            //     compiler_function_argument_declaration_item(argument_name, argument_type, argument_no + 1); // >>>>>>>>>>
if_523_end:             loadi             (2+BP);
                        store             (258+BP);
                        load              (1+BP);
                        store             (259+BP);
                        load              (0+BP);
                        store             (260+BP);
                        loadi             (1);
                        add               (260+BP);
                        store             (260+BP);
                        load              (260+BP);
                        store             (270+BP);
                        load              (259+BP);
                        store             (269+BP);
                        load              (258+BP);
                        store             (268+BP);
                        movebp            (268);
                        compiler_function_argument_declaration_item(); 
                        movebp            (-268);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_function_argument_declaration_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // function-argument-declaration-list
                                                            // //            function-argument-declaration , function-argument-declaration-list
                                                            // //            function-argument-declaration
                                                            // //
                                                            // syntax_function_argument_declaration_list(int argument_no) {
syntax_function_argument_declaration_end:
return;	}
syntax_function_argument_declaration_list
(){
                                                            // 
                                                            //     if (! syntax_function_argument_declaration(argument_no) ) {
                        load              (0+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        syntax_function_argument_declaration(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_526_false;
                        loadi             (1);
                        if(always())      goto logical_not_526_true;
logical_not_526_false:  loadi             (0);
logical_not_526_true:   if(equals())      goto if_527_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_function_argument_declaration_list_end;
                                                            //     }
                                                            // 
                                                            //     if (! token_advance_if(",") ) {
if_527_next:
if_527_end:             loadi             (4760);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_528_false;
                        loadi             (1);
                        if(always())      goto logical_not_528_true;
logical_not_528_false:  loadi             (0);
logical_not_528_true:   if(equals())      goto if_529_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_function_argument_declaration_list_end;
                                                            //     }
                                                            // 
                                                            //     if (! syntax_function_argument_declaration_list(argument_no + 1) ) {
if_529_next:
if_529_end:             load              (0+BP);
                        store             (1+BP);
                        loadi             (1);
                        add               (1+BP);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        syntax_function_argument_declaration_list(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_530_false;
                        loadi             (1);
                        if(always())      goto logical_not_530_true;
logical_not_530_false:  loadi             (0);
logical_not_530_true:   if(equals())      goto if_531_next;
                                                            //         error_syntax("function argument expected");
                        loadi             (4762);
                        store             (1+BP);
                        load              (1+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     return True;
if_531_next:
if_531_end:             loadi             (1);
                        if(always())      goto syntax_function_argument_declaration_list_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // function-compound-statement
                                                            // //            { local-declaration-list statement-list } 
                                                            // //            { statement-list } 
                                                            // //
                                                            // syntax_function_compound_statement() {
syntax_function_argument_declaration_list_end:
return;	}
syntax_function_compound_statement
(){
                                                            //     
                                                            //     if (! token_advance_if("{") ) {
                        loadi             (4789);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_532_false;
                        loadi             (1);
                        if(always())      goto logical_not_532_true;
logical_not_532_false:  loadi             (0);
logical_not_532_true:   if(equals())      goto if_533_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_function_compound_statement_end;
                                                            //     }
                                                            // 
                                                            //     syntax_local_declaration_list();
if_533_next:
if_533_end:             movebp            (8);
                        syntax_local_declaration_list(); 
                        movebp            (-8);
                                                            // 
                                                            //     compiler_function_compound_statement_locals_declared(); // >>>>>>>>>>
                        movebp            (8);
                        compiler_function_compound_statement_locals_declared(); 
                        movebp            (-8);
                                                            // 
                                                            //     syntax_statement_list();
                        movebp            (8);
                        syntax_statement_list(); 
                        movebp            (-8);
                                                            // 
                                                            //     if (! token_advance_if("}") ) {
                        loadi             (4791);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_advance_if(); 
                        movebp            (-9);
                        if(notequals())   goto logical_not_534_false;
                        loadi             (1);
                        if(always())      goto logical_not_534_true;
logical_not_534_false:  loadi             (0);
logical_not_534_true:   if(equals())      goto if_535_next;
                                                            //         error_syntax("closing brace expected at end of function");
                        loadi             (4793);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     return True;
if_535_next:
if_535_end:             loadi             (1);
                        if(always())      goto syntax_function_compound_statement_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // function-definition
                                                            // //            identifier( function-argument-declaration-list ) function-compound-statement
                                                            // //            identifier( ) function-compound-statement
                                                            // //
                                                            // syntax_function_definition() {
syntax_function_compound_statement_end:
return;	}
syntax_function_definition
(){
                                                            //     char function_name[Str_size];
                                                            // 
                                                            //     if (! (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) ) {
                        loadi             (4);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_type_is();  
                        movebp            (-265);
                        if(equals())      goto logical_and_536_false;
                        loadi             (4835);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_lookahead_text_is(); 
                        movebp            (-265);
                        if(equals())      goto logical_and_536_false;
                        loadi             (1);
                        if(always())      goto logical_and_536_true;
logical_and_536_false:  loadi             (0);
logical_and_536_true:   if(notequals())   goto logical_not_537_false;
                        loadi             (1);
                        if(always())      goto logical_not_537_true;
logical_not_537_false:  loadi             (0);
logical_not_537_true:   if(equals())      goto if_538_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_function_definition_end;
                                                            //     }
                                                            // 
                                                            //     copy(function_name, token_text);
if_538_next:
if_538_end:             loadi             (0+BP);
                        store             (256+BP);
                        loadi             (-1049611+global);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            //     token_advance();
                        movebp            (264);
                        token_advance();  
                        movebp            (-264);
                                                            //     token_advance();
                        movebp            (264);
                        token_advance();  
                        movebp            (-264);
                                                            // 
                                                            //     compiler_output_source_as_comment(); // >>>>>>>>>>
                        movebp            (264);
                        compiler_output_source_as_comment(); 
                        movebp            (-264);
                                                            // 
                                                            //     compiler_function_definition_begin(function_name); // >>>>>>>>>>
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        compiler_function_definition_begin(); 
                        movebp            (-265);
                                                            // 
                                                            //     syntax_function_argument_declaration_list(0);
                        loadi             (0);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        syntax_function_argument_declaration_list(); 
                        movebp            (-265);
                                                            // 
                                                            //     if (! token_advance_if(")") ) {
                        loadi             (4837);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        token_advance_if(); 
                        movebp            (-265);
                        if(notequals())   goto logical_not_539_false;
                        loadi             (1);
                        if(always())      goto logical_not_539_true;
logical_not_539_false:  loadi             (0);
logical_not_539_true:   if(equals())      goto if_540_next;
                                                            //         error_syntax("closing parenthesis expected after function definintion");
                        loadi             (4839);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     if (! syntax_function_compound_statement() ) {
if_540_next:
if_540_end:             movebp            (264);
                        syntax_function_compound_statement(); 
                        movebp            (-264);
                        if(notequals())   goto logical_not_541_false;
                        loadi             (1);
                        if(always())      goto logical_not_541_true;
logical_not_541_false:  loadi             (0);
logical_not_541_true:   if(equals())      goto if_542_next;
                                                            //         error_syntax("function body expected after function definintion");
                        loadi             (4895);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        error_syntax();   
                        movebp            (-265);
                                                            //     }
                                                            // 
                                                            //     compiler_function_definition_end(); // >>>>>>>>>>
if_542_next:
if_542_end:             movebp            (264);
                        compiler_function_definition_end(); 
                        movebp            (-264);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_function_definition_end;
                                                            // }
                                                            // 
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // global-declaration
                                                            // //            declaration
                                                            // //            function-definition
                                                            // //
                                                            // syntax_global_declaration() {
syntax_function_definition_end:
return;	}
syntax_global_declaration
(){
                                                            // 
                                                            //     if (syntax_declaration()) {
                        movebp            (8);
                        syntax_declaration(); 
                        movebp            (-8);
                        if(equals())      goto if_543_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_global_declaration_end;
                                                            //     }
                                                            // 
                                                            //     if (syntax_function_definition()) {
if_543_next:
if_543_end:             movebp            (8);
                        syntax_function_definition(); 
                        movebp            (-8);
                        if(equals())      goto if_544_next;
                                                            //         return True;
                        loadi             (1);
                        if(always())      goto syntax_global_declaration_end;
                                                            //     }
                                                            // 
                                                            //     return False;
if_544_next:
if_544_end:             loadi             (0);
                        if(always())      goto syntax_global_declaration_end;
                                                            // }
                                                            // // ---------------------------------------------------------------------------
                                                            // // global-declaration-list
                                                            // //            global-declaration global-declaration-list
                                                            // //            global-declaration
                                                            // //
                                                            // syntax_global_declaration_list() {
syntax_global_declaration_end:
return;	}
syntax_global_declaration_list
(){
                                                            // 
                                                            //     if (! syntax_global_declaration()) {
                        movebp            (8);
                        syntax_global_declaration(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_545_false;
                        loadi             (1);
                        if(always())      goto logical_not_545_true;
logical_not_545_false:  loadi             (0);
logical_not_545_true:   if(equals())      goto if_546_next;
                                                            //         return False;
                        loadi             (0);
                        if(always())      goto syntax_global_declaration_list_end;
                                                            //     }
                                                            // 
                                                            //     syntax_global_declaration_list();
if_546_next:
if_546_end:             movebp            (8);
                        syntax_global_declaration_list(); 
                        movebp            (-8);
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_global_declaration_list_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // // program
                                                            // //            global-declaration-list
                                                            // //
                                                            // syntax_program() {
syntax_global_declaration_list_end:
return;	}
syntax_program
(){
                                                            //     token_advance();
                        movebp            (8);
                        token_advance();  
                        movebp            (-8);
                                                            // 
                                                            //     compiler_program_begin(); // >>>>>>>>>>
                        movebp            (8);
                        compiler_program_begin(); 
                        movebp            (-8);
                                                            // 
                                                            //     if (! syntax_global_declaration_list()) {
                        movebp            (8);
                        syntax_global_declaration_list(); 
                        movebp            (-8);
                        if(notequals())   goto logical_not_547_false;
                        loadi             (1);
                        if(always())      goto logical_not_547_true;
logical_not_547_false:  loadi             (0);
logical_not_547_true:   if(equals())      goto if_548_next;
                                                            //         error_syntax("function or variable declaration expected");
                        loadi             (4945);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     if (! token_type_is(Token_t_eof)) {
if_548_next:
if_548_end:             loadi             (7);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        token_type_is();  
                        movebp            (-9);
                        if(notequals())   goto logical_not_549_false;
                        loadi             (1);
                        if(always())      goto logical_not_549_true;
logical_not_549_false:  loadi             (0);
logical_not_549_true:   if(equals())      goto if_550_next;
                                                            //         error_syntax("end of file expected");
                        loadi             (4987);
                        store             (0+BP);
                        load              (0+BP);
                        store             (9+BP);
                        movebp            (9);
                        error_syntax();   
                        movebp            (-9);
                                                            //     }
                                                            // 
                                                            //     compiler_output_source_as_comment();
if_550_next:
if_550_end:             movebp            (8);
                        compiler_output_source_as_comment(); 
                        movebp            (-8);
                                                            //     compiler_program_end(); // >>>>>>>>>>
                        movebp            (8);
                        compiler_program_end(); 
                        movebp            (-8);
                                                            // 
                                                            //     return True;
                        loadi             (1);
                        if(always())      goto syntax_program_end;
                                                            // }
                                                            // 
                                                            // #ifndef _MSC_VER
                                                            // #line 2 "bminus.c"
                                                            // #endif
                                                            // 
                                                            // #ifdef _MSC_VER
                                                            // #include "builtinfuncs_ansic.h"
                                                            // #include "globals.h"
                                                            // #include "stringlib.h" 
                                                            // #include "errormessages.h"
                                                            // #include "preprocessor.h" 
                                                            // #include "token.h" 
                                                            // // #include "target_cvirtualmachine.h" 
                                                            // #include "target_javascript.h" 
                                                            // // #include "target_linuxassemblerx86.h" 
                                                            // #include "compiler.h" 
                                                            // #include "syntax.h" 
                                                            // #endif
                                                            // 
                                                            // 
                                                            // main() {
syntax_program_end:
return;	}
main
(){
                                                            //     preprocessor_init();
                        movebp            (8);
                        preprocessor_init(); 
                        movebp            (-8);
                                                            //     token_init();
                        movebp            (8);
                        token_init();     
                        movebp            (-8);
                                                            //     compiler_init();
                        movebp            (8);
                        compiler_init();  
                        movebp            (-8);
                                                            //     target_init();
                        movebp            (8);
                        target_init();    
                        movebp            (-8);
                                                            // 
                                                            //     syntax_program();
                        movebp            (8);
                        syntax_program(); 
                        movebp            (-8);
                                                            // 
                                                            //     exit(0);
                        loadi             (0);
                        exit              (A);
                                                            // 
                                                            // }
                                                            // 
main_end:
return;	}


int global = 8411812;

int BP = 5008;

int RAM[8411812] = {
'F',
'i',
'l',
'e',
':',
' ',
0,
'L',
'i',
'n',
'e',
' ',
'n',
'o',
':',
' ',
0,
'L',
'i',
'n',
'e',
' ',
'p',
'o',
's',
':',
' ',
0,
'C',
'o',
'm',
'p',
'i',
'l',
'e',
' ',
'e',
'r',
'r',
'o',
'r',
':',
' ',
0,
'S',
'y',
'n',
't',
'a',
'x',
' ',
'e',
'r',
'r',
'o',
'r',
':',
' ',
0,
'P',
'a',
'r',
's',
'e',
' ',
'e',
'r',
'r',
'o',
'r',
':',
' ',
0,
'E',
'r',
'r',
'o',
'r',
' ',
'w',
'h',
'i',
'l',
'e',
' ',
'r',
'e',
'a',
'd',
'i',
'n',
'g',
' ',
's',
'o',
'u',
'r',
'c',
'e',
':',
' ',
0,
'C',
'o',
'd',
'e',
' ',
'g',
'e',
'n',
'e',
'r',
'a',
't',
'i',
'o',
'n',
' ',
'e',
'r',
'r',
'o',
'r',
':',
' ',
0,
'I',
'n',
't',
'e',
'r',
'n',
'a',
'l',
' ',
'e',
'r',
'r',
'o',
'r',
0,
0,
0,
'N',
'/',
'A',
0,
0,
'l',
'i',
'n',
'e',
' ',
't',
'o',
'o',
' ',
'l',
'o',
'n',
'g',
0,
0,
'#',
'l',
'i',
'n',
'e',
' ',
'2',
' ',
0,
0,
'#',
'l',
'i',
'n',
'e',
' ',
'2',
' ',
0,
'#',
0,
'i',
'n',
'v',
'a',
'l',
'i',
'd',
' ',
'c',
'h',
'a',
'r',
'a',
'c',
't',
'e',
'r',
' ',
'e',
's',
'c',
'a',
'p',
'e',
' ',
's',
'e',
'q',
'u',
'e',
'n',
'c',
'e',
0,
's',
't',
'r',
'i',
'n',
'g',
' ',
'l',
'i',
't',
'e',
'r',
'a',
'l',
' ',
'n',
'o',
't',
' ',
't',
'e',
'r',
'm',
'i',
'n',
'a',
't',
'e',
'd',
0,
'_',
'a',
'b',
'c',
'd',
'e',
'f',
'g',
'h',
'i',
'j',
'k',
'l',
'm',
'n',
'o',
'p',
'q',
'r',
's',
't',
'u',
'v',
'w',
'x',
'y',
'z',
'A',
'B',
'C',
'D',
'E',
'F',
'G',
'H',
'I',
'J',
'K',
'L',
'M',
'N',
'O',
'P',
'Q',
'R',
'S',
'T',
'U',
'V',
'W',
'X',
'Y',
'Z',
'0',
'1',
'2',
'3',
'4',
'5',
'6',
'7',
'8',
'9',
0,
'_',
'a',
'b',
'c',
'd',
'e',
'f',
'g',
'h',
'i',
'j',
'k',
'l',
'm',
'n',
'o',
'p',
'q',
'r',
's',
't',
'u',
'v',
'w',
'x',
'y',
'z',
'A',
'B',
'C',
'D',
'E',
'F',
'G',
'H',
'I',
'J',
'K',
'L',
'M',
'N',
'O',
'P',
'Q',
'R',
'S',
'T',
'U',
'V',
'W',
'X',
'Y',
'Z',
0,
' ',
0,
' ',
0,
' ',
'i',
'n',
't',
' ',
'c',
'h',
'a',
'r',
' ',
'i',
'f',
' ',
'e',
'l',
's',
'e',
' ',
'w',
'h',
'i',
'l',
'e',
' ',
'e',
'n',
'u',
'm',
' ',
'r',
'e',
't',
'u',
'r',
'n',
' ',
0,
'c',
'h',
'a',
'r',
'a',
'c',
't',
'e',
'r',
' ',
'c',
'o',
'n',
's',
't',
'a',
'n',
't',
' ',
'n',
'o',
't',
' ',
't',
'e',
'r',
'm',
'i',
'n',
'a',
't',
'e',
'd',
0,
'0',
'1',
'2',
'3',
'4',
'5',
'6',
'7',
'8',
'9',
0,
0,
'<',
'>',
'=',
'+',
'-',
'/',
'*',
'(',
')',
'[',
']',
'{',
'}',
'!',
';',
',',
0,
0,
0,
0,
'#',
'i',
'n',
'c',
'l',
'u',
'd',
'e',
' ',
'<',
's',
't',
'd',
'i',
'o',
'.',
'h',
'>',
0,
'#',
'i',
'n',
'c',
'l',
'u',
'd',
'e',
' ',
'<',
's',
't',
'd',
'l',
'i',
'b',
'.',
'h',
'>',
0,
0,
'i',
'n',
't',
' ',
'A',
';',
0,
'i',
'n',
't',
' ',
'X',
';',
0,
'e',
'x',
't',
'e',
'r',
'n',
' ',
'i',
'n',
't',
' ',
'B',
'P',
';',
0,
'e',
'x',
't',
'e',
'r',
'n',
' ',
'i',
'n',
't',
' ',
'R',
'A',
'M',
'[',
']',
';',
0,
0,
'l',
'o',
'a',
'd',
'i',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'A',
' ',
'=',
' ',
'n',
';',
' ',
'}',
0,
0,
'l',
'o',
'a',
'd',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'A',
' ',
'=',
' ',
'R',
'A',
'M',
'[',
'n',
']',
';',
' ',
'}',
0,
's',
't',
'o',
'r',
'e',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'R',
'A',
'M',
'[',
'n',
']',
' ',
'=',
' ',
'A',
';',
' ',
'}',
0,
0,
'a',
'd',
'd',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'A',
' ',
'+',
'=',
' ',
'R',
'A',
'M',
'[',
'n',
']',
';',
' ',
'}',
0,
's',
'u',
'b',
't',
'r',
'a',
'c',
't',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'A',
' ',
'-',
'=',
' ',
'R',
'A',
'M',
'[',
'n',
']',
';',
' ',
'}',
0,
'm',
'u',
'l',
't',
'i',
'p',
'l',
'y',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'A',
' ',
'*',
'=',
' ',
'R',
'A',
'M',
'[',
'n',
']',
';',
' ',
'}',
0,
'd',
'i',
'v',
'i',
'd',
'e',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'A',
' ',
'/',
'=',
' ',
'R',
'A',
'M',
'[',
'n',
']',
';',
' ',
'}',
0,
0,
'l',
'o',
'a',
'd',
'x',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
')',
' ',
' ',
' ',
' ',
' ',
' ',
'{',
' ',
'X',
' ',
'=',
' ',
'A',
';',
' ',
'}',
0,
'm',
'o',
'v',
'e',
'b',
'p',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
'i',
'n',
't',
' ',
'n',
')',
' ',
'{',
' ',
'B',
'P',
' ',
'+',
'=',
' ',
'n',
';',
' ',
'}',
0,
0,
'l',
'e',
's',
's',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
')',
' ',
' ',
' ',
' ',
' ',
' ',
'{',
' ',
'r',
'e',
't',
'u',
'r',
'n',
' ',
'A',
' ',
'>',
' ',
'0',
';',
' ',
'}',
0,
'g',
'r',
'e',
'a',
't',
'e',
'r',
' ',
' ',
' ',
' ',
' ',
'(',
')',
' ',
' ',
' ',
' ',
' ',
' ',
'{',
' ',
'r',
'e',
't',
'u',
'r',
'n',
' ',
'A',
' ',
'<',
' ',
'0',
';',
' ',
'}',
0,
'e',
'q',
'u',
'a',
'l',
's',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
')',
' ',
' ',
' ',
' ',
' ',
' ',
'{',
' ',
'r',
'e',
't',
'u',
'r',
'n',
' ',
'A',
' ',
'=',
'=',
' ',
'0',
';',
' ',
'}',
0,
'n',
'o',
't',
'e',
'q',
'u',
'a',
'l',
's',
' ',
' ',
' ',
'(',
')',
' ',
' ',
' ',
' ',
' ',
' ',
'{',
' ',
'r',
'e',
't',
'u',
'r',
'n',
' ',
'A',
' ',
'!',
'=',
' ',
'0',
';',
' ',
'}',
0,
'a',
'l',
'w',
'a',
'y',
's',
' ',
' ',
' ',
' ',
' ',
' ',
'(',
')',
' ',
' ',
' ',
' ',
' ',
' ',
'{',
' ',
'r',
'e',
't',
'u',
'r',
'n',
' ',
'1',
';',
' ',
'}',
0,
0,
'e',
'x',
't',
'e',
'r',
'n',
' ',
'i',
'n',
't',
' ',
'g',
'l',
'o',
'b',
'a',
'l',
';',
0,
0,
0,
0,
'i',
'n',
't',
' ',
'g',
'l',
'o',
'b',
'a',
'l',
' ',
'=',
' ',
0,
';',
0,
0,
'i',
'n',
't',
' ',
'B',
'P',
' ',
'=',
' ',
0,
';',
0,
0,
'i',
'n',
't',
' ',
'R',
'A',
'M',
'[',
0,
']',
' ',
'=',
' ',
'{',
0,
'\'',
'\\',
' ',
'\'',
0,
'\'',
' ',
'\'',
0,
',',
0,
'}',
';',
0,
0,
0,
0,
'/',
'/',
' ',
0,
0,
0,
0,
':',
0,
0,
' ',
0,
' ',
0,
'i',
'f',
'(',
0,
'(',
')',
')',
0,
'g',
'o',
't',
'o',
' ',
0,
';',
0,
'+',
'g',
'l',
'o',
'b',
'a',
'l',
0,
'+',
'g',
'l',
'o',
'b',
'a',
'l',
0,
'+',
'X',
0,
'+',
'B',
'P',
0,
'+',
'B',
'P',
'+',
'X',
0,
'X',
0,
'(',
0,
')',
';',
0,
'(',
0,
')',
';',
0,
'(',
')',
';',
0,
'a',
'l',
'w',
'a',
'y',
's',
0,
'a',
'l',
'w',
'a',
'y',
's',
0,
'l',
'e',
's',
's',
0,
'g',
'r',
'e',
'a',
't',
'e',
'r',
0,
'e',
'q',
'u',
'a',
'l',
's',
0,
'n',
'o',
't',
'e',
'q',
'u',
'a',
'l',
's',
0,
'l',
'o',
'a',
'd',
'x',
0,
'l',
'o',
'a',
'd',
'i',
0,
'l',
'o',
'a',
'd',
'i',
0,
'l',
'o',
'a',
'd',
0,
's',
't',
'o',
'r',
'e',
0,
'a',
'd',
'd',
0,
's',
'u',
'b',
't',
'r',
'a',
'c',
't',
0,
'm',
'u',
'l',
't',
'i',
'p',
'l',
'y',
0,
'd',
'i',
'v',
'i',
'd',
'e',
0,
'(',
')',
'{',
0,
0,
0,
'r',
'e',
't',
'u',
'r',
'n',
';',
9,
'}',
0,
'm',
'o',
'v',
'e',
'b',
'p',
0,
'(',
')',
';',
0,
0,
'm',
'o',
'v',
'e',
'b',
'p',
0,
's',
't',
'o',
'r',
'e',
0,
0,
':',
0,
'p',
'r',
'i',
'n',
't',
'f',
0,
'(',
'"',
'%',
'd',
'\\',
'n',
'"',
',',
' ',
'A',
')',
';',
0,
'e',
'x',
'i',
't',
0,
'(',
'A',
')',
';',
0,
'A',
'=',
'f',
'g',
'e',
't',
'c',
0,
'(',
's',
't',
'd',
'i',
'n',
')',
';',
0,
'f',
'p',
'u',
't',
'c',
0,
'(',
'A',
',',
' ',
's',
't',
'd',
'o',
'u',
't',
')',
';',
0,
'f',
'p',
'u',
't',
'c',
0,
'(',
'A',
',',
' ',
's',
't',
'd',
'e',
'r',
'r',
')',
';',
0,
'o',
'u',
't',
' ',
'o',
'f',
' ',
'i',
'n',
'i',
't',
'i',
'a',
'l',
'i',
's',
'e',
'd',
' ',
'(',
's',
't',
'r',
'i',
'n',
'g',
')',
' ',
's',
't',
'o',
'r',
'a',
'g',
'e',
' ',
's',
'p',
'a',
'c',
'e',
0,
'_',
0,
0,
0,
0,
'n',
'a',
'm',
'e',
' ',
'a',
'l',
'r',
'e',
'a',
'd',
'y',
' ',
'd',
'e',
'f',
'i',
'n',
'e',
'd',
0,
'o',
'u',
't',
' ',
'o',
'f',
' ',
's',
'y',
'm',
'b',
'o',
'l',
' ',
't',
'a',
'b',
'l',
'e',
' ',
's',
'p',
'a',
'c',
'e',
0,
'n',
'a',
'm',
'e',
' ',
'n',
'o',
't',
' ',
'd',
'e',
'f',
'i',
'n',
'e',
'd',
0,
't',
'o',
'o',
' ',
'm',
'a',
'n',
'y',
' ',
'l',
'o',
'c',
'a',
'l',
' ',
't',
'e',
'm',
'p',
'o',
'r',
'a',
'r',
'y',
' ',
'v',
'a',
'r',
'i',
'a',
'b',
'l',
'e',
's',
0,
'_',
0,
'a',
'r',
'r',
'a',
'y',
' ',
'l',
'e',
'n',
'g',
't',
'h',
' ',
'm',
'u',
's',
't',
' ',
'b',
'e',
' ',
'g',
'r',
'e',
'a',
't',
'e',
'r',
' ',
't',
'h',
'a',
'n',
' ',
'z',
'e',
'r',
'o',
0,
'c',
'o',
'n',
's',
't',
'a',
'n',
't',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'l',
'e',
'n',
'g',
't',
'h',
' ',
's',
'p',
'e',
'c',
'i',
'f',
'i',
'e',
'r',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'_',
'e',
'n',
'd',
0,
'_',
'e',
'n',
'd',
0,
0,
'i',
'd',
'e',
'n',
't',
'i',
'f',
'i',
'e',
'r',
' ',
'c',
'a',
'n',
'n',
'o',
't',
' ',
'b',
'e',
' ',
'u',
's',
'e',
'd',
' ',
'i',
'n',
' ',
'a',
'n',
' ',
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
0,
'+',
0,
'-',
0,
'!',
0,
'l',
'o',
'g',
'i',
'c',
'a',
'l',
'_',
'n',
'o',
't',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'*',
0,
'/',
0,
'+',
0,
'-',
0,
'c',
'o',
'm',
'p',
'a',
'r',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'=',
'=',
0,
'_',
't',
'r',
'u',
'e',
0,
'!',
'=',
0,
'_',
't',
'r',
'u',
'e',
0,
'<',
0,
'_',
't',
'r',
'u',
'e',
0,
'<',
'=',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'>',
0,
'_',
't',
'r',
'u',
'e',
0,
'>',
'=',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'l',
'o',
'g',
'i',
'c',
'a',
'l',
'_',
'a',
'n',
'd',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'l',
'o',
'g',
'i',
'c',
'a',
'l',
'_',
'o',
'r',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
't',
'r',
'u',
'e',
0,
'_',
'f',
'a',
'l',
's',
'e',
0,
'_',
'e',
'n',
'd',
0,
'l',
'e',
'f',
't',
' ',
'h',
'a',
'n',
'd',
' ',
's',
'i',
'd',
'e',
' ',
'o',
'f',
' ',
'a',
's',
's',
'i',
'g',
'n',
'm',
'e',
'n',
't',
' ',
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
' ',
'm',
'u',
's',
't',
' ',
'b',
'e',
' ',
'a',
'n',
' ',
'i',
'n',
't',
'e',
'g',
'e',
'r',
' ',
'i',
'd',
'e',
'n',
't',
'i',
'f',
'i',
'e',
'r',
' ',
'o',
'r',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'e',
'l',
'e',
'm',
'e',
'n',
't',
0,
'w',
'h',
'i',
'l',
'e',
0,
'_',
'e',
'n',
'd',
0,
'_',
't',
'e',
's',
't',
0,
'_',
't',
'e',
's',
't',
0,
'_',
't',
'e',
's',
't',
0,
'_',
'e',
'n',
'd',
0,
'_',
'e',
'n',
'd',
0,
'i',
'f',
0,
'_',
'e',
'n',
'd',
0,
'_',
'n',
'e',
'x',
't',
0,
'_',
'n',
'e',
'x',
't',
0,
'_',
'e',
'n',
'd',
0,
'_',
'n',
'e',
'x',
't',
0,
'_',
'n',
'e',
'x',
't',
0,
'_',
'e',
'n',
'd',
0,
'_',
'e',
'n',
'd',
0,
'f',
'g',
'e',
't',
'c',
0,
'(',
0,
's',
't',
'd',
'i',
'n',
0,
')',
0,
'f',
'g',
'e',
't',
'c',
'(',
's',
't',
'd',
'i',
'n',
')',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'f',
'p',
'u',
't',
'c',
0,
'(',
0,
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'f',
'p',
'u',
't',
'c',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'f',
'p',
'u',
't',
'c',
' ',
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
0,
',',
0,
'f',
'p',
'u',
't',
'c',
' ',
't',
'a',
'k',
'e',
's',
' ',
't',
'w',
'o',
' ',
'a',
'r',
'g',
'u',
'm',
'e',
'n',
't',
's',
0,
's',
't',
'd',
'o',
'u',
't',
0,
's',
't',
'd',
'e',
'r',
'r',
0,
's',
'e',
'c',
'o',
'n',
'd',
' ',
'a',
'r',
'g',
'u',
'm',
'e',
'n',
't',
' ',
'o',
'f',
' ',
'f',
'p',
'u',
't',
'c',
' ',
'm',
'u',
's',
't',
' ',
'b',
'e',
' ',
's',
't',
'd',
'o',
'u',
't',
' ',
'o',
'r',
' ',
's',
't',
'd',
'e',
'r',
'r',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'e',
'x',
'i',
't',
0,
'(',
0,
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'x',
'i',
't',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'x',
'i',
't',
' ',
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'd',
'e',
'b',
'u',
'g',
0,
'(',
0,
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'd',
'e',
'b',
'u',
'g',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'd',
'e',
'b',
'u',
'g',
' ',
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'[',
0,
',',
0,
'(',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'c',
'a',
'l',
'l',
' ',
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
0,
'[',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'k',
'e',
't',
0,
']',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'k',
'e',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'(',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
0,
' ',
'!',
' ',
'+',
' ',
'-',
' ',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'u',
'n',
'a',
'r',
'y',
' ',
'o',
'p',
'e',
'r',
'a',
't',
'o',
'r',
0,
' ',
'*',
' ',
'/',
' ',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'u',
'n',
'a',
'r',
'y',
' ',
'o',
'p',
'e',
'r',
'a',
't',
'o',
'r',
0,
' ',
'+',
' ',
'-',
' ',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'r',
'i',
'g',
'h',
't',
' ',
'o',
'f',
' ',
'a',
'd',
'd',
'i',
't',
'i',
'v',
'e',
' ',
'o',
'p',
'e',
'r',
'a',
't',
'o',
'r',
0,
' ',
'<',
' ',
'<',
'=',
' ',
'>',
' ',
'>',
'=',
' ',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'r',
'i',
'g',
'h',
't',
' ',
'o',
'f',
' ',
'r',
'e',
'l',
'a',
't',
'i',
'o',
'n',
'a',
'l',
' ',
'o',
'p',
'e',
'r',
'a',
't',
'o',
'r',
0,
' ',
'=',
'=',
' ',
'!',
'=',
' ',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'r',
'i',
'g',
'h',
't',
' ',
'o',
'f',
' ',
'e',
'q',
'u',
'a',
'l',
'i',
't',
'y',
' ',
'o',
'p',
'e',
'r',
'a',
't',
'o',
'r',
0,
'&',
'&',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'r',
'i',
'g',
'h',
't',
' ',
'o',
'f',
' ',
'l',
'o',
'g',
'i',
'c',
'a',
'l',
' ',
'a',
'n',
'd',
0,
'&',
'&',
0,
'|',
'|',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'r',
'i',
'g',
'h',
't',
' ',
'o',
'f',
' ',
'l',
'o',
'g',
'i',
'c',
'a',
'l',
'-',
'o',
'r',
' ',
'o',
'p',
'e',
'r',
'a',
't',
'o',
'r',
0,
'|',
'|',
0,
'(',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'c',
'a',
'l',
'l',
0,
'r',
'e',
't',
'u',
'r',
'n',
0,
'=',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'q',
'u',
'a',
'l',
' ',
's',
'i',
'g',
'n',
0,
'[',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'w',
'i',
't',
'h',
'i',
'n',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'i',
'n',
'd',
'e',
'x',
0,
']',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'k',
'e',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'i',
'n',
'd',
'e',
'x',
0,
'=',
0,
'e',
'q',
'u',
'a',
'l',
' ',
's',
'i',
'g',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'i',
'n',
'd',
'e',
'x',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'q',
'u',
'a',
'l',
' ',
's',
'i',
'g',
'n',
0,
'w',
'h',
'i',
'l',
'e',
0,
'(',
0,
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'w',
'h',
'i',
'l',
'e',
' ',
'k',
'e',
'y',
'w',
'o',
'r',
'd',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'i',
'n',
' ',
'w',
'h',
'i',
'l',
'e',
' ',
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'w',
'h',
'i',
'l',
'e',
' ',
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
0,
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'w',
'h',
'i',
'l',
'e',
0,
'i',
'f',
0,
'(',
0,
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'i',
'f',
' ',
'k',
'e',
'y',
'w',
'o',
'r',
'd',
0,
'e',
'x',
'p',
'r',
'e',
's',
's',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'i',
'n',
' ',
'i',
'f',
' ',
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'i',
'f',
' ',
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
0,
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'i',
'f',
0,
'e',
'l',
's',
'e',
0,
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'l',
's',
'e',
0,
'=',
0,
'i',
'n',
't',
'e',
'g',
'e',
'r',
' ',
'c',
'o',
'n',
's',
't',
'a',
'n',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'q',
'u',
'a',
'l',
' ',
's',
'i',
'g',
'n',
' ',
'i',
'n',
' ',
'e',
'n',
'u',
'm',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
',',
0,
'i',
'd',
'e',
'n',
't',
'i',
'f',
'i',
'e',
'r',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'c',
'o',
'm',
'm',
'a',
' ',
'i',
'n',
' ',
'e',
'n',
'u',
'm',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
'i',
'n',
't',
0,
'c',
'h',
'a',
'r',
0,
'i',
'd',
'e',
'n',
't',
'i',
'f',
'i',
'e',
'r',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
't',
'y',
'p',
'e',
' ',
's',
'p',
'e',
'c',
'i',
'f',
'i',
'e',
'r',
' ',
'i',
'n',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
'[',
0,
';',
0,
's',
'e',
'm',
'i',
'c',
'o',
'l',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
'i',
'd',
'e',
'n',
't',
'i',
'f',
'i',
'e',
'r',
' ',
'o',
'r',
' ',
'i',
'n',
't',
'e',
'g',
'e',
'r',
' ',
'c',
'o',
'n',
's',
't',
'a',
'n',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'k',
'e',
't',
' ',
'i',
'n',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
']',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'k',
'e',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'i',
'n',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
';',
0,
's',
'e',
'm',
'i',
'c',
'o',
'l',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
'e',
'n',
'u',
'm',
0,
'{',
0,
'o',
'p',
'e',
'n',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'e',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'n',
'u',
'm',
' ',
'k',
'e',
'y',
'w',
'o',
'r',
'd',
0,
'e',
'n',
'u',
'm',
'e',
'r',
'a',
't',
'o',
'r',
' ',
'l',
'i',
's',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'}',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'e',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'n',
'u',
'm',
'e',
'r',
'a',
't',
'o',
'r',
' ',
'l',
'i',
's',
't',
0,
';',
0,
's',
'e',
'm',
'i',
'c',
'o',
'l',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'e',
'n',
'u',
'm',
'e',
'r',
'a',
't',
'o',
'r',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
'{',
0,
'}',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'e',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
't',
' ',
'e',
'n',
'd',
' ',
'o',
'f',
' ',
'c',
'o',
'm',
'p',
'o',
'u',
'n',
'd',
' ',
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
0,
';',
0,
's',
'e',
'm',
'i',
'c',
'o',
'l',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
's',
't',
'a',
't',
'e',
'm',
'e',
'n',
't',
0,
'i',
'd',
'e',
'n',
't',
'i',
'f',
'i',
'e',
'r',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
't',
'y',
'p',
'e',
' ',
's',
'p',
'e',
'c',
'i',
'f',
'i',
'e',
'r',
' ',
'i',
'n',
' ',
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'd',
'e',
'f',
'i',
'n',
'i',
't',
'i',
'o',
'n',
0,
'[',
0,
']',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'k',
'e',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'a',
'r',
'r',
'a',
'y',
' ',
'a',
'r',
'g',
'u',
'm',
'e',
'n',
't',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
0,
',',
0,
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'a',
'r',
'g',
'u',
'm',
'e',
'n',
't',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'{',
0,
'}',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'b',
'r',
'a',
'c',
'e',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
't',
' ',
'e',
'n',
'd',
' ',
'o',
'f',
' ',
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
0,
'(',
0,
')',
0,
'c',
'l',
'o',
's',
'i',
'n',
'g',
' ',
'p',
'a',
'r',
'e',
'n',
't',
'h',
'e',
's',
'i',
's',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'd',
'e',
'f',
'i',
'n',
'i',
'n',
't',
'i',
'o',
'n',
0,
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'b',
'o',
'd',
'y',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
' ',
'a',
'f',
't',
'e',
'r',
' ',
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'd',
'e',
'f',
'i',
'n',
'i',
'n',
't',
'i',
'o',
'n',
0,
'f',
'u',
'n',
'c',
't',
'i',
'o',
'n',
' ',
'o',
'r',
' ',
'v',
'a',
'r',
'i',
'a',
'b',
'l',
'e',
' ',
'd',
'e',
'c',
'l',
'a',
'r',
'a',
't',
'i',
'o',
'n',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0,
'e',
'n',
'd',
' ',
'o',
'f',
' ',
'f',
'i',
'l',
'e',
' ',
'e',
'x',
'p',
'e',
'c',
't',
'e',
'd',
0
};


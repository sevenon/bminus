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
                                                            // enum { False = 0, True = 1 };
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
                                                            // 	while(str[i] != 0) {
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
                                                            // strequals(char str1[], char str2[]) {
writeln_end:
return;	}
strequals
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(str1[i] == str2[i]) {
while_2_test:           load              (2+BP);
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
                        if(equals())      goto compare_3_true;
                        loadi             (0);
                        if(always())      goto compare_3_false;
compare_3_true:         loadi             (1);
compare_3_false:        if(equals())      goto while_2_end;
                                                            // 		if(str1[i] == 0 && str2[i] == 0)
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
                        if(equals())      goto compare_4_true;
                        loadi             (0);
                        if(always())      goto compare_4_false;
compare_4_true:         loadi             (1);
compare_4_false:        if(equals())      goto logical_and_5_false;
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
                        if(equals())      goto compare_6_true;
                        loadi             (0);
                        if(always())      goto compare_6_false;
compare_6_true:         loadi             (1);
compare_6_false:        if(equals())      goto logical_and_5_false;
                        loadi             (1);
                        if(always())      goto logical_and_5_true;
logical_and_5_false:    loadi             (0);
logical_and_5_true:     if(equals())      goto if_7_next;
                                                            // 			return True;
                        loadi             (1);
                        if(always())      goto strequals_end;
if_7_next:
                                                            // 		
                                                            // 		if(str1[i] == 0 || str2[i] == 0)
if_7_end:               load              (2+BP);
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
                        if(equals())      goto compare_8_true;
                        loadi             (0);
                        if(always())      goto compare_8_false;
compare_8_true:         loadi             (1);
compare_8_false:        if(notequals())   goto logical_or_9_true;
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
                        if(equals())      goto compare_10_true;
                        loadi             (0);
                        if(always())      goto compare_10_false;
compare_10_true:        loadi             (1);
compare_10_false:       if(notequals())   goto logical_or_9_true;
                        loadi             (0);
                        if(always())      goto logical_or_9_false;
logical_or_9_true:      loadi             (1);
logical_or_9_false:     if(equals())      goto if_11_next;
                                                            // 			return False;
                        loadi             (0);
                        if(always())      goto strequals_end;
if_11_next:
                                                            // 
                                                            // 		i = i + 1;
if_11_end:              load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      goto while_2_test;
while_2_end:            loadi             (0);
                        if(always())      goto strequals_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // copy(char dest[], char src[]) {
strequals_end:
return;	}
copy
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(src[i] != 0) {
while_12_test:          load              (2+BP);
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
                        if(notequals())   goto compare_13_true;
                        loadi             (0);
                        if(always())      goto compare_13_false;
compare_13_true:        loadi             (1);
compare_13_false:       if(equals())      goto while_12_end;
                                                            // 		dest[i] = src[i];
                        load              (2+BP);
                        store             (3+BP);
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
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
                                                            // 
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	dest[i] = 0;
                        if(always())      goto while_12_test;
while_12_end:           load              (2+BP);
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
                                                            // append(char dest[], char src[]) {
copy_end:
return;	}
append
(){
                                                            // 	int i;
                                                            // 	int j;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(dest[i] != 0) {
while_14_test:          load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (0+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
                        store             (4+BP);
                        loadi             (0);
                        subtract          (4+BP);
                        if(notequals())   goto compare_15_true;
                        loadi             (0);
                        if(always())      goto compare_15_false;
compare_15_true:        loadi             (1);
compare_15_false:       if(equals())      goto while_14_end;
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	j = 0;
                        if(always())      goto while_14_test;
while_14_end:           loadi             (0);
                        store             (3+BP);
                                                            // 	while(src[j] != 0) {
while_16_test:          load              (3+BP);
                        loadx             ();
                        loadi             (X);
                        store             (4+BP);
                        load              (1+BP);
                        add               (4+BP);
                        loadx             ();
                        load              (X);
                        store             (4+BP);
                        loadi             (0);
                        subtract          (4+BP);
                        if(notequals())   goto compare_17_true;
                        loadi             (0);
                        if(always())      goto compare_17_false;
compare_17_true:        loadi             (1);
compare_17_false:       if(equals())      goto while_16_end;
                                                            // 		dest[i] = src[j];
                        load              (2+BP);
                        store             (4+BP);
                        load              (3+BP);
                        loadx             ();
                        loadi             (X);
                        store             (5+BP);
                        load              (1+BP);
                        add               (5+BP);
                        loadx             ();
                        load              (X);
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
                                                            // 
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (2+BP);
                                                            // 		j = j + 1;
                        load              (3+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (3+BP);
                                                            // 	}
                                                            // 
                                                            // 	dest[i] = 0;
                        if(always())      goto while_16_test;
while_16_end:           load              (2+BP);
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
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // append_char(char dest[], int c) {
append_end:
return;	}
append_char
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(dest[i] != 0) {
while_18_test:          load              (2+BP);
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
                        if(notequals())   goto compare_19_true;
                        loadi             (0);
                        if(always())      goto compare_19_false;
compare_19_true:        loadi             (1);
compare_19_false:       if(equals())      goto while_18_end;
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	dest[i] = c;
                        if(always())      goto while_18_test;
while_18_end:           load              (2+BP);
                        store             (3+BP);
                        load              (1+BP);
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
                                                            // 	dest[i + 1] = 0;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
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
append_char_end:
return;	}
contains
(){
                                                            // 	int i;
                                                            // 	int j;
                                                            // 	int k;
                                                            // 
                                                            // 	if(substr[0] == 0)
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
                        if(equals())      goto compare_20_true;
                        loadi             (0);
                        if(always())      goto compare_20_false;
compare_20_true:        loadi             (1);
compare_20_false:       if(equals())      goto if_21_next;
                                                            // 		return True;
                        loadi             (1);
                        if(always())      goto contains_end;
if_21_next:
                                                            // 
                                                            // 	i = 0;
if_21_end:              loadi             (0);
                        store             (2+BP);
                                                            // 	while (str[i] != 0) {
while_22_test:          load              (2+BP);
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
                        if(notequals())   goto compare_23_true;
                        loadi             (0);
                        if(always())      goto compare_23_false;
compare_23_true:        loadi             (1);
compare_23_false:       if(equals())      goto while_22_end;
                                                            // 		j = i;
                        load              (2+BP);
                        store             (3+BP);
                                                            // 		k = 0;
                        loadi             (0);
                        store             (4+BP);
                                                            // 		while(str[j] == substr[k]) {
while_24_test:          load              (3+BP);
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
                        if(equals())      goto compare_25_true;
                        loadi             (0);
                        if(always())      goto compare_25_false;
compare_25_true:        loadi             (1);
compare_25_false:       if(equals())      goto while_24_end;
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
                                                            // 
                                                            // 			if(substr[k] == 0)
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
                        if(equals())      goto compare_26_true;
                        loadi             (0);
                        if(always())      goto compare_26_false;
compare_26_true:        loadi             (1);
compare_26_false:       if(equals())      goto if_27_next;
                                                            // 				return True;
                        loadi             (1);
                        if(always())      goto contains_end;
if_27_next:
                                                            // 		}
                                                            // 
                                                            // 		i = i + 1;
if_27_end:              if(always())      goto while_24_test;
while_24_end:           load              (2+BP);
                        store             (5+BP);
                        loadi             (1);
                        add               (5+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      goto while_22_test;
while_22_end:           loadi             (0);
                        if(always())      goto contains_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // contains_char(char str[], int c) {
contains_end:
return;	}
contains_char
(){
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while (str[i] != 0) {
while_28_test:          load              (2+BP);
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
                        if(notequals())   goto compare_29_true;
                        loadi             (0);
                        if(always())      goto compare_29_false;
compare_29_true:        loadi             (1);
compare_29_false:       if(equals())      goto while_28_end;
                                                            // 		if (str[i] == c)
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (3+BP);
                        load              (0+BP);
                        add               (3+BP);
                        loadx             ();
                        load              (X);
                        store             (3+BP);
                        load              (1+BP);
                        subtract          (3+BP);
                        if(equals())      goto compare_30_true;
                        loadi             (0);
                        if(always())      goto compare_30_false;
compare_30_true:        loadi             (1);
compare_30_false:       if(equals())      goto if_31_next;
                                                            // 			return True;
                        loadi             (1);
                        if(always())      goto contains_char_end;
if_31_next:
                                                            // 
                                                            // 		i = i + 1;
if_31_end:              load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      goto while_28_test;
while_28_end:           loadi             (0);
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
                                                            // 	while (str[i] != 0)
while_32_test:          load              (1+BP);
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
                        if(notequals())   goto compare_33_true;
                        loadi             (0);
                        if(always())      goto compare_33_false;
compare_33_true:        loadi             (1);
compare_33_false:       if(equals())      goto while_32_end;
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                        if(always())      goto while_32_test;
                                                            // 
                                                            // 	return i;
while_32_end:           load              (1+BP);
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
while_34_test:          load              (1+BP);
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
                        if(notequals())   goto compare_35_true;
                        loadi             (0);
                        if(always())      goto compare_35_false;
compare_35_true:        loadi             (1);
compare_35_false:       if(equals())      goto while_34_end;
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
                                                            // 
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (1+BP);
                                                            // 	}
                                                            // 
                                                            // 	return n;
                        if(always())      goto while_34_test;
while_34_end:           load              (2+BP);
                        if(always())      goto str_to_int_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // int_to_str(int n, char str[]) {
str_to_int_end:
return;	}
int_to_str
(){
                                                            // 	int i;
                                                            // 	int j;
                                                            // 	int n_mod_10;
                                                            // 	char tmp_swap;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(i == 0 || n != 0) {
while_36_test:          load              (2+BP);
                        store             (6+BP);
                        loadi             (0);
                        subtract          (6+BP);
                        if(equals())      goto compare_37_true;
                        loadi             (0);
                        if(always())      goto compare_37_false;
compare_37_true:        loadi             (1);
compare_37_false:       if(notequals())   goto logical_or_38_true;
                        load              (0+BP);
                        store             (6+BP);
                        loadi             (0);
                        subtract          (6+BP);
                        if(notequals())   goto compare_39_true;
                        loadi             (0);
                        if(always())      goto compare_39_false;
compare_39_true:        loadi             (1);
compare_39_false:       if(notequals())   goto logical_or_38_true;
                        loadi             (0);
                        if(always())      goto logical_or_38_false;
logical_or_38_true:     loadi             (1);
logical_or_38_false:    if(equals())      goto while_36_end;
                                                            // 		n_mod_10 = n - (10 * ( n / 10));
                        load              (0+BP);
                        store             (6+BP);
                        loadi             (10);
                        store             (7+BP);
                        load              (0+BP);
                        store             (8+BP);
                        loadi             (10);
                        store             (9+BP);
                        load              (8+BP);
                        divide            (9+BP);
                        multiply          (7+BP);
                        store             (7+BP);
                        load              (6+BP);
                        subtract          (7+BP);
                        store             (4+BP);
                                                            // 		str[i] = '0' + n_mod_10;
                        load              (2+BP);
                        store             (6+BP);
                        loadi             (48);
                        store             (7+BP);
                        load              (4+BP);
                        add               (7+BP);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (6+BP);
                        loadi             (X);
                        store             (7+BP);
                        load              (1+BP);
                        add               (7+BP);
                        loadx             ();
                        load              (6+BP);
                        store             (X);
                                                            // 		n = n / 10;
                        load              (0+BP);
                        store             (6+BP);
                        loadi             (10);
                        store             (7+BP);
                        load              (6+BP);
                        divide            (7+BP);
                        store             (0+BP);
                                                            // 
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (6+BP);
                        loadi             (1);
                        add               (6+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	str[i] = 0;
                        if(always())      goto while_36_test;
while_36_end:           load              (2+BP);
                        store             (6+BP);
                        loadi             (0);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (6+BP);
                        loadi             (X);
                        store             (7+BP);
                        load              (1+BP);
                        add               (7+BP);
                        loadx             ();
                        load              (6+BP);
                        store             (X);
                                                            // 
                                                            // 	i = i - 1;
                        load              (2+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (6+BP);
                        subtract          (7+BP);
                        store             (2+BP);
                                                            // 	j = 0;
                        loadi             (0);
                        store             (3+BP);
                                                            // 	while(j < i) {
while_40_test:          load              (3+BP);
                        store             (6+BP);
                        load              (2+BP);
                        subtract          (6+BP);
                        if(less())        goto compare_41_true;
                        loadi             (0);
                        if(always())      goto compare_41_false;
compare_41_true:        loadi             (1);
compare_41_false:       if(equals())      goto while_40_end;
                                                            // 		tmp_swap = str[i];
                        load              (2+BP);
                        loadx             ();
                        loadi             (X);
                        store             (6+BP);
                        load              (1+BP);
                        add               (6+BP);
                        loadx             ();
                        load              (X);
                        store             (5+BP);
                                                            // 		str[i] = str[j];
                        load              (2+BP);
                        store             (6+BP);
                        load              (3+BP);
                        loadx             ();
                        loadi             (X);
                        store             (7+BP);
                        load              (1+BP);
                        add               (7+BP);
                        loadx             ();
                        load              (X);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (6+BP);
                        loadi             (X);
                        store             (7+BP);
                        load              (1+BP);
                        add               (7+BP);
                        loadx             ();
                        load              (6+BP);
                        store             (X);
                                                            // 		str[j] = tmp_swap;
                        load              (3+BP);
                        store             (6+BP);
                        load              (5+BP);
                        store             (7+BP);
                        load              (6+BP);
                        loadx             ();
                        load              (7+BP);
                        store             (6+BP);
                        loadi             (X);
                        store             (7+BP);
                        load              (1+BP);
                        add               (7+BP);
                        loadx             ();
                        load              (6+BP);
                        store             (X);
                                                            // 		i = i - 1;
                        load              (2+BP);
                        store             (6+BP);
                        loadi             (1);
                        store             (7+BP);
                        load              (6+BP);
                        subtract          (7+BP);
                        store             (2+BP);
                                                            // 		j = j + 1;
                        load              (3+BP);
                        store             (6+BP);
                        loadi             (1);
                        add               (6+BP);
                        store             (3+BP);
                                                            // 	}
                                                            // }
                        if(always())      goto while_40_test;
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // 
                                                            // 
                                                            // main() {
while_40_end:
int_to_str_end:
return;	}
main
(){
                                                            // 	char str[256];
                                                            // 
                                                            // 	debug(strequals("hello", "world"));
                        loadi             (0);
                        store             (256+BP);
                        loadi             (6);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        strequals();      
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(strequals("", "world"));
                        loadi             (12);
                        store             (256+BP);
                        loadi             (13);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        strequals();      
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(strequals("hello", ""));
                        loadi             (19);
                        store             (256+BP);
                        loadi             (25);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        strequals();      
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(strequals("", ""));
                        loadi             (26);
                        store             (256+BP);
                        loadi             (27);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        strequals();      
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(strequals("hello", "hello1"));
                        loadi             (28);
                        store             (256+BP);
                        loadi             (34);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        strequals();      
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(strequals("hello", "hello"));
                        loadi             (41);
                        store             (256+BP);
                        loadi             (47);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        strequals();      
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	copy(str, "");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (53);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            // 	writeln(str);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	copy(str, "Hello");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (54);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            // 	writeln(str);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	copy(str, "world");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (60);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        copy();           
                        movebp            (-266);
                                                            // 	writeln(str);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 
                                                            // 	str[0] = 0;
                        loadi             (0);
                        store             (256+BP);
                        loadi             (0);
                        store             (257+BP);
                        load              (256+BP);
                        loadx             ();
                        load              (257+BP);
                        store             (0+BP+X);
                                                            // 	append(str, "");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (66);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 	write(str); write("\n");
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                        loadi             (67);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                                                            // 	append(str, "Hello");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (69);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 	write(str); write("\n");
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                        loadi             (75);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                                                            // 	append(str, " ");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (77);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 	write(str); write("\n");
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                        loadi             (79);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                                                            // 	append(str, "world");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (81);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 	write(str); write("\n");
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                        loadi             (87);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                                                            // 
                                                            // 	str[0] = 0;
                        loadi             (0);
                        store             (256+BP);
                        loadi             (0);
                        store             (257+BP);
                        load              (256+BP);
                        loadx             ();
                        load              (257+BP);
                        store             (0+BP+X);
                                                            // 	append_char(str, '!');
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (33);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append_char();    
                        movebp            (-266);
                                                            // 	append(str, "Hello world");
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (89);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append();         
                        movebp            (-266);
                                                            // 	append_char(str, '!');
                        loadi             (0+BP);
                        store             (256+BP);
                        loadi             (33);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        append_char();    
                        movebp            (-266);
                                                            // 	writeln(str); write("\n");
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                        loadi             (101);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        write();          
                        movebp            (-265);
                                                            // 
                                                            // 	debug(contains("", ""));
                        loadi             (103);
                        store             (256+BP);
                        loadi             (104);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("", "abcd"));
                        loadi             (105);
                        store             (256+BP);
                        loadi             (106);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("abcd", ""));
                        loadi             (111);
                        store             (256+BP);
                        loadi             (116);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("a", ""));
                        loadi             (117);
                        store             (256+BP);
                        loadi             (119);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("", "b"));
                        loadi             (120);
                        store             (256+BP);
                        loadi             (121);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("abcdef", "ab"));
                        loadi             (123);
                        store             (256+BP);
                        loadi             (130);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("abcdef", "ef"));
                        loadi             (133);
                        store             (256+BP);
                        loadi             (140);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("abcdef", "cd"));
                        loadi             (143);
                        store             (256+BP);
                        loadi             (150);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("abcdef", "abcx"));
                        loadi             (153);
                        store             (256+BP);
                        loadi             (160);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("abcdef", "efx"));
                        loadi             (165);
                        store             (256+BP);
                        loadi             (172);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("ab", "abcd"));
                        loadi             (176);
                        store             (256+BP);
                        loadi             (179);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("cd", "abcd"));
                        loadi             (184);
                        store             (256+BP);
                        loadi             (187);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains("cd", "cd"));
                        loadi             (192);
                        store             (256+BP);
                        loadi             (195);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains();       
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	writeln("");
                        loadi             (198);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	debug(contains_char("", 0));
                        loadi             (199);
                        store             (256+BP);
                        loadi             (0);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains_char();  
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains_char("", 'a'));
                        loadi             (200);
                        store             (256+BP);
                        loadi             (97);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains_char();  
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains_char("a", 0));
                        loadi             (201);
                        store             (256+BP);
                        loadi             (0);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains_char();  
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains_char("a", 'a'));
                        loadi             (203);
                        store             (256+BP);
                        loadi             (97);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains_char();  
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains_char("abc", 'a'));
                        loadi             (205);
                        store             (256+BP);
                        loadi             (97);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains_char();  
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains_char("abc", 'c'));
                        loadi             (209);
                        store             (256+BP);
                        loadi             (99);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains_char();  
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 	debug(contains_char("abc", 'd'));
                        loadi             (213);
                        store             (256+BP);
                        loadi             (100);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        contains_char();  
                        movebp            (-266);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	writeln("");
                        loadi             (217);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	debug(length(""));
                        loadi             (218);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        length();         
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(length("a"));
                        loadi             (219);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        length();         
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(length("abc\n"));
                        loadi             (221);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        length();         
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	writeln("");
                        loadi             (226);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	debug(str_to_int(""));
                        loadi             (227);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(str_to_int("0"));
                        loadi             (228);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(str_to_int("12345"));
                        loadi             (230);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(str_to_int("012345"));
                        loadi             (236);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(str_to_int("0123450"));
                        loadi             (243);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(str_to_int("2147483647"));
                        loadi             (251);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 	debug(str_to_int("abc"));
                        loadi             (262);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printf            ("%d\n", A);
                                                            // 
                                                            // 	writeln("");
                        loadi             (266);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(100, str); writeln(str);
                        loadi             (100);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(0, str); writeln(str);
                        loadi             (0);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(-10, str); writeln(str);
                        loadi             (10);
                        store             (256+BP);
                        loadi             (0);
                        subtract          (256+BP);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(-0, str); writeln(str);
                        loadi             (0);
                        store             (256+BP);
                        loadi             (0);
                        subtract          (256+BP);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(10, str); writeln(str);
                        loadi             (10);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(9292, str); writeln(str);
                        loadi             (9292);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(131, str); writeln(str);
                        loadi             (131);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // 	int_to_str(2147483647, str); writeln(str);
                        loadi             (2147483647);
                        store             (256+BP);
                        loadi             (0+BP);
                        store             (257+BP);
                        load              (257+BP);
                        store             (267+BP);
                        load              (256+BP);
                        store             (266+BP);
                        movebp            (266);
                        int_to_str();     
                        movebp            (-266);
                        loadi             (0+BP);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        writeln();        
                        movebp            (-265);
                                                            // }
main_end:
return;	}


int global = 1048843;

int BP = 267;

int RAM[1048843] = {
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
0,
0,
'w',
'o',
'r',
'l',
'd',
0,
'h',
'e',
'l',
'l',
'o',
0,
0,
0,
0,
'h',
'e',
'l',
'l',
'o',
0,
'h',
'e',
'l',
'l',
'o',
'1',
0,
'h',
'e',
'l',
'l',
'o',
0,
'h',
'e',
'l',
'l',
'o',
0,
0,
'H',
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
0,
0,
10,
0,
'H',
'e',
'l',
'l',
'o',
0,
10,
0,
' ',
0,
10,
0,
'w',
'o',
'r',
'l',
'd',
0,
10,
0,
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
0,
10,
0,
0,
0,
0,
'a',
'b',
'c',
'd',
0,
'a',
'b',
'c',
'd',
0,
0,
'a',
0,
0,
0,
'b',
0,
'a',
'b',
'c',
'd',
'e',
'f',
0,
'a',
'b',
0,
'a',
'b',
'c',
'd',
'e',
'f',
0,
'e',
'f',
0,
'a',
'b',
'c',
'd',
'e',
'f',
0,
'c',
'd',
0,
'a',
'b',
'c',
'd',
'e',
'f',
0,
'a',
'b',
'c',
'x',
0,
'a',
'b',
'c',
'd',
'e',
'f',
0,
'e',
'f',
'x',
0,
'a',
'b',
0,
'a',
'b',
'c',
'd',
0,
'c',
'd',
0,
'a',
'b',
'c',
'd',
0,
'c',
'd',
0,
'c',
'd',
0,
0,
0,
0,
'a',
0,
'a',
0,
'a',
'b',
'c',
0,
'a',
'b',
'c',
0,
'a',
'b',
'c',
0,
0,
0,
'a',
0,
'a',
'b',
'c',
10,
0,
0,
0,
'0',
0,
'1',
'2',
'3',
'4',
'5',
0,
'0',
'1',
'2',
'3',
'4',
'5',
0,
'0',
'1',
'2',
'3',
'4',
'5',
'0',
0,
'2',
'1',
'4',
'7',
'4',
'8',
'3',
'6',
'4',
'7',
0,
'a',
'b',
'c',
0,
0
};


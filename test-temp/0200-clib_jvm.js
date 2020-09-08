
var A;
var X;
var BP;
var RAM = [];

function loadi       (n) { A = n; }

function load        (n) { A = RAM[n]; }
function store       (n) { RAM[n] = A; }

function add         (n) { A += RAM[n]; }
function subtract    (n) { A -= RAM[n]; }
function multiply    (n) { A *= RAM[n]; }
function divide      (n) { A = (A / RAM[n]) | 0; }

function loadx       ()  { X = A; }
function movebp      (n) { BP += n; }

function less        ()  { return A > 0; }
function greater     ()  { return A < 0; }
function equals      ()  { return A == 0; }
function notequals   ()  { return A != 0; }
function always      ()  { return true; }

var global;

                                                            // 
                                                            // enum { False = 0, True = 1 };
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // write(char str[]) {
function write
(){
                                             write_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	while(str[i] != 0) {
                                             while_0_end: {
while_0_test: while(true) {
                        load              (1+BP);
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
                                             compare_1_false: {
                                             compare_1_true: {
                        if(notequals())   break compare_1_true;
                        loadi             (0);
                        if(always())      break compare_1_false;
} // compare_1_true:
                        loadi             (1);
} // compare_1_false:
                        if(equals())      break while_0_end;
                                                            // 		fputc(str[i], stdout);
                        load              (1+BP);
                        loadx             ();
                        loadi             (X);
                        store             (2+BP);
                        load              (0+BP);
                        add               (2+BP);
                        loadx             ();
                        load              (X);
                        printCharCodeToStdout (A);
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                                                            // 	}
                                                            // }
                        if(always())      continue while_0_test;
                                             break; } // while_0_test:
} // while_0_end:
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // writeln(char str[]) {
} // write_end:
return;	}
function writeln
(){
                                             writeln_end: {
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
                        printCharCodeToStdout (A);
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // strequals(char str1[], char str2[]) {
} // writeln_end:
return;	}
function strequals
(){
                                             strequals_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(str1[i] == str2[i]) {
                                             while_2_end: {
while_2_test: while(true) {
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
                                             compare_3_false: {
                                             compare_3_true: {
                        if(equals())      break compare_3_true;
                        loadi             (0);
                        if(always())      break compare_3_false;
} // compare_3_true:
                        loadi             (1);
} // compare_3_false:
                        if(equals())      break while_2_end;
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
                                             compare_4_false: {
                                             compare_4_true: {
                        if(equals())      break compare_4_true;
                        loadi             (0);
                        if(always())      break compare_4_false;
} // compare_4_true:
                        loadi             (1);
} // compare_4_false:
                                             logical_and_5_true: {
                                             logical_and_5_false: {
                        if(equals())      break logical_and_5_false;
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
                                             compare_6_false: {
                                             compare_6_true: {
                        if(equals())      break compare_6_true;
                        loadi             (0);
                        if(always())      break compare_6_false;
} // compare_6_true:
                        loadi             (1);
} // compare_6_false:
                        if(equals())      break logical_and_5_false;
                        loadi             (1);
                        if(always())      break logical_and_5_true;
} // logical_and_5_false:
                        loadi             (0);
} // logical_and_5_true:
                                             if_7_end: {
                                             if_7_next: {
                        if(equals())      break if_7_next;
                                                            // 			return True;
                        loadi             (1);
                        if(always())      break strequals_end;
} // if_7_next:
} // if_7_end:
                                                            // 		
                                                            // 		if(str1[i] == 0 || str2[i] == 0)
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
                                             compare_8_false: {
                                             compare_8_true: {
                        if(equals())      break compare_8_true;
                        loadi             (0);
                        if(always())      break compare_8_false;
} // compare_8_true:
                        loadi             (1);
} // compare_8_false:
                                             logical_or_9_false: {
                                             logical_or_9_true: {
                        if(notequals())   break logical_or_9_true;
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
                                             compare_10_false: {
                                             compare_10_true: {
                        if(equals())      break compare_10_true;
                        loadi             (0);
                        if(always())      break compare_10_false;
} // compare_10_true:
                        loadi             (1);
} // compare_10_false:
                        if(notequals())   break logical_or_9_true;
                        loadi             (0);
                        if(always())      break logical_or_9_false;
} // logical_or_9_true:
                        loadi             (1);
} // logical_or_9_false:
                                             if_11_end: {
                                             if_11_next: {
                        if(equals())      break if_11_next;
                                                            // 			return False;
                        loadi             (0);
                        if(always())      break strequals_end;
} // if_11_next:
} // if_11_end:
                                                            // 
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      continue while_2_test;
                                             break; } // while_2_test:
} // while_2_end:
                        loadi             (0);
                        if(always())      break strequals_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // copy(char dest[], char src[]) {
} // strequals_end:
return;	}
function copy
(){
                                             copy_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(src[i] != 0) {
                                             while_12_end: {
while_12_test: while(true) {
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
                                             compare_13_false: {
                                             compare_13_true: {
                        if(notequals())   break compare_13_true;
                        loadi             (0);
                        if(always())      break compare_13_false;
} // compare_13_true:
                        loadi             (1);
} // compare_13_false:
                        if(equals())      break while_12_end;
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
                        if(always())      continue while_12_test;
                                             break; } // while_12_test:
} // while_12_end:
                        load              (2+BP);
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
} // copy_end:
return;	}
function append
(){
                                             append_end: {
                                                            // 	int i;
                                                            // 	int j;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(dest[i] != 0) {
                                             while_14_end: {
while_14_test: while(true) {
                        load              (2+BP);
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
                                             compare_15_false: {
                                             compare_15_true: {
                        if(notequals())   break compare_15_true;
                        loadi             (0);
                        if(always())      break compare_15_false;
} // compare_15_true:
                        loadi             (1);
} // compare_15_false:
                        if(equals())      break while_14_end;
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (4+BP);
                        loadi             (1);
                        add               (4+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	j = 0;
                        if(always())      continue while_14_test;
                                             break; } // while_14_test:
} // while_14_end:
                        loadi             (0);
                        store             (3+BP);
                                                            // 	while(src[j] != 0) {
                                             while_16_end: {
while_16_test: while(true) {
                        load              (3+BP);
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
                                             compare_17_false: {
                                             compare_17_true: {
                        if(notequals())   break compare_17_true;
                        loadi             (0);
                        if(always())      break compare_17_false;
} // compare_17_true:
                        loadi             (1);
} // compare_17_false:
                        if(equals())      break while_16_end;
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
                        if(always())      continue while_16_test;
                                             break; } // while_16_test:
} // while_16_end:
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
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // append_char(char dest[], int c) {
} // append_end:
return;	}
function append_char
(){
                                             append_char_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(dest[i] != 0) {
                                             while_18_end: {
while_18_test: while(true) {
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
                                             compare_19_false: {
                                             compare_19_true: {
                        if(notequals())   break compare_19_true;
                        loadi             (0);
                        if(always())      break compare_19_false;
} // compare_19_true:
                        loadi             (1);
} // compare_19_false:
                        if(equals())      break while_18_end;
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	dest[i] = c;
                        if(always())      continue while_18_test;
                                             break; } // while_18_test:
} // while_18_end:
                        load              (2+BP);
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
} // append_char_end:
return;	}
function contains
(){
                                             contains_end: {
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
                                             compare_20_false: {
                                             compare_20_true: {
                        if(equals())      break compare_20_true;
                        loadi             (0);
                        if(always())      break compare_20_false;
} // compare_20_true:
                        loadi             (1);
} // compare_20_false:
                                             if_21_end: {
                                             if_21_next: {
                        if(equals())      break if_21_next;
                                                            // 		return True;
                        loadi             (1);
                        if(always())      break contains_end;
} // if_21_next:
} // if_21_end:
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while (str[i] != 0) {
                                             while_22_end: {
while_22_test: while(true) {
                        load              (2+BP);
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
                                             compare_23_false: {
                                             compare_23_true: {
                        if(notequals())   break compare_23_true;
                        loadi             (0);
                        if(always())      break compare_23_false;
} // compare_23_true:
                        loadi             (1);
} // compare_23_false:
                        if(equals())      break while_22_end;
                                                            // 		j = i;
                        load              (2+BP);
                        store             (3+BP);
                                                            // 		k = 0;
                        loadi             (0);
                        store             (4+BP);
                                                            // 		while(str[j] == substr[k]) {
                                             while_24_end: {
while_24_test: while(true) {
                        load              (3+BP);
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
                                             compare_25_false: {
                                             compare_25_true: {
                        if(equals())      break compare_25_true;
                        loadi             (0);
                        if(always())      break compare_25_false;
} // compare_25_true:
                        loadi             (1);
} // compare_25_false:
                        if(equals())      break while_24_end;
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
                                             compare_26_false: {
                                             compare_26_true: {
                        if(equals())      break compare_26_true;
                        loadi             (0);
                        if(always())      break compare_26_false;
} // compare_26_true:
                        loadi             (1);
} // compare_26_false:
                                             if_27_end: {
                                             if_27_next: {
                        if(equals())      break if_27_next;
                                                            // 				return True;
                        loadi             (1);
                        if(always())      break contains_end;
} // if_27_next:
} // if_27_end:
                                                            // 		}
                                                            // 
                                                            // 		i = i + 1;
                        if(always())      continue while_24_test;
                                             break; } // while_24_test:
} // while_24_end:
                        load              (2+BP);
                        store             (5+BP);
                        loadi             (1);
                        add               (5+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      continue while_22_test;
                                             break; } // while_22_test:
} // while_22_end:
                        loadi             (0);
                        if(always())      break contains_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // contains_char(char str[], int c) {
} // contains_end:
return;	}
function contains_char
(){
                                             contains_char_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while (str[i] != 0) {
                                             while_28_end: {
while_28_test: while(true) {
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
                                             compare_29_false: {
                                             compare_29_true: {
                        if(notequals())   break compare_29_true;
                        loadi             (0);
                        if(always())      break compare_29_false;
} // compare_29_true:
                        loadi             (1);
} // compare_29_false:
                        if(equals())      break while_28_end;
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
                                             compare_30_false: {
                                             compare_30_true: {
                        if(equals())      break compare_30_true;
                        loadi             (0);
                        if(always())      break compare_30_false;
} // compare_30_true:
                        loadi             (1);
} // compare_30_false:
                                             if_31_end: {
                                             if_31_next: {
                        if(equals())      break if_31_next;
                                                            // 			return True;
                        loadi             (1);
                        if(always())      break contains_char_end;
} // if_31_next:
} // if_31_end:
                                                            // 
                                                            // 		i = i + 1;
                        load              (2+BP);
                        store             (3+BP);
                        loadi             (1);
                        add               (3+BP);
                        store             (2+BP);
                                                            // 	}
                                                            // 
                                                            // 	return False;
                        if(always())      continue while_28_test;
                                             break; } // while_28_test:
} // while_28_end:
                        loadi             (0);
                        if(always())      break contains_char_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // length(char str[]) {
} // contains_char_end:
return;	}
function length
(){
                                             length_end: {
                                                            // 	int i;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (1+BP);
                                                            // 	while (str[i] != 0)
                                             while_32_end: {
while_32_test: while(true) {
                        load              (1+BP);
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
                                             compare_33_false: {
                                             compare_33_true: {
                        if(notequals())   break compare_33_true;
                        loadi             (0);
                        if(always())      break compare_33_false;
} // compare_33_true:
                        loadi             (1);
} // compare_33_false:
                        if(equals())      break while_32_end;
                                                            // 		i = i + 1;
                        load              (1+BP);
                        store             (2+BP);
                        loadi             (1);
                        add               (2+BP);
                        store             (1+BP);
                        if(always())      continue while_32_test;
                                             break; } // while_32_test:
} // while_32_end:
                                                            // 
                                                            // 	return i;
                        load              (1+BP);
                        if(always())      break length_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // str_to_int(char str[]) {
} // length_end:
return;	}
function str_to_int
(){
                                             str_to_int_end: {
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
                                             while_34_end: {
while_34_test: while(true) {
                        load              (1+BP);
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
                                             compare_35_false: {
                                             compare_35_true: {
                        if(notequals())   break compare_35_true;
                        loadi             (0);
                        if(always())      break compare_35_false;
} // compare_35_true:
                        loadi             (1);
} // compare_35_false:
                        if(equals())      break while_34_end;
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
                        if(always())      continue while_34_test;
                                             break; } // while_34_test:
} // while_34_end:
                        load              (2+BP);
                        if(always())      break str_to_int_end;
                                                            // }
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // int_to_str(int n, char str[]) {
} // str_to_int_end:
return;	}
function int_to_str
(){
                                             int_to_str_end: {
                                                            // 	int i;
                                                            // 	int j;
                                                            // 	int n_mod_10;
                                                            // 	char tmp_swap;
                                                            // 
                                                            // 	i = 0;
                        loadi             (0);
                        store             (2+BP);
                                                            // 	while(i == 0 || n != 0) {
                                             while_36_end: {
while_36_test: while(true) {
                        load              (2+BP);
                        store             (6+BP);
                        loadi             (0);
                        subtract          (6+BP);
                                             compare_37_false: {
                                             compare_37_true: {
                        if(equals())      break compare_37_true;
                        loadi             (0);
                        if(always())      break compare_37_false;
} // compare_37_true:
                        loadi             (1);
} // compare_37_false:
                                             logical_or_38_false: {
                                             logical_or_38_true: {
                        if(notequals())   break logical_or_38_true;
                        load              (0+BP);
                        store             (6+BP);
                        loadi             (0);
                        subtract          (6+BP);
                                             compare_39_false: {
                                             compare_39_true: {
                        if(notequals())   break compare_39_true;
                        loadi             (0);
                        if(always())      break compare_39_false;
} // compare_39_true:
                        loadi             (1);
} // compare_39_false:
                        if(notequals())   break logical_or_38_true;
                        loadi             (0);
                        if(always())      break logical_or_38_false;
} // logical_or_38_true:
                        loadi             (1);
} // logical_or_38_false:
                        if(equals())      break while_36_end;
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
                        if(always())      continue while_36_test;
                                             break; } // while_36_test:
} // while_36_end:
                        load              (2+BP);
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
                                             while_40_end: {
while_40_test: while(true) {
                        load              (3+BP);
                        store             (6+BP);
                        load              (2+BP);
                        subtract          (6+BP);
                                             compare_41_false: {
                                             compare_41_true: {
                        if(less())        break compare_41_true;
                        loadi             (0);
                        if(always())      break compare_41_false;
} // compare_41_true:
                        loadi             (1);
} // compare_41_false:
                        if(equals())      break while_40_end;
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
                        if(always())      continue while_40_test;
                                             break; } // while_40_test:
} // while_40_end:
                                                            // 
                                                            // // ---------------------------------------------------------------------------
                                                            // 
                                                            // 
                                                            // main() {
} // int_to_str_end:
return;	}
function main
(){
                                             main_end: {
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
                                                            // 	debug(length("a"));
                        loadi             (219);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        length();         
                        movebp            (-265);
                        printIntegerNumber (A);
                                                            // 	debug(length("abc\n"));
                        loadi             (221);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        length();         
                        movebp            (-265);
                        printIntegerNumber (A);
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
                        printIntegerNumber (A);
                                                            // 	debug(str_to_int("0"));
                        loadi             (228);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printIntegerNumber (A);
                                                            // 	debug(str_to_int("12345"));
                        loadi             (230);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printIntegerNumber (A);
                                                            // 	debug(str_to_int("012345"));
                        loadi             (236);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printIntegerNumber (A);
                                                            // 	debug(str_to_int("0123450"));
                        loadi             (243);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printIntegerNumber (A);
                                                            // 	debug(str_to_int("2147483647"));
                        loadi             (251);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printIntegerNumber (A);
                                                            // 	debug(str_to_int("abc"));
                        loadi             (262);
                        store             (256+BP);
                        load              (256+BP);
                        store             (265+BP);
                        movebp            (265);
                        str_to_int();     
                        movebp            (-265);
                        printIntegerNumber (A);
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
} // main_end:
return;	}


function init_memory() {
global = 1048843;

BP = 267;

RAM = [
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
"w".charCodeAt(0),
"o".charCodeAt(0),
"r".charCodeAt(0),
"l".charCodeAt(0),
"d".charCodeAt(0),
0,
0,
"w".charCodeAt(0),
"o".charCodeAt(0),
"r".charCodeAt(0),
"l".charCodeAt(0),
"d".charCodeAt(0),
0,
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
0,
0,
0,
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
"1".charCodeAt(0),
0,
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
"h".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
0,
"H".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
"w".charCodeAt(0),
"o".charCodeAt(0),
"r".charCodeAt(0),
"l".charCodeAt(0),
"d".charCodeAt(0),
0,
0,
10,
0,
"H".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
0,
10,
0,
" ".charCodeAt(0),
0,
10,
0,
"w".charCodeAt(0),
"o".charCodeAt(0),
"r".charCodeAt(0),
"l".charCodeAt(0),
"d".charCodeAt(0),
0,
10,
0,
"H".charCodeAt(0),
"e".charCodeAt(0),
"l".charCodeAt(0),
"l".charCodeAt(0),
"o".charCodeAt(0),
" ".charCodeAt(0),
"w".charCodeAt(0),
"o".charCodeAt(0),
"r".charCodeAt(0),
"l".charCodeAt(0),
"d".charCodeAt(0),
0,
10,
0,
0,
0,
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
0,
"a".charCodeAt(0),
0,
0,
0,
"b".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
"e".charCodeAt(0),
"f".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
"e".charCodeAt(0),
"f".charCodeAt(0),
0,
"e".charCodeAt(0),
"f".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
"e".charCodeAt(0),
"f".charCodeAt(0),
0,
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
"e".charCodeAt(0),
"f".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"x".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
"e".charCodeAt(0),
"f".charCodeAt(0),
0,
"e".charCodeAt(0),
"f".charCodeAt(0),
"x".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
"c".charCodeAt(0),
"d".charCodeAt(0),
0,
0,
0,
0,
"a".charCodeAt(0),
0,
"a".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
0,
0,
0,
"a".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
10,
0,
0,
0,
"0".charCodeAt(0),
0,
"1".charCodeAt(0),
"2".charCodeAt(0),
"3".charCodeAt(0),
"4".charCodeAt(0),
"5".charCodeAt(0),
0,
"0".charCodeAt(0),
"1".charCodeAt(0),
"2".charCodeAt(0),
"3".charCodeAt(0),
"4".charCodeAt(0),
"5".charCodeAt(0),
0,
"0".charCodeAt(0),
"1".charCodeAt(0),
"2".charCodeAt(0),
"3".charCodeAt(0),
"4".charCodeAt(0),
"5".charCodeAt(0),
"0".charCodeAt(0),
0,
"2".charCodeAt(0),
"1".charCodeAt(0),
"4".charCodeAt(0),
"7".charCodeAt(0),
"4".charCodeAt(0),
"8".charCodeAt(0),
"3".charCodeAt(0),
"6".charCodeAt(0),
"4".charCodeAt(0),
"7".charCodeAt(0),
0,
"a".charCodeAt(0),
"b".charCodeAt(0),
"c".charCodeAt(0),
0,
0
];

for (i = 267; i < 1048843; i ++) {
RAM[i] = 0;
}
}


.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # 
                                                            # enum { False = 0, True = 1 };
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # write(char str[]) {
write:                  enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(str[i] != 0) {
while_0_test:           movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        jne               compare_1_true
                        movl              $0, %eax
                        jmp               compare_1_false
compare_1_true:         movl              $1, %eax
compare_1_false:        cmpl              $0, %eax
                        jz                while_0_end
                                                            # 		fputc(str[i], stdout);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        pushl             %eax
                        movl              $4, %eax
                        movl              $1, %ebx
                        movl              %esp, %ecx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # }
                        jmp               while_0_test
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # writeln(char str[]) {
while_0_end:
write_end:
                        leave
                        ret
writeln:                enter             $32, $0
                                                            # 	write(str);
                        movl              8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                        movl              -4(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                                                            # 	fputc('\n', stdout);
                        movl              $10, %eax
                        pushl             %eax
                        movl              $4, %eax
                        movl              $1, %ebx
                        movl              %esp, %ecx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # strequals(char str1[], char str2[]) {
writeln_end:
                        leave
                        ret
strequals:              enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(str1[i] == str2[i]) {
while_2_test:           movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              12(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        subl              -8(%ebp), %eax
                        je                compare_3_true
                        movl              $0, %eax
                        jmp               compare_3_false
compare_3_true:         movl              $1, %eax
compare_3_false:        cmpl              $0, %eax
                        jz                while_2_end
                                                            # 		if(str1[i] == 0 && str2[i] == 0)
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        je                compare_4_true
                        movl              $0, %eax
                        jmp               compare_4_false
compare_4_true:         movl              $1, %eax
compare_4_false:        cmpl              $0, %eax
                        jz                logical_and_5_false
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              12(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        je                compare_6_true
                        movl              $0, %eax
                        jmp               compare_6_false
compare_6_true:         movl              $1, %eax
compare_6_false:        cmpl              $0, %eax
                        jz                logical_and_5_false
                        movl              $1, %eax
                        jmp               logical_and_5_true
logical_and_5_false:    movl              $0, %eax
logical_and_5_true:     cmpl              $0, %eax
                        jz                if_7_next
                                                            # 			return True;
                        movl              $1, %eax
                        jmp               strequals_end
if_7_next:
                                                            # 		
                                                            # 		if(str1[i] == 0 || str2[i] == 0)
if_7_end:               movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        je                compare_8_true
                        movl              $0, %eax
                        jmp               compare_8_false
compare_8_true:         movl              $1, %eax
compare_8_false:        cmpl              $0, %eax
                        jnz               logical_or_9_true
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              12(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        je                compare_10_true
                        movl              $0, %eax
                        jmp               compare_10_false
compare_10_true:        movl              $1, %eax
compare_10_false:       cmpl              $0, %eax
                        jnz               logical_or_9_true
                        movl              $0, %eax
                        jmp               logical_or_9_false
logical_or_9_true:      movl              $1, %eax
logical_or_9_false:     cmpl              $0, %eax
                        jz                if_11_next
                                                            # 			return False;
                        movl              $0, %eax
                        jmp               strequals_end
if_11_next:
                                                            # 
                                                            # 		i = i + 1;
if_11_end:              movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	return False;
                        jmp               while_2_test
while_2_end:            movl              $0, %eax
                        jmp               strequals_end
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # copy(char dest[], char src[]) {
strequals_end:
                        leave
                        ret
copy:                   enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(src[i] != 0) {
while_12_test:          movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              12(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        jne               compare_13_true
                        movl              $0, %eax
                        jmp               compare_13_false
compare_13_true:        movl              $1, %eax
compare_13_false:       cmpl              $0, %eax
                        jz                while_12_end
                                                            # 		dest[i] = src[i];
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              12(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -12(%ebp)
                        movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -12(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              8(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -8(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # 
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	dest[i] = 0;
                        jmp               while_12_test
while_12_end:           movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        movl              %eax, -12(%ebp)
                        movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -12(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              8(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -8(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # append(char dest[], char src[]) {
copy_end:
                        leave
                        ret
append:                 enter             $40, $0
                                                            # 	int i;
                                                            # 	int j;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(dest[i] != 0) {
while_14_test:          movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              8(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -12(%ebp)
                        movl              $0, %eax
                        subl              -12(%ebp), %eax
                        jne               compare_15_true
                        movl              $0, %eax
                        jmp               compare_15_false
compare_15_true:        movl              $1, %eax
compare_15_false:       cmpl              $0, %eax
                        jz                while_14_end
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $1, %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	j = 0;
                        jmp               while_14_test
while_14_end:           movl              $0, %eax
                        movl              %eax, -8(%ebp)
                                                            # 	while(src[j] != 0) {
while_16_test:          movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              12(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -12(%ebp)
                        movl              $0, %eax
                        subl              -12(%ebp), %eax
                        jne               compare_17_true
                        movl              $0, %eax
                        jmp               compare_17_false
compare_17_true:        movl              $1, %eax
compare_17_false:       cmpl              $0, %eax
                        jz                while_16_end
                                                            # 		dest[i] = src[j];
                        movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              12(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -16(%ebp)
                        movl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -16(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              8(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -12(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # 
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $1, %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 		j = j + 1;
                        movl              -8(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $1, %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, -8(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	dest[i] = 0;
                        jmp               while_16_test
while_16_end:           movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $0, %eax
                        movl              %eax, -16(%ebp)
                        movl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -16(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              8(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -12(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # append_char(char dest[], int c) {
append_end:
                        leave
                        ret
append_char:            enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(dest[i] != 0) {
while_18_test:          movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        jne               compare_19_true
                        movl              $0, %eax
                        jmp               compare_19_false
compare_19_true:        movl              $1, %eax
compare_19_false:       cmpl              $0, %eax
                        jz                while_18_end
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	dest[i] = c;
                        jmp               while_18_test
while_18_end:           movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              12(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -12(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              8(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -8(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # 	dest[i + 1] = 0;
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        movl              %eax, -12(%ebp)
                        movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -12(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              8(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -8(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # contains(char str[], char substr[]) {
append_char_end:
                        leave
                        ret
contains:               enter             $44, $0
                                                            # 	int i;
                                                            # 	int j;
                                                            # 	int k;
                                                            # 
                                                            # 	if(substr[0] == 0)
                        movl              $0, %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              12(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -16(%ebp)
                        movl              $0, %eax
                        subl              -16(%ebp), %eax
                        je                compare_20_true
                        movl              $0, %eax
                        jmp               compare_20_false
compare_20_true:        movl              $1, %eax
compare_20_false:       cmpl              $0, %eax
                        jz                if_21_next
                                                            # 		return True;
                        movl              $1, %eax
                        jmp               contains_end
if_21_next:
                                                            # 
                                                            # 	i = 0;
if_21_end:              movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while (str[i] != 0) {
while_22_test:          movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              8(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -16(%ebp)
                        movl              $0, %eax
                        subl              -16(%ebp), %eax
                        jne               compare_23_true
                        movl              $0, %eax
                        jmp               compare_23_false
compare_23_true:        movl              $1, %eax
compare_23_false:       cmpl              $0, %eax
                        jz                while_22_end
                                                            # 		j = i;
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                                                            # 		k = 0;
                        movl              $0, %eax
                        movl              %eax, -12(%ebp)
                                                            # 		while(str[j] == substr[k]) {
while_24_test:          movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              8(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -16(%ebp)
                        movl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -20(%ebp)
                        movl              12(%ebp), %eax
                        addl              -20(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        subl              -16(%ebp), %eax
                        je                compare_25_true
                        movl              $0, %eax
                        jmp               compare_25_false
compare_25_true:        movl              $1, %eax
compare_25_false:       cmpl              $0, %eax
                        jz                while_24_end
                                                            # 			j = j + 1;
                        movl              -8(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $1, %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, -8(%ebp)
                                                            # 			k = k + 1;
                        movl              -12(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $1, %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, -12(%ebp)
                                                            # 
                                                            # 			if(substr[k] == 0)
                        movl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              12(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -16(%ebp)
                        movl              $0, %eax
                        subl              -16(%ebp), %eax
                        je                compare_26_true
                        movl              $0, %eax
                        jmp               compare_26_false
compare_26_true:        movl              $1, %eax
compare_26_false:       cmpl              $0, %eax
                        jz                if_27_next
                                                            # 				return True;
                        movl              $1, %eax
                        jmp               contains_end
if_27_next:
                                                            # 		}
                                                            # 
                                                            # 		i = i + 1;
if_27_end:              jmp               while_24_test
while_24_end:           movl              -4(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $1, %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	return False;
                        jmp               while_22_test
while_22_end:           movl              $0, %eax
                        jmp               contains_end
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # contains_char(char str[], int c) {
contains_end:
                        leave
                        ret
contains_char:          enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while (str[i] != 0) {
while_28_test:          movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        jne               compare_29_true
                        movl              $0, %eax
                        jmp               compare_29_false
compare_29_true:        movl              $1, %eax
compare_29_false:       cmpl              $0, %eax
                        jz                while_28_end
                                                            # 		if (str[i] == c)
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              12(%ebp), %eax
                        subl              -8(%ebp), %eax
                        je                compare_30_true
                        movl              $0, %eax
                        jmp               compare_30_false
compare_30_true:        movl              $1, %eax
compare_30_false:       cmpl              $0, %eax
                        jz                if_31_next
                                                            # 			return True;
                        movl              $1, %eax
                        jmp               contains_char_end
if_31_next:
                                                            # 
                                                            # 		i = i + 1;
if_31_end:              movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	return False;
                        jmp               while_28_test
while_28_end:           movl              $0, %eax
                        jmp               contains_char_end
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # length(char str[]) {
contains_char_end:
                        leave
                        ret
length:                 enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while (str[i] != 0)
while_32_test:          movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        jne               compare_33_true
                        movl              $0, %eax
                        jmp               compare_33_false
compare_33_true:        movl              $1, %eax
compare_33_false:       cmpl              $0, %eax
                        jz                while_32_end
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                        jmp               while_32_test
                                                            # 
                                                            # 	return i;
while_32_end:           movl              -4(%ebp), %eax
                        jmp               length_end
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # str_to_int(char str[]) {
length_end:
                        leave
                        ret
str_to_int:             enter             $40, $0
                                                            # 	int i;
                                                            # 	int n;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	n = 0;
                        movl              $0, %eax
                        movl              %eax, -8(%ebp)
                                                            # 	while (str[i] != 0) {
while_34_test:          movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -12(%ebp)
                        movl              8(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -12(%ebp)
                        movl              $0, %eax
                        subl              -12(%ebp), %eax
                        jne               compare_35_true
                        movl              $0, %eax
                        jmp               compare_35_false
compare_35_true:        movl              $1, %eax
compare_35_false:       cmpl              $0, %eax
                        jz                while_34_end
                                                            # 		n = n * 10 + (str[i] - '0');
                        movl              -8(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $10, %eax
                        imull             -12(%ebp)
                        movl              %eax, -12(%ebp)
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -16(%ebp)
                        movl              8(%ebp), %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -16(%ebp)
                        movl              $48, %eax
                        movl              %eax, -20(%ebp)
                        movl              -16(%ebp), %eax
                        subl              -20(%ebp), %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, -8(%ebp)
                                                            # 
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $1, %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	return n;
                        jmp               while_34_test
while_34_end:           movl              -8(%ebp), %eax
                        jmp               str_to_int_end
                                                            # }
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # int_to_str(int n, char str[]) {
str_to_int_end:
                        leave
                        ret
int_to_str:             enter             $48, $0
                                                            # 	int i;
                                                            # 	int j;
                                                            # 	int n_mod_10;
                                                            # 	char tmp_swap;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(i == 0 || n != 0) {
while_36_test:          movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $0, %eax
                        subl              -20(%ebp), %eax
                        je                compare_37_true
                        movl              $0, %eax
                        jmp               compare_37_false
compare_37_true:        movl              $1, %eax
compare_37_false:       cmpl              $0, %eax
                        jnz               logical_or_38_true
                        movl              8(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $0, %eax
                        subl              -20(%ebp), %eax
                        jne               compare_39_true
                        movl              $0, %eax
                        jmp               compare_39_false
compare_39_true:        movl              $1, %eax
compare_39_false:       cmpl              $0, %eax
                        jnz               logical_or_38_true
                        movl              $0, %eax
                        jmp               logical_or_38_false
logical_or_38_true:     movl              $1, %eax
logical_or_38_false:    cmpl              $0, %eax
                        jz                while_36_end
                                                            # 		n_mod_10 = n - (10 * ( n / 10));
                        movl              8(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $10, %eax
                        movl              %eax, -24(%ebp)
                        movl              8(%ebp), %eax
                        movl              %eax, -28(%ebp)
                        movl              $10, %eax
                        movl              %eax, -32(%ebp)
                        movl              -28(%ebp), %eax
                        cdq
                        idivl             -32(%ebp)
                        imull             -24(%ebp)
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        subl              -24(%ebp), %eax
                        movl              %eax, -12(%ebp)
                                                            # 		str[i] = '0' + n_mod_10;
                        movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $48, %eax
                        movl              %eax, -24(%ebp)
                        movl              -12(%ebp), %eax
                        addl              -24(%ebp), %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -24(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -24(%ebp)
                        movl              12(%ebp), %eax
                        addl              -24(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -20(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # 		n = n / 10;
                        movl              8(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $10, %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        cdq
                        idivl             -24(%ebp)
                        movl              %eax, 8(%ebp)
                                                            # 
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $1, %eax
                        addl              -20(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	str[i] = 0;
                        jmp               while_36_test
while_36_end:           movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $0, %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -24(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -24(%ebp)
                        movl              12(%ebp), %eax
                        addl              -24(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -20(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # 
                                                            # 	i = i - 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $1, %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        subl              -24(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	j = 0;
                        movl              $0, %eax
                        movl              %eax, -8(%ebp)
                                                            # 	while(j < i) {
while_40_test:          movl              -8(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              -4(%ebp), %eax
                        subl              -20(%ebp), %eax
                        jg                compare_41_true
                        movl              $0, %eax
                        jmp               compare_41_false
compare_41_true:        movl              $1, %eax
compare_41_false:       cmpl              $0, %eax
                        jz                while_40_end
                                                            # 		tmp_swap = str[i];
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -20(%ebp)
                        movl              12(%ebp), %eax
                        addl              -20(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -16(%ebp)
                                                            # 		str[i] = str[j];
                        movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -24(%ebp)
                        movl              12(%ebp), %eax
                        addl              -24(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -24(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -24(%ebp)
                        movl              12(%ebp), %eax
                        addl              -24(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -20(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # 		str[j] = tmp_swap;
                        movl              -8(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              -16(%ebp), %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -24(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        lea               (,%ebx,4), %eax
                        movl              %eax, -24(%ebp)
                        movl              12(%ebp), %eax
                        addl              -24(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -20(%ebp), %eax
                        movl              %eax, (%ebx)
                                                            # 		i = i - 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $1, %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        subl              -24(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 		j = j + 1;
                        movl              -8(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $1, %eax
                        addl              -20(%ebp), %eax
                        movl              %eax, -8(%ebp)
                                                            # 	}
                                                            # }
                        jmp               while_40_test
                                                            # 
                                                            # // ---------------------------------------------------------------------------
                                                            # 
                                                            # 
                                                            # main() {
while_40_end:
int_to_str_end:
                        leave
                        ret
main:                   enter             $1056, $0
                                                            # 	char str[256];
                                                            # 
                                                            # 	debug(strequals("hello", "world"));
                        lea               4+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               28+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              strequals
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_42_end
                        neg               %eax
debug_neg_if_42_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_43_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_43_end
                        jmp               debug_to_str_43_begin
debug_to_str_43_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_44_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_44_end:
debug_print_45_begin:   cmpl              $0, %esi
                        jz                debug_print_45_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_45_begin
                                                            # 	debug(strequals("", "world"));
debug_print_45_end:     lea               52+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               56+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              strequals
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_46_end
                        neg               %eax
debug_neg_if_46_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_47_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_47_end
                        jmp               debug_to_str_47_begin
debug_to_str_47_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_48_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_48_end:
debug_print_49_begin:   cmpl              $0, %esi
                        jz                debug_print_49_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_49_begin
                                                            # 	debug(strequals("hello", ""));
debug_print_49_end:     lea               80+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               104+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              strequals
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_50_end
                        neg               %eax
debug_neg_if_50_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_51_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_51_end
                        jmp               debug_to_str_51_begin
debug_to_str_51_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_52_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_52_end:
debug_print_53_begin:   cmpl              $0, %esi
                        jz                debug_print_53_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_53_begin
                                                            # 	debug(strequals("", ""));
debug_print_53_end:     lea               108+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               112+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              strequals
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_54_end
                        neg               %eax
debug_neg_if_54_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_55_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_55_end
                        jmp               debug_to_str_55_begin
debug_to_str_55_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_56_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_56_end:
debug_print_57_begin:   cmpl              $0, %esi
                        jz                debug_print_57_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_57_begin
                                                            # 	debug(strequals("hello", "hello1"));
debug_print_57_end:     lea               116+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               140+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              strequals
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_58_end
                        neg               %eax
debug_neg_if_58_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_59_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_59_end
                        jmp               debug_to_str_59_begin
debug_to_str_59_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_60_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_60_end:
debug_print_61_begin:   cmpl              $0, %esi
                        jz                debug_print_61_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_61_begin
                                                            # 	debug(strequals("hello", "hello"));
debug_print_61_end:     lea               168+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               192+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              strequals
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_62_end
                        neg               %eax
debug_neg_if_62_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_63_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_63_end
                        jmp               debug_to_str_63_begin
debug_to_str_63_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_64_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_64_end:
debug_print_65_begin:   cmpl              $0, %esi
                        jz                debug_print_65_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_65_begin
                                                            # 
                                                            # 	copy(str, "");
debug_print_65_end:     lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               216+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              copy
                        addl              $8, %esp
                                                            # 	writeln(str);
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	copy(str, "Hello");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               220+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              copy
                        addl              $8, %esp
                                                            # 	writeln(str);
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	copy(str, "world");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               244+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              copy
                        addl              $8, %esp
                                                            # 	writeln(str);
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 
                                                            # 	str[0] = 0;
                        movl              $0, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $0, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1028(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -1032(%ebp), %eax
                        movl              %eax, -1024(%ebp,%ebx,4)
                                                            # 	append(str, "");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               268+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              append
                        addl              $8, %esp
                                                            # 	write(str); write("\n");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                        lea               272+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                                                            # 	append(str, "Hello");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               280+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              append
                        addl              $8, %esp
                                                            # 	write(str); write("\n");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                        lea               304+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                                                            # 	append(str, " ");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               312+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              append
                        addl              $8, %esp
                                                            # 	write(str); write("\n");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                        lea               320+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                                                            # 	append(str, "world");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               328+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              append
                        addl              $8, %esp
                                                            # 	write(str); write("\n");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                        lea               352+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                                                            # 
                                                            # 	str[0] = 0;
                        movl              $0, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $0, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1028(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -1032(%ebp), %eax
                        movl              %eax, -1024(%ebp,%ebx,4)
                                                            # 	append_char(str, '!');
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              $33, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              append_char
                        addl              $8, %esp
                                                            # 	append(str, "Hello world");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               360+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              append
                        addl              $8, %esp
                                                            # 	append_char(str, '!');
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              $33, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              append_char
                        addl              $8, %esp
                                                            # 	writeln(str); write("\n");
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                        lea               408+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                                                            # 
                                                            # 	debug(contains("", ""));
                        lea               416+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               420+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_66_end
                        neg               %eax
debug_neg_if_66_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_67_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_67_end
                        jmp               debug_to_str_67_begin
debug_to_str_67_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_68_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_68_end:
debug_print_69_begin:   cmpl              $0, %esi
                        jz                debug_print_69_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_69_begin
                                                            # 	debug(contains("", "abcd"));
debug_print_69_end:     lea               424+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               428+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_70_end
                        neg               %eax
debug_neg_if_70_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_71_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_71_end
                        jmp               debug_to_str_71_begin
debug_to_str_71_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_72_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_72_end:
debug_print_73_begin:   cmpl              $0, %esi
                        jz                debug_print_73_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_73_begin
                                                            # 	debug(contains("abcd", ""));
debug_print_73_end:     lea               448+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               468+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_74_end
                        neg               %eax
debug_neg_if_74_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_75_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_75_end
                        jmp               debug_to_str_75_begin
debug_to_str_75_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_76_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_76_end:
debug_print_77_begin:   cmpl              $0, %esi
                        jz                debug_print_77_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_77_begin
                                                            # 	debug(contains("a", ""));
debug_print_77_end:     lea               472+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               480+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_78_end
                        neg               %eax
debug_neg_if_78_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_79_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_79_end
                        jmp               debug_to_str_79_begin
debug_to_str_79_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_80_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_80_end:
debug_print_81_begin:   cmpl              $0, %esi
                        jz                debug_print_81_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_81_begin
                                                            # 	debug(contains("", "b"));
debug_print_81_end:     lea               484+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               488+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_82_end
                        neg               %eax
debug_neg_if_82_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_83_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_83_end
                        jmp               debug_to_str_83_begin
debug_to_str_83_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_84_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_84_end:
debug_print_85_begin:   cmpl              $0, %esi
                        jz                debug_print_85_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_85_begin
                                                            # 	debug(contains("abcdef", "ab"));
debug_print_85_end:     lea               496+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               524+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_86_end
                        neg               %eax
debug_neg_if_86_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_87_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_87_end
                        jmp               debug_to_str_87_begin
debug_to_str_87_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_88_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_88_end:
debug_print_89_begin:   cmpl              $0, %esi
                        jz                debug_print_89_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_89_begin
                                                            # 	debug(contains("abcdef", "ef"));
debug_print_89_end:     lea               536+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               564+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_90_end
                        neg               %eax
debug_neg_if_90_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_91_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_91_end
                        jmp               debug_to_str_91_begin
debug_to_str_91_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_92_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_92_end:
debug_print_93_begin:   cmpl              $0, %esi
                        jz                debug_print_93_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_93_begin
                                                            # 	debug(contains("abcdef", "cd"));
debug_print_93_end:     lea               576+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               604+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_94_end
                        neg               %eax
debug_neg_if_94_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_95_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_95_end
                        jmp               debug_to_str_95_begin
debug_to_str_95_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_96_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_96_end:
debug_print_97_begin:   cmpl              $0, %esi
                        jz                debug_print_97_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_97_begin
                                                            # 	debug(contains("abcdef", "abcx"));
debug_print_97_end:     lea               616+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               644+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_98_end
                        neg               %eax
debug_neg_if_98_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_99_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_99_end
                        jmp               debug_to_str_99_begin
debug_to_str_99_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_100_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_100_end:
debug_print_101_begin:  cmpl              $0, %esi
                        jz                debug_print_101_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_101_begin
                                                            # 	debug(contains("abcdef", "efx"));
debug_print_101_end:    lea               664+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               692+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_102_end
                        neg               %eax
debug_neg_if_102_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_103_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_103_end
                        jmp               debug_to_str_103_begin
debug_to_str_103_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_104_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_104_end:
debug_print_105_begin:  cmpl              $0, %esi
                        jz                debug_print_105_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_105_begin
                                                            # 	debug(contains("ab", "abcd"));
debug_print_105_end:    lea               708+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               720+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_106_end
                        neg               %eax
debug_neg_if_106_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_107_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_107_end
                        jmp               debug_to_str_107_begin
debug_to_str_107_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_108_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_108_end:
debug_print_109_begin:  cmpl              $0, %esi
                        jz                debug_print_109_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_109_begin
                                                            # 	debug(contains("cd", "abcd"));
debug_print_109_end:    lea               740+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               752+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_110_end
                        neg               %eax
debug_neg_if_110_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_111_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_111_end
                        jmp               debug_to_str_111_begin
debug_to_str_111_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_112_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_112_end:
debug_print_113_begin:  cmpl              $0, %esi
                        jz                debug_print_113_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_113_begin
                                                            # 	debug(contains("cd", "cd"));
debug_print_113_end:    lea               772+string, %eax
                        movl              %eax, -1028(%ebp)
                        lea               784+string, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_114_end
                        neg               %eax
debug_neg_if_114_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_115_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_115_end
                        jmp               debug_to_str_115_begin
debug_to_str_115_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_116_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_116_end:
debug_print_117_begin:  cmpl              $0, %esi
                        jz                debug_print_117_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_117_begin
                                                            # 
                                                            # 	writeln("");
debug_print_117_end:    lea               796+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	debug(contains_char("", 0));
                        lea               800+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $0, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains_char
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_118_end
                        neg               %eax
debug_neg_if_118_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_119_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_119_end
                        jmp               debug_to_str_119_begin
debug_to_str_119_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_120_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_120_end:
debug_print_121_begin:  cmpl              $0, %esi
                        jz                debug_print_121_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_121_begin
                                                            # 	debug(contains_char("", 'a'));
debug_print_121_end:    lea               804+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $97, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains_char
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_122_end
                        neg               %eax
debug_neg_if_122_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_123_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_123_end
                        jmp               debug_to_str_123_begin
debug_to_str_123_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_124_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_124_end:
debug_print_125_begin:  cmpl              $0, %esi
                        jz                debug_print_125_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_125_begin
                                                            # 	debug(contains_char("a", 0));
debug_print_125_end:    lea               808+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $0, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains_char
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_126_end
                        neg               %eax
debug_neg_if_126_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_127_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_127_end
                        jmp               debug_to_str_127_begin
debug_to_str_127_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_128_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_128_end:
debug_print_129_begin:  cmpl              $0, %esi
                        jz                debug_print_129_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_129_begin
                                                            # 	debug(contains_char("a", 'a'));
debug_print_129_end:    lea               816+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $97, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains_char
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_130_end
                        neg               %eax
debug_neg_if_130_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_131_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_131_end
                        jmp               debug_to_str_131_begin
debug_to_str_131_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_132_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_132_end:
debug_print_133_begin:  cmpl              $0, %esi
                        jz                debug_print_133_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_133_begin
                                                            # 	debug(contains_char("abc", 'a'));
debug_print_133_end:    lea               824+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $97, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains_char
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_134_end
                        neg               %eax
debug_neg_if_134_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_135_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_135_end
                        jmp               debug_to_str_135_begin
debug_to_str_135_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_136_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_136_end:
debug_print_137_begin:  cmpl              $0, %esi
                        jz                debug_print_137_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_137_begin
                                                            # 	debug(contains_char("abc", 'c'));
debug_print_137_end:    lea               840+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $99, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains_char
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_138_end
                        neg               %eax
debug_neg_if_138_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_139_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_139_end
                        jmp               debug_to_str_139_begin
debug_to_str_139_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_140_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_140_end:
debug_print_141_begin:  cmpl              $0, %esi
                        jz                debug_print_141_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_141_begin
                                                            # 	debug(contains_char("abc", 'd'));
debug_print_141_end:    lea               856+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $100, %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              contains_char
                        addl              $8, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_142_end
                        neg               %eax
debug_neg_if_142_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_143_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_143_end
                        jmp               debug_to_str_143_begin
debug_to_str_143_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_144_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_144_end:
debug_print_145_begin:  cmpl              $0, %esi
                        jz                debug_print_145_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_145_begin
                                                            # 
                                                            # 	writeln("");
debug_print_145_end:    lea               872+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	debug(length(""));
                        lea               876+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              length
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_146_end
                        neg               %eax
debug_neg_if_146_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_147_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_147_end
                        jmp               debug_to_str_147_begin
debug_to_str_147_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_148_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_148_end:
debug_print_149_begin:  cmpl              $0, %esi
                        jz                debug_print_149_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_149_begin
                                                            # 	debug(length("a"));
debug_print_149_end:    lea               880+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              length
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_150_end
                        neg               %eax
debug_neg_if_150_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_151_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_151_end
                        jmp               debug_to_str_151_begin
debug_to_str_151_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_152_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_152_end:
debug_print_153_begin:  cmpl              $0, %esi
                        jz                debug_print_153_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_153_begin
                                                            # 	debug(length("abc\n"));
debug_print_153_end:    lea               888+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              length
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_154_end
                        neg               %eax
debug_neg_if_154_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_155_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_155_end
                        jmp               debug_to_str_155_begin
debug_to_str_155_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_156_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_156_end:
debug_print_157_begin:  cmpl              $0, %esi
                        jz                debug_print_157_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_157_begin
                                                            # 
                                                            # 	writeln("");
debug_print_157_end:    lea               908+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	debug(str_to_int(""));
                        lea               912+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              str_to_int
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_158_end
                        neg               %eax
debug_neg_if_158_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_159_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_159_end
                        jmp               debug_to_str_159_begin
debug_to_str_159_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_160_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_160_end:
debug_print_161_begin:  cmpl              $0, %esi
                        jz                debug_print_161_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_161_begin
                                                            # 	debug(str_to_int("0"));
debug_print_161_end:    lea               916+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              str_to_int
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_162_end
                        neg               %eax
debug_neg_if_162_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_163_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_163_end
                        jmp               debug_to_str_163_begin
debug_to_str_163_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_164_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_164_end:
debug_print_165_begin:  cmpl              $0, %esi
                        jz                debug_print_165_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_165_begin
                                                            # 	debug(str_to_int("12345"));
debug_print_165_end:    lea               924+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              str_to_int
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_166_end
                        neg               %eax
debug_neg_if_166_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_167_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_167_end
                        jmp               debug_to_str_167_begin
debug_to_str_167_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_168_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_168_end:
debug_print_169_begin:  cmpl              $0, %esi
                        jz                debug_print_169_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_169_begin
                                                            # 	debug(str_to_int("012345"));
debug_print_169_end:    lea               948+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              str_to_int
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_170_end
                        neg               %eax
debug_neg_if_170_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_171_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_171_end
                        jmp               debug_to_str_171_begin
debug_to_str_171_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_172_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_172_end:
debug_print_173_begin:  cmpl              $0, %esi
                        jz                debug_print_173_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_173_begin
                                                            # 	debug(str_to_int("0123450"));
debug_print_173_end:    lea               976+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              str_to_int
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_174_end
                        neg               %eax
debug_neg_if_174_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_175_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_175_end
                        jmp               debug_to_str_175_begin
debug_to_str_175_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_176_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_176_end:
debug_print_177_begin:  cmpl              $0, %esi
                        jz                debug_print_177_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_177_begin
                                                            # 	debug(str_to_int("2147483647"));
debug_print_177_end:    lea               1008+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              str_to_int
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_178_end
                        neg               %eax
debug_neg_if_178_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_179_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_179_end
                        jmp               debug_to_str_179_begin
debug_to_str_179_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_180_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_180_end:
debug_print_181_begin:  cmpl              $0, %esi
                        jz                debug_print_181_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_181_begin
                                                            # 	debug(str_to_int("abc"));
debug_print_181_end:    lea               1052+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              str_to_int
                        addl              $4, %esp
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_182_end
                        neg               %eax
debug_neg_if_182_end:   pushl             $'\n
                        movl              $1, %esi
debug_to_str_183_begin: movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_183_end
                        jmp               debug_to_str_183_begin
debug_to_str_183_end:   cmpl              $0, %ecx
                        jge               debug_sign_if_184_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_184_end:
debug_print_185_begin:  cmpl              $0, %esi
                        jz                debug_print_185_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_185_begin
                                                            # 
                                                            # 	writeln("");
debug_print_185_end:    lea               1068+string, %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(100, str); writeln(str);
                        movl              $100, %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(0, str); writeln(str);
                        movl              $0, %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(-10, str); writeln(str);
                        movl              $10, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $0, %eax
                        subl              -1028(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(-0, str); writeln(str);
                        movl              $0, %eax
                        movl              %eax, -1028(%ebp)
                        movl              $0, %eax
                        subl              -1028(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(10, str); writeln(str);
                        movl              $10, %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(9292, str); writeln(str);
                        movl              $9292, %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(131, str); writeln(str);
                        movl              $131, %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # 	int_to_str(2147483647, str); writeln(str);
                        movl              $2147483647, %eax
                        movl              %eax, -1028(%ebp)
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1032(%ebp)
                        movl              -1032(%ebp), %eax
                        pushl             %eax
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              int_to_str
                        addl              $8, %esp
                        lea               -1024(%ebp), %eax
                        movl              %eax, -1028(%ebp)
                        movl              -1028(%ebp), %eax
                        pushl             %eax
                        call              writeln
                        addl              $4, %esp
                                                            # }
main_end:
                        leave
                        ret
.bss
global:
.lcomm global_storage_space, 0

.data
string:
.int 0
.int 104 # 'h'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.int 119 # 'w'
.int 111 # 'o'
.int 114 # 'r'
.int 108 # 'l'
.int 100 # 'd'
.int 0
.int 0
.int 119 # 'w'
.int 111 # 'o'
.int 114 # 'r'
.int 108 # 'l'
.int 100 # 'd'
.int 0
.int 104 # 'h'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.int 0
.int 0
.int 0
.int 104 # 'h'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.int 104 # 'h'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 49 # '1'
.int 0
.int 104 # 'h'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.int 104 # 'h'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.int 0
.int 72 # 'H'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.int 119 # 'w'
.int 111 # 'o'
.int 114 # 'r'
.int 108 # 'l'
.int 100 # 'd'
.int 0
.int 0
.int 10
.int 0
.int 72 # 'H'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.int 10
.int 0
.int 32 # ' '
.int 0
.int 10
.int 0
.int 119 # 'w'
.int 111 # 'o'
.int 114 # 'r'
.int 108 # 'l'
.int 100 # 'd'
.int 0
.int 10
.int 0
.int 72 # 'H'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 32 # ' '
.int 119 # 'w'
.int 111 # 'o'
.int 114 # 'r'
.int 108 # 'l'
.int 100 # 'd'
.int 0
.int 10
.int 0
.int 0
.int 0
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 0
.int 97 # 'a'
.int 0
.int 0
.int 0
.int 98 # 'b'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 101 # 'e'
.int 102 # 'f'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 101 # 'e'
.int 102 # 'f'
.int 0
.int 101 # 'e'
.int 102 # 'f'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 101 # 'e'
.int 102 # 'f'
.int 0
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 101 # 'e'
.int 102 # 'f'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 120 # 'x'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 101 # 'e'
.int 102 # 'f'
.int 0
.int 101 # 'e'
.int 102 # 'f'
.int 120 # 'x'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 99 # 'c'
.int 100 # 'd'
.int 0
.int 0
.int 0
.int 0
.int 97 # 'a'
.int 0
.int 97 # 'a'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 0
.int 0
.int 0
.int 97 # 'a'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 10
.int 0
.int 0
.int 0
.int 48 # '0'
.int 0
.int 49 # '1'
.int 50 # '2'
.int 51 # '3'
.int 52 # '4'
.int 53 # '5'
.int 0
.int 48 # '0'
.int 49 # '1'
.int 50 # '2'
.int 51 # '3'
.int 52 # '4'
.int 53 # '5'
.int 0
.int 48 # '0'
.int 49 # '1'
.int 50 # '2'
.int 51 # '3'
.int 52 # '4'
.int 53 # '5'
.int 48 # '0'
.int 0
.int 50 # '2'
.int 49 # '1'
.int 52 # '4'
.int 55 # '7'
.int 52 # '4'
.int 56 # '8'
.int 51 # '3'
.int 54 # '6'
.int 52 # '4'
.int 55 # '7'
.int 0
.int 97 # 'a'
.int 98 # 'b'
.int 99 # 'c'
.int 0
.int 0
.end

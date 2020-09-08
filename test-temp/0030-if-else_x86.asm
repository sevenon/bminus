
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # main() {
main:                   enter             $40, $0
                                                            # 	int i;
                                                            # 	int t;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	t = 100;
                        movl              $100, %eax
                        movl              %eax, -8(%ebp)
                                                            # 
                                                            # 	while (i != 10) {
while_0_test:           movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $10, %eax
                        subl              -12(%ebp), %eax
                        jne               compare_1_true
                        movl              $0, %eax
                        jmp               compare_1_false
compare_1_true:         movl              $1, %eax
compare_1_false:        cmpl              $0, %eax
                        jz                while_0_end
                                                            # 		if (i == 1)
                        movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $1, %eax
                        subl              -12(%ebp), %eax
                        je                compare_2_true
                        movl              $0, %eax
                        jmp               compare_2_false
compare_2_true:         movl              $1, %eax
compare_2_false:        cmpl              $0, %eax
                        jz                if_3_next
                                                            # 			debug(i);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_4_end
                        neg               %eax
debug_neg_if_4_end:     pushl             $'\n
                        movl              $1, %esi
debug_to_str_5_begin:   movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_5_end
                        jmp               debug_to_str_5_begin
debug_to_str_5_end:     cmpl              $0, %ecx
                        jge               debug_sign_if_6_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_6_end:
debug_print_7_begin:    cmpl              $0, %esi
                        jz                debug_print_7_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_7_begin
debug_print_7_end:      jmp               if_3_end
                                                            # 		else if (i == 2)
if_3_next:              movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $2, %eax
                        subl              -12(%ebp), %eax
                        je                compare_8_true
                        movl              $0, %eax
                        jmp               compare_8_false
compare_8_true:         movl              $1, %eax
compare_8_false:        cmpl              $0, %eax
                        jz                if_9_next
                                                            # 			debug(i);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_10_end
                        neg               %eax
debug_neg_if_10_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_11_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_11_end
                        jmp               debug_to_str_11_begin
debug_to_str_11_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_12_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_12_end:
debug_print_13_begin:   cmpl              $0, %esi
                        jz                debug_print_13_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_13_begin
debug_print_13_end:     jmp               if_9_end
                                                            # 		else if (i == 3)
if_9_next:              movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $3, %eax
                        subl              -12(%ebp), %eax
                        je                compare_14_true
                        movl              $0, %eax
                        jmp               compare_14_false
compare_14_true:        movl              $1, %eax
compare_14_false:       cmpl              $0, %eax
                        jz                if_15_next
                                                            # 			debug(i);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_16_end
                        neg               %eax
debug_neg_if_16_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_17_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_17_end
                        jmp               debug_to_str_17_begin
debug_to_str_17_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_18_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_18_end:
debug_print_19_begin:   cmpl              $0, %esi
                        jz                debug_print_19_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_19_begin
debug_print_19_end:     jmp               if_15_end
                                                            # 		else if (i == 4)
if_15_next:             movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $4, %eax
                        subl              -12(%ebp), %eax
                        je                compare_20_true
                        movl              $0, %eax
                        jmp               compare_20_false
compare_20_true:        movl              $1, %eax
compare_20_false:       cmpl              $0, %eax
                        jz                if_21_next
                                                            # 			debug(i);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_22_end
                        neg               %eax
debug_neg_if_22_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_23_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_23_end
                        jmp               debug_to_str_23_begin
debug_to_str_23_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_24_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_24_end:
debug_print_25_begin:   cmpl              $0, %esi
                        jz                debug_print_25_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_25_begin
debug_print_25_end:     jmp               if_21_end
                                                            # 		else if (i == 5)
if_21_next:             movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $5, %eax
                        subl              -12(%ebp), %eax
                        je                compare_26_true
                        movl              $0, %eax
                        jmp               compare_26_false
compare_26_true:        movl              $1, %eax
compare_26_false:       cmpl              $0, %eax
                        jz                if_27_next
                                                            # 			debug(i);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_28_end
                        neg               %eax
debug_neg_if_28_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_29_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_29_end
                        jmp               debug_to_str_29_begin
debug_to_str_29_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_30_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_30_end:
debug_print_31_begin:   cmpl              $0, %esi
                        jz                debug_print_31_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_31_begin
debug_print_31_end:     jmp               if_27_end
                                                            # 		else
                                                            # 			debug(t);
if_27_next:             movl              -8(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_32_end
                        neg               %eax
debug_neg_if_32_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_33_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_33_end
                        jmp               debug_to_str_33_begin
debug_to_str_33_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_34_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_34_end:
debug_print_35_begin:   cmpl              $0, %esi
                        jz                debug_print_35_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_35_begin
debug_print_35_end:
if_27_end:
if_21_end:
if_15_end:
if_9_end:
                                                            # 
                                                            # 		i = i + 1;
if_3_end:               movl              -4(%ebp), %eax
                        movl              %eax, -12(%ebp)
                        movl              $1, %eax
                        addl              -12(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # }
                        jmp               while_0_test
while_0_end:
main_end:
                        leave
                        ret
.bss
global:
.lcomm global_storage_space, 0

.data
string:
.int 0
.end

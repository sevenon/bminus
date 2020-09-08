
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # int g1;
                                                            # int g2;
                                                            # 
                                                            # main() {
main:                   enter             $44, $0
                                                            # 	int i;
                                                            # 	int j;
                                                            # 	int k;
                                                            # 
                                                            # 	g1 = 2;
                        movl              $2, %eax
                        movl              %eax, 0+global
                                                            # 	g2 = -4;
                        movl              $4, %eax
                        movl              %eax, -16(%ebp)
                        movl              $0, %eax
                        subl              -16(%ebp), %eax
                        movl              %eax, 4+global
                                                            # 
                                                            # 	i = 5;
                        movl              $5, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	j = 6;
                        movl              $6, %eax
                        movl              %eax, -8(%ebp)
                                                            # 
                                                            # 	debug(i < 5 && j == 6);
                        movl              -4(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jg                compare_0_true
                        movl              $0, %eax
                        jmp               compare_0_false
compare_0_true:         movl              $1, %eax
compare_0_false:        cmpl              $0, %eax
                        jz                logical_and_1_false
                        movl              -8(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $6, %eax
                        subl              -16(%ebp), %eax
                        je                compare_2_true
                        movl              $0, %eax
                        jmp               compare_2_false
compare_2_true:         movl              $1, %eax
compare_2_false:        cmpl              $0, %eax
                        jz                logical_and_1_false
                        movl              $1, %eax
                        jmp               logical_and_1_true
logical_and_1_false:    movl              $0, %eax
logical_and_1_true:     movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_3_end
                        neg               %eax
debug_neg_if_3_end:     pushl             $'\n
                        movl              $1, %esi
debug_to_str_4_begin:   movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_4_end
                        jmp               debug_to_str_4_begin
debug_to_str_4_end:     cmpl              $0, %ecx
                        jge               debug_sign_if_5_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_5_end:
debug_print_6_begin:    cmpl              $0, %esi
                        jz                debug_print_6_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_6_begin
                                                            # 	if (i < 5 && j == 6)
debug_print_6_end:      movl              -4(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jg                compare_7_true
                        movl              $0, %eax
                        jmp               compare_7_false
compare_7_true:         movl              $1, %eax
compare_7_false:        cmpl              $0, %eax
                        jz                logical_and_8_false
                        movl              -8(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $6, %eax
                        subl              -16(%ebp), %eax
                        je                compare_9_true
                        movl              $0, %eax
                        jmp               compare_9_false
compare_9_true:         movl              $1, %eax
compare_9_false:        cmpl              $0, %eax
                        jz                logical_and_8_false
                        movl              $1, %eax
                        jmp               logical_and_8_true
logical_and_8_false:    movl              $0, %eax
logical_and_8_true:     cmpl              $0, %eax
                        jz                if_10_next
                                                            # 		debug(1);
                        movl              $1, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_11_end
                        neg               %eax
debug_neg_if_11_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_12_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_12_end
                        jmp               debug_to_str_12_begin
debug_to_str_12_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_13_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_13_end:
debug_print_14_begin:   cmpl              $0, %esi
                        jz                debug_print_14_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_14_begin
debug_print_14_end:     jmp               if_10_end
                                                            # 	else
                                                            # 		debug(2);
if_10_next:             movl              $2, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_15_end
                        neg               %eax
debug_neg_if_15_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_16_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_16_end
                        jmp               debug_to_str_16_begin
debug_to_str_16_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_17_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_17_end:
debug_print_18_begin:   cmpl              $0, %esi
                        jz                debug_print_18_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_18_begin
debug_print_18_end:
                                                            # 
                                                            # 	debug(0 || 1 && 1 && 1);
if_10_end:              movl              $0, %eax
                        cmpl              $0, %eax
                        jnz               logical_or_19_true
                        movl              $1, %eax
                        cmpl              $0, %eax
                        jz                logical_and_20_false
                        movl              $1, %eax
                        cmpl              $0, %eax
                        jz                logical_and_20_false
                        movl              $1, %eax
                        cmpl              $0, %eax
                        jz                logical_and_20_false
                        movl              $1, %eax
                        jmp               logical_and_20_true
logical_and_20_false:   movl              $0, %eax
logical_and_20_true:    cmpl              $0, %eax
                        jnz               logical_or_19_true
                        movl              $0, %eax
                        jmp               logical_or_19_false
logical_or_19_true:     movl              $1, %eax
logical_or_19_false:    movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_21_end
                        neg               %eax
debug_neg_if_21_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_22_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_22_end
                        jmp               debug_to_str_22_begin
debug_to_str_22_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_23_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_23_end:
debug_print_24_begin:   cmpl              $0, %esi
                        jz                debug_print_24_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_24_begin
                                                            # 
                                                            # 	debug(1 || 0 && 1 && 1);
debug_print_24_end:     movl              $1, %eax
                        cmpl              $0, %eax
                        jnz               logical_or_25_true
                        movl              $0, %eax
                        cmpl              $0, %eax
                        jz                logical_and_26_false
                        movl              $1, %eax
                        cmpl              $0, %eax
                        jz                logical_and_26_false
                        movl              $1, %eax
                        cmpl              $0, %eax
                        jz                logical_and_26_false
                        movl              $1, %eax
                        jmp               logical_and_26_true
logical_and_26_false:   movl              $0, %eax
logical_and_26_true:    cmpl              $0, %eax
                        jnz               logical_or_25_true
                        movl              $0, %eax
                        jmp               logical_or_25_false
logical_or_25_true:     movl              $1, %eax
logical_or_25_false:    movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_27_end
                        neg               %eax
debug_neg_if_27_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_28_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_28_end
                        jmp               debug_to_str_28_begin
debug_to_str_28_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_29_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_29_end:
debug_print_30_begin:   cmpl              $0, %esi
                        jz                debug_print_30_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_30_begin
                                                            # 
                                                            # 	if (1 || debug(10)) {}
debug_print_30_end:     movl              $1, %eax
                        cmpl              $0, %eax
                        jnz               logical_or_31_true
                        movl              $10, %eax
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
debug_print_35_end:     cmpl              $0, %eax
                        jnz               logical_or_31_true
                        movl              $0, %eax
                        jmp               logical_or_31_false
logical_or_31_true:     movl              $1, %eax
logical_or_31_false:    cmpl              $0, %eax
                        jz                if_36_next
                                                            # 	if (0 || debug(20)) {}
if_36_next:
if_36_end:              movl              $0, %eax
                        cmpl              $0, %eax
                        jnz               logical_or_37_true
                        movl              $20, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_38_end
                        neg               %eax
debug_neg_if_38_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_39_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_39_end
                        jmp               debug_to_str_39_begin
debug_to_str_39_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_40_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_40_end:
debug_print_41_begin:   cmpl              $0, %esi
                        jz                debug_print_41_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_41_begin
debug_print_41_end:     cmpl              $0, %eax
                        jnz               logical_or_37_true
                        movl              $0, %eax
                        jmp               logical_or_37_false
logical_or_37_true:     movl              $1, %eax
logical_or_37_false:    cmpl              $0, %eax
                        jz                if_42_next
                                                            # 	if (1 && debug(30)) {}
if_42_next:
if_42_end:              movl              $1, %eax
                        cmpl              $0, %eax
                        jz                logical_and_43_false
                        movl              $30, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_44_end
                        neg               %eax
debug_neg_if_44_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_45_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_45_end
                        jmp               debug_to_str_45_begin
debug_to_str_45_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_46_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_46_end:
debug_print_47_begin:   cmpl              $0, %esi
                        jz                debug_print_47_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_47_begin
debug_print_47_end:     cmpl              $0, %eax
                        jz                logical_and_43_false
                        movl              $1, %eax
                        jmp               logical_and_43_true
logical_and_43_false:   movl              $0, %eax
logical_and_43_true:    cmpl              $0, %eax
                        jz                if_48_next
                                                            # 	if (0 && debug(40)) {}
if_48_next:
if_48_end:              movl              $0, %eax
                        cmpl              $0, %eax
                        jz                logical_and_49_false
                        movl              $40, %eax
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
debug_print_53_end:     cmpl              $0, %eax
                        jz                logical_and_49_false
                        movl              $1, %eax
                        jmp               logical_and_49_true
logical_and_49_false:   movl              $0, %eax
logical_and_49_true:    cmpl              $0, %eax
                        jz                if_54_next
                                                            # }
if_54_next:
                                                            # 
if_54_end:
main_end:
                        leave
                        ret
.bss
global:
.lcomm global_storage_space, 8

.data
string:
.int 0
.end

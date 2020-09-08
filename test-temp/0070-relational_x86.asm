
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
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	j = 10;
                        movl              $10, %eax
                        movl              %eax, -8(%ebp)
                                                            # 	k = -5;
                        movl              $5, %eax
                        movl              %eax, -16(%ebp)
                        movl              $0, %eax
                        subl              -16(%ebp), %eax
                        movl              %eax, -12(%ebp)
                                                            # 
                                                            # 
                                                            # 	g1 = 2;
                        movl              $2, %eax
                        movl              %eax, 0+global
                                                            # 
                                                            # 
                                                            # 	g1 = 1 == 10 == 10;
                        movl              $1, %eax
                        movl              %eax, -16(%ebp)
                        movl              $10, %eax
                        subl              -16(%ebp), %eax
                        je                compare_0_true
                        movl              $0, %eax
                        jmp               compare_0_false
compare_0_true:         movl              $1, %eax
compare_0_false:        movl              %eax, -16(%ebp)
                        movl              $10, %eax
                        subl              -16(%ebp), %eax
                        je                compare_1_true
                        movl              $0, %eax
                        jmp               compare_1_false
compare_1_true:         movl              $1, %eax
compare_1_false:        movl              %eax, 0+global
                                                            # 	debug(g1);
                        movl              0+global, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_2_end
                        neg               %eax
debug_neg_if_2_end:     pushl             $'\n
                        movl              $1, %esi
debug_to_str_3_begin:   movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_3_end
                        jmp               debug_to_str_3_begin
debug_to_str_3_end:     cmpl              $0, %ecx
                        jge               debug_sign_if_4_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_4_end:
debug_print_5_begin:    cmpl              $0, %esi
                        jz                debug_print_5_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_5_begin
                                                            # 
                                                            # 	g1 = 10 == 10 == 1;
debug_print_5_end:      movl              $10, %eax
                        movl              %eax, -16(%ebp)
                        movl              $10, %eax
                        subl              -16(%ebp), %eax
                        je                compare_6_true
                        movl              $0, %eax
                        jmp               compare_6_false
compare_6_true:         movl              $1, %eax
compare_6_false:        movl              %eax, -16(%ebp)
                        movl              $1, %eax
                        subl              -16(%ebp), %eax
                        je                compare_7_true
                        movl              $0, %eax
                        jmp               compare_7_false
compare_7_true:         movl              $1, %eax
compare_7_false:        movl              %eax, 0+global
                                                            # 	debug(g1);
                        movl              0+global, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_8_end
                        neg               %eax
debug_neg_if_8_end:     pushl             $'\n
                        movl              $1, %esi
debug_to_str_9_begin:   movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_9_end
                        jmp               debug_to_str_9_begin
debug_to_str_9_end:     cmpl              $0, %ecx
                        jge               debug_sign_if_10_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_10_end:
debug_print_11_begin:   cmpl              $0, %esi
                        jz                debug_print_11_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_11_begin
                                                            # 
                                                            # 	g1 = 1 > 5 != 0;
debug_print_11_end:     movl              $1, %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jl                compare_12_true
                        movl              $0, %eax
                        jmp               compare_12_false
compare_12_true:        movl              $1, %eax
compare_12_false:       movl              %eax, -16(%ebp)
                        movl              $0, %eax
                        subl              -16(%ebp), %eax
                        jne               compare_13_true
                        movl              $0, %eax
                        jmp               compare_13_false
compare_13_true:        movl              $1, %eax
compare_13_false:       movl              %eax, 0+global
                                                            # 	debug(g1);
                        movl              0+global, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_14_end
                        neg               %eax
debug_neg_if_14_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_15_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_15_end
                        jmp               debug_to_str_15_begin
debug_to_str_15_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_16_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_16_end:
debug_print_17_begin:   cmpl              $0, %esi
                        jz                debug_print_17_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_17_begin
                                                            # 
                                                            # 	g1 = 1 > 5 == 0;
debug_print_17_end:     movl              $1, %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jl                compare_18_true
                        movl              $0, %eax
                        jmp               compare_18_false
compare_18_true:        movl              $1, %eax
compare_18_false:       movl              %eax, -16(%ebp)
                        movl              $0, %eax
                        subl              -16(%ebp), %eax
                        je                compare_19_true
                        movl              $0, %eax
                        jmp               compare_19_false
compare_19_true:        movl              $1, %eax
compare_19_false:       movl              %eax, 0+global
                                                            # 	debug(g1);
                        movl              0+global, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_20_end
                        neg               %eax
debug_neg_if_20_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_21_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_21_end
                        jmp               debug_to_str_21_begin
debug_to_str_21_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_22_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_22_end:
debug_print_23_begin:   cmpl              $0, %esi
                        jz                debug_print_23_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_23_begin
                                                            # 
                                                            # 	debug(2 < 5);
debug_print_23_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jg                compare_24_true
                        movl              $0, %eax
                        jmp               compare_24_false
compare_24_true:        movl              $1, %eax
compare_24_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_25_end
                        neg               %eax
debug_neg_if_25_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_26_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_26_end
                        jmp               debug_to_str_26_begin
debug_to_str_26_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_27_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_27_end:
debug_print_28_begin:   cmpl              $0, %esi
                        jz                debug_print_28_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_28_begin
                                                            # 	debug(2 <= 5);
debug_print_28_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jg                compare_29_true
                        je                compare_29_true
                        movl              $0, %eax
                        jmp               compare_29_false
compare_29_true:        movl              $1, %eax
compare_29_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_30_end
                        neg               %eax
debug_neg_if_30_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_31_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_31_end
                        jmp               debug_to_str_31_begin
debug_to_str_31_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_32_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_32_end:
debug_print_33_begin:   cmpl              $0, %esi
                        jz                debug_print_33_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_33_begin
                                                            # 	debug(2 <= 2);
debug_print_33_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        subl              -16(%ebp), %eax
                        jg                compare_34_true
                        je                compare_34_true
                        movl              $0, %eax
                        jmp               compare_34_false
compare_34_true:        movl              $1, %eax
compare_34_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_35_end
                        neg               %eax
debug_neg_if_35_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_36_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_36_end
                        jmp               debug_to_str_36_begin
debug_to_str_36_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_37_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_37_end:
debug_print_38_begin:   cmpl              $0, %esi
                        jz                debug_print_38_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_38_begin
                                                            # 	debug(2 > 5);
debug_print_38_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jl                compare_39_true
                        movl              $0, %eax
                        jmp               compare_39_false
compare_39_true:        movl              $1, %eax
compare_39_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_40_end
                        neg               %eax
debug_neg_if_40_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_41_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_41_end
                        jmp               debug_to_str_41_begin
debug_to_str_41_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_42_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_42_end:
debug_print_43_begin:   cmpl              $0, %esi
                        jz                debug_print_43_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_43_begin
                                                            # 	debug(2 >= 5);
debug_print_43_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $5, %eax
                        subl              -16(%ebp), %eax
                        jl                compare_44_true
                        je                compare_44_true
                        movl              $0, %eax
                        jmp               compare_44_false
compare_44_true:        movl              $1, %eax
compare_44_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_45_end
                        neg               %eax
debug_neg_if_45_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_46_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_46_end
                        jmp               debug_to_str_46_begin
debug_to_str_46_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_47_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_47_end:
debug_print_48_begin:   cmpl              $0, %esi
                        jz                debug_print_48_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_48_begin
                                                            # 	debug(2 >= 2);
debug_print_48_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        subl              -16(%ebp), %eax
                        jl                compare_49_true
                        je                compare_49_true
                        movl              $0, %eax
                        jmp               compare_49_false
compare_49_true:        movl              $1, %eax
compare_49_false:       movl              %eax, %ecx
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
                                                            # 	debug(2 == 2);
debug_print_53_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        subl              -16(%ebp), %eax
                        je                compare_54_true
                        movl              $0, %eax
                        jmp               compare_54_false
compare_54_true:        movl              $1, %eax
compare_54_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_55_end
                        neg               %eax
debug_neg_if_55_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_56_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_56_end
                        jmp               debug_to_str_56_begin
debug_to_str_56_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_57_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_57_end:
debug_print_58_begin:   cmpl              $0, %esi
                        jz                debug_print_58_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_58_begin
                                                            # 	debug(2 == 3);
debug_print_58_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $3, %eax
                        subl              -16(%ebp), %eax
                        je                compare_59_true
                        movl              $0, %eax
                        jmp               compare_59_false
compare_59_true:        movl              $1, %eax
compare_59_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_60_end
                        neg               %eax
debug_neg_if_60_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_61_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_61_end
                        jmp               debug_to_str_61_begin
debug_to_str_61_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_62_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_62_end:
debug_print_63_begin:   cmpl              $0, %esi
                        jz                debug_print_63_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_63_begin
                                                            # 	debug(3 == 2);
debug_print_63_end:     movl              $3, %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        subl              -16(%ebp), %eax
                        je                compare_64_true
                        movl              $0, %eax
                        jmp               compare_64_false
compare_64_true:        movl              $1, %eax
compare_64_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_65_end
                        neg               %eax
debug_neg_if_65_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_66_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_66_end
                        jmp               debug_to_str_66_begin
debug_to_str_66_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_67_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_67_end:
debug_print_68_begin:   cmpl              $0, %esi
                        jz                debug_print_68_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_68_begin
                                                            # 	debug(2 != 2);
debug_print_68_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        subl              -16(%ebp), %eax
                        jne               compare_69_true
                        movl              $0, %eax
                        jmp               compare_69_false
compare_69_true:        movl              $1, %eax
compare_69_false:       movl              %eax, %ecx
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
                                                            # 	debug(2 != 3);
debug_print_73_end:     movl              $2, %eax
                        movl              %eax, -16(%ebp)
                        movl              $3, %eax
                        subl              -16(%ebp), %eax
                        jne               compare_74_true
                        movl              $0, %eax
                        jmp               compare_74_false
compare_74_true:        movl              $1, %eax
compare_74_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_75_end
                        neg               %eax
debug_neg_if_75_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_76_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_76_end
                        jmp               debug_to_str_76_begin
debug_to_str_76_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_77_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_77_end:
debug_print_78_begin:   cmpl              $0, %esi
                        jz                debug_print_78_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_78_begin
                                                            # 	debug(3 != 2);
debug_print_78_end:     movl              $3, %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        subl              -16(%ebp), %eax
                        jne               compare_79_true
                        movl              $0, %eax
                        jmp               compare_79_false
compare_79_true:        movl              $1, %eax
compare_79_false:       movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_80_end
                        neg               %eax
debug_neg_if_80_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_81_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_81_end
                        jmp               debug_to_str_81_begin
debug_to_str_81_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_82_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_82_end:
debug_print_83_begin:   cmpl              $0, %esi
                        jz                debug_print_83_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_83_begin
                                                            # 
                                                            # }
debug_print_83_end:
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

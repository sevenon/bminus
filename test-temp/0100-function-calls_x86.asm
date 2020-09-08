
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # int global1;
                                                            # 
                                                            # f1(int arg1, int arg2, int arg3) {
f1:                     enter             $32, $0
                                                            # 	debug(arg1);
                        movl              8(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_0_end
                        neg               %eax
debug_neg_if_0_end:     pushl             $'\n
                        movl              $1, %esi
debug_to_str_1_begin:   movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_1_end
                        jmp               debug_to_str_1_begin
debug_to_str_1_end:     cmpl              $0, %ecx
                        jge               debug_sign_if_2_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_2_end:
debug_print_3_begin:    cmpl              $0, %esi
                        jz                debug_print_3_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_3_begin
                                                            # 	debug(arg2);
debug_print_3_end:      movl              12(%ebp), %eax
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
                                                            # 	debug(arg3);
debug_print_7_end:      movl              16(%ebp), %eax
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
                                                            # }
                                                            # 
                                                            # int global2;
debug_print_11_end:
f1_end:
                        leave
                        ret
                                                            # 
                                                            # f2(int arg2, int arg3) {
f2:                     enter             $32, $0
                                                            # 	return arg2 * arg3;
                        movl              8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                        movl              12(%ebp), %eax
                        imull             -4(%ebp)
                        jmp               f2_end
                                                            # }
                                                            # 
                                                            # int global3;
f2_end:
                        leave
                        ret
                                                            # 
                                                            # main() {
main:                   enter             $36, $0
                                                            # 	int local1;
                                                            # 
                                                            # 	f1(10, f2(10,50), 30);
                        movl              $10, %eax
                        movl              %eax, -8(%ebp)
                        movl              $10, %eax
                        movl              %eax, -12(%ebp)
                        movl              $50, %eax
                        movl              %eax, -16(%ebp)
                        movl              -16(%ebp), %eax
                        pushl             %eax
                        movl              -12(%ebp), %eax
                        pushl             %eax
                        call              f2
                        addl              $8, %esp
                        movl              %eax, -12(%ebp)
                        movl              $30, %eax
                        movl              %eax, -16(%ebp)
                        movl              -16(%ebp), %eax
                        pushl             %eax
                        movl              -12(%ebp), %eax
                        pushl             %eax
                        movl              -8(%ebp), %eax
                        pushl             %eax
                        call              f1
                        addl              $12, %esp
                                                            # 
                                                            # 	local1 = 10;
                        movl              $10, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	global1 = 1;
                        movl              $1, %eax
                        movl              %eax, 0+global
                                                            # 	global2 = 2;
                        movl              $2, %eax
                        movl              %eax, 4+global
                                                            # 	global3 = 3;
                        movl              $3, %eax
                        movl              %eax, 8+global
                                                            # 
                                                            # 	debug(local1);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_12_end
                        neg               %eax
debug_neg_if_12_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_13_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_13_end
                        jmp               debug_to_str_13_begin
debug_to_str_13_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_14_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_14_end:
debug_print_15_begin:   cmpl              $0, %esi
                        jz                debug_print_15_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_15_begin
                                                            # 	debug(global1);
debug_print_15_end:     movl              0+global, %eax
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
                                                            # 	debug(global2);
debug_print_19_end:     movl              4+global, %eax
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
                                                            # 	debug(global3);
debug_print_23_end:     movl              8+global, %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_24_end
                        neg               %eax
debug_neg_if_24_end:    pushl             $'\n
                        movl              $1, %esi
debug_to_str_25_begin:  movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_25_end
                        jmp               debug_to_str_25_begin
debug_to_str_25_end:    cmpl              $0, %ecx
                        jge               debug_sign_if_26_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_26_end:
debug_print_27_begin:   cmpl              $0, %esi
                        jz                debug_print_27_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_27_begin
                                                            # }
debug_print_27_end:
main_end:
                        leave
                        ret
.bss
global:
.lcomm global_storage_space, 12

.data
string:
.int 0
.end

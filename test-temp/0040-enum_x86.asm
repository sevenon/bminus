
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # enum {a, b, c, d=20, e, f=50};
                                                            # 
                                                            # 
                                                            # main() {
main:                   enter             $32, $0
                                                            # 	debug(a);
                        movl              $0, %eax
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
                                                            # 	debug(b);
debug_print_3_end:      movl              $1, %eax
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
                                                            # 	debug(c);
debug_print_7_end:      movl              $2, %eax
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
                                                            # 	debug(d);
debug_print_11_end:     movl              $20, %eax
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
                                                            # 	debug(e);
debug_print_15_end:     movl              $21, %eax
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
                                                            # 	debug(f);
debug_print_19_end:     movl              $50, %eax
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
                                                            # }
                                                            # 
debug_print_23_end:
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

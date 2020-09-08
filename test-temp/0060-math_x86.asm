
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
                                                            # 	k = 4 + 2 - 16 + 8 + (2 * 5 / 2);
                        movl              $4, %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $16, %eax
                        movl              %eax, -20(%ebp)
                        movl              -16(%ebp), %eax
                        subl              -20(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $8, %eax
                        addl              -16(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        movl              %eax, -20(%ebp)
                        movl              $5, %eax
                        imull             -20(%ebp)
                        movl              %eax, -20(%ebp)
                        movl              $2, %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        cdq
                        idivl             -24(%ebp)
                        addl              -16(%ebp), %eax
                        movl              %eax, -12(%ebp)
                                                            # 	debug(k);
                        movl              -12(%ebp), %eax
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
                                                            # 
                                                            # 	k = (g1 + i * 5 / 2 - 10 + 4 / 2) * 2 - j * (g2 - 1);
debug_print_3_end:      movl              0+global, %eax
                        movl              %eax, -16(%ebp)
                        movl              -4(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              $5, %eax
                        imull             -20(%ebp)
                        movl              %eax, -20(%ebp)
                        movl              $2, %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        cdq
                        idivl             -24(%ebp)
                        addl              -16(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $10, %eax
                        movl              %eax, -20(%ebp)
                        movl              -16(%ebp), %eax
                        subl              -20(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $4, %eax
                        movl              %eax, -20(%ebp)
                        movl              $2, %eax
                        movl              %eax, -24(%ebp)
                        movl              -20(%ebp), %eax
                        cdq
                        idivl             -24(%ebp)
                        addl              -16(%ebp), %eax
                        movl              %eax, -16(%ebp)
                        movl              $2, %eax
                        imull             -16(%ebp)
                        movl              %eax, -16(%ebp)
                        movl              -8(%ebp), %eax
                        movl              %eax, -20(%ebp)
                        movl              4+global, %eax
                        movl              %eax, -24(%ebp)
                        movl              $1, %eax
                        movl              %eax, -28(%ebp)
                        movl              -24(%ebp), %eax
                        subl              -28(%ebp), %eax
                        imull             -20(%ebp)
                        movl              %eax, -20(%ebp)
                        movl              -16(%ebp), %eax
                        subl              -20(%ebp), %eax
                        movl              %eax, -12(%ebp)
                                                            # 	debug(k);
                        movl              -12(%ebp), %eax
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
                                                            # 
                                                            # }
debug_print_7_end:
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

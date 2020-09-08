
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # int i;
                                                            # 
                                                            # main() {
main:                   enter             $32, $0
                                                            # 	i = 10;
                        movl              $10, %eax
                        movl              %eax, 0+global
                                                            # 
                                                            # 	debug(i);
                        movl              0+global, %eax
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
                                                            # }
                                                            # 
debug_print_3_end:
main_end:
                        leave
                        ret
.bss
global:
.lcomm global_storage_space, 4

.data
string:
.int 0
.end

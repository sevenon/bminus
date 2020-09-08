
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # main() {
main:                   enter             $36, $0
                                                            # 	int i;
                                                            # 	i = 20;
                        movl              $20, %eax
                        movl              %eax, -4(%ebp)
                                                            # 
                                                            # 	while (i - 10 >= 0) {
while_0_test:           movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $10, %eax
                        movl              %eax, -12(%ebp)
                        movl              -8(%ebp), %eax
                        subl              -12(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $0, %eax
                        subl              -8(%ebp), %eax
                        jl                compare_1_true
                        je                compare_1_true
                        movl              $0, %eax
                        jmp               compare_1_false
compare_1_true:         movl              $1, %eax
compare_1_false:        cmpl              $0, %eax
                        jz                while_0_end
                                                            #     	debug(i);
                        movl              -4(%ebp), %eax
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
                                                            # 		i = i-1;
debug_print_5_end:      movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        movl              %eax, -12(%ebp)
                        movl              -8(%ebp), %eax
                        subl              -12(%ebp), %eax
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

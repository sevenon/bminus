
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # 
                                                            # main() {
main:                   enter             $76, $0
                                                            # 	int i;
                                                            # 	int arr[10];
                                                            # 
                                                            # 	i = 9;
                        movl              $9, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while (i >= 0) {
while_0_test:           movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              $0, %eax
                        subl              -48(%ebp), %eax
                        jl                compare_1_true
                        je                compare_1_true
                        movl              $0, %eax
                        jmp               compare_1_false
compare_1_true:         movl              $1, %eax
compare_1_false:        cmpl              $0, %eax
                        jz                while_0_end
                                                            # 		arr[i] = i + 100;
                        movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              -4(%ebp), %eax
                        movl              %eax, -52(%ebp)
                        movl              $100, %eax
                        addl              -52(%ebp), %eax
                        movl              %eax, -52(%ebp)
                        movl              -48(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -52(%ebp), %eax
                        movl              %eax, -44(%ebp,%ebx,4)
                                                            # 		i = i - 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              $1, %eax
                        movl              %eax, -52(%ebp)
                        movl              -48(%ebp), %eax
                        subl              -52(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 	i = 9;
                        jmp               while_0_test
while_0_end:            movl              $9, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while (i >= 0) {
while_2_test:           movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              $0, %eax
                        subl              -48(%ebp), %eax
                        jl                compare_3_true
                        je                compare_3_true
                        movl              $0, %eax
                        jmp               compare_3_false
compare_3_true:         movl              $1, %eax
compare_3_false:        cmpl              $0, %eax
                        jz                while_2_end
                                                            # 		arr[i] = i + 100;
                        movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              -4(%ebp), %eax
                        movl              %eax, -52(%ebp)
                        movl              $100, %eax
                        addl              -52(%ebp), %eax
                        movl              %eax, -52(%ebp)
                        movl              -48(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -52(%ebp), %eax
                        movl              %eax, -44(%ebp,%ebx,4)
                                                            # 		i = i - 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              $1, %eax
                        movl              %eax, -52(%ebp)
                        movl              -48(%ebp), %eax
                        subl              -52(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 
                                                            # 	i = 0;
                        jmp               while_2_test
while_2_end:            movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while (i < 10) {
while_4_test:           movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              $10, %eax
                        subl              -48(%ebp), %eax
                        jg                compare_5_true
                        movl              $0, %eax
                        jmp               compare_5_false
compare_5_true:         movl              $1, %eax
compare_5_false:        cmpl              $0, %eax
                        jz                while_4_end
                                                            # 		debug(arr[i]);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -44(%ebp,%ebx,4), %eax
                        movl              %eax, %ecx
                        cmpl              $0, %eax
                        jge               debug_neg_if_6_end
                        neg               %eax
debug_neg_if_6_end:     pushl             $'\n
                        movl              $1, %esi
debug_to_str_7_begin:   movl              $0, %edx
                        movl              $10, %ebx
                        divl              %ebx
                        addl              $48, %edx
                        pushl             %edx
                        incl              %esi
                        cmpl              $0, %eax
                        jz                debug_to_str_7_end
                        jmp               debug_to_str_7_begin
debug_to_str_7_end:     cmpl              $0, %ecx
                        jge               debug_sign_if_8_end
                        pushl             $'-
                        incl              %esi
debug_sign_if_8_end:
debug_print_9_begin:    cmpl              $0, %esi
                        jz                debug_print_9_end
                        decl              %esi
                        movl              $4, %eax
                        movl              %esp, %ecx
                        movl              $1, %ebx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                        jmp               debug_print_9_begin
                                                            # 		i = i + 1;
debug_print_9_end:      movl              -4(%ebp), %eax
                        movl              %eax, -48(%ebp)
                        movl              $1, %eax
                        addl              -48(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}	
                                                            # }
                        jmp               while_4_test
while_4_end:
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

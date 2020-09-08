
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # fn(char s1[], char s2[]) {
fn:                     enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(s1[i] != 0) {
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
                                                            # 		debug(s1[i]);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
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
                                                            # 		i = i + 1;
debug_print_5_end:      movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # 	
                                                            # 	i = 0;
                        jmp               while_0_test
while_0_end:            movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(s2[i] != 0) {
while_6_test:           movl              -4(%ebp), %eax
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
                        jne               compare_7_true
                        movl              $0, %eax
                        jmp               compare_7_false
compare_7_true:         movl              $1, %eax
compare_7_false:        cmpl              $0, %eax
                        jz                while_6_end
                                                            # 		debug(s2[i]);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              12(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
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
                                                            # 		i = i + 1;
debug_print_11_end:     movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # }
                        jmp               while_6_test
                                                            # 
                                                            # main() {
while_6_end:
fn_end:
                        leave
                        ret
main:                   enter             $32, $0
                                                            # 
                                                            # 	fn("hello", "world");
                        lea               4+string, %eax
                        movl              %eax, -4(%ebp)
                        lea               28+string, %eax
                        movl              %eax, -8(%ebp)
                        movl              -8(%ebp), %eax
                        pushl             %eax
                        movl              -4(%ebp), %eax
                        pushl             %eax
                        call              fn
                        addl              $8, %esp
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
.end

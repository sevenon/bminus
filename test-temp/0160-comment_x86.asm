
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # // this is a comment
                                                            # 
                                                            # fn(char arr[]) {
fn:                     enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while(arr[i] != 0) {
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
                                                            # 		debug(arr[i]);
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
                                                            # }
                        jmp               while_0_test
                                                            # 
                                                            # main() {// more comments
while_0_end:
fn_end:
                        leave
                        ret
main:                   enter             $36, $0
                                                            # 	int i;
                                                            # 	i = 5;
                        movl              $5, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	fn("hello // hello");
                        lea               4+string, %eax
                        movl              %eax, -8(%ebp)
                        movl              -8(%ebp), %eax
                        pushl             %eax
                        call              fn
                        addl              $4, %esp
                                                            # 	// comment
                                                            # 	debug(i);
                        movl              -4(%ebp), %eax
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
                                                            # }
debug_print_9_end:
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
.int 32 # ' '
.int 47 # '/'
.int 47 # '/'
.int 32 # ' '
.int 104 # 'h'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 0
.end

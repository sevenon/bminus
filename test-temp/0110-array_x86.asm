
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # enum { arrlen = 10 };
                                                            # 
                                                            # int j[10];
                                                            # int k[arrlen];
                                                            # 
                                                            # fn() {
fn:                     enter             $32, $0
                                                            # 	return 2;
                        movl              $2, %eax
                        jmp               fn_end
                                                            # }
                                                            # 
                                                            # main() {
fn_end:
                        leave
                        ret
main:                   enter             $56, $0
                                                            # 	enum { five = 5 };
                                                            # 	int b;
                                                            # 	int i[five];
                                                            # 
                                                            # 	i[fn()] = 4;
                        call              fn
                        movl              %eax, -28(%ebp)
                        movl              $4, %eax
                        movl              %eax, -32(%ebp)
                        movl              -28(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -32(%ebp), %eax
                        movl              %eax, -24(%ebp,%ebx,4)
                                                            # 
                                                            # 	j[i[2]] = 99;
                        movl              $2, %eax
                        movl              %eax, %ebx
                        movl              -24(%ebp,%ebx,4), %eax
                        movl              %eax, -28(%ebp)
                        movl              $99, %eax
                        movl              %eax, -32(%ebp)
                        movl              -28(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -32(%ebp), %eax
                        movl              %eax, 0+global(,%ebx,4)
                                                            # 
                                                            # 	b = 4;
                        movl              $4, %eax
                        movl              %eax, -4(%ebp)
                                                            # 
                                                            # 	k[arrlen-1] = 0;
                        movl              $10, %eax
                        movl              %eax, -28(%ebp)
                        movl              $1, %eax
                        movl              %eax, -32(%ebp)
                        movl              -28(%ebp), %eax
                        subl              -32(%ebp), %eax
                        movl              %eax, -28(%ebp)
                        movl              $0, %eax
                        movl              %eax, -32(%ebp)
                        movl              -28(%ebp), %eax
                        movl              %eax, %ebx
                        movl              -32(%ebp), %eax
                        movl              %eax, 40+global(,%ebx,4)
                                                            # 
                                                            # 	debug(j[b]);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        movl              0+global(,%ebx,4), %eax
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
debug_print_3_end:
main_end:
                        leave
                        ret
.bss
global:
.lcomm global_storage_space, 80

.data
string:
.int 0
.end

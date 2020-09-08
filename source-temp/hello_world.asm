
.text
.globl _start
_start:
                        call              main
                        movl              $1, %eax
                        movl              $0, %ebx
                        int               $0x80

                                                            # 
                                                            # main() {
main:                   enter             $32, $0
                                                            # 
                                                            #     write("Hello world\n");
                        lea               4+string, %eax
                        movl              %eax, -4(%ebp)
                        movl              -4(%ebp), %eax
                        pushl             %eax
                        call              write
                        addl              $4, %esp
                                                            #     exit(0);
                        movl              $0, %eax
                        movl              %eax, %ebx
                        movl              $1, %eax
                        int               $0x80
                                                            # }
                                                            # 
                                                            # write(char str[]) {
main_end:
                        leave
                        ret
write:                  enter             $36, $0
                                                            # 	int i;
                                                            # 
                                                            # 	i = 0;
                        movl              $0, %eax
                        movl              %eax, -4(%ebp)
                                                            # 	while (str[i] != 0) {
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
                                                            # 		fputc(str[i], stdout);
                        movl              -4(%ebp), %eax
                        movl              %eax, %ebx
                        lea               (,%ebx,4), %eax
                        movl              %eax, -8(%ebp)
                        movl              8(%ebp), %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, %ebx
                        movl              (%ebx), %eax
                        pushl             %eax
                        movl              $4, %eax
                        movl              $1, %ebx
                        movl              %esp, %ecx
                        movl              $1, %edx
                        int               $0x80
                        addl              $4, %esp
                                                            # 		i = i + 1;
                        movl              -4(%ebp), %eax
                        movl              %eax, -8(%ebp)
                        movl              $1, %eax
                        addl              -8(%ebp), %eax
                        movl              %eax, -4(%ebp)
                                                            # 	}
                                                            # }
                        jmp               while_0_test
while_0_end:
write_end:
                        leave
                        ret
.bss
global:
.lcomm global_storage_space, 0

.data
string:
.int 0
.int 72 # 'H'
.int 101 # 'e'
.int 108 # 'l'
.int 108 # 'l'
.int 111 # 'o'
.int 32 # ' '
.int 119 # 'w'
.int 111 # 'o'
.int 114 # 'r'
.int 108 # 'l'
.int 100 # 'd'
.int 10
.int 0
.end

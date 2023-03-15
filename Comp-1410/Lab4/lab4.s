	.file	"lab4.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "lab4.c\0"
.LC1:
	.ascii "*select_max(str1) == 'o'\0"
.LC2:
	.ascii "ollhe\0"
.LC3:
	.ascii "strcmp(str1, \"ollhe\") == 0\0"
.LC4:
	.ascii "*select_max(str2) == 'u'\0"
.LC5:
	.ascii "utsrponmieeeccc\0"
	.align 8
.LC6:
	.ascii "strcmp(str2, \"utsrponmieeeccc\") == 0\0"
.LC7:
	.ascii "*select_max(str3) == 'y'\0"
.LC8:
	.ascii "yspppolecaa\0"
	.align 8
.LC9:
	.ascii "strcmp(str3, \"yspppolecaa\") == 0\0"
.LC10:
	.ascii "*select_max(str4) == 't'\0"
.LC11:
	.ascii "thec\0"
.LC12:
	.ascii "strcmp(str4, \"thec\") == 0\0"
.LC13:
	.ascii "*select_max(str5) == 'u'\0"
.LC14:
	.ascii "usnigb\0"
.LC15:
	.ascii "strcmp(str5, \"usnigb\") == 0\0"
	.align 8
.LC16:
	.ascii "All tests passed successfully.\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movl	$1819043176, -6(%rbp)
	movw	$111, -2(%rbp)
	leaq	-6(%rbp), %rax
	movq	%rax, %rcx
	call	select_max
	movzbl	(%rax), %eax
	cmpb	$111, %al
	je	.L6
	movl	$34, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L6:
	leaq	-6(%rbp), %rax
	movq	%rax, %rcx
	call	str_sort
	leaq	-6(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L9
	movl	$36, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L9:
	movabsq	$8243122740717776739, %rax
	movabsq	$28538298446734195, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	select_max
	movzbl	(%rax), %eax
	cmpb	$117, %al
	je	.L12
	movl	$39, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L12:
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	str_sort
	leaq	-32(%rbp), %rax
	leaq	.LC5(%rip), %rdx
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L15
	movl	$41, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L15:
	movabsq	$8749475255773327457, %rax
	movq	%rax, -44(%rbp)
	movl	$6648688, -36(%rbp)
	leaq	-44(%rbp), %rax
	movq	%rax, %rcx
	call	select_max
	movzbl	(%rax), %eax
	cmpb	$121, %al
	je	.L18
	movl	$44, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L18:
	leaq	-44(%rbp), %rax
	movq	%rax, %rcx
	call	str_sort
	leaq	-44(%rbp), %rax
	leaq	.LC8(%rip), %rdx
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L21
	movl	$46, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L21:
	movl	$1751344500, -49(%rbp)
	movb	$0, -45(%rbp)
	leaq	-49(%rbp), %rax
	movq	%rax, %rcx
	call	select_max
	movzbl	(%rax), %eax
	cmpb	$116, %al
	je	.L24
	movl	$49, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L24:
	leaq	-49(%rbp), %rax
	movq	%rax, %rcx
	call	str_sort
	leaq	-49(%rbp), %rax
	leaq	.LC11(%rip), %rdx
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L27
	movl	$51, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L27:
	movl	$1735289186, -56(%rbp)
	movw	$29557, -52(%rbp)
	movb	$0, -50(%rbp)
	leaq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	select_max
	movzbl	(%rax), %eax
	cmpb	$117, %al
	je	.L30
	movl	$54, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L30:
	leaq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	str_sort
	leaq	-56(%rbp), %rax
	leaq	.LC14(%rip), %rdx
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L33
	movl	$56, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC15(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L33:
	leaq	.LC16(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	swap_to_front
	.def	swap_to_front;	.scl	2;	.type	32;	.endef
	.seh_proc	swap_to_front
swap_to_front:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	movb	%al, -1(%rbp)
	movq	24(%rbp), %rax
	movzbl	(%rax), %edx
	movq	16(%rbp), %rax
	movb	%dl, (%rax)
	movq	24(%rbp), %rax
	movzbl	-1(%rbp), %edx
	movb	%dl, (%rax)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	swap_to_back
	.def	swap_to_back;	.scl	2;	.type	32;	.endef
	.seh_proc	swap_to_back
swap_to_back:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L37
.L38:
	addq	$1, 16(%rbp)
.L37:
	movl	-4(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L38
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	movb	%al, -5(%rbp)
	movq	24(%rbp), %rax
	movzbl	(%rax), %edx
	movq	16(%rbp), %rax
	movb	%dl, (%rax)
	movq	24(%rbp), %rax
	movzbl	-5(%rbp), %edx
	movb	%dl, (%rax)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	select_max
	.def	select_max;	.scl	2;	.type	32;	.endef
	.seh_proc	select_max
select_max:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	16(%rbp), %rcx
	call	strlen
	movl	%eax, -16(%rbp)
	cmpl	$0, -16(%rbp)
	jle	.L40
	movl	$0, -12(%rbp)
	jmp	.L41
.L43:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jle	.L42
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
.L42:
	addl	$1, -12(%rbp)
.L41:
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.L43
.L40:
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	str_sort
	.def	str_sort;	.scl	2;	.type	32;	.endef
	.seh_proc	str_sort
str_sort:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	32(%rbp), %rcx
	call	strlen
	subl	$1, %eax
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L46
.L47:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rcx
	call	select_max
	movq	%rbx, %rdx
	movq	%rax, %rcx
	call	swap_to_front
	addl	$1, -4(%rbp)
.L46:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L47
	nop
	nop
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev1, Built by MSYS2 project) 11.3.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef

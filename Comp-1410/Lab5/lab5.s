	.file	"lab5.c"
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
	.ascii "lab5.c\0"
.LC1:
	.ascii "check == 3\0"
	.align 8
.LC2:
	.ascii "The IDS for the students named '%s' are: \12\0"
.LC3:
	.ascii "%d\12\0"
	.align 8
.LC4:
	.ascii "strcmp(arr[2].name, name_change) == 0\0"
.LC5:
	.ascii "Assertions passed!\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$240, %rsp
	.seh_stackalloc	240
	.seh_endprologue
	call	__main
	movl	$123456, -160(%rbp)
	movabsq	$521510086978, %rax
	movl	$0, %edx
	movq	%rax, -156(%rbp)
	movq	%rdx, -148(%rbp)
	movl	$0, -140(%rbp)
	movl	$98763234, -136(%rbp)
	movabsq	$465675315280, %rax
	movl	$0, %edx
	movq	%rax, -132(%rbp)
	movq	%rdx, -124(%rbp)
	movl	$0, -116(%rbp)
	movl	$32132132, -112(%rbp)
	movabsq	$521341660994, %r10
	movl	$0, %r11d
	movq	%r10, -108(%rbp)
	movq	%r11, -100(%rbp)
	movl	$0, -92(%rbp)
	movl	$7777777, -88(%rbp)
	movq	%rax, -84(%rbp)
	movq	%rdx, -76(%rbp)
	movl	$0, -68(%rbp)
	movl	$4637568, -64(%rbp)
	movq	$1852138565, -60(%rbp)
	movq	$0, -52(%rbp)
	movl	$0, -44(%rbp)
	movl	$7843785, -40(%rbp)
	movq	%rax, -36(%rbp)
	movq	%rdx, -28(%rbp)
	movl	$0, -20(%rbp)
	movq	$0, -192(%rbp)
	movq	$0, -184(%rbp)
	movq	$0, -176(%rbp)
	movl	$1818847312, -198(%rbp)
	movw	$108, -194(%rbp)
	leaq	-192(%rbp), %rcx
	leaq	-160(%rbp), %rdx
	leaq	-198(%rbp), %rax
	movq	%rcx, %r9
	movl	$6, %r8d
	movq	%rax, %rcx
	call	find_name
	movl	%eax, -8(%rbp)
	cmpl	$3, -8(%rbp)
	je	.L6
	movl	$53, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L6:
	leaq	-198(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L7
.L9:
	movl	-4(%rbp), %eax
	cltq
	movl	-192(%rbp,%rax,4), %eax
	testl	%eax, %eax
	je	.L8
	movl	-4(%rbp), %eax
	cltq
	movl	-192(%rbp,%rax,4), %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L8:
	addl	$1, -4(%rbp)
.L7:
	cmpl	$5, -4(%rbp)
	jle	.L9
	movl	$6451010, -202(%rbp)
	leaq	-202(%rbp), %rax
	leaq	-160(%rbp), %rdx
	leaq	48(%rdx), %rcx
	movq	%rax, %rdx
	call	change_name
	leaq	-202(%rbp), %rax
	leaq	-160(%rbp), %rdx
	leaq	52(%rdx), %rcx
	movq	%rax, %rdx
	call	strcmp
	testl	%eax, %eax
	je	.L12
	movl	$63, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L12:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$240, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	find_id
	.def	find_id;	.scl	2;	.type	32;	.endef
	.seh_proc	find_id
find_id:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	%r9, 40(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L15
.L18:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, 16(%rbp)
	jne	.L16
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	leaq	4(%rax), %rdx
	movq	40(%rbp), %rax
	movq	%rax, %rcx
	call	strcpy
	movl	$1, %eax
	jmp	.L17
.L16:
	addl	$1, -4(%rbp)
.L15:
	movl	-4(%rbp), %eax
	cmpl	32(%rbp), %eax
	jl	.L18
	movl	$0, %eax
.L17:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	find_name
	.def	find_name;	.scl	2;	.type	32;	.endef
	.seh_proc	find_name
find_name:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	%r9, 40(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L20
.L22:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	addq	$4, %rax
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	jne	.L21
	addl	$1, -4(%rbp)
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	40(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
.L21:
	addl	$1, -8(%rbp)
.L20:
	movl	-8(%rbp), %eax
	cmpl	32(%rbp), %eax
	jl	.L22
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	change_name
	.def	change_name;	.scl	2;	.type	32;	.endef
	.seh_proc	change_name
change_name:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	call	strcpy
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev1, Built by MSYS2 project) 11.3.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.def	strcpy;	.scl	2;	.type	32;	.endef

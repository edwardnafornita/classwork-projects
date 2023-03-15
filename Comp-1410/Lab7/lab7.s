	.file	"lab7.c"
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
	.globl	create_node
	.def	create_node;	.scl	2;	.type	32;	.endef
	.seh_proc	create_node
create_node:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$16, %ecx
	call	malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L4
	movl	$0, %eax
	jmp	.L5
.L4:
	movq	-8(%rbp), %rax
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	strcpy
	movq	-8(%rbp), %rax
	movq	24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
.L5:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	free_node
	.def	free_node;	.scl	2;	.type	32;	.endef
	.seh_proc	free_node
free_node:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	16(%rbp), %rcx
	call	free
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	concat_nodes
	.def	concat_nodes;	.scl	2;	.type	32;	.endef
	.seh_proc	concat_nodes
concat_nodes:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	jmp	.L9
.L10:
	movq	16(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	strcat
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, 16(%rbp)
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L9
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movw	$32, (%rax)
.L9:
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L10
	nop
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "lab7.c\0"
	.align 8
.LC1:
	.ascii "strcmp(concat_expected, concat_llist) == 0\0"
.LC2:
	.ascii "%s\12\0"
	.align 8
.LC3:
	.ascii "strcmp(concat_expected2, concat_llist2) == 0\0"
	.align 8
.LC4:
	.ascii "strcmp(concat_expected3, concat_llist3) == 0\0"
	.align 8
.LC5:
	.ascii "All tests passed successfully!\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$592, %rsp
	.seh_stackalloc	592
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movabsq	$5208208757389214273, %rax
	movabsq	$5786930140093827657, %rdx
	movq	%rax, 352(%rbp)
	movq	%rdx, 360(%rbp)
	movabsq	$6365651522798441041, %rax
	movq	%rax, 368(%rbp)
	movw	$23129, 376(%rbp)
	movb	$0, 378(%rbp)
	movq	$0, 456(%rbp)
	movq	$0, 408(%rbp)
	movw	$0, 350(%rbp)
	movl	$0, 452(%rbp)
	jmp	.L12
.L13:
	movl	$26, %eax
	subl	452(%rbp), %eax
	cltq
	movzbl	352(%rbp,%rax), %eax
	movb	%al, 350(%rbp)
	movq	456(%rbp), %rdx
	leaq	350(%rbp), %rax
	movq	%rax, %rcx
	call	create_node
	movq	%rax, 408(%rbp)
	movq	408(%rbp), %rax
	movq	%rax, 456(%rbp)
	addl	$1, 452(%rbp)
.L12:
	cmpl	$26, 452(%rbp)
	jle	.L13
	movq	$0, 240(%rbp)
	movq	$0, 248(%rbp)
	movq	$0, 256(%rbp)
	movq	$0, 264(%rbp)
	movq	$0, 272(%rbp)
	movq	$0, 280(%rbp)
	movq	$0, 288(%rbp)
	movq	$0, 296(%rbp)
	movq	$0, 304(%rbp)
	movq	$0, 312(%rbp)
	movq	$0, 320(%rbp)
	movq	$0, 328(%rbp)
	movl	$0, 336(%rbp)
	movabsq	$2325018780306120769, %rax
	movabsq	$2326144697393094725, %rdx
	movq	%rax, 176(%rbp)
	movq	%rdx, 184(%rbp)
	movabsq	$2327270614480068681, %rax
	movabsq	$2328396531567042637, %rdx
	movq	%rax, 192(%rbp)
	movq	%rdx, 200(%rbp)
	movabsq	$2329522448654016593, %rax
	movabsq	$2330648365740990549, %rdx
	movq	%rax, 208(%rbp)
	movq	%rdx, 216(%rbp)
	movl	$5906521, 224(%rbp)
	leaq	240(%rbp), %rdx
	movq	456(%rbp), %rax
	movq	%rax, %rcx
	call	concat_nodes
	leaq	240(%rbp), %rdx
	leaq	176(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L16
	movl	$72, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L16:
	leaq	240(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L17
.L18:
	movq	456(%rbp), %rax
	movq	%rax, %rcx
	call	free_node
	movq	%rax, 456(%rbp)
.L17:
	cmpq	$0, 456(%rbp)
	jne	.L18
	movabsq	$7018142473656625253, %rax
	movq	%rax, 167(%rbp)
	movb	$0, 175(%rbp)
	movq	$0, 440(%rbp)
	movq	$0, 400(%rbp)
	movw	$0, 165(%rbp)
	movl	$0, 436(%rbp)
	jmp	.L19
.L20:
	movl	$9, %eax
	subl	436(%rbp), %eax
	cltq
	movzbl	167(%rbp,%rax), %eax
	movb	%al, 165(%rbp)
	movq	440(%rbp), %rdx
	leaq	165(%rbp), %rax
	movq	%rax, %rcx
	call	create_node
	movq	%rax, 400(%rbp)
	movq	400(%rbp), %rax
	movq	%rax, 440(%rbp)
	addl	$1, 436(%rbp)
.L19:
	cmpl	$9, 436(%rbp)
	jle	.L20
	movq	$0, 64(%rbp)
	movq	$0, 72(%rbp)
	movq	$0, 80(%rbp)
	movq	$0, 88(%rbp)
	movq	$0, 96(%rbp)
	movq	$0, 104(%rbp)
	movq	$0, 112(%rbp)
	movq	$0, 120(%rbp)
	movq	$0, 128(%rbp)
	movq	$0, 136(%rbp)
	movq	$0, 144(%rbp)
	movq	$0, 152(%rbp)
	movl	$0, 160(%rbp)
	movabsq	$2334307587684048997, %rax
	movabsq	$2333181700662829157, %rdx
	movq	%rax, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movb	$0, 48(%rbp)
	leaq	64(%rbp), %rdx
	movq	440(%rbp), %rax
	movq	%rax, %rcx
	call	concat_nodes
	leaq	64(%rbp), %rdx
	leaq	32(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L23
	movl	$93, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L23:
	leaq	64(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L24
.L25:
	movq	440(%rbp), %rax
	movq	%rax, %rcx
	call	free_node
	movq	%rax, 440(%rbp)
.L24:
	cmpq	$0, 440(%rbp)
	jne	.L25
	movw	$0, 30(%rbp)
	movq	$0, 424(%rbp)
	movq	$0, 392(%rbp)
	movw	$0, 28(%rbp)
	movl	$0, 420(%rbp)
	jmp	.L26
.L27:
	movl	$2, %eax
	subl	420(%rbp), %eax
	cltq
	movzbl	30(%rbp,%rax), %eax
	movb	%al, 165(%rbp)
	movq	424(%rbp), %rdx
	leaq	28(%rbp), %rax
	movq	%rax, %rcx
	call	create_node
	movq	%rax, 392(%rbp)
	movq	392(%rbp), %rax
	movq	%rax, 424(%rbp)
	addl	$1, 420(%rbp)
.L26:
	cmpl	$2, 420(%rbp)
	jle	.L27
	movq	$0, -80(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, 0(%rbp)
	movq	$0, 8(%rbp)
	movl	$0, 16(%rbp)
	movb	$0, -81(%rbp)
	leaq	64(%rbp), %rdx
	movq	424(%rbp), %rax
	movq	%rax, %rcx
	call	concat_nodes
	leaq	-80(%rbp), %rdx
	leaq	-81(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	je	.L30
	movl	$114, %r8d
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	movq	__imp__assert(%rip), %rax
	call	*%rax
.L30:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L31
.L32:
	movq	424(%rbp), %rax
	movq	%rax, %rcx
	call	free_node
	movq	%rax, 424(%rbp)
.L31:
	cmpq	$0, 424(%rbp)
	jne	.L32
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, %eax
	addq	$592, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev1, Built by MSYS2 project) 11.3.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	strcpy;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	strcat;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef

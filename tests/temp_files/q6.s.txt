	.file	"q6.c"
	.text
	.globl	wavefunction
	.type	wavefunction, @function
wavefunction:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm1
	movsd	.LC1(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	-24(%rbp), %xmm0
	addsd	-32(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	movq	.LC2(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	wavefunction, .-wavefunction
	.globl	interaction
	.type	interaction, @function
interaction:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movsd	%xmm0, -40(%rbp)
	movsd	%xmm1, -48(%rbp)
	movsd	%xmm2, -56(%rbp)
	movsd	%xmm3, -64(%rbp)
	movsd	%xmm4, -72(%rbp)
	movsd	%xmm5, -80(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %xmm0
	call	cos@PLT
	movsd	%xmm0, -88(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %xmm0
	call	cos@PLT
	movapd	%xmm0, %xmm6
	mulsd	-88(%rbp), %xmm6
	movsd	%xmm6, -88(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %xmm0
	call	sin@PLT
	movsd	%xmm0, -96(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %xmm0
	call	sin@PLT
	movapd	%xmm0, %xmm7
	mulsd	-96(%rbp), %xmm7
	movsd	%xmm7, -96(%rbp)
	movsd	-72(%rbp), %xmm0
	subsd	-80(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	cos@PLT
	mulsd	-96(%rbp), %xmm0
	addsd	-88(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	.LC0(%rip), %xmm0
	movq	-40(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movsd	%xmm0, -88(%rbp)
	movsd	.LC0(%rip), %xmm0
	movq	-48(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movsd	-88(%rbp), %xmm1
	addsd	%xmm0, %xmm1
	movsd	-40(%rbp), %xmm0
	addsd	%xmm0, %xmm0
	mulsd	-48(%rbp), %xmm0
	mulsd	-16(%rbp), %xmm0
	subsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	.LC3(%rip), %xmm0
	comisd	-24(%rbp), %xmm0
	jbe	.L4
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
.L4:
	movsd	.LC4(%rip), %xmm0
	divsd	-24(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	interaction, .-interaction
	.globl	inf
	.type	inf, @function
inf:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	.LC0(%rip), %xmm0
	movq	-24(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movsd	%xmm0, -40(%rbp)
	movsd	.LC0(%rip), %xmm0
	movq	-32(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	mulsd	-40(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	inf, .-inf
	.globl	norm_brute
	.type	norm_brute, @function
norm_brute:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movsd	.LC5(%rip), %xmm0
	movsd	%xmm0, -40(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	.LC0(%rip), %xmm0
	movq	-40(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movsd	.LC7(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	movsd	.LC8(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	$0, -52(%rbp)
	jmp	.L11
.L12:
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	-40(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	-40(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	wavefunction
	movsd	%xmm0, -80(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	inf
	mulsd	-80(%rbp), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	-48(%rbp), %xmm0
	addsd	-32(%rbp), %xmm0
	movsd	%xmm0, -48(%rbp)
	addl	$1, -52(%rbp)
.L11:
	movl	-52(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.L12
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-68(%rbp), %xmm1
	movsd	-48(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	mulsd	-24(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	norm_brute, .-norm_brute
	.globl	brute_integral
	.type	brute_integral, @function
brute_integral:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movl	%edi, -148(%rbp)
	movq	%rsi, -160(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -120(%rbp)
	movsd	.LC5(%rip), %xmm0
	movsd	%xmm0, -112(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -104(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -136(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -96(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -88(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -128(%rbp)
	movsd	-112(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	mulsd	%xmm0, %xmm1
	movsd	.LC7(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	.LC8(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -80(%rbp)
	movl	$0, -140(%rbp)
	jmp	.L15
.L16:
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm2
	movapd	%xmm0, %xmm1
	divsd	%xmm2, %xmm1
	movsd	-112(%rbp), %xmm0
	subsd	-120(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-120(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -48(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm2
	movapd	%xmm0, %xmm1
	divsd	%xmm2, %xmm1
	movsd	-112(%rbp), %xmm0
	subsd	-120(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-120(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm0
	movsd	.LC4(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	acos@PLT
	movq	%xmm0, %rax
	movq	%rax, -32(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm0
	movsd	.LC4(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	acos@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	movsd	.LC10(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	movsd	.LC10(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-40(%rbp), %xmm0
	movq	-48(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	wavefunction
	movsd	%xmm0, -168(%rbp)
	movsd	-8(%rbp), %xmm4
	movsd	-16(%rbp), %xmm3
	movsd	-24(%rbp), %xmm2
	movsd	-32(%rbp), %xmm1
	movsd	-40(%rbp), %xmm0
	movq	-48(%rbp), %rax
	movapd	%xmm4, %xmm5
	movapd	%xmm3, %xmm4
	movapd	%xmm2, %xmm3
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	interaction
	movapd	%xmm0, %xmm6
	mulsd	-168(%rbp), %xmm6
	movsd	%xmm6, -168(%rbp)
	movsd	-40(%rbp), %xmm0
	movq	-48(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	inf
	mulsd	-168(%rbp), %xmm0
	movsd	%xmm0, -104(%rbp)
	movsd	-136(%rbp), %xmm0
	addsd	-104(%rbp), %xmm0
	movsd	%xmm0, -136(%rbp)
	movsd	-104(%rbp), %xmm0
	mulsd	%xmm0, %xmm0
	movsd	-128(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -128(%rbp)
	addl	$1, -140(%rbp)
.L15:
	movl	-140(%rbp), %eax
	cmpl	-148(%rbp), %eax
	jl	.L16
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-148(%rbp), %xmm1
	movsd	-136(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -72(%rbp)
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-148(%rbp), %xmm1
	movsd	-128(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	-72(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	mulsd	%xmm0, %xmm1
	movsd	-64(%rbp), %xmm0
	subsd	%xmm1, %xmm0
	movsd	%xmm0, -56(%rbp)
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-148(%rbp), %xmm1
	movsd	-56(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	mulsd	-80(%rbp), %xmm0
	movq	-160(%rbp), %rax
	movsd	%xmm0, (%rax)
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-148(%rbp), %xmm1
	movsd	-136(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	mulsd	-80(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	brute_integral, .-brute_integral
	.globl	norm_imp
	.type	norm_imp, @function
norm_imp:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -36(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	nop
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	norm_imp, .-norm_imp
	.globl	imp_integral
	.type	imp_integral, @function
imp_integral:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movl	%edi, -132(%rbp)
	movq	%rsi, -144(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -96(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -112(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -104(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -88(%rbp)
	movsd	-88(%rbp), %xmm1
	movsd	.LC7(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	mulsd	-88(%rbp), %xmm1
	movsd	.LC11(%rip), %xmm0
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -80(%rbp)
	movl	$0, -116(%rbp)
	jmp	.L20
.L21:
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	log@PLT
	movq	%xmm0, %rax
	movq	.LC12(%rip), %xmm0
	movq	%rax, %xmm1
	xorpd	%xmm0, %xmm1
	movsd	-88(%rbp), %xmm0
	movapd	%xmm0, %xmm2
	addsd	%xmm0, %xmm2
	divsd	%xmm2, %xmm1
	movapd	%xmm1, %xmm0
	movsd	%xmm0, -48(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	log@PLT
	movq	%xmm0, %rax
	movq	.LC12(%rip), %xmm0
	movq	%rax, %xmm1
	xorpd	%xmm0, %xmm1
	movsd	-88(%rbp), %xmm0
	movapd	%xmm0, %xmm2
	addsd	%xmm0, %xmm2
	divsd	%xmm2, %xmm1
	movapd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm0
	movsd	.LC4(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	acos@PLT
	movq	%xmm0, %rax
	movq	%rax, -32(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm0
	movsd	.LC4(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	acos@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	movsd	.LC10(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	movsd	.LC10(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-40(%rbp), %xmm0
	movq	-48(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	inf
	movsd	%xmm0, -152(%rbp)
	movsd	-8(%rbp), %xmm4
	movsd	-16(%rbp), %xmm3
	movsd	-24(%rbp), %xmm2
	movsd	-32(%rbp), %xmm1
	movsd	-40(%rbp), %xmm0
	movq	-48(%rbp), %rax
	movapd	%xmm4, %xmm5
	movapd	%xmm3, %xmm4
	movapd	%xmm2, %xmm3
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	interaction
	mulsd	-152(%rbp), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	-112(%rbp), %xmm0
	addsd	-96(%rbp), %xmm0
	movsd	%xmm0, -112(%rbp)
	movsd	-96(%rbp), %xmm0
	mulsd	%xmm0, %xmm0
	movsd	-104(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -104(%rbp)
	addl	$1, -116(%rbp)
.L20:
	movl	-116(%rbp), %eax
	cmpl	-132(%rbp), %eax
	jl	.L21
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-132(%rbp), %xmm1
	movsd	-112(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -72(%rbp)
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-132(%rbp), %xmm1
	movsd	-104(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	-72(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	mulsd	%xmm0, %xmm1
	movsd	-64(%rbp), %xmm0
	subsd	%xmm1, %xmm0
	movsd	%xmm0, -56(%rbp)
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-132(%rbp), %xmm1
	movsd	-56(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	mulsd	-80(%rbp), %xmm0
	movq	-144(%rbp), %rax
	movsd	%xmm0, (%rax)
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-132(%rbp), %xmm1
	movsd	-112(%rbp), %xmm0
	divsd	%xmm1, %xmm0
	mulsd	-80(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	imp_integral, .-imp_integral
	.section	.rodata
.LC13:
	.string	"%0.4f\n"
.LC14:
	.string	"w"
.LC15:
	.string	"interaction.dat"
	.align 8
.LC16:
	.string	"Tries            Imp          Error_imp       Brute         Error_brute"
	.align 8
.LC17:
	.string	"Tries            Imp          Error_imp       Brute         Error_brute\n"
	.align 8
.LC18:
	.string	"%9d         %0.4f       %0.4f        %0.4f          %0.4f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$1000000, %edi
	call	norm_brute
	movq	%xmm0, %rax
	movq	%rax, -80(%rbp)
	movsd	.LC4(%rip), %xmm0
	divsd	-80(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	leaq	.LC13(%rip), %rdx
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$10, -48(%rbp)
	movl	$100, -44(%rbp)
	movl	$1000, -40(%rbp)
	movl	$10000, -36(%rbp)
	movl	$100000, -32(%rbp)
	movl	$1000000, -28(%rbp)
	movl	$10000000, -24(%rbp)
	leaq	.LC14(%rip), %rdx
	leaq	.LC15(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -72(%rbp)
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-72(%rbp), %rax
	leaq	.LC17(%rip), %rdi
	movq	%rax, %rcx
	movl	$72, %edx
	movl	$1, %esi
	call	fwrite@PLT
	movl	$0, -100(%rbp)
	jmp	.L24
.L25:
	movl	-100(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	leaq	-96(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	imp_integral
	movq	%xmm0, %rax
	movq	%rax, -64(%rbp)
	movl	-100(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	leaq	-88(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	brute_integral
	movq	%xmm0, %rax
	movq	%rax, -56(%rbp)
	movsd	-88(%rbp), %xmm0
	movapd	%xmm0, %xmm3
	divsd	-80(%rbp), %xmm3
	movsd	-56(%rbp), %xmm0
	movapd	%xmm0, %xmm2
	divsd	-80(%rbp), %xmm2
	movsd	-96(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	divsd	-80(%rbp), %xmm1
	movsd	-64(%rbp), %xmm0
	divsd	-80(%rbp), %xmm0
	movq	%xmm0, %rdx
	movl	-100(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	leaq	.LC18(%rip), %rcx
	movq	%rdx, %xmm0
	movl	%eax, %esi
	movq	%rcx, %rdi
	movl	$4, %eax
	call	printf@PLT
	movsd	-88(%rbp), %xmm0
	movapd	%xmm0, %xmm3
	divsd	-80(%rbp), %xmm3
	movsd	-56(%rbp), %xmm0
	movapd	%xmm0, %xmm2
	divsd	-80(%rbp), %xmm2
	movsd	-96(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	divsd	-80(%rbp), %xmm1
	movsd	-64(%rbp), %xmm0
	divsd	-80(%rbp), %xmm0
	movq	%xmm0, %rcx
	movl	-100(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %edx
	leaq	.LC18(%rip), %rsi
	movq	-72(%rbp), %rax
	movq	%rcx, %xmm0
	movq	%rax, %rdi
	movl	$4, %eax
	call	fprintf@PLT
	addl	$1, -100(%rbp)
.L24:
	cmpl	$6, -100(%rbp)
	jle	.L25
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L27
	call	__stack_chk_fail@PLT
.L27:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1073741824
	.align 8
.LC1:
	.long	0
	.long	-1073741824
	.align 8
.LC2:
	.long	-1961601175
	.long	1074118410
	.align 8
.LC3:
	.long	-640172613
	.long	1037794527
	.align 8
.LC4:
	.long	0
	.long	1072693248
	.align 8
.LC5:
	.long	0
	.long	1075052544
	.align 8
.LC7:
	.long	0
	.long	1074790400
	.align 8
.LC8:
	.long	2080276000
	.long	1078181104
	.align 8
.LC9:
	.long	0
	.long	1105199104
	.align 8
.LC10:
	.long	-1065151889
	.long	1074340298
	.align 8
.LC11:
	.long	2080276000
	.long	1080278256
	.align 16
.LC12:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.ident	"GCC: (GNU) 15.2.1 20260103"
	.section	.note.GNU-stack,"",@progbits

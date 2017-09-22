	.text
	.global zfunction
zfunction:
	pushl	%ebp
	movl	%esp, %ebp
	movl	0x8(%ebp), %eax
	and	$0xff803fff, %eax
	shl	$0x4, %eax
	pop	%ebp
	ret

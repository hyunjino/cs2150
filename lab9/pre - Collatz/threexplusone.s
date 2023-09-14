	global	threexplusone
	
	;optimizations:
	;used lea instruction instead of mul
	;xor eax instead of using a separate register for counter
	;used existing parameter registers (no pushing and popping)


	section .text

threexplusone:
	xor	eax, eax
recurse:
	cmp	edi, 1
	je	found
	test	edi, 1
	jnz	odd
	jz	even
even:	
	shr	edi, 1
	call	threexplusone
	inc	eax
	jmp	found
odd:
	lea	edi, [3*edi+1]
	call	threexplusone
	inc	eax
found:
	ret

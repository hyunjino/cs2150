	global product
	global power
	
	section .text

product:
	xor 	rax, rax 		; zero out return
	xor	r10, r10
startProd:
	cmp	r10, rsi
	je	doneProd
	add	rax, rdi
	inc	r10
	jmp	startProd
doneProd:
	ret

power:
	mov 	rax, 1
startPow:
	cmp	rsi, 0
	je	donePow
func:	
	dec	rsi
	call 	power
	mov	rsi, rax
	call	product
donePow:
	ret


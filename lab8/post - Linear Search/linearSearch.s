	global linearSearch

	section .text
	;; first parameter is pointer to int array
	;; second parameter is size of array
	;; third parameter is target integer
	;; return the index of target

linearSearch:
	mov	r10d, 0 		; make i=0
	mov	eax, -1
startLoop:
	cmp	esi, r10d
	je	endLoop
	mov	r11d, [edi + (4*r10d)] ;find location of element in memory
	cmp	r11d, edx	    ;compare target to element at index
	je	found
	inc	r10d
	jmp	startLoop
found:
	mov	eax, r10d
	jmp	endLoop
endLoop:	
	ret

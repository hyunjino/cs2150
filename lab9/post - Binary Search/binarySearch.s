; Hyunjin Kang, hk4tnh
; CS 2150 Post Lab 9
; binarySearch.s

	global binarySearch
	
	section .text
	
	;edi = int array pointer
	;esi = low
	;edx = high
	;ecx = target
	;r11d = mid

binarySearch:
	mov	eax, -1	; make return = -1 for now
	
whileLoop:
	cmp	esi, edx	; compare low and high
	jg	end		; if low>high, jump to the end
	lea	r11d, [esi+edx]; make r11d = low+high
	shr	r11d, 1	; r11d = mid
	
firstIf:
	mov	r10d,[edi+(4*r11d)]
	cmp 	ecx, r10d	; compare target and a[mid]
	jle	secondIf	; if target<=a[mid], go to the next if statement
	inc	r11d		; mid = mid+1
	mov	esi, r11d	; low = mid
	jmp	whileLoop	
	
secondIf:
	mov	r10d,[edi+(4*r11d)]
	cmp	ecx, r10d	; compare target to a[mid]
	jge	else		; if a[mid] = target, jump to else
	dec	r11d		; mid = mid-1
	mov	edx, r11d	; high = mid
	jmp	whileLoop	

else:	
	mov	eax, r11d	; return mid
	jmp	end		; jump back to while loop
end:
	ret			; return statement


.386 
PUBLIC _number_of_1
.model flat 
.data
max dword 0
.code 


_number_of_1 proc 
 
push ebp  
mov ebp,esp
pushad
mov esi, [ebp+8]

xor edi, edi
xor eax, eax
xor ecx, ecx
beg:
	mov al, [esi + edi]
	cmp al, 0
	je end_

	inc edi
	cmp al, '1'
	je inc_
	jmp beg
inc_:
	inc ecx
	jmp beg

end_:
	mov max, ecx
	popad
	mov eax, max
	pop ebp
	ret

_number_of_1 endp
end


	
	


 





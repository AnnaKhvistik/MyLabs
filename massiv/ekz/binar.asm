.386 
PUBLIC _binary
.model flat 
.code 

_binary proc  

push ebp  
mov ebp,esp
pushad
mov esi, [ebp+12]
mov eax, [ebp+8]
mov ebx, 2
xor ecx, ecx

cycle1:
	cmp eax, 0
	je end_cycle1

	xor edx, edx
	div ebx
	add edx, '0'
	mov [esi+ecx], edx
	inc ecx
	jmp cycle1

end_cycle1:

dec ecx
mov ebx, ecx
xor ecx, ecx

cycle2:
	cmp ecx, ebx
	jg end_cycle2
	push [esi+ecx]
	inc ecx
	jmp cycle2

end_cycle2:

xor ecx, ecx

cycle3:
	cmp ecx, ebx
	jg end_cycle3
	pop eax
	mov [esi+ecx], eax
	inc ecx
	jmp cycle3

end_cycle3:
	mov al, 0
	mov [esi+ecx], al
	


	popad
	pop ebp
	ret
	


_binary endp
end
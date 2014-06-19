.386 
PUBLIC _proc
.model flat
.data
arr db "        "
maxkol dw 0
maxind dw 0
.code 
EXTRN _binary:proc
EXTRN _number_of_1:proc

_proc proc  

push ebp  
mov ebp,esp
pushad
mov esi, [ebp+8]
xor ecx, ecx
xor ebx, ebx
xor eax, eax
beg:
	cmp ecx, [ebp + 12]
	je end_

	 lea edi, arr
	 mov eax, [esi + ecx*4]
	 push edi
	 push eax
	 call _binary
	 pop eax
	 pop edi
	 push edi
	 call _number_of_1
	 add esp, 4

	 cmp eax, ebx
	 jg change
	 inc ecx
	 jmp beg
	 
change:
	mov bx, ax
	mov maxind, cx
	inc ecx
	jmp beg

end_:
	
	popad
	mov ax, maxind
	pop ebp
	ret

	


_proc endp
end
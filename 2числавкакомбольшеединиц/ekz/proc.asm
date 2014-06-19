.386 
PUBLIC _proc
.model flat
.data
arr db "0123456789ABCDEF"
n1 dword 0
n2 dword 0
.code 
EXTRN _binary:proc
EXTRN _number_of_1:proc

_proc proc  

push ebp  
mov ebp,esp
pushad
mov eax, [ebp+8]
 lea esi, arr
 push esi
 push eax
 call _binary
 pop eax
 pop esi
 push esi
 call _number_of_1
 add esp, 4
 mov n1, eax

 mov eax, [ebp+12]
 lea esi, arr
 push esi
 push eax
 call _binary
 pop eax
 pop esi
 push esi
 call _number_of_1
 add esp, 4
 mov n2, eax

mov eax, n1
cmp eax, n2
jge endt
	popad
	mov eax, 0
	pop ebp
	ret

endt:
	popad
	mov eax, 1
	pop ebp
	ret

	


_proc endp
end
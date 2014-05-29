.386 
PUBLIC _check
.model flat 
.data 
row dword 0
col dword 0
block_row dword 0
block_col dword 0
.code 

_check proc  

push ebp  
mov ebp,esp
pushad

;ebp + 12  = cell    ebp + 16 = value  ebp + 8 = F
mov esi, [ebp+8]

	;int row = 9 * (cell/9);   36
mov eax, [ebp + 12]
mov ebx, 9
cdq  
div ebx
mul ebx
mov row, eax

	;int col = cell%9;   5
mov eax, [ebp + 12]
xor edx, edx
cdq  
div ebx
mov col, edx

	;int block_row = (row/27)*27;    27
mov eax, row
mov ebx, 27
cdq
div ebx
mul ebx
mov block_row, eax

	;int block_col = (col/3)*3;   3
mov eax, col
mov ebx, 3
cdq
div ebx
mul ebx
mov block_col, eax

mov edx, [ebp + 16]
	;for( int i = 0; i < 9; i++) 
	;	if(F[row+i] == value) return false;

xor ecx, ecx
mov ebx, row
begin1:
	cmp ecx, 9
	jge end1
	cmp edx, [esi + ebx*4]
	je rfalse
	inc ebx
	inc ecx
	jmp begin1
end1:

	;for( int i = 0; i < 9; i++) 
	;	if(F[col+(i*9)] == value) return false;

xor ecx, ecx
begin2:
	cmp ecx, 9
	jge end2
	mov ebx, col
	mov eax, ecx
	mov edi, 9
	mul edi
	add ebx, eax

	mov edx, [ebp + 16]
	cmp edx, [esi + ebx*4]
	je rfalse
	inc ecx
	jmp begin2
end2:

	;for(int i = 0; i < 3; i++)
	;	if (F[block_row+block_col+i] == value) return false;
mov ecx, 0
mov edx, block_row
add edx, block_col
mov ebx, [ebp + 16]
begin3:
	cmp ecx, 3
	jge end3
	cmp ebx, [esi + edx*4]
	je rfalse
	inc ecx
	inc edx
	jmp begin3
end3:

	;for(int i = 0; i < 3; i++)
	;	if (F[(block_row + 9)+block_col+i] == value) return false;

mov ecx, 0
mov edx, block_row
add edx, block_col
add edx, 9
begin4:
	cmp ecx, 3
	jge end4
	cmp ebx, [esi + edx*4]
	je rfalse
	inc ecx
	inc edx
	jmp begin4
end4:

	;for(int i = 0; i < 3; i++)
	;	if (F[(block_row + 18) +block_col+i] == value) return false;
mov ecx, 0
mov edx, block_row
add edx, block_col
add edx, 18
begin5:
	cmp ecx, 3
	jge end_
	cmp ebx, [esi + edx*4]
	je rfalse
	inc ecx
	inc edx
	jmp begin5
 
 rfalse:
	popad
	pop ebp
	mov eax, 0
	ret

end_:
	
	popad
	pop ebp
	mov eax, 1
	ret
 
 
_check endp 



		PUBLIC _finish
		_finish proc

		push ebp 
		mov ebp,esp
		pushad 
		mov esi, [ebp+8]
			


		;	for(int i = 0; i < 81; i++)
		;		if(F[i] == 0) return false;
		;	return true;

		xor ecx, ecx
		begin_:
			cmp ecx, 81
			je end_
			mov ebx, [esi + ecx*4]
			cmp ebx, 0
			je metka1
			inc ecx
			jmp begin_
		metka1:
			popad
			pop ebp
			mov eax, 0
			ret
		end_:
			popad
			pop ebp
			mov eax, 1
			ret



		_finish endp
end  
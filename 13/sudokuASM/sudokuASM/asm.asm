.386
PUBLIC _findMin
.model flat
.data
 count dword 0
  min_ dword 9
  minI dword 0
  tempECX dword 0
.code
	
EXTRN _check :proc
EXTRN _finish :proc

 _findMin proc

 push ebp
 mov ebp, esp
 pushad
 mov esi, [ebp + 8]

 mov eax, 9
 mov min_, eax
 mov eax, 0
 mov minI, eax
	
	;for(int i = 0; i < 81; i++)
	;	{
	;		count = 0;
	;		if(F[i] == 0)
	;		{
	;		for(int k = 1 ; k <= 9; k++)
	;				if(check(F, i, k))
	;					count++;
	;
	;			if(count < min_){
	;			
	;			min_ = count;
	;			minI = i;
	;			
	;			}
	;		if( min_ == 1) return minI;
	;		}
	;		
	;		}
	;return minI;

	;for(int i = 0; i < 81; i++)
	xor ecx, ecx
beg:
	cmp ecx, 81
	je end_

	xor ebx,ebx ;  	count = 0;
	mov count, ebx

	;if(F[i] == 0)
	mov tempECX, ecx
	mov edx, [esi + ecx*4]
	cmp edx, 0  
	jne met1

	;		for(int k = 1 ; k <= 9; k++)
	;				if(check(F, i, k))
	;					count++;

	mov ecx, 1
beg_:
	cmp ecx, 9
	jg met2

	push ecx
	push tempECX
	push esi

	call _check
	add esp, 12

	inc ecx
	cmp eax, 0
	je beg_

	inc ebx
	mov count, ebx
	jmp beg_

met2:
	;			if(count < min_){
	;			
	;			min_ = count;
	;			minI = i;
	;			
	;	}

	cmp ebx, min_
	jl met3
	jmp met5
met3:
	mov min_, ebx
	mov edx, tempECX
	mov minI, edx

	;if( min_ == 1) return minI
	cmp ebx, 1
	jne met5
	popad
	pop ebp
	mov eax, minI
	ret
met5:
	mov ecx, tempECX
	inc ecx
	jmp beg

met1:
	inc ecx
	jmp beg

	end_:
		popad
		pop ebp
		mov eax, minI
		ret
	
_findMin endp 



PUBLIC _fill_
_fill_ proc



;bool fill_(int *F)
;{
;	if(finish(F)) return true;
;	int cell = findMin(F);
;	for (int value = 1; value < 10; value++)
;	{
;		if (check(F, cell, value))
;		{
;			F[cell] = value;
;			if(fill_(F)) 
;					return true;
;			F[cell] = 0;
;		}
;		
;	}
;	return false;
				
;}


	 push ebp
	 mov ebp, esp 
	 pushad
	 sub esp, 4  ; memory for cell
	 mov esi, [ebp + 8]  ; F
	  ; call, registr, ebp

	  push esi
	  call _finish ; eax = 1 - end   =0 - continue
	  add esp, 4
	 cmp eax, 0
	 jg end_

	 push esi
	 call _findMin
	 add esp, 4
	 mov [esp], eax

	 mov ecx, 1
beg:
	 cmp ecx, 10
	 je end_false

		mov ebx, [esp]
		push ecx
	    push ebx
		push esi
		call _check
		add esp, 12

		cmp eax, 0
		je mtk

		mov ebx, [esp]
		mov [esi + ebx*4], ecx

		push esi
		call _fill_
		add esp, 4

		cmp eax, 0
		jg end_true

		xor edx, edx
		mov ebx, [esp]
		mov [esi + ebx*4], edx

		inc ecx
		jmp beg

end_:
	add esp, 4
	popad
	pop ebp
	mov eax, 1
	ret

end_false:
	add esp, 4
	popad
	pop ebp
	mov eax, 0
	ret

mtk:
	inc ecx
	jmp beg

end_true:
	add esp, 4
	popad
	pop ebp
	mov eax, 1
	ret

  





 _fill_ endp


end  
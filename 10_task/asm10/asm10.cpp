#include<iostream>
using namespace std;

int main()
{
int n;
int k = 2;
cout <<"Enter n:" << endl;
cin >> n;

double x, a;
cout <<"Enter x:" << endl;
cin >> x ;
cout <<"Enter a:" << endl;
cin >> a;

double multiplier, divider, multiplier1;
int nplus1;
double result;
int fact;
int counter;
_asm
{
	
	
		fld x
		fadd a
		fst multiplier 
		fstp multiplier1 
		mov ebx, n
		add ebx, 1
		mov nplus1, ebx
		mov ecx, 1
		mov eax, 1
beg_:
	cmp ecx, ebx
		JG end_
		mul ecx
		inc ecx
		jmp beg_
end_:
	mov fact, eax

		fild fact
		fstp divider

		fld1
		
		mov ecx, 1
		mov eax, n
		mul k
		
beg:
	cmp ecx, eax
		JG finish
		fmul multiplier 
		fdiv divider

		mov counter, ecx
		fild counter
		fild nplus1
		faddp st(1), st(0)
		fld divider
		fmulp st(1), st(0)
		fstp divider

		fld multiplier
		fmul multiplier1
		fstp multiplier

		inc ecx
		jmp beg
finish:
	fst result
	}

cout << result;

}
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

double multiplier, multiplier1;
int fact = 1;
double result;
int counter;
_asm
{	
		fld x
		fadd a
		fst multiplier 
		fstp multiplier1 

		fld1
		
		mov ecx, 1
		mov eax, n
		mul k
		
beg:
	cmp ecx, eax
		JG finish
		fmul multiplier 
		fidiv fact

		fild fact
		mov counter, ecx
		fild counter
		fld1
		faddp st(1), st(0)
		fmulp st(1), st(0)
		fistp fact

		fld multiplier
		fmul multiplier1
		fstp multiplier

		inc ecx
		jmp beg
finish:
	fst result
	}

cout << result;
return 0;

}
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	cout << "Enter the number of elements:" << endl;
	int n ;
	cin >> n;
	cout << "Enter the array elements in ascending:" << endl;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Enter the number: " << endl;
	int num;
	cin >> num;
	int index;
	_asm
	{
		mov ebx, arr //base
			xor esi,esi //index
			mov ecx, n //counter
			xor edx, edx//temp index

beg:

		mov eax, [ebx][esi * 4]
		cmp eax, num
			jg greater
			cmp eax, num
			je eq_
			mov edx, esi
			inc esi
			loop beg
greater:
		mov index, edx
			;
		
eq_:
		mov index, esi
			jmp finish
			;
finish:
		;
	}
	cout << "Entered element's index: " << endl << index << endl;
	
}
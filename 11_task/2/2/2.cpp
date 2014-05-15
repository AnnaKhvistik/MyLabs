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
		
			mov ebx, arr 
			xor esi,esi 
			mov edi,n 

beg:
			cmp esi, edi
			jge res
			mov eax, esi
			add eax, edi
			sar eax, 1
			mov edx, [ebx][eax * 4]
			cmp edx, num
				jg met
				mov esi, eax
				inc esi
				jmp beg
met:
			mov edi, eax
				jmp beg
				;
res:
			dec edi
			mov edx, [ebx][edi * 4]
			cmp edx, num
				JNE notfound
				mov index, edi
				jmp fin
				;
notfound:
			inc edi
				mov index, edi
				;
fin:
			;

	}
	cout << "Entered element's index: " << endl << index << endl; 
	return 0;
}

			
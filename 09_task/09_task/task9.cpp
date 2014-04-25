#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	if(num <= 0) 
	{
		cout <<"Enter natural number" << endl;
		exit(1);
	}
	int sum = 0;
	int result = 0;
	int a = 2;

	_asm
	{
		mov eax, num
			mov edx, 0
			div a
			cmp eax, 0
			JE eq_
			mov ebx, sum
			mov ecx, eax 
beg:
		mov eax, num
			mov edx, 0
			div ecx 
			cmp edx, 0 
			JNE not_eq 
			add ebx, ecx 
not_eq: 
		;
		loop beg 
			cmp ebx, num
			JNE not_eq1
			mov result, 1
not_eq1:
		;
eq_:
		;
	}

	if(result == 1) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;

}
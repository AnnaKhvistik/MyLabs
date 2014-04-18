#include<iostream>
using namespace std;
int main()
{
	int num1, num2, result;
	cin >> num1 >> num2;
	_asm
	{
		mov eax, num1
			add eax, num2
			mov result, eax
	}
	cout << result << endl;
}
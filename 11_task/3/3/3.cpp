#include <iostream>
using namespace std;
void print(int *M, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j< m; j++)
			cout << *(M + i*n + j) << " ";
		cout << endl;
	}

}
int main()
{
	int M[3][4] = {{100,2,33,4},{5,6000,77,8},{900,10,11,1200}};
	int n=3, m=4;

	print(&M[0][0], n, m);

	__asm 
	{ 
		   mov eax,n
			   mul m  
			   mov ecx,eax  ; количество элементов массива 
			   xor esi,esi  ; индекс 
begin_: 
		   cmp esi, ecx
			   jge finish
			   mov edx, M[esi*4]
		  not edx
			  
			  mov M[esi*4], edx
		   inc esi
		
		jmp begin_
finish:
		   ;
	} 

	cout << endl;
	print(&M[0][0], n, m);
}
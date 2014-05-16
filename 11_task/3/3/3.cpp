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
	int M[2][2] = {{100,2},{5,600}};
	int n=2, m=2;

	print(&M[0][0], n, m);

	int mSize=m*sizeof(int);  
	__asm
	{   lea ebx,M ;   
		mov ecx,n ; 
begin_n:
	push  ecx ; 
		mov ecx,m ; 
		xor esi,esi ; 
begin_m:   
	mov edx, [ebx][esi*4]
	not edx
		mov [ebx][esi*4], edx
		inc esi 
		loop begin_m
		add ebx,mSize 
		pop ecx 
		loop begin_n 
	}


	cout << endl;
	print(&M[0][0], n, m);
}
#include<iostream>
using namespace std;

int len (char *str)
{
	int l=0;
	__asm
	{
		cld
			mov edi, str
			mov esi, edi
			mov ecx, 0ffffffffh
			xor al, al
			repne scasb
			sub edi, esi
			dec edi
			mov l, edi
	}
	return l;
}
int main()
{
	char str1[100], str2[100], result[100] = "";
	fgets(str1, 100, stdin);
	fgets(str2, 100, stdin);
	int len1 = len(str1);
	int len2 = len(str2);



	_asm
	{
			cld
			lea esi, str1
			xor ebx, ebx
			xor edx, edx
beg:
		cmp ebx, len1
			je end_
			lea edi, str2
			mov ecx, len2
			inc ecx
			mov al, str1[ebx]
		repne scasb
			jecxz not_in_str2
			lea edi, result
			mov ecx, edx
			inc ecx

			repne scasb
			jecxz not_in_result

not_in_str2:
		inc ebx
			jmp beg
			;
not_in_result:
			mov result[edx], al
				inc edx
				;
		inc ebx
			jmp beg
end_:
		;
	}




	cout << result;
}
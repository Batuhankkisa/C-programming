#include <stdio.h>
int main()
{
	char ch;
	printf("karakter giriniz: ");
	scanf("%c",&ch);
	
	if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
{
		switch(ch)
	{
			case 'A':
			case 'E':
			case 'I':
			case '�':
			case 'O':
			case '�':
			case 'U':
			case '�':
			case 'a':
			case 'e':
			case '�':
			case 'i':
			case 'o':
			case '�':
			case 'u':
			case '�':
			printf("%c seslidir.\n",ch);
			break;
			default:
				printf("%c sessizdir.\n",ch);
		} }
	else
	{
		printf("%c alfabe degil.\n",ch);
	} return 0;
}


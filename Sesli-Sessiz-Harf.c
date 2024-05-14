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
			case 'Ý':
			case 'O':
			case 'Ö':
			case 'U':
			case 'Ü':
			case 'a':
			case 'e':
			case 'ý':
			case 'i':
			case 'o':
			case 'ö':
			case 'u':
			case 'ü':
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


#include <stdio.h>
int main()
{
	int sayi,i;
	long int fact;
	printf("bir sayi giriniz: ");
	scanf("%d",&sayi);
	fact=1;
	for(i=sayi; i>=1; i--)
	fact=fact*i;
	printf("\n %d faktoriyeli = %ld",sayi,fact);
return 0;
}

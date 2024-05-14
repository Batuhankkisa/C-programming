#include <stdio.h>
#include <stdlib.h>
void main()
{
	FILE *d;
	d=fopen("sonuc.txt","w");
	if (d == NULL)
		printf("Surucu bulunamadi.\n");
	else
	{
		int i,n,a,b,c;
		scanf("%d",&n);
		i=1;
		a=0;
		b=1;
		while(i<=n)
		{
			printf("%d ",a);
			fprintf(d,"%d ",a);
			c = a + b;
			a = b;
			b = c;
		i++;
	}
	puts("basarili");
	fclose(d);
	}
}

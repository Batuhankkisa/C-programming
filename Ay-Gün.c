#include <stdio.h>
int main()
{
	int ay, gun;
	printf("Ay giriniz ");
	scanf("%d",&ay);
	switch(ay)
	{
		case 4:
		case 6:
		case 9:
		case 11:
			gun=30;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			gun=31;
			break;
		case 2:
		gun=28;
		break;
		default:
			gun=0;
			break;
}
	if(gun)
		printf("%d. ay %d gun ceker \n",ay,gun);
	else
		printf("Yalnis girdi yaptiniz!!!\n");
return 0;}

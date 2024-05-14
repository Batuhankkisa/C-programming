#include <math.h>
#include <stdio.h>
int main() {
	double a, b, c, discriminant, kok1, kok2, realPart, imagPart;
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);
	discriminant = b * b - 4 * a * c
	
	if (discriminant > 0) {
		kok1 = (-b + sqrt(discriminant)) / (2 * a);
		kok2 = (-b - sqrt(discriminant)) / (2 * a);
		printf("root1 = %.2lf and root2 = %.2lf", kok1, kok2);
	}
	else if (discriminant == 0) {
		kok1 = kok2 = -b / (2 * a);
		printf("root1 = root2 = %.2lf;", kok1);
	}
	else {
		realPart = -b / (2 * a);
		imagPart = sqrt(-discriminant) / (2 * a);
		printf("kök1 = %.2lf+%.2lfi ve kök2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
	}
return 0;
}


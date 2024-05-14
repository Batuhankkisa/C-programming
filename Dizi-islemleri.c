#include <stdio.h>
#include <stdlib.h>

int main() {
	int A[5];
	int B[5];
	int C[5];
	int i;
	for (i=0;i<5;i++){
		printf("A dizisi icin %d. degeri giriniz: ", i+1);
		scanf("%d", &A[i]);
		printf("B dizisi icin %d. degeri giriniz: ", i+1);
		scanf("%d", &B[i]);
		C[i] = A[i] + B[i];
	}
	printf("\nC = {\t");
	for (i=0;i<5;i++){
		printf("%d\t", C[i]);
	}
	printf("}");
	return 0;
}

#include <stdio.h>

typedef struct {
	int *data;
	int top;
	int size;
}stack;

int isFull(stack *stk){
	return (stk->top == stk->size -1) ? 1 : 0;
}

int isEmpty(stack *stk){
	return (stk->top == -1) ? 1 : 0;
}

int push(stack *stk, int deger){
	int i;
	if (isFull(stk)== 1){
		printf("\nStack alani dolu.\n");
	}
	else {
		for (i=0;i<=3;i++){
			printf("%d\n", stk->data[i]);
		}
		stk->top++;
		stk->data[stk->top] = deger;
		printf("Stack'e deger yerlestirildi.\n");
	}
}

int pop(stack *stk){
	if (isEmpty(stk) == 0){
		printf("\nStack alani bos.");
	}
	else {
		int k = stk->top--;
		printf("Stack'ten deger cikartildi.\n");
		return k;
	}
}

int push2(stack *stk, int deger){
	int i, p;
	if (isFull(stk)== 1){
		printf("\nStack alaný dolu.\n");
	}
	else {
		stk->top++;
		stk->data[stk->top] = deger;
		printf("Stack'e deger yerlestirildi.\n");
		for (i=0;i<=4;i++){
			stk->data[i] = p;
			printf("%d", p);
		}
	}
}

int pop2(stack *stk){
	if (isEmpty(stk) == 1){
		printf("\nStack alani bos.");
	}
	else {
		int k = stk->top--;
		printf("Stack'ten cikarma islemi yapiliyor.\n");
		return k;
	}
}

int stk_goster(stack *stk){
	int i;
	for (i=0;i<=3;i++){
			printf("%d\n", stk->data);
		}
}

int main() {
	int islem_cevap, eklenecek_deger, k;
	stack s1;
	stack s2;
	s1.size = 4;
	s2.size = 4;
	printf("Sistem baslatildi.\n");
	printf("1:Stack1 deger ekle.\n2:Stack1 deger cikar.\n3:Stack2 deger ekle.\n4:Stack2 deger cikar.\n5:Stack goster.\n");
	printf("Yapmak istediginiz islemi girin: ");
	scanf("%d", &islem_cevap);
	switch (islem_cevap){
		case 1:
			printf("Stack'e eklenecek deger giriniz: ");
			scanf("%d", &eklenecek_deger);
			push(&s1, eklenecek_deger);
			stk_goster(&s1);
			break;
		case 2:
			k = pop(&s1);
			stk_goster(&s1);
			break;
		case 3:
			printf("Stack'e eklenecek deger giriniz: ");
			scanf("%d", &eklenecek_deger);
			push2(&s2, eklenecek_deger);
			stk_goster(&s2);
			break;
		case 4:
			k = pop2(&s2);
			stk_goster(&s2);
			break;
		case 5:
			stk_goster(&s1);
			stk_goster(&s2);
			break;
		default :
			printf("HATA!");
			break;
	}
	return 1;
}

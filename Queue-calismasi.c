#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int arr[SIZE];
int rear, front, i;

int main() {
	int system_num, num;
	drwLine();
	printf("\n(1): Eleman Ekle\n(2): Eleman Cikar\n(3): Diziyi Goster\n(4): Cikis Yap\n");
	drwLine();
	printf("\nLutfen yapmak istediginiz islem numarasi giriniz: ");
	scanf("%d", &system_num);
	switch (system_num){
		case 1:
			printf("Lutfen eklemek istediginiz elemani giriniz: ");
			scanf("%d", &num);
			enqueue(num);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			dispArr();
		case 4:
			printf("Sistemden cikis yapildi.");
			return 0;
		default:
			printf("Hatali islem numarasi girdiniz.");
			return 0;
	}
	return 0;
}

int isFull(){
	if (rear == SIZE){
		return 1;
	}
	else {
		return 0;
	}
}

int isEmpty(){
	if (front < 0 || front > rear){
		return 1;
	}
	else {
		return 0;
	}
}

int enqueue (int data){
	if (isFull()){
		printf("Kuyruk dolu durumdadir.");
		return 0;
	}
	arr[rear] = data;
	rear += 1;
	dispArr();
	main();
}

int dequeue (){
	if (isEmpty()){
		printf("Kuyruk bos durumdadir.");
		return 0;
	}
	int data = arr[front];
	arr[front] = 0;
	front += 1;
	dispArr();
	main();
	return data;
}

int drwLine (){
	for (i=1;i<=10;i++){
		printf("--");
	}
}

int dispArr (){
	drwLine();
	printf("\nKuyruk:");
	for (i=0;i<SIZE;i++){
		printf("\t%d", arr[i]);
	}
	printf("| front: %d - rear: %d", arr[front], arr[rear]);
	printf("\n");
	drwLine();
	printf("\n");
}

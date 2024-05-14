#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *ekle(struct node *head){
	int addval;
	printf("Eklenecek degeri giriniz: ");
	scanf("%d", &addval);
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = addval;
	temp->next = head;
	head = temp;
}

struct node *cikar(struct node *head){
	if (head == NULL){
		printf("Stack'te hucre/veri yok!");
		return;
	}
	struct node *temp = head;
	head = head->next;
	free(temp);
	return head;
}

void goster(struct node *head){
	if (head == NULL){
		printf("Stack'te hucre/veri yok!");
	}
	else {
		while (head != NULL){
		printf("[ %d ]\n", head->data);
		head = head->next;
		}
	}
	
}

int main(){
	int deger, islem;
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	printf("Stack'in ilk hucresine yerlestirilecek deger nedir? ");
	scanf("%d", &deger);
	head->data = deger;
	head->next = NULL;
	while (1){
		printf("\n##############################");
		printf("\n# 1- Stack'e eleman ekle.    #");
		printf("\n# 2- Stack'ten eleman cikar. #");
		printf("\n# 3- Stack'i goster.         #");
		printf("\n# 4- Cikis.                  #");
		printf("\n##############################");
		printf("\nIslem numarasi giriniz: ");
		scanf("%d", &islem);
		switch (islem){
			case 1:
				head = ekle(head);
				break;
			case 2:
				head = cikar(head);
				break;
			case 3:
				goster(head);
				break;
			case 4:
				exit(1);
				break;
		}
	}
}

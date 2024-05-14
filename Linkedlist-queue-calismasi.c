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
	temp->next = NULL;
	struct node *temp2 = head;
	while (temp2->next != NULL){
		temp2 = temp2->next;
	}
	temp2->next = temp;
	return head;
}

struct node *cikar(struct node *head){
	if (head == NULL){
		printf("Kuyrukta hucre/veri yok!");
		return;
	}
	struct node *temp = head;
	head = head->next;
	free(temp);
	return head;
}

void goster(struct node *head){
	if (head == NULL){
		printf("Kuyrukta hucre/veri yok!");
	}
	else {
		while (head != NULL){
		printf("[ %d ]\t", head->data);
		head = head->next;
		}
	}
	
}

int main(){
	int deger, islem;
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	printf("Kuyrugun ilk hucresine yerlestirilecek deger nedir? ");
	scanf("%d", &deger);
	head->data = deger;
	head->next = NULL;
	while (1){
		printf("\n##############################");
		printf("\n# 1- Kuyruga eleman ekle.    #");
		printf("\n# 2- Kuyruktan eleman cikar. #");
		printf("\n# 3- Kuyrugu goster.         #");
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

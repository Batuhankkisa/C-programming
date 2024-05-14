#include <stdio.h> 
#include <stdlib.h>

struct node {
      int data;
      struct node* next;
      struct node* prev;
};

struct node* head = NULL;

struct node *addFirst(struct node *head);
struct node *addLast(struct node *head);
struct node *addSel (struct node *head);
struct node *rmvFirst (struct node *head);
struct node *rmvLast (struct node *head);
struct node *rmvselNode (struct node *head);
struct node *dispNode (struct node *head);

int main(){
	int vote;
	do {
		printf("\n\t##########################\n");
		printf("\t# 0) Dugumleri goster.   #\n");
		printf("\t# 1) Basa ekle.          #\n");
		printf("\t# 2) Sona ekle.          #\n");
		printf("\t# 3) Secili yere ekle.   #\n");
		printf("\t# 4) Bastan sil.         #\n");
		printf("\t# 5) Sondan sil.         #\n");
		printf("\t# 6) Secili yerden sil.  #\n");
		printf("\t# 7) Cikis               #\n");
		printf("\t##########################\n");
		printf("\tIslem numarasi giriniz: ");
		scanf("%d", &vote);
		switch (vote){
			case 0:
				head = dispNode(head);
				break;
			case 1:
				head = addFirst(head);
				head = dispNode(head);
				break;
			case 2:
				head = addLast(head);
				head = dispNode(head);
				break;
			case 3:
				head = addSel(head);
				head = dispNode(head);
				break;
			case 4:
				head = rmvFirst(head);
				head = dispNode(head);
				break;
			case 5:
				head = rmvLast(head);
				head = dispNode(head);
				break;
			case 6:
				head = rmvselNode(head);
				head = dispNode(head);
				break;
			case 7:
				return 0;
			}
		} while(vote != 7);
	getch();
    return 0;
}

struct node *addFirst(struct node *head){
      struct node *temp;
      int addval;
      printf("\tEklemek istediginiz veriyi giriniz: ");
      scanf("%d", &addval);
      if (head == NULL){ // Herhangi bir dugum yoksa, bu kosula girilecek.
      		head = (struct node *)malloc(sizeof(struct node));
            head->data = addval; // Kullanicidan alinan deger, eklenen dugumun data kismina eklendi.
            head->next = NULL; // Bas dugumun nexti null olmali.
            head->prev = NULL; // Bas dugumun previ null olmali.
      }
      else {
      		struct node *temp = (struct node*)malloc(sizeof(struct node)); // Temp ile yeni dugum olusturuldu.
            temp->data = addval; // Yeni temp dugumunun verisine, kullanicidan alinan deger girilecek.
            temp->next = head; // Yeni temp dugumunun nexti, eklemeden onceki ilk dugume gonderilecek.
            temp->prev = NULL; // Yeni temp dugumunun previ, null olmali.
            head->prev = temp; // Eklemeden onceki head dugumunun previ, eklenen yeni dugumu isaret etmeli.
			head = temp; // Yeni bas dugumumuz, eklenen temp dugumu olmali.
      }
      return head;
}

struct node *addLast (struct node *head){
      struct node *temp, *temp2;
      int addval;
	  printf("\tEklemek istediginiz veriyi giriniz: ");
      scanf("%d", &addval);
      if (head == NULL){ // Herhangi bir dugum yoksa, bu kosula girilecek.
            head = (struct node*)malloc(sizeof(struct node)); // Dugum olusturuldu.
            head->data = addval; // Kullanicidan alinan deger, eklenen dugumun data kismina eklendi.
            head->next = NULL; // Bas dugumun nexti null olmali.
            head->prev = NULL; // Bas dugumun previ null olmali.
      }
      else {
            struct node *temp = head; // Bas dugume, temp denildi.
            struct node *temp2 = (struct node*)malloc(sizeof(struct node)); // Temp2 ile yeni dugum olusturuldu.
            while (temp->next != NULL){ // Tempin nexti null olmadigi surece devam edecek.
                  temp = temp->next; // Donguleri dolaniyoruz.
            }
            temp2->data = addval; // Yeni eklenen temp2'nin veri kýsmýna, kullanicidan alinan deger verildi.
            temp2->next = NULL; // Yeni eklenen temp2'nin nexti null olmali. Sona ekledigimiz icin.
            temp2->prev = temp; // Yeni eklenen temp2'nin previ temp'i gostermeli. Yani eklemeden onceki son dugumu.
            temp->next = temp2; // Eklemeden onceki son dugum olan temp'in nexti ise yeni eklenen temp2 oldu.
      }
      return head;
}

struct node *addSel (struct node *head){
	struct node *temp, *temp2;
	int addval, sel, i;
	temp = (struct node*)malloc(sizeof(struct node));
	temp2 = head;
	printf("\tVerinin eklenecegi sirayi giriniz: ");
	scanf("%d", &sel);
	for (i=1;i<sel;i++){
		temp2 = temp2->next; // Dugumleri dolastik.
		if (temp2 == NULL){ // Ustte temp'in devamý temp oldu. Temp null ise, yani birden fazla dugum yoksa, hata mesaji verecektir.
			printf("\tGirilen sira bulunamadi.");
			return;
		}
	}
	printf("\tEklemek istediginiz veriyi giriniz: ");
	scanf("%d", &addval);
	temp->data = addval; // Girilen veri temp2 dugumune eklendi.
	temp->next = temp2->next; // Temp2'nin nexti, temp'in nextine baglandi.
	temp->prev = temp2; // Temp2'nin previ ise temp'e baglandi. [temp] <- [temp2]
	temp2->next = temp; // Temp'in nexti, temp2'ye baglandi. [temp] -> [temp2]
	temp2->next->prev = temp; // Temp'in nexti'nin previne temp baglandi. [temp] -> (<-) [temp2]
	return head;
}

struct node *rmvFirst (struct node *head){
	struct node *temp;
	if (head == NULL){ // Dugum yoksa;
		printf("\tDugum bulunmamaktadir."); // hata mesaji verecektir.
	}
	else if (head->next == NULL){ // Tek dugum varsa;
		head = NULL; // Bas dugum null yapildi.
		free(head); // Free edildi.
	}
	else {
		temp = head; // temp head oldu.
		head = head->next; // Bas dugum, bas dugumun bir sonraki dugumu oldu.
		head->prev = NULL; // Son durumdaki bas dugumun previ null yapildi.
		free(temp); // Free edildi.
	}
	return head;
}

struct node *rmvLast (struct node *head){
	struct node *temp;
	if (head == NULL){ // Dugum yoksa;
		printf("\tDugum bulunmamaktadir."); // hata mesaji verecektir.
	}
	else if (head->next == NULL){ // Tek dugum varsa;
		head = NULL; // Bas dugum null yapildi.
		free(head); // Free edildi.
	}
	else {
		temp = head;
		while (temp->next != NULL){ // Dongu ile dugumleri dolastik.
			temp = temp->next; // Dugum dolastik.
		}
		temp->prev->next = NULL; // temp'nin previnin nextini null'a bagladik.
		free(temp); // Free edildi.
	}
	return head;
}

struct node *rmvselNode (struct node *head){
	struct node *temp = head;
	int rmvval;
	if (head == NULL){
		printf("\tDugum bulunmamaktadir.");
		return;
	}
	printf("\tSilmek istediginiz dugumun verisini giriniz: ");
	scanf("%d", &rmvval);
	if (head->data == rmvval){ // Elde bulunan tek dugumun verisi silinecek dugum verisine esit ise yurutulecek.
		head = head->next; // Bas dugum, bas dugumden bir sonraki oldu.
		head->prev = NULL; // Bas dugumun son halinde, previ null yapildi. Bu durumda gerideki dugum kirilmis oldu.
		free(temp); // Free edildi.
	}
	else {
		while (temp->data != rmvval){ // Silinecek dugumun verisine gelene dek dongu ilerleyecek.
			temp = temp->next; // Dugumler dolasiliyor.
		}
		temp->prev->next = temp->next; // Temp'in gerisinin ilerisine, temp'in ilerisi gonderildi. Boylece temp aradan cekilmis oldu.
		if (temp->next != NULL){ // Temp'in nexti null'a esit degilse; 
			temp->next->prev = temp->prev; // temp'in ilerisindekinin gerisine, temp'in gerisi gonderilecek.
		}
		free(temp); // Free edildi.
	}
	return head;
}

struct node *dispNode (struct node *head){
	struct node *temp;
	temp = head;
	if (temp == NULL){
		printf("\tDugum bulunmamaktadir.");
	}
	else if (temp != NULL){
		printf("\n");
		while (temp != NULL){
			printf("\t[P|%d|N]\t", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
	return head;
}

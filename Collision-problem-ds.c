#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 31 // array in boyutu
#define h(x) (x % m) //h(x) = x in modu m


typedef struct Node{
    int val;
    struct Node *next;
}Node;

//fonksiyonlarýn tanýmý
Node *fill_table(Node *table, int table_range, int number);
Node *insert(Node *table, int hash_index, int val);
Node *del(Node *table,int table_range,int val);
void print_table(Node *table, int table_range);
void search_table(Node *table, int table_range, int val);

int main(){
    Node *table; // hashtable
    int n, i, j, choice, search;
    int hash_num, val;	 	

    // table tanýmý
    table = (Node*) malloc(N*sizeof(Node));
    //table nin basýlarýný (heads)i  NULL yapýyoruz
    for(i = 0; i < N; i++){
    	table[i].next = NULL;
    }
	
    printf("--h(x) = xmod%d--\n",N);
    printf("\n\n");	 

    while(1){
    printf("1.Random sayi ekle\n");
    printf("2.Bir sayi sil\n");
	printf("3.Bir sayiyi ara\n");
	printf("4.Hash table yi goster\n");
	printf("0.Cikis\n");		
	printf("\n--------\n");
	printf("Secim: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 0: return;
		case 1:
			// random sayi ekleme
			printf("Kac tane random sayi eklensin?: ");
			scanf("%d", &n);
			table = fill_table(table, N, n);
			printf("Hashtable %d tane random sayi ile dolduruldu.\n", n);
			printf("\n--------\n");
			break;
		case 2:
			// bir sayiyi sil
			printf("Silinecek sayiyi yazin.: ");
			scanf("%d",&search);
			table = del(table, N, search);
			printf("\n--------\n");	
			break;
		case 3:
			// bir sayiyi ara
			printf("Aranacak sayiyi yazin.: ");
			scanf("%d",&search);			
			search_table(table, N, search);
			printf("\n--------\n");	
			break;
		case 4:
			//hashtable ý bastir
			printf("-HASHTABLE-\n\n");
			print_table(table, N);
			printf("\n--------\n");	
			break;	
	    }
	}	
	return 0;
}

// Fonksiyonlar ( eklemeyi yapamadým random sayilar ekledim)
Node *fill_table(Node *table, int table_range, int number){
    int i;
    int num;
    for(i=0; i<number; i++){
	num = rand()%10000; // 0 dan 9999 a random sayilar
	table = insert(table, num % table_range, num);
    }
    return table;
}

void print_table(Node *table, int table_range){
    int i;
    Node* cur;
    for(i = 0; i < table_range; i++){ // her liste için
	if(table[i].next == NULL){ // bossa
                printf("Table[%d] null!\n", i);
		continue;
	}
	cur = table[i].next;
	printf("Table[%d]", i);
	while(cur!=NULL){ // else butun degerleri bastir
		printf("->%d",cur->val);
		cur=cur->next; //cur=cur+1;
	}
	printf("\n");	
    }
}

Node *insert(Node *table, int hash_index, int val){
    Node *nn, *cur;

    nn = (Node*)malloc(sizeof(Node));
    nn->val=val;
    nn->next=NULL;
	
    if(table[hash_index].next == NULL){
	table[hash_index].next = nn;
	return table;
    }
	
    cur = table[hash_index].next;
    while(cur->next != NULL){
	cur=cur->next; //cur=cur+1;
    }
    cur->next = nn;
    return table;
}

void search_table(Node *table, int table_range, int val){
    int index = val % table_range;
    Node *cur;
	
    if(table[index].next == NULL){ // bossa
		printf("%d degeri bulunamadi cunku Table[%d] bos!\n", val,index);
                return;
    }

    cur = table[index].next;
    while(cur!=NULL){
	if(cur->val == val){
		printf("%d degeri bulundu.!\n", val);
		return;
	}
	cur = cur->next;
    }
    printf("%d  degeri hashtable de yok!\n", val);
}

Node *del(Node *table, int table_range, int val){
    int index = val % table_range;
    Node *prev;
	
    if(table[index].next == NULL){ // bossa
	printf("%d degeri bulunamadi çunku Table[%d] bos!\n", val,index);
	return table;
    }
	
    if(table[index].next->val == val){ // eger ilk item esitse
	printf("%d degeri table[%d] da bulundu ve silindi!\n", val,index);
	table[index].next = table[index].next->next;
	return table;
    }

    prev = table[index].next;
    while(prev->next!=NULL){
	if(prev->next->val == val){
		prev->next = prev->next->next;
		printf("%d degeri table[%d] da bulundu ve silindi!\n", val,index);
		return table;
	}
	prev = prev->next;
    }
    printf("%d degeri hastable de bulunamadi!\n", val);
    return table;
}

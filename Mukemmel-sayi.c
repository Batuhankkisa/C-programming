#include <stdio.h>
#include <stdlib.h>

void mukemmelkontrol(int s){
	int i, toplam=0;
	for (i=1;i<s;i++){
		if (s % i == 0){
			toplam += i;
		}
	}
	if (s == toplam){
		printf("%d sayisi mukemmel sayi.", s);
	}
	else{
		printf("%d sayisi mukemmel sayi degil!", s);
	}
}

int main (){
	int sayi;
	printf("Mukemmel sayi kontrol icin deger giriniz: ");
	scanf("%d", &sayi);
	mukemmelkontrol(sayi);
}

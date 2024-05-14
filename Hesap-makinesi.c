#include <stdio.h>

int main() {
	int sayi1, sayi2, islem_cevap;
	float sonuc;
	printf("Ilk sayiyi girin: ");
	scanf("%d", &sayi1);
	printf("Ikinci sayiyi girin: ");
	scanf("%d", &sayi2);
	printf("Lutfen yapmak istediginiz islemi seciniz.\n");
	printf("1:Toplama | 2:Cikarma | 3:Bolme | 4:Carpma \n");
	scanf("%d", &islem_cevap);
	if (islem_cevap == 1){
		sonuc = sayi1 + sayi2;
		printf("Secilen islem: Toplama | Sonuc: %d", (int)sonuc);
	}
	else if (islem_cevap == 2){
		sonuc = sayi1 - sayi2;
		printf("Secilen islem: Cikarma | Sonuc: %d", (int)sonuc);
	}
	else if (islem_cevap == 3){
		sonuc = (float)sayi1 / (float)sayi2;
		printf("Secilen islem: Bolme | Sonuc: %f", sonuc);
	}
	else if (islem_cevap == 4){
		sonuc = sayi1 * sayi2;
		printf("Secilen islem: Carpma | Sonuc: %d", (int)sonuc);
	}
	else {
		printf("Yanlis bir islem numarasi girdiniz.");
	}
	return 0;
}

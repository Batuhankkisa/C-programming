#include <stdio.h>
#include <stdlib.h>

int main() {
	int std_num=10, i, scr_avr, scr_all=0;
	int scrArr[std_num];
	for (i=0;i<std_num;i++){
		printf("%d. ogrencinin notu nedir? ", i+1);
		scanf("%d", &scrArr[i]);
		scr_all += scrArr[i];		
	}
	scr_avr = scr_all / std_num;
	printf("\nToplam %d ogrencinin girdigi dersin not ortalamasi %d olarak hesaplanmistir.\n", std_num, scr_avr);
	for (i=0;i<std_num;i++){
		if ( scrArr[i] > scr_avr ){
			printf("%d. ogrencinin notu : %d => Dersi basariyla tamamladi.\n", i+1, scrArr[i]);
		}	
		else if ( scrArr[i] <= scr_avr ){
			printf("%d. ogrencinin notu : %d => Dersi tamamlayamadi.\n", i+1, scrArr[i]);
		}	
	}
	return 0;
}

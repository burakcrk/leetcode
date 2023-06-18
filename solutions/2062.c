// 2062. Count Vowel Substrings of a String //
// Sorunun linki https://leetcode.com/problems/count-vowel-substrings-of-a-string

/*
Bu kod 'burakcrk' tarafýndan yazýlmýþtýr.
*/

/*
Soruda bir 'string' ifade içerisindeki 'vowel substring'lerinin sayýsýný
yani içerisinde ardýþýk ve sýrasý önemsiz bir þekilde 'a', 'e', 'i', 'o', 'u'
harflerini barýndýran alt dizilerinin sayýsýný bulmamýz istenmiþ.
*/

#include <stdio.h>
#include <string.h>

// Fonksiyonlarýn prototip tanýmlamalarý
int checkVowels(int *);                 
int countVowelSubstrings(char *);



int main(){
	char wost[10] = "cuaieuouac";
	printf("%d", countVowelSubstrings(wost));
	
	return 0;
}

int countVowelSubstrings(char * word){
    int countVowel = 0, i = 0, j = 0;	   // countVowel vowel 'substring' sayýsýný tutmak için, i ve j ise 'for' döngüleri için
	for(i = 0; i < strlen(word); i++){ 	   // ilk 'for' döngüsünde 'string'in 'i'nci elemanýndan kontrole baþlýyoruz
		int vowel[5] = {0,0,0,0,0};	       // kontrol ederken her vowel harfinin sayýsýný tutmak için bir dizi oluþturduk dizinin her bir elemaný bir harfin sayýsýný temsil ediyor (örn: 'a' için vowel[0], 'e' için vowel[1], ...)
		for(j = i; j < strlen(word); j++){ // 'i'nci harfi kontrol ettikten sonra 'i'den sonraki harfleri(yani 'j'inci) kontrol etmek için ikinci for döngüsü
			if(word[j] == 'a')
				vowel[0]++;
			else if(word[j] == 'e')
				vowel[1]++;
			else if(word[j] == 'i')
				vowel[2]++;
			else if(word[j] == 'o')
				vowel[3]++;
			else if(word[j] == 'u')
				vowel[4]++;	 // 'word' dizisinin 'j'inci elemanýnýn 'a', 'e', 'i', 'o', 'u' harflerinden biri olup olmadýðý kontrol edilir eðer o harflerden ise vowel dizisinde ilgili eleman arttýrýlýr (örn: o harfi için vowel[3]) 
			else			 // eðer o harflerden biri yoksa break ile dögü kýrýlýr ve ilk döngüye döneriz
				break;
			if(checkVowels(vowel)) // dögü kýrýlmaz ise 'vowel' dizisi 'checkVowels' fonksiyonuna gönderilir
				countVowel++;	   // 'checkVowels'den 1 dönerse countVowel 1 arttýrýlýr ve ilk 'for' döngsüne dönülür
		}
	}
	
	return countVowel;	
}

int checkVowels(int *vowels){		// burada 'vowel' dizisinin her bir elemanýnýn 0 olup olmadýðý kontrol edilir
	int chk = 0;					// 'vowel' dizisinin elemanlarýndan biri 0 ise bu kontrol ettiðimiz 'substring'de('i'nci elemandan baþlayýp 'j'inci elemana kadar olan) vowel harflerinde birinin olmadýðý anlamýna gelir
	for(chk = 0; chk < 5; chk++){	// bu durumda da fonksiyon 0 döndürür
		if(vowels[chk] == 0)		// eðer 'vowel' dizisinde hiç 0 yok ise bu 'substring'in vowel harflerinden oluþtuðu anlamýna gelir
			return 0;				// ve fonksiyon 1 döndürür.
	}
	
	return 1;
}

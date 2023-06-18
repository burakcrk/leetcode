// 2062. Count Vowel Substrings of a String //
// Sorunun linki https://leetcode.com/problems/count-vowel-substrings-of-a-string

/*
Bu kod 'burakcrk' taraf�ndan yaz�lm��t�r.
*/

/*
Soruda bir 'string' ifade i�erisindeki 'vowel substring'lerinin say�s�n�
yani i�erisinde ard���k ve s�ras� �nemsiz bir �ekilde 'a', 'e', 'i', 'o', 'u'
harflerini bar�nd�ran alt dizilerinin say�s�n� bulmam�z istenmi�.
*/

#include <stdio.h>
#include <string.h>

// Fonksiyonlar�n prototip tan�mlamalar�
int checkVowels(int *);                 
int countVowelSubstrings(char *);



int main(){
	char wost[10] = "cuaieuouac";
	printf("%d", countVowelSubstrings(wost));
	
	return 0;
}

int countVowelSubstrings(char * word){
    int countVowel = 0, i = 0, j = 0;	   // countVowel vowel 'substring' say�s�n� tutmak i�in, i ve j ise 'for' d�ng�leri i�in
	for(i = 0; i < strlen(word); i++){ 	   // ilk 'for' d�ng�s�nde 'string'in 'i'nci eleman�ndan kontrole ba�l�yoruz
		int vowel[5] = {0,0,0,0,0};	       // kontrol ederken her vowel harfinin say�s�n� tutmak i�in bir dizi olu�turduk dizinin her bir eleman� bir harfin say�s�n� temsil ediyor (�rn: 'a' i�in vowel[0], 'e' i�in vowel[1], ...)
		for(j = i; j < strlen(word); j++){ // 'i'nci harfi kontrol ettikten sonra 'i'den sonraki harfleri(yani 'j'inci) kontrol etmek i�in ikinci for d�ng�s�
			if(word[j] == 'a')
				vowel[0]++;
			else if(word[j] == 'e')
				vowel[1]++;
			else if(word[j] == 'i')
				vowel[2]++;
			else if(word[j] == 'o')
				vowel[3]++;
			else if(word[j] == 'u')
				vowel[4]++;	 // 'word' dizisinin 'j'inci eleman�n�n 'a', 'e', 'i', 'o', 'u' harflerinden biri olup olmad��� kontrol edilir e�er o harflerden ise vowel dizisinde ilgili eleman artt�r�l�r (�rn: o harfi i�in vowel[3]) 
			else			 // e�er o harflerden biri yoksa break ile d�g� k�r�l�r ve ilk d�ng�ye d�neriz
				break;
			if(checkVowels(vowel)) // d�g� k�r�lmaz ise 'vowel' dizisi 'checkVowels' fonksiyonuna g�nderilir
				countVowel++;	   // 'checkVowels'den 1 d�nerse countVowel 1 artt�r�l�r ve ilk 'for' d�ngs�ne d�n�l�r
		}
	}
	
	return countVowel;	
}

int checkVowels(int *vowels){		// burada 'vowel' dizisinin her bir eleman�n�n 0 olup olmad��� kontrol edilir
	int chk = 0;					// 'vowel' dizisinin elemanlar�ndan biri 0 ise bu kontrol etti�imiz 'substring'de('i'nci elemandan ba�lay�p 'j'inci elemana kadar olan) vowel harflerinde birinin olmad��� anlam�na gelir
	for(chk = 0; chk < 5; chk++){	// bu durumda da fonksiyon 0 d�nd�r�r
		if(vowels[chk] == 0)		// e�er 'vowel' dizisinde hi� 0 yok ise bu 'substring'in vowel harflerinden olu�tu�u anlam�na gelir
			return 0;				// ve fonksiyon 1 d�nd�r�r.
	}
	
	return 1;
}

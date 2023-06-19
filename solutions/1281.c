// 1281. Subtract the Product and Sum of Digits of an Integer
// Sorunun linki https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

/*
Soruda; girilen "integer" say�n�n basamak de�erlerinin toplanmas� ve basamak de�erlerinin �arp�lmas�,
fonksiyonunda �arp�m�n toplamdan fark�n�n d�nd�r�lmesi isteniyor
*/

#include <stdio.h>
#include <stdlib.h>

int subtractProductAndSum(int n);

int main(){
	int zort = 4421;
	printf("%d", subtractProductAndSum(zort));
	
	return 0;
}

int subtractProductAndSum(int n){
    int t=0, c=1;	// t de�i�keni toplam�, c de�i�keni �arp�m� tutuyor
    while(n > 0){	
    	t+=(n%10);	// her d�ng�de t de�i�kenine n de�i�keninin 10'a b�l�m�nden kalan rakam ekleniyor(yani her seferinde son basama�� eklemi� oluyoruz)
    	c*=(n%10);	// her d�ng�de c de�i�keni ile n de�i�keninin 10'a b�l�m�nden kalan rakam �arp�l�yor(yani her seferinde son basama�� �arpm�� oluyoruz)
    	n/=10;		// n say�s�n� s�rekli 10'a b�lerek say�y� her seferinde bir basamak azalt�yoruz(her seferinde son basama�� at�yoruz)
	}
    
    return (c-t);	// �arp�mdan toplam� ��kar�p d�d�r�yoruz
}

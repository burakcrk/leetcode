// 1281. Subtract the Product and Sum of Digits of an Integer
// Sorunun linki https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

/*
Soruda; girilen "integer" sayýnýn basamak deðerlerinin toplanmasý ve basamak deðerlerinin çarpýlmasý,
fonksiyonunda çarpýmýn toplamdan farkýnýn döndürülmesi isteniyor
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
    int t=0, c=1;	// t deðiþkeni toplamý, c deðiþkeni çarpýmý tutuyor
    while(n > 0){	
    	t+=(n%10);	// her döngüde t deðiþkenine n deðiþkeninin 10'a bölümünden kalan rakam ekleniyor(yani her seferinde son basamaðý eklemiþ oluyoruz)
    	c*=(n%10);	// her döngüde c deðiþkeni ile n deðiþkeninin 10'a bölümünden kalan rakam çarpýlýyor(yani her seferinde son basamaðý çarpmýþ oluyoruz)
    	n/=10;		// n sayýsýný sürekli 10'a bölerek sayýyý her seferinde bir basamak azaltýyoruz(her seferinde son basamaðý atýyoruz)
	}
    
    return (c-t);	// çarpýmdan toplamý çýkarýp dödürüyoruz
}

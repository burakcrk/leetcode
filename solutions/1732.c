// 1732. Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/

/*
X 0 noktasýndan baþlayýp her seferinde 'dizi' deðiþkenindeki eleman kadar daha yükseliyor. X'in ulaþabileceði en yüksek yükseklik nedir
*/

#include <stdio.h>
#include <stdlib.h>

int largestAltitude(int* gain, int gainSize);

int main(){
	int dizi[33] = {44,32,-9,52,23,-50,50,33,-84,47,-14,84,36,-62,37,81,-36,-85,-39,67,-63,64,-47,95,91,-40,65,67,92,-28,97,100,81};
	int dizisize = 33;
	printf("%d", largestAltitude(dizi, dizisize));
	return 0;
}

int largestAltitude(int* gain, int gainSize){
	int k = 0, altitude = 0, maxAltitude = 0;	// altitude 0 dan baþlýyor, ve maxAltitude 0 alýyoruz (en yüksek yüksekliði 0 kabul ediyoruz)

	for(k = 0; k < gainSize; k++){ 
		altitude += gain[k];					// altitude'da her seferinde gain[k] ekleniyor (yani altitude, gain[k] kadar artýyor)
		if(maxAltitude < altitude){				// anlýk yukseklýk(altitude) ile o anki en yuksek yuksekliði(maxAltitude) karþýlaþtýrýyoruz.
			maxAltitude = altitude;				// eðer anlýk yükseklik daha büyük ise maxAltitude'ý anlýk yüksekliðe eþitliyoruz
		}										// eðer anlýk yükseklik daha büyük deðilse döngü devam ediyor(altitude da artmaya devam ediyor)
	}											// döngü sonunda maxAltitude deðeri bizim en yüksek yüksekliðimiz oluyor

	return maxAltitude;

}

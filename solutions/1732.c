// 1732. Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/

/*
X 0 noktas�ndan ba�lay�p her seferinde 'dizi' de�i�kenindeki eleman kadar daha y�kseliyor. X'in ula�abilece�i en y�ksek y�kseklik nedir
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
	int k = 0, altitude = 0, maxAltitude = 0;	// altitude 0 dan ba�l�yor, ve maxAltitude 0 al�yoruz (en y�ksek y�ksekli�i 0 kabul ediyoruz)

	for(k = 0; k < gainSize; k++){ 
		altitude += gain[k];					// altitude'da her seferinde gain[k] ekleniyor (yani altitude, gain[k] kadar art�yor)
		if(maxAltitude < altitude){				// anl�k yuksekl�k(altitude) ile o anki en yuksek yuksekli�i(maxAltitude) kar��la�t�r�yoruz.
			maxAltitude = altitude;				// e�er anl�k y�kseklik daha b�y�k ise maxAltitude'� anl�k y�ksekli�e e�itliyoruz
		}										// e�er anl�k y�kseklik daha b�y�k de�ilse d�ng� devam ediyor(altitude da artmaya devam ediyor)
	}											// d�ng� sonunda maxAltitude de�eri bizim en y�ksek y�ksekli�imiz oluyor

	return maxAltitude;

}

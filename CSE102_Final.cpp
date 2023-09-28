// Student No = 211804106
#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

double calculateStandardDeviation(int data[], int size, double mean) {
	double sumOfSquaredDeviations = 0.0;
	double standardDeviation = 0.0;
	int i;

	for (i = 0; i < size; i++) {
		double deviation = data[i] - mean;
		sumOfSquaredDeviations += (deviation * deviation);
	}

	standardDeviation = sqrt(sumOfSquaredDeviations / size);

	return standardDeviation;
}




int main() {

	int ogrenciNo[20] = {1122,1133,1144,1155,1166,1177,1188,1199,1211,1222,1233,1244,1255,1266,1277,1288,1299,1311,1322,1333};
	
	int vizeNot[20] = { 0,0,0,20,20,30,40,40,53,57,64,66,77,85,83,71,80,90,91,93 };

	int finalNot[20] = { 0,0,11,24,33,51,55,57,63,67,71,76,78,79,81,83,92,95,97,100 };

	int i;
	double toplamNotFinal = 0.0;
	double toplamNotVize = 0.0;
	double toplamNotGecis = 0.0;
	double toplamKareFarkGecis = 0.0;
	double toplamKareFarkVize = 0.0;
	double toplamKareFarkFinal = 0.0;


	int ogrenciSayisi = sizeof(ogrenciNo) / sizeof(ogrenciNo[0]);
	int	gecenler = 0;
	for (i = 0; i < 20; i++) {
		double dersGecmeNotu = vizeNot[i] * 0.4 + finalNot[i] * 0.6;
		printf("No: %d		 Midterm: %d		 Final: %d			Pass: %.2lf\n", ogrenciNo[i], vizeNot[i], finalNot[i], dersGecmeNotu);
		toplamNotGecis += dersGecmeNotu;
		toplamNotVize += vizeNot[i];
		toplamNotFinal += finalNot[i];
		//Numaram 211804106 oldugu icin ve sonu 06 ile bittigi icin 70+6/2den gecme notu 38'dir.
		if (dersGecmeNotu > 38) {
			gecenler++;
		}
	}

	double sinifOrtalamasiFinal = toplamNotFinal / 18;

	double sinifOrtalamasiVize = toplamNotVize / 17;
	
	double sinifOrtalamasi = toplamNotGecis / 18;


	double standartSapmaFinal = calculateStandardDeviation(finalNot, 18, sinifOrtalamasiFinal);
	double standartSapmaVize = calculateStandardDeviation(vizeNot, 17, sinifOrtalamasiVize);
	double standartSapmaGecis = calculateStandardDeviation(vizeNot, 18, sinifOrtalamasi);




	printf("\nAvg:			    %.2lf		      %.2lf			 %.2lf",sinifOrtalamasiVize,sinifOrtalamasiFinal,sinifOrtalamasi);
	printf("\nStd:                        %2.lf                        %.2lf                      %.2lf\n", standartSapmaVize, standartSapmaFinal, standartSapmaGecis);
	printf("\nThere are %d students with grade greater than %lf\n", gecenler,sinifOrtalamasi);

	return 0;
}
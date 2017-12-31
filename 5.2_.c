#include <stdio.h>
#include <stdlib.h> //random
#include <time.h>

void wypelnij(int macierz[3][3]){
	time_t tt;
	srand(time(&tt));
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			macierz[i][j]=rand()%11;
		}
	}
}

void wypisz(int macierz[3][3]){
	for (int i=0; i<3; i++){
		printf("|");
		for (int j =0; j<3; j++){
			if (macierz [i][j]<10)
				printf (" ");
			printf("%d ", macierz[i][j]);
		}
		printf ("|\n");
	}
}	

int det(int macierz [3][3]){
	int a=0;
	for (int i=0; i<3; i++){
		int iloczynprawoskosny=1;
		int iloczynlewoskosny=-1;
		for (int j=0;j<3;j++){
			iloczynprawoskosny*=macierz[(i+j)%3][j];
			iloczynlewoskosny*=macierz[(i+j)%3][2-j];
		}
		a+=iloczynlewoskosny+iloczynprawoskosny;
	}
	return a;
}

int main(){
	int macierz[3][3];
	wypelnij(macierz);
	wypisz(macierz);
	printf("Wyznacznik = %d\n", det(macierz));
	return 0;
}


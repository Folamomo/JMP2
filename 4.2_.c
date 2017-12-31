#include <stdio.h>

int zgadnij(int n, int poczatek, int koniec);
int napraw(int n, int zakresOd, int zakresDo);

int main(){
	int n=0;
	int zakresOd=1;
	int zakresDo=10;
	printf("Podaj liczbę z zakresu [%d,%d]: \n", zakresOd, zakresDo);
	scanf("%d", &n);
	n=napraw(n, zakresOd, zakresDo);
	printf("Twoja liczba to: %d\n", zgadnij(n, zakresOd, zakresDo));

}

int zgadnij(int n, int poczatek, int koniec){
	while (poczatek != koniec){
		if (n>(poczatek+koniec)/2){
			poczatek=(poczatek+koniec)/2+1;
		}
		else{
			koniec=(poczatek+koniec)/2;
		}
	}
	return poczatek;
}

int napraw (int n, int zakresOd, int zakresDo){
	if (n<zakresOd||n>zakresDo){
		if (n<0)
			n=-n;
		n=n%(zakresDo-zakresOd+1)+zakresOd;
		printf( "Twoja liczba nie miescila sie przedziale.\n"
			"Zostala zamieniona na %d\n",n);
	}
	return n;
}

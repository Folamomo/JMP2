#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losuj(int* tab, const int rozmiar){ // losuje inna kulke, zwraca jej indeks
    for (int i=0; i<rozmiar; i++){
        tab[i]=10;
    }
    int a=rand()%9;
    tab[a]+=1;
    return a;
}

void wazenie(int* tab, const int rozmiar){
	int lewa[rozmiar];
	int prawa[rozmiar];
	int ileZLewej, ileZPrawej;
	printf("Ile kulek chcesz polozyc na lewej szalce wagi?\n");
	scanf("%d", &ileZLewej);
	printf("Wybierz kulki na lewa szalke\n");
	for (int i=0; i<ileZLewej; i++)
		scanf("%d", lewa+i);
	printf("Ile kulek chcesz polozyc na prawej szalce wagi?\n");
	scanf("%d", &ileZPrawej);
	printf("Wybierz kulki na prawa szalke\n");
	for (int i=0; i<ileZPrawej; i++)
		scanf("%d", prawa+i);
	int sumaLewa=0, sumaPrawa=0;
	for (int i=0; i<ileZLewej; i++)
		sumaLewa+=tab[lewa[i]-1];
	for (int i=0; i<ileZPrawej; i++)
		sumaPrawa+=tab[prawa[i]-1];
	if (sumaLewa>sumaPrawa)
		printf("Kulki na lewej szalce waza wiecej\n");
	else if (sumaLewa==sumaPrawa)
		printf("Kulki waza tyle samo\n");
	else
	        printf("Kulki na prawej szalce waza wiecej \n");	
}	

int odpowiedz(){
	int wybrana;
	printf("Ktora kulka ma inna wage?\n");
	scanf("%d", &wybrana);
	return wybrana-1;
}

int main(){
	int tab[9];
	const int rozmiar=sizeof(tab)/sizeof(tab[0]);
	int inna=losuj(tab, rozmiar);
	srand(time(NULL));
	for (int i=0; i<2; i++){
		wazenie(tab, rozmiar);
	}
	if (inna==odpowiedz())
		printf("Gratulacje, wygrales!\n");
	else
		printf("Niestety, poprawna odpowiedz to %d\n", inna);
	return 0;
}


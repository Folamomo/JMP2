#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 2

void mnozenie(int wymiar, int dane[2][wymiar][wymiar], int wynik[wymiar][wymiar]) {
  for (int wiersz = 0; wiersz < wymiar; wiersz++) {
    for (int kolumna = 0; kolumna < wymiar; kolumna++) {
      wynik[wiersz][kolumna] = 0;
      for (int i=0; i<wymiar; i++)
	      wynik[wiersz][kolumna]+=dane[0][wiersz][i] * dane[1][i][kolumna];
    }
  }
}

void polacz(int wymiar, int macierz1[wymiar][wymiar], int macierz2[wymiar][wymiar], int wynik[2][wymiar][wymiar]) {
  for (int i = 0; i < wymiar; i++) {
    for (int j = 0; j < wymiar; j++) {
      wynik[0][i][j] = macierz1[i][j];
      wynik[1][i][j] = macierz2[i][j];
    }
  }
}

void rozdziel(int wymiar, int wejscie[2][wymiar][wymiar], int wyjscie1[wymiar][wymiar], int wyjscie2[wymiar][wymiar]) {
  for (int i = 0; i < wymiar; i++) {
    for (int j = 0; j < wymiar; j++) {
      wyjscie1[i][j] = wejscie[0][i][j];
      wyjscie2[i][j] = wejscie[1][i][j];
    }
  }
}

void losuj(int wymiar, int macierz[wymiar][wymiar]) {
  for (int i = 0; i < wymiar; i++) {
    for (int j = 0; j < wymiar; j++)
      macierz[i][j] = rand() % 201 - 100;
  }
}

void wypisz(int wymiar, int macierz[wymiar][wymiar]) {
  for (int i = 0; i < wymiar; i++) {
    printf ("|");
    for (int j = 0; j < wymiar; j++)
      printf("%5d", macierz[i][j]);
    printf("|\n");
  }
}

int main() {
  srand(time(NULL));
  int macierz1[ROZMIAR][ROZMIAR];
  int macierz2[ROZMIAR][ROZMIAR];
  losuj(ROZMIAR, macierz1);
  losuj(ROZMIAR, macierz2);
  wypisz(ROZMIAR, macierz1);
  wypisz(ROZMIAR, macierz2);
  int polaczone[2][ROZMIAR][ROZMIAR];
  polacz(ROZMIAR, macierz1, macierz2, polaczone);
  int wynik[ROZMIAR][ROZMIAR];
  mnozenie(ROZMIAR, polaczone, wynik);
  wypisz(ROZMIAR, wynik);
}

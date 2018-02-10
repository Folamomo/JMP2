#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mnozenie(int dane[2][2][2], int wynik[2][2]) {
  for (int wiersz = 0; wiersz < 2; wiersz++) {
    for (int kolumna = 0; kolumna < 2; kolumna++) {
      wynik[wiersz][kolumna] = dane[0][wiersz][0] * dane[1][0][kolumna] +
                               dane[0][wiersz][1] * dane[1][1][kolumna];
    }
  }
}

void polacz(int macierz1[2][2], int macierz2[2][2], int wynik[2][2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      wynik[0][i][j] = macierz1[i][j];
      wynik[1][i][j] = macierz2[i][j];
    }
  }
}

void rozdziel(int wejscie[2][2][2], int wyjscie1[2][2], int wyjscie2[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      wyjscie1[i][j] = wejscie[0][i][j];
      wyjscie2[i][j] = wejscie[1][i][j];
    }
  }
}

void losuj(int macierz[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++)
      macierz[i][j] = rand() % 201 - 100;
  }
}

void wypisz(int macierz[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      printf("%d  ", macierz[i][j]);
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  int macierz1[2][2];
  int macierz2[2][2];
  losuj(macierz1);
  losuj(macierz2);
  wypisz(macierz1);
  wypisz(macierz2);
  int polaczone[2][2][2];
  polacz(macierz1, macierz2, polaczone);
  int wynik[2][2];
  mnozenie(polaczone, wynik);
  wypisz(wynik);
}

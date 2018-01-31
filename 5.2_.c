#include <stdio.h>
#include <stdlib.h> //random
#include <time.h>

void wypelnij(int wymiar, int macierz[wymiar][wymiar]) {
  for (int i = 0; i < wymiar; i++) {
    for (int j = 0; j < wymiar; j++) {
      macierz[i][j] = rand() % 11;
    }
  }
}

void wypisz(int wymiar, int macierz[wymiar][wymiar]) {
  for (int i = 0; i < wymiar; i++) {
    printf("|");
    for (int j = 0; j < wymiar; j++) {
      if (macierz[i][j] < 10)
        printf(" ");
      printf("%d ", macierz[i][j]);
    }
    printf("|\n");
  }
}

int det(int macierz[3][3]) {     //tutaj nie daję wymiaru jako
  int a = 0;                     //argument bo ta metoda nie 
  for (int i = 0; i < 3; i++) {  //działa dla macierzy nie 3X3
    int iloczynprawoskosny = 1;
    int iloczynlewoskosny = -1;
    for (int j = 0; j < 3; j++) {
      iloczynprawoskosny *= macierz[(i + j) % 3][j];
      iloczynlewoskosny *= macierz[(i + j) % 3][2 - j];
    }
    a += iloczynlewoskosny + iloczynprawoskosny;
  }
  return a;
}

int main() {
  int macierz[3][3];
  srand(time(NULL));
  wypelnij(3, macierz);
  wypisz(3, macierz);
  printf("Wyznacznik = %d\n", det(macierz));
  return 0;
}

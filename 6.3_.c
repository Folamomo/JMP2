#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losuj(int *tab) {
  for (int i = 0; i < 10; i++) {
    *(tab + i) = rand();
  }
}

void drukuj(int *tab) {
  printf("[");
  for (int i = 0; i < 9; i++) {
    printf("%d, ", *(tab + i));
  }
  printf("%d]\n", *(tab + 9));
}

float srednia(int *tab) {
  int suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += *(tab + i);
  }
  return suma / 10.0;
}

float mediana(int *wejscie) {
  int tab[10];
  for (int i = 0; i < 10; i++) {
    tab[i] = wejscie[i];
  }
  for (int i = 0; i < 10; i++) { // bubblesort
    for (int j = 0; j < 9; j++) {
      if (tab[j] < tab[j + 1]) {
        int t = tab[j];
        tab[j] = tab[j + 1];
        tab[j + 1] = t;
      }
    }
  }
  return (tab[4] + tab[5]) / 2.0;
}

int najmn(int *tab) {
  int min = tab[0];
  for (int i = 1; i < 10; i++) {
    if (min > tab[i])
      min = tab[i];
  }
  return min;
}

int najw(int *tab) {
  int maks = tab[0];
  for (int i = 1; i < 10; i++) {
    if (maks < tab[i])
      maks = tab[i];
  }
  return maks;
}

int main() {
  int tab[10];
  char c[100];
  srand(time(NULL));
  while (c[0] != '6') {

    printf("Menu\n"
           "1. Losuj\n"
           "2. Wyswietl\n"
           "3. Policz srednia\n"
           "4. Policz mediane\n"
           "5. Zajdź element maksymalny i minimalny\n"
           "6. Zakoncz program\n");
    scanf("%s", c);
    switch (c[0]) {
    case '1':
      losuj(tab);
      break;
    case '2':
      drukuj(tab);
      break;
    case '3':
      printf("Srednia wynosi %f\n", srednia(tab));
      break;
    case '4':
      printf("Mediana wynosi %f\n", mediana(tab));
      break;
    case '5':
      printf("Najw= %d, Najmn= %d\n", najw(tab), najmn(tab));
    }
  }
}

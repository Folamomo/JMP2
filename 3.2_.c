#include <stdio.h>

#define ZAMIANA_CELSJUSZ_FARENHEIT 1
#define ZAMIANA_FARENHEIT_CELSJUSZ 2

void zamien(double wartosc, int kierunek) {
  if (kierunek == ZAMIANA_CELSJUSZ_FARENHEIT) {
    printf("%lf stopni Celsjusza to %lf stopni Farenheita\n", wartosc,
           wartosc * 1.8 + 32);
  }
  if (kierunek == ZAMIANA_FARENHEIT_CELSJUSZ) {
    printf("%lf stopni Farenheita to %lf stopni Celsjusza\n", wartosc,
           (wartosc - 32) / 1.8);
  }
}

int main() {
  printf("1.Celsjusz -> Farenheit\n2.Farenheit ->Celsiusz\n");
  int kierunek = 0;
  scanf("%d", &kierunek);
  if (kierunek != 1 && kierunek != 2) {
    printf("Niewlasciwa wartosc. Wybierz 1 lub 2\n");
    return 0;
  }
  printf("Podaj wartość\n");
  double wartosc;
  scanf("%lf", &wartosc);
  zamien(wartosc, kierunek);
  return 0;
}

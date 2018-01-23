// kompiluje się z flagą -lm

#include <math.h>
#include <stdio.h>

#define ZAMIEN_STOPNIE_RADIANY 2
#define ZAMIEN_RADIANY_STOPNIE 1

void zamien(double wartosc, int kierunek) {
  if (kierunek == ZAMIEN_STOPNIE_RADIANY) {
    printf("%lf radianów to %lf stopni \n", wartosc, wartosc / M_PI * 180);
  }
  if (kierunek == ZAMIEN_RADIANY_STOPNIE) {
    printf("%lf stopni to %lf radianów\n", wartosc, wartosc * M_PI / 180);
  }
}
int main() {
  printf("1.Stopnie ->Radiany\n2.Radiany ->Stopnie\n");
  int kierunek = 0;
  scanf("%d", &kierunek);
  if (kierunek != 1 && kierunek != 2) {
    printf("Niewlasciwa wartosc. Wybierz 1 lub 2");
    return 0;
  }
  printf("Podaj wartość: ");
  double wartosc;
  scanf("%lf", &wartosc);
  zamien(wartosc, kierunek);
  return 0;
}

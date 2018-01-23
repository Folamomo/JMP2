#include <stdio.h>

int porownaj(int czas1[3], int czas2[3]) {
  for (int i = 0; i < 3; i++) {
    if (czas1[i] > czas2[i])
      return -1;
    if (czas1[i] < czas2[i])
      return 1;
  }
  return 0;
}

int sprawdzformat(int czas[3]) {
  if (czas[0] > 23 || czas[0] < 0)
    return 0;
  if (czas[1] > 59 || czas[1] < 0)
    return 0;
  if (czas[2] > 59 || czas[2] < 0)
    return 0;
  return 1;
}

int main() {
  int czas1[3];
  int czas2[3];
  printf("podaj 1 godzinę\n");
  scanf("%d%d%d", czas1, czas1 + 1, czas1 + 2);
  printf("podaj 2 godzinę\n");
  scanf("%d%d%d", czas2, czas2 + 1, czas2 + 2);
  if ((sprawdzformat(czas1) && sprawdzformat(czas2)) == 0) {
    printf("Nieprawidłowy format. Używaj hh mm ss\n");
    return 0;
  }
  return porownaj(czas1, czas2);
}

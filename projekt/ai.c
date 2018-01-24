#include <stdio.h>
#include <stdlib.h>

int sprobujwygrac(int pole[3][3]){
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (pole[y][x] == 0) // dla każdego pustego pola
      {
        if (pole[(y + 1) % 3][x] == 2 &&
            pole[(y + 2) % 3][x] == 2) // spróbuj wygrać kolumnę
        {
          pole[y][x] = 2;
          return 1;
        }

        if (pole[y][(x + 1) % 3] == 2 &&
            pole[y][(x + 2) % 3] == 2) // spróbuj wygrać wiersz
        {
          pole[y][x] = 2;
          return 1;
        }

        if (x == y) //==leży na przekątnej prawoskosnej
        {
          if (pole[(y + 1) % 3][(x + 1) % 3] == 2 &&
              pole[(y + 2) % 3][(x + 2) % 3] == 2) {
            pole[y][x] = 2;
            return 1;
          }
        }
        if (y == 2 - x) // druga przekątna
        {

          if (pole[(y + 1) % 3][(x + 2) % 3] == 2 &&
              pole[(y + 2) % 3][(x + 1) % 3] == 2) {
            pole[y][x] = 2;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int sprobujbronic(int pole [3][3]){
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (pole[y][x] == 0) // dla każdego pustego pola
      {
        if (pole[(y + 1) % 3][x] == 1 &&
            pole[(y + 2) % 3][x] == 1) // spróbuj bronic kolumnę
        {
          pole[y][x] = 2;
          return 1;
        }

        if (pole[y][(x + 1) % 3] == 1 &&
            pole[y][(x + 2) % 3] == 1) // spróbuj bronic wiersz
        {
          pole[y][x] = 2;
          return 1;
        }

        if (y == x) //==leży na przekątnej prawoskosnej
        {
          if (pole[(y + 1) % 3][(x + 1) % 3] == 1 &&
              pole[(y + 2) % 3][(x + 2) % 3] == 1) {
            pole[y][x] = 2;
            return 1;
          }
        }

        if (y == 2 - x) // druga przekątna
        {
          if (pole[(y + 1) % 3][(x + 2) % 3] == 1 &&
              pole[(y + 2) % 3][(x + 1) % 3] == 1) {
            pole[y][x] = 2;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

void ai(int pole[3][3]) {
  if(sprobujwygrac(pole))
    return;
  if(sprobujbronic(pole))
    return;
  if (pole[1][1] == 0) { // gra środek jeśli pusty
    pole[1][1] = 2;
    return;
  }
  if (pole[1][1] == 1 && pole[0][2] == 0) { // obrona przed środkiem
    pole[0][2] = 2;
    return;
  }
  if (pole[1][1] == 2 && pole[0][0] == 1 && pole[2][2] == 1 &&
      pole[0][1] == 0) { // obrona przed strategią skośną
    pole[0][1] = 2;
    return;
  }
  if (pole[1][1] == 2 && pole[2][0] == 1 && pole[0][2] == 1 &&
      pole[0][1] == 0) { // druga przekątna
    pole[0][1] = 2;
    return;
  }
  int a = -1; // gra losowe pole
  int x, y;
  while (a != 0) {
    y = rand() % 3;
    x = rand() % 3;
    a = pole[y][x];
  }
  pole[y][x] = 2;
}

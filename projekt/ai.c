#include <stdio.h>
#include <stdlib.h>

int tryWining(int field[3][3]){
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (field[y][x] == 0) // dla każdego pustego pola
      {
        if (field[(y + 1) % 3][x] == 2 &&
            field[(y + 2) % 3][x] == 2) // spróbuj wygrać kolumnę
        {
          field[y][x] = 2;
          return 1;
        }

        if (field[y][(x + 1) % 3] == 2 &&
            field[y][(x + 2) % 3] == 2) // spróbuj wygrać wiersz
        {
          field[y][x] = 2;
          return 1;
        }

        if (x == y) //==leży na przekątnej prawoskosnej
        {
          if (field[(y + 1) % 3][(x + 1) % 3] == 2 &&
              field[(y + 2) % 3][(x + 2) % 3] == 2) {
            field[y][x] = 2;
            return 1;
          }
        }
        if (y == 2 - x) // druga przekątna
        {

          if (field[(y + 1) % 3][(x + 2) % 3] == 2 &&
              field[(y + 2) % 3][(x + 1) % 3] == 2) {
            field[y][x] = 2;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int tryDefending(int field [3][3]){
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (field[y][x] == 0) // dla każdego pustego pola
      {
        if (field[(y + 1) % 3][x] == 1 &&
            field[(y + 2) % 3][x] == 1) // spróbuj bronic kolumnę
        {
          field[y][x] = 2;
          return 1;
        }

        if (field[y][(x + 1) % 3] == 1 &&
            field[y][(x + 2) % 3] == 1) // spróbuj bronic wiersz
        {
          field[y][x] = 2;
          return 1;
        }

        if (y == x) //==leży na przekątnej prawoskosnej
        {
          if (field[(y + 1) % 3][(x + 1) % 3] == 1 &&
              field[(y + 2) % 3][(x + 2) % 3] == 1) {
            field[y][x] = 2;
            return 1;
          }
        }

        if (y == 2 - x) // druga przekątna
        {
          if (field[(y + 1) % 3][(x + 2) % 3] == 1 &&
              field[(y + 2) % 3][(x + 1) % 3] == 1) {
            field[y][x] = 2;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

void playrandom(int field[3][3]){// gra losowe pole
  while(1) { 
    int* randomfield=&(field[rand() % 3][rand() % 3])	;
    if (*randomfield==0){
	    *randomfield=2;
	    return;
    }
  }  
}

void CPmove(int field[3][3]) {
  if(tryWining(field))
    return;
  if(tryDefending(field))
    return;
  if (field[1][1] == 0) { // gra środek jeśli pusty
    field[1][1] = 2;
    return;
  }
  if (field[1][1] == 1 && field[0][2] == 0) { // obrona przed środkiem
    field[0][2] = 2;
    return;
  }
  if (field[1][1] == 2 && field[0][0] == 1 && field[2][2] == 1 &&
      field[0][1] == 0) { // obrona przed strategią skośną
    field[0][1] = 2;
    return;
  }
  if (field[1][1] == 2 && field[2][0] == 1 && field[0][2] == 1 &&
      field[0][1] == 0) { // druga przekątna
    field[0][1] = 2;
    return;
  }
  playrandom(field);
}


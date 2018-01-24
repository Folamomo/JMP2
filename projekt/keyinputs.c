#include <ncurses.h>
#include <stdio.h>

void p1move(int pole[3][3]) {
  int warunek = 1;
  while (warunek) {
    const char c = getch();
    if (c == 'q') {
      if (pole[0][0] == 0) {
        pole[0][0] = 1;
        warunek = 0;
      }
    } else if (c == 'w') {
      if (pole[0][1] == 0) {
        pole[0][1] = 1;
        warunek = 0;
      }
    } else if (c == 'e') {
      if (pole[0][2] == 0) {
        pole[0][2] = 1;
        warunek = 0;
      }
    } else if (c == 'a') {
      if (pole[1][0] == 0) {
        pole[1][0] = 1;
        warunek = 0;
      }
    } else if (c == 's') {
      if (pole[1][1] == 0) {
        pole[1][1] = 1;
        warunek = 0;
      }
    } else if (c == 'd') {
      if (pole[1][2] == 0) {
        pole[1][2] = 1;
        warunek = 0;
      }
    } else if (c == 'z') {
      if (pole[2][0] == 0) {
        pole[2][0] = 1;
        warunek = 0;
      }
    } else if (c == 'x') {
      if (pole[2][1] == 0) {
        pole[2][1] = 1;
        warunek = 0;
      }
    } else if (c == 'c') {
      if (pole[2][2] == 0) {
        pole[2][2] = 1;
        warunek = 0;
      }
    }
  }
}

void p2move(int pole[3][3]) {

  int warunek = 1;
  while (warunek) {
    const char c = getch();
    if (c == 'u') {
      if (pole[0][0] == 0) {
        pole[0][0] = 2;
        warunek = 0;
      }
    } else if (c == 'i') {
      if (pole[0][1] == 0) {
        pole[0][1] = 2;
        warunek = 0;
      }
    } else if (c == 'o') {
      if (pole[0][2] == 0) {
        pole[0][2] = 2;
        warunek = 0;
      }
    } else if (c == 'j') {
      if (pole[1][0] == 0) {
        pole[1][0] = 2;
        warunek = 0;
      }
    } else if (c == 'k') {
      if (pole[1][1] == 0) {
        pole[1][1] = 2;
        warunek = 0;
      }
    } else if (c == 'l') {
      if (pole[1][2] == 0) {
        pole[1][2] = 2;
        warunek = 0;
      }
    } else if (c == 'm') {
      if (pole[2][0] == 0) {
        pole[2][0] = 2;
        warunek = 0;
      }
    } else if (c == ',') {
      if (pole[2][1] == 0) {
        pole[2][1] = 2;
        warunek = 0;
      }
    } else if (c == '.') {
      if (pole[2][2] == 0) {
        pole[2][2] = 2;
        warunek = 0;
      }
    }
  }
}

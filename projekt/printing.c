#include <ncurses.h>
#include <stdio.h>
#include <stdbool.h>

void printhelp() {
  clear();
  printw("\tGracz 1:        Gracz 2:\n"
         "\t  q|w|e           u|i|p\n"
         "\t  a|s|d           j|k|l\n"
         "\t  z|x|c           m|,|.\n"
         "\tNacisnij dowolny klawisz aby wrocic");
  getch();
}

void printfield(int n, int field[n][n]) {
  clear();
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (field[y][x] == 0) {
        printw(" ");
      } else if (field[y][x] == 1) {
        printw("x");
      } else if (field[y][x] == 2) {
        printw("O");
      }
      if (x < n-1) {
        printw("|");
      } else {
        printw("\n");
      }
    }
  }
}

void printscore(int p1score, int p2score, bool pvp) {
  if (pvp == TRUE)
    printw("\n"
           "Gracz 1   Gracz 2\n");
  else
    printw("\n"
           "Gracz 1   Komputer\n");
  printw(
           "  %d         %d\n", p1score, p2score);
}

#include <ncurses.h> // sudo apt-get install libncurses5-dev
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "keyinputs.h"
#include "ai.h"
#include "printing.h"

void init() {
  initscr();
  noecho();
  cbreak();
  time_t tt;
  int seed = time(&tt);
  srand(seed);
}

void initfield(int field[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      field[i][j] = 0;
  }
}

int chkwin(int pole[3][3]) {

  for (int i = 0; i < 3; i++) { 
    if (pole[0][i] != 0) {
      if (pole[0][i] == pole[1][i] && pole[0][i] == pole[2][i]) {
        return pole[0][i];
      }
    }
    if (pole[i][0] != 0) {
      if (pole[i][0] == pole[i][1] && pole[i][0] == pole[i][2]) {
        return pole[i][0];
      }
    }
  }
  if (pole[1][1] != 0) {
    if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2]) {
      return pole[1][1];
    }
    if (pole[2][0] == pole[1][1] && pole[1][1] == pole[0][2]) {
      return pole[1][1];
    }
  }
  return 0;
}

int runda(int startsfirst, int p1score, int p2score, int pvp) {
  int field[3][3];
  initfield(field);
  int movecounter = 0;
  printfield(field);
  printscore(p1score, p2score, pvp);
  
  while (chkwin(field) == 0 && movecounter < 9) {
    if ((movecounter + startsfirst) % 2)
      p1move(field);
    else if (pvp == TRUE)
      p2move(field);
    else
      ai(field);
    printfield(field);
    printscore(p1score, p2score, pvp);
    movecounter++;
  }
  
  getch();
  return chkwin(field);
}

void gra(int pvp) {
  int startsfirst = 1;
  int p1score = 0;
  int p2score = 0;
  
  while (p1score < 4 && p2score < 4) {
    int winner = runda(startsfirst, p1score, p2score, pvp);
    if (winner == 1) {
      p1score++;
      startsfirst = 0;
    } else if (winner == 2) {
      p2score++;
      startsfirst = 1;
    } else
      startsfirst = (startsfirst + 1) % 2;
  }

  if (p1score > p2score)
    printw("Wygrywa gracz 1!\n");
  else if (pvp == TRUE)
    printw("Wygrywa gracz 2!\n");
  else
    printw("Wygrywa Komputer!\n");
  printw("Nacisnij dowolny klawisz, aby wrocic do menu\n");
  getch();
  return;
}


void run(int mode) {
  switch (mode) {
  case 1:
    gra(TRUE);
    break;
  case 2:
    gra(FALSE);
    break;
  case 3:
    printhelp();
  }
  return;
}

int menu() {
  clear();
  printw("1. Zagraj z innym graczem\n2. Zagraj z komputerem\n3. Sterowanie\n"
         "4. Wyjscie\n");
  char c = getch();
  switch (c) {
  case '1':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 0;
  }
}
int main() {
  init();
  int choice = 1;
  while (choice) {
    choice = menu();
    run(choice);
  }
  endwin();
  return 0;
}

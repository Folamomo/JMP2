#ifndef PRINTING_H
#define PRINTING_H

#include <stdio.h>
#include <ncurses.h>

void printhelp();
void printfield(int n, int pole[n][n]);
void printscore(int p1score, int p2score, int pvp);

#endif

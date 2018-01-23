#include <stdio.h>
#include <time.h>

const int dni_w_mies[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void kalendarz(int miesiac, int dzientyg, int dzienmies) {
  int odstep = (dzientyg - dzienmies + 42) % 7;
  printf("Pon Wto Sro Czw Pia Sob Nie\n");
  for (int i = 0; i < odstep; i++)
    printf("    ");
  for (int i = 1; i <= dni_w_mies[miesiac]; i++) {
    if (i < 10)
      printf(" ");
    printf("%d  ", i);
    if ((i + odstep) % 7 == 0)
      printf("\n");
  }
  printf("\n");
  return;
}

int main() {
  time_t czas;
  struct tm *timeinfo;
  time(&czas);
  //	czas+=60*60*24*150;
  //	Powyższa linijka pozwala testować działanie programu dla dat innych niż
  //dzisiejsza.
  timeinfo = localtime(&czas);
  char czasstr[100];
  char naglowek[100];

  strftime(naglowek, 100, "%B %Y", timeinfo);
  printf("\t%s\n", naglowek);

  strftime(czasstr, 100, "%m%u%d", timeinfo);
  int miesiac = 10 * (czasstr[0] - '0') + czasstr[1] - '0';
  int dzientyg = czasstr[2] - '0';
  int dzienmies = 10 * (czasstr[3] - '0') + czasstr[4] - '0';
  kalendarz(miesiac, dzientyg, dzienmies);
  return 0;
}

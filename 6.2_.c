#include <stdio.h>
#include <time.h>

void drukujNaglowek(struct tm *timeinfo) {
  char naglowek[100];
  strftime(naglowek, 100, "    %B %Y", timeinfo);
  printf("%s", naglowek);
  printf("\nMon Tue Wed Thu Fri Sat Sun\n");
}

void drukujKalendarz(struct tm *timeinfo) {
  timeinfo->tm_mday = 1;
  mktime(timeinfo);

  int odstep = (timeinfo->tm_wday + 6) % 7;
  for (int i = 0; i < odstep; i++)
    printf("    ");

  do {
    printf("%3d ", timeinfo->tm_mday);
    if (timeinfo->tm_wday == 0)
      printf("\n");
    timeinfo->tm_mday++;
    mktime(timeinfo);
  } while (timeinfo->tm_mday > 1);
  printf("\n");
}

int main() {
  time_t czas;
  time(&czas);
  struct tm *timeinfo = localtime(&czas);

  drukujNaglowek(timeinfo);
  drukujKalendarz(timeinfo);

  return 0;
}

#include <stdio.h>

int main() {
  for (int j = 0; j < 256; j++) {
    printf("%c\t%d\n", j, j);
  }
  return 0;
}

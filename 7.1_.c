#include <stdio.h>


float srednia(int* pocz, int* kon)
{
  float suma =0;
  int waga=0;
  for (int i =0;i<kon-pocz;i++)
  {
    suma+=(*(pocz+i)*i);
    waga+=i;
  }
  return suma/waga;
}

int main()
{
  int tab[]={3,5,2,1,1,2,3,4,3,1,4};
  int rozmiar = (sizeof(tab)/sizeof(tab[0]));
  float sr = srednia(tab,tab+rozmiar);
  printf("%f",sr);
  return 0;
}


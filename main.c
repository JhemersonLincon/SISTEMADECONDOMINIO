#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "interface.h"
#include "utils.h"

int main()
{
  int tMoradores = 4;
  areaInterface();

  totalMoradores(tMoradores);
  //login(30,14);
  Caixa(75, 7, 40, 17, 0,LIGHT_CYAN, BLACK);
  areaMenu();
  getche();
  return 0;
}





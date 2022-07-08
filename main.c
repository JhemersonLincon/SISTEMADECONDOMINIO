#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "interface.h"
#include "utils.h"
#include "moradores.h"

int main()
{
  int tmoradores = 0;
  areaInterface();
  totalGetMoradores();
  //login(30, 14);
  //login(30,14);
  Caixa(75, 6, 40, 17, 0,LIGHT_CYAN, BLACK);
  areaMenu();
  getche();
  return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "interface.h"
#include "utils.h"
#include "moradores.h"

int main()
{
  //login(30, 14);
  areaInterface();
  totalGetMoradores();
  //login(30,14);
  Caixa(75, 6, 40, 17, 0,LIGHT_CYAN, BLACK);
  //Caixa(3, 25, 112, 1, 0, LIGHT_CYAN, BLACK);
  areaMenu();

  getche();
  return 0;
}





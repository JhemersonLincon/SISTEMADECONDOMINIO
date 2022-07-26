#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "interface.h"
#include "utils.h"
#include "moradores.h"
int main()
{
  adicionarAdm("Heveras", "jow");
  adicionarAdm("Isac", "123");
  adicionarAdm("lincon", "123");

  areaInterface();
  totalGetMoradores();
  programerAp("A1", 30.00, 5, 0, 450.00);
  programerAp("A2", 30.00, 5, 0, 450.00);
  programerAp("A3", 30.00, 5, 0, 450.00);
  programerAp("A4", 30.00, 5, 1, 450.00);
  Caixa(3, 25, 112, 1, 0, LIGHT_CYAN, BLACK);
  areaMenu();
  getche();
  return 0;
}

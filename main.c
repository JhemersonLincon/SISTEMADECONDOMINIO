#include <stdio.h>
#include <windows.h>
#include "interface.h"
#include "utils.h"
#include "moradores.h"
int main()
{
  guardarMoradorVetor();
  guardarAdmVetor();
  guardarApVetor();
  guardarPagamentoVetor();

  
  areaInterface();
  areaMenu();
  system("cls");
  return 0;
}

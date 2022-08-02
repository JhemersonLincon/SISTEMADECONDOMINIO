#include <stdio.h>
#include <windows.h>
#include "interface.h"
#include "utils.h"
#include "moradores.h"
#include "ocorrencias.h"
int main()
{
  guardarMoradorVetor();
  guardarAdmVetor();
  guardarApVetor();
  guardarPagamentoVetor();
  guardarOcorrenciaVetor();
  

  
  areaInterface();
  areaMenu();
  system("cls");
  return 0;
}

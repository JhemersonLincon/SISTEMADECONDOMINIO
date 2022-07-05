#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "interface.h"
#include "utils.h"
int logado = 0;
int main()
{
  Caixa(1, 1, 115, 26, 1, LIGHT_CYAN, BLACK);//Caixa principal
  Caixa(1, 0, 115, 1,  1,LIGHT_CYAN, BLACK);//caixa do cabeçalho

  Caixa(28, 5, 45, 17, 0,LIGHT_CYAN, BLACK);// primeira caixa da area principal
  Caixa(75, 5, 40, 17, 0,LIGHT_CYAN, BLACK);

  Data(90, 1);
  gotoxy(3, 0);printf("SISTEMA DE CONDOMINIO");
  int x[] = {4 ,4, 4, 4, 4};
  int y[] = {6, 10, 14, 18, 22};
  int opcao;
  getche();
  return 0;
}





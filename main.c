#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "interface.h"
#include "utils.h"

int main()
{
  Caixa(1, 1, 115, 26, 1);
  Caixa(3, 2, 110, 1,  1);
  Caixa(3, 5, 20, 17, 0);
  Caixa(5, 6, 20, 17, 0);
  Caixa(28, 5, 82, 17, 0);
  Caixa(30, 6, 82, 17, 0);
  Caixa(6, 21, 12, 1, 1);
  Caixa(3, 25, 109, 1, 1);
  Data();
  gotoxy(5, 3);printf("SISTEMA DE CONDOMINIO", 144);

  int x[] = {9,9,9,7};
  gotoxy(8, 9);printf("", 128,229);
  int y[] = {13, 15, 17, 22};
  char op[][51] = {"", "", "", ""};
  int opcao;
  do{
  int result;
  opcao = Menu(x,y, op, 4);

    if(opcao == 0){
    }
    else if(opcao == 3){
      textcoloreback(BLACK, WHITE);
    
    }
  }while(opcao != -1);

  getche();
  return 0;
}


  /*
  switch(opcao){
    case 0:
      Caixa(55, 8, 50, 10, 1);
      Caixa(58, 9, 40, 1, 1);
      gotoxy(72, 10);printf("TELA DE LOGIN");
      result = login(58, 14);
  }*/
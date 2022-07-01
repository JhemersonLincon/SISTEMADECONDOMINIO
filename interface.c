#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "interface.h"

void gotoxy(int x, int y){
  COORD c;
  c.X = x;
  c.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void textcoloreback (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras + (fundo << 4));
}

void Caixa(int x, int y, int largura, int altura,int tipo){

  int i, j;
  unsigned char C[][6] = {{218, 196, 191, 179, 192, 217},
                          {201, 205, 187, 186, 200, 188}};
  textcoloreback(BLUE, BLACK);
  gotoxy(x, y); printf("%c", C[tipo][0]);
  for(i = 0; i < largura; i++) printf("%c", C[tipo][1]);
  printf("%c\n", C[tipo][2]);
  for(i=0;i < altura;i++){
    gotoxy(x, y+i+1);printf("%c", C[tipo][3]);
    for(j=0;j< largura;j++) printf(" ");
    printf("%c", C[tipo][3]);
  }

  gotoxy(x, y+i+1); printf("%c", C[tipo][4]);
  for(i = 0; i < largura; i++) printf("%c", C[tipo][1]);
  printf("%c\n", C[tipo][5]);
  textcoloreback(WHITE, BLACK); 
}


int Menu(int x[], int y[], char opcoes[][51], int n){
  int i;
  char op;
  int ops = 0;
  do{ 
    textcoloreback(WHITE, BLACK); 
    for(i = 0; i < n;i++){
      if(ops == i)textcoloreback(BLUE, BLACK); 
      else textcoloreback(WHITE, BLACK); 

      gotoxy(x[i],y[i]);printf(" %s", opcoes[i]); 
      if(ops == i) textcoloreback(BLUE, BLACK); 
      else textcoloreback(BLACK, BLACK);
      gotoxy(x[i]+1,y[i]+1);printf("O%c%c%c%c%c%c%cO",205,205,205,205,205,205,205); 

    }
    op = getTecla();
    if(op == 'w' || op == 'W') ops--;
    if(op == 's' || op == 'S') ops++;
    if(ops < 0) ops = n-1;
    if(ops >= n) ops = 0;
    if(op == 'd'){
        tipoCursor(1);
      textcoloreback(WHITE, BLACK);
      return ops;
    }
  }while(op != 13);
    tipoCursor(1);
  textcoloreback(WHITE, BLACK);
  return ops;


}
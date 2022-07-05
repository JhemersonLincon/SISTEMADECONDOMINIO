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

void Caixa(int x, int y, int largura, int altura,int tipo, int caracter, int fundo){

  int i, j;
  unsigned char C[][6] = {{218, 196, 191, 179, 192, 217},
                          {201, 205, 187, 186, 200, 188}};
  textcoloreback(caracter, fundo);
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
      if(ops == i){
        Caixa(x[i]-1,y[i]-1, 20, 1, 0, LIGHT_CYAN, LIGHT_CYAN);
        textcoloreback(BLACK, LIGHT_CYAN); 
      }
      else{
        textcoloreback(WHITE, BLACK); 
      Caixa(x[i]-1,y[i]-1, 20, 1, 0, LIGHT_CYAN, BLACK);
      } 

      gotoxy(x[i],y[i]);printf("%s", opcoes[i]); 

    }
    op = getTecla();
    if(op == 'w' || op == 'W') ops--;
    if(op == 's' || op == 'S') ops++;
    if(ops < 0) ops = n-1;
    if(ops >= n) ops = 0;
    if(op == 'd' || op == 'D'){
        tipoCursor(1);
      textcoloreback(WHITE, BLACK);
      return ops;
    }
    if(op == 13)break;
  }while(op != 27);
    tipoCursor(1);
  textcoloreback(WHITE, BLACK);
  return ops;
}
void LimparTela(int x, int y, int largura, int altura){
  int i, j;
  for(i=0;i <= altura+1; i++){
    gotoxy(x,y+i);
    for(j=0; j <= largura+1;j++)printf(" ");
  }
}

void Rolavel(int vetor[], int n,int quant){
  int i, pos = 0, aux = 0;
  char teclado;
  do{
    for( i = pos; i < quant+pos;i++){
      gotoxy(1, 2+aux+1);printf("%d", vetor[i]);
      aux++;
    }
    aux = 0;
    teclado = getch();
    if(teclado == 'w')pos--;
    else if(teclado == 's')pos++;
    if(pos < 0)pos = n > 5? n-5: 0;
    if(pos > n-5)pos = 0;
  }while(teclado != 27);
} 
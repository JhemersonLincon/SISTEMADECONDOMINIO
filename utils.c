#include <time.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "utils.h"
#include "interface.h"


// Define se o cursor vai aparecer ou não
void tipoCursor(int cursor){
  HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO CURSOR;
  BOOL result;
  CURSOR.dwSize = 100;
  if(cursor == 0) CURSOR.bVisible = FALSE;
  else CURSOR.bVisible = TRUE;
  result = SetConsoleCursorInfo(myconsole, &CURSOR);

}
// Printa na tela a data atual
void Data(int x, int y){
  char meses[][51] = {"Janeiro", "Fevereiro", "Março", "Abril", "Junho", "Julho", "Agosto", "Setembro", "Outubro","Novembro", "Dezembro"};
  time_t mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  //gotoxy(85, 3);printf("%d : %d : %d",tm.tm_hour,tm.tm_min,tm.tm_sec);
  gotoxy(x, y);printf("Brasil - %s %d, %d",meses[tm.tm_mon-1], tm.tm_mday, tm.tm_year+1900);
}
int getTecla(){
    int ch;
    ch = getch();
    if(ch == 224){
        ch = getch() + 1000;
    }
    return ch;
}

void totalGetMoradores(){

  Caixa(84, 3, 30, 1, 0,LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(94, 4);printf("Moradores: %d\n", getTotalMoradores());
  textcoloreback(LIGHT_CYAN, BLACK);
}

int sairCadastrar(int x, int y){
  int xO[] = {x, x+20};
  int yO[] = {y+12, y+12};
  char op[][51] = {"CADASTRAR MAIS", "SAIR"};
  int opcao = Menu(xO, yO, op, 2, 1);
  return opcao;
}

int sairListar(int x, int y){
  int xO[] = {x, x+20};
  int yO[] = {y+12, y+12};
  char op[][51] = {"PESQUISAR MAIS", "SAIR"};
  int opcao = Menu(xO, yO, op, 2, 1);
  return opcao;
}

int maisOpcoes(int x, int y){
  int xO[] = {x, x+20};
  int yO[] = {y+12, y+12};
  char op[][51] = {"MAIS OPCOES", "SAIR"};
  int opcao = Menu(xO, yO, op, 2, 1);
  return opcao;
}

void converterMaiusculo(char vetor[]){
  int i;
  for(i = 0; i < strlen(vetor); i++){
    if(isalpha(vetor[i]) == 2) vetor[i] =  toupper(vetor[i]);
  }
}

int maisOpcoesArea(int x, int y,char op[][51], int t){
  LimparTela(x, y, 40, 17);
  Caixa(x, y, 40, 17, 0,LIGHT_CYAN, BLACK);
  Caixa(x+3, y+1, 35, 1, 0,LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+4, y+2);printf("OPCOES");
  textcoloreback(LIGHT_CYAN, BLACK);
  int opcao;
  int xO[] = {x+4, x+4, x+4, x+4};
  int yO[] = {y+6, y+9, y+12, y+15};

  opcao = Menu(xO, yO, op, t, 0);
  areaApartamentosLivres(75, 6);
  return opcao;
}
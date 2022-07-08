#include <time.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "utils.h"
#include "interface.h"

void tipoCursor(int cursor){
  HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO CURSOR;
  BOOL result;
  CURSOR.dwSize = 100;
  if(cursor == 0) CURSOR.bVisible = FALSE;
  else CURSOR.bVisible = FALSE;
  result = SetConsoleCursorInfo(myconsole, &CURSOR);

}
void Data(int x, int y){
  char meses[][51] = {"Janeiro", "Fevereiro", "Março", "Abril", "Junho", "Julho", "Agosto", "Setembro", "Outubro","Novembro", "Dezembro"};
  tipoCursor(0);
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

int login(int x, int y){
  Caixa(x-2,y-7,70,14,0, LIGHT_CYAN, BLACK);
  Caixa(x,y-5,65,0,0, LIGHT_CYAN, LIGHT_CYAN);
  usuario adm;
  strcpy(adm.usuario,"house");
  strcpy(adm.senha, "wendus");
  
  gotoxy(x, y);printf("Usuario de acesso: ");
  gotoxy(x, y+3);printf("Digite senha de acesso: ");
  while(1){
    usuario user;
    int cont = 0;
    LimparTela(x+19,y, 10,0);
    LimparTela(x+24,y+3, 10,0);
    gotoxy(x+19, y); scanf(" %[^\n]", user.usuario);

    fflush(stdin);
    gotoxy(x+24, y+3);
    do{
      user.senha[cont]  = getTecla();

      if(user.senha[cont] == 8){
        printf("\b \b");
        cont--;
      }
      else if(user.senha[cont] == 13){
        user.senha[cont] = '\0';
        break;
      }
      else{
        putchar('*');
        cont++;
      }
    }while(user.senha[cont] != 1027);

    if(!(strcmp(adm.usuario, user.usuario)) && !(strcmp(adm.senha, user.senha))){
      LimparTela(x-2,y-7,70,14);
      return 1;
    }
  }
}

void totalGetMoradores(){

  Caixa(84, 3, 30, 1, 0,LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(94, 4);printf("Moradores: %d\n", getTotalMoradores());
  textcoloreback(LIGHT_CYAN, BLACK);
}
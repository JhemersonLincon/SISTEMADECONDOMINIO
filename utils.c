#include <time.h>
#include <stdio.h>
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
void Data(){
  char meses[][51] = {"Janeiro", "Fevereiro", "Março", "Abril", "Junho", "Julho", "Agosto", "Setembro", "Outubro","Novembro", "Dezembro"};
  tipoCursor(0);
  time_t mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  Sleep(60);
  //gotoxy(85, 3);printf("%d : %d : %d",tm.tm_hour,tm.tm_min,tm.tm_sec);
  gotoxy(90, 3);printf("Brasil - %s %d, %d",meses[tm.tm_mon-1], tm.tm_mday, tm.tm_year+1900);
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
  usuario user;
  gotoxy(x, y);printf("Usuario de acesso: ");
  gotoxy(x, y+2);printf("Digite senha de acesso: ");
  gotoxy(x, y);printf("Usuario de acesso: ");
  scanf(" %[^\n]%", user.usuario);

  gotoxy(x, y+2);printf("Digite senha de acesso: ");
  scanf("%s", user.senha);

  return 1;
}
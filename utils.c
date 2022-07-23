#include <time.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "utils.h"
#include "interface.h"

usuario adm[10];
int tAdm = 2;
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
//faz o sistema de login executar
int login(int x, int y){
  Caixa(x-2,y-7,70,14,0, LIGHT_CYAN, BLACK);
  Caixa(x,y-5,65,0,0, LIGHT_CYAN, LIGHT_CYAN);

  strcpy(adm[0].usuario,"house");
  strcpy(adm[0].senha, "wendus");
  // Isac
  strcpy(adm[1].usuario,"isac");
  strcpy(adm[1].senha, "123");
  int i;
  gotoxy(x, y);printf("Usuario de acesso: ");
  gotoxy(x, y+3);printf("Digite senha de acesso: ");
  while(1){
    usuario user;
    int cont = 0;
    LimparTela(x+19,y, 10,0);
    LimparTela(x+24,y+3, 10,0);
    gotoxy(x+19, y); scanf(" %[^\n]", user.usuario);
    gotoxy(x+24, y+3);
    do{
      user.senha[cont]  = getTecla();

      if(user.senha[cont] == 8 && cont > 0){
        printf("\b \b");
        cont--;
      }
      else if(user.senha[cont] == 13){
        user.senha[cont] = '\0';
        break;
      }
      else if(user.senha[cont] != 8){
        putchar('*');
        cont++;
      }
    }while(user.senha[cont] != 27);
    for(i = 0; i <  tAdm; i++){
      if(!(strcmp(adm[i].usuario, user.usuario)) && !(strcmp(adm[i].senha, user.senha))){
        LimparTela(x-2,y-7,70,14);
        return 1;
      }
    }
  }
}

void totalGetMoradores(){

  Caixa(84, 3, 30, 1, 0,LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(94, 4);printf("Moradores: %d\n", getTotalMoradores());
  textcoloreback(LIGHT_CYAN, BLACK);
}

int selecao(int x , int y, int larg, int alt, char opcoes[][101], int n, int opcao){
    Caixa(x, y, larg, alt,0,LIGHT_CYAN, BLACK);
    char tecla, i;
    int primeiro = 0;
    textcoloreback(0, 7);
    for(i = 0; i < alt; i++){
        gotoxy(x+1, y+1+i);printf("%*s",-larg, opcoes[primeiro+i]);
    }
    do{
        textcoloreback(2, 0);
        gotoxy(x+1, y+1+opcao - primeiro);printf("%*s",-larg, opcoes[opcao]);
        tecla = getTecla();
        textcoloreback(0, 7);
        gotoxy(x+1, y+1+opcao - primeiro);printf("%*s",-larg, opcoes[opcao]);

        if(tecla == 's')opcao++;
        if(tecla == 'w')opcao--;
        if(tecla == 13)return opcao;
        if(opcao < 0) opcao = 0;
        if(opcao > n-1) opcao = n-1;
        if(opcao > primeiro + alt-1){
            primeiro++;
            for(i = 0; i < alt; i++){
              gotoxy(x+1, y+1+i);printf("%*s",-larg, opcoes[primeiro+i]);
            }
        }
        else if(opcao < primeiro){
          primeiro--;
          for(i = 0; i < alt; i++){
            gotoxy(x+1, y+1+i);printf("%*s",-larg, opcoes[primeiro+i]);
          }
        }
    }while(1);
}
void cpfLimpo(char cpf[]){

  int i;
  for(i=0;i < 15 ; i++){
    if(i == 3 || i == 7)cpf[i] = '.';
    else if(i == 11)cpf[i] = '-';
    else if(i == 15)cpf[i] = '\0';
    else cpf[i] = getch();

    if(cpf[i] == 8){
      printf("\b \b");
      i--;
    }

    else if(cpf[i] == 13 && i > 0){
      cpf[i] = '\0';
      break;
    }

    else printf("%c", cpf[i]);
  }
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
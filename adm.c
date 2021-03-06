#include "adm.h"


int tAdms = 0;

Login adms[5];

int adicionarAdm(char nome[51], char login[51]){
  int i;
  for(i = 0;i < tAdms; i++){
    if(!strcmp(adms[tAdms].nome, nome))return 0;
  }
  strcpy(adms[tAdms].nome, nome);
  strcpy(adms[tAdms].login, login);
  tAdms++;
  return 1;
}

void CadastrarAdm(int x, int y){
    Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("CADASTRA ADIMINISTRADOR");
    int opcao;
    do{
      textcoloreback(WHITE, BLACK);
      Login login;
      gotoxy(x, y); printf("Administrador:                          ");
      gotoxy(x,y+2);printf("Login:                                  ");
      tipoCursor(1);
      gotoxy(x, y);  printf("Administrador: "); scanf(" %[^\n]", login.nome);
      gotoxy(x, y+2);printf("Login: "); scanf(" %[^\n]", login.login);
      int confirmacao = adicionarAdm(login.nome, login.login);
      tipoCursor(0);
      gotoxy(x, y+12);confirmacao?printf("Administrador Cadastrado..."):printf("Administrador ja existe...");
      Sleep(500);
      tipoCursor(1);
      opcao = sairCadastrar(x, y);
    }while(opcao == 0);

}

void ImprimirAdm(int x, int y, Login login){
  Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+10,y-3);printf("LISTAR ADMINISTRADORES");
  textcoloreback(WHITE, BLACK);
  gotoxy(x, y);printf("Administrador: ");       printf("%s", login.nome);
}

void areaAdm(int x, int y){
    int opcao;
    int xo[] = {x+24, x+24};
    int yo[] = {y-3, y+0};
    char op[][51] = {"CADASTRAR", "LISTAR ADM"};
   
    textcoloreback(WHITE, BLACK); 
    Login login;
    opcao = Menu(xo, yo, op, 2, 0);
    LimparTela(x+23, y-10, 20, 10);
    //Caixa(x[opcao]+24, y[opcao]-2, 20, 3, 0,LIGHT_CYAN, BLACK);
    if(opcao != -1)Caixa(28, 6, 45, 17, 0,LIGHT_CYAN, BLACK);
    switch(opcao){
      case 0:
        CadastrarAdm(30, 10);
        break;
      
      case 1:
        listarAdms(30, 10);
        break;
      
      default: break;
    }

}

void listarAdms(int x, int y){
    if(login(30, 13, 45, 17)){
      int op = -1;
      int opcao;
      do{
          if(tAdms) op = selecaoAdms(x-2, y-4, 45, 17, adms,tAdms, 0);
          LimparTela(x-1,y, 43, 11);
          if(op != -1 && tAdms > 0) {
              ImprimirAdm(x, y, adms[op]);  
              opcao = maisOpcoes(x, y);
              if(opcao == 0){
                  char op[][51] = {"APARTAMENTO ALUGADO", "EXCLUIR MORADOR", "SAIR"};
                  opcao = maisOpcoesArea(75, 6, op, 3);
              }
              else break;

          }
          opcao = sairListar(x, y);
      }while(opcao == 0);
    }
}
// Selecionar o morador na lista de moradores
int selecaoAdms(int x , int y, int larg, int alt,Login adms[], int total, int opcao){
    Caixa(x, y, larg, alt,0,LIGHT_CYAN, BLACK);
    Caixa(30,10-4 ,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(30+11,10-3);printf("LISTA DE MORADORES");
    textcoloreback(WHITE, BLACK);
    char tecla;
    int i;
    int primeiro = 0;
    textcoloreback(WHITE, BLACK);
    for(i = 0; i < total; i++){
        gotoxy(x+1, y+4+i);printf("%*s",-larg, adms[primeiro+i].nome);
    }
    do{
        textcoloreback(BLACK, LIGHT_CYAN);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, adms[opcao].nome);
        tecla = getTecla();
        textcoloreback(WHITE, BLACK);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, adms[opcao].nome);
        if(tecla == 's' || tecla == 'S')opcao++;
        if(tecla == 'w' || tecla == 'W')opcao--;
        if(tecla == 13)return opcao;
        if(opcao < 0) opcao = 0;
        if(opcao > total-1) opcao = total-1;
        if(opcao > primeiro + alt-1){
            primeiro++;
            for(i = 0; i < alt; i++){
               gotoxy(x+1, y+1+i);printf("%*s",-larg, adms[primeiro+i].nome);
            }
        }
        else if(opcao < primeiro){
                primeiro--;
            for(i = 0; i < alt; i++){
                gotoxy(x+1, y+1+i);printf("%*s",-larg, adms[primeiro+i].nome);
            }
        }
    }while(1);
}
//faz o sistema de login executar
int login(int x, int y, int largura, int altura){
  Caixa(x-2,y-7,largura,altura,0, LIGHT_CYAN, BLACK);
  //Caixa(x,y-5,largura-4,0,0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(LIGHT_CYAN, BLACK);
  gotoxy(x, y-5);printf("FAZER LOGIN");
  int i;
  int xO[] = {x, x+20};
  int yO[] = {y+8, y+8};
  char op[][51] = {"FAZER LOGIN", "SAIR"};
  int opcao = Menu(xO, yO, op, 2, 1);
  textcoloreback(LIGHT_CYAN, BLACK);
  if(opcao == 1){
    LimparTela(x,y, 50,8);
    return 0;
  }
  textcoloreback(WHITE, BLACK);
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
    for(i = 0; i <  tAdms; i++){
      if(!(strcmp(adms[i].nome, user.usuario)) && !(strcmp(adms[i].login, user.senha))){
        LimparTela(x-2,y-7,largura,altura);
        return 1;
      }
    }
  }
}
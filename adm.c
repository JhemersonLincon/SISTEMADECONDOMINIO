#include "adm.h"

int tAdms = 0;

Login adms[100];
FILE *fpAdm;

void abrirAdmArquivo(){
  fpAdm = fopen("adm.txt", "rb+");
  if(fpAdm == NULL){
      fpAdm = fopen("adm.txt", "wb+");
      if(fpAdm == NULL){
        printf("Falha em abrir o arquivo.\n");
        exit(1);
      }

  }
}
void fecharAdmArquivo(){
  fclose(fpAdm);
}

int adicionarAdm(Login adm){
  int i;
  for(i = 0;i < tAdms; i++){
    if(!strcmp(adms[tAdms].nome, adm.nome))return 0;
  }
  adms[tAdms] = adm;
  abrirAdmArquivo();
  fseek(fpAdm, 0, SEEK_END);
  fwrite(&adm, sizeof(Login), 1, fpAdm);
  fecharAdmArquivo();
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
      int confirmacao = adicionarAdm(login);
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

void guardarAdmVetor(){

    abrirAdmArquivo();
    fseek(fpAdm, 0, SEEK_SET);

    while(fread(&adms[tAdms], sizeof(Login), 1, fpAdm)){
      tAdms++;
    }
    fecharAdmArquivo();
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
          if(opcao != -1 && tAdms > 0) opcao = sairListar(x, y);
          
      }while(opcao == 0);
    }
}
// Selecionar o morador na lista de moradores
int selecaoAdms(int x , int y, int larg, int alt,Login adms[], int total, int opcao){
    Caixa(x, y, larg, alt,0,LIGHT_CYAN, BLACK);
    Caixa(30,10-4 ,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(30+11,10-3);printf("LISTA DE ADMINISTRADORES");
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
        if(tecla == 27){
          return -1;
        }
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

  LimparTela(x,y-4, 30,8);
  //Caixa(x,y-5,largura-4,0,0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(LIGHT_CYAN, BLACK);
  gotoxy(x, y-3);printf("FAZER LOGIN");
  int i;
  int xO[] = {x, x+20};
  int yO[] = {y+9, y+9};
  char op[][51] = {"FAZER LOGIN", "SAIR"};
  int opcao = Menu(xO, yO, op, 2, 1);
  textcoloreback(LIGHT_CYAN, BLACK);
  if(opcao == 1 || opcao == -1){
    LimparTela(x,y, 35,8);
    return 0;
  }
  textcoloreback(WHITE, BLACK);
  gotoxy(x, y);printf("Usuario de acesso: ");
  gotoxy(x, y+3);printf("Digite senha de acesso: ");
  while(1){
    tipoCursor(1);
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
        tipoCursor(0);
        break;
      }
      else if(user.senha[cont] != 8){
        putchar('*');
        cont++;
      }
    }while(user.senha[cont] != 27);
    for(i = 0; i <  tAdms; i++){
      if(!(strcmp(adms[i].nome, user.usuario)) && !(strcmp(adms[i].login, user.senha))){
        tipoCursor(0);
        LimparTela(x-1,y-4,largura-4,altura-5);

        return 1;
      }
    }
  }
}
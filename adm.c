#include "adm.h"
#include"interface.h"

int tadm = 0;

Login adm[5];

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

        adm[tadm] = login;
        tadm++;

    }while(opcao == 0);

}

void ImprimirAdm(int x, int y, Login login){
    
    Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("LISTAR ADMINISTRADORES");
    gotoxy(x, y);printf("Administrador: ");       printf("%s", login.nome);
    system("pause");

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
        ImprimirAdm(30, 10, login);
        break;
      
      default: break;
    }

}
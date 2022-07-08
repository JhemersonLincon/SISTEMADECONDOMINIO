#include "moradores.h"
#include "interface.h"
int tMoradores = 0;
Morador moradores[100];
// Puxar quantidade de moradores
int getTotalMoradores(){
    return tMoradores;
}

// cadastrar morador - imcompleto
Morador cadastrarMorador(int x, int y){
    char tecla;
    do{
        Morador morador;
        gotoxy(x, y);  printf("Dono: ");
        gotoxy(x, y+2);printf("Idade: ");
        gotoxy(x, y+4);printf("CPF");                        
        gotoxy(x, y+6);printf("Data de pagamento do aluguel: ");
        gotoxy(x, y+8);printf("Telefone: ");  

        gotoxy(x, y);  printf("Dono: ");                        scanf(" %[^\n]", morador.dono);
        gotoxy(x, y+2);printf("Idade: ");                       scanf("%d", &morador.idade);
        gotoxy(x, y+4);printf("CPF: ");                         scanf("%s", morador.cpf);
        gotoxy(x, y+6);printf("Data de pagamento do aluguel: ");scanf("%d", &morador.datapagamento);
        gotoxy(x, y+8);printf("Telefone: ");                    scanf("%d", &morador.tel);
        moradores[tMoradores] = morador;
        tMoradores++;
        totalGetMoradores();
        gotoxy(x, y+12);printf("Digite ESC para sair...");
        tecla = getch();
    }while(tecla != 27);
}

// mostra na tela o morador selecionado ou a lista inteira
void ImprimirMorador(int x, int y, Morador morador[], int N, int pos){
    int i;
    if(N == 0){
        gotoxy(x, y);  printf("Dono: ");                        printf("%s", morador[pos].dono);
        gotoxy(x, y+2);printf("Idade: ");                       printf("%d", morador[pos].idade);
        gotoxy(x, y+4);printf("CPF: ");                         printf("%s", morador[pos].cpf);                     
        gotoxy(x, y+6);printf("Data de pagamento do aluguel: ");printf("%d", morador[pos].datapagamento);
        gotoxy(x, y+8);printf("Telefone: ");                    printf("%d", morador[pos].tel);
    }

    else{
        for(i=0; i<N; i++){
            printf("%c", morador[i].dono);
            printf("%d", morador[i].idade);
            printf("%c", morador[i].cpf);
            printf("%d", morador[i].datapagamento);
            printf("%d", morador[i].tel);
        }
    }

}

// area selecionada de moradores
void areaMoradores(int x, int y){
    int xO[] = {x+24, x+24, x+24};
    int yO[] = {y-1, y+2, y+5};
    char opO[][51] = {"CADASTRAR MORADORES", "LISTAR MORADORES", "PESQUISAR MORADOR"};
    int opcao = Menu(xO, yO, opO, 3);
    LimparTela(x+23, y-3, 20, 10);
    if(opcao != -1)Caixa(28, 6, 45, 17, 0,LIGHT_CYAN, BLACK);// primeira caixa da area principal
    if(opcao == 0) cadastrarMorador(30, 10);
    else if(opcao == 2)pesquisaMoradores();

}

// pesquisa o morador pelo cpf e nome
void pesquisaMoradores(){   
    char dono[51], cpf[51];
    gotoxy(30, 10);printf("Dono: ");
    gotoxy(30, 12);printf("CPF: ");
    gotoxy(30, 10);printf("Dono: ");scanf("%s", dono);
    gotoxy(30, 12);printf("CPF: ");scanf("%s", cpf);

    int i;
    for(i=0;i < tMoradores; i++){
        if(strcmp(moradores[i].cpf, cpf) == 0 || strcmp(moradores[i].dono, dono) == 0){
            ImprimirMorador(30, 10, moradores, 0, i );
            break;
            
        }
    }
}
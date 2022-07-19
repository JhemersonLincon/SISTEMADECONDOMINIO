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
    Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("CADASTRO DE MORADOR");
    int opcao;
    char tecla;
    do{
        textcoloreback(WHITE, BLACK);
        tipoCursor(1);
        Morador morador;
        gotoxy(x, y);  printf("Dono:                           ");
        gotoxy(x, y+2);printf("Idade:                          ");
        gotoxy(x, y+4);printf("CPF:                            ");                        
        gotoxy(x, y+6);printf("Data de pagamento do aluguel:   ");
        gotoxy(x, y+8);printf("Telefone:                       ");  

        gotoxy(x+5, y);                    scanf(" %[^\n]", morador.dono);
        gotoxy(x+7, y+2);                  scanf(" %d", &morador.idade);
        gotoxy(x+4, y+4);                  scanf("%s", morador.cpf);
        gotoxy(x+30, y+6);                 scanf(" %d", &morador.datapagamento);
        gotoxy(x+10, y+8);                 scanf(" %[^\n]", morador.tel);
        moradores[tMoradores] = morador;
        tMoradores++;
        totalGetMoradores();
        opcao = sairCadastrar(x, y);
        LimparTela(x-1,y-1, 40, 13);
    }while(opcao == 0 );
}
// mostra na tela o morador selecionado ou a lista inteira
void ImprimirMorador(int x, int y, Morador morador[], int N, int pos){
    int i;
    if(N == 0){
        gotoxy(x, y);  printf("Dono: ");                        printf("%s", morador[pos].dono);
        gotoxy(x, y+2);printf("Idade: ");                       printf("%d", morador[pos].idade);
        gotoxy(x, y+4);printf("CPF: ");                         printf("%s", morador[pos].cpf);                     
        gotoxy(x, y+6);printf("Data de pagamento do aluguel: ");printf("%d", morador[pos].datapagamento);
        gotoxy(x, y+8);printf("Telefone: ");                    printf("%c", morador[pos].tel);
    }

    else{
        for(i=0; i<N; i++){
            printf("%c", morador[i].dono);
            printf("%d", morador[i].idade);
            printf("%c", morador[i].cpf);
            printf("%d", morador[i].datapagamento);
            printf("%c", morador[i].tel);
        }
    }

}
// area selecionada de moradores
void areaMoradores(int x, int y){
    int xO[] = {x+24, x+24, x+24};
    int yO[] = {y-1, y+2, y+5};
    char opO[][51] = {"CADASTRAR MORADORES", "LISTAR MORADORES", "PESQUISAR MORADOR"};
    int opcao = Menu(xO, yO, opO, 3, 0);
    LimparTela(x+23, y-3, 20, 10);
    if(opcao != -1)Caixa(28, 6, 45, 17, 0,LIGHT_CYAN, BLACK);// primeira caixa da area principal
    switch(opcao){
        case 0:
            cadastrarMorador(30, 10);
            break;
        case 1:
            listarMoradores(moradores, tMoradores);
            break;
        case 2:
             pesquisaMoradores(30, 10);
             break;
        default: break;
    }
}
//listar Moradores
void listarMoradores(Morador moradores[], int total){
    int op = -1;
    char tecla;
    do{
        if(tMoradores) op = selecaoMoradores(28, 6, 45, 17, moradores, tMoradores, 0);
        else {gotoxy(37, 7);printf("Nao a moradores cadastrados");}
        LimparTela(30,10, 40, 5);
        if(op != -1) ImprimirMorador(30, 10, moradores, 0, op );
            gotoxy(30, 22);printf("Digite ESC para sair...");
        tecla = getch();
    }while(tecla != 27);
}
// Selecionar o morador na lista de moradores
int selecaoMoradores(int x , int y, int larg, int alt,Morador moradores[], int total, int opcao){
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
        gotoxy(x+1, y+4+i);printf("%*s",-larg, moradores[primeiro+i].dono);
    }
    do{
        textcoloreback(BLACK, LIGHT_CYAN);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, moradores[opcao].dono);

        tecla = getTecla();
        textcoloreback(WHITE, BLACK);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, moradores[opcao].dono);
        if(tecla == 's')opcao++;
        if(tecla == 'w')opcao--;
        if(tecla == 13)return opcao;
        if(opcao < 0) opcao = 0;
        if(opcao > total-1) opcao = total-1;
        if(opcao > primeiro + alt-1){
            primeiro++;
            for(i = 0; i < alt; i++){
                gotoxy(x+1, y+1+i);printf("%*s",-larg, moradores[primeiro+i].dono);
            }
        }
        else if(opcao < primeiro){
                primeiro--;
                for(i = 0; i < alt; i++){
        gotoxy(x+1, y+1+i);printf("%*s",-larg, moradores[primeiro+i].dono);
    }
        }

    }while(1);
}
// pesquisa o morador pelo cpf e nome
void pesquisaMoradores(int x, int y){   
    Caixa(x,y-4 ,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("PESQUISAR MORADOR");
    textcoloreback(WHITE, BLACK);
    char tecla;
    do{
        char dono[51], cpf[51];
        LimparTela(x,y, 40, 12);
        gotoxy(x, y);printf("Dono: ");
        gotoxy(x, y+2);printf("CPF: ");
        gotoxy(x, y);printf("Dono: ");scanf(" %[^\n]", dono);
        gotoxy(x, y+2);printf("CPF: "); scanf("%s", cpf);

        int i;
        for(i=0;i < tMoradores; i++){
            if(strcmp(moradores[i].cpf, cpf) == 0 || strcmp(moradores[i].dono, dono) == 0){
                LimparTela(x,y, 40, 10);
                ImprimirMorador(x, y, moradores, 0, i );
                break;
            }
        }
        gotoxy(x, y+12);printf("Digite ESC para sair...");
        tecla = getch();
    }while(tecla != 27);
}


// Ocorrencias 
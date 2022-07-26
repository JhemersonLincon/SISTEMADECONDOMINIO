#include "moradores.h"
#include "interface.h"
int tMoradores = 0;
Morador moradores[100];

void adicionarMorador(char dono[51], int idade, char cpf[], int datapagamento, char tele[], char numero[]){
  strcpy(moradores[tMoradores].dono, dono);
  moradores[tMoradores].idade = idade;
  strcpy(moradores[tMoradores].cpf, cpf);
  strcpy(moradores[tMoradores].tel, tele);
  strcpy(moradores[tMoradores].apartamento.num, numero);
  tMoradores++;
}
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
    do{
        textcoloreback(WHITE, BLACK);
        Morador morador;
        gotoxy(x, y);  printf("Dono:                           ");
        gotoxy(x, y+2);printf("Idade:                          ");
        gotoxy(x, y+4);printf("CPF:                            ");                        
        gotoxy(x, y+6);printf("Data de pagamento:   ");
        gotoxy(x, y+8);printf("Telefone:                       ");  
        gotoxy(x, y+10);printf("Apartamento:                   ");  

        tipoCursor(1);
        gotoxy(x, y);  printf("Dono: ");                         scanf(" %[^\n]", morador.dono);
        gotoxy(x, y+2);printf("Idade: ");                        scanf(" %d", &morador.idade);
        gotoxy(x, y+4);printf("CPF: ");                          scanf(" %s", morador.cpf);
        gotoxy(x, y+6);printf("Data de pagamento: ");            scanf(" %d", &morador.datapagamento);
        gotoxy(x, y+8);printf("Telefone: ");                     scanf(" %s", morador.tel);
        gotoxy(x, y+10);printf("Apartamento: ");                 scanf(" %s", morador.apartamento.num);
        morador.apartamento = puxarAp(morador.apartamento);
        adicionarMorador(morador.dono, morador.idade, morador.cpf, morador.datapagamento, morador.tel, morador.apartamento.num);
        totalGetMoradores();
        opcao = sairCadastrar(x, y);
        LimparTela(x-1,y-1, 40, 13);
    }while(opcao == 0);
}
// mostra na tela o morador selecionado ou a lista inteira
void ImprimirMorador(int x, int y, Morador morador){
    gotoxy(x, y);  printf("Dono: ");                        printf("%s", morador.dono);
    gotoxy(x, y+2);printf("Idade: ");                       printf("%d", morador.idade);
    gotoxy(x, y+4);printf("CPF: ");                         printf("%s", morador.cpf);                     
    gotoxy(x, y+6);printf("Data de pagamento do aluguel: ");printf("%d", morador.datapagamento);
    gotoxy(x, y+8);printf("Telefone: ");                    printf("%s", morador.tel);
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
            listarMoradores(30, 10);
            break;
        case 2:
            pesquisaMoradores(30, 10);
            break;
        default: break;
    }
}
//listar Moradores
void listarMoradores(int x, int y){
    int op = -1;
    int opcao;
    do{
        if(tMoradores) op = selecaoMoradores(x-2, y-4, 45, 17, moradores, tMoradores, 0);
        LimparTela(x-1,y, 43, 11);

        if(op != -1 && tMoradores > 0) {
            ImprimirMorador(x, y, moradores[op]);  
            opcao = maisOpcoes(x, y);
            if(opcao == 0){
                char op[][51] = {"APARTAMENTO ALUGADO", "EXCLUIR MORADOR", "SAIR"};
                opcao = maisOpcoesArea(75, 6, op, 3);
            }
            else break;
            if(opcao == 0) apartamentoEmMorador(75, 6, moradores[op].apartamento);
            else if(opcao == 1) excluirMorador(op);
        }
        opcao = sairListar(x, y);
    }while(opcao == 0);
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
        if(tecla == 's' || tecla == 'S')opcao++;
        if(tecla == 'w' || tecla == 'W')opcao--;
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
    int opcao, encontrado = 0;
    do{
        char dono[51], cpf[51];
        LimparTela(x-1,y, 40, 12);
        gotoxy(x, y);printf("Dono: ");
        gotoxy(x, y+2);printf("CPF: ");
        gotoxy(x, y);printf("Dono: ");scanf(" %[^\n]", dono);
        gotoxy(x, y+2);printf("CPF: "); scanf("%s", cpf);

        int i;
        for(i=0;i < tMoradores; i++){
            if(strcmp(moradores[i].cpf, cpf) == 0 || strcmp(moradores[i].dono, dono) == 0){
                LimparTela(x,y, 40, 10);
                ImprimirMorador(x, y, moradores[i]);
                encontrado = 1;
                break;
            }
        }
        if(encontrado){
            opcao = maisOpcoes(x, y);
            char op[][51] = {"PESQUISAR MAIS", "EXCLUIR MORADOR", "ALTERAR MORADOR", "SAIR"};
            if(opcao == 0) opcao = maisOpcoesArea(75, 6, op, 4);
        }
        else opcao = sairListar(x, y);
    }while(opcao == 0);
}

void excluirMorador(int op){
    int i, j;
    if(login(30, 13, 45, 17)){
        
    }
    Morador aux;
    strcpy(moradores[op].dono, " ");
    strcpy(moradores[op].tel, " ");
    strcpy(moradores[op].cpf, " ");
    moradores[op].datapagamento = 0;
    moradores[op].idade = 0;
    esvaziarApartamento(moradores[op].apartamento);
    
    for(i = op; i < tMoradores+2; i++){
        for(j = i+1; j < tMoradores; j++){
            aux = moradores[i];
            moradores[i] = moradores[j];
            moradores[j] = aux;
        }
    }
    tMoradores--;
    totalGetMoradores();
    strcpy(moradores[op].cpf, " ");
}
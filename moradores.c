#include "moradores.h"

int tMoradores = 0;
Morador moradores[100];

FILE *fpMorador;
void abrirMoradorArquivo(){
    fpMorador = fopen("Morador.txt", "rb+");
    if(fpMorador == NULL){
        fpMorador = fopen("Morador.txt", "wb+");
        if(fpMorador == NULL){
            printf("Falha em abrir o arquivo.\n");
            exit(1);
        }
    }
}
void fecharMoradorArquivo(){
    fclose(fpMorador);
}
void adicionarMorador(Morador morador){
    moradores[tMoradores] = morador;
    Pagamento pagamento;

    strcpy(pagamento.pagador,morador.dono);
    pagamento.valorPagamento = morador.apartamento.aluguel;
    pagamento.diaPagamento = morador.datapagamento;

    adicionarPagamento(pagamento);

    abrirMoradorArquivo();
    fseek(fpMorador, 0, SEEK_END);
    fwrite(&morador, sizeof(Morador), 1, fpMorador);
    fecharMoradorArquivo();
    tMoradores++;
}

// Puxar quantidade de moradores
// cadastrar morador - imcompleto
void cadastrarMorador(int x, int y){
    Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("CADASTRO DE MORADOR");
    int opcao;
    do{
        if((getTotalApartamentos() - getTotalMoradores())){
            textcoloreback(WHITE, BLACK);
            Morador morador;
            gotoxy(x, y);  printf("Dono:                           ");
            gotoxy(x, y+2);printf("Idade:                          ");
            gotoxy(x, y+4);printf("CPF:                            ");                        
            gotoxy(x, y+6);printf("Telefone:                       ");  
            gotoxy(x, y+8);printf("Apartamento:                   ");  

            tipoCursor(1);
            gotoxy(x, y);  printf("Dono: ");                         scanf(" %[^\n]", morador.dono);
            gotoxy(x, y+2);printf("Idade: ");                        scanf(" %d", &morador.idade);
            gotoxy(x, y+4);printf("CPF: ");                          scanf(" %s", morador.cpf);
            gotoxy(x, y+6);printf("Telefone: ");                     scanf(" %s", morador.tel);
            gotoxy(x, y+8);printf("Apartamento: ");                 scanf(" %s", morador.apartamento.num);

            morador.datapagamento = Datas(90,1);

            converterMaiusculo(morador.apartamento.num);
            alterarDisp(morador.apartamento.num, 1);
            morador.apartamento = puxarAp(morador.apartamento);
            adicionarMorador(morador);
            totalGetMoradores();
            areaApartamentosLivres(75, 6);
        }
        else {gotoxy(x, y);printf("Sem apartamentos disponiveis");}
        opcao = sairCadastrar(x, y);
        LimparTela(x-1,y-1, 40, 13);
    }while(opcao == 0);
}
// mostra na tela o morador selecionado ou a lista inteira
int ImprimirMorador(int x, int y, Morador morador){
    if(login(30, 13, 45, 17)){
        gotoxy(x, y);  printf("Dono: ");                        printf("%s", morador.dono);
        gotoxy(x, y+2);printf("Idade: ");                       printf("%d", morador.idade);
        gotoxy(x, y+4);printf("CPF: ");                         printf("%s", morador.cpf);                     
        gotoxy(x, y+6);printf("Data de pagamento do aluguel: ");printf("%d", morador.datapagamento);
        gotoxy(x, y+8);printf("Telefone: ");                    printf("%s", morador.tel);
        return 1;
    }
    return 0;
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
                char op[][51] = {"APARTAMENTO", "EXCLUIR MORADOR","ALTERAR MORADOR", "SAIR"};
                opcao = maisOpcoesArea(75, 6, op, 4);
            }
            else break;
            switch(opcao){
                case 0:
                    apartamentoEmMorador(75, 6, moradores[op].apartamento);
                    break;
                case 1: 
                    excluirMorador(op);
                    break;
                case 2:
                    alterarMorador(30, 10, op);
                    break;
                default: break; 
            }
        }
        if(op != -1 && tMoradores > 0) opcao = sairListar(x, y);
        else break;
    }while(opcao == 0);
}
// Selecionar o morador na lista de moradores

void guardarMoradorVetor(){
    Morador morador;
    abrirMoradorArquivo();
    fseek(fpMorador, 0, SEEK_SET);

    while(fread(&morador, sizeof(Morador), 1, fpMorador)){
        if(strcmp(morador.dono, " ") && morador.idade != 0){
            moradores[tMoradores] = morador;
            tMoradores++;
        }
    }
    fecharMoradorArquivo();
}

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
    for(i = 0; i < alt-3; i++){
        gotoxy(x+1, y+4+i);printf("%*s",-larg, moradores[primeiro+i].dono);
    }
    do{
        textcoloreback(BLACK, LIGHT_CYAN);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, moradores[opcao].dono);
        tecla = getTecla();
        textcoloreback(WHITE, BLACK);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, moradores[opcao].dono);
        if(tecla == 27){
            return -1;
        }
        if(tecla == 's' || tecla == 'S')opcao++;
        if(tecla == 'w' || tecla == 'W')opcao--;
        if(tecla == 13)return opcao;
        if(opcao < 0) opcao = 0;
        if(opcao > total-1) opcao = total-1;
        if(opcao > primeiro + alt-4){
            primeiro++;
            for(i = 0; i < alt-3; i++){
               gotoxy(x+1, y+4+i);printf("%*s",-larg, moradores[primeiro+i].dono);
            }
        }
        else if(opcao < primeiro){
                primeiro--;
            for(i = 0; i < alt-3; i++){
                gotoxy(x+1, y+4+i);printf("%*s",-larg, moradores[primeiro+i].dono);
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
                encontrado = 1;
                break;
            }
        }
        if(encontrado && ImprimirMorador(x, y, moradores[i])){
            opcao = maisOpcoes(x, y);
            char op[][51] = {"PESQUISAR MAIS", "EXCLUIR MORADOR", "ALTERAR MORADOR", "SAIR"};
            if(opcao == 0) opcao = maisOpcoesArea(75, 6, op, 4);
            switch(opcao){
                case 1:
                    excluirMorador(i);   
                    break;
                case 2:
                    alterarMorador(30, 10, i);
                    break;
                default: break;
            }
        }
        else opcao = sairListar(x, y);
    }while(opcao == 0);
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
void excluirMorador(int op){
    int i, j;

    if(login(30, 13, 45, 17)){
        Morador aux;


        abrirMoradorArquivo();
        while(fread(&aux, sizeof(Morador), 1, fpMorador)){
            if(!strcmp(aux.dono, moradores[op].dono))break;
        }
        strcpy(moradores[op].dono, " ");
        strcpy(moradores[op].tel, " ");
        strcpy(moradores[op].cpf, " ");
        moradores[op].datapagamento = 0;
        moradores[op].idade = 0;
        fseek(fpMorador, -sizeof(Morador), SEEK_CUR);
        fwrite(&moradores[op], sizeof(Morador), 1, fpMorador);
        fecharMoradorArquivo();
        esvaziarApartamento(moradores[op].apartamento);
        
        for(i = op; i < tMoradores+2; i++){
            for(j = i+1; j < tMoradores; j++){
                aux = moradores[i];
                moradores[i] = moradores[j];
                moradores[j] = aux;
            }
        }
    }
    tMoradores--;
    totalGetMoradores();
    strcpy(moradores[op].cpf, " ");
}
void alterarMorador(int x, int y, int op){
    Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("ALTERAR MORADOR");
    int opcao;
    textcoloreback(WHITE, BLACK);
    Morador morador;
    abrirMoradorArquivo();
    while(fread(&morador, sizeof(Morador), 1, fpMorador)){
        if(!strcmp(morador.dono, moradores[op].dono))break;
    }
    gotoxy(x, y);  printf("Dono:                                     ");
    gotoxy(x, y+2);printf("Idade:                                    ");
    gotoxy(x, y+4);printf("CPF:                                      ");                        
    gotoxy(x, y+6);printf("Data de pagamento:                        ");
    gotoxy(x, y+8);printf("Telefone:                                 ");  
    gotoxy(x, y+10);printf("Apartamento:                             ");  

    tipoCursor(1);
    gotoxy(x, y);  printf("Dono: ");                         scanf(" %[^\n]", morador.dono);
    gotoxy(x, y+2);printf("Idade: ");                        scanf(" %d", &morador.idade);
    gotoxy(x, y+4);printf("CPF: ");                          scanf(" %s", morador.cpf);
    gotoxy(x, y+6);printf("Data de pagamento: ");            scanf(" %d", &morador.datapagamento);
    gotoxy(x, y+8);printf("Telefone: ");                     scanf(" %s", morador.tel);
    gotoxy(x, y+10);printf("Apartamento: ");                 scanf(" %s", morador.apartamento.num);
    converterMaiusculo(morador.apartamento.num);
    alterarDisp(morador.apartamento.num, 1);
    morador.apartamento = puxarAp(morador.apartamento);
    moradores[op] = morador;
    fseek(fpMorador, -sizeof(Morador), SEEK_CUR);
    fwrite(&morador, sizeof(Morador), 1, fpMorador);
    fecharMoradorArquivo();
}

int getTotalMoradores(){
    return tMoradores;
}
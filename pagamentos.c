#include "pagamentos.h"

int tPagamentos = 0;
Pagamento pagamentos[1000];

FILE *fpPagamento;

void areaPagamento(int x, int y){
  
  int xO[] = {x+24, x+24, x+24};
  int yO[] = {y-1, y+2, y+5};
  char opO[][51] = {"CADASTRAR PAGAMENTO", "LISTAR PAGAMENTOS"};
  int opcao = Menu(xO, yO, opO, 2, 0);
  LimparTela(x+23, y-3, 20, 5);
  
  if(opcao != -1)Caixa(28, 6, 87, 17, 0,LIGHT_CYAN, BLACK);// primeira caixa da area principal

    switch(opcao){
      case 0:
          cadastrarPagamento(30, 10);
          break;
      case 1: 
          listarPagamento(30, 10);
      default: break;
  }
}

void ImprimirPagamento(int x, int y, Pagamento pagamento){
  gotoxy(x, y);  printf("Pagador: ");                        printf("%s", pagamento.pagador);
  gotoxy(x, y+2);printf("Valor Pago: R$");                     printf("%.2lf", pagamento.valorPagamento);
  gotoxy(x, y+4);printf("Data do pagamento: ");               printf("%d", pagamento.diaPagamento);                     
}

void abrirPagamentoArquivo(){
  fpPagamento = fopen("Pagamentos.txt", "rb+");
  if(fpPagamento == NULL){
    fpPagamento = fopen("Pagamentos.txt", "wb+");
    if(fpPagamento == NULL){
      printf("Falha em abrir o arquivo.\n");
      exit(1);
    }
  }
}

void fecharPagamentoArquivo(){
  fclose(fpPagamento);
}

void adicionarPagamento(Pagamento pagamento){
  pagamentos[tPagamentos] = pagamento;
  abrirPagamentoArquivo();
  fseek(fpPagamento, 0, SEEK_END);
  fwrite(&pagamento, sizeof(Pagamento), 1, fpPagamento);
  tPagamentos++;
}

void cadastrarPagamento(int x, int y){
  Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
  Pagamento pagamento;
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+10,y-3);printf("CADASTRO DE PAGAMENTO");
  int opcao;
  int i;
  do{
    textcoloreback(WHITE, BLACK);
    tipoCursor(1);
    gotoxy(x, y);  printf("Pagador:                      ");
    gotoxy(x, y+2);printf("Valor do Pagamento:           ");
    gotoxy(x, y+4);printf("Dia do Pagamento:             ");

    gotoxy(x, y);   printf("Pagador: ");                    scanf(" %[^\n]", pagamento.pagador);
    gotoxy(x, y+2); printf("Valor do Pagamento: ");         scanf("%lf", &pagamento.valorPagamento);
    gotoxy(x, y+4); printf("Data do Pagamento: ");           scanf(" %d", &pagamento.diaPagamento);
    adicionarPagamento(pagamento);
    opcao = sairCadastrar(x, y);
  }while(opcao == 0);
}
void guardarPagamentoVetor(){
    abrirPagamentoArquivo();
    Pagamento pagamento;
    fseek(fpPagamento, 0, SEEK_SET);
    while(fread(&pagamento, sizeof(Pagamento), 1, fpPagamento)){
      if(strcmp(pagamento.pagador, " ") || pagamento.valorPagamento){
        pagamentos[tPagamentos] = pagamento;
        tPagamentos++;
      }
    }
    fecharPagamentoArquivo();
}


void listarPagamento(int x, int y){
  int op = -1;
  int opcao = 1;
  do{
    if(tPagamentos) op = selecaoPagamento(x-2, y-4, 45, 17, pagamentos, tPagamentos, 0);
    LimparTela(x-1,y, 43, 11);

    if(op != -1 && tPagamentos > 0) {
      ImprimirPagamento(x, y, pagamentos[op]);  
        opcao = maisOpcoes(x, y);
        if(opcao == 0){
          char op[][51] = {"EXCLUIR PAGAMENTO","ALTERAR PAGAMENTO", "SAIR"};
          opcao = maisOpcoesArea(75, 6, op, 3);
        }
        else break;
        switch(opcao){
          case 0: 
            excluirPagamento(op);
            break;
          case 1:
            alterarPagamento(30, 10, op);
            break;
          default: break; 
        }
    }
    if(op != -1 && tPagamentos > 0) opcao = sairListar(x, y);
  }while(opcao == 0);
}

int selecaoPagamento(int x , int y, int larg, int alt,Pagamento pagamentos[], int total, int opcao){
    Caixa(x, y, larg, alt,0,LIGHT_CYAN, BLACK);
    Caixa(30,10-4 ,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(30+11,10-3);printf("LISTA DE PAGAMENTOS");
    textcoloreback(WHITE, BLACK);
    char tecla;
    int i;
    int primeiro = 0;
    textcoloreback(WHITE, BLACK);
    for(i = 0; i < alt-3; i++){
        gotoxy(x+1, y+4+i);printf("%*s",-larg, pagamentos[primeiro+i].pagador);
    }
    do{
        textcoloreback(BLACK, LIGHT_CYAN);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, pagamentos[opcao].pagador);
        tecla = getTecla();
        textcoloreback(WHITE, BLACK);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, pagamentos[opcao].pagador);
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
               gotoxy(x+1, y+4+i);printf("%*s",-larg, pagamentos[primeiro+i].pagador);
            }
        }
        else if(opcao < primeiro){
                primeiro--;
            for(i = 0; i < alt-3; i++){
                gotoxy(x+1, y+4+i);printf("%*s",-larg, pagamentos[primeiro+i].pagador);
            }
        }
    }while(1);
}

void excluirPagamento(int op){
    int i, j;
    if(login(30, 13, 45, 17)){
        Pagamento aux;
        abrirPagamentoArquivo();
        while(fread(&aux, sizeof(Pagamento), 1, fpPagamento)){
            if(!strcmp(aux.pagador, pagamentos[op].pagador))break;
        }
        strcpy(pagamentos[op].pagador, " ");
        pagamentos[op].diaPagamento = 0;
        pagamentos[op].valorPagamento = 0;

        fseek(fpPagamento, -sizeof(Pagamento), SEEK_CUR);
        fwrite(&pagamentos[op], sizeof(Pagamento), 1, fpPagamento);
        fecharPagamentoArquivo();   
        for(i = op; i < tPagamentos+2; i++){
          for(j = i+1; j < tPagamentos; j++){
            aux = pagamentos[i];
            pagamentos[i] = pagamentos[j];
            pagamentos[j] = aux;
          }
        }
    }
    tPagamentos--;
}

void alterarPagamento(int x, int y, int op){
    Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("ALTERAR PAGAMENTO");
    int opcao;
    textcoloreback(WHITE, BLACK);
    Pagamento pagamento;
    abrirPagamentoArquivo();
    while(fread(&pagamento, sizeof(Pagamento), 1, fpPagamento)){
        if(!strcmp(pagamento.pagador, pagamentos[op].pagador))break;
    }
    textcoloreback(WHITE, BLACK);
    tipoCursor(1);
    gotoxy(x, y);  printf("Pagador:                      ");
    gotoxy(x, y+2);printf("Valor do Pagamento:           ");
    gotoxy(x, y+4);printf("Dia do Pagamento:             ");

    gotoxy(x, y);   printf("Pagador: ");                    scanf(" %[^\n]", pagamento.pagador);
    gotoxy(x, y+2); printf("Valor do Pagamento: ");         scanf("%lf", &pagamento.valorPagamento);
    gotoxy(x, y+4); printf("Dia do Pagamento: ");           scanf(" %d", &pagamento.diaPagamento);
    pagamentos[op] = pagamento;
    fseek(fpPagamento, -sizeof(Pagamento), SEEK_CUR);
    fwrite(&pagamento, sizeof(Morador), 1, fpPagamento);
    fecharPagamentoArquivo();
}

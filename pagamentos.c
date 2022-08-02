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
  gotoxy(x, y+4);printf("Dia do pagamento: ");               printf("%d", pagamento.diaPagamento);                     
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
    gotoxy(x, y+4); printf("Dia do Pagamento: ");           scanf(" %d", &pagamento.diaPagamento);
    adicionarPagamento(pagamento);
    opcao = sairCadastrar(x, y);
  }while(opcao == 0);
}
void guardarPagamentoVetor(){
    abrirPagamentoArquivo();
    fseek(fpPagamento, 0, SEEK_SET);
    while(fread(&pagamentos[tPagamentos], sizeof(Pagamento), 1, fpPagamento)){
      tPagamentos++;
    }
    fecharPagamentoArquivo();
}


void listarPagamento(int x, int y){
  int op = -1;
  int opcao;
  do{
    if(tPagamentos) op = selecaoPagamento(x-2, y-4, 45, 17, pagamentos, tPagamentos, 0);
    LimparTela(x-1,y, 43, 11);

    if(op != -1 && tPagamentos > 0) {
      ImprimirPagamento(x, y, pagamentos[op]);  
    }
    opcao = sairListar(x, y);
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
    for(i = 0; i < total; i++){
        gotoxy(x+1, y+4+i);printf("%*s",-larg, pagamentos[primeiro+i].pagador);
    }
    do{
        textcoloreback(BLACK, LIGHT_CYAN);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, pagamentos[opcao].pagador);
        tecla = getTecla();
        textcoloreback(WHITE, BLACK);
        gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, pagamentos[opcao].pagador);
        if(tecla == 's' || tecla == 'S')opcao++;
        if(tecla == 'w' || tecla == 'W')opcao--;
        if(tecla == 13)return opcao;
        if(opcao < 0) opcao = 0;
        if(opcao > total-1) opcao = total-1;
        if(opcao > primeiro + alt-1){
            primeiro++;
            for(i = 0; i < alt; i++){
               gotoxy(x+1, y+1+i);printf("%*s",-larg, pagamentos[primeiro+i].pagador);
            }
        }
        else if(opcao < primeiro){
                primeiro--;
            for(i = 0; i < alt; i++){
                gotoxy(x+1, y+1+i);printf("%*s",-larg, pagamentos[primeiro+i].pagador);
            }
        }
    }while(1);
}

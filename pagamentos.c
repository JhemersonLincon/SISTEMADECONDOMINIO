#include "pagamentos.h"

int tPagamentos = 0;
Pagamento pagamentos[1000];


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
          listarOcorrencia(30, 10);
      default: break;
  }
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
    pagamentos[tPagamentos] = pagamento;
    tPagamentos++;
    opcao = sairCadastrar(x, y);
  }while(opcao == 0);
}
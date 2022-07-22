#ifndef PAGAMENTOS_H_INCLUDE
#define PAGAMENTOS_H_INCLUDE
#include <stdio.h>
#include "moradores.h"

typedef struct{
  char pagador[51];
  float valorPagamento;
  int diaPagamento;
  Morador dadosPagador;
}Pagamento;

void areaPagamento(int x, int y);
void cadastrarPagamento(int x, int y);
#endif
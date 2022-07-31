#ifndef PAGAMENTOS_H_INCLUDE
#define PAGAMENTOS_H_INCLUDE
#include <stdio.h>
#include "moradores.h"

typedef struct{
  char pagador[51];
  double valorPagamento;
  int diaPagamento;
  Morador dadosPagador;
}Pagamento;

void guardarPagamentoVetor();
void abrirPagamentoArquivo();
void fecharPagamentoArquivo();

void areaPagamento(int x, int y);
void cadastrarPagamento(int x, int y);
void ImprimirPagamento(int x, int y, Pagamento pagamento);
void listarPagamento(int x, int y);
int selecaoPagamento(int x , int y, int larg, int alt,Pagamento pagamentos[], int total, int opcao);
#endif
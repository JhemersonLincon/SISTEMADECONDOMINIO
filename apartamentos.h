#if !defined(APARTAMENTO_H_INCLUDE)
#define APARTAMENTO_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "utils.h"

typedef struct{ 
  char num[31];
  double tamanho;
  int comodos;
  int disp;
  double aluguel;
}Apartamento;
Apartamento puxarAp(Apartamento apartamento);
void programerAp(char num[], double tamanho, int comodos, int disp, double aluguel);
void cadastrarAp(int x, int y);
void ImprimirApartamento(int x, int y, Apartamento apartamentos);
void areaApartamento(int x, int y);
void listarApartamento(int x, int y);
int selecaoApartamento(int x , int y, int larg, int alt, Apartamento apartamentos[], int total, int opcao);
void apartamentoEmMorador(int x, int y, Apartamento apartamento);
void areaApartamentosLivres(int x, int y);
void esvaziarApartamento(Apartamento apartamento);
#endif // APARTAMENTO_H_INCLUDE

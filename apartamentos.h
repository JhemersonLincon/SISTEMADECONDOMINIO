#if !defined(APARTAMENTO_H_INCLUDE)
#define APARTAMENTO_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "utils.h"

typedef struct{ 
  int num;
  double tamanho;
  int comodos;
  int disp;
  double aluguel;
}Apartamento;

void cadastrarAp(int x, int y);
void ImprimirApartamento(int x, int y, Apartamento apartamentos[], int N, int pos);
void areaApartamento(int x, int y);
void listarApartamento(int x, int y);
int selecaoApartamento(int x , int y, int larg, int alt, Apartamento apartamentos[], int total, int opcao);

#endif // APARTAMENTO_H_INCLUDE

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

Apartamento cadastrarAp(int num, double tamanho, int comodos, int dips, double aluguel);
void ImprimirApartamento(Apartamento apartamento[], int N);

#endif // APARTAMENTO_H_INCLUDE

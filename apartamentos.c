#include "apartamentos.h"

int tApartamentos = 4;
Apartamento apartamentos[100];

Apartamento cadastrarAp(int num, double tamanho, int comodos, int dips, double aluguel){
  Apartamento apartamento;
  apartamento.num = num;
  apartamento.tamanho = tamanho;
  apartamento.comodos = comodos;
  apartamento.disp = aluguel;
  return apartamento;
}

void ImprimirApartamento(Apartamento apartamento[], int N){
  int i;
  for(i=0; i<N; i++){
      printf("\n%d", apartamento[i].num);
      printf("\n%lf", apartamento[i].tamanho);
      printf("\n%d", apartamento[i].comodos);
      printf("\n%d", apartamento[i].disp);
      printf("\n%d", apartamento[i].aluguel);
  }
}

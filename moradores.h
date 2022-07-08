#if !defined(MORADORES_H_INCLUDE)
#define MORADORES_H_INCLUDE
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

typedef struct{
    
    char dono[51];
    int idade;
    char cpf[51];
    int datapagamento;
    int tel;
    Apartamento apartamento;

}Morador;

Apartamento CadastrarAp(int num, double tamanho, int comodos, int dips, double aluguel);

Morador CadastrarMorador();

void ImprimirApartamento(Apartamento apartamento[], int N);

void ImprimirMorador(Morador morador[], int n);

void areaMoradores(int x, int y);
#endif 
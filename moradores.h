#ifndef MORADORES_H_INCLUDE
#define MORADORES_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "utils.h"
#include "apartamentos.h"

typedef struct{
    
    char dono[51];
    int idade;
    char cpf[51];
    int datapagamento;
    char tel[51];
    Apartamento apartamento;

}Morador;


Apartamento CadastrarAp(int num, double tamanho, int comodos, int dips, double aluguel);
Morador cadastrarMorador(int x, int y);
void ImprimirApartamento(Apartamento apartamento[], int N);
void ImprimirMorador(int x, int y, Morador morador[], int n, int pos);
void areaMoradores(int x, int y);
int getMoradores();
void listarMoradores(Morador moradores[], int total);
void pesquisaMoradores(int x, int y);

#endif 
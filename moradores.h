#ifndef MORADORES_H_INCLUDE
#define MORADORES_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "utils.h"
#include "apartamentos.h"
#include "pagamentos.h"
typedef struct{
    char dono[51];
    int idade;
    char cpf[51];
    int datapagamento;
    char tel[51];
    Apartamento apartamento;
}Morador;


void abrirMoradorArquivo();
void fecharMoradorArquivo();
void guardarMoradorVetor();

void cadastrarMorador(int x, int y);
int ImprimirMorador(int x, int y, Morador morador);
void areaMoradores(int x, int y);
int getMoradores();
void listarMoradores(int x, int y);
void pesquisaMoradores(int x, int y);

void excluirMorador(int op);
void alterarMorador(int x,int y, int op);
#endif
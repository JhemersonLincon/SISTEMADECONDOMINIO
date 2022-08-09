#ifndef OCORRENCIA_H_INCLUDE
#define OCORRENCIA_H_INCLUDE
#include <stdio.h>
#include <stdio.h>
#include <string.h>
typedef struct{
  char relator[51];
  char dataOcorrencia[51];
  char relatos[1001];
  char relatosLm[1001];
}Ocorrencia;



void areaOcorrencia(int x, int y);

void abrirOcorrenciaArquivo();
void fecharOrcorrenciaArquivo();
void adicionarOcorrencia(Ocorrencia ocorrencia);
void guardarOcorrenciaVetor();

void cadastrarOcorrencia(int x, int y);
void listarOcorrencia(int x, int y);
int selecaoOcorrencia(int x , int y, int larg, int alt, Ocorrencia ocorrencias[], int total, int opcao);

void excluirOcorrencia(int op);
void alterarOcorrencia(int x, int y, int op);
#endif
#ifndef ADM_H_INCLUDE
#define ADM_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "interface.h"
#include "utils.h"
typedef struct{
    char nome[101];
    char login[10];
}Login;

int adicionarAdm(Login adm);

void abrirAdmArquivo();
void fecharAdmArquivo();
void guardarAdmVetor();

void CadastrarAdm(int x, int y);
void ImprimirAdm(int x, int y, Login Login); 

void areaAdm(int x, int y);

int login(int x, int y, int largura, int altura);

void listarAdms(int x, int y);
int selecaoAdms(int x , int y, int larg, int alt,Login adms[], int total, int opcao);
void excluirAdm(int op);
#endif // 

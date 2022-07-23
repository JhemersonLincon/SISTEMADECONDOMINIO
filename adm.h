#ifndef ADM_H_INCLUDE
#define ADM_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "utils.h"

typedef struct{
    
    char nome[101];
    char login[10];

}Login;

void CadastrarAdm(int x, int y);

void ImprimirAdm(int x, int y, Login Login); 

void areaAdm(int x, int y);






#endif // 

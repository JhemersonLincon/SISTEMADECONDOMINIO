#include "interface.h"
#include "ocorrencias.h"

Ocorrencia ocorrencias[100];
int tOcorrencia = 0;
FILE *fpOcorrencia;

void areaOcorrencia(int x, int y){
  int xO[] = {x+24, x+24, x+24};
  int yO[] = {y-1, y+2, y+5};
  char opO[][51] = {"CADASTRAR OCORRENCIA", "LISTAR OCORRENCIA"};
  int opcao = Menu(xO, yO, opO, 2, 0);
  LimparTela(x+23, y-3, 20, 5);
  if(opcao != -1)Caixa(28, 6, 87, 17, 0,LIGHT_CYAN, BLACK);// primeira caixa da area principal
    switch(opcao){
      case 0:
          cadastrarOcorrencia(30, 10);
          break;
      case 1: 
          listarOcorrencia(30, 10);
      default: break;
  }
}


void abrirOcorrenciaArquivo(){
  fpOcorrencia = fopen("Ocorrencias.txt", "rb+");
  if(fpOcorrencia == NULL){
    fpOcorrencia = fopen("Ocorrencias.txt", "wb+");
    if(fpOcorrencia == NULL){
      printf("Falha em abrir o arquivo.\n");
    }
  }
}
void fecharOcorrenciaArquivo(){
  fclose(fpOcorrencia);
}
void adicionarOcorrencia(Ocorrencia ocorrencia){
  ocorrencias[tOcorrencia] = ocorrencia;
  abrirPagamentoArquivo();
  fseek(fpOcorrencia, 0, SEEK_END);
  fwrite(&ocorrencia, sizeof(Ocorrencia), 1, fpOcorrencia);
  fecharOcorrenciaArquivo();
  tOcorrencia++;
}
void guardarOcorrenciaVetor(){
    abrirOcorrenciaArquivo();
    fseek(fpOcorrencia, 0, SEEK_SET);
    while(fread(&ocorrencias[tOcorrencia], sizeof(Ocorrencia), 1, fpOcorrencia)){
      tOcorrencia++;
    }
    fecharOcorrenciaArquivo();
}

void cadastrarOcorrencia(int x, int y){
  Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
  Ocorrencia ocorrencia;
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+10,y-3);printf("CADASTRO DE OCORRENCIA");
  int opcao;
  int i;
  do{
    textcoloreback(WHITE, BLACK);
    tipoCursor(1);
    gotoxy(x, y);  printf("Relator:                        ");
    gotoxy(x, y+2);printf("Ocorrencia:                     ");

    gotoxy(x, y);   printf("Relator:");                 scanf(" %[^\n]", ocorrencia.relator);
    gotoxy(x, y+2); printf("Ocorrencia:");              scanf(" %[^\n]", ocorrencia.relatos);
    for(i = 0; i < 34; i++){
      if(i <= 30) ocorrencia.relatosLm[i] = ocorrencia.relatos[i];
      else if(i <= 33) ocorrencia.relatosLm[i] = '.';
    }
    ocorrencia.relatosLm[i] = '\0';
    opcao = sairCadastrar(x, y);
  }while(opcao == 0);
}

void listarOcorrencia(int x, int y){
  int op = -1;
  int opcao;
  do{
    if(tOcorrencia) op = selecaoOcorrencia(x-2, y-4, 45, 17, ocorrencias, tOcorrencia, 0);
    else{gotoxy(37, 7);printf("Nao a Ocorrencias cadastrados");}
    LimparTela(x-1, y, 10, 5);
    //if(op != -1) ImprimirApartamento(x, y, ocorrencias, 0, op );
    opcao = sairListar(x, y);
  }while(opcao == 0);
}

int selecaoOcorrencia(int x , int y, int larg, int alt, Ocorrencia ocorrencias[], int total, int opcao){
  Caixa(x, y, larg, alt,0,LIGHT_CYAN, BLACK);
  Caixa(30,10-4 ,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(30+11,10-3);printf("LISTA DE OCORRENCIAS");
  textcoloreback(WHITE, BLACK);
  char tecla;
  int i;
  int primeiro = 0;
  textcoloreback(WHITE, BLACK);
  
  for(i = 0; i < total; i++){
    gotoxy(x+1, y+4+i);printf("%*s",-larg, ocorrencias[primeiro+i].relatosLm);
  }

  do{
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, ocorrencias[opcao].relatosLm);

    tecla = getTecla();
    textcoloreback(WHITE, BLACK);
    gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, ocorrencias[opcao].relatosLm);
    if(tecla == 's' || tecla == 'S')opcao++;
    if(tecla == 'w' || tecla == 'W')opcao--;
    if(tecla == 13) return opcao;
    if(opcao < 0) opcao = 0;
    if(opcao > total-1) opcao = total-1;
    if(opcao > primeiro + alt-1){
      primeiro++;
      for(i = 0; i < alt; i++){
        gotoxy(x+1, y+1+i);printf("%*s",-larg, ocorrencias[primeiro+i].relatosLm);
      }
    }
    else if(opcao < primeiro){
      primeiro--;
      for(i = 0; i < alt; i++){
        gotoxy(x+1, y+1+i);printf("%*s",-larg, ocorrencias[primeiro+i].relatosLm);
      }
   }
  }while(1);
}

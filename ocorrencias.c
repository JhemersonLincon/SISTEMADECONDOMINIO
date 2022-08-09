#include "interface.h"
#include "ocorrencias.h"

Ocorrencia ocorrencias[100];
int tOcorrencia = 0;
FILE *fpOcorrencia;

void areaOcorrencia(int x, int y)
{
  int xO[] = {x + 24, x + 24, x + 24};
  int yO[] = {y - 1, y + 2, y + 5};
  char opO[][51] = {"CADASTRAR OCORRENCIA", "LISTAR OCORRENCIA"};
  int opcao = Menu(xO, yO, opO, 2, 0);
  LimparTela(x + 23, y - 3, 20, 5);
  if (opcao != -1)
    Caixa(28, 6, 87, 17, 0, LIGHT_CYAN, BLACK); // primeira caixa da area principal
  switch (opcao)
  {
  case 0:
    cadastrarOcorrencia(30, 10);
    break;
  case 1:
    listarOcorrencia(30, 10);
  default:
    break;
  }
}

void abrirOcorrenciaArquivo()
{
  fpOcorrencia = fopen("Ocorrencias.txt", "rb+");
  if (fpOcorrencia == NULL)
  {
    fpOcorrencia = fopen("Ocorrencias.txt", "wb+");
    if (fpOcorrencia == NULL)
    {
      printf("Falha em abrir o arquivo.\n");
    }
  }
}
void fecharOcorrenciaArquivo()
{
  fclose(fpOcorrencia);
}
void adicionarOcorrencia(Ocorrencia ocorrencia)
{
  ocorrencias[tOcorrencia] = ocorrencia;
  abrirOcorrenciaArquivo();
  fseek(fpOcorrencia, 0, SEEK_END);
  fwrite(&ocorrencia, sizeof(Ocorrencia), 1, fpOcorrencia);
  fecharOcorrenciaArquivo();
  tOcorrencia++;
}

void guardarOcorrenciaVetor()
{
  Ocorrencia ocorrencia;
  abrirOcorrenciaArquivo();
  fseek(fpOcorrencia, 0, SEEK_SET);
  while (fread(&ocorrencia, sizeof(Ocorrencia), 1, fpOcorrencia)){
    if(strcmp(ocorrencia.relator, " ") || strcmp(ocorrencia.relatos, " ")){
      ocorrencias[tOcorrencia] = ocorrencia;
      tOcorrencia++;
    }
  }
  fecharOcorrenciaArquivo();
}

void cadastrarOcorrencia(int x, int y)
{
  Caixa(x, y - 4, 40, 1, 0, LIGHT_CYAN, LIGHT_CYAN);
  Ocorrencia ocorrencia;
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x + 10, y - 3);
  printf("CADASTRO DE OCORRENCIA");
  int opcao, cont = 0;
  int i;
  do
  {
    textcoloreback(WHITE, BLACK);
    tipoCursor(1);
    gotoxy(x, y);     printf("Relator:                          ");
    gotoxy(x, y+2);   printf("Data de Ocorrencia:               ");
    gotoxy(x, y + 4); printf("Ocorrencia:                       ");

    gotoxy(x, y);      printf("Relator:");              scanf(" %[^\n]", ocorrencia.relator);
    gotoxy(x, y+2);   printf("Data de Ocorrencia: ");   scanf("%s", ocorrencia.dataOcorrencia);
    gotoxy(x, y + 4); printf("Ocorrencia:");            scanf(" %[^\n]", ocorrencia.relatos);
    for (i = 0; i < 34; i++)
    {
      if (i <= 30)
        ocorrencia.relatosLm[i] = ocorrencia.relatos[i];
      else if (i <= 33)
        ocorrencia.relatosLm[i] = '.';
    }
    ocorrencia.relatosLm[i] = '\0';
    adicionarOcorrencia(ocorrencia);
    opcao = sairCadastrar(x, y);
  } while (opcao == 0);
}
void ImprimirOcorrencia(int x, int y, Ocorrencia ocorrencia){
  int i, posX = 0, posY = 0;
  gotoxy(x, y);   printf("Relator: %s", ocorrencia.relator);
  gotoxy(x, y+2); printf("Data Ocorrencia: %s", ocorrencia.dataOcorrencia);
  gotoxy(x, y + 4); printf("Ocorrencia: ");
  printf("\n");
  for(i = 0; i < strlen(ocorrencia.relatos); i++){
    if(i == 42 || i == 82){
      posY++;
      posX = 0;
    }
    gotoxy(x+posX, y+posY + 5);printf("%c", ocorrencia.relatos[i]);
    posX++;
  }
}

void listarOcorrencia(int x, int y){
  int op = -1;
  int opcao = 0;
  do{
    if (tOcorrencia)
      op = selecaoOcorrencia(x - 2, y - 4, 45, 17, ocorrencias, tOcorrencia, 0);
    else
    {
      gotoxy(37, 7);
      printf("Nao a Ocorrencias cadastrados");
    }
    LimparTela(x - 1, y, 40, 9);
    if (op != -1 && tOcorrencia > 0)
    {
      ImprimirOcorrencia(x, y, ocorrencias[op]);
      opcao = maisOpcoes(x, y);
      if(opcao == 0){
        char op[][51] = {"EXCLUIR PAGAMENTO","ALTERAR PAGAMENTO", "SAIR"};
        opcao = maisOpcoesArea(75, 6, op, 3);
      }
      else break;
      switch(opcao){
        case 0: 
          excluirOcorrencia(op);
          break;
        case 1:
          alterarOcorrencia(30, 10, op);
          break;
        default: break; 
      }
      opcao = sairListar(x, y);
    }
    else
      break;
    LimparTela(x - 1, y, 10, 5);
  } while (opcao == 0);
}

int selecaoOcorrencia(int x, int y, int larg, int alt, Ocorrencia ocorrencias[], int total, int opcao)
{
  Caixa(x, y, larg, alt, 0, LIGHT_CYAN, BLACK);
  Caixa(30, 10 - 4, 40, 1, 0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(30 + 11, 10 - 3);
  printf("LISTA DE OCORRENCIAS");
  textcoloreback(WHITE, BLACK);
  char tecla;
  int i;
  int primeiro = 0;
  textcoloreback(WHITE, BLACK);

  for (i = 0; i < total; i++)
  {
    gotoxy(x + 1, y + 4 + i);
    printf("%*s", -larg, ocorrencias[primeiro + i].relatosLm);
  }

  do
  {
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x + 1, y + 4 + opcao - primeiro);
    printf("%*s", -larg, ocorrencias[opcao].relatosLm);

    tecla = getTecla();
    textcoloreback(WHITE, BLACK);
    gotoxy(x + 1, y + 4 + opcao - primeiro);
    printf("%*s", -larg, ocorrencias[opcao].relatosLm);
    if(tecla == 27)return -1;
    if (tecla == 's' || tecla == 'S')
      opcao++;
    if (tecla == 'w' || tecla == 'W')
      opcao--;
    if (tecla == 13)
      return opcao;
    if (opcao < 0)
      opcao = 0;
    if (opcao > total - 1)
      opcao = total - 1;
    if (opcao > primeiro + alt - 4)
    {
      primeiro++;
      for (i = 0; i < alt - 3; i++)
      {
        gotoxy(x + 1, y + 3 + i);
        printf("%*s", -larg, ocorrencias[primeiro + i].relatosLm);
      }
    }
    else if (opcao < primeiro)
    {
      primeiro--;
      for (i = 0; i < alt - 3; i++)
      {
        gotoxy(x + 1, y + 3 + i);
        printf("%*s", -larg, ocorrencias[primeiro + i].relatosLm);
      }
    }
  } while (1);
}

void excluirOcorrencia(int op){
    int i, j;
    if(login(30, 13, 45, 17)){
        Ocorrencia aux;
        abrirOcorrenciaArquivo();
        while(fread(&aux, sizeof(Ocorrencia), 1, fpOcorrencia)){
            if(!strcmp(aux.relator, ocorrencias[op].relator))break;
        }
        strcpy(ocorrencias[op].relator, " ");
        strcpy(ocorrencias[op].dataOcorrencia, " ");
        strcpy(ocorrencias[op].relatos, " ");
        strcpy(ocorrencias[op].relatosLm, " ");

        fseek(fpOcorrencia, -sizeof(Ocorrencia), SEEK_CUR);
        fwrite(&ocorrencias[op], sizeof(Ocorrencia), 1, fpOcorrencia);
        fecharOcorrenciaArquivo();   
        for(i = op; i < tOcorrencia+2; i++){
          for(j = i+1; j < tOcorrencia; j++){
            aux = ocorrencias[i];
            ocorrencias[i] = ocorrencias[j];
            ocorrencias[j] = aux;
          }
        }
    }
    tOcorrencia--;
}

void alterarOcorrencia(int x, int y, int op){
    Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+10,y-3);printf("ALTERAR OCORRENCIA");
    int opcao, i;
    textcoloreback(WHITE, BLACK);
    LimparTela(x, y, 30, 8);
    Ocorrencia ocorrencia;
    abrirOcorrenciaArquivo();
    while(fread(&ocorrencia, sizeof(Ocorrencia), 1, fpOcorrencia)){
      if(!strcmp(ocorrencia.relator, ocorrencias[op].relator))break;
    }
    textcoloreback(WHITE, BLACK);
    tipoCursor(1);
    gotoxy(x, y);     printf("Relator:                        ");
    gotoxy(x, y+2);   printf("Data de Ocorrencia:             ");
    gotoxy(x, y + 4); printf("Ocorrencia:                     ");

    gotoxy(x, y);      printf("Relator: ");              scanf(" %[^\n]", ocorrencia.relator);
    gotoxy(x, y+2);   printf("Data de Ocorrencia: ");   scanf("%s", ocorrencia.dataOcorrencia);
    gotoxy(x, y + 4); printf("Ocorrencia: ");            scanf(" %[^\n]", ocorrencia.relatos);
    strcpy(ocorrencia.relatosLm, " ");
    for (i = 0; i < 34; i++){
      if (i <= 30)
        ocorrencia.relatosLm[i] = ocorrencia.relatos[i];
      else if (i <= 33)
        ocorrencia.relatosLm[i] = '.';
    }
    ocorrencia.relatosLm[i] = '\0';
    ocorrencias[op] = ocorrencia;
    fseek(fpOcorrencia, -sizeof(Ocorrencia), SEEK_CUR);
    fwrite(&ocorrencia, sizeof(Ocorrencia), 1, fpOcorrencia);
    fecharOcorrenciaArquivo();
}

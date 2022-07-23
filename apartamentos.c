#include "apartamentos.h"
#include "moradores.h"
int tApartamentos = 0;
Apartamento apartamentos[100];

Apartamento puxarAp(Apartamento apartamento){
  int i;
  for(i = 0; i < tApartamentos; i++){
    if(strcmp(apartamento.num, apartamentos[i].num) == 0){
      apartamentos[i].disp = 1;
      return apartamentos[i];
    }
  }
  return apartamento;
}

void programerAp(char num[], double tamanho, int comodos, int disp, double aluguel){
  strcpy(apartamentos[tApartamentos].num, num);
  apartamentos[tApartamentos].tamanho = tamanho;
  apartamentos[tApartamentos].comodos = comodos;
  apartamentos[tApartamentos].disp = disp;
  apartamentos[tApartamentos].aluguel = aluguel;
  tApartamentos++;
}

void cadastrarAp(int x, int y){

  Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+10,y-3);printf("CADASTRO DE APARTAMENTO");
  int opcao;
  do{
    textcoloreback(WHITE, BLACK);
    tipoCursor(1);
    Apartamento apartamento;
    gotoxy(x, y);  printf("Numero:                         ");
    gotoxy(x, y+2);printf("Tamanho:                        ");
    gotoxy(x, y+4);printf("Quant de comodos:               ");                        
    gotoxy(x, y+6);printf("Disponibilidade(0/1):             ");
    gotoxy(x, y+8);printf("Preco do Aluguel:               ");  

    gotoxy(x, y);   printf("Numero: ");                  scanf("%s", &apartamento.num);
    gotoxy(x, y+2); printf("Tamanho: ");                 scanf("%lf", &apartamento.tamanho);
    gotoxy(x, y+4); printf("Quant de comodos: ");        scanf("%d", &apartamento.comodos);
    gotoxy(x, y+6); printf("Disponibilidade(0/1): ");         scanf("%d", &apartamento.disp);
    gotoxy(x, y+8); printf("Preco do Aluguel: ");        scanf("%lf", &apartamento.aluguel);
    apartamentos[tApartamentos] = apartamento;
    tApartamentos++;
    totalGetMoradores();
    opcao = sairCadastrar(x, y);
    LimparTela(x-1,y-1, 40, 13);
  }while(opcao == 0);
}

void ImprimirApartamento(int x, int y, Apartamento apartamentos){
  gotoxy(x, y);  printf("Numero: ");                        printf("%s", apartamentos.num);
  gotoxy(x, y+2);printf("Tamanho: ");                       printf("%.2lf", apartamentos.tamanho);
  gotoxy(x, y+4);printf("Quant de comodos: ");              printf("%d", apartamentos.comodos);                     
  gotoxy(x, y+6);printf("Disponibilidade: ");               !apartamentos.disp?printf("Disponivel"):printf("Indisponivel");
  gotoxy(x, y+8);printf("Preco do Aluguel: ");              printf("R$ %.2lf", apartamentos.aluguel);
}

void areaApartamento(int x, int y){
  int xO[] = {x+24, x+24, x+24};
  int yO[] = {y-1, y+2, y+5};
  char opO[][51] = {"CADASTRAR APARTAMENTO", "LISTAR APARTAMENTO", };
  int opcao = Menu(xO, yO, opO, 2, 0);
  LimparTela(x+23, y-3, 20, 10); 
  if(opcao != -1)Caixa(28, 6, 45, 17, 0,LIGHT_CYAN, BLACK);// primeira caixa da area principal
  switch(opcao){
    case 0:
      cadastrarAp(30,10);
      break;
    case 1:
      listarApartamento(30, 10);
      break;
    default: break;
    }
}

void listarApartamento(int x, int y){
  int op = -1;
  int opcao;
  do{
    if(tApartamentos) op = selecaoApartamento(x-2, y-4, 45, 17, apartamentos, tApartamentos, 0);
    else{gotoxy(37, 7);printf("Nao a apartamento cadastrados");}
    LimparTela(x-1, y, 40, 5);
    if(op != -1) {
      ImprimirApartamento(x, y, apartamentos[op]);
    }
    opcao = sairListar(x, y);
  }while(opcao == 0);
}

int selecaoApartamento(int x , int y, int larg, int alt, Apartamento apartamentos[], int total, int opcao){
  Caixa(x, y, larg, alt,0,LIGHT_CYAN, BLACK);
  Caixa(30,10-4 ,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(30+11,10-3);printf("LISTA DE APARTAMENTOS");
  textcoloreback(WHITE, BLACK);
  char tecla;
  int i;
  int primeiro = 0;
  for(i = 0; i < total; i++){
    gotoxy(x+1, y+4+i);printf("%s", apartamentos[primeiro+i].num);
  }
  do{
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, apartamentos[opcao].num);
    tecla = getTecla();
    textcoloreback(WHITE, BLACK);
    gotoxy(x+1, y+4+opcao - primeiro);printf("%*s",-larg, apartamentos[opcao].num);
    if(tecla == 's' || tecla == 'S')opcao++;
    if(tecla == 'w' || tecla == 'W')opcao--;
    if(tecla == 13) return opcao;
    if(opcao < 0) opcao = 0;
    if(opcao > total-1) opcao = total-1;
    if(opcao > primeiro + alt-1){
      primeiro++;
      for(i = 0; i < alt; i++){
          gotoxy(x+1, y+1+i);printf("%*s",-larg, apartamentos[primeiro+i].num);
      }
    }
    else if(opcao < primeiro){
      primeiro--;
      for(i = 0; i < alt; i++){
        gotoxy(x+1, y+1+i);printf("%*s",-larg, apartamentos[primeiro+i].num);
      } 
    }
  }while(1);
}

void apartamentoEmMorador(int x, int y, Apartamento apartamento){
  LimparTela(x, y, 40, 17);
  Caixa(x, y, 40, 17, 0,LIGHT_CYAN, BLACK);
  Caixa(x+3, y+1, 35, 1, 0,LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+9, y+2);printf("APARTAMENTO");
  textcoloreback(LIGHT_CYAN, BLACK);
  ImprimirApartamento(x+3, y+5, apartamento);
}

void areaApartamentosLivres(int x, int y){
  LimparTela(x, y, 40, 17);
  Caixa(x, y, 40, 17, 0,LIGHT_CYAN, BLACK);
  Caixa(x+3, y+1, 35, 1, 0,LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+9, y+2);printf("APARTAMENTOS DISPONIVEIS");
  textcoloreback(LIGHT_CYAN, BLACK);
  int i;
  for(i = 0; i < tApartamentos; i++){
    if(!apartamentos[i].disp){
      gotoxy(x+3, y+i+5);printf("o- %s %*s", apartamentos[i].num, +13,"Disponivel");
    }
  }
  textcoloreback(WHITE, BLACK);
}
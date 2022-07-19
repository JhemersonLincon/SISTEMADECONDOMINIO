#include "apartamentos.h"

int tApartamentos = 0;
Apartamento apartamentos[100];

void cadastrarAp(int x, int y){
  Caixa(x,y-4,40,1,0, LIGHT_CYAN, LIGHT_CYAN);
  textcoloreback(BLACK, LIGHT_CYAN);
  gotoxy(x+10,y-3);printf("CADASTRO DE MORADOR");
  int opcao;
  do{
    textcoloreback(WHITE, BLACK);
    tipoCursor(1);
    Apartamento apartamento;
    gotoxy(x, y);  printf("Numero:                         ");
    gotoxy(x, y+2);printf("Tamanho:                        ");
    gotoxy(x, y+4);printf("Quant de comodos:               ");                        
    gotoxy(x, y+6);printf("Disponibilidade:                ");
    gotoxy(x, y+8);printf("Preco do Aluguel:               ");  

    gotoxy(x, y);   printf("Numero:");                  scanf("%d", &apartamento.num);
    gotoxy(x, y+2); printf("Tamanho:");                 scanf("%lf", &apartamento.tamanho);
    gotoxy(x, y+4); printf("Quant de comodos:");        scanf("%d", &apartamento.comodos);
    gotoxy(x, y+6); printf("Disponibilidade:");         scanf("%d", &apartamento.disp);
    gotoxy(x, y+8); printf("Preco do Aluguel:");        scanf("%lf", &apartamento.aluguel);
    apartamentos[tApartamentos] = apartamento;
    tApartamentos++;
    totalGetMoradores();
    opcao = sairCadastrar(x, y);
    LimparTela(x-1,y-1, 40, 13);
  }while(opcao == 0);

}

void ImprimirApartamento(int x, int y, Apartamento apartamentos[], int N, int pos){
  int i;
  if(N == 0){
    gotoxy(x, y);  printf("Numero: ");                        printf("%d", apartamentos[pos].num);
    gotoxy(x, y+2);printf("Tamanho: ");                       printf("%lf", apartamentos[pos].tamanho);
    gotoxy(x, y+4);printf("Quant de comodos: ");              printf("%d", apartamentos[pos].comodos);                     
    gotoxy(x, y+6);printf("Disponibilidade: ");               printf("%d", apartamentos[pos].disp);
    gotoxy(x, y+8);printf("Preco do Aluguel: ");              printf("%lf", apartamentos[pos].aluguel);
  }

  else{
    for(i=0; i<N; i++){
      printf("%c", apartamentos[i].num);
      printf("%d", apartamentos[i].tamanho);
      printf("%c", apartamentos[i].comodos);
      printf("%d", apartamentos[i].disp);
      printf("%c", apartamentos[i].aluguel);
      }
  }
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
  char tecla;
  do{
    if(tApartamentos) op = selecaoApartamento(x-2, y-4, 45, 17, apartamentos, tApartamentos, 0);
    else{gotoxy(37, 7);printf("Nao a apartamento cadastrados");}
    LimparTela(x-1, y, 40, 5);
    if(op != -1) ImprimirApartamento(x, y, apartamentos, 0, op );
    gotoxy(30, 22);printf("Digite ESC para sair...");
    tecla = getch();
  }while(tecla != 27);
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
  textcoloreback(WHITE, BLACK);
  
  for(i = 0; i < total; i++){
    gotoxy(x+1, y+4+i);printf("%*d",-larg, apartamentos[primeiro+i].num);
  }

  do{
    textcoloreback(BLACK, LIGHT_CYAN);
    gotoxy(x+1, y+4+opcao - primeiro);printf("%*d",-larg, apartamentos[opcao].num);

    tecla = getTecla();
    textcoloreback(WHITE, BLACK);
    gotoxy(x+1, y+4+opcao - primeiro);printf("%*d",-larg, apartamentos[opcao].num);
    if(tecla == 's')opcao++;
    if(tecla == 'w')opcao--;
    if(tecla == 13) return opcao;
    if(opcao < 0) opcao = 0;
    if(opcao > total-1) opcao = total-1;
    if(opcao > primeiro + alt-1){
        primeiro++;
        for(i = 0; i < alt; i++){
            gotoxy(x+1, y+1+i);printf("%*d",-larg, apartamentos[primeiro+i].num);
        }
    }
    else if(opcao < primeiro){
            primeiro--;
            for(i = 0; i < alt; i++){
    gotoxy(x+1, y+1+i);printf("%*d",-larg, apartamentos[primeiro+i].num);
  }
  }
  }while(1);
}



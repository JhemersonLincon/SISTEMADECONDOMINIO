#ifndef UTIL_H_INCLUDE
#define UTIL_H_INCLUDE
typedef struct {
  char usuario[51];
  char senha[51];
}usuario;

void Data(int x, int y);
int getTecla();
int selecao(int x, int y, int larg, int alt, char opcoes[][101], int n, int opcao);

void converterMaiusculo(char vetor[]);

int sairCadastrar(int x, int y);
int sairListar(int x, int y);

int maisOpcoes(int x, int y);
int maisOpcoesArea(int x, int y,char op[][51], int t);
#endif // UTIL_H_INCLUDE

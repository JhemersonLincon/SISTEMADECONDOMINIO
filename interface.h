#ifndef INTEFACE_H_INCLUDE
#define INTEFACE_H_INCLUDE
enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };
void gotoxy(int x, int y);
void Rolavel(int vetor[], int n,int quant); 
void Caixa(int x, int y, int largura, int altura, int tipo, int letra, int fundo);
int Menu(int x[], int y[], char opcoes[][51], int n);
void textcoloreback (int letras, int fundo);
void LimparTela(int x, int y, int largura, int altura);



void areaInterface();
void areaMenu();
#endif // INTEFACE_H_INCLUDE

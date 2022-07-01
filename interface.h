#ifndef INTEFACE_H_INCLUDE
#define INTEFACE_H_INCLUDE
enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };
void gotoxy(int x, int y);


void Caixa(int x, int y, int largura, int altura, int tipo);
int Menu(int x[], int y[], char opcoes[][51], int n);
void textcoloreback (int letras, int fundo);
#endif // INTEFACE_H_INCLUDE

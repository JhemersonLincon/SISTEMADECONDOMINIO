#ifndef INTEFACE_H_INCLUDE
#define INTEFACE_H_INCLUDE
enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };
#define TEC_ENTER 13
#define TEC_TAB 9
#define TEC_BACKSPACE 8
#define TEC_ESC 27
#define TEC_DIR 1077
#define TEC_ESQ 1075
#define TEC_BAIXO 1080
#define TEC_CIMA 1072
#define TEC_DEL 1083
#define TEC_END 1079
#define TEC_INSERT 1082
#define TEC_HOME 1071
#define TEC_PAGE_UP 1073
#define TEC_PAGE_DOWN 1081
void gotoxy(int x, int y);
void Rolavel(int vetor[], int n,int quant); 
void Caixa(int x, int y, int largura, int altura, int tipo, int letra, int fundo);
int Menu(int x[], int y[], char opcoes[][51], int n, int t);
void textcoloreback (int letras, int fundo);
void LimparTela(int x, int y, int largura, int altura);



void areaInterface();
void areaMenu();
#endif // INTEFACE_H_INCLUDE

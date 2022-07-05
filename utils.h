#ifndef UTIL_H_INCLUDE
#define UTIL_H_INCLUDE
typedef struct {
  char usuario[51];
  char senha[51];
}usuario;

void Data(int x, int y);
int getTecla();
int login(int x, int y);
#endif // UTIL_H_INCLUDE

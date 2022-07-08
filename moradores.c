#include "moradores.h"

Apartamento CadastrarAp(int num, double tamanho, int comodos, int dips, double aluguel){
    Apartamento apartamento;
    apartamento.num = num;
    apartamento.tamanho = tamanho;
    apartamento.comodos = comodos;
    apartamento.disp = aluguel;
    return apartamento;
}

Morador CadastrarMorador(){
    Morador morador;
    printf("\nDono: ");
    scanf(" %[^\n]", morador.dono);
    printf("\nIdade: ");
    scanf("%d", &morador.idade);
    printf("\nCPF");
    scanf("%s", morador.cpf);
    printf("\nData de pagamento do aluguel: ");
    scanf("%lf", &morador.datapagamento);
    printf("\nTelefone: ");
    scanf("%d", &morador.tel);
    return morador;
}

void ImprimirApartamento(Apartamento apartamento[], int N){
    int i;
    for(i=0; i<N; i++){
        printf("\n%d", apartamento[i].num);
        printf("\n%lf", apartamento[i].tamanho);
        printf("\n%d", apartamento[i].comodos);
        printf("\n%d", apartamento[i].disp);
        printf("\n%d", apartamento[i].aluguel);
    }
}

void ImprimirMorador(Morador morador[], int N){
    int i;
    for(i=0; i<N; i++){
        printf("%c", morador[i].dono);
        printf("%d", morador[i].idade);
        printf("%c", morador[i].cpf);
        printf("%d", morador[i].datapagamento);
        printf("%d", morador[i].tel);
    }
}

void areaMoradores(int x, int y){
    int xO[] = {x+24, x+24, x+24};
    int yO[] = {y-1, y+2, y+5};
    char opO[][51] = {"CADASTRAR MORADORES", "LISTAR MORADORES", "PESQUISAR MORADOR"};
    int opcao = Menu(xO, yO, opO, 3);
    LimparTela(x+23, y-3, 20, 10);
    if(opcao != -1)Caixa(28, 7, 45, 17, 0,LIGHT_CYAN, BLACK);// primeira caixa da area principal

}
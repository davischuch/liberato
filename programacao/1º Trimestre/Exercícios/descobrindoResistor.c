#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char primeiraFaixa[10];
    char segundaFaixa[10];
    char multiplicador[10];
    int valorNumerico;
    int multiplicadorNumerico;
} resistor;

/*
bah nem eras mto trampo
void translate(int* r, int* values, int* t) {
    for (int i = 0; i < 10; i++) {
        int stat = 0;
        for (int j = 0; j < 10; j++) {
            if (*(r + j) != *(values + i*10 + j)) {
                stat = 1;
            }
        }
        if (stat == 0) {
            *t = i;
            break;
        }
    } 
}
*/

int main() {
    int pF, sF, m;
    char values[12][10] = {
        {"preto"},{"marrom"},{"vermelho"},{"laranja"},{"amarelo"},{"verde"},{"azul"},{"roxo"},{"cinza"},{"branco"},{"prata"},{"dourado"}
    };
    resistor r;

    printf("Digite a primeira faixa do código de cores: ");
    scanf("%s", r.primeiraFaixa);
    printf("Digite a segunda faixa do código de cores: ");
    scanf("%s", r.segundaFaixa);
    printf("Digite a terceira faixa (multiplicador) do código de cores: ");
    scanf("%s", r.multiplicador);

    for (int i = 0; i < 10; i++) {
        int stat = 0;
        for (int j = 0; j < 10; j++) {
            if (r.primeiraFaixa[j] != values[i][j]) {
                stat = 1;
            }
        }
        if (stat == 0) {
            pF = i;
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        int stat = 0;
        for (int j = 0; j < 10; j++) {
            if (r.segundaFaixa[j] != values[i][j]) {
                stat = 1;
            }
        }
        if (stat == 0) {
            sF = i;
            break;
        }
    } 

    for (int i = 0; i < 10; i++) {
        int stat = 0;
        for (int j = 0; j < 10; j++) {
            if (r.multiplicador[j] != values[i][j]) {
                stat = 1;
            }
        }
        if (stat == 0) {
            m = i;
            break;
        }
    }

    r.valorNumerico = (pF * 10) + sF;
    r.multiplicadorNumerico = pow(10, m);

    printf("O valor do resistor é %i%i", r.valorNumerico, r.multiplicadorNumerico);
}
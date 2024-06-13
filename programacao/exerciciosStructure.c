#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned int matricula;
    char nome[50];
    float notas[3];
    float resultadoAnual;
    char conceito;
} chamadaT;

int main() {
    chamadaT chamada;

    printf("Digite o numero de matricula do aluno: ");
    scanf("%i", &chamada.matricula);
    fflush(stdin);

    printf("Digite o nome do aluno: ");
    scanf("%s", &chamada.nome);
    fflush(stdin);

    for (int i = 0; i < 3; i++) {
        printf("Digite a %iª nota do aluno: ", i + 1);
        scanf("%f", &chamada.notas[i]);
        printf("\n");
    }

    chamada.resultadoAnual = (((chamada.notas[0])*25)+(chamada.notas[0]*35)+(chamada.notas[0]*40))/(25+35+40);
    if (chamada.resultadoAnual >= 9) {
        chamada.conceito = 'A';
    } else if (chamada.resultadoAnual >= 7.5) {
        chamada.conceito = 'B';
    } else if (chamada.resultadoAnual >= 6) {
        chamada.conceito = 'C';
    } else {
        chamada.conceito = 'R';
    }

    printf("O aluno obteve o seguinte resultado: %c", chamada.conceito);
}
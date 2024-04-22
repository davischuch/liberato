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
    
}
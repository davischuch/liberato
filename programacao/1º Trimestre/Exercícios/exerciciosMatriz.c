#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 10

void printMatrix(int *mat) {
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            printf("%i ", *(mat + i*max + j));
        }
        printf("\n");
    }
}

void mEscala(int* mat, int k, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            *(mat + i * lin + j) = k * (*(mat + i * lin + j));
        }
    }
}

void mIdentidade(int *mat, int ordem) {
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            if (i == j) {
                *(mat + i * ordem + j) = 1;
            } else {
                *(mat + i * ordem + j) = 0;
            }
        }
    }
}

/*
int mTrasnposta(int *matT, int *mat, int lin, int col) {
    int p = 0;
    
    if (lin > max || col > max) {
        return 0;
    }
    //    matt[i][j] = mat[j][i]
    //    matt[1][0] = mat[0][1]

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            *(matT + i * lin + j) = *(mat + j+lin + i);
            p++;
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%i ", *(matT + i * lin + j));
        }
        printf("\n");
    }
    printf("\n");
    return p;
}
*/

void mOrdenaLinha(int* dados, int lin, int col) {
    int aux[10];

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col - 1; j++) {
            if (*(dados + i * lin + j) > *(dados + i * lin + j + 1)) {
                aux[j] = *(dados + i * lin + j);
                *(dados + i * lin + j) = *(dados + i * lin + j + 1);
                *(dados + i * lin + j + 1) = aux[j];

                j = -1;
            }
        }
    }
}

int main() {
    int matrix[max][max], matrixT[max][max], k, lin, col;
    srand(time(NULL));

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            matrix[i][j] = rand() % 50 + 1;
        }
        printf("\n");
    }
    printf("\n");
    int *m = &matrix, *mT = &matrixT;

    printf("1. Matriz Escalar:");
    printf("\n");
    printf("Digite um valor verdadeiro: ");
    scanf_s("%i", &k);
    printf("\n");
    mEscala(m, k, max, max);
    printMatrix(m);
    printf("\n");

    printf("2. Matriz Identidade:");
    printf("\n");
    mIdentidade(m, max);
    printMatrix(m);
    printf("\n");

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            matrix[i][j] = rand() % 50 + 1;
        }
        printf("\n");
    }

    /*
    printf("3. Matriz Transposta:");
    printf("\n");
    printf("Digite o valor de linhas: ");
    scanf_s("%i", &lin);
    printf("Digite o valor de colunas: ");
    scanf_s("%i", &col);
    printf("\n");
    printf("%i", mTrasnposta(mT, m, lin, col));
    */

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            matrix[i][j] = rand() % 50 + 1;
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("4. Matriz Ordenada por Linha:");
    printf("\n");
    mOrdenaLinha(m, max, max);
    printMatrix(m);
}
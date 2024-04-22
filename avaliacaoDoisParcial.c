#include <stdio.h>
#include <stdlib.h>

#define TAM 3
#define NTABS 4
int row = 0;

/* complete o código dado, implementando as funcoes prototipadas segundo suas especificacoes */


/* Prototipos */
char temVencedor(char *tabuleiro, int tam);
void exibeTabuleiro(char *tabuleiro, int tam);

int main() {
    char vencedor;
    char teste = 0;

    // tabuleiros preenchidos para teste
    char tabuleiro[NTABS][TAM][TAM]={{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},
                                     {{'O','X',' '},{'X','O',' '},{' ','X','O'}},
                                     {{'X','O',' '},{'X','O',' '},{'X',' ',' '}},
                                     {{'O','X','O'},{'O','O','X'},{'X','X','O'}}};

for (teste=0; teste<NTABS; teste++) {
    printf("Teste %d\n",teste);
    exibeTabuleiro(tabuleiro, TAM);
    //vencedor= temVencedor(tabuleiro, TAM);
    vencedor = 'n';
    if (vencedor == 'n')
        {
        printf("Sem vencedor !\n");
        }
    else
        {
        printf("O jogador %c venceu !\n",vencedor);
        }
    }
}

/* @brief Exibe na tela o tabuleiro do jogo
   @param  tabuleiro de jogo
   @param  tamanho do tabuleiro
   @retval 'jogador' vencedor ('X','O' ou ' ' se não há vencedo)
   */
void exibeTabuleiro(char *tabuleiro, int tam) {
    for (int j = 0; j < tam; j++) {
        for (int k = 0; k < tam; k++) {
            printf("| %c |", *(tabuleiro + row*tam + k));
        }
        printf("\n");
    }
    row += TAM;
}


/* @brief Verifica se tem vencedor do jogo
   @param  tabuleiro de jogo
   @param  tamanho do tabuleiro
   @retval 'jogador' vencedor ('X','O' ou ' ' se não há vencedo)
*/
char temVencedor(char *tabuleiro, int tam) {
    int sum = 0;
    
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (*(tabuleiro + i*tam + j) == *(tabuleiro + 2*i*tam + j)) { //verifica diagonal
                sum++;
            }
        }
    }
}

/*
0:
_ _ _
_ _ _
_ _ _

1:
o x _
x o _
_ x o

2:
x o _
x o _
x _ _

3:
o x o
o o x
x x o

to-do:
verifica linha
verifica coluna
verifica diagonal
*/
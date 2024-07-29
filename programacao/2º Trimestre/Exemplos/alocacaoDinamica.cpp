/****
C++ - Alocação dinâmica de memoria

@brief  Alocacao dinamica
@author Marcos Zuccolotto
@date   jul/2024
@version 1.0
*/

#include <iostream>
using namespace std; //!< Definindo escopo STD
#define NLINHAS 4
const string texto[NLINHAS]={
    "Alocação de memória é a reserva de um espaço de memoria para guardar dados de uma variável",
    "Alocação estática acontece no INICIO da execução do programa, e a quantidade de memória é fixa",
    "Alocação dinâmica acontece DURANTE a execução do programa",
    "Alocação dinâmica é OBRIGATORIA na implementação de compiladores C++"
};

double iMedia(int vet[],int nitens);

int main() {
    setlocale(LC_ALL, "portuguese");
    cout << "Alocacao dinâmica de memoria\n" << endl;

    int quantidade =0; // Alocacao estática - 1 inteiro
    for (int i=0;i<NLINHAS;i++)
        cout << texto[i] << endl;
    cout << "\nCalculo de media\nQuantidade de valores :" ;
    cin >> quantidade;

    // Alocacao dinâmica
    // reservando memoria para armazenar a quantidade de inteiros solicitada
    int *dados = new int [quantidade];
    if (dados == nullptr) {
        std::cout << "deu xabu" << std::endl;
        return -1;
    }
    cout << "\nEntrando com os dados" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << "dado " << i + 1 << ": ";
        cin >> dados[i];
        cout << endl;
    }
    double media = iMedia(dados, quantidade);
    cout << "Media = " << media << endl;

    /*IMPORTANTE: Liberando a memoria alocada */
    delete []dados;
}

double iMedia(int vet[],int nitens){
        /*          +- Conversao de tipo
                    V  */
    double media = double(vet[0]);
    for(int i = 1; i < nitens; i++) {
        media = media + double(vet[i]);
    }
    media = media / double(nitens);
    return media;
}
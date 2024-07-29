#include <iostream>

struct ivet_t {
    int *valor;
    int quantidade;
};
void showiVet (ivet_t *v);
/**
@brief adiciona mais um valor inteiro a variável tipo iVet
@param vetor que vai receber mais um item
@param valor do novo item
*/
void addiVet(ivet_t *v, int novoValor);

int main() {
    ivet_t vetor;
    vetor.valor=new int(1);
    vetor.quantidade=1;
    vetor.valor[0]=1024;

    std::cout << "Vetor contem " << vetor.quantidade << " elementos\n" << std::endl;

    showiVet(&vetor);
    addiVet(&vetor, 666);
    showiVet(&vetor);
    delete(vetor.valor);
}

void showiVet (ivet_t *v) {
    for (int i = 0; i < v->quantidade; i++)
        std::cout << v->valor[i] << "  ";
    std::cout << std::endl;
}

void addiVet(ivet_t *v, int novoValor) {
    int *add = new int [2];
    add[0] = *v->valor;
    add[1] = novoValor;
    v->valor = add;
    v->quantidade = 2;
}
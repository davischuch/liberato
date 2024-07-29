#include <iostream>

enum fErro_t {
    errValor = -2, //valor invalido
    errParam,      //parametros invalidos
    ok = 0         //sucesso na execucao
};

enum conexao_t {
    err = -1,
    serie = 1,
    paral
};

int main() {

}

conexao_t getValues(int r1, int r2, int req) {
    if ((r1 + r2) == req) {
        return serie;
    } else if ((1/(1 / r1) + (1 / r2)) == req) {
        return paral;
    } else return err;
}
#include "fonte.h"

fonte::fonte():componente() {
    //ctor
    unidade = "V";
}

fonte::fonte(double val):componente(val) {
    unidade = "V";
    tensao = valor;
}

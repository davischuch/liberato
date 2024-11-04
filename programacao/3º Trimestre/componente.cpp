#include <cstdlib>
#include "componente.h"

using namespace std;
// construtor - metodo chamado quando o objeto eh criado
/*
componente::componente()
{
    //ctor
    tensao=0;
    corrente=0;
    valor=0;
    unidade="";
    dt=0.000001;
}
*/
// construtor - metodo chamado quando o objeto eh criado
componente::componente(double val) {
    //ctor
    tensao=0;
    corrente=0;
    valor=0;
    unidade="";
    multiplicador="";
    dt=0.000001;
    valor=val;
}

// construtor - metodo chamado quando o objeto eh criado
componente::~componente() {
    //ctor
}

// interfaces
double componente::v(bool type) {
    if (type) return tensao;
    double out = tensao;
    if (tensao < 1) {
        out = out * 1000;
        multiplicador = "m";
    } else {
        multiplicador = "";
    }
    return out;
}

double componente:: i(void) {
    return corrente;
}

double componente::dT(void) {
    return dt;
}

bool componente::dT(double val) {
    if (val > 0) {
        dt=val;
        return true;
    } else return false;
}

double componente::getVal() {
    double out = valor;
    if (valor <= 0.000001) {
        out = out * 1000000000;
        multiplicador = "n";
    } else if (valor <= 0.001) {
        out = out * 1000000;
        multiplicador = "u";
    } else if (valor < 1) {
        out = out * 1000;
        multiplicador = "m";
    } else if (valor > 1000) {
        out = out / 1000;
        multiplicador = "k"; 
    } else if (valor > 1000000) {
        out = out / 1000000;
        multiplicador = "M"; 
    } else {
        multiplicador = "";
    }
    return out;
}

// Sobrecarga fora da classe
std::ostream& operator << (std::ostream&saida, componente &cmp) {
    saida << cmp.getVal() << " " << cmp.getM() << cmp.getU();
    return saida;
}
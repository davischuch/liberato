#include "resistor.h"

resistor::resistor() : componente() {
    //ctor
    unidade="Ω";
}

resistor::resistor(double val) : componente() {
    //ctor
    unidade="Ω";
    r(val);
}

double resistor::V(double i) {
    corrente = i;
    tensao = valor * corrente;
    return tensao;
}

double resistor::I(double v) {
    tensao=v;
    corrente = tensao / valor;
    return corrente;
}


double resistor::r() {
    return valor;
}

bool resistor::r(double val) {
    if (val > 0) {
        valor = val;
        return true;
    } else return false;
}

// Sobrecarga operadores dentro classe
/**
@brief associacao serie de resistores
*/
resistor resistor::operator+(resistor &outroR) {
    resistor req; //!< resistor equivalente da associacao serie
    req.valor=this->valor+outroR.valor;
    return req;
}
/**
@brief associacao serie de resistores
*/
resistor resistor::operator||(resistor &outroR) {
    resistor req; //!< resistor equivalente da associacao serie
    req.valor=(this->valor*outroR.valor)/(this->valor+outroR.valor);
    return req;
}
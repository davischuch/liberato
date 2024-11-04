#include "capacitor.h"

capacitor::capacitor():componente() {
    //ctor
    unidade = "F";
}

capacitor::capacitor(double val):componente() {
    unidade = "F";
    c(val);
}

/*
double capacitor::v()
{
    return componente::v();
}
*/

double capacitor::V(double i) {
    double q; // quanto a carga variou no intevalo dt
    corrente = i;
    q = corrente * dt;
    tensao = q / valor + tensao;
    /* vc(t1)=int(i(dt))/C +v(to) */
    return tensao;
}

double capacitor::I(double v) {
    double dv;
    dv = v - tensao;
    corrente = valor * dv / dt;
    tensao = v;
    return corrente;
}

double capacitor::c() {
    return valor;
}

bool capacitor::c(double val) {
    if (val > 0) {
        valor = val;
        return true;
    } else return false;
}

capacitor capacitor::operator+(capacitor &outroC) {
    capacitor ceq;
    ceq.valor = (this->valor * outroC.valor) / (this->valor + outroC.valor);
    return ceq;
}

capacitor capacitor::operator||(capacitor &outroC) {
    capacitor ceq;
    ceq.valor = this->valor + outroC.valor;
    return ceq;
}
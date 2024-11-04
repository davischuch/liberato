#include "componente.h"

#ifndef RESISTOR_H
#define RESISTOR_H

class resistor : public componente {
    public:
        resistor();
        resistor(double val);
        double V(double i) override;
        double I(double v) override;
        double r();
        bool r(double valor);
        resistor operator + (resistor &outroR);
        resistor operator || (resistor &outroR);
};

#endif // RESISTOR_H
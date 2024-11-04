#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "fonte.h"
#include "resistor.h"
#include "capacitor.h"
#include "componente.h"

#include "fonte.cpp"
#include "resistor.cpp"
#include "capacitor.cpp"
#include "componente.cpp"

using namespace std;

double curr(double i, string* mult) {
    double out = i;
    if (i <= 0.000001) {
        out = out * 1000000000;
        *mult = "n";
    } else if (i <= 0.001) {
        out = out * 1000000;
        *mult = "u";
    } else if (i < 1) {
        out = out * 1000;
        *mult = "m";
    } else {
        *mult = "";
    }
    return out;
}

int main() {
    resistor r(2200);
    capacitor c(0.00005);

    fonte Vf(10);

    ofstream outf;
    outf.open("vc.dat", ios::out);

    double dt = 0.001;
    c.dT(dt);
    double i;
    string mult;

    for (int tempo = 0; tempo < 1000; tempo++) {
        cout << r.v(true);
        i = r.I(Vf.v(true) - c.v(true));

        c.V(i);
        cout << "t = " << tempo * dt << " Vc = " << c.v(false) << endl;
        outf << tempo * dt << " / " << c.v(false) << " " << c.getM() << "V" <<  " / " << curr(i, &mult) << " " << mult << "A" <<  endl;
    }
    outf.close();

    resistor r1(120000);
    resistor r2(100000);
    resistor req;

    req = r1 + r2;
    std::cout << req << std::endl;

    capacitor c1(0.047);
    capacitor c2(0.047);
    capacitor ceq;

    ceq = c1 + c2;
    std::cout << ceq << std::endl;
}
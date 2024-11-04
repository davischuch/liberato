#include <ostream>
#include <string>
#ifndef COMPONENTE_H
#define COMPONENTE_H

class componente
{
    public:
        //componente();
        componente(double val=0);
        virtual ~componente();
        double v(bool type);
        virtual double V(double i){return tensao;};
        double i(void);
        virtual double I(double v){return corrente;};
        double dT(void);
        bool dT(double val);
        double getVal();
        std::string getU(){return unidade;};
        std::string getM(){return multiplicador;};
    protected:
        double valor;
        std::string unidade;
        std::string multiplicador;
        double tensao;
        double corrente;
        double dt;
    private:
};

std::ostream& operator << (std::ostream&saida, componente &cmp);

#endif // COMPONENTE_H
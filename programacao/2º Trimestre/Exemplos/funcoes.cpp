/****
C++ - Funcoes
      Passagem por referencia
      Parametros Default

@brief  funcoes CPP - passagem referencia e parametros default
@author Marcos Zuccolotto
@date   jul/2024
@version 1.0
*/

#include <iostream>
using namespace std; //!< Definindo escopo STD

/**    +-- Nome do tipo de dado definido pela enum
       V                               */
enum ferro_t { //!< Codigo erro retorno funcao
            ERR_VALOR=-2,   //!< valor invalido
            ERR_PARAM,      //!< parametros invalidos
            OK=0            //!< sucesso na execução
};

enum conexao_t //!< Tipo conexao desejada
                {ERR=-1,   //!< erro de parametros / valores
                 SERIE=1, //!<conexao serie
                 PARAL};  //!< conexao paralelo

const string associacao[]={"","serie","paralelo"};

/**    Parametro DEFAULT - se omitido, este sera valor assumido V */
ferro_t resAssocia(double &res1, double res2, conexao_t associa=SERIE);
/**                           ^ - Passagem por referencia
                              Permite alteracao da variavel pela funcao *

/** Sobrecarga de nome de funcoes tambem eh utilizado - polimorfismo */
ferro_t exibeResultado(double r1, double r2, double req, conexao_t assoc);

int main() {
    setlocale(LC_ALL, "portuguese");

    cout << "Associação de resistores " << endl;

    double r1=1200, r2=5600;
    double requi;
    ferro_t st;

    double r1old=r1;
    st=resAssocia(r1,r2);
    exibeResultado(r1old,r2,r1, SERIE);

    r1=r1old;

    st=resAssocia(r1,r2,PARAL);
    exibeResultado(r1old,r2,r1, PARAL);

    r1=r1old;

    st=resAssocia(r1,r2,SERIE);
    exibeResultado(r1old,r2,r1, SERIE);
}

/**
@brief  Calcula associacao de resistores
@param  primeiro resistor / resultado
@param  segundo resistor
@param  tipo associação
@retval status execucao
*/
ferro_t resAssocia(double &res1, double res2, conexao_t associa) {
    if (res1<0 || res2<0)
        return ERR_VALOR;
    if (associa < SERIE || associa > PARAL)
        return ERR_PARAM;
    if (associa==PARAL) {
       res1=1/(1/res1+1/res2);
    } else {
       res1+=res2;
    }
    return OK;
}

/**
@brief  Exibe resultado associacao
@param  primeiro resistor /
@param  segundo resistor
@param  resultado
@param  tipo assoociacao
@retval status execucao
*/
ferro_t exibeResultado(double r1, double r2, double req, conexao_t associa) {
    if (associa < SERIE || associa > PARAL)
        return ERR_PARAM;
    cout << "R1 = " << r1 << " ohms associado em " << associacao[associa] << " com R2 = " << r2 << " ohms" ;
    cout << " resulta em " << req << " ohms" << endl;

    return OK;
}
#ifndef CALCULO_H
#define CALCULO_H

#include <QString>
#include <qmath.h>


#include <iostream>
#include <complex>
//#include <complex.h>




//#include <QDebug>

class Calculo
{
public:
    Calculo();

    double getTensaoFonte() const;
    void setTensaoFonte(double value);
    double getFrequencia() const;
    void setFrequencia(double value);

    double getResistenciaA() const;
    void setResistenciaA(double value);
    double getIndutanciaA() const;
    void setIndutanciaA(double value);

    double getResistenciaB() const;
    void setResistenciaB(double value);
    double getIndutanciaB() const;
    void setIndutanciaB(double value);

    double getCapacitancia() const;
    void setCapacitancia(double value);

    double getPassoDeCalculo() const;
    void setPassoDeCalculo(double value);
    double getTempoDeSimulacao() const;
    void setTempoDeSimulacao(double value);

private:
    //Qvector<double> ;

    double tensaoFonte;
    double frequencia;

    double resistenciaA;
    double indutanciaA;
    double resistenciaB;
    double indutanciaB;

    double capacitancia;
    double passoDeCalculo;
    double tempoDeSimulacao;
};

#endif // CALCULO_H

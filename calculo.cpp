#include "calculo.h"

Calculo::Calculo()
{

}

double Calculo::getTensaoFonte() const
{
    return tensaoFonte;
}

void Calculo::setTensaoFonte(double value)
{
    tensaoFonte = value;
}

double Calculo::getFrequencia() const
{
    return frequencia;
}

void Calculo::setFrequencia(double value)
{
    frequencia = value;
}

double Calculo::getResistenciaA() const
{
    return resistenciaA;
}

void Calculo::setResistenciaA(double value)
{
    resistenciaA = value;
}

double Calculo::getIndutanciaA() const
{
    return indutanciaA;
}

void Calculo::setIndutanciaA(double value)
{
    indutanciaA = value;
}

double Calculo::getResistenciaB() const
{
    return resistenciaB;
}

void Calculo::setResistenciaB(double value)
{
    resistenciaB = value;
}

double Calculo::getIndutanciaB() const
{
    return indutanciaB;
}

void Calculo::setIndutanciaB(double value)
{
    indutanciaB = value;
}

double Calculo::getCapacitancia() const
{
    return capacitancia;
}

void Calculo::setCapacitancia(double value)
{
    capacitancia = value;
}

double Calculo::getPassoDeCalculo() const
{
    return passoDeCalculo;
}

void Calculo::setPassoDeCalculo(double value)
{
    passoDeCalculo = value;
}

double Calculo::getTempoDeSimulacao() const
{
    return tempoDeSimulacao;
}

void Calculo::setTempoDeSimulacao(double value)
{
    tempoDeSimulacao = value;
}

bool Calculo::getSimulacaoIniciada() const
{
    return simulacaoIniciada;
}

void Calculo::setSimulacaoIniciada(bool value)
{
    simulacaoIniciada = value;
}

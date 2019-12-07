#include "valores.h"

QString Valores::getVetorNome() const
{
    return vetorNome;
}

void Valores::setVetorNome(const QString &value)
{
    vetorNome = value;
}

double Valores::getVetorModulo() const
{
    return vetorModulo;
}

void Valores::setVetorModulo(double value)
{
    vetorModulo = value;
}

double Valores::getVetorAngulo() const
{
    return vetorAngulo;
}

void Valores::setVetorAngulo(double value)
{
    vetorAngulo = value;
}

Valores::Valores()
{

}

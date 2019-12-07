#ifndef VALORES_H
#define VALORES_H

#include "calculo.h"

class Valores
{
private:
    QString vetorNome;
    double vetorModulo;
    double vetorAngulo;

public:
    Valores();

    QString getVetorNome() const;
    void setVetorNome(const QString &value);
    double getVetorModulo() const;
    void setVetorModulo(double value);
    double getVetorAngulo() const;
    void setVetorAngulo(double value);
};

#endif // VALORES_H

#ifndef VETOR_H
#define VETOR_H

#include <QVector>
#include <QFile>
#include <algorithm>
#include <QFile>
#include "valores.h"

class Vetor
{
private:
    QVector<Valores> vetores;
public:
    Vetor();

    void adicionarVetor(Valores a);
    void apagarTudo();
    void ordenarModulo();
    void ordenarAngulo();

    bool salvarArquivo(QString arquivo);
    bool carregarArquivo(QString arquivo);
    Valores operator[](int indice);
};

#endif // VETOR_H

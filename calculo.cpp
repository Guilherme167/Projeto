#include "calculo.h"

Calculo::Calculo()
{

}
/*
bool Objeto::salvarArquivo(QString file)
{
    QFile arquivo(file);
    arquivo.open(QIODevice::WriteOnly);
    if(arquivo.isOpen() == 1){
        for(auto a:objetos){
            QString linha = a.getObj() + "," + a.getCi() + "," + QString::number(a.getValor()) + "," + a.getData() + "," + a.getEstado() +","+ a.getDestino() + "," + QString::number(a.getPeso()) +"\n";
            arquivo.write(linha.toLocal8Bit());
        }
        arquivo.close();
        return 1;
    }else{
        return 0;
    }

}

bool Objeto::carregarArquivo(QString file)
{

    QFile arquivo(file);
    if(arquivo.isOpen() == 1)return 1;
    else{
        arquivo.open(QIODevice::ReadOnly);
        QString linha;
        QStringList dados;
        while(!arquivo.atEnd()){
            Cadastro temp;
            linha = arquivo.readLine();
            dados = linha.split(",");
            temp.setObj(dados[0]);
            temp.setCi(dados[1]);
            temp.setValor(dados[2].toDouble());
            temp.setData(dados[3]);
            temp.setEstado(dados[4]);
            temp.setDestino(dados[5]);
            temp.setPeso(dados[6].toDouble());
            if(objetoExiste(temp) == 0)
                inserirObjeto(temp);
        }
        arquivo.close();
        return 0;
    }

}
*/

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

#include "vetor.h"

Vetor::Vetor()
{

}

bool Vetor::salvarArquivo(QString nomeArquivo)
{
    QFile arquivo(nomeArquivo);
    arquivo.open(QIODevice::WriteOnly);
    if(arquivo.isOpen() == 1){
        for(auto a:vetores){
            QString linha = a.getVetorNome() + "," + QString::number(a.getVetorModulo()) + "," + QString::number(a.getVetorAngulo()) + "\n";
            arquivo.write(linha.toLocal8Bit());
        }
        arquivo.close();
        return 1;
    }else{
        return 0;
    }
}

bool Vetor::carregarArquivo(QString nomeArquivo)
{
    QFile arquivo(nomeArquivo);
    if(arquivo.isOpen() == 1)return 1;
        else{
            arquivo.open(QIODevice::ReadOnly);
            QString linha;
            QStringList dados;
            while(!arquivo.atEnd()){
                Valores vetores;
                linha = arquivo.readLine();
                dados = linha.split(",");

                vetores.setVetorNome(dados[0]);
                vetores.setVetorModulo(dados[1].toDouble());
                vetores.setVetorAngulo(dados[2].toDouble());
                adicionarVetor(vetores);
            }
            arquivo.close();
            return 0;
        }
}

void Vetor::adicionarVetor(Valores a)
{
    vetores.push_back(a);
}

void Vetor::apagarTudo()
{
    vetores.erase(vetores.begin(),vetores.end());
}

void Vetor::ordenarModulo()
{
    std::sort(vetores.begin(),vetores.end(),[](Valores a, Valores b)
    {
        return a.getVetorModulo()>b.getVetorModulo();
    });
}

void Vetor::ordenarAngulo()
{
    std::sort(vetores.begin(),vetores.end(),[](Valores a, Valores b)
    {
        return a.getVetorAngulo()>b.getVetorAngulo();
    });
}

Valores Vetor::operator[](int indice)
{
    return vetores[indice];
}

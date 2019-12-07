#include "mainwindow.h"
#include "ui_mainwindow.h"

Calculo temp;
Valores var;
Vetor a;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSimular_clicked()
{
    if((ui->impTensao->text())!= "" and (ui->impFreq->text())!= "" and (ui->impResA->text())!= "" and (ui->impIndA->text())!= "" and (ui->impResB->text())!= "" and (ui->impIndB->text())!= "" and (ui->impCap->text())!= "" and (ui->passoAtual->currentText())!= "" and (ui->tempoAtual->currentText())!= "")
    {
        if((ui->impTensao->text())> "0" and (ui->impFreq->text())> "0" and (ui->impResA->text())> "0" and (ui->impIndA->text())> "0" and (ui->impResB->text())> "0" and (ui->impIndB->text())> "0" and (ui->impCap->text())> "0")
        {  
            temp.setTensaoFonte(ui->impTensao->text().toDouble());
            temp.setFrequencia(ui->impFreq->text().toDouble());
            temp.setResistenciaA(ui->impResA->text().toDouble());
            temp.setIndutanciaA(ui->impIndA->text().toDouble());
            temp.setResistenciaB(ui->impResB->text().toDouble());
            temp.setIndutanciaB(ui->impIndB->text().toDouble());
            temp.setCapacitancia(ui->impCap->text().toDouble());
            temp.setPassoDeCalculo(ui->passoAtual->currentText().toDouble());
            temp.setTempoDeSimulacao(ui->tempoAtual->currentText().toDouble());

            MainWindow::makePlot();
            MainWindow::simular();
            QMessageBox::information(this,"Programa","A simulação ocorreu com sucesso!");
        }
        else
        {
            QMessageBox::critical(this,"Erro","A simulação não pode ser concluida. Caracteres como 0 (Zero), vírgula, simbolos ou letras não podem ser considerados como parâmetros. Apenas números positivos!");
        }
    }
    else
    {
        QMessageBox::critical(this,"Erro","A simulação não pode ser concluida. Preencha os campos vazios!");
    }
}

void MainWindow::makePlot()
{
    double ri, li, rl, ll, cc, vi, h, t, tf, f, w, vica, pi = 3.14159265359, r2 = 1.4142135624; // Variaveis utilizadas no calculo

    vi = temp.getTensaoFonte();
    f = temp.getFrequencia();
    tf = temp.getTempoDeSimulacao();
    h = temp.getPassoDeCalculo();
    w = 2*pi*f;

    ri = temp.getResistenciaA();
    li = temp.getIndutanciaA();
    rl = temp.getResistenciaB();
    ll = temp.getIndutanciaB();
    cc = temp.getCapacitancia();

    int i = 0, n = 3000; // Parametro para salvar os dados dos vetores
    double vcc, vli, vll, ii, ic, il, dii, dil, dvcc; // Tensões e correntes nos componentes do circuito
    vcc = vli = vll = ii = ic = il = dii = dil = dvcc = vica = t = 0;

    QVector<double> tempo(n), svi(n), svli(n), svll(n), svcc(n), sii(n), sil(n), sic(n);
    while (t < tf)
    {
        vica = vi*r2*qSin(w*t);

        dii = -(ri/li)*ii + (1/li)*(vica-vcc);
        ii = ii + dii*h;
        vli = ri*ii + li*dii;

        ic = ii -il;
        dvcc = (1/cc)*ic;
        vcc = vcc + dvcc*h;

        vll = vcc;
        dil = -(rl/ll)*il + vll/ll;
        il = il + dil*h;
        //----------------------------
        tempo[i] = t;
        svi[i] = vica;
        svli[i] = vli;
        svll[i] = vll;
        svcc[i] = vcc;

        sii[i] = ii;
        sil[i] = il;
        sic[i] = ic;
        //----------------------------
        t = t + h;
        i++;
    } // Fim do loop de simulação

    QPen penBlue, penRed;
    penBlue.setColor(QColor(Qt::blue));
    penRed.setColor(QColor(Qt::red));

    // Gráfico da Fonte:
    ui->customPlotA->addGraph();
    ui->customPlotA->graph(0)->setData(tempo, svi);
    ui->customPlotA->addGraph();
    ui->customPlotA->graph(1)->setData(tempo, sii);
    ui->customPlotA->graph(0)->setPen(penBlue);
    ui->customPlotA->graph(1)->setPen(penRed);

    ui->customPlotA->xAxis->setRange(0, tf);
    ui->customPlotA->yAxis->setRange(-1.5*vi, 1.5*vi);
    ui->customPlotA->xAxis->setLabel("Tempo(s)");
    ui->customPlotA->yAxis->setLabel("Amplitude");
    ui->customPlotA->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlotA->replot();

    // Gráfico da Filtro Indutivo:
    ui->customPlotB->addGraph();
    ui->customPlotB->graph(0)->setData(tempo, svli);
    ui->customPlotB->addGraph();
    ui->customPlotB->graph(1)->setData(tempo, sii);
    ui->customPlotB->graph(0)->setPen(penBlue);
    ui->customPlotB->graph(1)->setPen(penRed);

    ui->customPlotB->xAxis->setRange(0, tf);
    ui->customPlotB->yAxis->setRange(-1.5*vi, 1.5*vi);
    ui->customPlotB->xAxis->setLabel("Tempo(s)");
    ui->customPlotB->yAxis->setLabel("Amplitude");
    ui->customPlotB->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlotB->replot();

    // Gráfico da Filtro Capacitivo:
    ui->customPlotC->addGraph();
    ui->customPlotC->graph(0)->setData(tempo, svcc);
    ui->customPlotC->addGraph();
    ui->customPlotC->graph(1)->setData(tempo, sic);
    ui->customPlotC->graph(0)->setPen(penBlue);
    ui->customPlotC->graph(1)->setPen(penRed);

    ui->customPlotC->xAxis->setRange(0, tf);
    ui->customPlotC->yAxis->setRange(-1.5*vi, 1.5*vi);
    ui->customPlotC->xAxis->setLabel("Tempo(s)");
    ui->customPlotC->yAxis->setLabel("Amplitude");
    ui->customPlotC->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlotC->replot();

    // Gráfico da Carga Elétrica:
    ui->customPlotD->addGraph();
    ui->customPlotD->graph(0)->setData(tempo, svll);
    ui->customPlotD->addGraph();
    ui->customPlotD->graph(1)->setData(tempo, sil);
    ui->customPlotD->graph(0)->setPen(penBlue);
    ui->customPlotD->graph(1)->setPen(penRed);

    ui->customPlotD->xAxis->setRange(0, tf);
    ui->customPlotD->yAxis->setRange(-1.5*vi, 1.5*vi);
    ui->customPlotD->xAxis->setLabel("Tempo(s)");
    ui->customPlotD->yAxis->setLabel("Amplitude");
    ui->customPlotD->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlotD->replot();
}

void MainWindow::simular()
{
    temp.setSimulacaoIniciada(1);
    for(int i = 0; i < 7 ; i++)ui->tabela->removeRow(0);
    a.apagarTudo();

    double ri, li, rl, ll, cc, vi, f, w, vica, pi = 3.14159265359, r2 = 1.4142135624, gr = 180/pi;

    vi = temp.getTensaoFonte();
    f = temp.getFrequencia();
    w = 2*pi*f;
    vica = vi/r2;

    ri = temp.getResistenciaA();
    li = temp.getIndutanciaA();
    rl = temp.getResistenciaB();
    ll = temp.getIndutanciaB();
    cc = temp.getCapacitancia();

    std::complex<double> vcc, vli, vll, ii, ic, il, div, xc(0,1/(w*cc)), xli(0,w*li), xll(0,w*ll);

    div = (-xc*ri +xc*xli -xc*rl +xc*xll +ri*rl +xll*ri +xli*rl -xli*xll);
    // Forma retangular
    ii = (-xc+rl+xll)*vica/div;
    ic = (rl+xll)*vica/div;
    il = (-xc)*vica/div;

    vcc = (xc)*ic;
    vli = (xli + ri)*ii;
    vll = (xll + rl)*il;
    //------------------------------------
    int nlinhas;

    var.setVetorNome("Corrente ii"); var.setVetorModulo(abs(ii)); var.setVetorAngulo(arg(ii)*gr);
    a.adicionarVetor(var);
    nlinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(nlinhas);
    exibirTabela(var, nlinhas);

    var.setVetorNome("Corrente il"); var.setVetorModulo(abs(il)); var.setVetorAngulo(arg(il)*gr);
    a.adicionarVetor(var);
    nlinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(nlinhas);
    exibirTabela(var, nlinhas);

    var.setVetorNome("Corrente ic"); var.setVetorModulo(abs(ic)); var.setVetorAngulo(arg(ic)*gr);
    a.adicionarVetor(var);
    nlinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(nlinhas);
    exibirTabela(var, nlinhas);

    var.setVetorNome("Tensao Indutor"); var.setVetorModulo(abs(vli)); var.setVetorAngulo(arg(vli)*gr);
    a.adicionarVetor(var);
    nlinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(nlinhas);
    exibirTabela(var, nlinhas);

    var.setVetorNome("Tensao Carga"); var.setVetorModulo(abs(vll)); var.setVetorAngulo(arg(vll)*gr);
    a.adicionarVetor(var);
    nlinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(nlinhas);
    exibirTabela(var, nlinhas);

    var.setVetorNome("Tensao Capacitor"); var.setVetorModulo(abs(vcc)); var.setVetorAngulo(arg(vcc)*gr);
    a.adicionarVetor(var);
    nlinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(nlinhas);
    exibirTabela(var, nlinhas);

    var.setVetorNome("Tensao Fonte"); var.setVetorModulo(vica); var.setVetorAngulo(0);
    a.adicionarVetor(var);
    nlinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(nlinhas);
    exibirTabela(var, nlinhas);

    ui->tabela->setColumnWidth(0,130);
    ui->tabela->setColumnWidth(1,100);
    ui->tabela->setColumnWidth(2,120);
}

void MainWindow::exibirTabela(Valores a, int linha)
{
    ui->tabela->setItem(linha,0, new QTableWidgetItem(a.getVetorNome()));
    ui->tabela->setItem(linha,1, new QTableWidgetItem(QString::number(a.getVetorModulo())));
    ui->tabela->setItem(linha,2, new QTableWidgetItem(QString::number(a.getVetorAngulo())));
}

void MainWindow::on_actionConsultar_manual_triggered()
{
    QString url = "https://github.com/Guilherme167/Projeto/blob/master/README.md";
    QDesktopServices::openUrl(QUrl(url));
}

void MainWindow::on_actionSair_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSalvar_triggered()
{
    QString nomeArquivo;
    nomeArquivo = QFileDialog::getSaveFileName(this,"Salvar Arquivo","","*.csv");
    if(a.salvarArquivo(nomeArquivo) == 1)QMessageBox::information(this,"Salvo","Arquivo salvo com sucesso!");
    else QMessageBox::critical(this,"Erro","O arquivo não foi salvo.");
}

void MainWindow::on_actionAbrir_triggered()
{
    QString nomeArquivo;
    nomeArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo","","*.csv");

    if(a.carregarArquivo(nomeArquivo) == 1){
            QMessageBox::critical(this,"Erro"," O arquivo não foi berto");
        }else{
            for(int i = 0; i < 7 ; i++)ui->tabela->removeRow(0);
            for(int i = 0; i < 7; i++){
                ui->tabela->insertRow(i);
                exibirTabela(a[i],i);
            }
            ui->tabela->setColumnWidth(0,130);
            ui->tabela->setColumnWidth(1,100);
            ui->tabela->setColumnWidth(2,120);
        }
}

void MainWindow::on_btnOrdenarModulo_clicked()
{
    if(temp.getSimulacaoIniciada() == 1){
        a.ordenarModulo();
        ui->tabela->clearContents();
            for(int i = 0; i < 7; i++){
                exibirTabela(a[i],i);
        }
    }
}

void MainWindow::on_btnOrdenarAngulo_clicked()
{
    if(temp.getSimulacaoIniciada() == 1){
        a.ordenarAngulo();
        ui->tabela->clearContents();
            for(int i = 0; i < 7; i++){
                exibirTabela(a[i],i);
        }
    }
}

void MainWindow::on_btnLimparTabela_clicked()
{
    temp.setSimulacaoIniciada(0);
    for(int i = 0; i < 7 ; i++)ui->tabela->removeRow(0);
    a.apagarTudo();
    QMessageBox::information(this,"Tabela","A tabela foi limpa com sucesso.");
}

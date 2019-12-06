#include "mainwindow.h"
#include "ui_mainwindow.h"

Calculo temp;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow::makePlot();
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
            MainWindow::gerarTabela();
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
    double ri, li, rl, ll, cc, vi, h, t, tf, f, w, vica, pi = 3.14159265359; // Variaveis utilizadas no calculo

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
        vica = vi*qSin(w*t);

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

void MainWindow::gerarTabela()
{
    /*
    double ri, li, rl, ll, cc, vi, f, w, vica, pi = 3.14159265359, r2 = 1.4142135624;
    double vcc, vli, vll, ii, ic, il, div, xc, xli, xll;
    vcc = vli = vll = ii = ic = il = div = vica = 0;

    vi = temp.getTensaoFonte();
    f = temp.getFrequencia();
    w = 2*pi*f;
    vica = vi/r2;

    ri = temp.getResistenciaA();
    li = temp.getIndutanciaA();
    rl = temp.getResistenciaB();
    ll = temp.getIndutanciaB();
    cc = temp.getCapacitancia();


    int i;
    //complex<double> xc(0,0);
    //, xli, xll;



    xc = i*1/(w*cc);
    xli = i*w*li;
    xll = i*w*ll;

    div = (-xc*ri +xc*xli -xc*rl +xc*xll +ri*rl +xll*ri +xli*rl -xli*xll);
    // Forma retangular
    ii = (-xc+rl+xll)*vica/div;
    ic = (rl+xll)*vica/div;
    il = (-xc)*vica/div;

    vcc = (xc)*ic;
    vli = (xli + ri)*ii;
    vll = (xll + rl)*il;

    // Forma polar (M-modulo) (A-angulo)
    PMii = abs(ii); PAii = angle(ii);
    PMic = abs(ic); PAic = angle(ic);
    PMil = abs(il); PAil = angle(il);

    PMvcc = abs(vcc); PAvcc = angle(vcc);
    PMvli = abs(vli); PAvli = angle(vli);
    PMvll = abs(vll); PAvll = angle(vll);
    */
}


//--------------------------------------------------------------------------

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
    /*
    QString filename;
    filename = QFileDialog::getSaveFileName(this,"Salvar Arquivo","","*.csv");
    if(a.salvarArquivo(filename) == 1)QMessageBox::information(this,"Salvo","Arquivo salvo com sucesso!");
    else QMessageBox::critical(this,"Erro", "O arquivo não foi salvo.");
    */
}

void MainWindow::on_actionAbrir_triggered()
{
    /*
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","Arquivo separado por vírgulas(*.csv)");
    if(a.carregarArquivo(filename) == 1){
        QMessageBox::critical(this,"Arquivo"," O arquivo já foi lido, favor cheque a tabela!");
    }else{
        ui->tabela->clearContents();
        on_actionLimpar_Tabela_triggered();
        for(int i=0;i<a.size();i++){
            ui->tabela->insertRow(i);
            inserirNaTabela(a[i],i);
        }
        atualizarEstatisticas();
        QMessageBox::information(this,"Arquivo"," O arquivo foi lido, cheque a tabela!");
    }
    */
}

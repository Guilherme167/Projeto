#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include "calculo.h"
#include "valores.h"
#include "vetor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSimular_clicked();
    void on_btnOrdenarModulo_clicked();
    void on_btnOrdenarAngulo_clicked();
    void on_btnLimparTabela_clicked();

    void on_actionConsultar_manual_triggered();
    void on_actionSair_triggered();
    void on_actionSalvar_triggered();
    void on_actionAbrir_triggered();

    void makePlot();
    void simular();
    void exibirTabela(Valores a, int linha);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

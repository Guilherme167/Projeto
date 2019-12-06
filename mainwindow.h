#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include "calculo.h"

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
    void makePlot();
    void on_btnSimular_clicked();
    void on_actionConsultar_manual_triggered();
    void on_actionSair_triggered();
    void on_actionSalvar_triggered();
    void on_actionAbrir_triggered();
    void gerarTabela();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

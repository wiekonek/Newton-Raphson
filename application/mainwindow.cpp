#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dlfcn.h>
#include <iostream>

#include "equationpa.h"

void * handle;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->frame->setEnabled(false);
}

MainWindow::~MainWindow() {

    if(handle)
        dlclose(handle);
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() {
    close();
}

void MainWindow::on_pushButton_loadLib_clicked() {

    if(handle)
        dlclose(handle);

    handle = dlopen (ui->lineEdit_libPath->text().toStdString().c_str(), RTLD_LAZY);
    if (!handle) {
        ui->frame->setEnabled(false);
        ui->label_error->setText("Nie mogę załadować biblioteki. Sprawdź ścieżkę.");
        fputs (dlerror(), stderr);
    } else {
        ui->label_error->setText("");
        ui->frame->setEnabled(true);
    }
}

void MainWindow::on_pushButton_PA_clicked() {

    ui->label_error->setText("");
    ui->label_ret->setText("x = ");

    EquationPA *eq = new EquationPA(ui->lineEdit_x->text(), handle, ui->lineEdit_functionName->text(), ui->lineEdit_it->text(), ui->lineEdit_eps->text());
    eq->solve_pa();

    switch (eq->get_st()) {
    case 0: ui->label_ret->setText("x = " + QString::number((double)eq->get_x(), 'f', 40) );
        break;
    case 1: ui->label_error->setText("mit < 1");
        break;
    case 2: ui->label_error->setText("during the calculations the second derivative of f with respect to x at a point x is equal to zero");
        break;
    case 3: ui->label_ret->setText("x = " + QString::number((double)eq->get_x(), 'f', 40) );
        ui->label_error->setText("the given accuracy eps is not achieved in mit iteration steps");
        break;
    case 4: ui->label_error->setText("during the calculations sqr(df(x))-2*f(x)*d2f(x)<0 at a point x");
        break;
    }

    delete eq;
}

void MainWindow::on_pushButton_IA_clicked() {

}

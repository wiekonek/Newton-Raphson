#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dlfcn.h>
#include <iostream>

#include "equationpa.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() {
    close();
}

void MainWindow::on_pushButton_clicked() {

    typedef long double (*func) (long double);
    void *handle;
    char *error;

    handle = dlopen ("/home/konrad/Documents/c_files/newton_raphson/build-newrap-Desktop_Qt_5_4_2_GCC_64bit-Debug/libnewrap.so", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }

    func f = (func)dlsym(handle, "f");
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

    func df = (func)dlsym(handle, "df");
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

    func d2f = (func)dlsym(handle, "d2f");
    if ((error = dlerror()) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }

    EquationPA *eq = new EquationPA(ui->lineEdit_x->text(), f, df, d2f, ui->lineEdit_it->text().toInt(), 0.001, "0", 0, 0);
    eq->solve_pa();

    ui->label_ret->setText( "x: " + QString::number((double)eq->get_x()) + "; fatx: " + QString::number((double)eq->get_fatx()) + "; st: " + QString::number(eq->get_st()) );

    delete eq;
    dlclose(handle);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qevent.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , caloriesCalculator(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Fit-counter");
    setFixedSize(QSize(530, 574));
    form = new Form(true);
    form2 = new Form(false);

    connect(this, &MainWindow::signal, form, &Form::slot);
    connect(this, &MainWindow::signal_2, form2, &Form::slot);

    ui->lineEdit->setPlaceholderText("my height(cm):");
    ui->lineEdit_2->setPlaceholderText("my weight(kg):");
    ui->lineEdit_3->setPlaceholderText("my age:");

    ui->label_3->setFocus();
}

MainWindow::~MainWindow()
{
    delete caloriesCalculator;
    delete form;
    delete form2;
    delete ui;
}

void MainWindow::KeyPressEvent(QKeyEvent* e)
{
    if(e->key()==Qt::Key_Escape)
    {
       close();
    }
}

bool MainWindow::process_data()
{
    QString str = ui->lineEdit->text();
    str.replace(',', '.');
    float height = str.toFloat();
    str = ui->lineEdit_2->text();
    str.replace(',', '.');
    float weight = str.toFloat();
    int age = ui->lineEdit_3->text().toInt();
    if(caloriesCalculator != nullptr){
        delete caloriesCalculator;
        caloriesCalculator = nullptr;
    }
    try {
        caloriesCalculator = new Nutrition(age, height, weight);
        return true;
    }
    catch(std::exception& e){
        QMessageBox::critical(this, "Error", e.what());
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Critical error");
    }
    return false;
}

void MainWindow::on_pushButton_clicked()
{
    if (process_data()){
    form->set_text("Your BMI result");
    form->show();
    emit signal(caloriesCalculator->getBMI());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (process_data()){
    form2->set_text("Your nutrition result");
    form2->show();
    emit signal_2 (caloriesCalculator->getNutrition());
    }
}


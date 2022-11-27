#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , caloriesCalculator(nullptr)
{
    ui->setupUi(this);
    setFixedSize(QSize(530, 574));
    form = new Form;

    connect(this, &MainWindow::signal, form, &Form::slot);
    connect(this, &MainWindow::signal_2, form, &Form::slot_2);

    ui->lineEdit->setPlaceholderText("my height:");
    ui->lineEdit_2->setPlaceholderText("my weight:");
    ui->lineEdit_3->setPlaceholderText("my age:");

    ui->label_3->setFocus();
}

MainWindow::~MainWindow()
{
    delete caloriesCalculator;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    form->show();
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
    }
    catch(std::exception& e){
        QMessageBox::critical(this, "Error", e.what());
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Critical error");
    }
    emit signal(QString::number(caloriesCalculator->getBMI()));
    emit signal_2 (QString::number(caloriesCalculator->getNutrition()));
}


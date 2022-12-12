#include "form.h"
#include "bmicheck.h"
#include "qevent.h"
#include "ui_form.h"

Form::Form(bool check_BMI, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    is_BMI(check_BMI)
{
    ui->setupUi(this);
    setWindowTitle("Fit-counter");
    setFixedSize(QSize(530, 574));
}

Form::~Form()
{
    delete ui;
}

void Form::KeyPressEvent(QKeyEvent* e)
{
    if(e->key()==Qt::Key_Escape)
    {
       close();
    }
}

void Form::set_text(const QString &text)
{
    ui->label_4->setText(text);
}

void Form::slot(double result){
    ui->label_2->setText(QString::number(result));
    if(is_BMI){
        ui->label_3->setText(BMICheck::check(result));
    }
}

void Form::on_pushButton_clicked()
{
    close();
}


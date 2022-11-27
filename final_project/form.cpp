#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setFixedSize(QSize(530, 574));
}

Form::~Form()
{
    delete ui;
}

void Form::slot(QString i){
    ui->label_2->setText(i);
}
void Form::slot_2(QString a){
    ui->label_3->setText(a);
}

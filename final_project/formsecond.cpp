#include "formsecond.h"

FormSecond::FormSecond(QWidget *parent):
    QWidget(parent),
    ui(new Ui::FormSecond)
{
    ui->setupUi(this);
    setWindowTitle("Fit-counter");
    setFixedSize(QSize(530, 574));
}

FormSecond::~FormSecond()
{
    delete ui;
}

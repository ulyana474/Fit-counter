#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(bool check_BMI, QWidget *parent = nullptr);
    ~Form();

void KeyPressEvent(QKeyEvent* e);

void set_text(const QString& text);

bool is_BMI;

private:
    Ui::Form *ui;
public slots:
    void slot(double result);
private slots:
    void on_pushButton_clicked();
};

#endif // FORM_H

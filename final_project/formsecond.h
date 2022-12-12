#ifndef FORMSECOND_H
#define FORMSECOND_H

#include <QWidget>

namespace Ui {
class FormSecond;
}

class FormSecond : public QWidget
{
    Q_OBJECT
public:
    explicit FormSecond(QWidget *parent = nullptr);
    ~FormSecond();

private:
    Ui::FormSecond *ui;

public slots:
    void slot_2(QString a);

private slots:
    void on_pushButton_2_clicked();
};

#endif // FORMSECOND_H

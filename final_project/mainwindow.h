#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <form.h>
#include <nutrition.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();

signals:
    void signal(QString);
    void signal_2(QString);

private:
    Ui::MainWindow *ui;
    Form* form;
    Nutrition* caloriesCalculator;
};
#endif // MAINWINDOW_H

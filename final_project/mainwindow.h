#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QKeyEvent>
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

    void KeyPressEvent(QKeyEvent* e);

private:
    bool process_data();

public slots:
    void on_pushButton_clicked();

signals:
    void signal(double);
    void signal_2(double);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow* ui;
    Form* form;
    Form* form2;
    Nutrition* caloriesCalculator;
};
#endif // MAINWINDOW_H

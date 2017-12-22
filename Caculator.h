#ifndef CACULATOR_H
#define CACULATOR_H

#include <QMainWindow>
#include <QString>
#include <QKeyEvent>
namespace Ui {
class Caculator;
}

class Caculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Caculator(QWidget *parent = 0);
    ~Caculator();

private slots:

    void on_pushButton9_clicked();

    void on_pushButton8_clicked();

    void on_pushButton7_clicked();

    void on_pushButton6_clicked();

    void on_pushButton5_clicked();

    void on_pushButton4_clicked();

    void on_pushButton3_clicked();

    void on_pushButton2_clicked();

    void on_pushButton1_clicked();

    void on_pushButton0_clicked();



    void on_pushButton_ans_clicked();

    void on_pushButton_imag_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_ac_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_point_clicked();

private:
    void keyPressEvent(QKeyEvent *event);


    QString text = "";
    Ui::Caculator *ui;
};

#endif // CACULATOR_H

#include "Caculator.h"
#include "ui_caculator.h"
#include "BinNode.h"
#include "BinTree.h"



//去掉空格
void trim(string &s)
{
    int index = 0;
    if( !s.empty() )
        while( (index = s.find(' ',index)) != string::npos)
            s.erase(index,1);
}

Caculator::Caculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Caculator)
{
    ui->setupUi(this);
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocusPolicy(Qt::NoFocus);
}

Caculator::~Caculator()
{
    delete ui;
}

void Caculator::on_pushButton9_clicked()
{
    text += "9";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton8_clicked()
{
    text +="8";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton7_clicked()
{
    text +="7";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton6_clicked()
{
    text += "6";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton5_clicked()
{
    text +="5";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton4_clicked()
{
    text += "4";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton3_clicked()
{
    text += "3";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton2_clicked()
{
    text += "2";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton1_clicked()
{
    text += "1";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton0_clicked()
{
    text += "0";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_ans_clicked()
{
    BinTree ExprTree;
    QString Qexpr = ui->lineEdit->text();
    string expr = Qexpr.toStdString();
    trim(expr);
    try {
            ExprTree.ChangeToBitTree(expr);
    } catch(string wrong) {
        text = QString::fromStdString(wrong);
        ui->lineEdit->setText(text);
        text = "";
        return;
    }
    string buffer;
    ExprTree.postOrderTreeWalk(buffer);
    buffer = ExprTree.Calculate().Show() + "    (" + buffer + ")";
    text = QString::fromStdString(buffer);
    ui->lineEdit->setText(text);
    text = "";
}

void Caculator::on_pushButton_imag_clicked()
{
    text += "i";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_pow_clicked()
{
    text += "^";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_del_clicked()
{
    text.remove(text.length() - 1, 1);
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_ac_clicked()
{
    text.clear();
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_plus_clicked()
{
    text += "+";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_div_clicked()
{
    text += "/";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_mul_clicked()
{
    text += "*";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_minus_clicked()
{
    text += "-";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_left_clicked()
{
    text += "(";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_right_clicked()
{
    text += ")";
    ui->lineEdit->setText(text);
}

void Caculator::on_pushButton_point_clicked()
{
    text += ".";
    ui->lineEdit->setText(text);
}

void Caculator::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_1:
        on_pushButton1_clicked();
        break;
    case Qt::Key_2:
        on_pushButton2_clicked();
        break;
    case Qt::Key_3:
        on_pushButton3_clicked();
        break;
    case Qt::Key_4:
        on_pushButton4_clicked();
        break;
    case Qt::Key_5:
        on_pushButton5_clicked();
        break;
    case Qt::Key_6:
        on_pushButton6_clicked();
        break;
    case Qt::Key_7:
        on_pushButton7_clicked();
        break;
    case Qt::Key_8:
        on_pushButton8_clicked();
        break;
    case Qt::Key_9:
        on_pushButton9_clicked();
        break;
    case Qt::Key_0:
        on_pushButton0_clicked();
        break;
    case Qt::Key_Backspace:
        on_pushButton_del_clicked();
        break;
    case Qt::Key_Plus:
        on_pushButton_plus_clicked();
        break;
    case Qt::Key_ParenLeft:
        on_pushButton_left_clicked();
        break;
    case Qt::Key_ParenRight:
        on_pushButton_right_clicked();
        break;
    case Qt::Key_Asterisk:
        on_pushButton_mul_clicked();
        break;
    case Qt::Key_Minus:
        on_pushButton_minus_clicked();
        break;
    case Qt::Key_Slash:
        on_pushButton_div_clicked();
        break;
    case Qt::Key_Period:
        on_pushButton_point_clicked();
        break;
    case Qt::Key_I:
        on_pushButton_imag_clicked();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Equal:
        on_pushButton_ans_clicked();
        break;
    case Qt::Key_AsciiCircum:
        on_pushButton_pow_clicked();
        break;
    default:
        break;
    }
}

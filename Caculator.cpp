#include "Caculator.h"
#include "ui_caculator.h"
#include "BinNode.h"
#include "BinTree.h"
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

//去掉空格
void trim(string &s)
{
    int index = 0;
    if( !s.empty() )
        while( (index = s.find('\n',index)) != string::npos || (index = s.find(' ',index)) != string::npos)
            s.erase(index,1);
}

Caculator::Caculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Caculator)
{
    ui->setupUi(this);
    ui->expression->setText(text);
    ui->answer->setText(text);
    ui->expression->setFocusPolicy(Qt::NoFocus);
}

Caculator::~Caculator()
{
    delete ui;
}

void Caculator::on_pushButton9_clicked()
{
    text += "9";
    ui->expression->setText(text);
}

void Caculator::on_pushButton8_clicked()
{
    text +="8";
    ui->expression->setText(text);
}

void Caculator::on_pushButton7_clicked()
{
    text +="7";
    ui->expression->setText(text);
}

void Caculator::on_pushButton6_clicked()
{
    text += "6";
    ui->expression->setText(text);
}

void Caculator::on_pushButton5_clicked()
{
    text +="5";
    ui->expression->setText(text);
}

void Caculator::on_pushButton4_clicked()
{
    text += "4";
    ui->expression->setText(text);
}

void Caculator::on_pushButton3_clicked()
{
    text += "3";
    ui->expression->setText(text);
}

void Caculator::on_pushButton2_clicked()
{
    text += "2";
    ui->expression->setText(text);
}

void Caculator::on_pushButton1_clicked()
{
    text += "1";
    ui->expression->setText(text);
}

void Caculator::on_pushButton0_clicked()
{
    text += "0";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_ans_clicked()
{
    BinTree ExprTree;
    QString Qexpr = ui->expression->text();
    string expr = Qexpr.toStdString();
    trim(expr);
    try {
            ExprTree.ChangeToBitTree(expr);
    } catch(string wrong) {
        text = QString::fromStdString(wrong);
        ui->statusbar->setStyleSheet("background-color:#d56b67;");
        ui->statusbar->showMessage(text);
        text = "";
        return;
    }
    string buffer;
    ExprTree.postOrderTreeWalk(buffer);
    buffer = ExprTree.Calculate().Show();
    text = QString::fromStdString(buffer);
    ui->answer->setText(text);
    ui->statusbar->setStyleSheet("background-color:#66ff66;");
    ui->statusbar->showMessage("done");
    text = QString::fromStdString(expr);
}

void Caculator::on_pushButton_imag_clicked()
{
    text += "i";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_pow_clicked()
{
    text += "^";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_del_clicked()
{
    text.remove(text.length() - 1, 1);
    ui->expression->setText(text);
}

void Caculator::on_pushButton_ac_clicked()
{
    text.clear();
    ui->expression->setText(text);
    ui->answer->setText(text);
}

void Caculator::on_pushButton_plus_clicked()
{
    text += "+";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_div_clicked()
{
    text += "/";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_mul_clicked()
{
    text += "*";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_minus_clicked()
{
    text += "-";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_left_clicked()
{
    text += "(";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_right_clicked()
{
    text += ")";
    ui->expression->setText(text);
}

void Caculator::on_pushButton_point_clicked()
{
    text += ".";
    ui->expression->setText(text);
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
    case Qt::Key_Return:
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

void Caculator::on_pushButton_imag_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "选择要导入的文件", "/");
    if(fileName == NULL)
        return;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, QString("Read File"),
                             QString("Cannot open file:\n%1").arg(fileName));
        return;
    }else
    {
        QMessageBox::warning(this, QString("Path"),
                             QString("You did not select any file."));
    }
    while(!file.atEnd()) {
        QString line = file.readLine();
        ui->expression->setText(line);
    }
    file.close();
}

void Caculator::on_pushButton_ac_2_clicked()
{
    int ran_num, i = 0, n = 0;
       int flag[12];
       char ch[4] = {'+', '-', '*', '/'};
       string str;

       memset(flag, 2, sizeof(flag));
       srand((unsigned)time(0));
       for(int j=0; j < (rand()%8)+2; j++)
       {
           if(rand()%2)
           {
               str += '(';
               flag[i++] = 0;
               if(rand()%2)
                   str += '-';
           }
           for(int k=0; k < (rand()%3)+1; k++)
           {
               ran_num = rand()%10;
               if(ran_num == 0 && k == 0) ran_num = 1;
               str += ran_num + '0';
           }
           if(rand()%2)
               str += 'i';
           if(rand()%2 && flag[n] == 0)
           {
               str += ')';
               flag[n++] = 1;
           }
           str += ch[rand()%3];
       }
       if(flag[n++] == 0)
           *(str.end()-1) = ')';
       else
           *(str.end()-1) = '\n';
       while(flag[n++] == 0)
           str += ')';
       QString a=QString::fromStdString(str);
       ui->expression->setText(a);
}

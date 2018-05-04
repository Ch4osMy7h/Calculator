#include <iostream>
#include "BinNode.h"
#include "BinTree.h"
#include "Calculator.h"
#include <QApplication>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication window(argc, argv);
    Calculator calc;
    calc.show();
    /*
    string str;
    while(cin >> str) {
        BinTree ExprTree;
        ExprTree.ChangeToBitTree(str);
        string buffer;
        ExprTree.postOrderTreeWalk(buffer);
        cout << buffer << endl;
        cout << ExprTree.Calculate().Show() << endl;
    }*/
    return window.exec();
}

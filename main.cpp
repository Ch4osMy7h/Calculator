#include <iostream>
#include "BinNode.h"
#include "BinTree.h"


using namespace std;

int main(void) {
    string str;
    while(cin >> str) {
        BinTree ExprTree;
        ExprTree.ChangeToBitTree(str);
        string buffer;
        ExprTree.postOrderTreeWalk(buffer);
        cout << buffer << endl;
        cout << ExprTree.Calculate().Show() << endl;
    }
    return 0;
}
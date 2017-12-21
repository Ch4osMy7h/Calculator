//
// Created by chaosmyth on 12/12/2017.
//

#ifndef CALCULATOR_BINTREE_H
#define CALCULATOR_BINTREE_H

#include "BinNode.h"
#include <string>

using namespace std;

enum Status {OK, NOR, ERROR, OVER};


class BinNode;

class BinTree {
private:
    BinNode *root;
public:
    BinTree() {
        root = NULL;
    }
    ~BinTree() {
        Destroy(root);
        root = nullptr;
    }
    //销毁节点
    void Destroy(BinNode *node);
    Status ChangeToBitTree(string &str);
    Complex Calculate();
    //得到后缀表达式
    void postOrderTreeWalk(string& buffer);
};



#endif //CALCULATOR_BINTREE_H

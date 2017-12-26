//
// Created by chaosmyth on 12/12/2017.
//

#ifndef CALCULATOR_BINNODE_H
#define CALCULATOR_BINNODE_H

#include <iostream>
#include "Complex.h"
#include "BinTree.h"

#include "Expression.h"

using std::string;




class BinNode {
public:
    bool isComplex; //判断该节点是否为复数，如果是复数则为true,否则值为假, 并且用来存放运算符
    Complex data;
    BinNode *lchild, *rchild;
    BinNode()
            : lchild(nullptr), rchild(nullptr), isComplex(true), data(0,0) {}
    Complex Calculate(BinNode* root);
    void postOrderTreeWalk(BinNode* root, string& buffer);
    BinNode* ChangeToBitTree(string &str);

    void postorder(BinNode *node) {
        if(lchild != NULL) {
            postorder(node->lchild);
        }
        if(rchild != NULL) {
            postorder(node->rchild);
        }
        cout << node->data.Show() << endl;
    }
};

using PtrToBinNode = BinNode*;





#endif //CALCULATOR_BINNODE_H

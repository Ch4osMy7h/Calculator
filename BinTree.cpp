//
// Created by chaosmyth on 12/12/2017.
//

#include "BinTree.h"
#include "Expression.h"


void BinTree::Destroy(BinNode *node) {
    if(node == nullptr) {
        return ;
    }
    Destroy(node->lchild);
    Destroy(node->rchild);
    delete node;
}

Complex BinTree::Calculate() {
    return root->Calculate(root);
}

void BinTree::postOrderTreeWalk(string &str) {
    root->postOrderTreeWalk(root, str);
}

Status BinTree::ChangeToBitTree(string &str) {
    root = root->ChangeToBitTree(str);
}

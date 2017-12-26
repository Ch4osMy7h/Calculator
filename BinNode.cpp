//
// Created by chaosmyth on 12/12/2017.
//

#include "BinNode.h"
#include "Stack.h"
#include "Expression.h"
#include <string>
#include <cmath>

class Expression;



BinNode* BinNode::ChangeToBitTree(string &str) {
    Stack<PtrToBinNode > ExprStack;
    BinNode* ExprNode;
    Stack<char> OptrStack;
    int flag; //标记
    PtrToBinNode *pt;
    double i, j, num;
    auto StrBegin = str.begin();
    //std::cout << "转化后的字符串为:";
    int CTOPTR; //存储Optr转化成对应数字
    for(int i = 0, flag = 0; i < str.size(); ++i, flag = 0) {
        //除数不能为
        if(*(StrBegin + i) == '0' && *(StrBegin + i - 1) == '/') {
            throw ExpreesionError::DIVISION_ERROR;
        }
        //判断是否为负数
        if(*(StrBegin + i) == '-' && (i == 0 || *(StrBegin+i-1) == '(')) {
            flag = 1;
            ++i;
        }
        if(*(StrBegin + i) == 'i' || isdigit(* (StrBegin + i))) {
            //将字符串中的数字(包括多位数字)转换为整形
            if (isdigit(*(StrBegin + i))) {
                for (j = i + 1, num = *(StrBegin + i) - '0'; isdigit(*(StrBegin + j)); ++j) {
                    num = num * 10 + ((*(StrBegin + j)) - '0');
                }
                //跳到第一个不是数字的位置
                i = j;
                //如果有小数点就计算浮点数
                double float_num = 0;
                if(*(StrBegin+i) == '.') {
                    i++;
                    for (j = i + 1, float_num = (*(StrBegin + i) - '0') * pow(10, -1); isdigit(*(StrBegin + j)); ++j) {
                        float_num += ((*(StrBegin + j)) - '0') * pow(10,  -(j - i + 1));
                    }
                    num += float_num;
                    i = j;
                }
            } else {
                num = 1;
            }
            if (flag) num = -num; //判断正负号
            ExprNode = new BinNode();
            //非数字部分出现虚数单位i
            if (*(StrBegin + i) == 'i') {
                (ExprNode->data).setImag(num);
                //跳过这个符号
                ++i;
                num = 0;
                (ExprNode->data).setReal(num);
            } else {
                (ExprNode->data).setReal(num);
                num = 0;
                (ExprNode->data).setImag(num);
            }
            ExprNode->isComplex = true;
            ExprNode->lchild = nullptr;
            ExprNode->rchild = nullptr;
            ExprStack.push(ExprNode);
        }
        if(i == str.size()) break;
        if(!Expression::isOperator(StrBegin + i) && !isdigit(*(StrBegin +i))) {
            throw ExpreesionError::ILLEGAL_CHARACTER_ERROR;
        }
        //如果是操作符
        if(!(OptrStack.empty())) {
            if(*(StrBegin + i) == '(') {
                OptrStack.push(*(StrBegin + i));
            }
            else if(*(StrBegin + i) == ')') {
                while((OptrStack.top() != '(')) {
                    if(!(OptrStack.empty()) && ExprStack.size() >= 2) {
                        ExprNode = new BinNode();
                        ExprNode->isComplex = false;
                        CTOPTR = Expression::StringToOperator(OptrStack.top());
                        (ExprNode->data).setReal(CTOPTR); OptrStack.pop();
                        ExprNode->rchild = ExprStack.top(); ExprStack.pop();
                        ExprNode->lchild = ExprStack.top(); ExprStack.pop();
                        ExprStack.push(ExprNode);
                    } else {
                        throw ExpreesionError::ILLEGAL_BRACKET_ERROR;
                    }
                }
                OptrStack.pop();
            } else {
                switch(Expression::orderBetween(OptrStack.top(), *(StrBegin+i))){
                    //优先级比栈顶元素大
                    case '<':
                        OptrStack.push(*(StrBegin + i));
                        break;
                        //优先级比栈顶元素小于等于
                    case '=':
                        OptrStack.pop();
                        break;
                    default:
                        if(!OptrStack.empty() && ExprStack.size() >= 2) {
                                ExprNode = new BinNode();
                                ExprNode->isComplex = false;
                                CTOPTR = Expression::StringToOperator(OptrStack.top());
                                (ExprNode->data).setReal(CTOPTR);  OptrStack.pop();
                                ExprNode->rchild = ExprStack.top(); ExprStack.pop();
                                ExprNode->lchild = ExprStack.top(); ExprStack.pop();
                                ExprStack.push(ExprNode);
                        } else {
                            //计算的数不够
                            throw ExpreesionError::MISSING_OPERAND_ERROR;
                        }
                        OptrStack.push(*(StrBegin + i));
                        break;
                }
            }
            //如果栈为空
        } else {
            OptrStack.push(*(StrBegin+i));
        }
    }
    while(!(OptrStack.empty()) && ExprStack.size() >= 2) {
        ExprNode = new BinNode();
        ExprNode->isComplex = false;
        CTOPTR = Expression::StringToOperator(OptrStack.top());
        (ExprNode->data).setReal(CTOPTR);
        OptrStack.pop();
        ExprNode->rchild = ExprStack.top(); ExprStack.pop();
        ExprNode->lchild = ExprStack.top(); ExprStack.pop();
        ExprStack.push(ExprNode);
    }
    //如果ExprStack中有两个元素以上， 或者OptrStack仍不为空， 则表达式错误
    if(!(OptrStack.empty()) || ExprStack.size() >= 2) {
        throw ExpreesionError::MISSING_EXPRESSION_ERROR;
    }
    return ExprStack.top();
}

//得到后缀表达式
void BinNode::postOrderTreeWalk(BinNode *root,string &str) {
    if (root->lchild != nullptr) {
        postOrderTreeWalk(root->lchild, str);
    }
    if (root->rchild != nullptr) {
        postOrderTreeWalk(root->rchild, str);
    }
    if (!root->lchild && !root->rchild) {
        str = str + root->data.Show();
    } else {
        switch ((int)(root->data).getReal()) {
            case ADD:
                str = str + "+ ";
                break;
            case SUB:
                str = str + "- ";
                break;
            case MUL:
                str = str + "* ";
                break;
            case DIV:
                str = str + "/ ";
                break;
            case POW:
                str = str + "^ ";
                break;
            default:
                break;
        }
    }
}

Complex BinNode::Calculate(BinNode* root) {
    Complex lvalue, rvalue;
    if(!root->lchild && !root->rchild && root->isComplex) {
        return root->data;
    } else {
        lvalue = BinNode::Calculate(root->lchild);
        rvalue = BinNode::Calculate(root->rchild);
        switch((int)(root->data).getReal()) {
            case ADD:
                lvalue = lvalue + rvalue;
                break;
            case SUB:
                lvalue = lvalue - rvalue;
                break;
            case DIV:
                lvalue = lvalue / rvalue;
                break;
            case MUL:
                lvalue = lvalue * rvalue;
                break;
            case POW:
                lvalue = lvalue.pow(rvalue.getReal());
                break;
            default:break;
        }
    }
    return lvalue;
}

//
// Created by chaosmyth on 15/12/2017.
//

#include "Expression.h"


bool Expression::isOperator(string::iterator it) {
    bool tag;
    switch (*it)
    {
        case '+' :
        case '-' :
        case '*' :
        case '/' :
        case '^' :
        case '!' :
        case '(' :
        case ')' :
            tag = true;
            break;
        default:
            tag = false;
            break;
    }
    return tag;
}

Operator Expression::StringToOperator(char op) {
    switch ( op ) {
        case '+' : return ADD; //加
        case '-' : return SUB; //减
        case '*' : return MUL; //乘
        case '/' : return DIV; //除
        case '^' : return POW; //乘方
        case '!' : return FAC; //阶乘
        case '(' : return L_P; //左括号
        case ')' : return R_P; //右括号
        case '\0': return EOE; //起始符与终止符
        default  : exit ( -1 ); //未知运算符
    }
}

char Expression::orderBetween ( char op1, char op2 ) //比较两个运算符之间的优先级
{return pri[Expression::StringToOperator( op1 ) ][Expression::StringToOperator( op2 ) ];}

//
// Created by chaosmyth on 15/12/2017.
//

#ifndef CALCULATOR_EXPRESSION_H
#define CALCULATOR_EXPRESSION_H


#include <string>
#include "BinNode.h"

using namespace std;

enum TAG{IsLarger, IsSmaller, IsSame};


#define N_OPTR 9 //运算符总数
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //运算符集合
//加、减、乘、除、乘方、阶乘、左括号、右括号、起始符与终止符

const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [当前]
        /*              |-------------------- 当 前 运 算 符 --------------------| */
        /*              +      -      *      /      ^      !      (      )      \0 */
        /* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
        /* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
        /* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
        /* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
        /* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
        /* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
        /* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
        /* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
        /* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};


namespace ExpreesionError {
    //未知异常
    const string UNKNOWN_ERROR = "未知错误";
    //除数不能为0
    const string DIVISION_ERROR = "除数不能为0";
    //非法字符
    const string ILLEGAL_CHARACTER_ERROR = "非法字符: ";
    //括号不匹配
    const string ILLEGAL_BRACKET_ERROR = "括号不匹配";
    //缺失操作数
    const string MISSING_OPERAND_ERROR = "缺少操作数";
    //表达式错误
    const string MISSING_EXPRESSION_ERROR = "表达式错误";
    //不能对复数求阶乘
    const string CANT_COMPLEX_FACTORIAL = "不能对复数求阶乘";
}


class Expression {
public:
    static bool isOperator(string::iterator it);
    static char orderBetween ( char op1, char op2 );
    static Operator StringToOperator(char ch);
};


#endif //CALCULATOR_EXPRESSION_H

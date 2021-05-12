/*
* Заголовочный файл с описанием классов и их методов для дифференцирования функций
*/

#include <cmath>
#include <iostream>
#include <stdlib.h>

#pragma once
 
// Этот класс наследуют все последующие
class Expression
{
public:
    virtual Expression* dif() = 0;
    virtual void print() = 0;
};

// Для хранения чисел
class Number : public Expression
{
public:
    double num;

    Number(double n) : num(n) {}
    Expression* dif();
    void print();
};

// Для хранения переменных
class Variable : public Expression
{
    char x;
public:
    Variable(char c): x(c) {}
    Expression* dif();
    void print();
};

// Производная суммы
class Add : public Expression
{
    Expression* e1, * e2;
public:
    Add(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// Разности
class Sub : public Expression
{
    Expression* e1, * e2;
public:
    Sub(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// Произведения
class Mul : public Expression
{
    Expression* e1, * e2;
public:
    Mul(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// Частного
class Div : public Expression
{
    Expression* e1, * e2;
public:
    Div(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// Производная степенной функции
class Pow : public Expression
{
    Expression* e;
    Number* n;
public:
    Pow(Expression* a1, Number* a2) : e(a1), n(a2) {}
    Expression* dif();
    void print();
};

// Производная cинуса
class Sin : public Expression
{
    Expression* e;
public:
    Sin(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};

// Производная косинуса
class Cos : public Expression
{
    Expression* e;
public:
    Cos(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};

// Производная экспоненты (через неё же можем выразить любую показательную функцию)
class Exp : public Expression
{
    Expression* e;
public:
    Exp(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};

// Производная натурального логарифма (через него выражается логарифм по любому основанию)
class Ln : public Expression
{
    Expression* e;
public:
    Ln(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};
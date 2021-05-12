/*
* ������������ ���� � ��������� ������� � �� ������� ��� ����������������� �������
*/

#include <cmath>
#include <iostream>
#include <stdlib.h>

#pragma once
 
// ���� ����� ��������� ��� �����������
class Expression
{
public:
    virtual Expression* dif() = 0;
    virtual void print() = 0;
};

// ��� �������� �����
class Number : public Expression
{
public:
    double num;

    Number(double n) : num(n) {}
    Expression* dif();
    void print();
};

// ��� �������� ����������
class Variable : public Expression
{
    char x;
public:
    Variable(char c): x(c) {}
    Expression* dif();
    void print();
};

// ����������� �����
class Add : public Expression
{
    Expression* e1, * e2;
public:
    Add(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// ��������
class Sub : public Expression
{
    Expression* e1, * e2;
public:
    Sub(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// ������������
class Mul : public Expression
{
    Expression* e1, * e2;
public:
    Mul(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// ��������
class Div : public Expression
{
    Expression* e1, * e2;
public:
    Div(Expression* a1, Expression* a2) : e1(a1), e2(a2) {}
    Expression* dif();
    void print();
};

// ����������� ��������� �������
class Pow : public Expression
{
    Expression* e;
    Number* n;
public:
    Pow(Expression* a1, Number* a2) : e(a1), n(a2) {}
    Expression* dif();
    void print();
};

// ����������� c�����
class Sin : public Expression
{
    Expression* e;
public:
    Sin(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};

// ����������� ��������
class Cos : public Expression
{
    Expression* e;
public:
    Cos(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};

// ����������� ���������� (����� �� �� ����� �������� ����� ������������� �������)
class Exp : public Expression
{
    Expression* e;
public:
    Exp(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};

// ����������� ������������ ��������� (����� ���� ���������� �������� �� ������ ���������)
class Ln : public Expression
{
    Expression* e;
public:
    Ln(Expression* a) : e(a) {}
    Expression* dif();
    void print();
};
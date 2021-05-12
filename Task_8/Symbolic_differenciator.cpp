/*
*  Реализация методов из классов, описанных в Symbolic_differenciator.h
*/

#include <cmath>
#include <iostream>
#include "Parcer.h"
#include <stdlib.h>
#include "Symbolic_differenciator.h"


Expression* Number::dif()
{
    return new Number(0);
}
void Number::print()
{
    std::cout << num;
}

Expression* Variable::dif()
{
    return new Number(1);
}
void Variable::print()
{
    std::cout << x;
}

Expression* Add::dif()
{
    return new Add(e1->dif(), e2->dif());
}
void Add::print()
{
    std::cout << "(";
    e1->print();
    std::cout << "+";
    e2->print();
    std::cout << ")";
}

Expression* Mul::dif()
{
    return new Add(new Mul(e1->dif(), e2), new Mul(e1, e2->dif()));
}
void Mul::print()
{
    std::cout << "(";
    e1->print();
    std::cout << "*";
    e2->print();
    std::cout << ")";
}

Expression* Sub::dif()
{
    return new Sub(e1->dif(), e2->dif());
}
void Sub::print()
{
    std::cout << "(";
    e1->print();
    std::cout << "-";
    e2->print();
    std::cout << ")";
}

Expression* Div::dif()
{
    return new Div(new Sub(new Mul(e1->dif(), e2), new Mul(e1, e2->dif())), new Mul(e2, e2));
}
void Div::print()
{
    std::cout << "(";
    e1->print();
    std::cout << ")";
    std::cout << "/";
    std::cout << "(";
    e2->print();
    std::cout << ")";
}

Expression* Pow::dif()
{
    double k = n->num - 1;
    return new Mul(new Mul(n, new Pow(e, new Number(k))), e->dif());
}
void Pow::print()
{
    std::cout << "(";
    e->print();
    std::cout << ")";
    std::cout << "^";
    std::cout << "(";
    n->print();
    std::cout << ")";
}

Expression* Sin::dif()
{
    return new Mul(new Cos(e), e->dif());
}
void Sin::print()
{
    std::cout << "sin(";
        e->print();
        std::cout << ')';
}

Expression* Cos::dif()
{
    return new Mul(new Sub(new Number(0), new Sin(e)), e->dif());
}
void Cos::print()
{
    std::cout << "cos(";
    e->print();
    std::cout << ')';
}

Expression* Exp::dif()
{
    return new Mul(new Exp(e), e->dif());
}
void Exp::print()
{
    std::cout << "exp(";
    e->print();
    std::cout << ')';
}

Expression* Ln::dif()
{
    return new Div(e->dif(), e);
}
void Ln::print()
{
    std::cout << "ln(";
    e->print();
    std::cout << ')';
}
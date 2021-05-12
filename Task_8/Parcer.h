#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

/*
*  Реализация методов из классов, описанных в Parser.h
*/
#pragma once

class Formula
{
public:
    virtual void print() = 0;
    virtual void parse() = 0;
};

class Term : public Formula
{
    std::string val;
public:
    Term(std::string v) : val(v) {}
    void print();
    void parse();
};

class Node : public Formula
{
    Formula* left;
    Formula* right;
    char op; // +, -, *, /, ^
public:
    Node(char op, Formula* left, Formula* right) :op(op), left(left), right(right) {}
    void print();
    void parse();
};

Formula* str_to_exrp(std::string& str);
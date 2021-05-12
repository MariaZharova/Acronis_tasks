/*
* Заголовочный файл с описанием классов и их методов для парсинга входных (и в будущем выходных...) данных
*/

#include "Parcer.h"
#define ERROR_INVALID_INPUT NULL

void Term::print()
{
    std::cout << ' ' << val << ' ';
}
void Term::parse()
{
}

void Node::print()
{
    std::cout << '(' << op << ' ';
    left->print();
    right->print();
    std::cout << ')';
}
void Node::parse()
{
    left->parse();
    right->parse();
    delete left;
    delete right;
}

Formula* str_to_exrp(std::string& str)
{
    int counter = 0;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        // подсчёт откр. и закр. скобок
        char c = str[i];
        if (c == ')')
        {
            ++counter;
            continue;
        }
        if (c == '(')
        {
            --counter;
            continue;
        }
        if (counter > 0)
        {
            continue;
        }
        // переход в поддеревья по операциям
        if (((c == '+' || c == '-') && i != 0) || (c == '*' || c == '/' || c == '^'))
        {
            std::string left(str.substr(0, i));
            std::string right(str.substr(i + 1));
            return new Node(c, str_to_exrp(left), str_to_exrp(right));
        }
    }

    if (str[0] == '(')
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '(')
            {
                ++counter;
                continue;
            }
            if (str[i] == ')')
            {
                --counter;
                if (counter == 0)
                {
                    std::string exp(str.substr(1, i - 1));
                    return str_to_exrp(exp);
                }
                continue;
            }
        }
    }
    else
    {
        return new Term(str);
    }
    std::cout << "Error" << std::endl;
    return ERROR_INVALID_INPUT;
}
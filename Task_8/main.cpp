#include "Symbolic_differenciator.h"
//#include "Parcer.h"

int main()
{
    //Expression* test = new Exp(new Mul(new Ln(new Number(3)), new Variable('x')));
    Expression* test = new Add(new Pow(new Variable('x'), new Number(3)), new Exp(new Mul(new Number(3), new Variable('x'))));
    // test = x ^ 3 + exp(3 * x)
    test->print();
    std::cout << std::endl;
    Expression* dif_test = test->dif();
    dif_test->print();
    delete test;
    delete dif_test;

    return 0;
}


/*
* Часть кода для тестирования разбора формулы
int main()
{
    std::string expr(" (a * b)^c / (d + e - f)");
    expr.erase(remove_if(expr.begin(), expr.end(), ::isspace), expr.end());
    Formula* ftree = str_to_exrp(expr);
    ftree->print();
    ftree->parse();
    delete ftree;
}*/

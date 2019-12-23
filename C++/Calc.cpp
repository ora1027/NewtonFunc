#include <iostream>
#include <cmath> // pow

#include "Calc.h"

Calc::Calc()
    : x_new_()
{}

double Calc::operator()(std::function<double(double)>f, std::function<double(double)>df, double x0, int max_iter, double epc)
{
    double x = x0;
    int iter = 0;
    while(1)
    {
        x_new_ = x - f(x)/df(x);
        if (std::abs(x - x_new_) < epc)
        {
            break;
        }
        x = x_new_;
        iter ++;
        if (iter == max_iter)
        {
            break;
        }
    }
    return x_new_;
}

#include <iostream>
#include <cmath> // pow

#include "Calc.h"

const int Calc::MAX_ITER = 1000;
const double Calc::EPC = 1e-10;


double fx(double x)
{
    return std::pow(x, 3.0) - 5 * x + 1;
}

double df(double x)
{
    return 3 * std::pow(x, 2) - 5;
}

double Newton_Main(std::function<double(double)>f, std::function<double(double)>df, double x0, int max_iter, double epc)
{
    double x_new = 0;
    double x = x0;
    int iter = 0;
    while(1)
    {
        x_new = x - f(x)/df(x);
        if (std::abs(x - x_new) < epc)
        {
            break;
        }
        x = x_new;
        iter ++;
        if (iter == max_iter)
        {
            break;
        }
    }
    return x_new;
}

int main()
{
    Calc calc;
    std::function<double(std::function<double(double)>,
                         std::function<double(double)>,
                         double,
                         int,
                         double)> newton = calc;

    std::cout << "Newton Object : " <<newton(fx, df, 2, Calc::MAX_ITER, Calc::EPC) << std::endl;
    std::cout << "Newton Object : " <<newton(fx, df, 0, Calc::MAX_ITER, Calc::EPC) << std::endl;
    std::cout << "Newton Object : " <<newton(fx, df, 3, Calc::MAX_ITER, Calc::EPC) << std::endl;

    std::function<double(std::function<double(double)>,
                         std::function<double(double)>,
                         double,
                         int,
                         double)> newton_ptr = Newton_Main;

    std::cout << "Newton Ptr : " << newton_ptr(fx, df, 2, Calc::MAX_ITER, Calc::EPC) << std::endl;
    std::cout << "Newton Ptr : " << newton_ptr(fx, df, 0, Calc::MAX_ITER, Calc::EPC) << std::endl;
    std::cout << "Newton Ptr : " << newton_ptr(fx, df, 3, Calc::MAX_ITER, Calc::EPC) << std::endl;

    // std::function<double(std::function<double(double)>,
    //                      std::function<double(double)>,
    //                      double,
    //                      int,
    //                      double)> newton_lamda = [](std::function<double(double)>f,
    //                                                 std::function<double(double)>df,
    //                                                 double x0)
    //                                                 {
    //                                                     double x_new = 0;
    //                                                     double x = x0;
    //                                                     int iter = 0;
    //                                                     while(1)
    //                                                     {
    //                                                         x_new = x - f(x)/df(x);
    //                                                         if (std::abs(x - x_new) < Calc::EPC)
    //                                                         {
    //                                                             break;
    //                                                         }
    //                                                         x = x_new;
    //                                                         iter ++;
    //                                                         if (iter == Calc::MAX_ITER)
    //                                                         {
    //                                                             break;
    //                                                         }
    //                                                     }
    //                                                     return x_new;
    //                                                 };

    // newton_lamda(fx, df, 2, Calc::MAX_ITER, Calc::EPC);
    // newton_lamda(fx, df, 0, Calc::MAX_ITER, Calc::EPC);
    // newton_lamda(fx, df, 3, Calc::MAX_ITER, Calc::EPC);

    return 0;
}

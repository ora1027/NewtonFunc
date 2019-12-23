#include <functional>

class Calc
{
public:
    Calc();

    double operator()(std::function<double(double)>f, std::function<double(double)>df, double x0, int max_iter, double epc);
    double Newton(std::function<double(double)>f, std::function<double(double)>df, double x0, int max_iter, double epc);

    static const int MAX_ITER;
    static const double EPC;

private:
    double x_new_;
};

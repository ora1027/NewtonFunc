import calc


def f(x):
    return x**3 - 5*x + 1

def df(x):
    return 3*x**2 - 5

def main():
    formula = calc.Calc()
    newton = formula.newton_func(f, df)
    print(newton(2))
    print(newton(0))
    print(newton(3))


if __name__ == '__main__':
    main()

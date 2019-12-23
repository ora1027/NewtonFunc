class Calc:
    def __init__(self):
        self.eps = 1e-10
        self.max_iter = 1000

    def newton_func(self, f, df):
        def newton(x0):
            x = x0
            iter = 0
            while True:
                x_new = x - f(x)/df(x)
                if abs(x-x_new) < self.eps:
                    break
                x = x_new
                iter += 1
                if iter == self.max_iter:
                    break
            return x_new
        return newton

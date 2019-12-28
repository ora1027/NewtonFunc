package main

import (
	"fmt"
	"math"
)

// Calc Newton Calculaion struct
type Calc struct{}

// fx f(x) formula
func (calc Calc) fx(x float64) float64 {
	return x*x*x - 5*x + 1
}

// df differentiated f(x)
func (calc Calc) df(x float64) float64 {
	return 3*x*x - 5
}

// Newton_main Calculation for Newton method
func (calc Calc) Newton_main(fx func(float64) float64, df func(float64) float64, x0 float64, maxIter int, epc float64) float64 {
	var xNew float64
	var x = x0
	var iter int
	for {
		xNew = x - fx(x)/df(x)
		if math.Abs(x-xNew) < epc {
			break
		}
		x = xNew
		iter++
		if iter == maxIter {
			break
		}
	}
	return xNew
}

func main() {
	calc := Calc{}

	var ans float64

	ans = calc.Newton_main(calc.fx, calc.df, 2, 1000, 1e-10)
	fmt.Println("The answer is : ", ans)

	ans = calc.Newton_main(calc.fx, calc.df, 0, 1000, 1e-10)
	fmt.Println("The answer is : ", ans)

	ans = calc.Newton_main(calc.fx, calc.df, 3, 1000, 1e-10)
	fmt.Println("The answer is : ", ans)
}

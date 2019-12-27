package main

import (
	"fmt"
	"math"
)

// Calc Newton Calculaion struct
type Calc struct {
	x float64
}

// fx f(x) formula
func (calc Calc) fx() float64 {
	return calc.x*calc.x*calc.x - 5*calc.x + 1
}

// df differentiated f(x)
func (calc Calc) df() float64 {
	return 3*calc.x*calc.x - 5
}

// Newton_main Calculation for Newton method
func (calc Calc) Newton_main(fx func(), df func(), x0 float64, maxIter int, epc float64) float64 {
	var xNew float64
	var x = x0
	var iter int
	for {
		xNew = x - fx()/df()
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
	calc.x = 5.0

	var y float64

	y = calc.fx()
	fmt.Println("The result of fx(5.0) : ", y)

	y = calc.df()
	fmt.Println("The result of dx(5.0) : ", y)

	// fx, dfを関数オブジェクトを返す関数に変更する必要がある。
	// var fx func()
	// var df func()
	// fx = calc.fx
	// df = calc.df

	// var ans float64
	// ans = calc.Newton_main(calc.fx, calc.df, 2, 1000, 1e-10)
}

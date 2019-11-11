#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

//f() = sin(x), cos(x), ln(1+x) define as ln_1(), arctg(x), sh(x), ch(x);

int main()
{
	double x, eps = 0.00001;
	cin >> x;
	double res = sin(x,eps);
	int a = res / eps;
	res = a * eps;
	cout << res;
	return 0;
}


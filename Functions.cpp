#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

double common(double x, double xFirst, double (*f)(double, int), double eps)
{
	double res1 = 0, res2 = 0;;
	int n = 1;
	double x1 = xFirst;
	do
	{
		res1 = res2;
		res2 = res1 + x1;
		x1 *= f(x, n);
		n++;
	} while (abs(res2 - res1) >= eps);
	return res2;
}

double arctgInternal(double x, int n) {
	return x * x * (-1) * ((2 * n) - 1) / ((2 * n) + 1);
}

double arctg(double x, double eps)
{
	return common(x, x, arctgInternal, eps);
}


double ln_1Internal(double x, int n) {
	return (-1) * x * n / (n + 1);
}

double ln_1(double x, double eps)
{
	return common(x, 1, ln_1Internal, eps);
}


double cosInternal(double x, int n) {
	return (-1) * x * x / ((2 * n - 1) * (2 * n));
}

double cos(double x, double eps)
{
	return common(x, 1, cosInternal, eps);
}


double sinInternal(double x, int n) {
	return (-1) * x * x / ((2 * n + 1) * (2 * n));
}

double sin(double x, double eps)
{
	return common(x, x, sinInternal, eps);
}


double shInternal(double x, int n) {
	return x * x / ((2 * n + 1) * (2 * n));
}

double sh(double x, double eps)
{
	return common(x, x, shInternal, eps);
}


double chInternal(double x, int n) {
	return x * x / ((2 * n - 1) * (2 * n));
}

double ch(double x, double eps)
{
	return common(x, 1, chInternal, eps);
}
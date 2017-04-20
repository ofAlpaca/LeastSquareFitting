// 演算法分析機測
// 學號: 10327111 / 10327216 / 10327219
// 姓名: 李京展 / 林函緯 / 江紹賢

#include <stdio.h>
#include <iostream>

using namespace std;

bool LeastSquareFit() {
	int np = 0;
	// How many points do we have?
	cin >> np;
	if (np == 0)
		return false; // quit the program

	// Input all points
	double * x = (double*)malloc(sizeof(double)*np);
	double * y = (double*)malloc(sizeof(double)*np);
	for (int i = 0; i < np; i++)
		cin >> x[i] >> y[i];

	// Caculate x and y means
	double x_mean = 0, y_mean = 0;
	for (int s = 0; s < np; s++) {
		x_mean += x[s];
		y_mean += y[s];
	}
	x_mean /= np;
	y_mean /= np;

	// Caculate the Var of x,y and x,y means 
	double * xminx_mean = (double*)malloc(sizeof(double)*np);
	double * yminy_mean = (double*)malloc(sizeof(double)*np);
	for (int k = 0; k < np; k++) {
		xminx_mean[k] = x[k] - x_mean;
		yminy_mean[k] = y[k] - y_mean;
	}

	// Add every square of x-xmean and add mulitplied x-xmean and y-ymean
	double SqOf_xminx_mean = 0, Mul_xy = 0;
	for (int m = 0; m < np; m++) {
		SqOf_xminx_mean += xminx_mean[m] * xminx_mean[m];
		Mul_xy += xminx_mean[m] * yminy_mean[m];
	}

	// Caculate a and b through formula
	// a = sigma((x-xmean)*(y-ymean)) / sigma((x-xmean)^2)
	// b = y_mean - a * x_mean
	double a, b;
	if (SqOf_xminx_mean == 0)
		throw overflow_error("There is no SLOPE in these point set !\n");
	a = Mul_xy / SqOf_xminx_mean;
	b = y_mean - (a * x_mean);
	cout << "a = " << a << ", b = " << b << endl;

	// Properly finished the program
	return true;
}
int main()
{
	try {
		while (true) {
			if (!LeastSquareFit())
				break;
		}
	}
	catch (overflow_error  e) {
		cout << e.what() << endl;
	}

	system("pause");
}

// 求下面方程的一个根：f(x) = x3-5x2+10x-80 = 0
// 若求出的根是a，则要求|f(a)| <= 10-6
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std ;

const double EPS = 1e-6 ;
inline double fun(double x)
{
	return x*x*x - 5*x*x + 10*x - 80 ;
}

int main()
{
	double root, x1 = 0, x2 = 100, y ;
	root = x1 + (x2-x1)/2.0 ;
	int triedTimes = 1 ; //记录一共尝试多少次，对求根来说不是必须的
	y = fun(root) ;
	while (fabs(y) > EPS)
	{
		if (y > 0) 
			x2 = root ;
		else
			x1 = root ;
		root = x1 + (x2-x1)/2.0 ;
		y = fun(root) ;
		++triedTimes ;
	}
	printf("%.8f\n", root) ;
	printf("%d", triedTimes) ;
	return 0 ;
}
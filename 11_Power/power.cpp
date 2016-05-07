#include <iostream>
using namespace std;

double Power(double base,int exponent)
{
	if(exponent == 0)
		return 1.0;
	double double_zero = 0.0;
	if((base-double_zero) > -0.0000001 && (base-double_zero) < 0.0000001){
		return 0.0;
	}
	if(exponent < 0)
		return 1/Power(base,(-1)*exponent);
	if(exponent == 1)
		return base;
	return base*Power(base,exponent);
}

double Power_best(double base,unsigned int exponent)
{
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;

	double result = Power_best(base,exponent>>1);
	result *= result;
	if(exponent & 0x1 == 1)
		result *= base;

	return result;
}

int main()
{
	return 0;
}

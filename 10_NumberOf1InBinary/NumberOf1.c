#include <stdio.h>

int NumberOf1(int n)
{
	int count = 0;
	unsigned long flag = 1;
	while(flag)
	{
		if(n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_best(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = (n-1)&n;
	}
	return count;
}

int main()
{
	int number1 = 1;
	int number2 = 0x7fffffff;
	int number3 = 0x80000000;
	int number4 = 0xffffffff;
	int number5 = 0;
	NumberOf1(number1);
	NumberOf1_best(number1);
	return 0;
}

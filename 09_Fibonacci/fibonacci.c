#include <stdio.h>

int Fibonacci(int n)
{
	int fib1 = 1;
	int fib2 = 1;
	int fib3;

	if(n == 0)
		return 0;
	if(n == 1 || n == 2)
		return 1;

	for(int i=3;i<=n;i++){
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
	}
	return fib3;
}

int main()
{
	int sum = 0;
	sum = Fibonacci(5);
	printf("%d",sum);
	return 0;
}

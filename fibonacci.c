#include <stdio.h>

/* Fibonacci Iterative implementation */
int fib_iter(n){
	int i = 2;
	int aux = 1;
	int tmp[2];
	tmp[0] = 0;
	tmp[1] = 1;

	if(n == 0 || n == 1)
		return tmp[n];

	for(; i <= n; i++){
		tmp[0] += aux;
		aux = tmp[1];
		tmp[1] = tmp[0];
	}

	return tmp[0];
}

/* Fibonacci Recursive implementation */
int fib_recur(n){
	return (n < 2)? n : fib_recur(n-1) + fib_recur(n-2);
}

#include <stdio.h>


int fib_iter(n){	//something wrong
	int i;
	int tmp[2];
	tmp[0] = 0;
	tmp[1] = 1;

	if(n == 0 || n == 1)
		return tmp[n];

	for(i = 2; i <= n; i++){
		tmp[0] += tmp[1];
		tmp[1] = tmp[0];
	}

	return tmp[0];
}

int fib_recur(n){
	if(n < 2)
		return n;
	return fib_recur(n-1) + fib_recur(n-2);
}

int main(){
	int i = fib_iter(10);
	printf("fib: %d\n", i);
	return 0;
}


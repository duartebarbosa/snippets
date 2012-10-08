#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535898
/* Useful defines in Math applications */
#define odd_even(x) ((x & 1) ?  1 : 0)			/* return 1 in odd number, 0 in even number. */
#define even(x) ((x & 1) ? 0 : 1 )			/* find if a number is even (return 1 - true). */
#define evener(x) ((x & 1) ? (x = (x + 1)) : (x))	/* even a number. */
#define odd(x) ((x & 1) ? 1 : 0 )			/* find if a number is odd (return 1 - true). */
#define odder(x) ((x & 1) ? (x) : (x = (x + 1)))	/* odd a number. */
#define MAX(a, b) ((a) < (b) ? (b) : (a))		/* find the maximum a number. */
#define MIN(a, b) ((a) > (b) ? (b) : (a))		/* find the minimum a number. */
#define SWAP(a, b)  {a ^= b; b ^= a; a ^= b;}		/* swap two numbers */

/* Useful defines in Sorting algorithms */
#define key(A) (A)					/* access the value to be compared, exchanged, wtv */
#define less(A, B) (key(A) < key(B))			/* find the "lesser" item */
#define exch (A, B) { Item t = A; A = B; B = t; } 	/* you need to define the "item" type */
#define compexch(A, B) if (less (B, A)) exch (A, B)	/* compare two items and change them if necessary */

/*
inline void swap(int &x, int &y){
        x ^= y ^= x ^= y;
}
*/

/* A prime number generator. The start argument is a seed from which the function must return a prime (by excess). */
unsigned long int prime_gen(int start){

	unsigned int k, found = 1;
	
	if(start == 2)
		return 2;

	for(odder(start); ; start += 2, found = 1){		// all even numbers are not prime
		for(k = 2; k < start; ++k)
			if(!(start % k))
				found = 0;
		if(found)
			break;
	}

	return start;
}


/* A prime number verifier. C!! */
int isprime(unsigned long n){

	if(n <= 3){
		if(n <= 1)
			return 0;
		return 1;
	}

	if(!(n % 2))			/* ((n % 2) == 0) */
		return 0;

	unsigned long i = 3, k = sqrt(n) + 1;
	
	for (; i <= k ; i += 2)
		if(n % i == 0)
			return 0;

	return 1;
}

inline int isPowerOf2(unsigned int n){
    return n == 1 || (n & (n-1)) == 0;
}

/* taken from http://cartera.me/2012/01/10/primality-testing-and-factorization-in-c/ with slight changes*/
void fillPrimeSieve(char *sieve, long int length) {
	for (long int i = 2; i <= length ; i++) {
		if (!sieve[i]) {
			for (long int j = 2 * i; j < length; j += i)
				sieve[j] = 1;
		}
	}
}

void factorizeWithTrialDivisionAndSieve(long int n, char *sieve, long max) {
	for (long int i = 2; i <= max; i++) {
		if (sieve[i]) continue;
		long int prime = i;
		if (prime * prime == n) {
			printf("%ld\n%ld\n", prime, prime);
			break;
		}
		if (n % prime == 0) {
			printf("%ld\n", prime);
			long int otherFactor = n/prime;
			if (isprime(otherFactor))
				printf("%ld\n", otherFactor);
			else
				factorizeWithTrialDivisionAndSieve(otherFactor, sieve, floor(sqrt(otherFactor)));
			break;
		}
	}
}

void factor(unsigned long n) {
	if (isprime(n)) {
		printf("%ld is prime.\n", n);
		return;
	}
	long int max = floor(sqrt(n));
	char *sieve = calloc(max, 1);
	fillPrimeSieve(sieve, max);
	factorizeWithTrialDivisionAndSieve(n, sieve, max);
	free(sieve);
}


int main(){
	factor(2147483642222329387);
	return 0;
}

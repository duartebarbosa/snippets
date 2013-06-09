#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HIGH_NIBBLE(b) (((b) >> 4) & 0x0F)
#define LOW_NIBBLE(b) ((b) & 0x0F)
#define SET_MOST_SIGNIFICANT_BIT(b) (b)<<((sizeof(int)*8)-1)

//int to binary string, non-x86 int beware!
//returning string must be freed.
char* itobs(int value){
	int j = 31;
	char aux[33] = {0};

	for(; value; value >>= 1)
		aux[j--] = value & 0x1 ? '1' : '0';

	return strcpy(calloc(32-j, 1), aux + j + 1);
}

// A positive integer N is called K-sparse if there are at least K 0s between any two consecutive 1s in its binary representation.
int kSparseIntegers(int value, int k){
	int i = 0, tmp = 0;
	char *aux = itobs(value);
	
	for(; aux[i] != '\0'; i++){
		if(aux[i] == '0')
			tmp++;
		else{
			if(i == 0 || aux[i+1] == '\0')
				continue;
			else if(tmp >= k)
				tmp = 0;
			else
				return -1;
		}
	}
	
	return 0;
			
}

//maximal consecutive zeros in the binary representation of a number
int consecutiveZeros(char *value){
	int index = 0, tmp = 0, counter = 0;
	
	for(; value[index] != '\0'; index++){
		if(value[index] == '0')
			tmp++;
		else{
			if(tmp > counter)
				counter = tmp;
			tmp = 0;
		}
	}

	if(tmp > counter)
		return tmp;

	return counter;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define HIGH_NIBBLE(b) (((b) >> 4) & 0x0F)
#define LOW_NIBBLE(b) ((b) & 0x0F)
#define SET_MOST_SIGNIFICANT_BIT(b) (b)<<((sizeof(int)*8)-1)
#define POWER_OF_TWO(B) ((B!=0)&&((B&(~B+1))==B))

int bstoi(char *binary){
	int size = 0, value = 0, index = 0;
	
	for(; binary[size] != '\0'; size++);

	for(; index != size; index++)
		value += (binary[index] == '1') ? pow(2, index) : 0;

	return value;

}

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

	if(POWER_OF_TWO(value))
		return 0;
	
	for(i = 0; aux[i] != '\0'; i++){
		if(aux[i] == '0')
			tmp++;
		else{
			if(i == 0 || (aux[i+1] == '\0' && tmp >= k))
				continue;
			else if(tmp >= k)
				tmp = 0;
			else
				return -1;
		}
	}
	free(aux);
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

//solution for codility challenge
int kSparseIntegersBetween(char *source, char *target, int n) {
	int min = bstoi(source), max = bstoi(target), counter = 0;
	
	for(; min <= max; min++)
		if(kSparseIntegers(min, n) == 0)
			counter++;
	return counter;
}


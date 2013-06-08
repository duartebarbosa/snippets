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


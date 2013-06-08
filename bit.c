#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HIGH_NIBBLE(b) (((b) >> 4) & 0x0F)
#define LOW_NIBBLE(b) ((b) & 0x0F)


//int to binary string, x86 int beware.
//returning string must be freed!
char* itobs(int value){
	int j = 31;
	char aux[33] = {0};

	for(; value; value >>= 1)
		aux[j--] = value % 2 ? '1' : '0';

	return strcpy(calloc(32-j, 1), aux + j + 1);
}


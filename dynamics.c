/* 

float *array = (float *) malloc (sizeof (float) * array_width * array_height);

#define ARRAY(x,y) array[(x) + (y) * array_width]
*/

float **createContiguous2Darray(int array_height, int array_width){

	float **array = calloc (array_height * sizeof(float));
	float *data = malloc (array_width * array_height * sizeof(float));
	int n = 0;

	for (; n < array_height; ++n)
		array[n] = data + n * array_width;

	return array;
}


/* Now you can access the elements in the array using array[y][x]. */


char *CreateArray(int number, int ascii){					/* cria arrays com number elementos inicializados a ascii */

	register int index;
	char *p = calloc(number, sizeof(char));

	for(index = 0; index <= number - 1; index++){
		p[index] = ascii;
	}

	return p;
}

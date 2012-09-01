char *CreateArray(int number, int ascii){					/* cria arrays com number elementos inicializados a ascii */

	register int index;
	char *p = calloc(number, sizeof(char));

	for(index = 0; index <= number - 1; index++){
		p[index] = ascii;
	}

	return p;
}

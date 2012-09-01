#include <stdio.h>
#include <string.h>
#include <ctype.h>


int inverte (char* string) {

  	register int num_words, num_car, num_car_esp, num_spa, num_dig;						/* Define contadores */
	num_words = num_car = num_car_esp = num_spa = num_dig = 0;

	if (isblank(string[num_car]))
		num_spa++;

	for (num_car = 1; string[num_car] != '\0'; num_car++) {				/* Corre os Contadores */
			
		if (isblank(string[num_car])) {
			num_spa++;
			if ((!isblank(string[num_car-1])) && (!isblank(string[num_car+1])))
				num_words++;
		}
		
		else {
			if (isblank(string[num_car-1]))
				num_words++;
		}


		if (isdigit(string[num_car]))
			num_dig++;
	}

	num_car_esp = num_car - num_dig - num_spa;					/* Detecta caracteres especiais*/

	if (string[0] != '\0') {

		if (((num_spa > num_words) && (num_spa != num_car) && (num_spa > (num_car - num_spa))) ||
		   ((num_spa == 0) && (num_car > 0)) )
			num_words++;

		
		printf ("\nNúmero de Words : %d\n", num_words);					/* Printa as estatisticas */
		
		printf ("Número de Caracteres : %d\n", num_car);

		printf ("Número de Dígitos : %d\n", num_dig);

		printf ("Número de Caracteres Especiais : %d\n", num_car_esp-num_spa);

		printf ("Número de Espaços em branco : %d\n", num_spa);

		printf ("\nA string invertida fica : ");

		while (num_car != -1){								/* Manda para o stdout o inverso do array */
			printf("%c", string[num_car]);
			num_car--;
		  }

		return 0;
	}
	
	else {
		printf ("\nThis isn't really a string right? Dumbass.");
		return 1;
	}
}




int main(int argc,char *argv[]) {


  	char string[100];
  	
	system("clear");

  	printf ("\n");
 	printf ("#######################\n");
	printf ("#                     #\n");
	printf ("#   Inverte Strings   #\n");
	printf ("#                     #\n");
	printf ("#######################\n\n");


	if (argc > 1) {
		if (strcmp (argv[1], "-help") == 0) {
			printf ("\nEste Programa inverte Strings pela ordem contrária a que foram introduzidas. \n\n"
				  "USO :\n"
				  "\tinvert_strings [\"ARGUMENT\"]\n"
				  "\tinvert_strings\n\n"
				  "duarte barbosa @ Skywalker\n\n");
			return 0;
		}	

		else {
			inverte (argv[1]);
			printf ("\n\nduarte barbosa @ Skywalker\n\n");
			return 0;
		}
	}

	else { 
		printf ("Insira uma string para inverter : ");  
		gets (string);							/* Escuta o input no stdin */

		fgets (string, 100, stdin);
	
		inverte (string);
		
  	}
	printf ("\n\nduarte barbosa @ Skywalker\n\n");

  	return 0;


}





/* duarte barbosa @ Skywalker, 24/08/2009 */

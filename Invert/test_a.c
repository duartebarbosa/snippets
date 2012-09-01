#include <stdio.h>


int inverte (char* string, int i) {

	if ( i != 0) {
		printf ("\nNúmero de Words : %d\n", i);
		
		for (; string[i] != '\0'; i++);

		printf ("Número de caracteres : %d\n", i);

		printf ("\nA string invertida fica : ");
		  while (i != -1){

		    printf("%c", string[i]);
			i--;
		  }
		return 0;
	}
	
	else {
		printf ("\nThis isn't really a word right? Dumbass.");
		return 1;
	}
}




int main(int argc,char *argv[]) {

  register int num;
  char *string;
  char str[80];

  printf ("\n\n");
  printf ("#######################\n");
  printf ("#                     #\n");
  printf ("#     Inverte Words   #\n");
  printf ("#                     #\n");
  printf ("#######################\n\n");
  printf ("Insira uma word para inverter : ");  


  num = scanf ("%s", str);

  string = str;



  inverte (string, num);
	
  printf ("\n\n");

  return 0;


}





/* duarte barbosa @ Skywalker, 15/07/2009 */

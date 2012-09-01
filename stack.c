#include <stdio.h>
#include <stdlib.h>

/* Stack (array implementation) of size SIZE. */
#define SIZE 10

int stack[SIZE];

int *top = stack;		/* top points to the top of stack */
int *p1 = stack;		/* initialize p1 */


void push(int i){
	p1++;

	if(p1 == (top + SIZE)) {
		printf("Stack Overflow.\n");
	}
	*p1 = i;
}

int pop(void){

	int *p2 = p1;
	if(p1 == top) {
		printf("Stack Underflow.\n");
	}
	p1--;

	return *(p2++);
}

int back(void){

	int *p2 = p1;	
	return *(p2--);
}

int actual(void){

	return *p1;
}



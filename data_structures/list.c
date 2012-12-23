#include <stdio.h>
#include <stdlib.h>

//Structure containing a Data part & a
//Link part to the next node in the List

struct info {
	int size;
	struct Node *head, *tail;
}

typedef struct Node {
	void *data;
	struct Node *previous, *next;
} *node_t;

// Counting number of elements in the List

int length(){
	return info.size;
	/*
	struct Node *current;
	int count = 0;

	current = head;

	while(current != NULL){
		current = current->next;
		count++;
	}
	return(count);*/
}

void delete(node_t node){
	if(current == info.head){
		info.head = current->next;
		info.head->previous = NULL;
	}
	else if(current == info.tail){
		info.tail = current->previous;
		info.tail->next = NULL
	}
	else{
		current->next->previous = current->previous;
		current->previous = current->next;
	}
	info.size--;
	free(current);
}

// Deleting a node from List depending upon the data in the node.

int deleteElement(node_t node) {

	node_t current = info.head;

	for(; current != NULL; current = current->next)
		if(current == node){
			delete(current);
			return 0;
		}

	return 1;
}

// Deleting a node from List depending upon the location in the list.

int deleteElementAt(int location){
	node_t current = info.head;

	if(location < 0 || location > info.size)
		printf("[list] delete : invalid element location\n");
	else {
		for(; location > 0, location--)
			current = current->next;
		delete(current);
		return 0;
	}
	return 1;
}

int addElementStart(void *data){
	node_t aux = malloc(sizeof(struct Node));
	aux->data = data;
	aux->previous = NULL;

	if(info.head == NULL)
		aux->next = NULL;
	else
		aux->next = info.head;

	info.head = aux;
	return 0;
}

int addElementEnd(void *data){
	node_t tmp = malloc(sizeof(struct Node));
	tmp->data = data;
	tmp->after = NULL;

	if(info.tail == NULL)
		aux->previous = NULL;
	else
		aux->previous = info.tail;

	info.tail = tmp;
	return 0;
}


void addElementAt(void *data, int location){
	int i;
	struct Node *temp, *previous, *current = head;

	if(location < 0 || location > info.size + 1)
		printf("[list] insertion : invalid element location\n");
	else{
		if (!location)
			addElementStart(data);
		else if(location == info.size + 1)
			addElementEnd(data);
		else{
			for(i=1;i<loc;i++){
					previous=current;
					current=current->next;
			}

			temp=(struct Node *)malloc(sizeof(struct Node));
			temp->Data=num;

			previous->next=temp;
			temp->next=current;
		}
	}
}

// Displaying list contents

void display(){
	struct Node *current=head;

	if(current==NULL){
		 printf("\nList is Empty");
	}
	else{
			printf("\nElements in the List: ");
			//traverse the entire linked list
			while(current!=NULL)
			{
					printf(" -> %d ",current->Data);
					current=current->next;
			}
			printf("\n");
	}
}

//Reversesing a Linked List

void reverse(){
	struct Node *previous, *current, *temp;

	current=head;
	previous=NULL;

	while(current != NULL){
		 temp=previous;
		 previous=current;

		 current=current->next;
		 previous->next=temp;
	}

	head=previous;
}


int main(int argc, char *argv[]){
 int i=0;

 //Set head as NULL
 head=NULL;

 while(1) {
		printf("\n####################################################\n");
		printf("MAIN MENU\n");
		printf("####################################################\n");
		printf(" \nInsert a number \n1. At the Beginning");
		printf(" \n2. At the End");
		printf(" \n3. At a Particular Location in the List");
		printf(" \n\n4. Print the Elements in the List");
		printf(" \n5. Print number of elements in the List");
		printf(" \n6. Reverse the linked List");
		printf(" \n\nDelete a Node in the List");
		printf(" \n7. Delete a node based on Value");
		printf(" \n8. Delete a node based on Location\n");
		printf(" \n\n9. Exit\n");
		printf(" \nChoose Option: ");
		scanf("%d",&i);

		switch(i){
			case 1:
			{
					int num;
					printf(" \nEnter a Number to insert in the List: ");
					scanf("%d",&num);
					addBeg(num);
					display();
					break;
			}

			case 2:
			{
					int num;
					printf(" \nEnter the Number to insert: ");
					scanf("%d",&num);
					addEnd(num);
					display();
					break;
			}

			case 3:
			{
					int num, loc;
					printf("\nEnter the Number to insert: ");
					scanf("%d",&num);
					printf("\nEnter the location Number in List at which \
					the Number is inserted: ");
					scanf("%d",&loc);
					addAt(num,loc);
					display();
					break;
			}

			case 4:
			{
					display();
					break;
			}

			case 5:
			{
					display();
					printf(" \nTotal number of nodes in the List: %d",length());
					break;
			}

			case 6:
			{
					reverse();
					display();
					break;
			}

			case 7:
			{
					int num;
					printf(" \nEnter the number to be deleted from List: ");
					scanf("%d",&num);
					delNodeData(num);
					display();
					break;
			}

			case 8:
			{
					int num;
					printf(" \nEnter the location of the node to \
					be deleted from List: ");
					scanf("%d",&num);
					delNodeLoc(num);
					display();
					break;
			}

			case 9:
			{
					struct Node *temp;

					while(head != NULL)
					{
							temp = head->next;
							free(head);
							head = temp;
					}
					exit(0);
			}

			default:
			{
					printf("\nWrong Option choosen");
			}
		}/* end if switch */
 }/* end of while */
}/* end of main */

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
		current = current->Next;
		count++;
	}
	return(count);*/
}

// Deleting a node from List depending upon the data in the node.

int deleteElement(node_t node) {

	node_t current = info.head;

	for(; current != NULL; current = current->next){
		if(current == node){
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
			return 0;
		}
	}
	return 1;
}

int deleteElement(int num){
	node_t previous, current = info.head;

	while(current != NULL){
		 if(current->Data == num){
				if(current==head){
					 head=current->Next;
					 free(current);
					 return 0;
				}
				else{
					 previous->Next=current->Next;
					 free(current);
					 return 0;
				}
		 }
		 else{
				previous=current;
				current=current->Next;
		 }
	}

	printf("\nElement %d is not found in the List", num);
	return 1;
}

// Deleting a node from List depending upon the location in the list.

int delNodeLoc(int loc){
	struct Node *previous, *current;
	int i;

	current=head;

	if(loc > (length()) || loc <= 0){
			printf("\nDeletion of Node at given location is not possible\n ");
	}
	else {
			// If the location is starting of the list
			if (loc == 1){
					head=current->Next;
					free(current);
					return 0;
			}
			else{
					for(i=1;i<loc;i++){
							previous=current;
							current=current->Next;
					}

					previous->Next=current->Next;
					free(current);
			}
	}
	return 1;
}

//Adding a Node at the end of the list

void addEnd(int num){
	struct Node *temp1, *temp2;

	temp1=(struct Node *)malloc(sizeof(struct Node));
	temp1->Data=num;

	// Copying the head location into another node.
	temp2=head;

	if(head == NULL){
		 // If List is empty we create First Node.
		 head=temp1;
		 head->Next=NULL;
	}
	else{
		 // Traverse down to end of the list.
		 while(temp2->Next != NULL)
		 temp2=temp2->Next;

		 // Append at the end of the list.
		 temp1->Next=NULL;
		 temp2->Next=temp1;
	}
}

// Adding a Node at the Beginning of the List

void addBeg(int num){
	struct Node *temp;

	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->Data = num;

	if (head == NULL){
		 //List is Empty
		 head=temp;
		 head->Next=NULL;
	}
	else {
		 temp->Next=head;
		 head=temp;
	}
}

// Adding a new Node at specified position

void addAt(int num, int loc){
	int i;
	struct Node *temp, *previous, *current;

	current=head;

	if(loc > (length()+1) || loc <= 0){
		 printf("\nInsertion at given location is not possible\n ");
	}
	else{
			// If the location is starting of the list
			if (loc == 1){
					addBeg(num);
			}
			else{
					for(i=1;i<loc;i++){
							previous=current;
							current=current->Next;
					}

					temp=(struct Node *)malloc(sizeof(struct Node));
					temp->Data=num;

					previous->Next=temp;
					temp->Next=current;
			}
	}
}

// Displaying list contents

void display(){
	struct Node *current;

	current=head;

	if(current==NULL){
		 printf("\nList is Empty");
	}
	else{
			printf("\nElements in the List: ");
			//traverse the entire linked list
			while(current!=NULL)
			{
					printf(" -> %d ",current->Data);
					current=current->Next;
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

		 current=current->Next;
		 previous->Next=temp;
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
							temp = head->Next;
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

#include <stdio.h>
#include <stdlib.h>

//Structure containing a data part & a
//Link part to the next node in the List

struct {
	int size;
	struct Node *head, *tail;
} info;

typedef struct Node {
	void *data;
	struct Node *previous, *next;
} *node_t;

struct coco {
	int i;
};

// Counting number of elements in the List
int length(){
	return info.size;
}

void delete(node_t current){
	if(current == info.head){
		info.head = current->next;
		if(info.head != NULL)
			info.head->previous = NULL;
	}
	else if(current == info.tail){
		info.tail = current->previous;
		if(info.tail != NULL)
			info.tail->next = NULL;
	}
	else{
		current->previous->next = current->next;
		current->next->previous = current->previous;
	}
	info.size--;
	free(current->data);
	free(current);
}

int deleteElementStart() {
	delete(info.head);
	return 0;
}

int deleteElementEnd() {
	delete(info.tail);
	return 0;
}


// Deleting a node from List depending upon the data in the node.
int deleteElement(void *data) {
	node_t current = info.head;

	for(; current != NULL; current = current->next)
		if(current->data == data){
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
		for(; location > 0 ; location--)
			current = current->next;
		delete(current);
	}
	return 0;
}

int addElementStart(void *data){
	node_t aux = malloc(sizeof(struct Node));
	aux->data = data;
	aux->previous = NULL;

	if(info.head == NULL){
		aux->next = NULL;
		info.tail = aux;
	}
	else{
		aux->next = info.head;
		info.head->previous = aux;
	}

	info.head = aux;
	info.size++;
	return 0;
}

int addElementEnd(void *data){
	node_t tmp = malloc(sizeof(struct Node));
	tmp->data = data;
	tmp->next = NULL;

	if(info.tail == NULL){
		tmp->previous = NULL;
		info.head = tmp;
	}
	else{
		tmp->previous = info.tail;
		info.tail->next = tmp;
	}

	info.tail = tmp;
	info.size++;
	return 0;
}

int addElementAt(void *data, int location){
	node_t tmp = NULL, current = info.head;

	if(location < 0 || location > info.size + 1)
		printf("[list] insertion : invalid element location\n");
	else{
		if (!location)
			addElementStart(data);
		else if(location == info.size + 1)
			addElementEnd(data);
		else{
			for(; location > 0 && current->next != NULL; location--, current = current->next);
			tmp = malloc(sizeof(struct Node));
			tmp->data = data;
			tmp->previous = current->previous;
			tmp->previous->next = tmp;
			tmp->next = current;
			tmp->next->previous = tmp;
			info.size++;
		}
	}
	return 0;
}

// Displaying list contents
void display(){
	node_t current = info.head;
	printf("head: %p, tail: %p\n", info.head, info.tail);
	if(current == NULL)
		 printf("List is Empty");
	else{
		printf("Elements in the List: ");
		//traverse the entire linked list
		for(; current != NULL; current = current->next)
			printf(" -> %p ", current);
	}
	printf("\n");
}

void reverse(){
	node_t a = NULL, b = info.head, c = NULL;
	
	while(b != NULL) {
		c = b->next;
		if(!c)
			info.head = b;

		b->next = a;
		a = b;
		b = c;
	}
}

void freemem(){
	node_t current = info.head, tmp = info.head;
	for(; tmp != NULL; current = tmp){
		tmp = current->next;
		free(current->data);
		free(current);
	}
}

struct coco* dummy(){
	static int j = 0;
	struct coco * dummyStruct = malloc(sizeof(struct coco));
	dummyStruct->i = j++;
	return dummyStruct;
}

int main(){
	addElementStart(dummy());
	addElementStart(dummy());
	addElementStart(dummy());
	display();
	reverse();
	printf("_________________________\n");
	display();
	freemem();
	return 0;
}

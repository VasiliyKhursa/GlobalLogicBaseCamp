/*
 ============================================================================
 Name        : 03_LIST.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    void  *data;
    struct Node *next;
} Node ={.data=NULL, Node=NULL };

typedef void (*callback)(Node* data);


void printNode (Node* data)
{
	printf("%p\n", data);
}

//traverse(head, printNode);

void traverse(Node* head, callback func)
{
	Node* cursor = head;
    while(cursor != NULL)
    {
        func(cursor);
        cursor = cursor->next;
    }
}

int count(Node *head)
{
	Node *cursor = head;
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}

Node* reverse(Node* head)
{
	Node* prev    = NULL;
	Node* current = head;
	Node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}


void insert(Node * head, int val) {
	Node * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(Node));
    current->next->next = NULL;
}

void destroy(Node *head)
{
	Node *current = head;
	Node *next;

    while (current != NULL)
    {
       next = current->next;
       free(current->data);
       free(current);
       current = next;
    }
    head = NULL;
}



typedef struct people{
	char name[10];
	char addr[10];
} people;



int main(void) {

	people * ptemp = malloc(sizeof(people));
	Node first;

	first.data = ptemp;



	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

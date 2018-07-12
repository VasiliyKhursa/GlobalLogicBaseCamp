/*
 * main.c
 *
 *  Created on: Jul 12, 2018
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    void  *data;
    struct Node *next;
} node_t;

typedef void (*callback)(node_t * data);


void printNode (node_t * data)
{
	printf("%p\n", data);
}

//traverse(head, printNode);

void traverse(node_t * head, callback func)
{
	node_t * cursor = head;
    while(cursor != NULL)
    {
        func(cursor);
        cursor = cursor->next;
    }
}

int count(node_t *head)
{
	node_t *cursor = head;
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}

node_t * reverse(node_t * head)
{
	node_t * prev    = NULL;
	node_t * current = head;
	node_t * next;
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


void insert(node_t  * head, int val) {
	node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->next = NULL;
}

void destroy(node_t * head)
{
	node_t * current = head;
	node_t * next;

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
	node_t first;

	first.data = ptemp;

	printf("%p\n", first.data);

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

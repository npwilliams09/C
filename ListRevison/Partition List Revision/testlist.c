//testlist.c
//originally by Bella

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"


static list newList(void);
static link newNode(int v);
static void printList(list l);
void partition (list sourceList);

int main (int argc, char*argv[]){
	list l1 = newList();

	link n1 = newNode(10);
	link n2 = newNode(1);
	link n3 = newNode(23);
	link n4 = newNode(1);
	link n5 = newNode(10);
	link n6 = newNode(2);
	link n7 = newNode(3);
	link n8 = newNode(1);


	//checking an empty list
	printf("\n======TEST 1=====\n");
	printf("The list before:   ");
	printList(l1);
	partition(l1);
	printf("The list after:    ");
	printList(l1);
	assert(l1->head == NULL);
	printf("==TEST 1 PASSED==\n");


	l1->head = n1;
	//checking list with 1 element
	printf("\n======TEST 2=====\n");
	printf("The list before:   ");
	printList(l1);
	partition(l1);
	printf("The list after:    ");
	printList(l1);
	assert(l1->head == n1);
	printf("==TEST 2 PASSED==\n");

	n1->next = n2;
	//checking list with element 2 smaller than first
	printf("\n======TEST 3=====\n");
	printf("The list before:   ");
	printList(l1);
	partition(l1);
	printf("The list after:    ");
	printList(l1);
	assert(l1->head == n2);
	printf("==TEST 3 PASSED==\n");
	
	list l2 = newList();
	l2->head  = n1;
	n1->next = n2;
	n3->next = NULL;
	n1->value = 20;
	n2->value = 21;
	n3->value = 22;
	n2->next = n3;
	//checking list with 3 elements
	printf("\n======TEST 4=====\n");
	printf("The list before:   ");
	printList(l2);
	partition(l2);
	printf("The list after:    ");
	printList(l2);
	assert(l2->head == n1);
	printf("==TEST 4 PASSED==\n");
	
	n1->value = 21;
	n2->value = 20;
	n3->value = 22;
	//checking list with 3 elements
	printf("\n======TEST 5=====\n");
	printf("The list before:   ");
	printList(l2);
	partition(l2);
	printf("The list after:    ");
	printList(l2);
	assert(l2->head == n2);
	assert(l2->head->next == n1);
	assert(l2->head->next->next == n3);
	assert(l2->head->next->next->next == NULL);
	printf("==TEST 5 PASSED==\n");

	l2->head = n1;
	n1->next = n2;
	n2->next = n3;
	n1->value = 21;
	n2->value = 22;
	n3->value = 20;
	//checking list with 3 elements
	printf("\n======TEST 6=====\n");
	printf("The list before:   ");
	printList(l2);
	partition(l2);
	printf("The list after:    ");
	printList(l2);
	assert(l2->head == n3);
	assert(l2->head->next == n1);
	assert(l2->head->next->next == n2);
	assert(l2->head->next->next->next == NULL);
	printf("==TEST 6 PASSED==\n");
	
	l2->head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n1->value = 44;
	n2->value = 30;
	n3->value = 12;
	n4->value = 444;

	printf("\n======TEST 7=====\n");
	printf("The list before:   ");
	printList(l2);
	partition(l2);
	printf("The list after:    ");
	printList(l2);
	assert(l2->head == n2);
	assert(l2->head->next == n3);
	assert(l2->head->next->next == n1);
	assert(l2->head->next->next->next == n4);
	assert(l2->head->next->next->next->next == NULL);
	printf("==TEST 7 PASSED==\n");
		
	l2->head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n1->value = 200;
	n2->value = 10;
	n3->value = 250;
	n4->value = 15;

	printf("\n======TEST 8=====\n");
	printf("The list before:   ");
	printList(l2);
	partition(l2);
	printf("The list after:    ");
	printList(l2);
	assert(l2->head == n2);
	assert(l2->head->next == n4);
	assert(l2->head->next->next == n1);
	assert(l2->head->next->next->next == n3);
	assert(l2->head->next->next->next->next == NULL);
	printf("==TEST 8 PASSED==\n");

	l2->head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = NULL;

	n1->value = 50;
	n2->value = 100;
	n3->value = 20;
	n4->value = 150;
	n5->value = 21;
	n6->value = 22;
	n7->value = 250;
	n8->value = 15;


	printf("\n======TEST 9=====\n");
	printf("The list before:   ");
	printList(l2);
	partition(l2);
	printf("The list after:    ");
	printList(l2);
	assert(l2->head == n3);
	assert(l2->head->next == n5);
	assert(l2->head->next->next == n6);
	assert(l2->head->next->next->next == n8);
	assert(l2->head->next->next->next->next == n1);
	assert(l2->head->next->next->next->next->next == n2);
	assert(l2->head->next->next->next->next->next->next == n4);
	assert(l2->head->next->next->next->next->next->next->next == n7);
	printf("==TEST 9 PASSED==\n");
	
	l2->head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = NULL;

	n1->value = 50;
	n2->value = 49;
	n3->value = 48;
	n4->value = 47;
	n5->value = 46;
	n6->value = 45;
	n7->value = 44;
	n8->value = 43;


	printf("\n======TEST 10=====\n");
	printf("The list before:   ");
	printList(l2);
	partition(l2);
	printf("The list after:    ");
	printList(l2);
	assert(l2->head == n2);
	assert(l2->head->next == n3);
	assert(l2->head->next->next == n4);
	assert(l2->head->next->next->next == n5);
	assert(l2->head->next->next->next->next == n6);
	assert(l2->head->next->next->next->next->next == n7);
	assert(l2->head->next->next->next->next->next->next == n8);
	assert(l2->head->next->next->next->next->next->next->next == n1);
	printf("==TEST 10 PASSED==\n\n");
	
	printf("\n<(-_-)>~<(-_-)>~<(-_-)>~<(-_-)>~<(-_-)>\n\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("         You passed you legend         \n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("\n<(-_-)>~<(-_-)>~<(-_-)>~<(-_-)>~<(-_-)>\n\n\n");


	return EXIT_SUCCESS;
}

static list newList(void){
	//create new list
	list new = malloc(sizeof(struct _list));
	return new;
}

static link newNode(int v){
	//create new node
	link new = malloc(sizeof(struct _node));
	new->next = NULL;
	new->value = v;
	return new;
}

static void printList(list l){
	link curr = l->head;
	while(curr != NULL){
		printf("[%d]->", curr->value);
		curr = curr->next;
	}
	printf("X\n");
}

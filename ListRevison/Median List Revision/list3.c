//Written by Michael Simarta
//With the help of Bernice Chen
//list.c file that implements all functions declared in list.h
//implement the median() function here
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
 
typedef struct _node {
    int value;
    Node next;
} node;
 
typedef struct _list {
    Node head;
} list;
 
//when the median() function is complete,
//compile with testList.c, type
//"gcc -Wall -Werror -O -o test testList.c List.c"
//to run program, type
//"./test"
 
//TODO
//Read List.h to help you look at the hints
//find the median value
//given a list X
//(Empty List)
//then median (list);
//it will return 0 
 //
//given a list 1->X
//then median (list);
//it will return 1  
//
//given a list 0->1->2->X
//then median (list);
//it will return 1
//
//given a list 2->3->5->6->X
//then median (list);    
//it will return 4
//because the middle is the average of the 2 middlemost numbers
//(3+5)/2 = 4.
//We will not test where the average will lead to decimal places
//
//given a list 2->3->5->6->1000->X
//then median (list);
//it will return 5
int median(List l) {
   int med = 0; 
   if (l->head == NULL){
    med = 0;
   }
   else if (l->head->next == NULL) {
      med = l->head->value;
   }
   else {
   Node current = l->head;
   int i = 0;
   int h = 0;
   while (current !=NULL) {
      i++;
      current = current->next;
   }
   if (i%2 == 0) {
           
      i = (i + 2) / 2;
      h = i  - 1;
   }
   if (i%2 != 0) {
      i = ((i + 1) / 2);
      h = i;
   }
   int ivalue = 0;
   int hvalue = 0;
   
   current = l->head;
   int j = 1;
   while (j < i) {
      current = current -> next;
      j++;
   }
   ivalue = current->value;
   
   current = l->head;
   j = 0;
   while (j < h) {
      current = current -> next;
      j++;
   }
   hvalue = current->value;
   
   med = (hvalue + ivalue) / 2;
   }
   return med;
}
 
//returns a new list of length 0
List newList() {
   List l = malloc(sizeof(list));
   assert ( l!=NULL );
   l->head = NULL;
   return l;
}
 
//frees everything malloced for the list
void destroy(List l) {
   Node curNode = l->head;
   Node prevNode = NULL;
 
   while (curNode != NULL) {
     prevNode = curNode;
     curNode = prevNode->next;
     free(prevNode);
   }
 
   free(l);
}
 
//appends a node of value to the end of the list
void append(List l, int value) {
   Node newNode = malloc(sizeof(node));
   newNode->value = value;
   newNode->next = NULL;
   Node curNode = l->head;
   if ( curNode==NULL ) {
      l->head = newNode;
   } else {
      while ( curNode->next!=NULL ) {
         curNode = curNode->next;
      }
      curNode->next = newNode;
   }
}
 
//returns the int value of the node at index
//assumes input index is within range of the list's length
int getValue(List l, int index) {
 
   Node curNode = l->head;
   assert (curNode!=NULL);
   int counter = 0;
   while (counter<index) {
      curNode = curNode->next;
      counter++;
   }
   return curNode->value;
}
 

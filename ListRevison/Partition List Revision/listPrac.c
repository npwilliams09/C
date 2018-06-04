//Nathan Williams
//28/05/16
//partition solution

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void partition (list sourceList);

void partition (list sourceList) {
    
    if (sourceList->head == NULL) {
        return;
    }
    
    else if (sourceList->head->next == NULL) {
        return;
    }
    
    else {
        int value = sourceList->head->value;
        link current = sourceList->head;
        link headHold = sourceList->head;
        link chainHead = sourceList->head;
        link newHead = NULL;
        
        while (current != NULL) {
            if (current->value < value) {
                link relink = current->next;
                current->next = headHold;
                if (sourceList->head == headHold) {
                    sourceList->head = current;
                    newHead = current;
                }
                else {
                    newHead->next = current;
                    newHead = newHead->next;
                }
                chainHead->next = relink;
                current = headHold;
            } else {
                if (chainHead->next != NULL) {
                    if (chainHead->next->value >= value) {
                        chainHead = chainHead->next;
                    }
                }
            }
            current = current->next;
        }
    }
}



/*
void partition (list sourceList){
    link curr = sourceList->head;
	link first = sourceList->head;
	link newHead = NULL;
	if(curr == NULL){
  	    return;
	} else if(curr->next == NULL){
	    return;
	} else { //actual code
	    int value = first->value;
	    while(curr != NULL){
		if(curr->value < value){
		    if(sourceList->head == first){
			    sourceList->head = curr;
			    if(first->next == curr){
			        first->next = curr->next;
			    } else {
			        link currR = first;
			        while(currR->next != curr){
			            currR = currR->next;
			        }
			        currR->next = curr->next;
		            }
			    curr->next = first;
		    } else {
			    newHead->next = curr;
			    if(first->next == curr){
		       	    first->next = curr->next;
			    } else {
			        link currR = first;
			        
			        while(currR->next != curr){
				        currR = currR->next;
			        }
			        currR->next = curr->next;
			    }
			    curr->next = first;
	        }
		newHead = curr;
	    }
	    curr = curr->next;
	    }
    }
} */

 



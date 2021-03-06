/* intlist.c - implements functions of intlist.h
   YOUR NAME(S) AND TODAY'S DATE */

#include "intlist.h"

#include <stdio.h>
#include <stdlib.h>

/* return sum of values in list */
int sum(Node *list) {
  Node *n;
  int count = 0;
  for(n=list; n!=NULL; n=n->next)
    count += n->info;
    return count;
}

/* returns true if value is in the list; false if not */
int contains(int value, Node *list) {
    /* REPLACE THIS NON-SOLUTION */
    return 0;
}

/* implement optional challenge functions here */



/* four functions below already done; do not change */

/* append value at end of list */
void append(int value, Node **listPtr) {
    Node *newNode = malloc(sizeof(Node));
    newNode->info = value;
    newNode->next = NULL;
    
    if (*listPtr == NULL) /* empty list */
        *listPtr = newNode;
    
    else {
        Node *n = *listPtr;
        while (n->next) /* not last node yet */
            n = n->next;
        n->next = newNode;
    }
}

/* print values separated by spaces */
void printList(Node *list) {
    Node *n = list;
    while (n) {
        printf("%d", n->info);
        if (n->next)
            putchar(' ');
        n = n->next;
    }
}

/* return count of values */
int count(Node *list) {
    int result = 0;
    Node *n = list;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}

/* free all the nodes in list */
void freeNodes(Node **listPtr) {
    Node *n = *listPtr, *temp;
    while (n) {
        temp = n;
        n = n->next;
        free(temp);
    }
    *listPtr = NULL;
}

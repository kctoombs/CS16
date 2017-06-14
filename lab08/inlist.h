/* intlist.h - linked list header file for CS 16 Lab08 */

#ifndef INTLIST_H
#define INTLIST_H

/* one node of a linked list - DO NOT CHANGE THIS DEFINITION */
struct node {
    int info;
    struct node *next;
};

/* handy alias for the struct node type */
typedef struct node Node;

/* 4 functions already implemented in intlist.c */
void append(int value, Node **listPtr);  /* append value at end of list */
void printList(Node *list);              /* print values to stdout */
int count(Node *list);                   /* return count of values */
void freeNodes(Node **ListPtr);          /* free all the nodes in list */

/* 2 FUNCTIONS YOU MUST IMPLEMENT in intlist.c */
int sum(Node *list);                    /* sum of all values */
int contains(int value, Node *list);    /* true if value in list */

/* suggested signatures of optional challenge functions:
int max(Node *list);
double average(Node *list);
void insertFirst(int value, Node **listPtr);
*/

#endif

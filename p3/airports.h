/* airports.h - header file for CS 16 Project 3.
   DO NOT CHANGE THIS FILE - you will not turn it in */

#ifndef AIRPORTS_H
#define AIRPORTS_H

#include <stdio.h>
#include <stdlib.h>

/* defined types:
   AirportCode is an alias for a 4-char array
   Node is a linked list node (struct) for AirportCodes */
typedef char AirportCode[4];
typedef struct node {
    AirportCode airport;
    struct node *next;
} Node;

/* The assignment is to implement each of the following five functions;
   more details are provided in airports.c */
void insertFirst(AirportCode, Node **);
void deleteFirst(Node **);
Node *copy(Node *);
void reverse(Node **);
Node *concat(Node *, Node *);

/*
   The following three functions are already defined in the skeleton -
   DO NOT CHANGE THEM, BUT YOU MAY USE THEM AS NECESSARY.
   - newNode is used to create new list nodes
   - append will add a new node to the end of the list
   - recycle frees the memory used by a linked list of nodes
*/
Node *newNode(AirportCode);
void append(AirportCode, Node **);
void recycle(Node **);

#endif

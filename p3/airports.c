/*
    airports.c
    Kenneth Toombs, 3/3/2014
*/

#include <string.h>
#include "airports.h"

/* insertFirst - creates a new node with code as its airport field,
        and makes this node the first node in the list */
void insertFirst(AirportCode code, Node **listPtr) {

  if(*listPtr == NULL)
    {
      Node *new;
      new = newNode(code);
     *listPtr = new;
    }
  else
    {
      Node *newPtr;
      newPtr = newNode(code); 
      newPtr->next = *listPtr;
      *listPtr = newPtr;
    }
  
  
}

/* deleteFirst - removes the first node from the list, and frees
        the memory space used by this node;
        all other nodes remain in the list
        Note: does nothing if the list is empty */
void deleteFirst(Node **listPtr) {

  Node *temp = *listPtr;
    if(*listPtr == NULL)
    return;
 
    *listPtr = temp->next;
    free(temp);
}


/* copy - copies the list, and returns a pointer to the new list
        Note: the new list contains copies of each node in list */
Node *copy(Node *list) {
  if(list == NULL)
    return list;
  Node *n = newNode(list->airport);
  Node **nptr = &n;
  Node  *ptr = list;
    
  for(ptr = list->next; ptr != NULL; ptr=ptr->next)
    append(ptr->airport,nptr);
  /*deleteFirst(nptr);*/
  return n;
  
 
}

/* reverse - reverses the order of the nodes in the list */
void reverse(Node **listPtr) {
  Node *prev = NULL;
  Node *current = *listPtr;
  Node * next;
  while(current)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
  *listPtr = prev;
}

/* concat - concatenates list1 and list2 to form a new list,
        and returns a pointer to this new list;
        Note: new list contains copies of all nodes in list1 and list2 */
Node *concat(Node *list1, Node *list2) {
  Node *Ptr = copy(list1);
  Node *Ptr2 = copy(list2);
  Node *list1Ptr = Ptr;
  if(Ptr == NULL)
    return Ptr2;
  if(list2 == NULL)
    return Ptr;
 /*Node **list2Ptr = list2;*/

  while(Ptr->next != NULL)
    {
      Ptr = Ptr->next;
    }
  Ptr->next = Ptr2;
  
  return list1Ptr;
}

/*************************************************************************
   DO NOT CHANGE THE FUNCTIONS BELOW. SEE airports.h FOR MORE INFORMATION.

   Do study the definitions though, to understand how they work.
*************************************************************************/

/* newNode - here is a utility function to create a new node;
    node's airport set to a copy of code, and next set to NULL;
    returns a pointer to the new node */
Node *newNode(AirportCode code) {
    Node *node;
    if ((node = (Node *)malloc(sizeof(Node))) != NULL) {
        strcpy(node->airport, code);
        node->next = NULL;
    }
    else {
        fprintf(stderr, "out of memory - terminating\n");
        exit(1);
    }
    return node;
}

/* append - creates a new Node and adds it to the end of the list */
void append(AirportCode code, Node **listPtr) {
    Node *n, *ptr;
    n = newNode(code);

    if (*listPtr == NULL)
        *listPtr = n;
        
    else {
        ptr = *listPtr;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = n;
    }
}

/* recycle - frees the node and any nodes linked to it */
void recycle(Node **listPtr) {
    if (*listPtr != NULL) {
        Node *n = *listPtr;
        Node *next;
        while(n != NULL) {
            next = n->next;
            free(n);
            n = next;
        }
        *listPtr = NULL;
    }
}

/* testp3.c - Test program for CS 16 Project 3.

   DO NOT RELY ON CHANGES TO THIS FILE - you will not turn it in.
   And beware that we are likely to use a different testing program
   to do the grading - so be sure your functions can handle any
   possible situation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airports.h"

void printList(Node *);

int main(int argc, char *argv[]) {
    Node *list1, *list2, *list3;
    list1 = list2 = list3 = NULL;

    /* use append to create list1 and print it */
    append("DUS", &list1);
    append("ORD", &list1);
    append("SAN", &list1);
    printf("list1 created by 3 appends: "); printList(list1);

    /* use insertFirst to create list2 and print it */
    insertFirst("LAX", &list2);
    insertFirst("DFW", &list2);
    insertFirst("JFK", &list2);
    printf("list2 created by 3 insertFirsts: "); printList(list2);

    /* test deleteFirst, and print revised list */
    deleteFirst(&list1);
    printf("list1 after delete first: "); printList(list1);

    /* test copy, and print the copy */
    list3 = copy(list1);
    printf("list3 copied from list1: "); printList(list3);

    /* clear the copy, and print both it and the original */
    recycle(&list3);
    printf("list3 after recycle: "); printList(list3);
    printf("list1 after list3 is recycled: "); printList(list1);

    /* test concat, and print the concatenated list */
    list3 = concat(list1, list2);
    printf("list3 now concatenated list1, list2: "); printList(list3);
    
    /* test reverse, and print all lists */
    reverse(&list3);
    printf("list3 after reverse: "); printList(list3);
    printf("list1 after list3 reversed: "); printList(list1);
    printf("list2 after list3 reversed: "); printList(list2);

    /* try some empty list operations - hope for no segmentation faults */
    recycle(&list3);
    deleteFirst(&list3);
    reverse(&list3);
    list2 = copy(list3);
    list1 = concat(list2, list3);
    printf("list1 should be empty: "); printList(list1);
    return 0;
}


/* printList - prints the airport codes in list order */
void printList(Node *list) {
    Node *n = list;
    putchar('(');
    while (n != NULL) {
        printf("%s", n->airport);
        n = n->next;
        if (n != NULL) printf(", ");
    }
    puts(")");
}

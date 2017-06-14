/* testp3a.c - Another test program for CS 16 Project 3.
 cmc, 3/6/2014 */

#include <stdio.h>
#include <stdlib.h>
#include "airports.h"

enum ch { BAD = 0, INFIRST, DEFIRST, COPY, CONCAT, REVERSE };
enum ch choice(void);
Node *getAcodes(void);
void printList(Node *);

int main(void) {
    Node *empty = NULL, *oneNode = NULL, *allAcodes = NULL, *temp;
    append("JFK", &oneNode);
    allAcodes = getAcodes();
    
    switch (choice()) {
        case INFIRST:
            insertFirst("SBA", &empty);
            printf("SBA added first to empty: "); printList(empty);
            insertFirst("SBA", &oneNode);
            printf("SBA added first to oneNode: "); printList(oneNode);
            insertFirst("SBA", &allAcodes);
            printf("SBA added first to allAcodes:\n"); printList(allAcodes);
            break;
        case DEFIRST:
            deleteFirst(&empty);
            printf("deleted first from empty: "); printList(empty);
            deleteFirst(&oneNode);
            printf("deleted first from oneNode: "); printList(oneNode);
            deleteFirst(&allAcodes);
            printf("deleted first from allAcodes:\n"); printList(allAcodes);
            break;
        case COPY:
            temp = copy(empty);
            printf("copy of empty: "); printList(temp);
            recycle(&temp);
            temp = copy(oneNode);
            printf("copy of oneNode: "); printList(temp);
            recycle(&temp);
            temp = copy(allAcodes);
            printf("copy of allAcodes:\n"); ;printList(temp);
            recycle(&temp);
            break;
        case CONCAT:
            temp = concat(empty, oneNode);
            printf("concat of empty, oneNode: "); printList(temp);
            recycle(&temp);
            temp = concat(oneNode, empty);
            printf("concat of oneNode, empty: "); printList(temp);
            recycle(&temp);
            temp = concat(allAcodes, oneNode);
            printf("concat of allAcodes, oneNode:\n"); printList(temp);
            recycle(&temp);
            break;
        case REVERSE:
            reverse(&empty);
            printf("reversed empty: "); printList(empty);
            reverse(&oneNode);
            printf("reversed oneNode: "); printList(oneNode);
            reverse(&allAcodes);
            printf("reversed allAcodes:\n"); printList(allAcodes);
            break;
        case BAD:
            /* function choice() should not allow to happen */
            break;
    }
    
    recycle(&empty);
    recycle(&oneNode);
    recycle(&allAcodes);
    return 0;
}

/* gets choice from user */
enum ch choice(void) {
    int num;
    enum ch result = BAD;
    printf("Function to test:\n");
    printf("1. insertFirst\n");
    printf("2. deleteFirst\n");
    printf("3. copy\n");
    printf("4. concat\n");
    printf("5. reverse\n");
    do {
        int count;
        printf("Enter test number: ");
        count = scanf("%d", &num);
        if (count == 1 && num > 0 && num < 6)
            result = num;
        else {
            if (count == 0) /* flush input buffer */
                while (getchar() != '\n')
                    ;
            printf("   Invalid choice - try again.\n");
        }
    } while(result == BAD);
    return result;
}


/* gets all airport codes starting with A from text file */
Node *getAcodes(void) {
    Node *list = NULL, *n;
    AirportCode code;
    
    FILE *in = fopen("allAcodes.txt", "r");
    if (in == NULL) {
        fprintf(stdout, "need a copy of allAcodes.txt in this directory\n");
        exit(1);
    }

    fscanf(in, "%s", code);
    list = newNode(code);
    n=list;
    while (fscanf(in, "%s", code) == 1) {
        n->next = newNode(code);
        n = n->next;
    }
    
    fclose(in);
    return list;
}

/* printList - prints the airport codes in list order */
void printList(Node *list) {
    Node *n = list;
    int ctr = 0, max = 10; /* to prevent really long output lines */
    putchar('(');
    while (n != NULL) {
        printf("%s", n->airport);
        n = n->next;
        if (n != NULL)
            printf(", ");
        if (++ctr > max) {
            putchar('\n');
            ctr = 0;
        }
    }
    puts(")");
}

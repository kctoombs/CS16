/* testlist.c - tests intlist.c for CS 16 Lab08 */

#include "intlist.h"

#include <stdio.h>

/* creates two lists (one empty), and does simple tests of list functions */
int main() {

    Node *list1 = NULL, *list2 = NULL;
    
    char *b[] = {"False", "True"}; /* for labels below */

    /* add data to list1 (first 10 powers of 2, for no particular reason) */
    int i;
    for (i = 1; i <= 512; i *= 2)
        append(i, &list1);

    /* print and test functions for list1 */
    printf("List: ");
    printList(list1);
    printf("\n   count: %d\n", count(list1));
    printf("   sum: %d\n", sum(list1));
    printf("   contains 1 ? %s\n", b[contains(1, list1)]);
    printf("   contains 32 ? %s\n", b[contains(32, list1)]);
    printf("   contains 512 ? %s\n", b[contains(512, list1)]);
    printf("   contains 17? ? %s\n", b[contains(17, list1)]);

    /* now test for empty list2 (just need one contains test though) */
    printf("Empty list: ");
    printList(list2);
    printf("\n   count: %d\n", count(list2));
    printf("   sum: %d\n", sum(list2));
    printf("   contains 1 ? %s\n", b[contains(1, list2)]);

    /* add tests for optional functions that you attempt to implement */

    
    freeNodes(&list1);
    freeNodes(&list2); /* in case your new tests add nodes to list2 */
    return 0;
}

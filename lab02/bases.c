/* bases.c - gets integer from user and displays in three bases
   Kenneth Toombs , Yuval Halperin 1/21/2014 */

#include <stdio.h>

int main()
{
    /* DECLARE AN APPROPRIATE VARIABLE */
    int x;

          
    /* PRINT A PROMPT: ASK USER TO ENTER AN INTEGER */
    printf("enter an integer:");


    /* GET THE VALUE FROM THE USER */
    scanf("%i", &x);


    /* DISPLAY VALUE IN DECIMAL, OCTAL AND HEX, WITH LABELS */
    printf("decimal: %d \n", x);
    printf("hex: %x \n", x);
    printf("octal: %o \n", x);


    /* EXIT NORMALLY */
    return 0;

}

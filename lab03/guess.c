/* guess.c - lets user try to guess a random number until success
   Yuval Halperin and Kenneth Toombs, January 28, 2014 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int target, max = 0, guess = 1;   /* use these variables below */

    /* HERE: GET A BETTER VALUE FOR max FROM THE USER:
       REPEAT AS NECESSARY UNTIL THE VALUE OF max IS GREATER THAN 1 */
    while(max < 10)
      {
	printf("Enter maximum value - must be greater than 1: ");
      scanf("%i", &max); 
       }    
           


    srand(time(NULL));
    target = 1 + rand() % max; /* random target value for user to guess */


    /* START REPETITION HERE:
       KEEP GOING AS LONG AS guess DIFFERS FROM target */
    do
    {
      
            printf("Guess a number between 1 and %d: ", max);
            scanf("%i", &guess); /* here is the user's guess */
	    
	    
	    
            if (guess == target)
                printf("Correct!\n");

            else { 
                /* HERE: REPLACE THE FOLLOWING STATEMENT WITH A SELECTION
                   STRUCTURE THAT PRINTS EITHER "Too high." OR "Too low."
                   AND ALSO PRINTS "Try again." */
              	 
	      
		if (guess < target)
		  printf("Too low. Try again. \n");
		if(guess > target)
		  printf("Too high. Try again. \n");
	      
		}
    }while(guess!=target);
	    /* printf("wrong\n");*/

    /* REMEMBER TO TERMINATE THE REPEATING BLOCK */


    return 0;
}

/* prints differences from average for all values entered
   Kenneth Toombs and Yuval Halperin, February 11, 2014 */

#include <stdio.h>


/* prototypes of functions to be pasted below main */
int isum(int x[], int n);
double avg(int x[], int n);

#define MAXN 100

int main(void) {
    int a[MAXN], i, n;
    double average, diff;

    /* fill array with data from user, and count items */
    printf("enter up to %d integers - end by non-integer:\n", MAXN);
    n = 0;
    while ( n < MAXN && scanf("%i", &a[n]) > 0 )
        ++n;


    /* SET average TO AVERAGE VALUE OF FIRST n ELEMENTS OF a */
    average = avg(a,n);



    /* print summary results and header for diffs */
    printf("average of %d values: %g\ndifferences from average:\n",
          n, average);


    /* USE A FOR LOOP: i = 0 TO n-1, AND ON EACH ITERATION,
           CALCULATE AND PRINT diff AS a[i] MINUS average */
    for(i=0; i<=n-1; i++)
{
      diff = a[i]-average;
         printf("%lf \n", diff);
    }



    return 0;
}

/* BE SURE COPIES OF isum AND avg FUNCTIONS ARE BELOW HERE */
/* Yuval Halperin, Kenneth Toombs, Feburary 11th */

/*returns sum of the first n values in x */

int isum(int x[], int n)
{
int i;
int sum=0;
for(i=0; i<n; i++)
   sum+=x[i];
   return sum;
}



 /* Yuval Halperin, Kenneth Toombs, February 11th, 2014 */
/* Takes the average of the first n values of an array */

double avg(int x[], int n)
{
double result = (double)isum(x,n) / n;
return result;
}

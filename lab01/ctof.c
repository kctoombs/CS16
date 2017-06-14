/* ctof.c - converts Celsius to Fahrenheit
  Kenneth Toombs, Yuval Halperan, 1/14/14 */

#include <stdio.h>

int main()
{
    /* DECLARE VARIABLES */
  double cTemp;
    printf("Enter a temperature in degrees C: ");
    scanf("%lf",&cTemp);
      
    /* CALCULATE/STORE FAHRENHEIT VALUE */
   double fTemp = ((cTemp*(9.0/5.0)) + 32);

    printf("%g degrees C is %g degrees F\n",
	   cTemp, fTemp);

    return 0;
}

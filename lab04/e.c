/* Kenneth Toombs and Yuval Halperin, Feb 4th,2014 */

/* calculates factorial of n as double for exponential function */
# include <stdio.h>

double dfactorial(int n){
    double result=1;
   
       if( n == 0 )
         printf("1");
 while(n > 0)
   {
     
      	  result*=n;
     	   n--;
   }

return result;
}
 
 int main(void)

 {
   double e=1;
   int n;
   {
     for (n=1; n<=170; n++)
       e+=(1/dfactorial(n));
   }

   printf("exp: %.8lf \n", e);

   return 0;
 }

/* Kenneth Toombs, Yuval Halperin*/
/* January 28th, 2014*/

int num;
srand(time(NULL));
do
 {
   num = 1 + rand()%100;
   printf("%d ", num);
} while (num%10 > 0);
 printf("\n");

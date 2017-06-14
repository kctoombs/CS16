/*
   counts.c - CS 16 Project 2
   Kenneth Toombs, Boris Sadykoff, 2/14/2014
*/

#include <stdio.h>
#include "common.h"


int main(int argc, char *argv[]) 
{


  if(argc == 1)
    {
  int i = 0,
  int total;
  int ASCII;
  int count[NUM] = {0};
  FILE *in = stdin, *out = stdout;
  char c;

  while(c != EOF)
    {
      c = getc(stdin);
      ASCII = c;
      count[ASCII]++;
      total++;
    }
    
  prHeader(out);
  for(i = 0; i <= 32; i++)
    {
      if(count[i] != 0)
	{
	  prCountStr(out, i, symbols[i], count[i]);
	}
    }

      for(i = 33; i <= 126; i++)
	{
	  if(count[i] != 0)
	    {
	      prCountChr(out, i, (char)i, count[i]);
	    }
 	}
	
	  if( i == 127 && count[i] != 0)
	    {
	      prCountStr(out, i, symbolDel, count[i]);
	    }
	 
       prTotal(out, total-1);
    }
  
	     
}


   if(argc > 1 )
    {
      int inCount = 0;
      int outCount = 0;
      int Count[NUM] = {0};
      int b;
   
      for(b = 1; b < argc; b++)
	{
	  if(*argv[b] != '-')
	    {
	      inCount = inCount + 1;
	      FILE *input = fopen(argv[b], "r");
	      if(input == NULL)
		{
		BADFILE(argv[b]);
		}
	      int a = 0;
	    
	      while((a = getc(in) != EOF))
		    Count[a]+=1;
		    
	    }

	}

	  if(outCount == 0)
	    {
	      int i;
	      prHeader(stdout);
	      
	      for( i = 0; i < FIRST; i++)
		{
		  if(Count[i] != 0)
		    prCountStr(stdout, i, symbols[i], Count[i]);
		}

	      if(Count[LAST] != 0)
		prCountStr(stdout, i, symbols[i], Count[i];

			   for(i = FIRST; i < LAST; i++)
			     {
			       if(Count[i] != 0)
				 prCountChr(stdout, i, (char)i, Count[i]);
			     }

	      int total = 0;
	      for( i = 0; i < LAST; i++)
		total += Count[i];
	      prTotal(stdout, total);

	      return 0;
	    }

	  if(*argv[b] == '-' && *(argv[b]+1) != 'o' )
	    {
	  
	  BADOPTION(argv[b+1]);
	    }
	  if(*argv[b] == '-' && *(argv[b]+1) == 'o' && *(argv[b]+2) == '\0' && (argc-1) == b)
	
	    {
	    
		MISSING;
	    }
	  if(*argv[b] == '-' && *(argv[b]+1) == 'o' && *(argv[b]+2) != '\0')
	    {

	      for(c = 2; c <= (argv[b]); c++)
		{
		  outFile[(c-2)] = *(argv[b]+c);
		}
	      FILE *output = fopen(outFile, "w");
	      if(output == NULL)
		{
		  BADFILE(outFile);
		}


	      else
		{
	          FILE* output = fopen(argv[(b+1)], "w");
		  if(output == NULL)
		    {
		      BADFILE(argv[(b+1)]);
		}
	    }
	      if(inCount == 0);
	      {
		int d = 0;
		while(d != EOF)
		  {
		    d = getchar();
		    Count[d]+=1;
		  }
	      }
	      if(outCount != 0)
		{
		  if(*argv[b] == '-' && *(argv[b]+1) == 'o' && *(argv[b]+2) != '\0')
		    {
		      for(c = 2; c<=(argv[b]); c++)
			{
			  outFile[(c-2)] = *(argv[b]+c);
			    }
		      FILE *output = fopen(outFile, "w");
		      prHeader(output);

		      int i;
		      for(i = 0; i < FIRST; i++)
			{
			  if(Count[i] != 0)
			    prCountStr(output, i, symbols[i], Count[i]);
			      }
		      if(Count[LAST] != 0)
			prCountStr(output, LAST, symbolDEL, Count[LAST]);
		      
		      for(i = FIRST; i < LAST; i++)
			{
			  if(Count[i] != 0)
			    prCountChr(output, i, char(i), Count[i]);
			}
		      int total = 0;
		      for(i = 0; i < LAST; i++)
			total += Count[i];
		      prTotal(output, total);
		    }

		  else
		    {
		      FILE* output = fopen(argv[(b+1)], "w");
		      prHeader(output);

		      int i;
		      for(i=0; i < FIRST; i++)
			{
			  if(Count[i] != 0)
			    prCountStr(output, i, symbols[i], Count[i]);
			}
			  if(Count[LAST] != 0)
			    prCountStr(output, LAST, symbolDel, Count[LAST]);

			  for(i = FIRST; i < LAST; i++)
			    {
			      if(Count[i] != 0)
				prCountChr(output, i, char(i), Count[i]);
			    }
			  int total = 0;
			  for(i = 0; i < LAST, i++)
			    total+= Count[i];
			  prTotal(output, total);
		    }
		  return 0;
		}

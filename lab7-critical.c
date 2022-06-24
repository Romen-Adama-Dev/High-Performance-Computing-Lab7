#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 500

int main()
{
   int square=0, number, i;
   int a[N];
	
   printf("Insert number:\n");
   scanf("%d",&number);

   //how to parallelize it with good final result?

   

   for(i=0;i<N;i++)
   {
	square+=number*number;
   printf("%d\n, a[i]");
   }

   square = a[0];
   #pragma omp parallel for num_threads(4)
   for (i = 1; i < N; i++){
      if(a[i] > square){
         #pragma omp critical{
            if(a[i] > square)
               square = a[i];
         }
      }
   }
   
   printf("Square=%d\n",square);
}
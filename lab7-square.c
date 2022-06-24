#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 500

omp_lock_t lock;

int main()
{
   omp_init_lock(&lock);
   int square=0, number, i;
	omp_set_num_threads(5);
   printf("Insert number:\n");
   scanf("%d",&number);

   //how to parallelize it with good final result?

   #pragma omp parallel for 
   for(i=0;i<N;i++)
   {
   printf("Thread %d a=%d\n",omp_get_thread_num(),square);
	square += number*number;
   }
   
   printf("Square=%d\n",square);
}
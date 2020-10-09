#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
 float sum = 0.0;
 int inf = atoi(argv[1]);
 int n=2;
 int k;
 #pragma omp parallel for reduction(+: sum)
 for( k=1 ; k<=inf ; k++) {
  sum += 1.0/pow(k,(double)n);
 }
 printf("sum %f\n",sum);
}

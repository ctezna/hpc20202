#include <stdio.h>
#include "omp.h"
#include <time.h>
#include <stdlib.h>
/* matrix multiply
 * *
 * * c[i][j]= a_row[i] dot b_col[j] for all i,j
 * * a_row[i] -> a[i][0 .. DIM-1]
 * * b_col[j] -> b[0 .. DIM-1][j]
 * *
 * */

int main(int argc, char const *argv[])
{
  int n = atoi(argv[1]);
  int a[n][n], b[n][n], c[n][n];
  int i,j,k;
  float dot;
for(i=0;i<n;i++) {
  for(j=0;j<n;j++) {
    dot=0.0;
    for(k=0;k<n;k++)
    dot += a[i][k]*b[k][j];
    c[i][j]=dot;
  }
}
}

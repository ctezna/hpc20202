#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char const *argv[])
{
    int pid, npr, i, n;
    double PI = 3.1415926536;
    double h,x, pi_loc, pi_glob, sum;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &npr);

    n = atof(argv[1]);

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    h = 1.0 / (double)n;
    sum = 0.0;
    for (i = pid; i < n; i += npr)
    {
        x = (i + 0.5) * h;
        sum += 4.0 / (1.0 + x * x);
    }
    pi_loc = h * sum;

    MPI_Reduce(&pi_loc, &pi_glob, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (pid == 0)
        printf("pi(+/-) = %.16f, error 			= %.16f\n", pi_glob, fabs(pi_glob - PI));
    MPI_Finalize();
}

#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
        int miRango;
        int size;
        int factorial;
        int ini,fin;
        int i;
        double resultado_local = 1.0;
        double total;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &miRango);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        if(miRango == 0) {
                printf("Ingrese un numero:\n");
                scanf("%d", &factorial);
        }

        MPI_Bcast(&factorial, 1, MPI_INT, 0, MPI_COMM_WORLD);

        if(miRango == 0) {
                ini = 1;
        } else {
                ini = miRango * (factorial / size) + 1;
        }
        if(miRango == (size - 1)) {
                fin = factorial;
        } else {
                fin = (miRango + 1) * (factorial / size);
        }

        for(i = ini; i <= fin; i++) {
                resultado_local = resultado_local * (double)i;
        }

        MPI_Reduce(&resultado_local, &total, 1, MPI_DOUBLE, MPI_PROD, 0, MPI_COMM_WORLD);

        if(miRango == 0) {
                printf("El factorial de %d es %f, y fue calculado usando %d proceso(s)\n", factorial, total, size);
        }

        MPI_Finalize();

        return 0;
}
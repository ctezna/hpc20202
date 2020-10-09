# Universidad EAFIT
# Curso ST0263 Tópicos Especiales en Telemática, 2020-2
# Profesor: Edwin Montoya M. – emontoya@eafit.edu.co y Alvaro Ospina - aeospinas@eafit.edu.co
#
# Laboratorio de MPI

* this lab is based on: https://computing.llnl.gov/tutorials/mpi/exercise.html

* some scripts were adapted for running on EAFIT DCA MPI Cluster

* compile all mpi examples:

        $ cd llnl-mpi-examples/mpi
        $ make -f Makefile.MPI.c

* compile all serial examples:

        $ cd llnl-mpi-examples/serial
        $ make -f Makefile.Ser.c

* run mpi examples:

        $ cd llnl-mpi-examples/mpi
        $ mpirun -f ../../hosts_mpi -n 4 ./mpi_array
        $
        $ mpirun -f ../../hosts_mpi -n 4 ./mpi_latency

* run serial examples:

        $ cd llnl-mpi-examples/serial
        $ ./ser_array
        $
        $ ./ser_head2D

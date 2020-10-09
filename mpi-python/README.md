# Universidad EAFIT
# Curso ST0263 Tópicos Especiales en Telemática, 2020-2
# Profesor: Edwin Montoya M. – emontoya@eafit.edu.co y Alvaro Ospina - aeospinas@eafit.edu.co
# Laboratorio de MPI en Python

## se debe tener instalada la libreria MPI4PY:

        $ pip install mpi4py

## ya se pueden ejecutar programas en python que utilicen MPI:

## Helloword

        $ cd mpi4py-examples
        $ mpiexec -f ../hosts_mpi -n 4 /opt/anaconda3/bin/python helloWorld_MPI.py

## correr los ejemplos del dir 'basic-examples'

        $ sh executor.sh

        o

        $ mpiexec -f ../../hosts_mpi -np 8  /opt/anaconda3/bin/python ./hello_world1.py

## corres los ejemplos del dir 'advanced-examples'      

        $ sh executor.sh

        o

        $ mpiexec -f ../../hosts_mpi -np 8  /opt/anaconda3/bin/python ./01-hello-world.py

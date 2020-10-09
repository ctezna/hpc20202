# Universidad EAFIT
# Curso ST0263 Tópicos Especiales en Telemática, 2020-2
# Profesor: Edwin Montoya M. – emontoya@eafit.edu.co y Alvaro Ospina - aeospinas@eafit.edu.co
# Laboratorio de MPI

# entrar al cluster:

## 1. conectar a la VPN

        $ ssh user-vpn@192.168.10.40
        Password: pass-vpn

## 2. verificar que se conecte a los 2 slaves SIN password.

        $ ssh user-vpn@192.168.10.41

SI le pide password alguno de los slaves anteriores, por favor realice el paso de la Instalación Manual de las claves. (numeral 3)

## 3. instalar las claves ssh para cada usuario (solo se hace una vez):

// conectar a master:

        $ ssh user-vpn@192.168.10.40
        Password: pass-vpn
        $ mkdir ~/.ssh
        $ ssh-keygen -t rsa -b 4096 -C "your_username@eafit.edu.co"
        // de enter a todas las opciones
        $
        $ cd .ssh
        $ cp id_rsa.pub authorized_keys
        $ scp ~/.ssh/id_rsa user-vpn@192.168.10.41:
        Password: pass-vpn
        $ scp ~/.ssh/id_rsa.pub user-vpn@192.168.10.41:
        Password: pass-vpn

// conectar a slave1:

        $ ssh user-vpn@192.168.10.41
        Password: pass-vpn        
        $ mkdir ~/.ssh
        $ cp ~/id_rsa* ~/.ssh
        $ cd ~/.ssh
        $ cp id_rsa.pub authorized_keys
        $ exit

// compilar en OpenMP

        $ gcc prog-omp.c -o prog-omp -fopenmp

// ejecutar en OpenMP (con 4 cores)

        $ export OMP_NUM_THREADS=4
        $ export OMP_DISPLAY_ENV='true'
        $ time ./prog-omp

// compilar en MPI con C

        $ mpicc prog-mpi-c -o prog-mpi

// ejecutar en MPI (4 procesos en 4 nucleos - si los hay -)

        $ time mpirun -f hosts -np 4 ./prog-mpi

# correr mpi en docker:

https://github.com/oweidner/docker.openmpi



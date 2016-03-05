#include <stdio.h>
#include <string.h>
#include <mpi.h>

const int MAX_STRING = 100;

int main ()
{
    char greeting [ MAX_STRING ];
    int comm_sz;
    int my_rank;

    MPI_Init ( NULL, NULL );
    MPI_Comm_size ( MPI_COMM_WORLD, &comm_sz );

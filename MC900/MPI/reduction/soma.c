/* C Example */
#include <stdio.h>
#include <mpi.h>
#include <math.h>

int main ( )
{
    int rank, size;
    int n, i;
    double vet[16];
    double myNumber; // auxiliar para recepção de dados
    double sum; // soma parcial
    // mod representa a fase que é dada, onde cada processo pode ser mapeado
    // pelo mod de seu rank
    int mod;

    MPI_Init ( NULL, NULL );
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);    /* get current process id */
    MPI_Comm_size (MPI_COMM_WORLD, &size);    /* get number of processes */

    // Inicializando vetor, rank 0 faz I/O
    if ( !rank )
    {
        // inicializando variáveis
        sum = 0;
        mod = 1;
        scanf ( " %d", &n );
        for ( i = 0; i < n; i++ )
        {
            scanf ( " %lf", &vet[i] );
        }
        // Todos necessitam saber o tamanho do vetor
        for ( i = 1; i < size; i++ )
            MPI_Send ( &n, 1, MPI_INT, i, 0, MPI_COMM_WORLD );

        // Cada elemento é passado de forma injetora para cada processador
        for ( i = 1; i < n; i++ )
        {
            MPI_Send ( &vet[i], 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD );
        }
        sum += vet [0];
    }
    else
    {
        sum = 0;
        MPI_Recv ( &n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );

        // Caso o rank extrapole o vetor
        if ( rank < n )
        {
            // recebendo dado do vetor
            MPI_Recv ( &myNumber, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
            mod = 1;
            sum += myNumber;
            // Mandando sua soma
            MPI_Send ( &sum, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD );
        }
    }

    // Caso o rank extrapole o vetor
    if ( rank < n )
    {
        // Enquanto rank 0 não possue a soma total
        while ( mod < n )
        {
            // Ativa a recepção e a soma para os processadores ativos na fase mod
            if ( rank % mod == 0 )
            {
                if ( rank + mod < n )
                {
                    MPI_Recv ( &myNumber, 1, MPI_DOUBLE, rank+mod, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
                    sum += myNumber;
                }

                // Atualizando mod
                mod <<= 1;
                if ( rank - mod >= 0 )
                {
                    MPI_Send ( &sum, 1, MPI_DOUBLE, rank-mod, 0, MPI_COMM_WORLD );
                }
            }
            else
                // Garantindo que todos os processadores saem do loop
                mod <<= 1;
        }
    }

    // rank 0 lida com I/O
    if ( !rank )
    {
        printf ( "%.2lf\n", sum );
    }
    MPI_Finalize();
    return 0;
}

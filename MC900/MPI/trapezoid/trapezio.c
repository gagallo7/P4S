/* C Example */
#include <stdio.h>
#include <sys/time.h>
#include <mpi.h>
#include <math.h>

/* funcao a ser calculada a integral */
double f(double x) {
	double y;

	y = exp(x);

	return y;
}

/* calcula a area sob a curva do inicio ate o fim passados como argumentos */
double Trap(double a, double b, double h, int trapCount) {
	double estimate, x;
	int i;

	estimate = (f(a) + f(b))/2.0;
	for(i=1;i<trapCount;i++) {
		x=a + i*h;
		estimate += f(x);
	}
	estimate = estimate*h;

	return estimate;
}

int main ( )
{
    int rank, size;
    int n, i;
    double myNumber; // auxiliar para recepção de dados
    double local_a, local_b, h;
    int local_n;
    double sum; // soma parcial
    double low, high;
    double total_sum;
    struct timeval start, end;
    long unsigned duration;
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
        mod = 1;
        scanf ( " %lf %lf %d", &low, &high, &n );
        gettimeofday ( &start, NULL );
        local_n = n/size;
        h = (high-low)/n;
        local_a = low + rank*local_n*h;
        local_b = local_a + local_n*h;
        sum = Trap ( local_a, local_b, h, local_n );
        total_sum = 0;
        //printf ( "ID: %d; Trap(%d,%lf,%lf,%lf,%d) = %lf\n", rank, rank, local_a, local_b, h, local_n, sum );
        // Todos necessitam saber o tamanho do vetor
        for ( i = 1; i < size; i++ )
        {
            MPI_Send ( &n, 1, MPI_INT, i, 0, MPI_COMM_WORLD );
            MPI_Send ( &low, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD );
            MPI_Send ( &high, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD );
        }
    }
    else
    {
        sum = 0;
        MPI_Recv ( &n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
        MPI_Recv ( &low, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
        MPI_Recv ( &high, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );

        // recebendo dado do vetor
        mod = 1;
        local_n = n/size;
        h = (high-low)/n;
        local_a = low + rank*local_n*h;
        local_b = local_a + local_n*h;

        sum = Trap ( local_a, local_b, h, local_n );
        //printf ( "ID: %d; Trap(%d,%lf,%lf,%lf,%d) = %lf\n", rank, rank, local_a, local_b, h, local_n, sum );
        // Mandando sua soma
        //MPI_Send ( &sum, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD );
    }

    MPI_Reduce ( &sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD );
    /*
        // Enquanto rank 0 não possue a soma total
        while ( mod < n )
        {
            // Ativa a recepção e a soma para os processadores ativos na fase mod
            if ( rank % mod == 0 )
            {
                if ( rank + mod < size )
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
    */

    // rank 0 lida com I/O
    if ( !rank )
    {
        gettimeofday ( &end, NULL );
        printf ( "%.5lf\n", total_sum );
        /* Calculando tempo de execução */
        duration = ( ( end.tv_sec * 1000000 + end.tv_usec ) - ( start.tv_sec * 1000000 + start.tv_usec ) );
        printf ( "%lu\n", duration );
    }
    MPI_Finalize();
    return 0;
}

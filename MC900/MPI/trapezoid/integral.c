/* 
 * Guilherme Alcarde Gallo
 * RA: 105008
 * */

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
    // variaveis locais
    double local_a, local_b, h;
    int local_n;
    double x;
    double sum; // soma parcial
    double total_sum; // soma total
    double low, high;
    struct timeval start, end;
    long unsigned duration;

    MPI_Init ( NULL, NULL );
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);    /* get current process id */
    MPI_Comm_size (MPI_COMM_WORLD, &size);    /* get number of processes */

    // Inicializando vetor, rank 0 faz I/O
    if ( !rank )
    {
        // inicializando variáveis
        scanf ( " %lf %lf %d", &low, &high, &n );

        // comecando a contar tempo de execucao
        gettimeofday ( &start, NULL );
        /*
        for ( i = 1; i < size; i++ )
        {
            MPI_Send ( &n, 1, MPI_INT, i, 0, MPI_COMM_WORLD );
            MPI_Send ( &low, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD );
            MPI_Send ( &high, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD );
        }
        */

        total_sum = 0;
    }

    // Comunicando a galera
    MPI_Bcast ( &n, 1, MPI_INT, 0, MPI_COMM_WORLD );
    MPI_Bcast ( &low, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
    MPI_Bcast ( &high, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );

    // formando conjunto de trapézio local para o rank 0
    local_n = n/size;
    h = (high-low)/n;
    local_a = low + rank*local_n*h;
    local_b = local_a + local_n*h;

    //sum = Trap ( local_a, local_b, h, local_n );
    // evitando chamada de função, para melhorar desempenho
    // inicializando sum
    sum = 0;

    // caso em que n não é múltiplo de 4
    // o último núcleo é o encarregado de fazer o cálculo adicional
    if ( rank == size-1 && n%size )
    {
        // corrigindo local_n e local_b
        local_n += n%size;
        local_b = high;
    }
    // Trap function
    sum = (f(local_a) + f(local_b))/2.0;
    for(i=1;i<local_n;i++) {
        x= local_a + i*h;
        sum += f(x);
    }
    sum = sum*h;

    // fazendo reduce de todas as somas locais
    MPI_Reduce ( &sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD );

    // rank 0 lida com I/O
    if ( !rank )
    {
        // fim da contagem de tempo
        gettimeofday ( &end, NULL );

        printf ( "%.5lf\n", total_sum );

        /* Calculando tempo de execução */
        duration = ( ( end.tv_sec * 1000000 + end.tv_usec ) - ( start.tv_sec * 1000000 + start.tv_usec ) );
        printf ( "%lu\n", duration );
    }
    MPI_Finalize();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void producer_consumer_parallel(int *buffer, int size, int *vec, int n, int nThreads )
{
	int i, j;
	long long unsigned int sum = 0;
    double tstart, tend, duration;

    tstart = omp_get_wtime();

    // Paralelizando a execução do laço, mas repartindo os
    // casos de produtor e consumidor em dois laços diferentes
    // de parallel for, a fim de aproveitar as threads já criadas,
    // criando dois grupos de threads oriundas da linha 17
#pragma omp parallel num_threads ( nThreads ) \
    default(none) shared(buffer, vec, size, n) private(i, j) \
    reduction (+:sum) 

	for(i=0;i<n;i++) 
    {
		if(i % 2 == 0)
        {	// PRODUTOR

            // Usando escalonamento guided para balancear melhor
            // a carga durante a execução de instâncias maiores
            // em que |Vetor|/numThreads é grande

#pragma omp for schedule ( guided )
			for(j=0;j<size;j++)
            {
				buffer[j] = vec[i] + j*vec[i+1];
			}
		}
		else
        {	// CONSUMIDOR
//#pragma omp for
#pragma omp for schedule ( guided )
			for(j=0;j<size;j++)
            {
				sum += buffer[j];
			}
		}
	}
    tend = omp_get_wtime();
    duration = tend - tstart;

	printf("%llu\n%lf\n",sum,duration);
}

void producer_consumer(int *buffer, int size, int *vec, int n) {
	int i, j;
	long long unsigned int sum = 0;

	for(i=0;i<n;i++) {
		if(i % 2 == 0) {	// PRODUTOR
			for(j=0;j<size;j++) {
				buffer[j] = vec[i] + j*vec[i+1];
			}
		}
		else {	// CONSUMIDOR
			for(j=0;j<size;j++) {
				sum += buffer[j];
			}
		}
	}
	printf("%llu\n",sum);
}

int main ()
{
    int nThreads, nIter, n;
    int i;

    scanf ( " %d %d %d", &nThreads, &nIter, &n );

    int* buffer = (int* ) calloc ( n, sizeof ( int ) );
    int* vec = (int* ) calloc ( nIter, sizeof ( int ) );

    for ( i = 0; i < nIter; i++ )
    {
        scanf ( " %d", &vec[i] );
    }

    //producer_consumer ( buffer, n, vec, nIter );
    producer_consumer_parallel ( buffer, n, vec, nIter, nThreads );
 

    // Limpando a memória
    free ( buffer );
    free ( vec );

    return 0;
}

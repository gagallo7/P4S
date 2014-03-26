#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void producer_consumer_parallel(int *buffer, int size, int *vec, int n, int nThreads )
{
	int i, j;
	long long unsigned int sum = 0;
    double tstart, tend, duration;

    tstart = omp_get_wtime();
#pragma omp parallel num_threads ( nThreads ) \
    default(none) shared(buffer, vec, size, n) private(i, j) \
    reduction (+:sum)
	for(i=0;i<n;i++) 
    {
		if(i % 2 == 0)
        {	// PRODUTOR
#pragma omp for
			for(j=0;j<size;j++)
            {
				buffer[j] = vec[i] + j*vec[i+1];
			}
		}
		else
        {	// CONSUMIDOR
#pragma omp for
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
    int* vec = (int* ) calloc ( n, sizeof ( int ) );

    for ( i = 0; i < n; i++ )
    {
        scanf ( " %d", &vec[i] );
    }

//    producer_consumer ( buffer, n, vec, nIter );
    producer_consumer_parallel ( buffer, n, vec, nIter, nThreads );

    return 0;
}

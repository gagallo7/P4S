#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

/* Estrutura para ser usado como argumento 
 * das threads min, max, h etc */
typedef struct mmh
{
    int min;
    int max;
    int h;
    int rank;
    double gap;
    double * val;
    int * vet;
    int size;
} composite
; 

/* Barreira para região crítica, usando mutex */
pthread_mutex_t barrier;

void * binCount ( void * mMh )
{
    composite c = * ( ( composite * ) mMh );
    int j;
    double * val = c.val;
    double aux;
    double min = c.min, gap = c.gap;

    //printf ( "min %d, max %d, rank %d, gap %lf, size %d, val* %p\n", c.min, c.max, c.rank, c.gap, c.size, c.val );

	for(j= c.rank; j < c.size;j++) {

        /* Calculando em qual bin o valor está */
        aux = ( double ) ( val[j] - min ) / gap ;
        /* Indexação começa em zero */
        aux = ceil ( aux )-1;

        pthread_mutex_lock ( &barrier );
        /* ------- REGIÃO CRÍTICA -------- */
        c.vet [ (int) aux ]++;      /* Cast para inteiro ( índice de vetor ) */
        /* ------- REGIÃO CRÍTICA -------- */
        pthread_mutex_unlock ( &barrier );
	}

    /* Liberando argumentos */
    free ( mMh );
    return NULL;
}

/* histograma paralelo */
void parallel_count (double min, double max, int * vet, int nbins, double h, double * val, int nval, int nthreads )
{
	int j;

    /* Ideia geral: dividir o vetor de dados entre 
     * as threads, ao estilo parallel for de OpenMP */
    int ratio = nval / nthreads;

    pthread_t *th_list = ( pthread_t * ) malloc ( sizeof ( pthread_t ) * nbins );
    
	for(j=0;j < nthreads; j++ ) {
        /* Guardando valores importantes para cada thread */
        composite * mMh = ( composite * ) malloc ( sizeof ( composite ) );
        //*mMh = { min, max, h, j, nval, val, vet };
        mMh->min = min;
        mMh->rank = ratio*j;
        mMh->gap = h;
        mMh->val = val;
        mMh->vet = vet;
        /* size guarda até onde a thread vai processar no
         * vetor de dados */
        mMh->size = (j+1) * ratio % ( nval + 1 );

        /* Criando as threads */
        pthread_create ( &th_list [j], NULL, binCount, (void * ) mMh );
    }
     
    /* Destruindo as threads */
	for(j=0;j < nthreads; j++ ) {
        pthread_join ( th_list [j], NULL );
    }

    free ( th_list );
}

int * count(double min, double max, int * vet, int nbins, double h, double * val, int nval) {
	int i, j, count;
	double min_t, max_t;

	for(j=0;j<nbins;j++) {
		count = 0;
		min_t = min + j*h;
		max_t = min + (j+1)*h;
		for(i=0;i<nval;i++) {
			if(val[i] <= max_t && val[i] > min_t) {
				count++;
			}
		}

		vet[j] = count;
	}

	return vet;
}

int main ()
{
    int nthreads, n, bins, i;

    struct timeval start, end;

    scanf ( " %d %d %d", &nthreads, &n, &bins );

    int * bin = ( int * ) calloc ( bins + 1, sizeof ( int ) );
    double * vet = ( double * ) calloc ( n, sizeof ( double ) );
    double max , min;
    double gap;
    long unsigned duration;
    double j;

    scanf ( " %lf", &vet[0] );
    max = min = vet[0];
    for ( i = 1; i < n; i++ )
    {
        scanf ( " %lf", &vet[i] );
        if ( max <  vet[i] )
        {
            max = vet[i];
        }
        if ( min > vet[i] )
        {
            min = vet [ i ];
        }

    }

    min = floor ( min );
    max = ceil ( max );
    gap = (max-min)/bins;

    /* ~~~~~~~~~ // ~~~~ */

    gettimeofday ( &start, NULL );
    parallel_count ( min, max, bin, bins, gap, vet, n, nthreads );
    //count ( min, max, bin, bins, gap, vet, n );
    gettimeofday ( &end, NULL );

    /* Imprimindo resultado, excluindo espaço da
     * impressão de último item */
    for ( j = min; 
            fabs ( max - j ) > 10e-7;  /* valor absoluto < Epsilon
                                        * cálculo numérico */
            j += gap )
    {
        printf ( "%.2lf ", j );
    }
    printf ( "%.2lf\n", max );

    for ( i = 0; i < bins-1; i++ )
    {
        printf ( "%d ", bin[i] );
    }
    printf ( "%d\n", bin[bins-1] );

    /* Calculando tempo de execução */
    duration = ( ( end.tv_sec * 1000000 + end.tv_usec ) - ( start.tv_sec * 1000000 + start.tv_usec ) );

    printf ( "%lu\n", duration );

    /* Liberando memória alocada */
    free ( vet );

    return 0;

}


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>


pthread_mutex_t mutex;

long long int nthreads;
long long int chances;
long long int circle = 0;

typedef struct Arg
{
    int rank;
    unsigned int iterations;
} argList;

void monteCarloSerial( int max )
{
    int i;
    
    // Variável auxiliar para aumentar randomicidade
    unsigned int j;

    for ( i = 0; i < max; i++ )
    {
        // Gerando números aleatórios reentrantes com
        // rand_r ( unsigned int * )
        double x = rand_r (&j);
        double y = rand_r (&j);

        // Gerando números entre 0 e 1
        x /= RAND_MAX;
        y /= RAND_MAX;

        //printf ( "(%u %d)   %lf %lf \n", i, max, x, y );
        double distSq = x*x + y*y;


        if ( distSq <= 1 )
        {
            circle++;
        }
    }

}

void * monteCarlo ( void * args )
{
    argList * a = ( argList * ) args;
    unsigned int max = a->iterations;
    unsigned int i;
    long long int myCircle = 0;
    
    // Variável auxiliar para aumentar randomicidade
    unsigned int j = a->rank;

    for ( i = 0; i < max; i++ )
    {
        // Gerando números aleatórios reentrantes com
        // rand_r ( unsigned int * )
        double x = rand_r (&j);
        double y = rand_r (&j);

        // Gerando números entre 0 e 1
        x /= RAND_MAX;
        y /= RAND_MAX;

        //printf ( "(%u %d)   %lf %lf \n", i, max, x, y );
        double distSq = x*x + y*y;


        if ( distSq <= 1 )
        {
            myCircle++;
        }
    }

    pthread_mutex_lock ( & mutex );
    /* ------- REGIÃO CRÍTICA -------- */
    circle += myCircle;
    /* ------- REGIÃO CRÍTICA -------- */
    pthread_mutex_unlock ( & mutex );
    // Liberando memória para argumentos
    free ( args );
    return NULL;
}

int main ()
{
    int i;
    long unsigned duration;
    struct timeval start, end;

    /* Lendo entrada */
    scanf ( " %lli %lli", &nthreads, &chances );

    /* Criando threads */
    pthread_t * threadList = ( pthread_t * ) malloc ( nthreads * sizeof ( pthread_t ) );

    /*
    gettimeofday ( &start, NULL );
    monteCarloSerial ( chances );
    gettimeofday ( &end, NULL );
    duration = ( ( end.tv_sec * 1000000 + end.tv_usec ) - ( start.tv_sec * 1000000 + start.tv_usec ) );
    printf ( "Serial: %lu\n", duration );
    */


    circle = 0;
    /* Iniciando cronômetro */
    gettimeofday ( &start, NULL );
    for ( i = 0; i < nthreads; i++ )
    {
        argList * pa = ( argList * ) malloc ( sizeof ( argList ) );
        pa->rank = i;
        pa->iterations = chances / nthreads;
        pthread_create ( &threadList [i], NULL, monteCarlo, (void *) pa );
    }

    for ( i = 0; i < nthreads; i++ )
    {
        pthread_join ( threadList [i], NULL );
    }

    /* Parando cronômetro */
    gettimeofday ( &end, NULL );

    /* Calculando tempo de execução */
    duration = ( ( end.tv_sec * 1000000 + end.tv_usec ) - ( start.tv_sec * 1000000 + start.tv_usec ) );


    //printf ( "circle %lli\t chances %lli\n", circle, chances );
    double area = 4*(double)circle/chances;

    /* Saída */
    printf ( "%lf\n", area );
    printf ( "%lu\n", duration );

    free ( threadList );

    return 0;
}


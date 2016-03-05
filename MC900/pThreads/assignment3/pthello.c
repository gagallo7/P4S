#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * hello ( void * );

int main ( int argc, char* argv[] )
{
    long thread, thread_count, i;
    pthread_t* thread_list;
    
    thread_count = strtol ( argv[1], NULL, 10 );

    thread_list = ( pthread_t * ) malloc ( thread_count * sizeof ( pthread_t ) );
    
    for ( i = 0; i < thread_count; i++ )
    {
        pthread_create ( &thread_list [i], NULL, hello, (void*) i );
    }

    printf ( "hello from fodao!\n" );

    
    for ( i = 0; i < thread_count; i++ )
    {
        pthread_join ( thread_list [ i ], NULL );
    }

    return 0;
}

void * hello ( void * myrank )
{
   long rank = (long ) myrank;

   printf ( "Ae, sou %i, vai encarar?\n", rank );
}

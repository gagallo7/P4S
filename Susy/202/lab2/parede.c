
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int paredesDerrubadas;

struct Fila;
typedef struct Fila fila;

struct Fila
{
    int x, y;
    fila * next;
    fila * last;
};

fila * criaFila ( int x, int y )
{
    fila * raiz = (fila *) malloc ( sizeof ( fila ) );
    raiz->x = x;
    raiz->y = y;
    raiz->next = NULL;
    raiz->last = raiz;

    return raiz;
}

fila * insereNo ( fila * raiz, int x, int y )
{
    if ( raiz != NULL )
    {
        fila * last = raiz->last;
        fila * novo = criaFila ( x, y );        
        last->last = last->next = novo;
        return raiz;
    }
    
    return criaFila ( x, y );
}

char extraiElementoFila ( fila * raiz, char ** planta )
{
    assert ( raiz != NULL );

    char elem = planta [ raiz->x ] [ raiz->y ];

    fila * tmp = raiz;

    raiz = raiz->next;
    if ( raiz->last == tmp )
    {
        raiz->last = raiz;
    }

    return elem;
}

void imprimeFila ( fila * raiz )
{
    while ( raiz != NULL )
    {
        printf ( "%d %d\n", raiz->x, raiz->y );
        raiz = raiz->next;
    }
}

void liberaFila ( fila * raiz )
{
    while ( raiz != NULL )
    {
        fila * tmp = raiz;
        raiz = raiz->next;
        free ( tmp );
    }
}

int contar ( char ** planta, int x, int y )
{
    if ( planta [ x ] [ y ] == '.' )
    {
        return 0;
    }
    return 1;
}

int contarTudo ( char ** planta, int x, int y )
{
    printf ( "\n\n%d %d\n", x, y );
    printf ( "%c %c\n", planta [x][y], planta [x][y+1] );
    printf ( "%c %c\n", planta [x+1][y], planta [x+1][y+1] );
    return contar ( planta, x, y ) + contar ( planta, x + 1, y ) +
        contar ( planta, x, y + 1 ) + contar ( planta, x + 1, y + 1 );
}



void enfileirarParedesSuspeitas ( char ** planta, int x, int y, 
                                    fila * f )
{
    int nParedes = contarTudo ( planta, y, x );

    if ( nParedes == 1 )
    {
        printf ( "--%d %d \n", y, x ); 
        f = insereNo ( f, y, x );
    }
}

void analisaLinha ( int y, int x, int xMax, char ** planta, fila * f )
{
    if ( x >= xMax )
    {
        return;
    }
    
    enfileirarParedesSuspeitas ( planta, x, y, f );

    analisaLinha ( y, x + 1, xMax, planta, f );
}

void derrubaParede ( int x, int y, char ** planta, fila * f )
{
    if ( planta [x][y] == '*' )
    {
        planta [x][y] = '.';
    }
    else if ( planta [x+1][y] == '*' )
    {
        planta [x+1][y] = '.';
        ++x;
    }
    else if ( planta [x][y+1] == '*' )
    {
        planta [x][y+1] = '.';
        ++y;
    }
    else 
    {
        planta [x+1][y+1] = '.';
        ++x;
        ++y;
    }

    ++paredesDerrubadas;

    enfileirarParedesSuspeitas ( planta, x-1, y-1, f );
    enfileirarParedesSuspeitas ( planta, x, y-1, f );
    enfileirarParedesSuspeitas ( planta, x-1, y, f );
}

void analisaTudo ( int m, int n, char ** planta, fila * f )
{
    int i;
    for ( i = 1; i < m-1; ++i )
    {
        analisaLinha ( i, 1, n-2, planta, f );
    }
}


int achaTamanho ( char ** planta, char ** mask, int x, int y, int xMax, int yMax )
{
    if ( x >= xMax || y >= yMax )
    {
        return 0;
    }

    // Nas bordas só há paredes
    if ( x == 0 || y == 0 )
    {
        return 0;
    }

    // Evitando repeticoes
    mask [ x ] [ y ] = 1;

    int tamanho = 1;
    if ( mask [ x+1 ] [ y ] == 0 )
        if ( planta [ x+1 ] [ y ] == '.' )
        {
            tamanho += achaTamanho ( planta, mask, x+1, y, xMax, yMax );
        }

    if ( mask [ x ] [ y+1 ] == 0 )
        if ( planta [ x ] [ y+1 ] == '.' )
        {
            tamanho += achaTamanho ( planta, mask, x, y+1, xMax, yMax );
        }

    if ( mask [ x-1 ] [ y ] == 0 )
        if ( planta [ x-1 ] [ y ] == '.' )
        {
            tamanho += achaTamanho ( planta, mask, x-1, y, xMax, yMax );
        }

    if ( mask [ x ] [ y-1 ] == 0 )
        if ( planta [ x ] [ y-1 ] == '.' )
        {
            tamanho += achaTamanho ( planta, mask, x, y-1, xMax, yMax );
        }

    return tamanho;
}

int numComodos ( char ** planta, char ** mask, int xMax, int yMax )
{
    int num = 0;
    int i = 1;
    int j = 1;
    fila * f = NULL;
    int tamanho;

    for ( ; i < xMax; ++i )
    {
        printf ( "I atualizado!!\n\n\n" );
        for ( ; j < yMax; ++j )
        {
            printf ( "(%d,%d) (%d,%d)\n", i, j, xMax, yMax );
            if ( mask[i][j] == 0 )
            {
                if ( planta [i][j] == '.' )
                {
                    tamanho = achaTamanho ( planta, mask, i, j, xMax, yMax );     
                    // Usando somente 1 elemento da fila
                    // de pares de inteiro
                    f = insereNo ( f, tamanho, 0 );
                    printf ( "Cômodo %d: %d m2\n", num+1, tamanho );
                    ++num;
                }

                // Quando for parede, marcar que
                // esta posição já foi visitada
                mask [i][j] = 1;
            }
        }
    }

    printf ( "Tamanho dos comodos: " );
    imprimeFila ( f );
    printf ( "\nNumero de comodos: %d.\n", num );

    return num;
}

int main ()
{
    fila * teste = NULL;
    teste = insereNo ( teste, 3, 4 );
    teste = insereNo ( teste, 4, 5 );

    int m, n;
    int i, j;
    scanf ( " %d %d", &m, &n );
    char ** planta = (char**) calloc ( m, sizeof ( char* ) );
    char ** mask = (char**) calloc ( m, sizeof ( char* ) );
    for ( i = 0; i < m; ++i )
    {
        planta [i] = ( char * ) calloc ( n, sizeof ( char ) );
        mask [i] = ( char * ) calloc ( n, sizeof ( char ) );
    }

    for ( i = 0; i < m; ++i )
    {
        for ( j = 0; j < n; ++j )
        {
            scanf ( " %c", &planta [i][j] );
        }
    }

    for ( i = 0; i < m; ++i )
    {
        for ( j = 0; j < n; ++j )
        {
            printf ( "%c", planta [i][j] );
        }
        printf ( "\n" );
    }

    //printf ( "Tamanho: %d\n\n", achaTamanho ( planta, mask, 1, 1, m-1, n-1 ) );
    numComodos ( planta, mask, m-1, n-1 );

    fila * f = NULL;

    // Enfileira em f todos os quadrados 2x2 que incluem alguma
    // parede a ser destruída 
    analisaTudo ( m, n, planta, f );

    fila * g = f;

    while ( g != NULL )
    {
        if ( contarTudo ( planta, g->x, g->y ) )
        {
            derrubaParede ( g->x, g->y, planta, f );
        }
    }

    liberaFila ( f );
    /*
  */
    for ( i = 0; i < m; ++i )
    {
        for ( j = 0; j < n; ++j )
        {
            printf ( "%c", planta [i][j] );
        }
        printf ( "\n" );
    }


    imprimeFila ( teste );
    for ( i = 0; i < m; ++i )
    {
        for ( j = 0; j < n; ++j )
        {
            printf ( "%c", planta [i][j] );
        }
        printf ( "\n" );
    }

    for ( i = 0; i < m; ++i )
    {
        free (planta [i]);
    }
    free ( planta );
    liberaFila ( teste );

    return 0;
}

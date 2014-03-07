#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double count_sort_parallel ( double a[], int n, int tcount ) 
{
	int i, j, count;
	double *temp;
	double start, end, duracao;

	temp = (double *)malloc(n*sizeof(double));

	start = omp_get_wtime();
	for (i = 0; i < n; i++) 
    {
		count = 0;
#pragma omp parallel for num_threads (tcount) \
        default ( none ) reduction (+:count) \
        private ( n, i, j, a ) shared ( temp )
		for (j = 0; j < n; j++)
        {
			if (a[j] < a[i])
            {
				count++;
            }
			else if (a[j] == a[i] && j < i)
            {
				count++;
            }
        }
		temp[count] = a[i];
	}
	end = omp_get_wtime();

	duracao = end - start;

	memcpy(a, temp, n*sizeof(double));
	free(temp);

	return duracao;
}

double count_sort_serial(double a[], int n) {
	int i, j, count;
	double *temp;
	double start, end, duracao;

	temp = (double *)malloc(n*sizeof(double));

	start = omp_get_wtime();
	for (i = 0; i < n; i++) {
		count = 0;
		for (j = 0; j < n; j++)
			if (a[j] < a[i])
				count++;
			else if (a[j] == a[i] && j < i)
				count++;
		temp[count] = a[i];
	}
	end = omp_get_wtime();

	duracao = end - start;

	memcpy(a, temp, n*sizeof(double));
	free(temp);

	return duracao;
}

int main ()
{
    double v[20001];
    double v2[20001];

    int nthreads, n;
    int i;

    scanf ( " %d %d", &nthreads, &n );

    for ( i = 0; i < n; i++ )
    {
        scanf ( " %lf", &v[i] );
    }

    memcpy ( v2, v, n*sizeof(double) );

    double time = count_sort_serial ( v, n );

    for ( i = 0; i < n; i++ )
    {
        printf ( " %.2lf", v[i] );
    }

    printf ( "\n%lf\n", time );

    time = count_sort_parallel ( v2, n, nthreads );

    for ( i = 0; i < n; i++ )
    {
        printf ( " %.2lf", v2[i] );
    }

    printf ( "\n%lf\n", time );

    return 0;
}

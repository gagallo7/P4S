/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include "common.h"

void cpu_stencil(float c0,float c1, float *A0,float * Anext,const int nx, const int ny, const int nz)
{

    int i, j, k;
    int minI, minJ, minK;
    int bi, bj, bk;

    // Paralelizando laço externo
#pragma omp parallel for num_threads (8) default ( none ) \
    private (i, k, j, bi, bj, bk, minI, minJ, minK) shared (A0, Anext, c0, c1 )

    // Loop interchange + Loop tiling (BLK)
    for ( bj = 1; bj < ny-1; bj += BLK )
    {
        minJ = (ny - 1) < (bj + BLK) ? ny - 1 : bj + BLK;
        for ( j = bj; j < minJ; j++ )
        {
            //for(j=1;j<ny-1;j++)
            {
                for ( bk = 1; bk < nz-1; bk += BLK )
                {
                    minK = (nz - 1) < (bk + BLK) ? nz - 1 : bk + BLK;
                    for ( k = bk; k < minK; k++ )
                        //for(k=1;k<nz-1;k++)
                    {
                        for ( bi = 1; bi < nx - 1; bi += BLK )
                        {
                            minI = (nx - 1) < (bi + BLK) ? nx - 1 : bi + BLK;
                            for ( i = bi; i < minI; i++ )
                                //for(i=1;i<nx-1;i++)
                            {
                                Anext[Index3D (nx, ny, i, j, k)] = 
                                    (A0[Index3D (nx, ny, i, j, k + 1)] +
                                     A0[Index3D (nx, ny, i, j, k - 1)] +
                                     A0[Index3D (nx, ny, i, j + 1, k)] +
                                     A0[Index3D (nx, ny, i, j - 1, k)] +
                                     A0[Index3D (nx, ny, i + 1, j, k)] +
                                     A0[Index3D (nx, ny, i - 1, j, k)])*c1
                                    - A0[Index3D (nx, ny, i, j, k)]*c0;
                            }
                        }
                    }
                }
            }
        }
    }
}



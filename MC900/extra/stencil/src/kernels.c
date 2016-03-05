/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include "common.h"
#define BLOCK 16

void cpu_stencil(float c0,float c1, float *A0,float * Anext,const int nx, const int ny, const int nz)
{

  	int i, j, k;
  	int jk, kk;
	for(i=1;i<nx-1;i++)
		
		for(jk=1;jk<ny-1;jk+=BLOCK)

			for(kk=1;kk<nz-1;kk+=BLOCK)
				
				for(j=jk;j<jk+BLOCK;j++)

					for(k=kk;k<kk+BLOCK;k++)
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



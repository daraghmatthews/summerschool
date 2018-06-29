
#include <stdio.h>
#include <omp.h>



#define NX 102400


int main(void)
{
    long vecA[NX];
    long sum, psum, sumex;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i + 1;
    }

    sumex = (long) NX * (NX + 1) / ((long) 2);
    printf("Arithmetic sum formula (exact):                  %ld\n",
           sumex);

    sum = 0.0;
    /* TODO: Parallelize computation */
	
	#pragma omp parallel shared(vecA, sum) private(i, psum) 
    	{
	psum = 0;

	#pragma omp for 
	for (i = 0; i < NX; i++) {
        	psum += vecA[i];
    	}

	#pragma omp critical(add_all)
	sum += psum;
	}

    printf("Sum: %ld\n", sum);

    return 0;
}

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
 	
	int tnum, num_t;

	#pragma omp parallel private(tnum)
    	{

	tnum = omp_get_thread_num();
        printf("Howya, Im thread number %i\n", tnum);

	#pragma omp master
	{
	num_t = omp_get_num_threads();
        printf("Howya, Im thread number %i and the total numnber of threads is %i\n", tnum, num_t);
	}


    	}

    	return 0;
}

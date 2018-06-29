#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
 	
	int tnum, num_t;

	#pragma omp parallel private(tnum)
    	{

	tnum = omp_get_thread_num();
        printf("Howya, Im thread number %i\n", tnum);


	if((tnum + 1) % 2 == 0){ 

		#pragma omp critical(critical_test)
		{
        	printf("Inside IF, Im thread number %i\n", tnum);
		}
	}

    	}

    	return 0;
}

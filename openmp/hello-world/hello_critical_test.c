#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[])
{
 	
	int tnum, num_t;
	long i, cnt;
	char filename[] = "out.txt";
	FILE *fp;
    

    	if ((fp = fopen(filename, "w")) == NULL) {
        	fprintf(stderr, "Could not open file: %s\n", filename);
    	}

	cnt = 0;

	#pragma omp parallel private(tnum) firstprivate(cnt)
    	{

	tnum = omp_get_thread_num();

	struct tm *timenow;
	time_t now = time(NULL);
	timenow = gmtime(&now);
//	strftime(outname, sizeof(outname), "parentage_results_%Y%m%d.txt", timenow);
	char time_string[30];
	
	#pragma omp for
	for(i = 0; i < 100000; i++){
		
		cnt++;

		if(cnt == 15000){
			strftime(time_string, sizeof(time_string), "%M%S%N", timenow);
			printf("thread num %i @ %s\n", tnum, time_string);
		}

		if((tnum + 1) % 2 == 0){ 

			#pragma omp critical(critical_test)
			{
    			fprintf(fp, "thread no: %d\n", tnum);

			}
		}
	}
    	printf("cnt is %d\n", cnt); 
	}

    	return 0;
}

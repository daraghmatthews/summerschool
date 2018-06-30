#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	int rank, total_num;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &total_num);

	printf("Hello world, im process num %i of %i\n", rank, total_num);

	MPI_Finalize();

	return 0;
}

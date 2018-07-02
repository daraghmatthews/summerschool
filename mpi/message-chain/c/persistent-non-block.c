#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, myid, ntasks, dest, src;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status statuses[2];
    MPI_Request reqs[2];

    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message buffers */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }


    if(myid < ntasks - 1){
	dest = myid + 1;
    }else{
	dest = MPI_PROC_NULL;
    }

    if(myid > 0){
	src = myid - 1;
    }else{
	src = MPI_PROC_NULL;
    }


    /* Start measuring the time spent in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

    /* Send and receive messages as defined in exercise */
    
    MPI_Recv_init(receiveBuffer, size, MPI_INT, src, MPI_ANY_TAG, MPI_COMM_WORLD, &reqs[0]);

    MPI_Send_init(message, size, MPI_INT, dest, myid+1, MPI_COMM_WORLD, &reqs[1]);

    MPI_Startall(2, reqs);

    MPI_Waitall(2, reqs, statuses);


    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}

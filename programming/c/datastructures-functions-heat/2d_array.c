#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
	double array[NX][NY];

    // Initialize first the zeros
	for(i=0;i<NX;i++){
		for(j=0;j<NY;j++){
			array[i][j] = 0;

		}
	}

    // Initial conditions for left and right
	for(i=0;i<NY;i++){
		array[i][0] = 20.0;
		array[NX][i] = 85.0;
	}

    // and top and bottom boundaries
	for(j=1;j<NX;j++){
		array[0][j] = 70.0;
		array[NY][j] = 5.0;	

	}

    return 0;
}

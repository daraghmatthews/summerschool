#include "field.h"


void init_field(field *f, int nx, int ny){

	f->nx = nx;
	f->ny = ny;
	f->dx = DX;
	f->dy = DY;
	f->dx2 = DX * DX;
	f->dy2 = DY * DY;


    	int i, j;
   
   	 // First initalize the inner values to zero
    	for (i = 1; i <= f->nx; i++) {
        	for (j = 1; j <= f->ny; j++) {
            		f->data[i][j] = 0.0;
        	}
    	}

	// Initial conditions for left and right
    	for (i = 0; i <= f->nx; i++) {
        	f->data[i][0] = 30.0;
        	f->data[i][f->ny + 1] = -10.0;
   	 }
    
	// left and right
    	for (j = 0; j <= f->ny; j++) {
        	f->data[0][j] = 15.0;
        	f->data[f->ny + 1][j] = -25.0;
    	}
}


// compute the Laplacian of the field
void laplacian(field *f){		
	
	// for the results
	double laplacian[NX+2][NY+2];
	int i,j;

	for(i=1; i <= f->nx; i++){
		for(j=1; j <= f->ny; j++){
			laplacian[i][j] = (f->data[i-1][j] - 2.0 * f->data[i][j] + f->data[i+1][j]) / 
				(f->dx * f->dy)
			+ (f->data[i][j-1] - 2.0 * f->data[i][j] + f->data[i][j+1]) / (f->dx * f->dy);			
		}
	}

	for(i=1; i <= f->nx; i++){
		for(j=1; j <= f->ny; j++){
			f->data[i][j] = laplacian[i][j];
	
		}
	}

}


void print_field(field *f){

	int error_code;

	error_code = save_png((double *) f->data, f->nx+2, f->ny+2, "datastructures_functions_heat-a_b.png", 'c');

    	if (error_code == 0) {
        	printf("Wrote the output file datastructures_functions_heat-a_b.png\n");
    	} else {
        	printf("Error while writing output file datastructures_functions_heat-a_b.png\n");
    	}
}



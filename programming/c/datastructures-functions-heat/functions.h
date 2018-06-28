#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "field.h"
#include "pngwriter.h"


#define DX 0.01
#define DY 0.01


void init_field(field *f, int nx, int ny);
void laplacian(field *f);		
void print_field(field *f);

#endif

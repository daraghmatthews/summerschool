#ifndef FIELD_H
#define FIELD_H

#define NX 256
#define NY 256

typedef struct{
	int nx, ny;
	double dx, dy, dx2, dy2;
	double data[NX+2][NY+2];
}field;


#endif

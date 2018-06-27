#include <stdio.h>
void add_one_to_both(int *c, int *d);


int main(int argc, char *argv[])
{
    	int a, b;

	a = 10;
	b = 20;

	add_one_to_both(&a, &b);

    	printf("a = %d, b = %d\n", a, b);

    	return 0;
}


void add_one_to_both(int *c, int *d){
	(*c)+=1;
	(*d)++;

}

#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare integers, floats, and doubles
	int a = 1, b = 3, c = 5;
	int i = 17;
	float f = 5.0;
	double d = 6.9987;	


    // evaluate expressions, e.g. c = a + 2.5 * b
    // and print out results. Try to combine integers, floats
    // and doubles and investigate what happens in type conversions
	
	a = (float) 2.5 * i;
	b = b * f;



	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("i = %d\n", i);

	printf("f = %.2f\n", f);
	printf("d = %.8f\n", d); 	

    return 0;
}

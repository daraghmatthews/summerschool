#include <stdio.h>

int main(int argc, char *argv[])
{
    int f0, f1, f2;

    // initialize variables and write the while loop
    // Remember to update all variables within the loop

	f0=0;
	f1=1;
	f2 = f0 + f1;

	printf("%d\n", f0);

	while(f2 < 500){
		printf("%d\n", f2);
		f0 = f1;
		f1 = f2;
		f2 = f0 + f1;

	}

    return 0;
}

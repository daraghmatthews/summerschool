#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    // write the control structure as described in the exercise
    // and run the code with different values for i

	printf("Enter number: ");
   	scanf("%d", &i);

	if(i < 0){
		printf("Negative number\n");
	
	}else if(i == 0){
		printf("Zero\n");
	
	}else if(i > 100){
		printf("Over 100\n");	
	
	}else{
		printf("Between 1 and 100\n");

	}

    return 0;
}

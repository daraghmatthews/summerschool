#include <cstdio>

class democlass {
public:
  // Two member variables, a and b
  int a, b;

  // print member function
	void print_members() const{
		printf("a is %i, b is %i\n", a, b);
	};	
};


int main(void)
{
  democlass demo;
  demo.a = 10;
  demo.b = 20;

  // call to the print member
	demo.print_members();

  
  return 0;
}

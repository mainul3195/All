//pass by value when any value is transfered to function
//pass by reference when the memory address of value is transfrered to a function
#include <stdio.h>

int foo(int x, int z[])
{
	printf("X in func -> %d\n", &x);
	x+=10;
	z[0]--;
	z[1]++;
	return x*3+(z[0]--*++z[1]);
}

int main()
{
	int x = 10, y, z[2]={4,3};
	printf("X in main -> %d\n", &x);
	y=foo(x, z);
	printf("x = %d, y = %d\n",x, y);
	printf("z[0] = %d, z[1] = %d\n", z[0], z[1]);
	return 0;
}
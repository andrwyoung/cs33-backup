#include <stdio.h>
/*
In problem 2.63, the types of the 
functions' first arguments and returned 
values should be long and unsigned long, 
not int and unsigned. 
(The type of the second arguments remains int.) 
Also, check your 2.63 solution with both 
'gcc -m32' and 'gcc -m64'.
*/

unsigned long srl(unsigned long x, int k)
	//perform shift logically
	//without right shifts or divisions
	//given a arithmatic shift
{
	unsigned long xsra = (long) x >> k;
	unsigned long mask = ~(-1 << (8 * sizeof(long) - k));
	return mask & xsra;
}


long sra(long x, int k)
	//perform shift arithmatically
	//without right shifts of divisions
	//given a logical shift
{
	long xsrl = (unsigned long) x >> k;
	long mask = -1 << (8 * sizeof(long) - k);
	return x > 0? xsrl: mask | xsrl;

}

int main()
{
	long x = -34;
	int k = 2;

	if(sra(x, k) == x >> k)
	{
		printf("passed\n");
	}
	else
	{
		printf("nope\n");
	}

	return 0;
}
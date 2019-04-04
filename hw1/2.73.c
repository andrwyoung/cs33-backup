#include <limits.h>
#include <stdio.h>

int saturating_add(int x, int y)
{
	int k = 8 * sizeof(int) - 1;

	int answer = x + y;
	int sign = answer >> k;
	x = x >> k;
	y = y >> k;
	((!x & !y & sign) && (answer = INT_MAX)) || ((x & y & !sign) && (answer = INT_MIN));

	return answer;
}


int main()
{	
	if(saturating_add(8, 6) == 14)
	{
		printf("yes!\n");
	}

		
	if(saturating_add(INT_MAX, INT_MAX) == INT_MAX)
	{
		printf("yes\n");
	}

	return 0;
}
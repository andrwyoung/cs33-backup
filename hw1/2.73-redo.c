#include <limits.h>
#include <stdio.h>

int saturating_add(int x, int y)
{
	int k = 8 * sizeof(int) - 1;

	int answer = x + y; 
	int sign = answer >> k;
	int overflow = __builtin_add_overflow_p(x, y, (typeof((x) + (y))) 0);
	(sign & overflow) && (answer = INT_MAX) || (overflow & !sign) && (answer = INT_MIN);

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
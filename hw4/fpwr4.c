static float u2f(unsigned u)
{
	return *((float*)&u);
}

float fpwr4(int x)
{
	unsigned exp, frac;
	unsigned u;


	// 4^x = 2^(2x)
	if(x < -74) // ceiling((-23 - 126) / 2)
	//too small. Return 0.0
	{
		exp = 0;
		frac =  0;
	} else if (x < -63) // -126 / 2
	//denormalized result
	{
		exp = 0;
		frac = 1 << ((23 + 126) + (2 * x)); 
	} else if (x < 64) // floor(128 / 2)
	//normalized result
	{
		exp = (2 * x) + 127;
		frac = 0;
	} else 
	//too big. Return +Inf
	{
		exp = 255;
		frac = 0;
	}

	//put exp and frac into 32 bits
	u = exp << 23 | frac;
	//return as float
	return u2f(u);
}

int main()
{	
	return 0;
}
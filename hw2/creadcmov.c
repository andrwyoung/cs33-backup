long cread_alt(long *xp)
{
	long one = xp[-1];
	long two = -1;
	if(xp == 0)
		one = two;
	return one;
}


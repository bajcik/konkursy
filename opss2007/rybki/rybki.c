/*
        file: rybki.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
	int rybmin[52],rybmax[52];
	int N,i,K,min,max,m,ai;

	/* rybki */
	scanf("%d", &N);
	for (i=1; i<=N; ++i)
	{
		scanf("%d", rybmin+i);
		scanf("%d", rybmax+i);
	}

	/* zapytania */
	scanf("%d", &K);
	for (; K; --K)
	{
		min = 0;
		max = 50;
		/* rybki w zapytaniu */
		scanf("%d", &m);
		for (; m; --m)
		{
			scanf("%d", &ai);
			if (rybmin[ai] > min)
				min = rybmin[ai];
			if (rybmax[ai] < max)
				max = rybmax[ai];
		}
		
		if (min <= max)
			printf("%d %d\n", min, max);
		else
			printf("NIE\n");
	}

	return 0;
} /* main */



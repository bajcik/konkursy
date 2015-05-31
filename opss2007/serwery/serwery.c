/*
        file: serwery.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
	int C,n,i,a,max;
	long long suma;

	scanf("%d", &C);
	for (; C; --C)
	{
		scanf("%d", &n);
		suma = max = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &a);
			if (a > max)
				max = a;
			suma += a;
		}
		//printf("%d %d %d\n", suma,max,suma-max);
		printf("%Ld\n", suma-max);
	}
	return 0;
} /* main */



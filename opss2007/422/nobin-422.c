/*
        file: 422.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>
#include <stdlib.h>
#define FMT "%Ld"

int main(int argc, char *argv[])
{
	long long D,N,P,K,i,j, zL,zT, nlast,nteraz, mod,posr;
	long long tab[50001];
	long long min[50001];
	long long zmiana[2][50001];

	scanf(FMT, &D);
	for (; D; --D)
	{
		scanf(FMT, &N);
		scanf(FMT, &P); P--;
		scanf(FMT, &K); K--;
		for (i=0; i<N; i++)
			scanf(FMT, &tab[i]);

		for (i=0; i<N; i++)
		{
			min[i] = tab[i]*labs(i-P);
			zmiana[0][i] = i;
		}
		nlast = N;
		zL = 0;
		zT = 1;

		while (nlast)
		{
			nteraz = 0;
			for (i=0; i<N; i++)
			{
				mod = 0;
				// wszystkie zamiast najblizsze otoczenie
				for (j=0; j<nlast; j++)
				{
					posr = tab[i]*labs(i-zmiana[zL][j]) + min[zmiana[zL][j]];
					if (posr < min[i])
					{
						min[i] = posr;
						mod = 1;
					}
				}
				if (mod)
					zmiana[zT][nteraz++] = i;
			}

			nlast = nteraz;
			zL = 1-zL;
			zT = 1-zT;
			//printf(FMT "\n", nlast);
		}

		printf(FMT "\n", tab[P]*labs(K-P) + min[K]);
	}
	return 0;
} /* main */



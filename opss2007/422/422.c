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
	long long D,N,P,K,i,j, zL,zT, nlast,nteraz, mod,posr, lewy, prawy, sr, kosztp;
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
				
				// znajdujemy srodek
				lewy = 0;
				prawy = nlast-1;
				while (lewy < prawy && abs(prawy-lewy)>2)
				{
					sr = (lewy+prawy)/2;
					if (i < zmiana[zL][sr])
						prawy = sr;
					else
						lewy = sr;
					//printf("i=%Ld zm=%Ld %Ld %Ld, %Ld\n", i, zmiana[zL][sr], lewy, sr, prawy);
				}
				if (i==zmiana[zL][lewy])
					sr = lewy;
				else
					sr = prawy;


				// od srodka w lewo
				for (j=sr; j>=0; j--)
				{
					kosztp = tab[i]*labs(i-zmiana[zL][j]);
					if (kosztp >= min[i]) // zeby za daleko w lewo nie zajsc
						break;
					posr = kosztp + min[zmiana[zL][j]];
					if (posr < min[i])
					{
						min[i] = posr;
						mod = 1;
					}
				}
				
				// od srodka w prawo
				for (j=sr; j<nlast; j++)
				{
					kosztp = tab[i]*labs(i-zmiana[zL][j]);
					if (kosztp >= min[i]) // zeby za daleko w prawo nie zajsc
						break;
					posr = kosztp + min[zmiana[zL][j]];
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



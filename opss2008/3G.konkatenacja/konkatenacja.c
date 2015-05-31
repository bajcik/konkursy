/*
        file: konkatenacja.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>


typedef struct
{
	int dlugosc;
	int next;
} wyraz;

wyraz wyrazy[202];

int main(int argc, char *argv[])
{
	int D, N, i, czas, pary, minidx, min, sum;

	scanf("%d", &D);
	for (; D; --D)
	{
		scanf("%d", &N);
		// czytamy dane
		for (i=0; i<N; i++)
		{
			scanf("%d", &wyrazy[i].dlugosc);
			wyrazy[i].next = i<N-1 ? i+1 : 0;
		}

		// liczymy
		czas = pary = 0;
		while (wyrazy[0].next)
		{
			minidx = 0;
			min = wyrazy[0].dlugosc + wyrazy[wyrazy[0].next].dlugosc;
			// szukamy minimalnej pary
			for (i=0; wyrazy[i].next; i=wyrazy[i].next)
			{
				sum = wyrazy[i].dlugosc + wyrazy[wyrazy[i].next].dlugosc;
				if (sum < min)
				{
					min = sum;
					minidx = i;
				}
			}

			if (minidx)
				pary++;

			// konkatenacja
			wyrazy[minidx].dlugosc = min;
			wyrazy[minidx].next = wyrazy[ wyrazy[minidx].next ].next;
			czas += min;
		}

		printf("%d %d\n", czas, pary);
	}
	return 0;
} /* main */



/*
        file: 2C.detektyw.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>

typedef struct
{
	int winny;
	int niewinny;
	int wskazal;
	int klamstw;
} osoba;
osoba osoby[10000];

typedef struct
{
	int kto;
	char zewinny;
} zeznanie;
zeznanie zeznania[20001];
int zeznan;

int main()
{
	int D, N, Z, P, C, K, mink, i;
	scanf("%d", &D);
	for (; D; --D)
	{
		scanf("%d", &N);
		scanf("%d", &Z);

		// czyszczenie
		for (i=1; i<=N; i++)
		{
			osoby[i].winny = 0;
			osoby[i].niewinny = 0;
			osoby[i].wskazal = 0;
		}

		// wczytywanie zeznan
		for (i=1; i<=Z; i++)
		{
			scanf("%d", &P);
			getchar(); // ' '
			C = getchar();
			scanf("%d", &K);
			
			osoby[P].wskazal = 1;

			if (C == 'W')
			{
				osoby[K].winny++;
				zeznania[i].kto = K;
				zeznania[i].zewinny = 1;
			}
			else
			{
				zeznania[i].kto = zeznania[K].kto;

				if (C == 'P')
					zeznania[i].zewinny = zeznania[K].zewinny;
				else // if (C == 'F')
					zeznania[i].zewinny = !zeznania[K].zewinny;

				if (zeznania[i].zewinny)
					osoby[zeznania[i].kto].winny++;
				else
					osoby[zeznania[i].kto].niewinny++;
			}
		}

		// szukamy minimalnej liczby klamstw
		mink = 20001;
		for (i=1; i<=N; i++)
		{
			int nk = N - osoby[i].winny;
			if (nk < mink)
				mink = nk;
			osoby[i].klamstw = nk;
		}

		// wypisac winnych
		for (i=1; i<=N; i++)
			if (osoby[i].klamstw == mink)
				printf("%d ", i);
		printf("\n");
	}

	return 0;
} /* main */



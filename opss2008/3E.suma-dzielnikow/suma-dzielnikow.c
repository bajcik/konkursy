/*
        file: suma-dzielnikow.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>

typedef struct
{
	int val;
	char byl;
} dzielnik;

dzielnik tab[5000];
int tabsize;

// zwraca najmniejszy dzielnik lub 0 jesli v pierwsze
int ND(int v)
{
	int j;
	// dzielimy przez mniejsze pierwsze
	for (j=0; j<tabsize; j++)
	{
		if (tab[j].val*tab[j].val > v)
			return 0;
		if (v % tab[j].val == 0)
			return tab[j].val;
	}
	return -1;
}


void generuj()
{
	int k;
	tab[0].val = 2;
	tabsize = 1;

	// badamy kandydatow
	for (k=3; k<32000; k++)
	{
		if (ND(k))
			continue;

		tab[tabsize++].val = k;
	}
	printf("%d\n", tabsize);
}


int main(int argc, char *argv[])
{
	int C,M,n,suma,nr,d,i,found;

	generuj();
	return 0;

	scanf("%d", &C);
	scanf("%d", &M);
	
	for (; C; --C)
	{
		scanf("%d", &n);
		suma = 1 + n;
		nr = n;
		while (nr>1)
		{
			// szukamy dzielnika
			d = ND(nr);

			// czy pozostalosc jest liczba pierwsza
			if (!d)
			{
				suma += nr;
				break;
			}

			while (nr % d == 0)
				nr /= d;
		}
		printf("%d %d\n", suma, M%n);
	}

	return 0;
} /* main */



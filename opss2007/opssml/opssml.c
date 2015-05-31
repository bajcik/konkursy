/*
        file: opssml.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct element_t_ element_t;
struct element_t_{
	int id;               /* wyznacznik kolejnosci - dla sortowania elementow o tej samej nazwie */
	int pelny;
	element_t *dzieci;
	element_t *atrybuty;
	element_t *next;
	char nazwa[20];
	char wartosc[20];
};

/* globalne */
element_t Magazyn[200000];
int Magnext = 0;

element_t *mkelement()
{
	element_t *e = &Magazyn[Magnext++];
	memset(e, 0, sizeof(element_t));
	e->id = Magnext;
	return e;
}

/* parser */
char magazynek[3];
int wmag = 0;

char wezznak()
{
	char ch;
	if (wmag)
	{
		ch = magazynek[0];
		magazynek[0] = magazynek[1];
		magazynek[1] = magazynek[2];
		wmag--;
	}
	else
		ch =  getchar();
	return ch;
}

void zwrocznak(char ch)
{
	magazynek[2] = magazynek[1];
	magazynek[1] = magazynek[0];
	magazynek[0] = ch;
	wmag++;
}

void wczytajliteral(char *str)
{
	char ch = wezznak();
	while ((ch>='a' && ch<='z') || (ch>='A' && ch>='Z') || (ch>='0' && ch<='9'))
	{
		*str = ch;
		str++;
		ch = wezznak();
	}
	zwrocznak(ch);
	*str = 0; 
}

element_t *Sorttab[200000];

int cmp_element(element_t **e1, element_t **e2)
{
	int scmp = strcmp((*e1)->nazwa, (*e2)->nazwa);
	if (scmp)
		return scmp;
	else
		return (*e1)->id - (*e2)->id;
}

element_t * posortuj(element_t *e)
{
	int i,n;
	element_t *es, *e1;

	/* przepisanie listy */
	for (i=0; e; e=e->next, i++)
		Sorttab[i] = e;
	n = i;
	
	/* sortowanie */
	qsort(Sorttab, n, sizeof(element_t *), (int(*)(const void *, const void *))cmp_element);

	/* utworzenie nowej listy - od konca */
	e1 = NULL;
	for (i=n-1; i>=0; --i)
	{
		es = Sorttab[i];
		es->next = e1;
		e1 = es;
	}

	return e1;
}

element_t *wczytaj_element()
{
	char ch;
	element_t *e,*e2;

	e = mkelement();
	wezznak();                         // <
	wczytajliteral(e->nazwa);         // nazwa
	ch = wezznak();

	/* atrybuty */
	while (ch == ' ')
	{
		element_t *atr = mkelement();
		wczytajliteral(atr->nazwa);
		wezznak();  // =
		wezznak();  // "
		wczytajliteral(atr->wartosc);
		wezznak();  // "
		atr->next = e->atrybuty;
		e->atrybuty = atr;
		ch = wezznak();
	}
	e->atrybuty = posortuj(e->atrybuty);

	if (ch == '/')
	{
		/* koniec elementu */
		wezznak();      // >
		wezznak();      // \n
	}
	else if (ch == '>')
	{
		e->pelny = 1;
		/* elementy podrzedne */
		wezznak();      // \n
		while (1)
		{
			wezznak();      // <
			ch = wezznak();
			if (ch == '/')
			{
				/* tag zamykajacy */
				while (ch != '\n')
					ch = wezznak();
				break;
			}
			else
			{
				zwrocznak(ch);
				zwrocznak('<');
				e2 = wczytaj_element();
				e2->next = e->dzieci;
				e->dzieci = e2;
			}
		}
		e->dzieci = posortuj(e->dzieci);
	}
	else
		printf("BLAD\n");

	return e;
}

element_t sorttab[200000];

void wypisz(element_t *e)
{
	element_t *atr, *dz;

	printf("<%s", e->nazwa);
	if (e->atrybuty)
		for (atr = e->atrybuty; atr; atr=atr->next)
			printf(" %s=\"%s\"", atr->nazwa, atr->wartosc);
	if (e->pelny)
	{
		printf(">\n");
		for (dz = e->dzieci; dz; dz=dz->next)
			wypisz(dz);
		printf("</%s>\n", e->nazwa);
	}
	else
		printf("/>\n");
}

void naglowek()
{
	char ch;
	/* naglowek */
	do {
		ch = wezznak();
		putchar(ch);
	} while (ch != '\n');
}

int main(int argc, char *argv[])
{
	element_t *e;
	char ch;
	
	naglowek();

	e = wczytaj_element();
	wypisz(e);

	return 0;
} /* main */



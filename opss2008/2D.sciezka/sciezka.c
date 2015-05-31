/*
        file: sciezka.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>

typedef struct
{
	char kierunek;
	char zbadana;
	int  odleglosc;
} komorka;

komorka tab[1002][1002]; // 6MB

int stos[1000*1000][2]; // 8MB
int stos_i = 0;
#define EMPTY (stos_i == 0)
#define PUSH(x,y) {stos[stos_i][0] = (x); stos[stos_i][1] = (y); stos_i++;}
#define POP(x,y) {stos_i--; x=stos[stos_i][0]; y=stos[stos_i][1];}
#define CLEAR {stos_i = 0;}

char getletter()
{
	for (;;)
	{
		char ch = getchar();
		if (ch == 'g' || ch == 'd' || ch == 'l' || ch == 'p' || ch == '.' || ch == 'k')
			return ch;
	}
}

int main(int argc, char *argv[])
{
	int C,N, i,j, nodl;

	scanf("%d", &C);
	for (; C; C--)
	{
		scanf("%d", &N);

		// guard brzegi ;)
		for (i=0; i<=N+1; i++)
		{
			tab[i][0].zbadana = 1;
			tab[i][N+1].zbadana = 1;
			tab[0][i].zbadana = 1;
			tab[N+1][i].zbadana = 1;
		}

		CLEAR;

		// czytanie tabeli
		for (j=N; j; j--)
		{
			for (i=1; i<=N; i++)
			{
				tab[i][j].kierunek = getletter();
				tab[i][j].zbadana = 0;
				tab[i][j].odleglosc = -1;

				if (tab[i][j].kierunek == 'k')
				{
					tab[i][j].zbadana = 1;
					tab[i][j].odleglosc = 0;
					PUSH(i, j);
				}
			}
		}

		// szukanie drogi
		while (!EMPTY)
		{
			POP(i, j);

			// odleglosc kolejnych wezlow
			nodl = tab[i][j].odleglosc + 1;

			// prawa
			if (!tab[i+1][j].zbadana)
				switch (tab[i+1][j].kierunek)
				{
					case '.':
						tab[i+1][j].kierunek = 'l';
					case 'l':
						tab[i+1][j].zbadana = 1;
						tab[i+1][j].odleglosc = nodl;
						PUSH(i+1, j);
					break;
				}
			
			// lewa
			if (!tab[i-1][j].zbadana)
				switch (tab[i-1][j].kierunek)
				{
					case '.':
						tab[i-1][j].kierunek = 'p';
					case 'p':
						tab[i-1][j].zbadana = 1;
						tab[i-1][j].odleglosc = nodl;
						PUSH(i-1, j);
					break;
				}

			// wyzej
			if (!tab[i][j+1].zbadana)
				switch (tab[i][j+1].kierunek)
				{
					case '.':
						tab[i][j+1].kierunek = 'd';
					case 'd':
						tab[i][j+1].zbadana = 1;
						tab[i][j+1].odleglosc = nodl;
						PUSH(i, j+1);
					break;
				}

			// nizej
			if (!tab[i][j-1].zbadana)
				switch (tab[i][j-1].kierunek)
				{
					case '.':
						tab[i][j-1].kierunek = 'g';
					case 'g':
						tab[i][j-1].zbadana = 1;
						tab[i][j-1].odleglosc = nodl;
						PUSH(i, j-1);
					break;
				}
			
			if (i==1 && j==1)
				break; // mamy sciezke

		}

		// pokazujemy droge
		printf("%d\n", tab[1][1].odleglosc+1);
		
		i = j = 1;
		while (1)
		{
			printf("%d %d\n", i, j);
			
			if (tab[i][j].kierunek == 'k')
				break;

			switch (tab[i][j].kierunek)
			{
				case 'l': i-- ;break;
				case 'p': i++ ;break;
				case 'g': j++ ;break;
				case 'd': j-- ;break;
			}

		}

	}

	return 0;
} /* main */



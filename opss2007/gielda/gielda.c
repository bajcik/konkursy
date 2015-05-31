/*
        file: gielda.c
 description:
	 license: GPL
      author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
              http://kolos.math.uni.lodz.pl/~bajcik/
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _trans_t trans_t;
struct _trans_t
{
	int cena, ilosc
	trans_t *next;
};

trans_t *OfertyS['Z'-'A'];
trans_t *OfertyK['Z'-'A'];

trans_t *new_trans(int cena, int ilosc)
{
	trans_t *t = calloc(1, sizeof(trans_t));
	t->cena = cena;
	t->ilosc = ilosc;
	return t;
}

int main(int argc, char *argv[])
{
	memset(OfertyS, 0, sizeof(OfertyS));
	memset(OfertyK, 0, sizeof(OfertyK));
	scanf("%d", &N);
	for (; N; --N)
	{
		char buf[50];
		fgets(buf, sizeof(buf), stdin);
		rzecz = buf[0]-'A';
		kupno = buf[2] == 'K' ? 1:0;
		ilosc = 0;
		for (i=4; buf[i]>='0' && buf[i]<=9; i++)
		{
			ilosc *= 10;
			ilosc += buf[i]-'0';
		}

		i++;
		cena = 0;
		for (; buf[i]>='0' && buf[i]<=9; i++)
		{
			cena *= 10;
			cena += buf[i]-'0';
		}
		// jeszcze grosiki
		cena *= 100;
		cena += (buf[i+1]-'0')*10;
		cena +=  buf[i+1]-'0';

		t = new_trans(cena, ilosc);
	}
	return 0;
} /* main */



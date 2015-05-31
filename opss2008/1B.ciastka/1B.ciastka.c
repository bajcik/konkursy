
#include <stdio.h>


int main()
{
	int D,N,suma,x,C;

	scanf("%d", &D);
	for (; D>0; D--)
	{
		scanf("%d", &N);
		suma = 0;
		for (; N>0; N--)
		{
			scanf("%d", &x);
			suma += x;
		}

		scanf("%d", &C);
		printf("%d\n", suma ? (C%suma) : C);
	}

	return 0;
} /* main */



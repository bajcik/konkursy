
#include <stdio.h>


int main()
{
	int N, obwod;

	scanf("%d", &N);
	scanf("%d", &obwod);

	for (; N>0; N--)
	{
		int k, o, d;
		scanf("%d", &k);
		scanf("%d", &o);
		scanf("%d", &d);
		
		if (k > obwod)
			printf("komin\n");
		else if (o > obwod)
			printf("okno\n");
		else if (d > obwod)
			printf("drzwi\n");
		else
			printf("brak\n");
	}

	return 0;
} /* main */



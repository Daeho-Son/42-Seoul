#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int		random;
	int		max;

	srand(time(NULL));
	random = 0;
	max = atoi(argv[1]);
	for (int i = 0; i < max; i++) {
		random = rand() % 26 + 97;
		printf("%c", random);
	}
}

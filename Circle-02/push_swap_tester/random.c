#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    int a[N];
    int k;

	srand(time(NULL));
    for (int i = 0; i < N;)
    {
        k = 0;
        a[i] = rand() % 6000;
        if (i == 0)
        {
            i++;
            continue ;
        }
        for (int j = 0; j < i; ++j)
        {
            if (a[i] == a[j])
                k++;
        }
        if (k == 0)
        {
            printf("%d ", a[i]);
            i++;
        }
    }
}

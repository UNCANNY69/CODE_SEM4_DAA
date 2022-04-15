#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
void main()
{
    int n = 100;
    int a1[n][n],a3[n][n],a2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a1[i][j] = rand()%100;
        }
    }
    double time_spent1 = 0.0;
    clock_t begin1 = clock();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a2[i][j] = rand()%100;
            a3[i][j] = a1[i][j] + a2[i][j];
        }
    }
    clock_t end1 = clock();
    time_spent1 += (double)(end1 - begin1)/CLOCKS_PER_SEC;
    printf("The seconds for jik %.10f \n ", time_spent1);
}
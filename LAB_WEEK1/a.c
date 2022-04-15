#include <stdio.h>
#include <stdlib.h>
void main()
{
    int b = 0, n;
    printf("please enter the size of the matrix u want:-\n");
    //scanf("%d", &n);
    n = 50;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand()%1000;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
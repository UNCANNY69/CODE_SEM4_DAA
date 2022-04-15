#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
    int n = 100;
    printf("FOR a %d x %d matrix \n",n,n);
    int a1[n][n], a3[n][n], a2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a1[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a2[i][j] = rand() % 100;
        }
    }
    
    double time_spent1 = 0.0;
    double time_spent2 = 0.0;
    double time_spent3 = 0.0;
    double time_spent4 = 0.0;
    double time_spent5 = 0.0;
    double time_spent6 = 0.0;
    clock_t begin1 = clock();
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            a3[i][j] = 0;
            for (int k = 0; k < n; k++)
                a3[i][j] += a1[i][k] * a2[k][j];
        }
    }
    clock_t end1 = clock();
    time_spent1 += (double)(end1 - begin1)/CLOCKS_PER_SEC;
    printf("The seconds for jik %.10f \n ", time_spent1);
    clock_t begin2 = clock();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a3[i][j] = 0;
            for (int k = 0; k < n; k++)
                a3[i][j] += a1[i][k] * a2[k][j];
        }
    }
    clock_t end2 = clock();
    time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("The seconds for ijk %.10f \n ", time_spent2);
    clock_t begin3 = clock();
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            
            for (int i = 0; i < n; i++){
                a3[i][j] = 0;
                a3[i][j] += a1[i][k] * a2[k][j];}
        }
    }
    clock_t end3 = clock();
    time_spent3 += (double)(end3 - begin3) / CLOCKS_PER_SEC;
    printf("The seconds for kij %.10f \n ", time_spent3);
    clock_t begin4 = clock();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a3[i][j] = 0;
            for (int k = 0; k < n; k++)
                a3[i][j] += a1[i][k] * a2[k][j];
        }
    }
    clock_t end4 = clock();
    time_spent4 += (double)(end4 - begin4) / CLOCKS_PER_SEC;
    printf("The seconds for ikj %.10f \n ", time_spent4);
    clock_t begin5 = clock();
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            
            for (int i = 0; i < n; i++){
               a3[i][j] = 0;
                a3[i][j] += a1[i][k] * a2[k][j];}
        }
    }
    clock_t end5 = clock();
    time_spent5 += (double)(end5 - begin5) / CLOCKS_PER_SEC;
    printf("The seconds for jki %.10f \n ", time_spent5);
    clock_t begin6 = clock();
    for (int k = 0; k < n; k++)
    {
       for (int j = 0; j < n; j++)
        {
            
            for (int i = 0; i < n; i++){
                a3[i][j] = 0;
                a3[i][j] += a1[i][k] * a2[k][j];}
        }
    }
    clock_t end6 = clock();
    time_spent6 += (double)(end6 - begin6) / CLOCKS_PER_SEC;
    printf("The seconds for kji %.10f \n ", time_spent6);
}
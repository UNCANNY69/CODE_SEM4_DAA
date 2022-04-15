#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
    struct timespec start;
    struct timespec end;
    FILE *fp1, *fp2;
    fp1 = fopen("text1.txt", "w");
    fp2 = fopen("text2.txt", "w");
    int size, i, toSearch, found, count = 0;
    size = 500;
    for (int j = size; j <= 10000; j += 500)
    {
        int arr[j];
        for (i = 0; i < size; i++)
        {
            arr[i] = rand() % (2*j-1);
        }
        toSearch = 670;
        found = 0;
        
        for (i = 0; i < size; i++)
        {
            count++;
            if (arr[i] == toSearch)
            {
                found = 1;
                break;
            }
        }
        printf("%d\t%d\n", j, count);
        //fprintf(fp1, "%d\t%d\n", j, count);
        //fprintf(fp2, "%d\t%.9f \n", j, time_elapsed(start, end));
    }
    return 0;
}

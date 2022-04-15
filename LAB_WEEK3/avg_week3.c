#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int n = 500, max, min;
    for (int i = 500; i < 10000; i = i + 500)
    {
        int sum = 0, count1 = 0, count2 = 0;
        float avg = 0;
        int arr[n];
        arr[0] = rand() % n;
        max = arr[0];
        min = arr[0];

        for (int i = 1; i < n; i++)
        {
            arr[i] = rand() % 1000;
            if (arr[i] > max)
            {
                count1++;
                max = arr[i];
            }
            if (arr[i] < min)
            {
                count2++;
                min = arr[i];
            }
            sum += arr[i];
        }
        printf("%d. max comparision count:%d\tmin comparision count:%d\n",i/500, count1, count2);
        avg = (sum - min - max) / n;
    }
}
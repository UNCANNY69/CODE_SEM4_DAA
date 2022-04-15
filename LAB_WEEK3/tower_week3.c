#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int *count1, int *count2)
{
    *count1 = *count1 + 1;
    if (n == 1)
    {
        *count2 = *count2 + 1;
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, count1, count2);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, count1, count2);
}

int main()
{
    int n = 4;
    FILE *fp1 = fopen("test4.txt", "w");
    FILE *fp2 = fopen("test5.txt", "w");
    int count1 = 0;
    int count2 = 0;
    for (int i = 3; i <= 3; i++)
    {
        towerOfHanoi(i, 'A', 'C', 'B', &count1, &count2);
        fprintf(fp1, "%d\t%d\n", i, count1);
        fprintf(fp2, "%d\t%d\n", i, count2);
    }
    return 0;
}
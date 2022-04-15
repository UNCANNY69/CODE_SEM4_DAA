#include <stdio.h>
void main()
{
    int a[3][3];
    int b = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    int a[3][3] = {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1};
}
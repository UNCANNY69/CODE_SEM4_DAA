#include <stdio.h>
#include <sys/time.h>
void main()
{
    int a[3][3];
    int b = 0,flag =0;
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
    for (int i = 0; i < 3 && flag == 0; i++)
    {
        for (int j = 0; j < 3 && flag == 0; j++)
        {
            if(i != j && (a[i][j]!=0)){
                flag = 1;
            }
            if(i == j && (a[i][j]!=1)){
                flag = 1;
            }
        }
    }
    if(flag == 0){
        printf("it is a identity matrix");
    }
    else{
        printf("it is nota identity matrix");
    }
}
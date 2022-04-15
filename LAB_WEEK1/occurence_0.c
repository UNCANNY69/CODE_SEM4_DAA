#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char str[1000],a[5]="01010";

    for(int i=0;i<1000;i++)
    {
        str[i]='0';
    }
    //printf("%d\t%d\n",strlen(a),strlen(b));
    int occurences=0,comp=0;
    int i=0,j=0;

    //Approach 1:
    for(i=0;i<996;i++)
    {
        for(j=0;j<5;j++)
        {
            if(str[j+i]==a[j])
            {
                comp++;
            }
            else
            {
                comp++;
                break;
            }
        }
        if(j==strlen(a))
        {
            occurences++;
        }
    }

    printf("Approach 1: %d\n",comp);
    occurences=0;
    comp=0;
    

    //Approach 2:
    for(i=0;i<996;i++)
    {
        for(j=0;j<5;j++)
        {
            comp++;
            if(str[j+i]==a[j])
            {
            }
            else
            {
                break;
            }
        }
        if(j==strlen(a))
        {
            occurences++;
            i+=strlen(a)-1;
        }
    }
    printf("Approach 2:%d\n",comp);
    
    return 0;
}
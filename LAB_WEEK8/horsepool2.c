#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift_t(char pat[], int shift[], int m)
{
    for (int i = 0; i < 126; i++)
    {
        shift[i] = m;
    }
    for (int j = 0; j < m - 1; j++)
    {
        shift[pat[j]] = m - j - 1;
    }
}
void hp_match_a(char *pat, char *text, int *shift, int m,int *count)
{
    int s = 1000, flag;
    for (int i = 0; i <= s-m; i++)
    {
        flag = 1;
        for (int j = m - 1; j >= 0 && flag == 1; j--)
        {
            *count = *count + 1;
            if (text[i + j] != pat[j])
            {
                flag = 0;
                i += shift[text[i + m - 1]] - 1;
            }
            else if (j == 0)
            {
                printf("patten present at %d\n", i);
            }
        }
    }
}

void main()
{
    char pat1[] = "10000",pat2[] = "00001",pat3[] = "01010";
    char text[1000];
    for(int i = 0; i <1000 ; i++){
        text[i] = 48;
    }
    int count = 0;
    int shift[126], m = strlen(pat1);
    shift_t(pat1, shift, m);
    printf("NUMBER OF ALL COMPARISIONS for 00001:\n");
    hp_match_a(pat1, text, shift, m,&count);
    printf("%d\n", count);
    count = 0;
    printf("NUMBER OF ALL COMPARISIONS for 10000:\n");
    hp_match_a(pat2, text, shift, m,&count);
    printf("%d\n", count);
    count = 0;
    printf("NUMBER OF ALL COMPARISIONS for 10101:\n");
    hp_match_a(pat2, text, shift, m,&count);
    printf("%d\n", count);
}
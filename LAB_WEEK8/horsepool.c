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
void hp_match_a(char *pat, char *text, int *shift, int m)
{
    int s = strlen(text), flag;
    for (int i = 0; i < s; i++)
    {
        flag = 1;
        for (int j = m - 1; j >= 0 && flag == 1; j--)
        {
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
void hp_match_b(char *pat, char *text, int *shift, int m)
{
    int s = strlen(text), flag=1;
    for (int i = 0; i < s; i++)
    {
        flag = 1;
        for (int j = m - 1; j >= 0 && flag == 1; j--)
        {
            if (text[i + j] != pat[j])
            {
                flag = 0;
                i += shift[text[i + m - 1]] - 1;
            }
            else if (j == 0)
            {
                printf("patten present at %d\n", i);
                return;
            }
        }
    }
}
void hp_match_c(char *pat, char *text, int *shift, int m)
{
    int s = strlen(text), flag,last=-1;
    for (int i = 0; i < s; i++)
    {
        flag = 1;
        for (int j = m - 1; j >= 0 && flag == 1; j--)
        {
            if (text[i + j] != pat[j])
            {
                flag = 0;
                i += shift[text[i + m - 1]] - 1;
            }
            else if (j == 0)
            {
                //printf("patten present at %d\n", i);
                last = i;
            }   
        }
    }
    printf("patten present at %d\n", last);
}
void main()
{
    char pat[] = "101", text[] = "10000101010001010101001010101010101010101010101010101";
    int shift[126], m = strlen(pat);
    shift_t(pat, shift, m);
    printf("LIST OF ALL OCCURANCES:\n");
    hp_match_a(pat, text, shift, m);
    printf("FIRST OCCURANCE:\n");
    hp_match_b(pat, text, shift, m);
    printf("LAST OCCURANCE:\n");
    hp_match_c(pat, text, shift, m);
}
#include <limits.h>
#include <stdio.h>
#include <string.h>

struct airport
{
    int num_id;
    const char *airport_name;
};
typedef struct airport airport_t;

/*
 * The connection represents the details of an edge in the connection graph.
 * graph[i][j] will be a connection structure containg the time and distance
 * from airport with id=i to airport with id=j.
 */
struct connection
{
    int distance;
    int time;
};
typedef struct connection connection_t;

/*
 * This structure is used as a return value and parameters in some functions.
 */
struct pair
{
    int first;
    int second;
};
typedef struct pair pair_t;

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    char shift[126];
    int m = strlen(pat);
    for (int i = 0; i < 126; i++)
    {
        shift[i] = m;
    }
    for (int j = 0; j < m - 1; j++)
    {
        shift[pat[j]] = m - j - 1;
    }
    for (int a = 0; a < n; a++)
    {
        int s = strlen(airports[a].airport_name), flag;
        for (int i = 0; i < s; i++)
        {
            flag = 1;
            for (int j = m - 1; j >= 0 && flag == 1; j--)
            {
                if (airports[a].airport_name[i + j] != pat[j])
                {
                    flag = 0;
                    i += shift[airports[a].airport_name[i + m - 1]] - 1;
                }
                else if (j == 0)
                {
                    contains[a] = 1;
                }
            }
        }
    }
}
int main()
{
    {
        int n = 3;
        const char *pat = "TA";
        int contains[3] = {0, 0, 0};
        airport_t q7_t1_airports[] = {{0, "KOCHI"}, {1, "KTA"}, {2, "KOLKATA"}};

        q7(n, pat, contains, q7_t1_airports);

        if (contains[0] == 0 && contains[1] == 1 && contains[2] == 1)
        {
            printf("Q7 TestCase 1: PASSED");
        }
        else
        {
            printf("Q7 TestCase 1: FAILED");
        }
    }
}
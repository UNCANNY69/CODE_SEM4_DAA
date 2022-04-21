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

int str_match(airport_t a, airport_t b)
{
    int i = 0;
    int count = 0;
    while (a.airport_name[i] != '\0' && b.airport_name[i] != '\0')
    {
        if (a.airport_name[i] == b.airport_name[i])
        {
            count++;
            i++;
        }
        else
        {
            return count;
        }
    }
    return count;
}

pair_t q5(int n, airport_t airports[n])
{
    int max = 0, temp = 0;
    pair_t ans = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            temp = str_match(airports[i], airports[j]);
            if (max < temp)
            {
                max = temp;
                ans.first = i;
                ans.second = j;
            }
        }
    }
    return ans;
}

int main()
{
    {
        airport_t q5_t2_airports[] = {{0, "BLR"}, {1, "MUM"}, {2, "BLR"}};
            pair_t q5_t2_result = q5(3, q5_t2_airports);

            if (q5_t2_result.first == 0 && q5_t2_result.second == 2)
            {
                printf("Q5 TestCase 2: PASSED" );
            }
            else
            {
                printf("Q5 TestCase 2: FAILED" );
            }
    }
}
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

int DFS(int src, int dst, int n, int k, const connection_t connections[n][n], int *flag, int count, int visited[n])
{
    for (int i = 0; i < n && *flag == 0 && visited[i] == 0; i++)
    {
        if (connections[src][i].distance != 0 && connections[src][i].distance != INT_MAX)
        {
            visited[src] = 1;
            src = i;
            count++;
            if (i == dst)
            {
                if (count <= k)
                {
                    *flag = 1;
                }
            }
            DFS(src, dst, n, k, connections, flag, count, visited);
        }
    }
    return *flag;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k, const connection_t connections[n][n])
{
    int visited[n];
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    DFS(src->num_id, dest->num_id, n, k, connections, &flag, 0, visited);
    return flag;
}

int main()
{
    airport_t src = {0, "BLR"};
    airport_t dest = {1, "MUM"};
    int n = 3;
    int k = 2;
    connection_t connections[3][3] = {
            {{0, 0}, {INT_MAX, INT_MAX}, {1, 5}},
            {{1, 2}, {0, 0}, {4, 3}},
            {{2, 3}, {2, 3}, {0, 0}}};
    if (q2(&src, &dest, n, k, connections))
    {
        printf("Q2 TestCase 1: PASSED");
    }
    else
    {
        printf("FAILED");
    }
}
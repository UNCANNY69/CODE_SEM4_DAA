#include <limits.h>
#include <stdio.h>
#include <string.h>

#define PASSED "PASSED\n"
#define FAILED "FAILED\n"

struct airport
{
    int num_id;
    const char *airport_name;
};
typedef struct airport airport_t;

struct pv
{
    int visited;
    int parent;
};
typedef struct pv pv;

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

struct pair
{
    int first;
    int second;
};
typedef struct pair pair_t;

int unordered_pair_compare(const pair_t *p1, const pair_t *p2)
{
    return ((p1->first == p2->first) && (p1->second == p2->second)) ||
           ((p1->first == p2->second) && (p1->second == p2->first));
}

int check_edge_perm(const pair_t p[3], const pair_t *p1, const pair_t *p2, const pair_t *p3)
{
    return unordered_pair_compare(&p[0], p1) && unordered_pair_compare(&p[1], p2) && unordered_pair_compare(&p[2], p3);
}

static void path_gen(int n, int *trip_order, pv *pv_arr, int source, int loop, const connection_t connections[n][n], int *min)
{
    int count = 1, mini = connections[loop][source].distance, temp = 0, temp2 = loop;
    while (loop != source)
    {
        count++;
        temp = loop;
        loop = pv_arr[loop].parent;
        mini += connections[loop][temp].distance;
    }
    if (count == n - 1 && *min > mini)
    {
        *min = mini;
        loop = temp2;
        for (int i = n - 2; i >= 0; i--)
        {
            trip_order[i] = loop;
            loop = pv_arr[loop].parent;
        }
        trip_order[0] = source;
    }
}

static void d_cycle(int n, pv *pv_arr, const connection_t connections[n][n], int source, int *trip_order, int *min)
{
    pv_arr[source].visited = 1;
    for (int i = 0; i < n; i++)
    {
        if (connections[source][i].distance != 0 && connections[source][i].distance != INT_MAX)
        {
            if (pv_arr[i].visited != 1)
            {
                pv_arr[i].parent = source;
                d_cycle(n, pv_arr, connections, i, trip_order, min);
            }
            else if (pv_arr[source].parent != i)
            {
                path_gen(n, trip_order, pv_arr, i, source, connections, min);
            }
        }
    }
    pv_arr[source].visited = 0;
}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    pv pv_arr[n];
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        pv_arr[i].visited = 0;
        pv_arr[i].parent = -1;
    }
    d_cycle(n, pv_arr, connections, 0, trip_order, &min);
    if (min == INT_MAX)
    {
        return -1;
    }
    return min;
}

int main()
{
    connection_t q8_t2_connections[3][3] = {
        {{0, 0}, {1, 2}, {INT_MAX, INT_MAX}},
        {{INT_MAX, INT_MAX}, {0, 0}, {2, 3}},
        {{3, 4}, {INT_MAX, INT_MAX}, {0, 0}}};

    int n = 3;
    int trip_order[2] = {-1, -1};

    int result = q8(n, trip_order, q8_t2_connections);

    if (result == -1 && trip_order[0] == -1 && trip_order[1] == -1)
    {
        printf("Q8 TestCase 2: " PASSED);
    }
    else
    {
        printf("Q8 TestCase 2: " FAILED);
    }
}
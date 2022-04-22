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

typedef struct vinfo
{
    int vid;
    int d;
    int p;
} vinfo;

struct heaps
{
    vinfo *arr;
    int size;
    int max_size;
};
typedef struct heaps heap_e;

void init_heap2(heap_e *heap, int max_size, vinfo *n_selected)
{
    heap->size = max_size;
    heap->max_size = max_size;
    heap->arr = n_selected; // allocating memory for array
}
void heapify2(heap_e *heap)
{
    int p, flag = 0, c;
    vinfo temp;
    for (int i = (heap->size / 2) - 1; i >= 0; i--)
    {
        p = i;
        c = (2 * p) + 1;
        flag = 0;
        while (p <= (heap->size / 2) - 1 && flag == 0)
        {
            if ((c + 1) <= heap->size && heap->arr[c].d > heap->arr[c + 1].d)
            {
                c = c + 1;
            }
            if (heap->arr[c].d < heap->arr[p].d)
            {
                temp = heap->arr[p];
                heap->arr[p] = heap->arr[c];
                heap->arr[c] = temp;
                p = c;
                c = p * 2;
            }
            else
            {
                flag = 1;
            }
        }
    }
}

vinfo extract_maxs(heap_e *heap)
{
    if (heap->size > 0)
    {
        vinfo max = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapify2(heap);
        return max;
    }
}

int find(heap_e *heap, int a)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (a == heap->arr[i].vid)
        {
            return i;
        }
    }
}

int find_s(int n ,vinfo *selected, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (a == selected[i].vid)
        {
            return i;
        }
    }
}

void relax_edge(int n ,heap_e *heap, vinfo *selected, connection_t connections[n][n])
{
    int source = heap->arr[0].vid,index = 0;
    for (int i = 0; i < n; i++)
    {
        if (connections[source][i].time != INT_MAX && connections[source][i].time != 0)
        {
            index = find(heap, i);
            if (heap->arr[index].d >  connections[source][i].time + heap->arr[0].d)
            {
                heap->arr[index].d = connections[source][i].time + heap->arr[0].d;
                heap->arr[index].p = source;
            }
        }
    }
}

void shortest_path(int n ,int k,vinfo *selected , int destinations[k] , int costs[k])
{
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        index = find_s(n,selected, destinations[i]);
        costs[i] = selected[index].d;
    }
}

void init_struct(heap_e *heap, int size,int source)
{
     for (int i = 0; i < size; i++)
    {
        heap->arr[i].d = INT_MAX;
        heap->arr[i].p = -1;
        heap->arr[i].vid = i;
    }
    heap->arr[source].d = 0;
    heap->arr[source].p = 0;
    heap->arr[source].vid = source;
   
}

void q10(int n, int k, const airport_t *src,const connection_t connections[n][n], const int destinations[k],int costs[k])
{
    vinfo selected[n];
    vinfo n_selected[n];
    int source = src->num_id;
    heap_e heap;
    init_heap2(&heap, n, n_selected);
    init_struct(&heap, n, source);
    heapify2(&heap);
    for (int i = 0; i < n; i++)
    {
        relax_edge(n,&heap, selected, connections);
        selected[i] = extract_maxs(&heap);
    }
    shortest_path(n,k,selected , destinations,costs);
}

int main()
{
    {
        connection_t q10_t1_connections[4][4] = {
            {{0, 0}, {1, 2}, {2, 6}, {INT_MAX, INT_MAX}},
            {{1, 2}, {0, 0}, {3, 5}, {4, 1}},
            {{2, 6}, {3, 5}, {0, 0}, {5, 7}},
            {{INT_MAX, INT_MAX}, {4, 1}, {5, 7}, {0, 0}}};

        int n = 4;
        int k = 2;
        int destinations[] = {0, 2};
        int costs[2] = {INT_MAX, INT_MAX};

        airport_t src = {3, "BLR"};
        q10(n, k, &src, q10_t1_connections, destinations, costs);

        if (costs[0] == 3 && costs[1] == 6)
        {
            printf("Q10 TestCase 1: PASSED" );
        }
        else
        {
            printf("Q10 TestCase 1: FAILED" );
        }
    }
}
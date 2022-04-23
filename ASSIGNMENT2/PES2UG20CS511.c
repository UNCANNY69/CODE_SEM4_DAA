#include "header.h"
#include <limits.h>
#include <string.h>

struct node
{
    int i;
    int j;
    int time;
};
typedef struct node node_e;

struct heap
{
    node_e *arr;
    int size;
    int max_size;
};
typedef struct heap heap_t;

struct pv
{
    int visited;
    int parent;
};
typedef struct pv pv;

struct vinfo
{
    int vid;
    int d;
    int p;
};
typedef struct vinfo vinfo;

struct heaps
{
    vinfo *arr;
    int size;
    int max_size;
};
typedef struct heaps heap_e;

// ANY STATIC FUNCTIONS ARE UP HERE


static void cycle(int n, pv *pv_arr, const connection_t connections[n][n], int source, int src, int *flag)
{
    pv_arr[source].visited = 1;
    for (int i = 0; i < n; i++)
    {
        if (connections[source][i].distance != 0 && connections[source][i].distance != INT_MAX)
        {
            if (pv_arr[i].visited != 1)
            {
                pv_arr[i].parent = source;
                cycle(n, pv_arr, connections, i, src, flag);
            }
            else if(src == i && pv_arr[source].parent != src)
            {
                *flag = 1;
            }
        }
    }
    pv_arr[source].visited = 0;
}

static void init_heap2(heap_e *heap, int max_size, vinfo *n_selected)
{
    heap->size = max_size;
    heap->max_size = max_size;
    heap->arr = n_selected; // allocating memory for array
}

static void heapify2(heap_e *heap)
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

static vinfo extract_maxs(heap_e *heap)
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

static int find(heap_e *heap, int a)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (a == heap->arr[i].vid)
        {
            return i;
        }
    }
}

static int find_s(int n, vinfo *selected, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (a == selected[i].vid)
        {
            return i;
        }
    }
}

static void relax_edge(int n, heap_e *heap, vinfo *selected, const connection_t connections[n][n])
{
    int source = heap->arr[0].vid, index = 0;
    for (int i = 0; i < n; i++)
    {
        if (connections[source][i].time != INT_MAX && connections[source][i].time != 0)
        {
            index = find(heap, i);
            if (heap->arr[index].d > connections[source][i].time + heap->arr[0].d)
            {
                heap->arr[index].d = connections[source][i].time + heap->arr[0].d;
                heap->arr[index].p = source;
            }
        }
    }
}

static void shortest_path(int n, int k, vinfo *selected, const int destinations[k], int costs[k])
{
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        index = find_s(n, selected, destinations[i]);
        costs[i] = selected[index].d;
    }
}

static void init_struct(heap_e *heap, int size, int source)
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

static void swap(airport_t *arr, int a, int b)
{
    airport_t temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

static void init_heap(heap_t *heap, int max_size, node_e *nodes)
{
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = nodes;
    for (int i = 0; i < max_size; i++)
    {
        heap->arr[i].i = 0;
        heap->arr[i].j = 0;
        heap->arr[i].time = 0;
    }
}

static void heapify(heap_t *heap)
{
    int p, flag = 0, c;
    node_e temp;
    for (int i = (heap->size / 2) - 1; i >= 0; i--)
    {
        p = i;
        c = (2 * p) + 1;
        flag = 0;
        while (p <= (heap->size / 2) - 1 && flag == 0)
        {
            if ((c + 1) < heap->size && heap->arr[c].time > heap->arr[c + 1].time)
            {
                c = c + 1;
            }
            if (heap->arr[c].time < heap->arr[p].time)
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

static node_e extract_max(heap_t *heap)
{
    if (heap->size > 0)
    {
        node_e max = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapify(heap);
        return max;
    }
}

static int not_full(int n, int *visited)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            return 1;
        }
    }
    return 0;
}

static int partition(airport_t *arr, int low, int high, int (*predicate_func)(const airport_t *, const airport_t *))
{
    airport_t pivot_ele = arr[low];
    int i = low + 1, j = high;
    while (j >= i)
    {
        while (i <= high && !predicate_func(&pivot_ele, &arr[i]))
        {
            i++;
        }
        while (j > low && predicate_func(&pivot_ele, &arr[j]))
        {
            j--;
        }
        if (j > i)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

static void quicksort(airport_t *arr, int low, int high, int (*predicate_func)(const airport_t *, const airport_t *))
{
    int s = 0;
    if (low >= high)
        return;
    else
    {
        s = partition(arr, low, high, predicate_func);
        quicksort(arr, low, s - 1, predicate_func);
        quicksort(arr, s + 1, high, predicate_func);
    }
}

static int str_match(airport_t a, airport_t b)
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

static void DFS(int src, int dst, int n, int k, const connection_t connections[n][n], int *flag, int count, int visited[n])
{
    if (visited[src] == 1 || *flag == 1)
    {
        return;
    }
    else
    {
        visited[src] = 1;
        count++;
        if (src == dst && count <= k)
        {
            *flag = 1;
        }
        for (int i = 0; i < n && src != dst; i++)
        {
            if (connections[src][i].distance != 0 && connections[src][i].distance != INT_MAX)
            {

                DFS(i, dst, n, k, connections, flag, count, visited);
            }
        }
        visited[src] = 0;
    }
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

// ************************YOUR SOLUTIONS BELOW****************************

int q1(int n, const connection_t connections[n][n])
{
    int R[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (connections[i][j].distance != 0 && connections[i][j].distance != INT_MAX)
            {
                R[i][j] = 1;
            }
            else
            {
                R[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                for (int j = 0; j < n; j++)
                {
                    if (j != k)
                    {
                        if (R[k][j] == 1 && R[i][k] == 1)
                        {
                            R[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (R[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k,const connection_t connections[n][n])
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int flag = 0;
    DFS(src->num_id, dest->num_id, n, k, connections, &flag, -1, visited);
    return flag;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    pv pv_arr[n];
    for (int i = 0; i < n; i++)
    {
        pv_arr[i].visited = 0;
        pv_arr[i].parent = -1;
    }
    int source = src->num_id, flag = 0;
    cycle(n, pv_arr, connections, source, source, &flag);
    return flag;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *), airport_t airport_list[n])
{
    quicksort(airport_list, 0, n - 1, predicate_func);
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

int q6(int n, int amount, const int entry_fee[n])
{
    int low = 0, high = n - 1, m = (low + high) / 2;
    while (low != high && entry_fee[m] != amount)
    {

        if (entry_fee[m] > amount)
        {
            high = m - 1;
        }
        else
        {
            low = m + 1;
        }
        m = (low + high) / 2;
    }
    if (entry_fee[m] == amount)
    {
        if (entry_fee[m + 1] != amount)
            return m + 1;
        else
        {
            while (entry_fee[m] <= amount && m < n)
            {
                m++;
            }
            return m;
        }
    }
    else
    {
        if (amount < entry_fee[low])
            return low;
        else
            return low + 1;
    }
}

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

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    int src = 0, a = 0, flag = 0, value = 0;
    heap_t To_be_inserted;
    node_e nodes[n * n], next;
    init_heap(&To_be_inserted, n * n, nodes);
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    while (not_full(n, visited))
    {
        visited[src] = 1;
        for (int i = 0; i < n; i++)
        {
            if (connections[src][i].time != 0 && connections[src][i].time != INT_MAX)
            {
                To_be_inserted.arr[To_be_inserted.size].i = src;
                To_be_inserted.arr[To_be_inserted.size].j = i;
                To_be_inserted.arr[To_be_inserted.size].time = connections[src][i].time;
                To_be_inserted.size++;
            }
        }
        heapify(&To_be_inserted);
        while (flag == 0 && To_be_inserted.size > 0)
        {
            next = extract_max(&To_be_inserted);
            if ((visited[next.i] == 0 && visited[next.j] == 1) || (visited[next.i] == 1 && visited[next.j] == 0))
            {
                edges[a].first = next.i;
                edges[a].second = next.j;
                value += next.time;
                a++;
                flag = 1;
            }
        }
        flag = 0;
        if (visited[next.i] == 0)
        {
            src = next.i;
        }
        else
        {
            src = next.j;
        }
    }
    return value;
}

void q10(int n, int k, const airport_t *src, const connection_t connections[n][n], const int destinations[k], int costs[k])
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
        relax_edge(n, &heap, selected, connections);
        selected[i] = extract_maxs(&heap);
    }
    shortest_path(n, k, selected, destinations, costs);
}

// END

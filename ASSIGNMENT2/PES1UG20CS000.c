#include "header.h"
#include <limits.h>
// ANY STATIC FUNCTIONS ARE UP HERE
static void swap(airport_t *arr, int a, int b)
{
    airport_t temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
 static int partition(airport_t *arr, int low, int high,int (*predicate_func)(const airport_t *, const airport_t *))
{
    airport_t pivot_ele = arr[low];
    int i = low + 1, j = high;
    while (j >= i)
    {
        while (i <= high && !predicate_func(&pivot_ele,&arr[i]))
        {
            i++;
        }
        while (j > low && predicate_func(&pivot_ele,&arr[j]))
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

static void quicksort(airport_t *arr, int low, int high,int (*predicate_func)(const airport_t *, const airport_t *))
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

// ************************YOUR SOLUTIONS BELOW****************************

int q1(int n, const connection_t connections[n][n])
{
    return 0;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k,
       const connection_t connections[n][n])
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
    return 0;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n])
{
     quicksort(airport_list,0,n-1,predicate_func);
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
    int low = 0, high = n-1, m = (low+high) / 2;
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
        m = (low+high) / 2;
    }
    if (entry_fee[m] == amount)
    {
        if (entry_fee[m + 1] != amount)
            return m + 1;
        else
        {
            while (entry_fee[m] <= amount && m<n)
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
    return 0;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    return 0;
}

void q10(int n, int k, const airport_t *src,
         const connection_t connections[n][n], const int destinations[k],
         int costs[k])
{
}

// END

#include <stdio.h>
#include <stdlib.h>

typedef struct vinfo
{
    int vid;
    int d;
    int p;
} vinfo;

struct heap
{
    vinfo *arr;
    int size;
    int max_size;
};
typedef struct heap heap_t;

void init_heap(heap_t *heap, int max_size, vinfo *n_selected)
{
    heap->size = max_size;
    heap->max_size = max_size;
    heap->arr = n_selected; // allocating memory for array
}
void heapify(heap_t *heap)
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

vinfo extract_max(heap_t *heap)
{
    if (heap->size > 0)
    {
        vinfo max = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapify(heap);
        return max;
    }
}
int find(heap_t *heap, int a)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (a == heap->arr[i].vid)
        {
            return i;
        }
    }
}
int find_s(vinfo *selected, int a)
{
    for (int i = 0; i < 5; i++)
    {
        if (a == selected[i].vid)
        {
            return i;
        }
    }
}
void printpath(vinfo *selected, int *stack,int index,int *i)
{
    if(selected[index].p == 0){
        return ;
    }
    else{
        *i += 1;
        index = selected[index].p;
        index = find_s(selected,index);
        stack[(*i)] = selected[index].vid;
        printpath(selected,stack,index,i);
    }
}
void relax_edge(heap_t *heap, vinfo *selected, int graph[5][5])
{
    int source = heap->arr[0].vid, index = 0;
    for (int i = 0; i < 5; i++)
    {
        if (graph[source][i] != 9999)
        {
            index = find(heap, i);
            if (heap->arr[index].d > graph[source][i] + heap->arr[0].d)
            {
                heap->arr[index].d = graph[source][i] + heap->arr[0].d;
                heap->arr[index].p = source;
            }
        }
    }
}
void shortest_path(vinfo *selected)
{
    int stack[5],index = 0,stack_i;
    for (int i = 1; i < 5; i++)
    {
        stack_i=-1;
        index = find_s(selected, i);
        printf("The shortest distance  0-%d is: %d\n The path followed is:\n", i,selected[index].d);
        printpath(selected,stack,index,&stack_i);
        printf("0-");
        for (int j =stack_i; j >=0 ; j--){
            printf("%d-",stack[j]);
        }
        printf("%d\n",i);
    }
}
void init_struct(heap_t *heap, int size)
{
    heap->arr[0].d = 0;
    heap->arr[0].p = 0;
    heap->arr[0].vid = 0;
    for (int i = 1; i < size; i++)
    {
        heap->arr[i].d = 9999;
        heap->arr[i].p = -1;
        heap->arr[i].vid = i;
    }
}

int main()
{
    vinfo selected[5];
    vinfo n_selected[5];
    int source = 0;
    int graph[5][5] = {{9999, 10, 3, 9999, 9999}, {9999, 9999, 1, 2, 9999}, {9999, 4, 9999, 8, 2}, {9999, 9999, 9999, 9999, 7}, {9999, 9999, 9999, 9, 9999}};
    heap_t heap;
    init_heap(&heap, 5, n_selected);
    init_struct(&heap, 5);
    for (int i = 0; i < 5; i++)
    {
        relax_edge(&heap, selected, graph);
        selected[i] = extract_max(&heap);
    }
    shortest_path(selected);
}

#include <stdio.h>
#include <stdlib.h>
struct heap
{
    int *arr;
    int size;
    int max_size;
};

typedef struct heap heap_t;

void init_heap(heap_t *heap, int max_size) {
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = malloc(heap->max_size * sizeof(int));
}
void heapify(heap_t *heap, int *count_ptr)
{
    int p ,temp = 0,flag,c;
    for (int i = heap->size / 2; i >= 1; i--)
    {
        p = i;
        c = 2 * p;
         flag = 0;
        while (p >= 1 && flag == 0)
        {
            if ((c + 1) <= heap->size && heap->arr[c] < heap->arr[c + 1])
            {
                *count_ptr = *count_ptr + 2;
                c = c + 1;
            }
            *count_ptr = *count_ptr + 1;
            if (heap->arr[c] > heap->arr[p])
            {
                temp = heap->arr[p];
                heap->arr[p] = heap->arr[c];
                heap->arr[c] = temp;
                c = p;
                p = c/2;
            }
            else
                flag = 1;
        }
    }
}
void insert(heap_t *heap, int key, int *count_ptr)
{
    
        if (heap->size < heap->max_size)
        {
            heap->size++;
            heap->arr[heap->size] = key;
        }
        heapify(heap, count_ptr);
}

void copy_array(heap_t *dst, const int *src, int n)
{
    int c = 0;
    for (int i = 0; i < n; ++i)
    {
        c = 0;
        insert(dst, src[i], &c);
    }
}
int search(const heap_t *heap, int key, int *count_ptr)
{
    if (heap->size > 1)
    {
        *count_ptr = *count_ptr + 1;
        for (int i = 1; i <= heap->size / 2; i++)
        {
            if (key < heap->arr[i])
            {
                *count_ptr = *count_ptr + 3;
                if (2 * i <= heap->size  && heap->arr[2 * i] == key)
                    return key;
                if (2 * i + 1 <= heap->size && heap->arr[2 * i + 1] == key)
                    return key;
            }
        }
        return -1;
    }
    else if (heap->size == 1)
    {
        *count_ptr = *count_ptr + 3;
        if (heap->arr[1] == key)
            return key;
        else
            return -1;
    }
    else
    {
        *count_ptr = *count_ptr + 2;
        return -1;
    }
}
int extract_max(heap_t *heap, int *count_ptr)
{
    if (heap->size > 0)
    {
        *count_ptr = *count_ptr + 1;
        int max = heap->arr[1];
        heap->arr[1] = heap->arr[heap->size];
        heap->size--;
        heapify(heap,count_ptr);
        return max;
    }
    else
    {
        return -1;
    }
}
int main()
{
    const int n = 11;
    heap_t h;
    init_heap(&h, n);
    int a[] = {6, 3, 7, 4,8,9,1};
    copy_array(&h, a, 7);
    int c = 0,b=0;
    b = extract_max(&h, &c);
    b = search(&h,4, &c);  
}

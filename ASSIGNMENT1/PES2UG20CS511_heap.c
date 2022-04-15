// Name:JAYENDRA GANESH DEVISETTI
// SRN:PES2UG20CS511
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size)
{
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = malloc(heap->max_size * sizeof(int));
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void heapify(heap_t *heap, int *count_ptr)
{
    int p, temp = 0, flag = 0, c;
    for (int i = heap->size / 2; i >= 1; i--)
    {
        p = i;
        c = 2 * p;
        flag = 0;
        while (p <= heap->size / 2 && flag == 0)
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
void insert(heap_t *heap, int key, int *count_ptr)
{

    *count_ptr = *count_ptr + 1;
    if (heap->size < heap->max_size)
    {
        heap->size++;
        heap->arr[heap->size] = key;
    }
    heapify(heap, count_ptr);
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
    if (heap->size > 0)
    {
        *count_ptr = *count_ptr + 1;
        int max = heap->arr[1];
        heap->arr[1] = heap->arr[heap->size];
        heap->size--;
        heapify(heap, count_ptr);
        return max;
    }
    else
    {
        return -1;
    }
}

// Searches for the element key in the heap
// Returns the element if found, else -1
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
                if (2 * i <= heap->size && heap->arr[2 * i] == key)
                {
                    return key;
                }
                if (2 * i + 1 <= heap->size && heap->arr[2 * i + 1] == key)
                {
                    return key;
                }
            }
        }
        return -1;
    }
    else if (heap->size == 1)
    {
        *count_ptr = *count_ptr + 3;
        if (heap->arr[1] == key)
        {
            return key;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        *count_ptr = *count_ptr + 2;
        return -1;
    }
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
    if (heap->size > 0)
    {
        *count_ptr = *count_ptr + 1;
        return heap->arr[1];
    }
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr)
{

    if (heap->size >= 1)
    {
        *count_ptr = *count_ptr + 1;
        int min = heap->arr[1];
        for (int i = 1; i <= heap->size / 2; i++)
        {
            *count_ptr = *count_ptr + 2;
            if (2 * i <= heap->size)
            {
                min = heap->arr[2 * i];
            }
            if (2 * i + 1 <= heap->size && heap->arr[2 * i + 1] < min)
            {
                min = heap->arr[2 * i + 1];
            }
        }
        return min;
    }
    else
    {
        *count_ptr = *count_ptr + 1;
        return -1;
    }
}

// Clears the heap for reuse
void clear_heap(heap_t *heap)
{
    heap->size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap)
{
    free(heap->arr);
}

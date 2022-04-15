// Name: Sanjana.S
// SRN: PES2UG20CS549
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
    heap->arr = (int *)malloc(max_size * sizeof(int)); // allocating memory for array
}

static int *heapify(int *arr, int n, int *count_ptr)
{
    int p;
    int key;
    int l;
    int r;
    for (int i = n / 2; i >= 1; i--) // bottom-up approach
    {
        p = i; // parent
        key = arr[i];
        int over = 0;
        while (!over && 2 * p <= n)
        {
            *count_ptr = *count_ptr + 2;  // taking multiplication as basic operation since its performed twice
            l = 2 * p;                    // left child
            r = l + 1;                    // right child
            if (l < n && arr[l] < arr[r]) // checking if right child or left right is greater
            {
                ++l;
            }
            if (key >= arr[l]) // exiting loop if parent is greater than left child
            {
                over = 1;
            }
            else
            {
                arr[p] = arr[l];
                p = l;
            }
        }
        arr[p] = key;
    }
    return arr;
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr)
{
    if (heap->size < heap->max_size)
    {
        *count_ptr = *count_ptr + 1;
        int i = ++heap->size; // incrementing size of heap
        heap->arr[i] = key;
        heap->arr = heapify(heap->arr, heap->size, count_ptr); // calling heapify
    }
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
    int max;
    if (heap->size == 0)
    {
        max = -1;
    }
    else
    {
        max = heap->arr[1];                     // extracting the max element
        heap->arr[1] = heap->arr[heap->size--]; // removing the max element
        heapify(heap->arr, heap->size, count_ptr);
    } // calling heapify to restructure the max heap
    return max;
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr)
{
    int p = 1;
    while (p < heap->size)
    {
        if (heap->arr[p] == key)
        {
            *count_ptr = *count_ptr + 1;
            return key; // key found
        }
        else
        {
            *count_ptr = *count_ptr + 2;
            int l = 2 * p;           // left child
            int r = 2 * p + 1;       // right child
            if (heap->arr[l] == key) // checking the left child
            {
                *count_ptr = *count_ptr + 1;
                return key;
            }
            else if (heap->arr[r] == key) // checking the right child
            {
                *count_ptr = *count_ptr + 2;
                return key;
            }
        }
        p++;
    }
    return -1; // key not found
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
    if (heap->size == 0)
    {
        *count_ptr = *count_ptr + 1;
        return -1;
    }
    else
    {
        *count_ptr = *count_ptr + 1;
        return heap->arr[1];
    }
}

static int find_min_call(int *arr, int min, int i, int size, int *count_ptr)
{
    if (arr[2 * i] < min) // checking left child
    {
        *count_ptr = *count_ptr + 2;
        return arr[2 * i];
    }
    else if (arr[2 * i + 1] < min) // checking right child
    {
        *count_ptr = *count_ptr + 3;
        return arr[2 * i + 1];
    }
    return min;
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr)
{
    int min;
    if (heap->size == 0)
    {
        *count_ptr = *count_ptr + 1;
        min = -1;
        ;
    }
    else
    {
        min = heap->arr[heap->size / 2];
        for (int i = (heap->size / 2); i >= 1; i--)
        {
            *count_ptr = *count_ptr + 1;
            min = find_min_call(heap->arr, min, i, heap->size, count_ptr);
        }
    }
    return min;
}

// Clears the heap for reuse
void clear_heap(heap_t *heap)
{
    heap->size = 0; // assigning heap to NULL for reuse
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap)
{
    free(heap->arr);
}
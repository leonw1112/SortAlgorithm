#include <iostream>
#include "heapify.h"
#include "heap.h"
using namespace std;

void HeapSort::sort(int array[], int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // Heap sort
    for (int i = size - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);

        // Heapify root element to get the highest element at root again
        heapify(array, i, 0);
    }
}
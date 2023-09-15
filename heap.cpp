#include <heapify.h>
#include <iostream>

using namespace std;

void heapsort(int array[], int size)
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
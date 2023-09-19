#include <iostream>
#include "heapify.h"
#include "heap.h"
#include <ctime>
using namespace std;

void HeapSort::sort(int array[], int size)
{
    clock_t start = clock();
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
    clock_t end = clock();

    double timeDifference = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Difference in ms: " << timeDifference << " ms" << std::endl;
}
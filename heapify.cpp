#include <iostream>

using namespace std;
void heapify(int array[], int size, int i)
{
    // Find largest among root, left child, and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapify(array, size, largest);
    }
}
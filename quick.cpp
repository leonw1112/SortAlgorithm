#include "partition.h"

void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int pos = partition(array, low, high, pivot);

        quicksort(array, low, pos - 1);
        quicksort(array, pos + 1, high);
    }
}
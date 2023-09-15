
#include "quick.h"

void QuickSort::sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int pos = partition(array, low, high, pivot);

        sort(array, low, pos - 1);
        sort(array, pos + 1, high);
    }
}
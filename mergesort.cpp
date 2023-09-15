#include <merge.h>

void mergesort(int *array, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(array, low, mid);
        mergesort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
#include "quick.h"
#include <ctime>
void QuickSort::sort(int *array, int low, int high)
{
    clock_t start = clock();
    sortinternal(array, low, high);
    clock_t end = clock();

    double timeDifference = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    timelist.push_back(timeDifference);
    std::cout << "Difference in ms: " << timeDifference << " ms" << std::endl;
}
void QuickSort::sortinternal(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int pos = partition(array, low, high, pivot);

        sortinternal(array, low, pos - 1);
        sortinternal(array, pos + 1, high);
    }
}
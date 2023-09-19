#include "mergesort.h"
#include <ctime>
#include <iostream>
void MergeSort::sort(int *array, int low, int high)
{
    clock_t start = clock();
    sortinternal(array, low, high);
    clock_t end = clock();

    double timeDifference = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    timelist.push_back(timeDifference);
    std::cout << "Difference in ms: " << timeDifference << " ms" << std::endl;
}
void MergeSort::sortinternal(int *array, int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        sortinternal(array, low, mid);
        sortinternal(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void MergeSort::merge(int *array, int low, int mid, int high)
{

    int i = low, j = mid + 1;
    int *temp = new int[high - low + 1];
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = array[j];
        j++;
        k++;
    }
    for (int l = 0; l < k; l++)
    {
        array[low + l] = temp[l];
    }
    delete[] temp;
}

#include "insertion.h"

void InsertionSort::sort(int *array, int size)
{
    for (int step = 1; step < size; step++)
    {
        int cvalue = array[step];
        int j = step - 1;

        while (cvalue < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = cvalue;
    }
}
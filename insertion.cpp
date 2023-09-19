#include "insertion.h"
#include <ctime>
#include <iostream>
void InsertionSort::sort(int *array, int size)
{
    clock_t start = clock();
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
    clock_t end = clock();

    double timeDifference = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Difference in ms: " << timeDifference << " ms" << std::endl;
}
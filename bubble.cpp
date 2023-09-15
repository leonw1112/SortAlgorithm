#include <iostream>
#include <stdlib.h>

#include "bubble.h"

using namespace std;

void BubbleSort::sort(int *array, int length)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < length - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

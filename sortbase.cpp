
#include <iostream>
#include "sortbase.h"

using namespace std;

void SortBase::myswap(int *array, int pos1, int pos2)
{
    int temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int SortBase::partition(int array[], int low, int high, int pivot)
{
    int i = low;
    int j = low;
    while (i <= high)
    {
        if (array[i] > pivot)
        {
            i++;
        }
        else
        {
            myswap(array, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void SortBase::print(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << endl;
    }
}
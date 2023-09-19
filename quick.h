#ifndef __QUICK__
#define __QUICK__

#include "sortbase.h"

class QuickSort : public SortBase
{
public:
    void sort(int *array, int low, int high);

private:
    void sortinternal(int *array, int low, int high);
};

#endif

#ifndef __SORTBASE__
#define __SORTBASE__

class SortBase
{
protected:
    void myswap(int *array, int pos1, int pos2);
    int partition(int array[], int low, int high, int pivot);

public:
    void print(int *array, int size);
};

#endif

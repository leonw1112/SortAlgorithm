#include "sortbase.h"

class MergeSort : public SortBase
{
public:
    void sort(int *array, int low, int high);

private:
    void merge(int *array, int low, int mid, int high);
    void sortinternal(int *array, int low, int high);
};
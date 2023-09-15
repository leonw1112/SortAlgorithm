class MergeSort
{
public:
    void sort(int *array, int low, int high);

private:
    void merge(int *array, int low, int mid, int high);
};
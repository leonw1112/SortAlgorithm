int partition(int array[], int low, int high, int pivot)
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
            swap(array, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}
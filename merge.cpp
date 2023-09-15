void merge(int *array, int low, int mid, int high)
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

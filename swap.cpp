void swap(int *array, int pos1, int pos2)
{
    int temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}
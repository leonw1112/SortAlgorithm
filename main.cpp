#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void bubblesort(int *array, int length)
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

void swap(int *array, int pos1, int pos2)
{
    int temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

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

void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int pos = partition(array, low, high, pivot);

        quicksort(array, low, pos - 1);
        quicksort(array, pos + 1, high);
    }
}

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

void mergesort(int *array, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(array, low, mid);
        mergesort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
void insertionsort(int *array, int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void heapify(int array[], int size, int i)
{
    // Find largest among root, left child, and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapify(array, size, largest);
    }
}

void heapsort(int array[], int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // Heap sort
    for (int i = size - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);

        // Heapify root element to get the highest element at root again
        heapify(array, i, 0);
    }
}

int *readNumbers(int &size)
{
    const string fileName = "list.txt";

    ifstream infile(fileName.c_str());

    if (!infile)
    {
        cerr << "Error: Unable to open file." << endl;
        exit(1);
    }

    int sizeFromFile;
    infile >> sizeFromFile;
    size = sizeFromFile;

    int *numbers = new int[size];

    for (int i = 0; i < size; ++i)
    {
        infile >> numbers[i];
    }

    return numbers;
}

int main()
{

    int size;
    int *array = readNumbers(size);

    string algo;
    cout << "Which algorithm do you want to use? (Bubble, Quick, Merge, Insertion, Heap): ";
    cin >> algo;
    clock_t start = clock();
    if (algo == "Bubble")
    {
        bubblesort(array, size);

        // Output the sorted list
        for (int i = 0; i < size; ++i)
        {
            cout << array[i] << endl;
        }
    }
    else if (algo == "Quick") // Changed to "else if"
    {
        quicksort(array, 0, size - 1);
        // Output the sorted list
        for (int i = 0; i < size; ++i)
        {
            cout << array[i] << endl;
        }
    }
    else if (algo == "Merge")
    {
        mergesort(array, 0, size - 1);
        // Output the sorted list
        for (int i = 0; i < size; ++i)
        {
            cout << array[i] << endl;
        }
    }
    else if (algo == "Insertion")
    {
        insertionsort(array, size);
        // Output the sorted list
        for (int i = 0; i < size; ++i)
        {
            cout << array[i] << endl;
        }
    }
    else if (algo == "Heap")
    {
        heapsort(array, size);
        // Output the sorted list
        for (int i = 0; i < size; ++i)
        {
            cout << array[i] << endl;
        }
    }
    else
    {
        cout << "Invalid algorithm choice." << endl;
    }

    delete[] array;
    clock_t end = clock();

    double timeDifference = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

    std::cout << "Difference in ms: " << timeDifference << " ms" << std::endl;

    return 0;
}
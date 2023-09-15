#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <vector>
#include <algorithm>
// #include "sortbase.h"
#include "bubble.h"
#include "quick.h"
#include "mergesort.h"
#include "insertion.h"
#include "heapify.h"
#include "heap.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        cout << "Please enter a parameter. (type ./main help)"
             << "\n";
        exit(1);
    }
    char operation[6][16]{
        "help",
        "bubble",
        "quick",
        "merge",
        "insertion",
        "heap"};

    const string fileName = "list.txt";

    ifstream fin(fileName.c_str());

    if (!fin)
    {
        cerr << "Error: File "
             << "'list.txt'"
             << " not found." << endl;
        exit(1);
    }
    vector<int> v;
    int c;
    while (fin >> c)
    {
        v.push_back(c);
    }
    int array[v.size()];
    copy(v.begin(), v.end(), array);

    clock_t start = clock();

    if (strcmp(argv[1], operation[1]) == 0)
    {
        cout << "Running bubblesort." << endl;

        BubbleSort s;
        s.sort(array, v.size());

        s.print(array, v.size());
    }
    else if (strcmp(argv[1], operation[2]) == 0) // Changed to "else if"
    {
        cout << "Running quicksort." << endl;
        QuickSort s;
        s.sort(array, 0, v.size() - 1);

        s.print(array, v.size());
    }
    else if (strcmp(argv[1], operation[3]) == 0)
    {
        cout << "Running mergesort." << endl;
        MergeSort s;
        s.sort(array, 0, v.size() - 1);
    }
    else if (strcmp(argv[1], operation[4]) == 0)
    {
        cout << "Running insertionsort." << endl;
        InsertionSort s;
        s.sort(array, v.size());
    }
    else if (strcmp(argv[1], operation[5]) == 0)
    {
        cout << "Running heapsort." << endl;

        HeapSort s;
        s.sort(array, v.size());
    }
    else if (strcmp(argv[1], operation[0]) == 0)
    {
        cout << "----------";
        cout << "Operations:\n bubble \n quick \n merge \n insertion \n heap \n";
    }
    else
    {
        cout << "Invalid algorithm choice." << endl;
    }

    clock_t end = clock();

    double timeDifference = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

    std::cout << "Difference in ms: " << timeDifference << " ms" << std::endl;
    cout << "Processed " << v.size() << " elements"
         << " with " << argv[1] << endl;

    return 0;
}
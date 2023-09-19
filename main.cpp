#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <vector>
#include <algorithm>
#include "bubble.h"
#include "quick.h"
#include "mergesort.h"
#include "insertion.h"
#include "heapify.h"
#include "heap.h"
using namespace std;

int main(int argc, char *argv[])
{
    // char linp;
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

    int inps;
    int inpc;
    cout << "How often do you want to sort?: ";
    cin >> inps;
    cout << "How many numbers?: ";
    cin >> inpc;

    if (strcmp(argv[1], operation[1]) == 0)
    {
        cout << "Running bubblesort." << endl;
        BubbleSort s;
        int bubblearr[inpc];
        for (int i = 0; i < inps; i++)
        {
            vector<int> arr = s.listgenarray(inpc);
            copy(arr.begin(), arr.end(), bubblearr);
            s.sort(bubblearr, arr.size());
        }
        s.printmean();
    }
    else if (strcmp(argv[1], operation[2]) == 0) // Changed to "else if"
    {
        cout << "Running quicksort." << endl;
        QuickSort s;
        int quickarr[inpc];
        for (int i = 0; i < inps; i++)
        {
            vector<int> arr = s.listgenarray(inpc);
            copy(arr.begin(), arr.end(), quickarr);
            s.sort(quickarr, 0, arr.size() - 1);
        }
        s.printmean();
    }
    else if (strcmp(argv[1], operation[3]) == 0)
    {
        cout << "Running mergesort." << endl;
        MergeSort s;
        int mergearr[inpc];
        for (int i = 0; i < inps; i++)
        {
            vector<int> arr = s.listgenarray(inpc);
            copy(arr.begin(), arr.end(), mergearr);
            s.sort(mergearr, 0, arr.size() - 1);
        }
        s.printmean();
    }
    else if (strcmp(argv[1], operation[4]) == 0)
    {
        cout << "Running insertionsort." << endl;
        InsertionSort s;
        int insertionarr[inpc];
        for (int i = 0; i < 10; i++)
        {
            vector<int> arr = s.listgenarray(inpc);
            copy(arr.begin(), arr.end(), insertionarr);
            s.sort(insertionarr, arr.size());
        }
        s.printmean();
    }
    else if (strcmp(argv[1], operation[5]) == 0)
    {
        cout << "Running heapsort." << endl;

        HeapSort s;
        int heaparr[inpc];
        for (int i = 0; i < 10; i++)
        {
            vector<int> arr = s.listgenarray(inpc);
            copy(arr.begin(), arr.end(), heaparr);
            s.sort(heaparr, arr.size());
        }
        s.printmean();
    }
    else if (strcmp(argv[1], operation[0]) == 0)
    {
        cout << "---------- \n";
        cout << "Operations:\n bubble \n quick \n merge \n insertion \n heap \n listgen \n";
    }
    else
    {
        cout << "Invalid algorithm choice." << endl;
        exit(0);
    }
    // cout << "Processed " << v.size() << " elements"
    // << " with " << argv[1] << endl;

    return 0;
}
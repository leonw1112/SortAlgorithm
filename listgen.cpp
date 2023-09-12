#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int num;

    cout << "How many numbers should be generated?: ";
    cin >> num;

    ofstream NumList("list.txt");

    for (int i = 0; i < num; i++)
    {
        NumList << rand() % num << "\n";
    }
    NumList.close();
    return 0;
}
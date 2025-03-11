#include "LineCount.h"
#include <iostream>
#include <fstream>
using namespace std;

int LineCount::countLines(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "error has occured file couldnt be opened" << endl;
        return -1;
    }

    string line;
    int count = 0;

    while (getline(file, line))
    {
        count++;
    }
    file.close();
    return count;
}
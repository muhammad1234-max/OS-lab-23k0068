#include "WordCount.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int WordCount::countWords(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "error file couldnt open" << endl;
        return -1;
    }

    string word;
    int count = 0;
    while (file >> word)
    {
        count++;
    }
    file.close();
    return count;
}
#include "LetterCount.h"
#include <iostream>
#include <fstream>
using namespace std;

int LetterCount::countLetters(const string &filename)
{
    ifstream file(filename);
    // if file doesnt open
    if (!file)
    {
        cerr << "error in opening file" << endl;
        return -1;
    }

    char ch;
    int count = 0;
    while (file.get(ch))
    {
        if (isalpha(ch))
        {
            count++;
        }
    }
    file.close();
    return count;
}
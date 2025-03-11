#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"
#include <iostream>
using namespace std;

int main()
{
    string filename = "input.txt";

    LetterCount letterCounter;
    WordCount wordCounter;
    LineCount lineCounter;

    int letters = letterCounter.countLetters(filename);
    int words = wordCounter.countWords(filename);
    int lines = lineCounter.countLines(filename);

    if (letters != -1)
        std::cout << "Number of letters: " << letters << std::endl;
    if (words != -1)
        std::cout << "Number of words: " << words << std::endl;
    if (lines != -1)
        std::cout << "Number of lines: " << lines << std::endl;

    return 0;
}
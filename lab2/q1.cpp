#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int *arr = new int[argc - 1];
    int sum = 1;
    int avg;

    if (argc < 2)
    {
        cerr << "Error: No integers provided.\n";
        cerr << "Usage: " << argv[0] << " <integer1> <integer2> ...\n";
        return 1;
    }

    for (int i = 0; i < argc - 1; i++)
    {
        arr[i] = atoi(argv[i + 1]);
        sum = sum + arr[i];
    }

    avg = sum / argc;

    cout << "the sum is " << sum << " and the average is " << avg << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Function to find the missing number in a sequence
int findMissingNumber(const vector<int>& nums) {
    int n = nums.size() + 1; // Since one number is missing, total numbers should be (size+1)
    int expectedSum = n * (n + 1) / 2; // Sum of first N natural numbers
    int actualSum = 0;

    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <list of integers>\n";
        return 1;
    }

    vector<int> numbers;

    // Convert command-line arguments to integers and store them in the array
    for (int i = 1; i < argc; i++) {
        numbers.push_back(atoi(argv[i]));
    }

    // Find the missing number
    int missing = findMissingNumber(numbers);

    // Write the missing number to a file
    ofstream outFile("missing.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing.\n";
        return 1;
    }
    outFile << "Missing Number: " << missing << endl;
    outFile.close();

    cout << "Missing number found and written to missing.txt\n";

    return 0;
}

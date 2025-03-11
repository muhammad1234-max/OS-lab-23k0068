#include <iostream>
#include <fstream>
#include <vector>
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

int main() {
    ifstream inputFile("numbers.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file!\n";
        return 1;
    }

    vector<int> numbers;
    int num;

    // Read integers from file and store them in the vector
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();

    if (numbers.empty()) {
        cerr << "Error: File is empty or contains no valid integers!\n";
        return 1;
    }

    // Find the missing number
    int missing = findMissingNumber(numbers);

    // Write the missing number to an output file
    ofstream outFile("missing.txt");
    if (!outFile) {
        cerr << "Error: Could not open output file for writing.\n";
        return 1;
    }
    outFile << "Missing Number: " << missing << endl;
    outFile.close();

    cout << "Missing number found and written to missing.txt\n";

    return 0;
}

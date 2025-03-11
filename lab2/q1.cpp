#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    // Check if a file name is provided as a command-line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    // Open the file
    std::ifstream file(argv[1]);

    // Check if the file opened successfully
    if (!file) {
        std::cerr << "Error: Could not open file " << argv[1] << "\n";
        return 1;
    }

    // Read and display the file contents
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }

    // Close the file
    file.close();
    
    return 0;
}

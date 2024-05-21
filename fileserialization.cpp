#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> readDataFromFile(const std::string& filename) {
    std::ifstream inputFile(filename, std::ios::in | std::ios::binary);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open input file.");
    }

    std::vector<int> data;
    int value;
    while (inputFile.read(reinterpret_cast<char*>(&value), sizeof(int))) {
        data.push_back(value);
    }

    inputFile.close();
    return data;
}

void writeDataToFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream outputFile(filename, std::ios::out | std::ios::binary);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Could not open output file.");
    }

    for (const int& value : data) {
        outputFile.write(reinterpret_cast<const char*>(&value), sizeof(int));
    }

    outputFile.close();
}

int main() {
    try {
        const std::string inputFileName = "input.dat";
        const std::string outputFileName = "output.dat";

        std::vector<int> data = readDataFromFile(inputFileName);

        std::sort(data.begin(), data.end());

        writeDataToFile(outputFileName, data);

        std::cout << "Data sorted and written to " << outputFileName << " successfully." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

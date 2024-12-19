/*# Assignment 2
## Author
Basmanov Rodion Gennadievich B81-mm
## Contacts
st135699@student.spbu.ru
## Description
Home assingment 2a*/

#include "reverse.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace file_operations {

    void reverseFileContent() {
        std::string inputFile = "input.txt";
        if (!std::filesystem::exists(inputFile)) {
            std::cerr << "File not found: " << inputFile << "\n";
            return;
        }

        std::uintmax_t fileSize = std::filesystem::file_size(inputFile);

        std::ifstream infile(inputFile, std::ios::binary | std::ios::in);
        if (!infile) {
            std::cerr << "Failed to open file: " << inputFile << "\n";
            return;
        }

        char* buffer = new char[fileSize];

        if (!infile.read(buffer, fileSize)) {
            std::cerr << "Error reading file: " << inputFile << "\n";
            delete[] buffer;
            infile.close();
            return;
        }
        infile.close();

        for (std::uintmax_t i = 0; i < fileSize / 2; ++i) {
            std::swap(buffer[i], buffer[fileSize - 1 - i]);
        }

        std::string outputFile = "reversed_" + inputFile;

        std::ofstream outfile(outputFile, std::ios::binary | std::ios::out);
        if (!outfile) {
            std::cerr << "Failed to create output file: " << outputFile << "\n";
            delete[] buffer;
            return;
        }
        outfile.write(buffer, fileSize);
        outfile.close();

        delete[] buffer;

        std::cout << "File has been reversed successfully. Output file: " << outputFile << "\n";
    }
}
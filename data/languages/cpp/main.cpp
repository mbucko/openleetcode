#include "problemtest.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

bool openFileForWriting(const std::string &filename, std::ofstream &out) {
    const auto parent_path =
        std::filesystem::path(filename).parent_path();

    if (!std::filesystem::exists(parent_path) ||
        !std::filesystem::is_directory(parent_path)) {
        std::cerr << "Directory " << parent_path << " does not exist"
                  << std::endl;
    }

    std::ofstream outfile(filename);

    if (!outfile.is_open()) {
        std::cerr << "Unable to open file for writing";
        return false;
    }

    out = std::move(outfile);
    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file>"
                  << std::endl;
        return 1;
    }

    const std::string inputFile = argv[1];
    const std::string outputFile = argv[2];

    std::ifstream in(inputFile);
    if (!in) {
        std::cerr << "Error: Could not open input file: " << inputFile
                  << std::endl;
        return 1;
    }

    std::ofstream out;
    if (!openFileForWriting(outputFile, out)) {
        std::cerr << "Error: Could not open output file: " << outputFile
                  << std::endl;
        return 1;
    }

    ProblemTest problemTest(std::move(in), std::move(out));

    const bool success = problemTest.run();

    return success ? 0 : 1;
}

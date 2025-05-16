// C++
#include "xRAP_core-save.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

void saveGridToFile(const std::vector<std::vector<int>>& grid, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    if (grid.empty())
        return;
    size_t numCols = grid.size();
    size_t numRows = grid[0].size();
    // Iterate rows in reverse order so that the top row is output first.
    for (int row = static_cast<int>(numRows) - 1; row >= 0; row--) {
        for (size_t col = 0; col < numCols; col++) {
            file << grid[col][row] << " ";
        }
        file << "\n";
    }
    file.close();
}

void saveLandMaskToFile(const std::vector<std::vector<std::vector<int>>>& mask, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    // Process each layer similarly.
    for (const auto& layer : mask) {
        if (layer.empty())
            continue;
        size_t numCols = layer.size();
        size_t numRows = layer[0].size();
        for (int row = static_cast<int>(numRows) - 1; row >= 0; row--) {
            for (size_t col = 0; col < numCols; col++) {
                file << layer[col][row] << " ";
            }
            file << "\n";
        }
        file << "\n";
    }
    file.close();
}
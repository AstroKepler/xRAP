//
// Created by kepler1b on 5/16/25.
//

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

    for (const auto& row : grid) {
        for (const auto& value : row) {
            file << value << " ";
        }
        file << "";
    }

    file.close();
}

void saveLandMaskToFile(const std::vector<std::vector<std::vector<int>>>& mask, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& layer : mask) {
        for (const auto& row : layer) {
            for (const auto& value : row) {
                file << value << " ";
            }
            file << "";
        }
        file << "";
    }

    file.close();
}
//
// Created by kepler1b on 5/16/25.
//

#ifndef XRAP_CORE_SAVE_H
#define XRAP_CORE_SAVE_H
#include <vector>
#include <string>
void saveGridToFile(const std::vector<std::vector<int>>& grid, const std::string& filename);
void saveLandMaskToFile(const std::vector<std::vector<std::vector<int>>>& mask, const std::string& filename);
#endif //XRAP_CORE_SAVE_H

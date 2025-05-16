//
// Created by kepler1b on 5/16/25.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <vector>

constexpr int max_height = 1821; // Max terrain height

std::vector<std::vector<std::vector<int>>> land_mask;
std::vector<std::vector<int>> height_grid;

std::pair<std::vector<std::vector<int>>, std::vector<std::vector<std::vector<int>>>> generateHeightData(const char* filename, int grid_width, int grid_height) {
    int width, height, channels;

    unsigned char* img = stbi_load(filename, &width, &height, &channels, 1); // Load as grayscale
    std::cout << "Image dimensions: " << width << "x" << height << std::endl;
    if (!img) {
        std::cerr << "Error loading image!" << std::endl;
        return {};
    }

    if (width != grid_width || height != grid_height) {
        std::cerr << "Heightmap size mismatch!" << std::endl;
        stbi_image_free(img);
        return {};
    }

    // Resize vectors to match the grid size
    land_mask.resize(grid_width, std::vector<std::vector<int>>(grid_height, std::vector<int>(max_height)));
    height_grid.resize(grid_width, std::vector<int>(grid_height));

    for (int y = 0; y < grid_height; y++) {
        for (int x = 0; x < grid_width; x++) {
            int pixel_value = img[y * width + x]; // Grayscale intensity (0-255)

            height_grid[x][y] = pixel_value * max_height / 255; // Scale terrain height

            for (int z = 0; z < max_height; z++) {
                land_mask[x][y][z] = (pixel_value > 0) ? 1 : 0;
            }
        }
    }

    stbi_image_free(img);
    return {height_grid, land_mask};
}

#include <iostream>
#include <fstream>
#include <vector>
#include <temperature_solver.h>
#include <xRAP_core-save.h>
#include <xRAP_core-height.h>
#include "xRAP_core.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::cout << "Initialising Variables...";
    constexpr int max_height = 1821;
    constexpr int H_grid_size = 256;
    constexpr int V_grid_size = 256;
    constexpr int depth = 64;
    std::vector<std::vector<std::vector<float>>> temperature_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));
    std::vector<std::vector<std::vector<float>>> pressure_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));
    std::vector<std::vector<std::vector<float>>> dewpoint_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));
    std::vector<std::vector<std::vector<float>>> wind_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));
    std::vector<std::vector<std::vector<float>>> cloud_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));
    std::vector<std::vector<std::vector<float>>> shortwave_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));
    std::vector<std::vector<std::vector<float>>> rain_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));
    std::vector<std::vector<std::vector<float>>> fog_vector(
    depth, std::vector<std::vector<float>>(H_grid_size, std::vector<float>(V_grid_size, 0.0f)));

    const float max_lat = -38.30;  // Bottom-right latitude
    const float max_lon = 154.7;   // Bottom-right longitude

    std::vector<std::vector<std::pair<float, float>>> base_coordinates(H_grid_size, std::vector<std::pair<float, float>>(V_grid_size));

    for (int x = 0; x < H_grid_size; x++) {
        for (int y = 0; y < V_grid_size; y++) {
            constexpr float lat_step = 0.049609375;
            constexpr float lon_step = 0.041796875;
            constexpr float zero_lon = 142.0;
            constexpr float zero_lat = -28.13;
            float lat = zero_lat - (y * lat_step); // Decreasing latitude as we move down
            float lon = zero_lon + (x * lon_step); // Increasing longitude as we move right
            base_coordinates[x][y] = {lat, lon};  // Storing (latitude, longitude) coordinates
        }
    }
    auto [height_grid, land_mask] = generateHeightData("../HEIGHT_DATA.png", H_grid_size, V_grid_size);
    saveGridToFile(height_grid, "height_grid.txt");
    saveLandMaskToFile(land_mask, "land_mask.txt");


    std::cout << "Initialised Variables" << std::endl;
    std::cout << size(height_grid) << " bytes";





    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
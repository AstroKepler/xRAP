//
// Created by kepler1b on 5/18/25.
//

#include "xRAP_core-utils.h"
#include <cmath>

bool isInteger(float num) {
    return std::fmod(num, 1.0f) == 0.0f;
}
//
// Created by kepler1b on 5/15/25.
//

#include "xRAP_core.h"

void start_simulation(const int t_step_size, const int t_steps, const int t_sub_steps, const int duration) {
    for (int i = 0; i < t_sub_steps; i++) {
        // Calculate Data

        if (i % t_step_size == 0) {
            // Save Data at that step
        }
    }

}

void time_step() {
    /*
     *  TIME STEP
     *
     */

    // Temperature Solver
    // Dewpoint Solver
    // MLSP Solver
    // Wind Solver
    // Temperature Advector
    // Dewpoint Advector
    // Cloud Solver
    // Shortwave Solver
    // Rain Solver
    // Fog Solver

}

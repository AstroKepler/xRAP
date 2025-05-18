//
// Created by kepler1b on 5/15/25.
//

#include <iostream>
#include <xRAP_core.h>
#include <xRAP_core-utils.h>
#include <temperature_solver.h>

int step_num = 0;



void time_step(const int t_sub_steps) {

    step_num++;

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

void start_simulation(const int t_steps, const int t_sub_steps) {

    std::cout << "Time Sub Steps " << t_sub_steps << std::endl;
    std::cout << "Main Time Steps " << t_steps << std::endl;
    for (int i = 0; i < (t_steps*24)+1; i++) {
        // Calculate Data
        time_step(t_sub_steps);
        if (i % 24 == 0) {
            // Save Data at that step
            std::cout << "Full Step completed: " << i/24 << std::endl;
        } else {
            std::cout << "Sub Integer step: " << i << std::endl;
        }

    }

}
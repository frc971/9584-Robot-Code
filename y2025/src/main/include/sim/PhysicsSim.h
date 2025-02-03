#pragma once

#include "sim/TalonFXSimProfile.h"

#include <ctre/phoenix6/TalonFX.hpp>
#include <vector>

/**
 * Manages physics simulation for CTRE products.
 */
class PhysicsSim {
    PhysicsSim() {};

    std::vector<SimProfile *> _simProfiles{};

public:
    /**
     * Gets the robot simulator instance.
     */
    static PhysicsSim& GetInstance() {
        static PhysicsSim sim{};
        return sim;
    }

    /**
     * Adds a TalonFX controller to the simulator.
     * 
     * @param talonFX
     *        The TalonFX device
     * @param rotorInertia
     *        Rotational Inertia of the mechanism at the rotor
     */
    void AddTalonFX(ctre::phoenix6::hardware::TalonFX& talonFX, units::kilogram_square_meter_t rotorInertia);

    /**
     * Runs the simulator:
     * - enable the robot
     * - simulate sensors
     */
    void Run();
};

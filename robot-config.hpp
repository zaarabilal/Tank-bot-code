#pragma once
#include "api.hpp"

// extern brain Brain;
extern const double RPM;                      // max rotational velocity

// constants
extern const pros::motor_encoder_units_e_t encoder_units;
extern const pros::motor_gearset_e_t driveGearset;
extern const pros::motor_gearset_e_t rollerGearset;
extern const pros::motor_gearset_e_t intakeGearset;

// motors
extern pros::Controller master;
extern pros::Motor left_mtr_front;
extern pros::Motor left_mtr_back;
extern pros::Motor left_mtr_middle;
extern pros::Motor left_mtr_front_bottom;
extern pros::Motor right_mtr_front;
extern pros::Motor right_mtr_back;
extern pros::Motor right_mtr_front_bottom;
extern pros::Motor right_mtr_middle;
extern pros::Motor_Group leftDrive;
extern pros::Motor_Group rightDrive;
// extern pros::Motor rollerMotor;
// extern pros::Motor intakeMotorA;
// extern pros::Motor intakeMotorB;
// extern pros::Motor_Group intake;
// extern pros::Motor catapultMotor;
extern std::vector<pros::Motor> motorList;

//sensors
extern pros::ADIDigitalIn catapultSwitch;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void motorInit(void);
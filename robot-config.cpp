#include "robot-config.hpp"

extern const double RPM = 600;
// VEXcode generated functions
// define variable for remote controller enable/disable
// bool RemoteControlCodeEnabled = true;
//extern const pros::motor_encoder_units_e_t encoder_units = pros::E_MOTOR_ENCODER_ROTATIONS;
// extern const pros::motor_gearset_e_t driveGearset = pros::E_MOTOR_GEAR_600;
// extern const pros::motor_gearset_e_t rollerGearset = pros::E_MOTOR_GEAR_100;
// extern const pros::motor_gearset_e_t intakeGearset = pros::E_MOTOR_GEAR_200;

// device constructors
extern pros::Controller master(pros::E_CONTROLLER_MASTER);
extern pros::Motor left_mtr_front(11, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
	extern pros::Motor right_mtr_front_bottom(13, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
	extern pros::Motor right_mtr_middle(17, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
	extern pros::Motor right_mtr_front(14, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
	extern pros::Motor right_mtr_back(12, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
	extern pros::Motor left_mtr_back(15, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
	extern pros::Motor left_mtr_front_bottom(18, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
	extern pros::Motor left_mtr_middle(16, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// extern pros::Motor leftDriveMotorA = pros::Motor(18, driveGearset, true, encoder_units);
// extern pros::Motor leftDriveMotorB = pros::Motor(8, driveGearset, false, encoder_units);//out
// extern pros::Motor leftDriveMotorC = pros::Motor(15, driveGearset, true, encoder_units);
// extern pros::Motor leftDriveMotorD = pros::Motor(10, driveGearset, true, encoder_units);//?
extern pros::Motor_Group leftDrive = pros::Motor_Group({left_mtr_front, left_mtr_back, left_mtr_front_bottom, left_mtr_middle});
// extern pros::Motor rightDriveMotorA = pros::Motor(13, driveGearset, false, encoder_units);//out
// extern pros::Motor rightDriveMotorB = pros::Motor(17, driveGearset, true, encoder_units);//out
// extern pros::Motor rightDriveMotorC = pros::Motor(9, driveGearset, false, encoder_units);
// extern pros::Motor rightDriveMotorD = pros::Motor(7, driveGearset, false, encoder_units);
extern pros::Motor_Group rightDrive = pros::Motor_Group({right_mtr_front, right_mtr_back, right_mtr_front_bottom, right_mtr_middle});
// extern pros::Motor rollerMotor = pros::Motor(2, rollerGearset, false, encoder_units);
// extern pros::Motor intakeMotorA = pros::Motor(3, intakeGearset, false, encoder_units);
// extern pros::Motor intakeMotorB = pros::Motor(4, intakeGearset, true, encoder_units);
// extern pros::Motor_Group intake = pros::Motor_Group({intakeMotorA, intakeMotorB});
// extern pros::Motor catapultMotor = pros::Motor(1, rollerGearset, true, encoder_units);

// sensors
//extern pros::ADIDigitalIn catapultSwitch = pros::ADIDigitalIn(8);

extern std::vector<pros::Motor> motorList = {
    left_mtr_front,
    left_mtr_back,
    left_mtr_front_bottom,
    left_mtr_middle,
    right_mtr_front,
    right_mtr_back,
    right_mtr_front_bottom,
    right_mtr_middle};

    // leftDriveMotorA,
    // leftDriveMotorB,
    // leftDriveMotorC,
    // leftDriveMotorD,
    // rightDriveMotorA,
    // rightDriveMotorB,
    // rightDriveMotorC,
    // rightDriveMotorD,
    // rollerMotor,
    // intakeMotorA,
    // intakeMotorB,
    // catapultMotor};
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void motorInit(void)
{
    pros::motor_brake_mode_e_t brakeMode = pros::E_MOTOR_BRAKE_BRAKE;
    for (pros::Motor motor : motorList)
    {
        motor.set_brake_mode(brakeMode);
    }
}
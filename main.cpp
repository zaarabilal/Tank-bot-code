#include "main.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		pros::lcd::set_text(2, "I was pressed!");
	}
	else
	{
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Robot is working");

	pros::lcd::register_btn1_cb(on_center_button);
	motorInit();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
	while (true)
	{
		master.set_text(0, 1, "Ready to Start");
		master.set_text(1, 1, "Battery Level: " + std::to_string(pros::battery::get_capacity()));
		pros::delay(50);
	}
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize()
{
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
using namespace Auton;
void autonomous()
{
	setup();
	driveForward(10.0, 0.5, 0.5);
	pros::delay(100);
	driveBackward(4.0, 0.5, 0.5);
	pros::delay(100);
	turnLeft(180, 0.3, 0.3);
	pros::delay(100);
	turnRight(45, 0.5,0.5);
	//driveForward(6.0, 0.5, 0.5);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
	while (true){
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		pros::lcd::set_text(2, "LEFT Y: " + std::to_string(left));
		pros::lcd::set_text(3, "RIGHT Y: " + std::to_string(right));

		double speed = 0.7;

		int deadzone = 20;
		int joystickLeftY = master.get_analog(ANALOG_LEFT_Y);
		if (abs(joystickLeftY) < deadzone)
		{
			joystickLeftY = 0;
		}
		int joystickLeftX = master.get_analog(ANALOG_LEFT_X);
		if (abs(joystickLeftX) < deadzone)
		{
			joystickLeftX = 0;
		}
		int joystickRightY = master.get_analog(ANALOG_RIGHT_Y);
		if (abs(joystickRightY) < deadzone)
		{
			joystickRightY = 0;
		}
		int joystickRightX = master.get_analog(ANALOG_RIGHT_X);
		if (abs(joystickRightX) < deadzone)
		{
			joystickRightX = 0;
		}

		leftDrive.move_voltage(joystickLeftY / 127.0 * 12000 );
		rightDrive.move_voltage(joystickRightY / 127.0 * 12000 );

		pros::delay(20);
	}
}






// #include "main.h"
// #include <ghost_tank/tank_wheel_odom.hpp>
// // #include <ghost_util/angle_util.hpp>
// // #include "rclcpp/rclcpp.hpp"
// #include <cmath>
// #include <iostream>

// /**
//  * A callback function for LLEMU's center button.
//  *
//  * When this callback is fired, it will toggle line 2 of the LCD text between
//  * "I was pressed!" and nothing.
//  */
// void on_center_button() {
// 	static bool pressed = false;
// 	pressed = !pressed;
// 	if (pressed) {
// 		pros::lcd::set_text(2, "I was pressed!");
// 	} else {
// 		pros::lcd::clear_line(2);
// 	}
// }

// /**
//  * Runs initialization code. This occurs as soon as the program is started.
//  *
//  * All other competition modes are blocked by initialize; it is recommended
//  * to keep execution time for this mode under a few seconds.
//  */
// void initialize() {
// 	pros::lcd::initialize();
// 	pros::lcd::set_text(1, "Hello PROS User!");

// 	pros::lcd::register_btn1_cb(on_center_button);
// }

// /**
//  * Runs while the robot is in the disabled state of Field Management System or
//  * the VEX Competition Switch, following either autonomous or opcontrol. When
//  * the robot is enabled, this task will exit.
//  */
// void disabled() {}

// /**
//  * Runs after initialize(), and before autonomous when connected to the Field
//  * Management System or the VEX Competition Switch. This is intended for
//  * competition-specific initialization routines, such as an autonomous selector
//  * on the LCD.
//  *
//  * This task will exit when the robot is enabled and autonomous or opcontrol
//  * starts.
//  */
// void competition_initialize() {}

// /**
//  * Runs the user autonomous code. This function will be started in its own task
//  * with the default priority and stack size whenever the robot is enabled via
//  * the Field Management System or the VEX Competition Switch in the autonomous
//  * mode. Alternatively, this function may be called in initialize or opcontrol
//  * for non-competition testing purposes.
//  *
//  * If the robot is disabled or communications is lost, the autonomous task
//  * will be stopped. Re-enabling the robot will restart the task, not re-start it
//  * from where it left off.
//  */
// void autonomous() {}


// // using ghost_util::WrapAngle2PI;





// /**
//  * Runs the operator control code. This function will be started in its own task
//  * with the default priority and stack size whenever the robot is enabled via
//  * the Field Management System or the VEX Competition Switch in the operator
//  * control mode.
//  *
//  * If no competition control is connected, this function will run immediately
//  * following initialize().
//  *
//  * If the robot is disabled or communications is lost, the
//  * operator control task will be stopped. Re-enabling the robot will restart the
//  * task, not resume it from where it left off.
//  */
// void opcontrol() {
// 	pros::Controller master(pros::E_CONTROLLER_MASTER );
// 	pros::Motor left_mtr_front(11, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// 	pros::Motor right_mtr_front_bottom(13, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// 	pros::Motor right_mtr_middle(17, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// 	pros::Motor right_mtr_front(14, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// 	pros::Motor right_mtr_back(12, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, false, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// 	pros::Motor left_mtr_back(15, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// 	pros::Motor left_mtr_front_bottom(18, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);
// 	pros::Motor left_mtr_middle(16, pros::motor_gearset_e_t::E_MOTOR_GEAR_600, true, pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_COUNTS);

// 	double wheel_rotations_to_motor_rotations = 48.0/36.0;

// 	while (true) {
// 		int left = master.get_analog(ANALOG_LEFT_Y);
// 		int right = master.get_analog(ANALOG_RIGHT_Y);

		

// 		std::cout << "Right Motor: " << right_mtr_front.get_position() << std::endl;

// 		// right_mtr_front.move_voltage(right / 127.0 * 12000);
// 		// right_mtr_back.move_voltage(right / 127.0 * 12000);
// 		// left_mtr_front.move_voltage(left / 127.0 * 12000);
// 		// left_mtr_back.move_voltage(left / 127.0 * 12000);
// 		// left_mtr_front_bottom.move_voltage(left / 127.0 * 12000);
// 		// left_mtr_middle.move_voltage(left/ 127.0 * 12000);
// 		// right_mtr_front_bottom.move_voltage(right / 127.0 * 12000);
// 		// right_mtr_middle.move_voltage(right/ 127.0 * 12000);

// 		pros::delay(20);
// 	}


// 	namespace ghost_tank {

// TankOdometry::TankOdometry(){
// 	std::cout << "Constructor" << std::endl;
// }

// void TankOdometry::updateEncoders(double left_wheel, double right_wheel){
// 	std::cout << "updateEncoders" << std::endl;

// 	double prevencoderleft = 0;
// 	double prevencoderright = 0;
// 	// const double ticks = 300;       // get total number of ticks on encoder per revolution
// 	// const double circumference = 10.2101761242 ;  // circumference of wheels in inches
// 	// const double Rwheel = 5.5;       // get distance between wheel and center of robot (should be same for both sides?)
// 	double Xinitial = 0;        // initial position of robot
// 	double Yinitial = 0;        // initial position of robot
// 	double initialAngle = 0;    // initial angle of robot
// 	double prevX = 0;
// 	double prevY = 0;
// 	// m_Xposition = Xinitial;
// 	// m_Yposition = Yinitial;
// 	// m_Angle = initialAngle;

// 	// while(true){
// 	// for initial encoder reading
// 	if((m_Xposition == Xinitial) && (m_Yposition == Yinitial) ){
// 		prevX = m_Xposition;
// 		prevY = m_Yposition;
// 	}

// 	double encoderleft = left_wheel; // get value from encoder
// 	double encoderright = right_wheel; // get value from encoder
// 	double distanceleft = (((encoderleft - prevencoderleft) / m_ticks) * m_circumference);   // getting distance traveled by left encoder
// 	double distanceright = (((encoderright - prevencoderright) / m_ticks) * m_circumference);  // distance traveled by right encoder

// 	prevencoderleft = encoderleft;
// 	prevencoderright = encoderright;


// 	m_deltaAngle = ((distanceright - distanceleft) / 2 * m_Wheeldistance);    // find change in angle


// 	// for straight motion, both distances should be equal?
// 	if(distanceleft == distanceright){
// 		m_Xposition += distanceleft * cos(m_Angle);   // add x component of distance to previous position
// 		m_Yposition += distanceright * sin(m_Angle);  // add y component of distance to previous position
// 		m_Angle += m_deltaAngle;

// 		if(m_Angle > M_PI){
// 			m_Angle -= 2 * M_PI;
// 		}
// 		if(m_Angle < -M_PI){
// 			m_Angle += 2 * M_PI;
// 		}
// 	}
// 	else if(distanceleft == -distanceright){   // turning in place
// 		m_Xposition = m_Xposition;
// 		m_Yposition = m_Yposition;
// 		m_deltaAngle = ((distanceright) / m_Wheeldistance);
// 		m_Angle += m_deltaAngle;
// 			if(m_Angle > M_PI){
// 				m_Angle -= 2 * M_PI;
// 			}
// 			if(m_Angle < -M_PI){
// 				m_Angle += 2 * M_PI;
// 			}
// 	}

// 	else{
// 		double distance = ((distanceleft + distanceright) / 2); // distance traveled by robot
// 		double deltaX = (distance * cos(m_deltaAngle));
// 		double deltaY = (distance * sin(m_deltaAngle));
// 		// new_xpos = (m_Xposition*cos(deltaAngle) - m_Yposition*sin(deltaAngle)+ distance)
// 		// change to global coordinates
// 		m_Xposition += deltaX;
// 		m_Yposition += deltaY;
// 		m_Angle += m_deltaAngle;
// 		if(m_Angle > M_PI){
// 			m_Angle -= 2 * M_PI;
// 		}
// 		if(m_Angle < -M_PI){
// 			m_Angle += 2 * M_PI;
// 		}
// 		// probably need linear algebra here or something to make sure shift is relative to world
// 	}
// 	// WrapAngle2PI(m_Angle);
// }

// std::vector<double> TankOdometry::getRobotPositionWorld(){
// 	std::cout << "getRobotPositionWorld" << std::endl;
// 	return {m_Xposition, m_Yposition, m_Angle};
// }
// 	}
// }


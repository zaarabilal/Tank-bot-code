#pragma once
// #include "rclcpp/rclcpp.hpp"
#include <memory>
#include <vector>

namespace ghost_tank {

class TankOdometry {
public:
	TankOdometry();
	void setAngle(double angle) {
		m_Angle = angle;
	}

	void setXPosition(double x) {
		m_Xposition = x;
	}

	void setYPosition(double y) {
		m_Yposition = y;
	}

	void updateEncoders(double left_wheel, double right_wheel);

	std::vector<double> getRobotPositionWorld();
private:
	double m_Xposition = 0.0;
	double m_Yposition = 0.0;
	double m_Angle = 0.0;
	double m_deltaAngle = 0.0;
	const double m_ticks = 300;
	const double m_Wheeldistance = 5.5;
	const double m_circumference = 10.2101761242;
};

}
#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include <ctre/Phoenix.h>

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:

	static std::shared_ptr<WPI_TalonSRX> FLrotationMotor;
	static std::shared_ptr<WPI_TalonSRX> FLdriveMotor;
	static std::shared_ptr<AnalogPotentiometer> FLrotationEncoder;

	static std::shared_ptr<WPI_TalonSRX> FRrotationMotor;
	static std::shared_ptr<WPI_TalonSRX> FRdriveMotor;
	static std::shared_ptr<AnalogPotentiometer> FRrotationEncoder;

	static std::shared_ptr<WPI_TalonSRX> BLrotationMotor;
	static std::shared_ptr<WPI_TalonSRX> BLdriveMotor;
	static std::shared_ptr<AnalogPotentiometer> BLrotationEncoder;

	static std::shared_ptr<WPI_TalonSRX> BRrotationMotor;
	static std::shared_ptr<WPI_TalonSRX> BRdriveMotor;
	static std::shared_ptr<AnalogPotentiometer> BRrotationEncoder;

	static void init();
};
#endif



#ifndef ROBOTMAP_H
#define ROBOTMAP_H


#include "WPILib.h"
#include "AnalogPotentiometer.h"
#include "ctre\Phoenix.h"

class RobotMap {
public:

	static std::shared_ptr<WPI_TalonSRX> FRDriveMotor;
	static std::shared_ptr<WPI_TalonSRX> FRRotationMotor;

	static std::shared_ptr<WPI_TalonSRX> FLDriveMotor;
	static std::shared_ptr<WPI_TalonSRX> FLRotationMotor;

	static std::shared_ptr<WPI_TalonSRX> BRDriveMotor;
	static std::shared_ptr<WPI_TalonSRX> BRRotationMotor;

	static std::shared_ptr<WPI_TalonSRX> BLDriveMotor;
	static std::shared_ptr<WPI_TalonSRX> BLRotationMotor;

	static std::shared_ptr<AnalogPotentiometer> FRAbsEncoder;

	static std::shared_ptr<AnalogPotentiometer> FLAbsEncoder;

	static std::shared_ptr<AnalogPotentiometer> BRAbsEncoder;

	static std::shared_ptr<AnalogPotentiometer> BLAbsEncoder;


	static void init();
};
#endif

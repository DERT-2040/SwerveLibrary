

#ifndef ROBOTMAP_H
#define ROBOTMAP_H


#include "WPILib.h"
#include "SwerveModule.h"
#include "C:\Users\Carter DiOrio\Documents\Talon\include\ctre\Phoenix.h"

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

	static std::shared_ptr<AnalogInput> FRAbsEncoder;

	static std::shared_ptr<AnalogInput> FLAbsEncoder;

	static std::shared_ptr<AnalogInput> BRAbsEncoder;

	static std::shared_ptr<AnalogInput> BLAbsEncoder;

	static void init();
};
#endif

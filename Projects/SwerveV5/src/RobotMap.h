#ifndef ROBOTMAP_H
#define ROBOTMAP_H


#include <WPILib.h>
#include <ctre/Phoenix.h>

class RobotMap {

public:

	static void init();

	static std::shared_ptr<WPI_TalonSRX> FLDrive;
	static std::shared_ptr<WPI_TalonSRX> FLRotation;
	static std::shared_ptr<AnalogPotentiometer> FLrotationEncoder;

	static std::shared_ptr<WPI_TalonSRX> FRDrive;
	static std::shared_ptr<WPI_TalonSRX> FRRotation;
	static std::shared_ptr<AnalogPotentiometer> FRrotationEncoder;

	static std::shared_ptr<WPI_TalonSRX> BLDrive;
	static std::shared_ptr<WPI_TalonSRX> BLRotation;
	static std::shared_ptr<AnalogPotentiometer> BLrotationEncoder;

	static std::shared_ptr<WPI_TalonSRX> BRDrive;
	static std::shared_ptr<WPI_TalonSRX> BRRotation;
	static std::shared_ptr<AnalogPotentiometer> BRrotationEncoder;

};
#endif

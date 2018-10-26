#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include <WPILib.h>
#include "../RobotMap.h"
#include "../SwerveDrive.h"

class DriveTrain: public frc::Subsystem {

private:


public:

	DriveTrain();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Drive(Joystick *left, Joystick *right);
	module *FL, *FR, *BL, *BR;

	_swervedrive *modules;

	SwerveDrive *swerve;

};

#endif

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Swerve/SwerveDrive.h"

class DriveTrain: public frc::Subsystem
{

public:

	DriveTrain();
	void InitDefaultCommand() override;
	void Periodic() override;
	void drive(Joystick *left, Joystick *right);
	double angleT = 0;
private:

	SwerveDrive *swerve;

};

#endif

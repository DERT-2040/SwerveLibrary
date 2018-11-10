#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/DriveWithJoySticks.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain")
{
	swerve = new SwerveDrive;
	/*
	swerve->getModule(0).setOffset(209);
	swerve->getModule(1).setOffset(129);
	swerve->getModule(2).setOffset(180);
	*/

	swerve->FL->setOffset(-135);
	swerve->FL->setAngle(0);

	swerve->FR->setOffset(-64);
	swerve->FR->setAngle(0);

	swerve->BL->setOffset(-42);
	swerve->BL->setAngle(0);

	swerve->BR->setOffset(75);
	swerve->BR->setAngle(0);
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoysticks);
}

void DriveTrain::Periodic()
{
	SmartDashboard::PutString("DB/String 0", std::to_string(swerve->getModule(0).getAngle()));
	SmartDashboard::PutString("DB/String 1", std::to_string(swerve->getModule(1).getAngle()));
	SmartDashboard::PutString("DB/String 2", std::to_string(swerve->getModule(2).getAngle()));
	SmartDashboard::PutString("DB/String 3", std::to_string(swerve->getModule(3).getAngle()));

	//angleT = SmartDashboard::GetNumber("DB/String 5", 0);


}

void DriveTrain::drive(Joystick *left, Joystick *right)
{
	/*
	swerve->FL->setAngle(angleT);
	swerve->FR->setAngle(angleT);
	swerve->BL->setAngle(angleT);
	swerve->BR->setAngle(angleT);
	if(angleT >= 360) angleT = 0;
	angleT++;
	*/
	//swerve->drive(right->GetX()*-1, right->GetY()*-1, left->GetX());
	swerve->drive(left->GetRawAxis(4), left->GetRawAxis(5), left->GetRawAxis(0));
	SmartDashboard::PutString("DB/String 5", std::to_string(left->GetRawAxis(4)));
	SmartDashboard::PutString("DB/String 6", std::to_string(left->GetRawAxis(5)));

}




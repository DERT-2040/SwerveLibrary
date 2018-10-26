#include "DriveTrain.h"
#include "../Commands/JoystickDrive.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain")
{

	FL->driveMotor = RobotMap::FLdriveMotor.get();
	FL->rotationMotor = RobotMap::FLrotationMotor.get();
	FL->rotationEncoder = RobotMap::FLrotationEncoder.get();

	/*
	FR->driveMotor = RobotMap::FRdriveMotor.get();
	FR->rotationMotor = RobotMap::FRrotationMotor.get();
	FR->rotationEncoder = RobotMap::FRrotationEncoder.get();

	BL->driveMotor = RobotMap::BLdriveMotor.get();
	BL->rotationMotor = RobotMap::BLrotationMotor.get();
	BL->rotationEncoder = RobotMap::BLrotationEncoder.get();

	BR->driveMotor = RobotMap::BRdriveMotor.get();
	BR->rotationMotor = RobotMap::BRrotationMotor.get();
	BR->rotationEncoder = RobotMap::BRrotationEncoder.get();

	modules->FL = new SwerveModule(FL);
	modules->FR = new SwerveModule(FR);
	modules->BL = new SwerveModule(BL);
	modules->BR = new SwerveModule(BR);
	modules->trackWidth = 9.312;
	modules->wheelBase = 13.146;

	swerve = new SwerveDrive(modules);
	*/
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new JoystickDrive());
}

void DriveTrain::Periodic()
{
	SmartDashboard::PutString("DB/String 0", std::to_string(swerve->getModule(0).getPosition()));
	/*
	SmartDashboard::PutString("DB/String 1", std::to_string(swerve->getModule(1).getPosition()));
	SmartDashboard::PutString("DB/String 2", std::to_string(swerve->getModule(2).getPosition()));
	SmartDashboard::PutString("DB/String 3", std::to_string(swerve->getModule(3).getPosition()));
	*/
}

void DriveTrain::Drive(Joystick *left, Joystick *right)
{
	//swerve->Drive(right->GetX(), right->GetY(), left->GetX());
}




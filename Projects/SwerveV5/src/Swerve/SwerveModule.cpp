/*
 * SwerveModule.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: FIRSTMentor
 */

#include "SwerveModule.h"
#include <ctre/Phoenix.h>

SwerveModule::SwerveModule(std::shared_ptr<AnalogPotentiometer> _rotationEncoder, std::shared_ptr<WPI_TalonSRX> _driveMotor, std::shared_ptr<WPI_TalonSRX> _rotationMotor)
{
	driveMotor = _driveMotor;
	rotationMotor = _rotationMotor;
	rotationEncoder = _rotationEncoder;

	rotationPID = new PIDController(0.06, 0.0, 0.001, 0.0, rotationEncoder.get(), rotationMotor.get(), .01);
	rotationPID->SetInputRange(-180 , 180);
	rotationPID->SetContinuous(true);
	rotationPID->SetOutputRange(-.50, .50);
	rotationPID->SetEnabled(true);

	angle = 0;
	offset = 0;

}

void SwerveModule::setSpeed(double speed)
{
	driveMotor->Set(speed);
}

void SwerveModule::setAngle(double _angle)
{
	angle = _angle + offset;
	if(angle > 180) angle -= 360;
	if(angle < -180) angle += 360;
	rotationPID->SetSetpoint(angle);
}

void SwerveModule::setOffset(double _offset)
{
	offset = _offset;
}

double SwerveModule::getAngle()
{
	return rotationEncoder->Get();
}


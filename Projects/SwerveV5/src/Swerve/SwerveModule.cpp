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

	rotationPID = new PIDController(0.03, 0.0, 0.001, 0.0, rotationEncoder.get(), rotationMotor.get(), .01);
	rotationPID->SetContinuous(true);
	rotationPID->SetInputRange(0.0 , 360.0);
	rotationPID->SetOutputRange(-.5, .5);
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
	if(angle > 360) angle -= 360;
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


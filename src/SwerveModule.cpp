/*
 * SwerveModule.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: FIRSTMentor
 */

#include "SwerveModule.h"

SwerveModule::SwerveModule(const module *m)
{

	rotationMotor = m->rotationMotor;
	rotationEncoder = m->rotationEncoder;
	driveMotor = m->driveMotor;
	position = 0;
	rotationOffset = 0;
	rotationPID = new PIDController(P, I, D, 0.0, rotationEncoder, rotationMotor);
	rotationPID->SetContinuous(true);
	rotationPID->SetInputRange(0, 360);
	rotationPID->SetEnabled(true);
	rotationPID->SetOutputRange(-1,1);
}

void SwerveModule::setPosition(double degree)
{
	position = degree + rotationOffset;
	if(position > 360) position -= 360;
	rotationPID->SetSetpoint(position);
}

void SwerveModule::setSpeed(double speed)
{
	driveMotor->Set(speed);
}

double SwerveModule::getPosition()
{
	//return rotationEncoder->Get() + rotationOffset;
	//return rotationEncoder->Get();
	return 0;
}

void SwerveModule::setRotationOffset(double offset)
{
	rotationOffset = offset;
}








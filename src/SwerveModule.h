/*
 * SwerveModule.h
 *
 *  Created on: Sep 2, 2018
 *      Author: FIRSTMentor
 */

#ifndef SWERVEMODULE_H_
#define SWERVEMODULE_H_

#include "WPILib.h"
#include <ctre/Phoenix.h>

struct module
{
	WPI_TalonSRX *rotationMotor;
    WPI_TalonSRX *driveMotor;
    AnalogPotentiometer *rotationEncoder;
};

class SwerveModule {

public:

	SwerveModule(const module *m);
	void setPosition(double degree);
	void setSpeed(double speed);
	void setRotationOffset(double offset);
	double getPosition();

private:

	double P = 0;
	double I = 0;
	double D = 0;
	double rotationOffset;
	double position;

	WPI_TalonSRX *rotationMotor;
    WPI_TalonSRX *driveMotor;
    AnalogPotentiometer *rotationEncoder;

	PIDController *rotationPID;

};

#endif /* SWERVEMODULE_H_ */

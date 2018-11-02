/*
 * SwerveModule.h
 *
 *  Created on: Oct 25, 2018
 *      Author: FIRSTMentor
 */

#ifndef SRC_SWERVEMODULE_H_
#define SRC_SWERVEMODULE_H_

#include <ctre/Phoenix.h>
#include "WPILib.h"

class SwerveModule
{

	public:

		SwerveModule(std::shared_ptr<AnalogPotentiometer> re, std::shared_ptr<WPI_TalonSRX> dm, std::shared_ptr<WPI_TalonSRX> rm);
		void setAngle(double _angle);
		void setOffset(double _offset);
		void setSpeed(double speed);
		double getAngle();

	private:

		double offset;
		double angle;

		std::shared_ptr<AnalogPotentiometer> rotationEncoder;
		std::shared_ptr<WPI_TalonSRX> driveMotor;
		std::shared_ptr<WPI_TalonSRX> rotationMotor;

		PIDController *rotationPID;

};

#endif /* SRC_SWERVEMODULE_H_ */

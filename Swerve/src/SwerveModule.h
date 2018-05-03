/*
 * SwerveModule.h
 *
 *  Created on: May 2, 2018
 *      Author: Carter DiOrio
 */

#ifndef SRC_SWERVEMODULE_H_
#define SRC_SWERVEMODULE_H_

#include "RobotMap.h"
#include "C:\Users\Carter DiOrio\Documents\Talon\include\ctre\Phoenix.h"

class SwerveModule {
public:


	SwerveModule(std::shared_ptr<AnalogInput> absE , std::shared_ptr<WPI_TalonSRX> rMotor);
	virtual ~SwerveModule();

	double getDegrees();


private:

	std::shared_ptr<AnalogInput> absEncoder;
	std::shared_ptr<WPI_TalonSRX> rotationMotor;

};

#endif /* SRC_SWERVEMODULE_H_ */

/*
 * SwerveModule.cpp
 *
 *  Created on: May 2, 2018
 *      Author: Carter DiOrio
 */

#include "SwerveModule.h"

SwerveModule::SwerveModule(std::shared_ptr<AnalogInput> absE , std::shared_ptr<WPI_TalonSRX> rMotor) {

	absEncoder = absE;
	rotationMotor = rMotor;

}

double SwerveModule::getDegrees()
{
	return absEncoder->GetVoltage()*72;
}

SwerveModule::~SwerveModule() {
	// TODO Auto-generated destructor stub
}


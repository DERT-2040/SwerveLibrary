/*
 * SwerveDrive.h
 *
 *  Created on: Sep 8, 2018
 *      Author: FIRSTMentor
 */

#ifndef SWERVEDRIVE_H_
#define SWERVEDRIVE_H_

#include "SwerveModule.h"
#include <cmath>

struct _swervedrive
{
	SwerveModule *FL;
	SwerveModule *FR;
	SwerveModule *BL;
	SwerveModule *BR;
	double trackWidth;
	double wheelBase;
};

class SwerveDrive
{

public:

	SwerveDrive(const _swervedrive *sd);
	void Drive(double xComponent, double yComponent, double angularVelocity);
	SwerveModule getModule(int module);

private:

	SwerveModule *FL;
	SwerveModule *FR;
	SwerveModule *BL;
	SwerveModule *BR;

	double wheelBase;
	double trackWidth;
	double startingPosition = 0;

	double A = 0;
	double B = 0;
	double C = 0;
	double D = 0;
	double wheelAngle[4];
	double wheelSpeed[4];
};

#endif /* SWERVEDRIVE_H_ */

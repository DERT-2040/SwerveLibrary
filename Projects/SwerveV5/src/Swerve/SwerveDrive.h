/*
 * SwerveDrive.h
 *
 *  Created on: Oct 25, 2018
 *      Author: FIRSTMentor
 */

#ifndef SRC_SWERVE_SWERVEDRIVE_H_
#define SRC_SWERVE_SWERVEDRIVE_H_

#include "SwerveModule.h"
#include <cmath>

class SwerveDrive
{
	public:

		SwerveDrive();
		void drive(double robotX, double robotY, double omega);
		SwerveModule getModule(int module);
		SwerveModule *FL, *FR, *BL, *BR;

	private:


		double A, B, C, D;
		double wheelAngle[4];
		double wheelSpeed[4];
		double wheelBase;
		double trackWidth;

};

#endif /* SRC_SWERVE_SWERVEDRIVE_H_ */

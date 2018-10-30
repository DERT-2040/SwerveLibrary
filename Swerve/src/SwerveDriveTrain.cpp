/*
 * SwerveDriveTrain.cpp
 *
 *  Created on: May 2, 2018
 *      Author: Carter DiOrio
 */

#include "SwerveDriveTrain.h"

SwerveDriveTrain::SwerveDriveTrain(struct swerve_drive)
{


	A = 0;
	B = 0;
	C = 0;
	D = 0;

	double temp = 0;

	FLPosition = temp;
	FRPosition = temp;
	BLPosition = temp;
	BRPosition = temp;

	wheelbase = WB;
	trackwidth = TW;
	radius = sqrt(pow(WB,2) + pow(TW,2));

	FL = new SwerveModule(FLAbsEncoder , FLRotation);
	FR = new SwerveModule(FRAbsEncoder , FRRotation);
	BL = new SwerveModule(BLAbsEncoder , BLRotation);
	BR = new SwerveModule(BRAbsEncoder , BRRotation);

	//set rotation offset for each module
	FL->setRotationOffSet(0);
	FR->setRotationOffSet(0);
	BR->setRotationOffSet(0);
	BL->setRotationOffSet(0);

	FL->setRotationPosition(FLPosition);
	FR->setRotationPosition(FRPosition);
	BL->setRotationPosition(BLPosition);
	BR->setRotationPosition(BRPosition);

}

void SwerveDriveTrain::drive(double xValJoy1 , double xValJoy2 , double yValJoy2)
{
	if(xValJoy1 < 0.1 && xValJoy1 > -0.1)
	{
		xValJoy1 = 0;
	}

	if(xValJoy2 < 0.1 && xValJoy2 > -0.1)
	{
		xValJoy2 = 0;
	}

	if(yValJoy2 < 0.1 && yValJoy2 > -0.1)
	{
		yValJoy2 = 0;
	}

	radiansPerSecond = xValJoy1 * maxRotationSpeedMultiplier/5;

	A = xValJoy2 - radiansPerSecond*(wheelbase/2);
	B = xValJoy2 + radiansPerSecond*(wheelbase/2);
	C = yValJoy2 - radiansPerSecond*(trackwidth/2);
	D = yValJoy2 + radiansPerSecond*(trackwidth/2);

	FLPosition = atan2(C,A)*180/pi;
	FRPosition = atan2(D,A)*180/pi;
	BLPosition = atan2(C,B)*180/pi;
	BRPosition = atan2(D,B)*180/pi;

	FL->setRotationPosition(FLPosition);
	FR->setRotationPosition(FRPosition);
	BL->setRotationPosition(BLPosition);
	BR->setRotationPosition(BRPosition);

}

SwerveModule SwerveDriveTrain::getModule(int num)
{
	if(num == 1)
	{
		return *FL;
	}
	else if(num == 2)
	{
		return *FR;
	}
	else if(num == 3)
	{
		return *BL;
	}
	else
	{
		return *BR;
	}
}


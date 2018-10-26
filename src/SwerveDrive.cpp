/*
 * SwerveDrive.cpp
 *
 *  Created on: Sep 8, 2018
 *      Author: FIRSTMentor
 */

#include "SwerveDrive.h"

SwerveDrive::SwerveDrive(const _swervedrive *sd)
{
	FL = sd->FL;
	FR = sd->FR;
	BL = sd->BL;
	BR = sd->BR;
	trackWidth = sd->trackWidth;
	wheelBase = sd->wheelBase;

	/*
	FL->setPosition(startingPosition);
	FR->setPosition(startingPosition);
	BL->setPosition(startingPosition);
	BR->setPosition(startingPosition);
	*/
}

void SwerveDrive::Drive(double xComponent, double yComponent, double angularVelocity)
{

	int highest = 0;

	A = xComponent - (0.5*angularVelocity*wheelBase);
	B = xComponent + (0.5*angularVelocity*wheelBase);
	C = xComponent - (0.5*angularVelocity*trackWidth);
	D = xComponent + (0.5*angularVelocity*trackWidth);

	wheelAngle[0] = atan2(A,C)*180/M_PI;
	wheelAngle[1] = atan2(A,D)*180/M_PI;
	wheelAngle[2] = atan2(B,C)*180/M_PI;
	wheelAngle[3] = atan2(B,D)*180/M_PI;

	wheelSpeed[0] = sqrt(pow(A,2) + pow(C,2));
	wheelSpeed[1] = sqrt(pow(A,2) + pow(D,2));
	wheelSpeed[2] = sqrt(pow(B,2) + pow(C,2));
	wheelSpeed[3] = sqrt(pow(B,2) + pow(D,2));

	for(int i = 0; i < 4; i++) // Code for making sure the wheel speeds don't go over 1
	{
		if(wheelSpeed[i] > 1)
		{
			for(int i = 0; i < 4; i++)
			{
				if(wheelSpeed[i] > wheelSpeed[highest])
				{
						highest = i;
				}
			}

			for(int i = 0; i < 4; i++)
			{
					wheelSpeed[i] = wheelSpeed[i] / wheelSpeed[highest];
			}

			break;
		}
	}

	/*

	FL->setPosition(wheelAngle[0]);
	FR->setPosition(wheelAngle[1]);
	BL->setPosition(wheelAngle[2]);
	BR->setPosition(wheelAngle[3]);

	FL->setSpeed(wheelSpeed[0]);
	FR->setSpeed(wheelSpeed[1]);
	BL->setSpeed(wheelSpeed[2]);
	BR->setSpeed(wheelSpeed[3]);
	*/

}

SwerveModule SwerveDrive::getModule(int module)
{
	if(module == 0)
	{
		return *FL;
	}
	else if(module == 1)
	{
		return *FR;
	}
	else if(module == 2)
	{
		return *BL;
	}
	else
	{
		return *BR;
	}
}




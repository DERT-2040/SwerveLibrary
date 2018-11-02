/*
 * SwerveDrive.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: FIRSTMentor
 */

#include "SwerveDrive.h"
#include "../RobotMap.h"

SwerveDrive::SwerveDrive()
{
	FL = new SwerveModule(RobotMap::FLrotationEncoder, RobotMap::FLDrive, RobotMap::FLRotation);
	FR = new SwerveModule(RobotMap::FRrotationEncoder, RobotMap::FRDrive, RobotMap::FRRotation);
	BL = new SwerveModule(RobotMap::BLrotationEncoder, RobotMap::BLDrive, RobotMap::BLRotation);
	BR = new SwerveModule(RobotMap::BRrotationEncoder, RobotMap::BRDrive, RobotMap::BRRotation);

	wheelBase = 1;
	trackWidth = 1;

	A = 0;
	B = 0;
	C = 0;
	D = 0;

}

void SwerveDrive::drive(double robotX, double robotY, double omega)
{
	int highest = 0;

	A = robotX + omega*wheelBase/2;
	B = robotX - omega*wheelBase/2;
	C = robotY + omega*trackWidth/2;
	D = robotY - omega*trackWidth/2;

	wheelAngle[0] = atan2(B,D)*180/M_PI;
	wheelAngle[1] = atan2(B,C)*180/M_PI;
	wheelAngle[2] = atan2(A,D)*180/M_PI;
	wheelAngle[3] = atan2(A,C)*180/M_PI;

	wheelSpeed[0] = sqrt(pow(B,2) + pow(D,2));
	wheelSpeed[1] = sqrt(pow(B,2) + pow(C,2));
	wheelSpeed[2] = sqrt(pow(A,2) + pow(D,2));
	wheelSpeed[3] = sqrt(pow(A,2) + pow(C,2));

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

	FL->setAngle(wheelAngle[1]);
	FR->setAngle(wheelAngle[0]);
	BL->setAngle(wheelAngle[2]);
	BR->setAngle(wheelAngle[3]);

	FL->setSpeed(wheelSpeed[0]*.25);
	FR->setSpeed(wheelSpeed[1]*.25);
	BL->setSpeed(wheelSpeed[2]*.25);
	BR->setSpeed(wheelSpeed[3]*.25);

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


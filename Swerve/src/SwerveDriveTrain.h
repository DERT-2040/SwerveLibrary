

#ifndef SRC_SWERVEDRIVETRAIN_H_
#define SRC_SWERVEDRIVETRAIN_H_

#include "RobotMap.h"
#include <algorithm>
#include <cmath>
#include "SwerveModule.h"

static double pi = 3.1415926535897932384626433832795028841971693993751;

class SwerveDriveTrain {

public:

	SwerveDriveTrain(struct swerve_drive);

	void drive(double xValJoy1 , double xValJoy2 , double yValJoy2);
	SwerveModule getModule(int num);

private:

	std::shared_ptr<WPI_TalonSRX> FLRotation, FRRotation, BLRotation, BRRotation;
	std::shared_ptr<AnalogPotentiometer> FLAbsEncoder, FRAbsEncoder, BLAbsEncoder, BRAbsEncoder;

	double A , B , C , D;
	double wheelbase , trackwidth, radius;
	double FLPosition, FRPosition, BLPosition, BRPosition;
	double maxRotationSpeedMultiplier = pi;
	double radiansPerSecond  = 0;

	SwerveModule *FL , *FR , *BL , *BR;

};

#endif /* SRC_SWERVEDRIVETRAIN_H_ */

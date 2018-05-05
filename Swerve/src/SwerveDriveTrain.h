

#ifndef SRC_SWERVEDRIVETRAIN_H_
#define SRC_SWERVEDRIVETRAIN_H_

#include "RobotMap.h"
#include <algorithm>
#include <cmath>
#include "SwerveModule.h"

static double pi = 3.1415926535897932384626433832795028841971693993751;

class SwerveDriveTrain {

public:

	SwerveDriveTrain(std::shared_ptr<WPI_TalonSRX> FLR,  std::shared_ptr<WPI_TalonSRX> FRR
					,std::shared_ptr<WPI_TalonSRX> BLR,  std::shared_ptr<WPI_TalonSRX> BRR
					,std::shared_ptr<AnalogPotentiometer> FLAbs, std::shared_ptr<AnalogPotentiometer> FRAbs
					,std::shared_ptr<AnalogPotentiometer> BLAbs, std::shared_ptr<AnalogPotentiometer> BRAbs
					,double WB , double TW);

	void drive(double xValJoy1 , double xValJoy2 , double yValJoy2);

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

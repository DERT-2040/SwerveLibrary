

#ifndef SRC_SWERVEMODULE_H_
#define SRC_SWERVEMODULE_H_

#include "RobotMap.h"
#include "ctre\Phoenix.h"

class SwerveModule{
public:


	SwerveModule(std::shared_ptr<AnalogPotentiometer> absE , std::shared_ptr<WPI_TalonSRX> rMotor);
	virtual ~SwerveModule();

	void setRotationPosition(double degrees);
	void setRotationOffSet(double offset);

	//PID rotationPID = PID(.001, .1, 0.0);

	double angleOffset;
	double getEncoderValue();


private:
	std::shared_ptr<AnalogPotentiometer> absEncoder;
	std::shared_ptr<WPI_TalonSRX> rotationMotor;

	PIDController *rotationPID;

};

#endif /* SRC_SWERVEMODULE_H_ */

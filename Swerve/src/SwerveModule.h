

#ifndef SRC_SWERVEMODULE_H_
#define SRC_SWERVEMODULE_H_

#include "RobotMap.h"
#include "C:\Users\Carter DiOrio\Documents\Talon\include\ctre\Phoenix.h"

class SwerveModule{
public:


	SwerveModule(std::shared_ptr<AnalogPotentiometer> absE , std::shared_ptr<WPI_TalonSRX> rMotor);
	virtual ~SwerveModule();

	void setRotationPosition(double degrees);

	//PID rotationPID = PID(.001, .1, 0.0);


private:

	std::shared_ptr<AnalogPotentiometer> absEncoder;
	std::shared_ptr<WPI_TalonSRX> rotationMotor;

	PIDController *rotationPID;

};

#endif /* SRC_SWERVEMODULE_H_ */

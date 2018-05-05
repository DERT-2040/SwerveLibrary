

#include "SwerveModule.h"

SwerveModule::SwerveModule(std::shared_ptr<AnalogPotentiometer> absE , std::shared_ptr<WPI_TalonSRX> rMotor)
{

	absEncoder = absE;
	rotationMotor = rMotor;

	rotationPID = new PIDController(0.001 , 0.0, 0.0 , 0.0, absEncoder.get() , rotationMotor.get() , .01);
	rotationPID->SetContinuous(true);
	rotationPID->Enable();
}

void SwerveModule::setRotationPosition(double degrees)
{
	rotationPID->SetSetpoint(degrees);
}

SwerveModule::~SwerveModule()
{

}


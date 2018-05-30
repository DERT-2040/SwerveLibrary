

#include "SwerveModule.h"

SwerveModule::SwerveModule(std::shared_ptr<AnalogPotentiometer> absE , std::shared_ptr<WPI_TalonSRX> rMotor)
{

	absEncoder = absE;
	rotationMotor = rMotor;
	rotationPID = new PIDController(0.01 , 0.0, 0.0 , 0.0, absEncoder.get() , rotationMotor.get() , .01);
	rotationPID->SetContinuous(true);
	//rotationPID->SetAbsoluteTolerance(5);
	angleOffset = 0;
	rotationPID->SetOutputRange(-1,1);
	rotationPID->SetInputRange(0.0 , 360.0);
	rotationPID->Enable();
}

void SwerveModule::setRotationOffSet(double offset)
{
	angleOffset = offset;
}

void SwerveModule::setRotationPosition(double degrees)
{
	double angle;
	angle = degrees + angleOffset;
	if(angle > 360) angle -= 360;

	rotationPID->SetSetpoint(angle);
}

double SwerveModule::getEncoderValue()
{
	return absEncoder->Get();
}

SwerveModule::~SwerveModule()
{

}


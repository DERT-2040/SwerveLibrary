

#include "PID.h"

PID::PID(float Px, float Ix, float Dx) {

	P = Px;
	I = Ix;
	D = Dx;

	error = 0;
	setpoint = 0;
	resultant = 0;
	integral = 0;
	derivative = 0;
	previous_error = 0;

}

void PID::setSetpoint(float setpoint)
{
	this->setpoint = setpoint;
}

double PID::runPID(double input)
{
	previous_error = error;

	error = setpoint - input;
	integral += (error*.02);
	derivative = (error-previous_error) / .02;
	resultant = P*error + I*integral + D*derivative;

	return resultant;

}

PID::~PID()
{

}


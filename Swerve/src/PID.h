
/*
 * This is a test PID class
 */

#ifndef PID_H_
#define PID_H_

class PID {
public:


	PID(float P, float I, float D);

	double runPID(double input);

	void setSetpoint(float setpoint);

	virtual ~PID();


private:

	float P , I , D, error, setpoint, resultant, integral,
	derivative, previous_error;

};

#endif /* PID_H_ */

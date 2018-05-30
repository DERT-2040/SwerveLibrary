// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

std::shared_ptr<SwerveDriveTrain> SWERVEDRIVE;

void Robot::RobotInit() {
	RobotMap::init();

	oi.reset(new OI());

	SWERVEDRIVE.reset(new SwerveDriveTrain(RobotMap::FLRotationMotor , RobotMap::FRRotationMotor
										  ,RobotMap::BLRotationMotor , RobotMap::BRRotationMotor
										  ,RobotMap::FLAbsEncoder , RobotMap::FRAbsEncoder
										  ,RobotMap::BLAbsEncoder , RobotMap::BRAbsEncoder,
										  1.0 , 1.0));

	chooser.AddDefault("Autonomous Command", new AutonomousCommand());
	frc::SmartDashboard::PutData("Auto Modes", &chooser);
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {

	SWERVEDRIVE->drive(oi->joystick1->GetX() , oi->joystick2->GetY()*-1 , oi->joystick2->GetX()*-1);
	SmartDashboard::PutString("DB/String 0",std::to_string(SWERVEDRIVE->getModule(1).getEncoderValue()));
	SmartDashboard::PutString("DB/String 1",std::to_string(SWERVEDRIVE->getModule(2).getEncoderValue()));
	SmartDashboard::PutString("DB/String 2",std::to_string(SWERVEDRIVE->getModule(3).getEncoderValue()));
	SmartDashboard::PutString("DB/String 3",std::to_string(SWERVEDRIVE->getModule(4).getEncoderValue()));

	frc::Scheduler::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);



#include "OI.h"


#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"



OI::OI()
{

	joystick1.reset(new frc::Joystick(0));
	joystick2.reset(new frc::Joystick(1));


    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

}



#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"

OI::OI()
{
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    leftStick = new Joystick(0);
    rightStick = new Joystick(1);
}



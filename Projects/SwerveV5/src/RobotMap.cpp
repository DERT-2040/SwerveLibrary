#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<WPI_TalonSRX> RobotMap::FLDrive;
std::shared_ptr<WPI_TalonSRX> RobotMap::FLRotation;
std::shared_ptr<AnalogPotentiometer> RobotMap::FLrotationEncoder;

std::shared_ptr<WPI_TalonSRX> RobotMap::FRDrive;
std::shared_ptr<WPI_TalonSRX> RobotMap::FRRotation;
std::shared_ptr<AnalogPotentiometer> RobotMap::FRrotationEncoder;

std::shared_ptr<WPI_TalonSRX> RobotMap::BLDrive;
std::shared_ptr<WPI_TalonSRX> RobotMap::BLRotation;
std::shared_ptr<AnalogPotentiometer> RobotMap::BLrotationEncoder;

std::shared_ptr<WPI_TalonSRX> RobotMap::BRDrive;
std::shared_ptr<WPI_TalonSRX> RobotMap::BRRotation;
std::shared_ptr<AnalogPotentiometer> RobotMap::BRrotationEncoder;

void RobotMap::init() {

    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    FLDrive.reset(new WPI_TalonSRX(9));
    FLRotation.reset(new WPI_TalonSRX(5));
    FLrotationEncoder.reset(new AnalogPotentiometer(0, 360, 0));

    //FLRotation->SetInverted(true);

    FRDrive.reset(new WPI_TalonSRX(8));
    FRRotation.reset(new WPI_TalonSRX(7));
    FRrotationEncoder.reset(new AnalogPotentiometer(1, 360, 0));

    FRDrive->SetInverted(true);

    FRRotation->SetInverted(true);

    BLDrive.reset(new WPI_TalonSRX(6));
    BLRotation.reset(new WPI_TalonSRX(1));
    BLrotationEncoder.reset(new AnalogPotentiometer(2, 360, 0));

    BLRotation->SetInverted(true);

    BRDrive.reset(new WPI_TalonSRX(2));
    BRRotation.reset(new WPI_TalonSRX(3));
    BRrotationEncoder.reset(new AnalogPotentiometer(3, 360, 0));

    BRRotation->SetInverted(true);
    BRDrive->SetInverted(true);
}

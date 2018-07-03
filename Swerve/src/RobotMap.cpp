

#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

std::shared_ptr<WPI_TalonSRX> RobotMap::FLDriveMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::FRDriveMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::BLDriveMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::BRDriveMotor;

std::shared_ptr<WPI_TalonSRX> RobotMap::FLRotationMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::FRRotationMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::BLRotationMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::BRRotationMotor;

std::shared_ptr<AnalogPotentiometer> RobotMap::FLAbsEncoder;
std::shared_ptr<AnalogPotentiometer> RobotMap::FRAbsEncoder;
std::shared_ptr<AnalogPotentiometer> RobotMap::BLAbsEncoder;
std::shared_ptr<AnalogPotentiometer> RobotMap::BRAbsEncoder;

void RobotMap::init() {

    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    //FLDriveMotor.reset(new WPI_TalonSRX(1));
    FLRotationMotor.reset(new WPI_TalonSRX(1));
    //FLRotationMotor->SetInverted(true);
    FLAbsEncoder.reset(new AnalogPotentiometer(1 , 360 , 0));

    //FRDriveMotor.reset(new WPI_TalonSRX(2));
    FRRotationMotor.reset(new WPI_TalonSRX(2));
    FRAbsEncoder.reset(new AnalogPotentiometer(0 , 360 , 0));
    //FRRotationMotor->SetInverted(true);

    //BLDriveMotor.reset(new WPI_TalonSRX(3));
    BLRotationMotor.reset(new WPI_TalonSRX(3));
    BLAbsEncoder.reset(new AnalogPotentiometer(3 , 360 , 0));
    //BLRotationMotor->SetInverted(true);

    // BRDriveMotor.reset(new WPI_TalonSRX(4));
    BRRotationMotor.reset(new WPI_TalonSRX(0));
    BRAbsEncoder.reset(new AnalogPotentiometer(2 , 360 , 0));
    BRRotationMotor->SetInverted(true);
}

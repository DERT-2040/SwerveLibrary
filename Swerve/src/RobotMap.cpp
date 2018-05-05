

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

    FLDriveMotor.reset(new WPI_TalonSRX(1));
    FLRotationMotor.reset(new WPI_TalonSRX(5));
    FLAbsEncoder.reset(new AnalogPotentiometer(0 , 360 , 0));

    FRDriveMotor.reset(new WPI_TalonSRX(2));
    FRRotationMotor.reset(new WPI_TalonSRX(6));
    FRAbsEncoder.reset(new AnalogPotentiometer(1 , 360 , 0));

    BLDriveMotor.reset(new WPI_TalonSRX(3));
    BLRotationMotor.reset(new WPI_TalonSRX(7));
    BLAbsEncoder.reset(new AnalogPotentiometer(2 , 360 , 0));

    BRDriveMotor.reset(new WPI_TalonSRX(4));
    BRRotationMotor.reset(new WPI_TalonSRX(8));
    BRAbsEncoder.reset(new AnalogPotentiometer(3 , 360 , 0));

}

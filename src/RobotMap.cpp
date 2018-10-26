#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<WPI_TalonSRX> RobotMap::FLrotationMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::FLdriveMotor;
std::shared_ptr<AnalogPotentiometer> RobotMap::FLrotationEncoder;

std::shared_ptr<WPI_TalonSRX> RobotMap::FRrotationMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::FRdriveMotor;
std::shared_ptr<AnalogPotentiometer> RobotMap::FRrotationEncoder;

std::shared_ptr<WPI_TalonSRX> RobotMap::BLrotationMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::BLdriveMotor;
std::shared_ptr<AnalogPotentiometer> RobotMap::BLrotationEncoder;

std::shared_ptr<WPI_TalonSRX> RobotMap::BRrotationMotor;
std::shared_ptr<WPI_TalonSRX> RobotMap::BRdriveMotor;
std::shared_ptr<AnalogPotentiometer> RobotMap::BRrotationEncoder;

void RobotMap::init() {

	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    FLrotationMotor.reset(new WPI_TalonSRX(5));
    FLdriveMotor.reset(new WPI_TalonSRX(9));
    FLrotationEncoder.reset(new AnalogPotentiometer(0, 360, 0));

    FRrotationMotor.reset(new WPI_TalonSRX(7));
    FRdriveMotor.reset(new WPI_TalonSRX(8));
    FRrotationEncoder.reset(new AnalogPotentiometer(1, 360, 0));

    BLrotationMotor.reset(new WPI_TalonSRX(1));
    BLdriveMotor.reset(new WPI_TalonSRX(6));
    BLrotationEncoder.reset(new AnalogPotentiometer(2, 360, 0));

    BRrotationMotor.reset(new WPI_TalonSRX(3));
    BRdriveMotor.reset(new WPI_TalonSRX(2));
    BRrotationEncoder.reset(new AnalogPotentiometer(3, 360, 0));


}

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"
#include "ControllerDefinitions.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/smartdashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/TankDrive.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    operatorStick.reset(new frc::Joystick(1));
    
    driveStick.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("Tank Drive", new TankDrive());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getDriveStick() {
   return driveStick;
}

std::shared_ptr<frc::Joystick> OI::getOperatorStick() {
   return operatorStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

double OI::getLeftTankSpeed() {
    return driveStick->GetRawAxis(LogitechGamePad_LeftYAxis);
}

double OI::getRightTankSpeed() {
    return driveStick->GetRawAxis(LogitechGamePad_RightYAxis);
}

bool OI::isIntakeSignaledPositive() { //in
    const bool buttonA = operatorStick->GetRawButton(XBox_ButtonA);
    return buttonA;
}

bool OI::isIntakeSignaledLowNegative() { //out, slowly
    const bool buttonB = operatorStick->GetRawButton(XBox_ButtonB);
    return buttonB;
}

bool OI::isIntakeSignaledHighNegative() { //out, quickly
    const bool buttonY = operatorStick->GetRawButton(XBox_ButtonY);
    return buttonY;
}
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

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ArcadeDrive.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveForDistance.h"
#include "Commands/FPSDrive.h"
#include "Commands/FPSDriveLogarithmic.h"
#include "Commands/OneManIntake.h"
#include "Commands/PointTurn.h"
#include "Commands/StopDriveBase.h"
#include "Commands/StopIntake.h"
#include "Commands/StubCommand1.h"
#include "Commands/StubCommand2.h"
#include "Commands/SwingTurn.h"
#include "Commands/TankDrive.h"
#include "Commands/TimedMove.h"
#include "Commands/TwoPersonIntake.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    intakeStick.reset(new Joystick(1));
    
    pilotStick.reset(new Joystick(0));
    

    // SmartDashboard Buttons
    SmartDashboard::PutData("StopDriveBase", new StopDriveBase());
    SmartDashboard::PutData("StopIntake", new StopIntake());
    SmartDashboard::PutData("OneManIntake", new OneManIntake());
    SmartDashboard::PutData("Two Person Intake", new TwoPersonIntake());
    SmartDashboard::PutData("FPSDriveLogarithmic", new FPSDriveLogarithmic());
    SmartDashboard::PutData("FPSDrive", new FPSDrive());
    SmartDashboard::PutData("Stub Command 2", new StubCommand2());
    SmartDashboard::PutData("Stub Command 1", new StubCommand1());
    SmartDashboard::PutData("ArcadeDrive", new ArcadeDrive());
    SmartDashboard::PutData("Tank Drive", new TankDrive());
    SmartDashboard::PutData("TimedMove: 1 sec - ahead full", new TimedMove(1, 100));
    SmartDashboard::PutData("TimedMove: 1 sec - full reverse", new TimedMove(1, -100));
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    SmartDashboard::PutNumber("LeftTrim", 0);
    SmartDashboard::PutNumber("RightTrim", 0);
    SmartDashboard::PutNumber("Voltage", DriverStation::GetInstance().GetBatteryVoltage());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getPilotStick() {
   return pilotStick;
}

std::shared_ptr<Joystick> OI::getIntakeStick() {
   return intakeStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

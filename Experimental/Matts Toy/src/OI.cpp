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
#include "Commands/SimpleAutoCommand.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

const int PILOT_JOYSTICK_PORT = 0;

OI::OI() {
    // Process operator interface input here.
    pilotStick.reset(new Joystick(PILOT_JOYSTICK_PORT));

    // SmartDashboard Buttons
    SmartDashboard::PutData("Simple Auto Command", new SimpleAutoCommand());

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

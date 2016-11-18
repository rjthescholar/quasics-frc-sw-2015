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

#include "Commands/MoveAheadFast.h"
#include "Commands/MoveForward.h"
#include "Commands/MoveForwardTime.h"
#include "Commands/Rotate.h"
#include "Commands/Rotatation.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    auxStick.reset(new Joystick(1));
    
    pilotStick.reset(new Joystick(0));
    

    // SmartDashboard Buttons
    SmartDashboard::PutData("Rotate Right", new Rotate (3,.6));
    SmartDashboard::PutData("Rotatation", new Rotatation (3,.6));
    SmartDashboard::PutData("Forward Slow", new MoveForward ());
    SmartDashboard::PutData("Forward Fast", new MoveAheadFast ());
    SmartDashboard::PutData("1 second full power", new MoveForwardTime (1,1));
    SmartDashboard::PutData("3 seconds at half power", new MoveForwardTime (3,.5));
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getPilotStick() {
   return pilotStick;
}

std::shared_ptr<Joystick> OI::getAuxStick() {
   return auxStick;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

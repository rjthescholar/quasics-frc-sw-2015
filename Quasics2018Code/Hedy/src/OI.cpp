// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <Commands/FindBoxCommand.h>
#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoCrossTheLineCommand.h"
#include "Commands/AutoModeScoringCommand.h"
#include "Commands/AutoScoreOnLeftSwitchCommand.h"
#include "Commands/AutoScoreOnRightSwitchCommand.h"
#include "Commands/AutoScoreOnSwitchCommand.h"
#include "Commands/AutonomousCommand.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Commands/FaceYellow.h"
#include "Commands/AutoCrossTheLineCommand.h"
#include "Commands/Primitives/MoveForDistance.h"
#include "Commands/Teleop/Teleop.h"
#include "EncoderVariables.h"
#include "Commands/Primitives/ShoulderMove.h"
#include "Commands/Primitives/TurnLeft.h"

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    auxStick.reset(new frc::Joystick(1));
    
    driveStick.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("Auto Score On Right Switch Command", new AutoScoreOnRightSwitchCommand());
    frc::SmartDashboard::PutData("Auto Score On Left Switch Command", new AutoScoreOnLeftSwitchCommand());
    frc::SmartDashboard::PutData("Auto Score On Switch Command", new AutoScoreOnSwitchCommand());
    frc::SmartDashboard::PutData("Auto Cross The Line Command", new AutoCrossTheLineCommand());
    frc::SmartDashboard::PutData("Auto Mode Scoring Command", new AutoModeScoringCommand());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    frc::SmartDashboard::PutData("(Auto) Cross the line", new AutoCrossTheLineCommand());
    frc::SmartDashboard::PutData("Drive Stuff", new Teleop());
    frc::SmartDashboard::PutData("Move For Distance", new MoveForDistance(WHEEL_CIRCUMFERENCE_INCHES, .1));
    frc::SmartDashboard::PutData("CubeTracker", new FindBoxCommand());
    frc::SmartDashboard::PutData("Move Shoulder Auto", new ShoulderMove(5, .4));
    frc::SmartDashboard::PutData("Turn Left 90 degrees", new TurnLeft(90));
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getdriveStick() {
   return driveStick;
}

std::shared_ptr<frc::Joystick> OI::getauxStick() {
   return auxStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "StopIntake.h"

#include <Commands/Subsystem.h>
#include "../Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

StopIntake::StopIntake(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::intake.get());
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void StopIntake::Initialize() {
	Robot::intake->StopIntake();
}

// Called repeatedly when this Command is scheduled to run
void StopIntake::Execute() {
	Robot::intake->StopIntake();
}

// Make this return true when this Command no longer needs to run execute()
bool StopIntake::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void StopIntake::End() {
	Robot::intake->StopIntake();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopIntake::Interrupted() {
	Robot::intake->StopIntake();
}

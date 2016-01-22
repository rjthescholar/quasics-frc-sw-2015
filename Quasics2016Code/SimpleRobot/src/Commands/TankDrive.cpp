// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "TankDrive.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TankDrive::TankDrive() :
		Command() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSystem.get());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	if ((Robot::oi->getPilotStick()->GetRawButton(5)
			|| Robot::oi->getPilotStick()->GetRawButton(6))
			&& !(Robot::oi->getPilotStick()->GetRawButton(7)
					|| Robot::oi->getPilotStick()->GetRawButton(8))) {
		Robot::driveSystem->MoveLeft(
				double(Robot::oi->getPilotStick()->GetRawAxis(1)) * 25);
		Robot::driveSystem->MoveRight(
				double(Robot::oi->getPilotStick()->GetRawAxis(3)) * 25);
	} else if (!(Robot::oi->getPilotStick()->GetRawButton(5)
			|| Robot::oi->getPilotStick()->GetRawButton(6))
			&& (Robot::oi->getPilotStick()->GetRawButton(7)
					|| Robot::oi->getPilotStick()->GetRawButton(8))) {
		Robot::driveSystem->MoveLeft(
				double(Robot::oi->getPilotStick()->GetRawAxis(1)) * 62.5);
		Robot::driveSystem->MoveRight(
				double(Robot::oi->getPilotStick()->GetRawAxis(3)) * 62.5);
	} else {
		Robot::driveSystem->MoveLeft(
				double(Robot::oi->getPilotStick()->GetRawAxis(1)) * 50);
		Robot::driveSystem->MoveRight(
				double(Robot::oi->getPilotStick()->GetRawAxis(3)) * 50);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {
	Robot::driveSystem->StopEverything();
}

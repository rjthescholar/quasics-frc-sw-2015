// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "StubCommand2.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

StubCommand2::StubCommand2() :
		Command() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSystem.get());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	isFinished = false;
	deadliest = stop;
	m_distanceMeters = 0;
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void StubCommand2::Initialize() {
	Robot::driveSystem->ResetDisplacement();
	Robot::driveSystem->ResetYaw();
	isFinished = false;
	deadliest = stop;

}

// Called repeatedly when this Command is scheduled to run
void StubCommand2::Execute() {
	if (Robot::driveSystem-> GetDisplacementX() <= .5) {
		deadliest = forward;
	} else if (Robot::driveSystem-> GetDisplacementX()>= -.5) {
		deadliest = backward;
	} else if (Robot::driveSystem->GetContinuousYaw() <= .90) {
		deadliest = turnleft;
	} else if (Robot::driveSystem->GetContinuousYaw() <= -90) {
		deadliest = turnright;
	} else if (Robot::driveSystem-> GetDisplacementX()>= -.5) {
		deadliest = backward;
	} else if (Robot::driveSystem->GetContinuousYaw() <= -90) {
		deadliest = turnright;
	} else if (Robot::driveSystem-> GetContinuousYaw() <= 90) {
		deadliest = turnleft;
	} else if (Robot::driveSystem-> GetDisplacementX() <= .5) {
		deadliest = forward;
	} else if (Robot::driveSystem-> GetDisplacementX()>= -.5) {
		deadliest = backward;
	} else if (Robot::driveSystem-> GetContinuousYaw() <= -90) {
		deadliest = turnright;
	} else if (Robot::driveSystem-> GetDisplacementX()<= .5) {
		deadliest = forward;
	} else if (Robot::driveSystem-> GetDisplacementX() >= -.5) {
		deadliest = backward;
	} else if (Robot::driveSystem-> GetContinuousYaw() <= 90) {
		deadliest = turnleft;
	} else if (Robot::driveSystem-> GetDisplacementX() <= .5) {
		deadliest = forward;
	} else if (Robot::driveSystem-> GetDisplacementX() >= -.5) {
		deadliest = backward;
	} else if (Robot::driveSystem-> GetContinuousYaw() <= -90) {
		deadliest = turnright;
	} else {
		deadliest = stop;
		isFinished = true;
	}

	if (deadliest == forward) {
		Robot::driveSystem->MoveLeft(40);
		Robot::driveSystem->MoveRight(40);

	} else if (deadliest == backward) {
		Robot::driveSystem->MoveLeft(-40);
		Robot::driveSystem->MoveRight(-40);
	} else if (deadliest == turnleft) {
		Robot::driveSystem->MoveLeft(-60);
		Robot::driveSystem->MoveRight(60);
	} else if (deadliest == turnright) {
		Robot::driveSystem->MoveLeft(60);
		Robot::driveSystem->MoveRight(-60);
	} else {
		Robot::driveSystem->StopEverything();
	}


}
// Make this return true when this Command no longer needs to run execute()
bool StubCommand2::IsFinished() {
	return isFinished;
}

// Called once after isFinished returns true
void StubCommand2::End() {
Robot::driveSystem->StopEverything();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StubCommand2::Interrupted() {
	Robot::driveSystem->StopEverything();


}

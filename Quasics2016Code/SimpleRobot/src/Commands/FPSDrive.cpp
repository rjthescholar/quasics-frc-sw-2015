// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "FPSDrive.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

FPSDrive::FPSDrive() :
		Command() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSystem.get());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void FPSDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FPSDrive::Execute() {
	float multiplier;

	if ((Robot::oi->getPilotStick()->GetRawButton(5)
			|| Robot::oi->getPilotStick()->GetRawButton(6))
			&& !(Robot::oi->getPilotStick()->GetRawButton(7)
					|| Robot::oi->getPilotStick()->GetRawButton(8))) {
		multiplier = 0.25;
	} else if (!(Robot::oi->getPilotStick()->GetRawButton(5)
			|| Robot::oi->getPilotStick()->GetRawButton(6))
			&& (Robot::oi->getPilotStick()->GetRawButton(7)
					|| Robot::oi->getPilotStick()->GetRawButton(8))) {
		multiplier = 0.625;
	} else {
		multiplier = .5;
	}

	//Setting Motors
	if ((Robot::oi->getPilotStick()->GetRawAxis(0)) >= 0) {

		float yAxis;
		float xAxis;

		if (fabs(Robot::oi->getPilotStick()->GetRawAxis(3)) >= .05)
			yAxis = Robot::oi->getPilotStick()->GetRawAxis(3);
		else
			yAxis = 0;

		if (fabs(Robot::oi->getPilotStick()->GetRawAxis(0)) >= .05)
			xAxis = Robot::oi->getPilotStick()->GetRawAxis(0);
		else
			xAxis = 0;

		Robot::driveSystem->MoveLeft(
				(yAxis) * 100 * multiplier);
		Robot::driveSystem->MoveRight(
				yAxis * 100
						* (-fabs(
								2 * (xAxis))
								+ 1) * multiplier);
	} else {

		float yAxis;
		float xAxis;

		if (fabs(Robot::oi->getPilotStick()->GetRawAxis(3)) >= .05)
			yAxis = Robot::oi->getPilotStick()->GetRawAxis(3);
		else
			yAxis = 0;

		if (fabs(Robot::oi->getPilotStick()->GetRawAxis(0)) >= .05)
			xAxis = Robot::oi->getPilotStick()->GetRawAxis(0);
		else
			xAxis = 0;

		Robot::driveSystem->MoveRight((yAxis) * 100 * multiplier);
		Robot::driveSystem->MoveLeft(
				yAxis * 100 * (-fabs(2 * (xAxis)) + 1) * multiplier);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FPSDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FPSDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FPSDrive::Interrupted() {

}

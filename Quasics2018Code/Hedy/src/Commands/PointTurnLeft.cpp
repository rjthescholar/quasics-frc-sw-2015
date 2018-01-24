// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "PointTurnLeft.h"
PointTurnLeft::PointTurnLeft(double seconds, double power): frc::Command() {
	count = 0;
	m_seconds = seconds;
	m_power = power;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR


        // Use requires() here to declare subsystem dependencies
	Requires (Robot::driveBase.get());
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void PointTurnLeft::Initialize() {

	//robot turns left
	Robot::driveBase->SetLeftPower(m_power);
	Robot::driveBase->SetRightPower(-m_power);
}

// Called repeatedly when this Command is scheduled to run
void PointTurnLeft::Execute() {

	while(count <= m_seconds){
		count = count + 1;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool PointTurnLeft::IsFinished() {
	return count >= m_seconds;
}

// Called once after isFinished returns true
void PointTurnLeft::End() {
	Robot::driveBase->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PointTurnLeft::Interrupted() {
	Robot::driveBase->Stop();
}

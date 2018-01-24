

#include "../Robot.h"
#include "../ControllerDefinitions.h"
#include "TankDrive.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TankDrive::TankDrive(): frc::Command() {

	Requires(Robot::driveBase.get());

}

// Called just before this Command runs the first time
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	std::shared_ptr<Joystick> joystick = Robot::oi->getdriveStick();
	const bool leftTrigger = joystick->GetRawButton(LogitechGamePad_LeftTrigger);
	const bool rightTrigger = joystick->GetRawButton(LogitechGamePad_RightTrigger);
	const bool XButton = joystick->GetRawButton(LogitechGamePad_XButton);

	double mult = .4;
	if(leftTrigger && rightTrigger){
		mult = .8;
	}
	else if(leftTrigger && !rightTrigger){
		mult = .6;
	}
	else if(rightTrigger && !leftTrigger){
		mult = .2;
	}

	if(!XButton && pressedLastTime){
		counter = counter + 1;
	}


	if(counter % 2 == 0){
		Robot::driveBase->SetLeftPower(joystick->GetRawAxis(LogitechGamePad_LeftYAxis)* -mult);
		Robot::driveBase->SetRightPower(joystick->GetRawAxis(LogitechGamePad_RightYAxis)* -mult);
	}
	else{
		Robot::driveBase->SetLeftPower(joystick->GetRawAxis(LogitechGamePad_LeftYAxis)* mult);
		Robot::driveBase->SetRightPower(joystick->GetRawAxis(LogitechGamePad_RightYAxis)* mult);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void TankDrive::End() {
	Robot::driveBase->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {
	Robot::driveBase->Stop();
}

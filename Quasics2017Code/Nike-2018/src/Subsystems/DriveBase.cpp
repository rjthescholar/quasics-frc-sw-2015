// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "DriveBase.h"
#include "../RobotMap.h"
#include <WPILib.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveBase::DriveBase() : Subsystem("DriveBase") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftFront = RobotMap::driveBaseleftFront;
    leftRear = RobotMap::driveBaseleftRear;
    rightFront = RobotMap::driveBaserightFront;
    rightRear = RobotMap::driveBaserightRear;
    leftEncoder = RobotMap::driveBaseleftEncoder;
    rightEncoder = RobotMap::driveBaserightEncoder;
    navX.reset(new AHRS(SerialPort::kMXP));
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void DriveBase::InitDefaultCommand() {

}

double DriveBase::ReadCurrentHeading() {
	return navX->GetAngle() * 4 / 3;
}

void DriveBase::ResetYaw() {
	navX->ZeroYaw();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveBase::SetLeftPower(double percent) {
	leftFront->Set(percent);
	leftRear->Set(percent);

}

void DriveBase::SetRightPower(double percent) {
	rightFront->Set(percent);
	rightRear->Set(percent);
}

double DriveBase::RightEncoderVelocity() {
	return rightEncoder->GetRate();
}

double DriveBase::LeftEncoderVelocity() {
	return leftEncoder->GetRate();
}


double DriveBase::RightEncoderDistance(){
	return rightEncoder->GetDistance();
}
double DriveBase::LeftEncoderDistance(){
	return leftEncoder->GetDistance();
}
uint32_t DriveBase::LeftEncoderRaw(){
	return rightEncoder->GetRaw();
}
uint32_t DriveBase::RightEncoderRaw(){
	return leftEncoder->GetRaw();
}


void DriveBase::RightEncoderReset(){
	leftEncoder->Reset();
}
void DriveBase::LeftEncoderReset(){
	rightEncoder->Reset();
}

void DriveBase::Stop(){
	SetLeftPower(0);
	SetRightPower(0);
}

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
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveBase::DriveBase() : frc::Subsystem("DriveBase") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftEncoder = RobotMap::driveBaseLeftEncoder;
    rightEncoder = RobotMap::driveBaseRightEncoder;
    leftRearMotor = RobotMap::driveBaseleftRearMotor;
    leftFrontMotor = RobotMap::driveBaseleftFrontMotor;
    leftMotors = RobotMap::driveBaseLeftMotors;
    rightFrontMotor = RobotMap::driveBaserightFrontMotor;
    rightRearMotor = RobotMap::driveBaserightRearMotor;
    rightMotors = RobotMap::driveBaseRightMotors;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void DriveBase::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveBase::SetLeftPower(double percent){
	leftMotors->Set(percent);
}

void DriveBase::SetRightPower(double percent){
	rightMotors->Set(percent);
}

//Encoders start here

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

//Encoders end here

void DriveBase::Stop(){
	SetLeftPower(0);
	SetRightPower(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

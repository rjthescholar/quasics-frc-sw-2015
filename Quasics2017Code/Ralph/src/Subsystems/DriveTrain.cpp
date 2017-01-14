// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "DriveTrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftEncoder = RobotMap::driveTrainLeftEncoder;
	frontLeft = RobotMap::driveTrainFrontLeft;
	backLeft = RobotMap::driveTrainBackLeft;
	rightEncoder = RobotMap::driveTrainRightEncoder;
	frontRight = RobotMap::driveTrainFrontRight;
	backRight = RobotMap::driveTrainBackRight;

	frontRight->SetInverted(true);
	backRight->SetInverted(true);

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::SetLeftPower(double percent) {
	frontLeft->Set(percent);
	backLeft->Set(percent);

}

void DriveTrain::SetRightPower(double percent) {
	frontRight->Set(percent);
	backRight->Set(percent);
}

double DriveTrain::RightEncoderVelocity() {
	return rightEncoder->GetRate();
}

double DriveTrain::LeftEncoderVelocity() {
	return leftEncoder->GetRate();
}

void DriveTrain::RightEncoderReset() {
	rightEncoder->Reset();
}

void DriveTrain::LeftEncoderReset() {
	leftEncoder->Reset();
}

double DriveTrain::RightEncoderDistance() {
	return rightEncoder->GetDistance();
}

double DriveTrain::LeftEncoderDistance() {
	return leftEncoder->GetDistance();
}

void DriveTrain::Stop() {
	frontRight->StopMotor();
	frontLeft->StopMotor();
	backRight->StopMotor();
	backLeft->StopMotor();
}

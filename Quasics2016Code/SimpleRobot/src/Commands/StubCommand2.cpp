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
	hexagon = kstop;
	timer = 0;
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void StubCommand2::Initialize() {
	isFinished = false;
	hexagon = kstop;
	timer = 0;
	Robot::driveSystem->ResetYaw();
	Robot::driveSystem->ResetEncoders();

}

// Called repeatedly when this Command is scheduled to run
void StubCommand2::Execute() {
	if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) >= -1 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) >= -1 ){  //L
		hexagon = kbackward;
	} else if (Robot::driveSystem->GetContinuousYaw() >= -90) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <=.75 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <=.75 ) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
	} else if (timer <= 100){
		hexagon = kstop;
		Robot::driveSystem->ResetEncoders();																										//I
	} else if (Robot::driveSystem->GetContinuousYaw() <= 90) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <= 1 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <= 1) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
		timer = 0;
	} else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetContinuousYaw() >= -540) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
		timer = 0;																																	//Z
	} else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetYaw();
	} else if (Robot::driveSystem->GetContinuousYaw() <= 90) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <=.75 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <=.75 ) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
	} else if (Robot::driveSystem->GetContinuousYaw() >= -135) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <=.9 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <=.9 ) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetContinuousYaw() <= 135 ) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <=.75 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <=.75 ) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
		timer = 0;
	}else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetYaw();																													//T
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <=.75 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <=.75 ) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
	}if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) >= -.375 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) >= -.375 ){
		hexagon = kbackward;
	}else if (Robot::driveSystem->GetContinuousYaw() >= -90) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <=1 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <=1 ) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
		timer = 0;
	}else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetYaw();																													//i
	}else if (Robot::driveSystem->GetContinuousYaw() <= 90) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <= 1 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <= 1) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
		timer = 0;
	} else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetContinuousYaw() >= -540) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
		timer = 0;
	} else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetYaw();																													//m
	} else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <= .5 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <= .5) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) >= -.5 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) >= -.5) {
		hexagon = kbackward;
		Robot::driveSystem->ResetYaw();
	} else if (Robot::driveSystem->GetContinuousYaw() <= 180 ) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetContinuousYaw() >= -180) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
	} else if (Robot::driveSystem->GetContinuousYaw() <= 180 ) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetContinuousYaw() >= -180) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
		timer = 0;
	} else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetYaw();																														//p																							//i
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <= .75 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <= .75) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) >= -.75 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) >= -.75) {
		hexagon = kbackward;
		Robot::driveSystem->ResetYaw();
	} else if (Robot::driveSystem->GetContinuousYaw() <= 90 ) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetContinuousYaw() >= -180) {
		hexagon = kturnright;
		Robot::driveSystem->ResetEncoders();
		timer = 0;
	}  else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetYaw();																														//l																							//i
	}else if (Robot::driveSystem->GetContinuousYaw() <= 90 ) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <= 1 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <= 1) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
		timer = 0;
	}else if (timer <= 100) {
		hexagon = kstop;
		Robot::driveSystem->ResetYaw();																														//e																							//i
	}else if (Robot::driveSystem->GetContinuousYaw() <= 90 ) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetEncoderDistance(DriveSystem::kLeft) <= .5 && Robot::driveSystem->GetEncoderDistance(DriveSystem::kRight) <= .5) {
		hexagon = kforward;
		Robot::driveSystem->ResetYaw();
	}else if (Robot::driveSystem->GetContinuousYaw() <= 180 ) {
		hexagon = kturnleft;
		Robot::driveSystem->ResetYaw();
	}else {
		hexagon = kstop;
		isFinished = true;
	}

	if (hexagon == kforward) {
		Robot::driveSystem->MoveLeft(30);
		Robot::driveSystem->MoveRight(30);
	}else if (hexagon == kturnright) {
		Robot::driveSystem->MoveLeft(40);
		Robot::driveSystem->MoveRight(-40);
	}else if (hexagon == kturnleft) {
		Robot::driveSystem->MoveLeft(-40);
		Robot::driveSystem->MoveRight(40);
	}else if(hexagon == kbackward){
		Robot::driveSystem->MoveLeft(-30);
		Robot::driveSystem->MoveRight(-30);
	}else {
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

#include <Commands/TeleOp/CubeIntakeControl.h>
#include "../../Robot.h"
#include "../../Subsystems/CubeIntake.h"

CubeIntakeControl::CubeIntakeControl() {
	Requires(Robot::cubeIntake.get());
}

// Called repeatedly when this Command is scheduled to run
void CubeIntakeControl::Execute() {
//	if(Robot::oi->isCubeIntakeSignaled() && !Robot::cubeIntake->IsLimitSwitchTriggered()){
//		Robot::cubeIntake->SetIntakePower(-.8);
//	}
	if (Robot::oi->isCubeLowSpeedExhaustSignaled()) {
		Robot::cubeIntake->SetIntakePower(-.80);
	}
	else if (Robot::oi->isCubeHighSpeedExhaustSignaled()){
		Robot::cubeIntake->SetIntakePower(1);
	}
	else if (Robot::oi->isCubeOutLowSpeedExhaustSignaled()){
		Robot::cubeIntake->SetIntakePower(.5);
	}
	else{
		Robot::cubeIntake->SetIntakePower(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CubeIntakeControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CubeIntakeControl::End() {
	Robot::cubeIntake->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeIntakeControl::Interrupted() {
	End();
}

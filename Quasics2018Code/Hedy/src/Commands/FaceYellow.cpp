#include "FaceYellow.h"

FaceYellow::FaceYellow() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveBase.get());
	Requires(Robot::cubeTracker.get());


}

// Called just before this Command runs the first time
void FaceYellow::Initialize() {
	/*
	 * code is needed to have the camera center itself with the cube
	 * drivetrain code in .h file is needed
	 *

		if the cube is in the center of the camera, then face it,

		else if the cube is moving, center it with the camera


	*/
}

// Called repeatedly when this Command is scheduled to run
void FaceYellow::Execute() {
	if (Robot::cubeTracker->getCurrentRect().width < Robot::cubeTracker->getImageRect().width && Robot::cubeTracker->getCurrentRect().height < Robot::cubeTracker->getImageRect().height)
	{
		std::cout<<"Turn left or right: "  << std::endl;
	}
	else
	{
		std::cout<<"Stay "  << std::endl;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool FaceYellow::IsFinished() {
	return false;

}

// Called once after isFinished returns true
void FaceYellow::End() {
	Robot::driveBase->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FaceYellow::Interrupted() {
	Robot::driveBase->Stop();
}

//Robot::cubeTracker->getCurrentRect().width < Robot::cubeTracker->getImageRect().width && Robot::cubeTracker->getCurrentRect().height < Robot::cubeTracker->getImageRect().height
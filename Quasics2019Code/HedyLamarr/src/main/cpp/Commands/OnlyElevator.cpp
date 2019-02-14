/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/OnlyElevator.h"
#include "OI.h"
#include "Robot.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/Elevator.h"

OnlyElevator::OnlyElevator() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::lifter.get());
  Requires(Robot::elevator.get());
}

// Called just before this Command runs the first time
void OnlyElevator::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void OnlyElevator::Execute() {
    //tests whether the elevator is signaled to go up, and if it isn't at the top
  if (Robot::oi->isElevatorMoveUpSignaled() && !Robot::elevator->atTop()) {
    //continues if both states are true
    Robot::elevator->moveSlowlyUp();
  } 
  //tests whether the elevator is signaled to go up, and if it isn't at the top
  else if (Robot::oi->isElevatorMoveDownSignaled() && !Robot::elevator->atBottom()) {
    //continues if both states are true
    Robot::elevator->moveSlowlyDown();
  } 
  else {
    //if neither is true, it stops
    Robot::elevator->stop();
  }
}

// Make this return true when this Command no longer needs to run execute()
bool OnlyElevator::IsFinished() { return false; }

// Called once after isFinished returns true
void OnlyElevator::End() {
  Robot::elevator->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OnlyElevator::Interrupted() {
  End();
}

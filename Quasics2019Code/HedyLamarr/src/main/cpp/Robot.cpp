// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Robot.h"

#include <frc/Commands/Scheduler.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include "Commands/TeleOp.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveBase> Robot::driveBase;
std::shared_ptr<Manipulator> Robot::manipulator;
std::shared_ptr<Elevator> Robot::elevator;
std::shared_ptr<Lifter> Robot::lifter;
std::shared_ptr<Lighting> Robot::lighting;
std::shared_ptr<TwoBarLinkage> Robot::twoBarLinkage;
std::unique_ptr<OI> Robot::oi;

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

std::shared_ptr<frc::CommandGroup> Robot::teleopCommand;
Robot::LifterMode Robot::currentLifterMode;

void Robot::RobotInit() {
  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
  driveBase.reset(new DriveBase());
  manipulator.reset(new Manipulator());
  elevator.reset(new Elevator());
  lifter.reset(new Lifter());
  lighting.reset(new Lighting());
  twoBarLinkage.reset(new TwoBarLinkage());

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
  // This MUST be here. If the OI creates Commands (which it very likely
  // will), constructing it during the construction of CommandBase (from
  // which commands extend), subsystems are not guaranteed to be
  // yet. Thus, their requires() statements may grab null pointers. Bad
  // news. Don't move it.
  oi.reset(new OI());

  // Add commands to Autonomous Sendable Chooser
  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

  // chooser.SetDefaultOption("Autonomous Command", new AutonomousCommand());

  frc::SmartDashboard::PutData("Auto Modes", &chooser);
  teleopCommand.reset(new TeleOp());
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
if (teleopCommand != NULL) {		//If there is a defined teleop comman group
		teleopCommand->Start();		//Start the teleop command group
	}
}

void Robot::AutonomousPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // these lines or comment it out.
  if (teleopCommand != NULL) {		//If there is a defined teleop comman group
		teleopCommand->Start();		//Start the teleop command group
	}
}

void Robot::TeleopPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::SetLifterMode(LifterMode newm) {
  currentLifterMode = newm;
}

Robot::LifterMode Robot::GetLifterMode() {
  return currentLifterMode;
}

#ifndef RUNNING_FRC_TESTS
int main(int argc, char** argv) {
  return frc::StartRobot<Robot>();
}
#endif

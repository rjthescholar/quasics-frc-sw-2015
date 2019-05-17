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
#include "Commands/Testing/TestMotor.h"

#include <frc/Commands/Scheduler.h>
#include <frc/SmartDashboard/SmartDashboard.h>

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<DriveBase> Robot::driveBase;
std::shared_ptr<Loader> Robot::loader;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    shooter.reset(new Shooter());
    driveBase.reset(new DriveBase());
    loader.reset(new Loader());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// Add commands to Autonomous Sendable Chooser
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS


	chooser.SetDefaultOption("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	// frc::SmartDashboard::PutData("Auto Modes", &chooser);
	{
		DriveBase::TestAccess driveBaseTestAccess = driveBase->getTestAccess();
		frc::SmartDashboard::PutData("Test front left", new TestMotor(*driveBase, driveBaseTestAccess.getLeftFrontMotor(), 1));
		frc::SmartDashboard::PutData("Test front right", new TestMotor(*driveBase, driveBaseTestAccess.getRightFrontMotor(), 1));
		frc::SmartDashboard::PutData("Test back left", new TestMotor(*driveBase, driveBaseTestAccess.getLeftBackMotor(), 1));
		frc::SmartDashboard::PutData("Test back right", new TestMotor(*driveBase, driveBaseTestAccess.getRightBackMotor(), 1));
	}

	{
		Shooter::TestAccess shooterTestAccess = shooter->getTestAccess();
		frc::SmartDashboard::PutData("Test front shooter", new TestMotor(*shooter, shooterTestAccess.getFrontMotor(), 1));
		frc::SmartDashboard::PutData("Test back shooter", new TestMotor(*shooter, shooterTestAccess.getFrontMotor(), 1));
	}
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

#ifndef RUNNING_FRC_TESTS
int main(int argc, char** argv) {
    return frc::StartRobot<Robot>();
}
#endif

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

#include <iostream>
#include <SmartDashboard/SmartDashboard.h>

#include "RobotMap.h"
#include "Commands/Autonomous.h"
#include "Commands/BekahsBox.h"
#include "Commands/DancingRobot.h"
#include "Commands/MoveForward.h"
#include "Commands/TurnLeftContinuous.h"
#include "Commands/TurnRightFortyFive.h"
#include "Commands/TurnToNorthHeading.h"
#include "Commands/GESLeft90.h"
#include "Commands/TankDrive.h"
#include "Commands/Testing/ShanesMotorTest.h"
#include "Commands/MoveForwardOneMeter.h"

std::unique_ptr<OI> Robot::oi;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveBase> Robot::driveBase;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Navigation> Robot::navigation;
std::shared_ptr<HardwareTesting> Robot::hardwareTesting;

void Robot::RobotInit() {
	RobotMap::init();

	//
	// Create the various subsystems
	//

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveBase.reset(new DriveBase());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    navigation.reset(new Navigation());
    hardwareTesting.reset(new HardwareTesting());

    //
    // Create the Operator Interface (OI).
    //
	// Note that this MUST be here. If the OI creates Commands (which it very
	// likely will), constructing it during the construction of CommandBase
	// (from which commands extend), subsystems are not guaranteed to be
	// available yet. Thus, their requires() statements may try to grab null
    // pointers to stuff that they require. Bad news. Don't move it.
	oi.reset(new OI());

	//
	// Instantiate the command used for the autonomous period
	//

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new Autonomous);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//
	// SmartDashboard Buttons
	//

	// SmartDashboard Buttons for commands in practice mode.
	SmartDashboard::PutData("Shane's motor test", new ShanesMotorTest(.5));
	SmartDashboard::PutData("Move forward 1sec @ 50%", new MoveForward(.5, 1));
	SmartDashboard::PutData("Turn left continuous", new TurnLeftContinuous());
	SmartDashboard::PutData("Turn right forty-five degrees", new TurnRightFortyFive());
	SmartDashboard::PutData("Turn towards north", new TurnToNorthHeading);
	SmartDashboard::PutData("Make the robot dance", new DancingRobot);
	SmartDashboard::PutData("BekahsBox", new BekahsBox);
	SmartDashboard::PutData("GESLeft90", new GESLeft90);
	SmartDashboard::PutData("Make the robot move forward about a meter!", new MoveForwardOneMeter());
	SmartDashboard::PutData("Drive the Robot!", new TankDrive());
}


/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	std::cout << "Starting autonomous mode" << std::endl;
	if(autonomousCommand != NULL) autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::StopAutoModeCommand() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	std::cout << "Stopping autonomous mode" << std::endl;
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	StopAutoModeCommand();

	// TODO: Decide if there should be a command running here.  (Hint: if you
	// want the robot to do anything during tele-op mode, then yeah, you
	// probably do.)  If so, then set it up to run.
	//
	// For example, if we had a data member named "tankDriveCmd" that pointed
	// to a Command object that should run during this mode, we could say
	// things like:
	//
	//     if (tankDriveCmd != null) { tankDriveCmd->Start(); }
	//
	// If there are other commands that should run in this mode as well (e.g.,
	// to control an elevator, shooter, etc.), they can also be started up
	// here.
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestInit() {
	StopAutoModeCommand();

	// TODO: Decide if there should be a command running here.  If so, then
	// set it up to run.  (See comments in TeleopInit().)
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

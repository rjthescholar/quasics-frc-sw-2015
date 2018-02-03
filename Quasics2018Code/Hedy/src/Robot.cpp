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
#include "RobotMap.h"
#include "Commands/AutoScoreOnLeftSwitchCommand.h"

#include <SmartDashboard/SmartDashboard.h>
#include <LiveWindow/LiveWindow.h>		// 	If needed, access via "frc::LiveWindow::GetInstance()"
#include <iostream>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<ClimberScissorLift> Robot::climberScissorLift;
std::shared_ptr<ClimberWinch> Robot::climberWinch;
std::shared_ptr<Ramp> Robot::ramp;
std::shared_ptr<DriveBase> Robot::driveBase;
std::shared_ptr<Navigation> Robot::navigation;
std::shared_ptr<CubeManipulation> Robot::cubeManipulation;
std::shared_ptr<CubeIntake> Robot::cubeIntake;
std::shared_ptr<Lighting> Robot::lighting;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

std::shared_ptr<CubeTracker> Robot::cubeTracker;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    climberScissorLift.reset(new ClimberScissorLift());
    climberWinch.reset(new ClimberWinch());
    ramp.reset(new Ramp());
    driveBase.reset(new DriveBase());
    navigation.reset(new Navigation());
    cubeManipulation.reset(new CubeManipulation());
    cubeIntake.reset(new CubeIntake());
    lighting.reset(new Lighting());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    std::cout<< "Degrees" << Robot::navigation->getAngle() << std::endl;
    cubeTracker.reset(new CubeTracker());


	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// Add commands to Autonomous Sendable Chooser
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS


	chooser.AddDefault("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	leftAutoCommand = new AutoScoreOnLeftSwitchCommand();
	chooser.AddObject("Left Auto", leftAutoCommand);
	frc::SmartDashboard::PutData("Auto Modes", &chooser);
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
	const std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	std::cout << "Game data: " << gameData << std::endl;
	if(chooser.GetSelected() == leftAutoCommand){
		if(gameData[0] == 'L')
		{
			//Sample Left Auto
			std::cout<< "Score in Left Switch \n";
		} else {
			// Sample Right Auto
			std::cout<< "Cross Auto Line \n";
		}
	}
	else{
		if(gameData[0] == 'L')
		{
			//Sample Left Auto
			std::cout<< "Cross Auto Line \n";
		} else {
			// Sample Right Auto
			std::cout<< "Score in Right Switch \n";
		}
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
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);


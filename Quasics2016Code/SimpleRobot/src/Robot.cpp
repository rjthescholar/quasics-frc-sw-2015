// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

////////////////////////////////////////////
// Conditional compilation flags

//
// Control behavior in autonomous mode
//

// #define USE_SELECTED_AUTO_CMD
#define DISABLE_AUTO_MODE

//
// Control lighting system.
//

#define DISABLE_LIGHTING
// #define USE_LIVE_LIGHTING


////////////////////////////////////////////
// Include files

#include "Robot.h"

#include "RobotMap.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/TankDrive.h"
#include "Commands/DashboardUpdater.h"

#ifndef DISABLE_LIGHTING
	#ifdef USE_LIVE_LIGHTING
		#include "Lighting/SerialLightingControl.h"
	#else
		#include "Lighting/SimulatedLightingControl.h"
	#endif	// USE_LIVE_LIGHTING
#endif	// DISABLE_LIGHTING

////////////////////////////////////////////
// "Real Code...."

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveSystem> Robot::driveSystem;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<IntakeArm> Robot::intakeArm;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

std::unique_ptr<LightingControl> Robot::lightingControl;

void Robot::RobotInit() {
	RobotMap::init();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveSystem.reset(new DriveSystem());
    intake.reset(new Intake());
    intakeArm.reset(new IntakeArm());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand(0));
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	tankModeCommand.reset(new TankDrive);

#ifndef DISABLE_LIGHTING
#ifdef USE_LIVE_LIGHTING
	lightingControl.reset(new SerialLightingControl);
#else
	lightingControl.reset(new SimulatedLightingControl);
#endif	// USE_LIVE_LIGHTING
#endif	// DISABLE_LIGHTING
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	updateLighting();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
#ifndef DISABLE_AUTO_MODE
#ifdef USE_SELECTED_AUTO_CMD
	autonomousCommand = oi->GetAutoCommand();
#endif

	if (autonomousCommand.get() != nullptr){
		autonomousCommand->Start();
	}
#endif	// DISABLE_AUTO_MODE

	updateLighting();
}

void Robot::AutonomousPeriodic() {
	updateLighting();

	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	updateLighting();

	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	tankModeCommand->Start();
}

void Robot::TeleopPeriodic() {
	updateLighting();

	Scheduler::GetInstance()->Run();
}

void Robot::TestInit(){
	updateLighting();
}

void Robot::TestPeriodic() {
	updateLighting();

	lw->Run();
}

void Robot::updateLighting() {
#ifndef DISABLE_LIGHTING
	lightingControl->LightingUpkeep();
#endif  // DISABLE_LIGHTING
}

START_ROBOT_CLASS(Robot);


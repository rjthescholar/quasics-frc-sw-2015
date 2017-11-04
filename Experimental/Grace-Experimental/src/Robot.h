// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include <WPILib.h>
#include <Commands/Command.h>
#include <LiveWindow/LiveWindow.h>

#include "OI.h"
#include "RobotMap.h"
#include "Commands/Autonomous.h"
#include "Subsystems/Navigation.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Subsystems/DriveBase.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<Command> moveForward;
	static std::unique_ptr<Command> Auto;
	LiveWindow *lw = LiveWindow::GetInstance();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<DriveBase> driveBase;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<Navigation> navigation;

	virtual void RobotInit();

	// Handling for "Disabled" mode
	virtual void DisabledInit();
	virtual void DisabledPeriodic();

	// Handling for "Autonomous" mode
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();

	// Handling for "Teleoperated" mode
	virtual void TeleopInit();
	virtual void TeleopPeriodic();

	// Handling for "Testing" mode
	virtual void TestInit();
	virtual void TestPeriodic();
private:
	void StopAutoModeCommand();
};
#endif

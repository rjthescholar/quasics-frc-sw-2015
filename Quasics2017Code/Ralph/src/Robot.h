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

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/MoveForTime.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Navigation.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Gear.h"
#include "OI.h"
#include "Subsystems/Outtake.h"
#include "Subsystems/FuelExhaustGate.h"


//Use Auto-Trim Code for Tank Drive?
#define USE_TANK_DRIVE_TRIM_

class Robot: public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	std::unique_ptr<Command> autoCommand;
	LiveWindow *lw = LiveWindow::GetInstance();
	static std::shared_ptr<DriveTrain> driveTrain;
	static std::shared_ptr<Navigation> gyro;
	static std::shared_ptr<Intake> intake;
	static std::shared_ptr<Gear> gear;
    static std::shared_ptr<Outtake> outtake;
    static std::shared_ptr<Lighting> lighting;
    static std::shared_ptr<FuelExhaustGate> fuelexhaustgate;


	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif

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

// #define VISION_TRACK_CUBES

#include <WPILib.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Subsystems/ClimberScissorLift.h"
#include "Subsystems/ClimberWinch.h"
#include "Subsystems/CubeIntake.h"
#include "Subsystems/CubeManipulation.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Lighting.h"
#include "Subsystems/Navigation.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#ifdef VISION_TRACK_CUBES
	#include "Subsystems/CubeTracker.h"
#else
	#include "Subsystems/TapeTracker.h"
#endif
#include "OI.h"

class Robot : public frc::TimedRobot {
private:
	frc::Command* leftAutoCommand = nullptr;
	int autoSelector;
public:
	frc::Command* autonomousCommand = nullptr;
	static std::unique_ptr<OI> oi;
	frc::SendableChooser<frc::Command*> chooser;

	////////////////////////////////////////////////////////////
	// Subsystems
	////////////////////////////////////////////////////////////
#ifdef VISION_TRACK_CUBES
	static std::shared_ptr<CubeTracker> cubeTracker;
#else
	static std::shared_ptr<TapeTracker> tapeTracker;
#endif
	static std::shared_ptr<CommandGroup> teleopCommand;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<ClimberScissorLift> climberScissorLift;
	static std::shared_ptr<ClimberWinch> climberWinch;
	static std::shared_ptr<DriveBase> driveBase;
	static std::shared_ptr<Navigation> navigation;
	static std::shared_ptr<CubeManipulation> cubeManipulation;
	static std::shared_ptr<CubeIntake> cubeIntake;
	static std::shared_ptr<Lighting> lighting;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS


	////////////////////////////////////////////////////////////
	// Basic robot functionality
	////////////////////////////////////////////////////////////
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Commands/AutoModeScoringCommand.h"
#include <Commands/AutoCrossTheLineFromSideCommand.h>
#include "OI.h"
#include "ControllerDefinitions.h"
#include "Commands/FaceTape.h"
#include "Commands/LightingTestCommand.h"
#include "Commands/LinearSlideControl.h"
#include "Commands/Primitives/PointTurnRight.h"
#include "Commands/Primitives/MoveForDistance.h"
#include "Commands/Teleop/Teleop.h"
#include "Commands/AutoExchange.h"
#include "Commands/Winch.h"
#include "Commands/GyroTurn.h"
#include "Commands/AutoLeftSwitch.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoCrossTheLineCommand.h"
#include "Commands/AutoModeScoringCommand.h"
#include "Commands/AutoScoreOnLeftSwitchCommand.h"
#include "Commands/AutoScoreOnRightSwitchCommand.h"
#include "Commands/AutoScoreOnSwitchCommand.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DummyCommand.h"
#include "Commands/LinearSlideControl.h"
#include "Commands/TurnWithGyro.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
	frc::SmartDashboard::PutData("Gryo @ .25 power", new GyroTurn(90, .25));
	frc::SmartDashboard::PutData("Gryo @ .15 power", new GyroTurn(90, .15));
	frc::SmartDashboard::PutData("Gryo @ .125 power", new GyroTurn(90, .125));
	frc::SmartDashboard::PutData("Gryo @ .10 power", new GyroTurn(90, .10));

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    auxStick.reset(new frc::Joystick(1));
    
    driveStick.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("TurnWithGyro", new TurnWithGyro());
    frc::SmartDashboard::PutData("Linear Slide Control", new LinearSlideControl());
    frc::SmartDashboard::PutData("Auto Score On Right Switch Command", new AutoScoreOnRightSwitchCommand());
    frc::SmartDashboard::PutData("Auto Score On Left Switch Command", new AutoScoreOnLeftSwitchCommand());
    frc::SmartDashboard::PutData("Auto Score On Switch Command", new AutoScoreOnSwitchCommand());
    frc::SmartDashboard::PutData("Auto Cross The Line Command", new AutoCrossTheLineCommand());
    frc::SmartDashboard::PutData("Auto Mode Scoring Command", new AutoModeScoringCommand());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS


    // frc::SmartDashboard::PutData("Test Negative GyroTurn", new GyroTurn(-90, -.15));
    // frc::SmartDashboard::PutData("winch", new Winch());
    frc::SmartDashboard::PutData("MoveForDistance", new MoveForDistance(100, -.3));
    frc::SmartDashboard::PutData("AutoLeftSwitch", new AutoLeftSwitch());
    frc::SmartDashboard::PutData("AutoModeScoringCommand", new AutoModeScoringCommand());
    frc::SmartDashboard::PutData("AutoExchange", new AutoExchange());

#ifdef VISION_TRACK_CUBES
    frc::SmartDashboard::PutData("Facing Yellow", new FaceYellow());
#else
    frc::SmartDashboard::PutData("Tape", new FaceTape());
#endif

    //    frc::SmartDashboard::PutData("Turn Right", new PointTurnRight(45,.1));
    //    frc::SmartDashboard::PutData("Test lighting command", new LightingTestCommand());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getdriveStick() {
   return driveStick;
}

std::shared_ptr<frc::Joystick> OI::getauxStick() {
   return auxStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

bool OI::isLinearSlideUpSignaled() {
	const bool signaled = auxStick->GetRawButton(XBox_RightButton);
	return signaled;
}

bool OI::isLinearSlideDownSignaled() {
	const bool signaled = auxStick->GetRawButton(XBox_LeftButton);
	return signaled;
}

bool OI::isWinchSignaled() {
	const bool signaled = auxStick->GetRawButton(XBox_ButtonX);
	return signaled;
}

bool OI::isLowBoostSignaled() {
	const bool lowBoost = driveStick->GetRawButton(LogitechGamePad_RightTrigger);
	return lowBoost;
}

double OI::getWinchPower() {
	return auxStick->GetRawAxis(XBox_RightYAxis);
}

bool OI::isCubeIntakeSignaled() {
	const bool buttonB = auxStick->GetRawButton(XBox_ButtonB);
	return buttonB;
}

bool OI::isCubeHighSpeedExhaustSignaled() {
	const bool buttonY = auxStick->GetRawButton(XBox_ButtonY);
	return buttonY;
}

bool OI::isCubeLowSpeedExhaustSignaled() {
	const bool buttonA = auxStick->GetRawButton(XBox_ButtonA);
	return buttonA;
}

bool OI::isHighBoostSignaled() {
	const bool highBoost = driveStick->GetRawButton(LogitechGamePad_LeftTrigger);
	return highBoost;
}

double OI::getLeftTrackPower() {
	return driveStick->GetRawAxis(LogitechGamePad_LeftYAxis);
}

double OI::getRightTrackPower() {
	return driveStick->GetRawAxis(LogitechGamePad_RightYAxis);
}

bool OI::isSwitchDirectionSignaled() {
	return driveStick->GetRawButton(LogitechGamePad_XButton);
}

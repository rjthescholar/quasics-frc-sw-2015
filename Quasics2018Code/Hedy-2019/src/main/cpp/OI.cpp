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

#include "Commands/Primitives/PointTurnRight.h"
#include "Commands/Primitives/MoveForDistance.h"
#include "Commands/TeleOp/Teleop.h"
#include "Commands/AutoExchange.h"

#include "Commands/AutoLeftSwitch.h"
#include "Commands/AutoRightSwitch.h"
#include "Commands/AutoModeLeft.h"
#include "Commands/AutoModeRight.h"
#include "Commands/Primitives/Outtake.h"
#include "Commands/TurnLightOn.h"
#include "Commands/TurnLightOff.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/smartdashboard/SmartDashboard.h"
#include "Commands/AutoCrossTheLineCommand.h"
#include "Commands/AutoModeScoringCommand.h"
#include "Commands/AutoScoreOnLeftSwitchCommand.h"
#include "Commands/AutoScoreOnRightSwitchCommand.h"
#include "Commands/AutoScoreOnSwitchCommand.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DummyCommand.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Commands/GyroTurn.h"


KatTrainerOI::KatTrainerOI() {
    // Process operator interface input here.

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    auxStick.reset(new frc::Joystick(1));
    
    driveStick.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("Auto Score On Right Switch Command", new AutoScoreOnRightSwitchCommand());
    frc::SmartDashboard::PutData("Auto Score On Left Switch Command", new AutoScoreOnLeftSwitchCommand());
    frc::SmartDashboard::PutData("Auto Score On Switch Command", new AutoScoreOnSwitchCommand());
    frc::SmartDashboard::PutData("Auto Cross The Line Command", new AutoCrossTheLineCommand());
    frc::SmartDashboard::PutData("Auto Mode Scoring Command", new AutoModeScoringCommand());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS


    frc::SmartDashboard::PutData("Cross the line", new MoveForDistance(100, -.3));
    frc::SmartDashboard::PutData("AutoLeftSwitch", new AutoLeftSwitch());
    frc::SmartDashboard::PutData("AutoRightSwitch", new AutoRightSwitch());
    //frc::SmartDashboard::PutData("AutoModeScoringCommand", new AutoModeScoringCommand());
    frc::SmartDashboard::PutData("AutoExchange", new AutoExchange());
    frc::SmartDashboard::PutData("AutoModeLeft", new AutoModeLeft());
    frc::SmartDashboard::PutData("AutoModeRight", new AutoModeRight());
    frc::SmartDashboard::PutData("Intake", new Outtake(10, .8));
    frc::SmartDashboard::PutData("Outtake", new Outtake(10, -1));
    frc::SmartDashboard::PutData("GyroTurn", new GyroTurn(45, .25));
    frc::SmartDashboard::PutData("Turn on a light", new TurnLightOn());
    frc::SmartDashboard::PutData("Turn off a light", new TurnLightOff());

    //    frc::SmartDashboard::PutData("Turn Right", new PointTurnRight(45,.1));
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> KatTrainerOI::getdriveStick() {
   return driveStick;
}

std::shared_ptr<frc::Joystick> KatTrainerOI::getauxStick() {
   return auxStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

bool KatTrainerOI::isLinearSlideUpSignaled() {
	const bool signaled = auxStick->GetRawButton(XBox_RightButton);
	return signaled;
}

bool KatTrainerOI::isLinearSlideDownSignaled() {
	const bool signaled = auxStick->GetRawButton(XBox_LeftButton);
	return signaled;
}

bool KatTrainerOI::isWinchSignaled() {
	const bool signaled = auxStick->GetRawButton(XBox_ButtonX);
	return signaled;
}

/*bool KatTrainerOI::isLowBoostSignaled() {
	const bool lowBoost = driveStick->GetRawButton(LogitechGamePad_RightTrigger);
	return lowBoost;
}*/

bool KatTrainerOI::isLowToggled() {
	const bool lowToggle = driveStick->GetRawButton(LogitechGamePad_RightTrigger);
	return lowToggle;
}

bool KatTrainerOI::isHighToggled() {
	const bool highToggle = driveStick->GetRawButton(LogitechGamePad_LeftTrigger);
	return highToggle;
}

double KatTrainerOI::getWinchPower() {
	return auxStick->GetRawAxis(XBox_LeftYAxis);
}
//
//bool OI::isCubeIntakeSignaled() {
//	const bool buttonA = auxStick->GetRawButton(XBox_ButtonA);
//	return buttonA;
//}

bool KatTrainerOI::isCubeHighSpeedExhaustSignaled() {
	const bool buttonY = auxStick->GetRawButton(XBox_ButtonY);
	return buttonY;
}

bool KatTrainerOI::isCubeLowSpeedExhaustSignaled() {
	const bool buttonA = auxStick->GetRawButton(XBox_ButtonA);
	return buttonA;
}

bool KatTrainerOI::isCubeOutLowSpeedExhaustSignaled() {
	const bool buttonB = auxStick->GetRawButton(XBox_ButtonB);
	return buttonB;
}

bool KatTrainerOI::isHighBoostSignaled() {
	const bool highBoost = driveStick->GetRawButton(LogitechGamePad_LeftTrigger);
	return highBoost;
}

double KatTrainerOI::getLeftTrackPower() {
	return driveStick->GetRawAxis(LogitechGamePad_LeftYAxis);
}

double KatTrainerOI::getRightTrackPower() {
	return driveStick->GetRawAxis(LogitechGamePad_RightYAxis);
}

bool KatTrainerOI::isSwitchDirectionSignaled() {
	return driveStick->GetRawButton(LogitechGamePad_YButton);
}

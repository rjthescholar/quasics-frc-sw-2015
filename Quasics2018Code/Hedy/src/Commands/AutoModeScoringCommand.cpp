// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoModeScoringCommand.h"
#include "Robot.h"
#include <DriverStation.h>
#include "Commands/AutoModeCrossTheLineCommand.h"
#include "Commands/AutoScoreOnSwitchCommand.h"

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR


AutoModeScoringCommand::AutoModeScoringCommand(): ConditionalCommand(new AutoScoreOnSwitchCommand, new AutoCrossTheLineCommand) {
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

bool AutoModeScoringCommand::Condition(){
	// If we're on the same side of the "arena" as our target on the switch, then we'll go for it.
	// If not, we'll just move forward.
	const std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if (gameData.empty()){
		return false;
	}

	bool shouldWeScoreOnSwitch = false;
	/*
	const bool ourSideIsLeftOnSwitch = (gameData[0] == 'L');
	Robot::RobotStartingPosition startingPosition = Robot::getStartingPosition();
	if (ourSideIsLeftOnSwitch && startingPosition == Robot::eStartingOnLeft) {
		shouldWeScoreOnSwitch = true;
	} else if (!ourSideIsLeftOnSwitch && startingPosition == Robot::eStartingOnRight) {
		shouldWeScoreOnSwitch = true;
	} else {
		// We're either in the middle, or else we're on the opposite side from the
		// target.  Either way, we aren't going to try to score on the switch.
		shouldWeScoreOnSwitch = false;
	}
	*/

	return shouldWeScoreOnSwitch;
}

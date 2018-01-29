
// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef AUTO_MODE_SCORING_COMMAND_H
#define AUTO_MODE_SCORING_COMMAND_H
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES


#include "Commands/AutoScoreOnSwitchCommand.h"
#include "Commands/AutoCrossTheLineCommand.h"
#include "Commands/ConditionalCommand.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
class AutoModeScoringCommand : public frc::ConditionalCommand {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	AutoModeScoringCommand();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
protected:
virtual bool Condition();
};

#endif

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include <WPILib.h>

class KatTrainerOI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	
	
	
	std::shared_ptr<frc::Joystick> auxStick;
	std::shared_ptr<frc::Joystick> driveStick;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	KatTrainerOI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<frc::Joystick> getdriveStick();
	std::shared_ptr<frc::Joystick> getauxStick();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	bool isSwitchDirectionSignaled();
	bool isLowBoostSignaled();
	bool isHighBoostSignaled();
	double getLeftTrackPower();
	double getRightTrackPower();

	bool isLinearSlideUpSignaled();
	bool isLinearSlideDownSignaled();
	bool isWinchSignaled();
	double getWinchPower();
	bool isCubeIntakeSignaled();
	bool isCubeHighSpeedExhaustSignaled();
	bool isCubeLowSpeedExhaustSignaled();
	bool isCubeOutLowSpeedExhaustSignaled();

};

#endif

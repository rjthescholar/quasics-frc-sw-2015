// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef DRIVESYSTEM_H
#define DRIVESYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "AHRS.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveSystem: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<SpeedController> leftFront;
	std::shared_ptr<SpeedController> leftRear;
	std::shared_ptr<SpeedController> rightFront;
	std::shared_ptr<SpeedController> rightRear;
	std::shared_ptr<RobotDrive> robotDrive41;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	//Data To Return
	bool isLeftForward;						//Left set to move forward
	bool isRightForward;					//Right set to move forward
	double leftPower;						//Left power setting
	double rightPower;						//Right power setting

	//Extra Pointers
	std::shared_ptr<AHRS> navx;				//NavX-MXP sensor

public:
	DriveSystem();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	//Motion Control
	void MoveLeft(double percentPower);		//Set left power
	void MoveRight(double percentPower);	//Set right power
	void StopEverything();					//Stop both sides

	//Report on motion status
	double GetPowerRight();					//Get left power percentage
	double GetPowerLeft();					//Get right power percentage
	bool IsLeftForward();					//Get left direction
	bool IsRightForward();					//Get right direction

	//NavX-MXP actions
	void ResetYaw();						//Reset yaw Rotation to 0 degrees
	void ResetDisplacement();				//Reset all displacement values

	//NavX-MXP readings
	double GetPitch();						//-180 to 180 degrees
	double GetYaw();						//-180 to 180 degrees
	double GetContinuousYaw();			//0 to infinity (or at least very high)
	double GetRoll();						//-180 to 180 degrees
	double GetDisplacementX();				//in meters
	double GetDisplacementY();				//in meters
	double GetDisplacementZ();				//in meters
};

#endif

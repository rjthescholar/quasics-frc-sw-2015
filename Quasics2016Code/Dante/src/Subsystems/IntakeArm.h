// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef INTAKEARM_H
#define INTAKEARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class IntakeArm: public Subsystem {
private:
	std::shared_ptr<SpeedController> leftArm;
	std::shared_ptr<SpeedController> rightArm;
	std::shared_ptr<Encoder> leftEncoder;
	std::shared_ptr<Encoder> rightEncoder;
public:
	IntakeArm();
	void InitDefaultCommand();

	void SetPower (float power);
	float GetLeftAngle ();
	float GetRightAngle ();
	float GetLeftSpeed ();
	float GetRightSpeed ();
	void ResetLeftEncoder ();
	void ResetRightEncoder ();
};

#endif

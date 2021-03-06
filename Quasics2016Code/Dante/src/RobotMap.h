// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<SpeedController> intakeArmLeftArm;
	static std::shared_ptr<SpeedController> intakeArmRightArm;
	static std::shared_ptr<Encoder> intakeArmLeftEncoder;
	static std::shared_ptr<Encoder> intakeArmRightEncoder;
	static std::shared_ptr<SpeedController> intakeShooterLeftIntakeWheel;
	static std::shared_ptr<SpeedController> intakeShooterRightIntakeWheel;
	static std::shared_ptr<DoubleSolenoid> intakeShooterPusher;
	static std::shared_ptr<SpeedController> driveTrainFrontLeft;
	static std::shared_ptr<SpeedController> driveTrainBackLeft;
	static std::shared_ptr<SpeedController> driveTrainFrontRight;
	static std::shared_ptr<SpeedController> driveTrainBackRight;
	static std::shared_ptr<Encoder> driveTrainLeftEncoder;
	static std::shared_ptr<Encoder> driveTrainRightEncoder;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
};
#endif

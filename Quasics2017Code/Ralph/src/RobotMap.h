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

#include <WPILib.h>


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 *
 * This class was originally auto-generated via RobotBuilder, but has been modified
 * extensively since then.
 */
class RobotMap {
public:
	static std::shared_ptr<SpeedController> driveTrainFrontLeft;
	static std::shared_ptr<SpeedController> driveTrainBackLeft;
	static std::shared_ptr<SpeedController> driveTrainFrontRight;
	static std::shared_ptr<SpeedController> driveTrainBackRight;
	static std::shared_ptr<SpeedController> intakeMotor;
	static std::shared_ptr<SpeedController> climberMotor;
	static std::shared_ptr<Encoder> driveTrainLeftEncoder;
	static std::shared_ptr<Encoder> driveTrainRightEncoder;

	static std::shared_ptr<Servo> gearServo;
	static std::shared_ptr<Servo> gearServoKicker;
	static std::shared_ptr<Spark> outtakeMotor;
	static std::shared_ptr<Servo> outputActuator;
	static std::shared_ptr<Servo> outputActuator2;

	static void init();
};
#endif

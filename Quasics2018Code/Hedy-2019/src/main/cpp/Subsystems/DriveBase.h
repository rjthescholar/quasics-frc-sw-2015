// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include <WPILib.h>

/**
 *
 *
 * @author ExampleAuthor
 */

class DriveBase: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<frc::Encoder> leftEncoder;
	std::shared_ptr<frc::Encoder> rightEncoder;
	std::shared_ptr<frc::SpeedController> leftFrontMotor;
	std::shared_ptr<frc::SpeedController> leftRearMotor;
	std::shared_ptr<frc::SpeedControllerGroup> leftMotors;
	std::shared_ptr<frc::SpeedController> rightFrontMotor;
	std::shared_ptr<frc::SpeedController> rightRearMotor;
	std::shared_ptr<frc::SpeedControllerGroup> rightMotors;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

public:
	DriveBase();
	void InitDefaultCommand();
	void SetPowerToMotors(double leftPercent, double rightPercent);

	double RightEncoderVelocity();
	double LeftEncoderVelocity();
	double RightEncoderDistance();
	double LeftEncoderDistance();
	uint32_t LeftEncoderRaw();
	uint32_t RightEncoderRaw();
	void RightEncoderReset();
	void LeftEncoderReset();

	void Stop();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif